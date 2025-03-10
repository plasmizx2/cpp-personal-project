import os
import csv
from datetime import datetime
import numpy as np
import cv2

# Paths to different face categories
DATASET_FOLDERS = [
    "dataSet/deliveryDrivers",
    "dataSet/parents",
    "dataSet/teachers",
    "dataSet/unknown"
]

def loadKnownFaces():
    knownEncodings = []
    knownNames = []

    for folder in DATASET_FOLDERS:
        if os.path.exists(folder):
            for fileName in os.listdir(folder):
                path = os.path.join(folder, fileName)
                image = face_recognition.load_image_file(path)
                encodings = face_recognition.face_encodings(image)

                if encodings:  # Ensure the image has a face
                    knownEncodings.append(encodings[0])
                    knownNames.append(os.path.splitext(fileName)[0])

    return knownEncodings, knownNames

def matchFace():
    print("Comparing captured face to database...")

    knownEncodings, knownNames = loadKnownFaces()

    if not knownEncodings:
        print("❌ No known faces found.")
        return

    # Load the captured face
    newFacePath = "userFrame.jpg"
    newFace = face_recognition.load_image_file(newFacePath)
    newEncoding = face_recognition.face_encodings(newFace)

    if newEncoding:
        distances = face_recognition.face_distance(knownEncodings, newEncoding[0])
        best_match_index = np.argmin(distances)
        threshold = 0.7

        if distances[best_match_index] < threshold:
            matchedName = knownNames[best_match_index]
            print(f"✅ Closest Match: {matchedName} (Distance: {distances[best_match_index]:.3f})")
            logAttendance(matchedName)
        else:
            print("❌ No match found within threshold.")
            logAttendance("Unknown")
            saveUnknownFace(newFacePath)
    else:
        print("❌ No face detected in captured image.")

def saveUnknownFace(imagePath):
    os.makedirs("dataSet/unknown", exist_ok=True)
    unknown_face_path = f"dataSet/unknown/Unknown_{datetime.now().strftime('%Y%m%d_%H%M%S')}.jpg"
    cv2.imwrite(unknown_face_path, cv2.imread(imagePath))
    print(f"🚨 Unknown face saved: {unknown_face_path}")

def logAttendance(name):
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open("attendance_log.csv", "a", newline="") as file:
        writer = csv.writer(file)
        writer.writerow([timestamp, name])
    print(f"📜 Logged Attendance: {name} at {timestamp}")

if __name__ == "__main__":
    matchFace()