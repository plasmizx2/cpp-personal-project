import cv2
import mediapipe as mp
from mediapipe.tasks import python
from mediapipe.tasks.python import vision
import numpy as np
import requests
#The vision module is just a namespace for all vision-related tasks (like face detection). 
# When you see from mediapipe.tasks.python import vision, 
# it means “import the vision tasks (e.g., face detection, object detection) so we can use them.”


# Create a BaseOptions object to point to your model file. 
baseOptionsAiModel = python.BaseOptions(model_asset_path='/Users/seandumont/Desktop/cpp-personal-project/bigOProject/blaze_face_short_range.tflite')

# Create a FaceDetectorOptions Object
# Configure your face detector. You can add more parameters here if needed.
# You pass the BaseOptions object to it and specify parameters like the running mode.
# Using running_mode=VisionRunningMode.IMAGE tells the detector to process single images (as opposed to video or live streams).
faceDetectorParameterOptions = vision.FaceDetectorOptions(base_options=baseOptionsAiModel,running_mode=vision.RunningMode.IMAGE)  # or VIDEO, LIVE_STREAM as needed

# Create the FaceDetector object, using the vision class with the options we made previosuly.
facedetector = vision.FaceDetector.create_from_options(faceDetectorParameterOptions)

cap = cv2.VideoCapture(0)# 0 stands for camera 0 so the first camera paird with the device.
while cap.isOpened(): #in python u can return more than one value
    frameReadCheck,frame = cap.read() #if the frame is read correctly with no errors then it returns true for that and gives u the actual image aka frame
    if not frameReadCheck:
        break

    cv2.imshow("CurrentImage", frame) # Display the frame in a window named CurrentImage

# cv2.waitKey(1) waits for 1 millisecond for any key press.
# It allows the OpenCV window to update and process events.
# If a key is pressed within that time, it returns the ASCII code of the key.
# If no key is pressed, it returns -1.
    key = cv2.waitKey(1) & 0xFF
    if key == ord(' '):
        capturedFrame = frame.copy()  # Make a copy of the current frame
        break


cap.release()#needed to stop it from being a infinite loop?
cv2.destroyAllWindows()

#save the captured frame to a file
cv2.imwrite("userFrame.jpg", capturedFrame) #dont forget in python you can use stuff inside of loops outside of them.
 
convertedImage = cv2.cvtColor(capturedFrame,cv2.COLOR_BGR2RGB)# CV2 does bgr media pipe needs it in rgb
# Convert frame to RGB (MediaPipe requires RGB)

#mp.Image: This class wraps your image data.
#image_format=mp.ImageFormat.SRGB: This tells MediaPipe that your image is in standard RGB color space.
#data=convertedImage: This is your image data the captured frame, converted from BGR to RGB.
mp_image = mp.Image(image_format=mp.ImageFormat.SRGB,data=convertedImage)


# Now you can use detector.detect() to process an image.
facedetector.detect(mp_image)



# Initialize MediaPipe face detector

# Open the webcam
# Convert frame to RGB (MediaPipe requires RGB)
# For simplicity, take the first detected face
# Crop the face region
# Save the image as a JPEG file






# Initialize MediaPipe Holistic model
mp_holistic = mp.solutions.holistic
mp_drawing = mp.solutions.drawing_utils

# Open webcam
cap = cv2.VideoCapture(0)

with mp_holistic.Holistic(min_detection_confidence=0.5, min_tracking_confidence=0.5) as holistic:
    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break

        # Convert BGR to RGB (MediaPipe needs RGB)
        image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # Make detections
        results = holistic.process(image)

        # Convert back to BGR for OpenCV display
        image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

        # Draw landmarks
        mp_drawing.draw_landmarks(image, results.pose_landmarks, mp_holistic.POSE_CONNECTIONS)
        mp_drawing.draw_landmarks(image, results.face_landmarks, mp_holistic.FACEMESH_TESSELATION)
        mp_drawing.draw_landmarks(image, results.left_hand_landmarks, mp_holistic.HAND_CONNECTIONS)
        mp_drawing.draw_landmarks(image, results.right_hand_landmarks, mp_holistic.HAND_CONNECTIONS)

        # Show the output
        cv2.imshow('MediaPipe Holistic', image)

        if cv2.waitKey(10) & 0xFF == ord('q'):  # Press 'q' to exit
            break

cap.release()
cv2.destroyAllWindows()



 