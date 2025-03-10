import croppPic
import captureCurrentFace
import faceMatch
import pandas as pd
import os

print("\n📌 Running Attendance System...\n")

# Step 1: Check if new images exist before processing
if os.path.exists("dataSet/untouchedFaces") and os.listdir("dataSet/untouchedFaces"):
    print("🔍 New images detected, processing...")
    croppPic.processUntouchedFaces()
    print("✅ Image cropping completed.")
else:
    print("📂 No new images to process.")

# Step 2: Capture a new face from the webcam
captureCurrentFace.captureNewFace()
print("✅ Face capture completed.")

# Step 3: Compare the captured face with stored faces & log attendance
faceMatch.matchFace()
print("✅ Face matching completed.")

# Step 4: Display latest check-ins
def showAttendanceLog():
    try:
        df = pd.read_csv("attendance_log.csv", names=["Timestamp", "Name"])
        print("\n📊 Latest Check-ins:\n", df.tail(10))  # Show last 10 entries
    except FileNotFoundError:
        print("\n❌ No attendance log found.")

showAttendanceLog()

print("\n✅ Attendance system completed!")
