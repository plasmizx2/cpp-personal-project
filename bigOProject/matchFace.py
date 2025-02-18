import face_recognition
import os
import csv
from datetime import datetime
import numpy as np

def matchFace():
    print("🔍 Comparing captured face to employee database...")

    # Load known employee faces
    croppedPics = "/Users/seandumont/Desktop/cpp-personal-project/bigOProject/croppedPics"  # Folder with images of registered employees
    knownEncodings = []
    employee_names = []

    for currentFile in os.listdir(croppedPics):
        path = os.path.join(croppedPics, currentFile)
        image = face_recognition.load_image_file(path)
        encodingOfImage = face_recognition.face_encodings(image)

        if encodingOfImage:  # Ensure there's a face detected before appending
            knownEncodings.append(encodingOfImage[0])
            employee_names.append(os.path.splitext(currentFile)[0])  

    if not knownEncodings:
        print("❌ No known faces found.")
        exit()

    # Load the captured face
    newFace = face_recognition.load_image_file("userFrame.jpg")
    newEncoding = face_recognition.face_encodings(newFace)

    if newEncoding:
        distances = face_recognition.face_distance(knownEncodings, newEncoding[0])
        best_match_index = np.argmin(distances)  # Get index of the smallest distance

        threshold = 0.7 # Adjust if necessary (lower = more strict, higher = more lenient)

        if distances[best_match_index] < threshold:
            matchedName = employee_names[best_match_index]
            print(f":white_check_mark: Closest Match: {matchedName} (Distance: {distances[best_match_index]:.3f})")
            logAttendance(matchedName)  # :white_check_mark: Log attendance
        else:
            print(":x: No match found within threshold.")
            logAttendance("Unknown")  # :white_check_mark: Log "Unknown" check-in
    else:
        print("❌ No face detected in captured image.")
        exit()

def logAttendance(name):
    #Logs the recognized person's name and timestamp in a CSV file.
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open("attendance_log.csv", "a", newline="") as file:
        writer = csv.writer(file)
        writer.writerow([timestamp, name])
    print(f"📜 Logged Attendance: {name} at {timestamp}")

