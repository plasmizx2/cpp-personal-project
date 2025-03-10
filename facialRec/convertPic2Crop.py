import cv2
import mediapipe as mp
import os


def regular2Crop():
    mpFaceDetection = mp.solutions.face_detection
    faceDetector = mpFaceDetection.FaceDetection(min_detection_confidence=.9)

    regEmployeePics = '/Users/seandumont/Desktop/cpp-personal-project/bigOProject/regularPics'
    croppedEmployeePics = '/Users/seandumont/Desktop/cpp-personal-project/c++ personal proj/UnconnHackAthon/knownFacesCropped'

    regdirectory = os.listdir(regEmployeePics) ## just use this so u can loop thru 
    
    os.makedirs(croppedEmployeePics, exist_ok=True)
    #find the image path so we can crop with cv2
    for fileName in regdirectory:
        currentImgPath = os.path.join(regEmployeePics,fileName)
        currentImg = cv2.imread(currentImgPath)

        if currentImg is None:
            print(f"❌ Error: Could not load {fileName}. Skipping.")
            continue  # Skip this image
        convertedImage = cv2.cvtColor(currentImg, cv2.COLOR_BGR2RGB)  # CV2 does BGR, MediaPipe needs it in RGB
        # mp.Image: This class wraps your image data.
        # image_format=mp.ImageFormat.SRGB: This tells MediaPipe that your image is in standard RGB color space.
        # data=convertedImage: This is your image data, the captured frame, converted from BGR to RGB.
        mpImageInfoResult = faceDetector.process(convertedImage)


        if mpImageInfoResult.detections:
            for detection in mpImageInfoResult.detections:
                boundBoxDetection = detection.location_data.relative_bounding_box
                h, w, _ = currentImg.shape
                #knowing the height and width of a img will let you know the shape of the img
                x =int(boundBoxDetection.xmin * w)
                y = int(boundBoxDetection.ymin * h)
                width = int(boundBoxDetection.width * w)
                height = int(boundBoxDetection.height * h)

                #now crop the face remeber mpImageResult is not an image. 
                croppedFace = currentImg[y:y+height,x:x+width]

                #now save the cropped img   
                croppedPath = os.path.join(croppedEmployeePics,fileName)
                cv2.imwrite(croppedPath,croppedFace)
                print(f"✅ Saved cropped face: {croppedPath}")

