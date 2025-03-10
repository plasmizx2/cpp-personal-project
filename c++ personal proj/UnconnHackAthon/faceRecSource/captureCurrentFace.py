import cv2

def captureNewFace():
    print("📷 Capturing face for attendance...")

    cap = cv2.VideoCapture(0)  # Open the webcam

    capturedFrame = None

    while cap.isOpened():
        frameReadCheck, frame = cap.read()
        if not frameReadCheck:
            break

        cv2.imshow("CurrentImage", frame)

        key = cv2.waitKey(1) & 0xFF
        if key == ord(' '):  # Capture frame on spacebar press
            capturedFrame = frame.copy()
            break

    cap.release()
    cv2.destroyAllWindows()

    if capturedFrame is not None:
        # Save the captured frame to a file without cropping
        cv2.imwrite("userFrame.jpg", capturedFrame)
        print("✅ Captured and saved face image (no cropping applied).")
