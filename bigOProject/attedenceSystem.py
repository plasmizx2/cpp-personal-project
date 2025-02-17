import convertPic2Crop
import captureFace
import matchFace
import pandas as pd

print("\n📌 Running Attendance System...\n")

# Step 1: Process stored images (Detect & crop faces)
convertPic2Crop.regular2Crop()
print("THIS DEF WORKS")

# Step 2: Capture a new face from the webcam
captureFace.captureNewFace()
print("THIS DEF WORKS")

# Step 3: Compare the captured face with stored faces & log attendance
matchFace.matchFace()
print("THIS DEF WORKS")

# Step 4: Display latest check-ins
def showAttendanceLog():
    try:
        df = pd.read_csv("attendance_log.csv", names=["Timestamp", "Name"])
        print("\n📊 Latest Check-ins:\n", df.tail(10))  # Show last 10 entries
    except FileNotFoundError:
        print("\n❌ No attendance log found.")

showAttendanceLog()

print("\n✅ Attendance system completed!")