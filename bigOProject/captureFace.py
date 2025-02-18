import cv2
import mediapipe as mp
from mediapipe.tasks import python
from mediapipe.tasks.python import vision
import numpy as np
#USED FOR CAPTURING THE PERSON CURRENT FACE SO THEY CAN COME BACK AND COMPARE IT WITH THE DATABASE


    # The vision module is just a namespace for all vision-related tasks (like face detection). 
    # When you see from mediapipe.tasks.python import vision, 
    # it means “import the vision tasks (e.g., face detection, object detection) so we can use them.”

    # Create a BaseOptions object to point to your model file. 
def captureNewFace():
    print("📷 Capturing face for attendance...")

    baseOptionsAiModel = python.BaseOptions(model_asset_path='/Users/seandumont/Desktop/cpp-personal-project/bigOProject/blaze_face_short_range.tflite')

    # Create a FaceDetectorOptions Object
    # Configure your face detector. You can add more parameters here if needed.
    # You pass the BaseOptions object to it and specify parameters like the running mode.
    # Using running_mode=VisionRunningMode.IMAGE tells the detector to process single images (as opposed to video or live streams).
    faceDetectorParameterOptions = vision.FaceDetectorOptions(base_options=baseOptionsAiModel, running_mode=vision.RunningMode.IMAGE)  # or VIDEO, LIVE_STREAM as needed

    # Create the FaceDetector object, using the vision class with the options we made previously.
    facedetector = vision.FaceDetector.create_from_options(faceDetectorParameterOptions)
    print("these lines above work")
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
    print("these lines above work iggg")

    cap.release()  # Release the camera when done capturing
    cv2.destroyAllWindows()  # Close all OpenCV windows
    print("these lines above work iggg dont stop")
    if capturedFrame is not None:  # Ensure a frame was captured before proceeding
        # Save the captured frame to a file
        cv2.imwrite("/Users/seandumont/Desktop/cpp-personal-project/bigOProject/userFrame.jpg", capturedFrame)  # Don't forget in Python you can use stuff inside of loops outside of them.
        print("idk someting ")
        # Convert frame to RGB (MediaPipe requires RGB)
        convertedImage = cv2.cvtColor(capturedFrame, cv2.COLOR_BGR2RGB)  # CV2 does BGR, MediaPipe needs it in RGB

        # mp.Image: This class wraps your image data.
        # image_format=mp.ImageFormat.SRGB: This tells MediaPipe that your image is in standard RGB color space.
        # data=convertedImage: This is your image data, the captured frame, converted from BGR to RGB.
        mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=convertedImage)

        # Now you can use detector.detect() to process an image. Below u can see what .detect returns.
        detection_result = facedetector.detect(mp_image)
        #detections: A list of Detection objects, each corresponding to a detected face.
        #bounding_box: Specifies the location of the detected face within the image.
        #categories: Contains a confidence score representing the probability that the detection is a face.
        print("these lines above work iggg dont stop right before the upa")

        if detection_result.detections:
            for detection in detection_result.detections:
                #we want to know the bounding box only for now so we will choose to work with that.
                boundBoxDetection = detection.bounding_box
                #media pipe uses floating point numbers so we want to switch it to int for cv2 later.
                x = int(boundBoxDetection.origin_x)
                width = int(boundBoxDetection.width)
                y = int(boundBoxDetection.origin_y)
                height = int(boundBoxDetection.height)
                
                croppedFace = capturedFrame[y:y+height, x:x+width]  # FIXED: Cropping instead of drawing
                
                

            #(0, 255, 0) is The color of the rectangle
            #3 is The thickness of the rectangle border
            
            # Save the cropped face as an image
            cv2.imwrite("/Users/seandumont/Desktop/cpp-personal-project/bigOProject/classAttedenceCurrentPicture/UsersFaceCropped.jpg", croppedFace)


    # Display the final image with detected faces
    cv2.imshow("Detected Faces", capturedFrame)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

