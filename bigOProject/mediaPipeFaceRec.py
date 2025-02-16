import cv2
import mediapipe as mp
from mediapipe.tasks import python
from mediapipe.tasks.python import vision
import numpy as np
import requests

# The vision module is just a namespace for all vision-related tasks (like face detection). 
# When you see from mediapipe.tasks.python import vision, 
# it means “import the vision tasks (e.g., face detection, object detection) so we can use them.”

# Create a BaseOptions object to point to your model file. 
baseOptionsAiModel = python.BaseOptions(model_asset_path='/Users/seandumont/Desktop/cpp-personal-project/bigOProject/blaze_face_short_range.tflite')

# Create a FaceDetectorOptions Object
# Configure your face detector. You can add more parameters here if needed.
# You pass the BaseOptions object to it and specify parameters like the running mode.
# Using running_mode=VisionRunningMode.IMAGE tells the detector to process single images (as opposed to video or live streams).
faceDetectorParameterOptions = vision.FaceDetectorOptions(base_options=baseOptionsAiModel, running_mode=vision.RunningMode.IMAGE)  # or VIDEO, LIVE_STREAM as needed

# Create the FaceDetector object, using the vision class with the options we made previously.
facedetector = vision.FaceDetector.create_from_options(faceDetectorParameterOptions)

cap = cv2.VideoCapture(0)  # 0 stands for camera 0, so the first camera paired with the device.

capturedFrame = None  # Initialize variable to avoid potential errors

while cap.isOpened():  # in python you can return more than one value
    frameReadCheck, frame = cap.read()  # if the frame is read correctly with no errors then it returns true for that and gives you the actual image aka frame
    if not frameReadCheck:
        break

    cv2.imshow("CurrentImage", frame)  # Display the frame in a window named CurrentImage

    # cv2.waitKey(1) waits for 1 millisecond for any key press.
    # It allows the OpenCV window to update and process events.
    # If a key is pressed within that time, it returns the ASCII code of the key.
    # If no key is pressed, it returns -1.
    key = cv2.waitKey(1) & 0xFF
    if key == ord(' '):  # Capture frame on spacebar press
        capturedFrame = frame.copy()  # Make a copy of the current frame
        break

cap.release()  # Release the camera when done capturing
cv2.destroyAllWindows()  # Close all OpenCV windows

if capturedFrame is not None:  # Ensure a frame was captured before proceeding
    # Save the captured frame to a file
    cv2.imwrite("userFrame.jpg", capturedFrame)  # Don't forget in Python you can use stuff inside of loops outside of them.

    # Convert frame to RGB (MediaPipe requires RGB)
    convertedImage = cv2.cvtColor(capturedFrame, cv2.COLOR_BGR2RGB)  # CV2 does BGR, MediaPipe needs it in RGB

    # mp.Image: This class wraps your image data.
    # image_format=mp.ImageFormat.SRGB: This tells MediaPipe that your image is in standard RGB color space.
    # data=convertedImage: This is your image data, the captured frame, converted from BGR to RGB.
    mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=convertedImage)

    # Now you can use detector.detect() to process an image.
    detection_result = facedetector.detect(mp_image)

