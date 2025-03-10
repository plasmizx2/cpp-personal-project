import cv2
import mediapipe as mp
import os

def processUntouchedFaces():
    mpFaceDetection = mp.solutions.face_detection
    faceDetector = mpFaceDetection.FaceDetection(min_detection_confidence=0.9)

    untouchedFolder = "dataSet/untouchedFaces"  # Folder containing unprocessed images
    processedFolder = "dataSet/croppedFaces"  # Temporary folder for processed images

    os.makedirs(processedFolder, exist_ok=True)

    for fileName in os.listdir(untouchedFolder):
        currentImgPath = os.path.join(untouchedFolder, fileName)
        currentImg = cv2.imread(currentImgPath)

        if currentImg is None:
            print(f"❌ Error: Could not load {fileName}. Skipping.")
            continue

        convertedImage = cv2.cvtColor(currentImg, cv2.COLOR_BGR2RGB)
        mpImageInfoResult = faceDetector.process(convertedImage)

        if mpImageInfoResult.detections:
            for detection in mpImageInfoResult.detections:
                boundBoxDetection = detection.location_data.relative_bounding_box
                h, w, _ = currentImg.shape

                x = int(boundBoxDetection.xmin * w)
                y = int(boundBoxDetection.ymin * h)
                width = int(boundBoxDetection.width * w)
                height = int(boundBoxDetection.height * h)

                croppedFace = currentImg[y:y+height, x:x+width]

                croppedPath = os.path.join(processedFolder, fileName)
                cv2.imwrite(croppedPath, croppedFace)
                print(f"✅ Cropped & saved: {croppedPath}")

if __name__ == "__main__":
    processUntouchedFaces()
