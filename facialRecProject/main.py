import cv2 as cv
import face_recognition

seansImages = []
otherImages = []

for indexImage in ["seansFace/sean1.jpg","seansFace/sean2.jpg","seansFace/sean3.jpg","seansFace/sean4.jpg","seansFace/sean5.jpg",]:
    currentImage = cv.load_image_file(indexImage)
