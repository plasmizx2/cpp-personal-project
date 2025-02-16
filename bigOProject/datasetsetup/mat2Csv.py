import scipy.io
import pandas as pd
import numpy as np

# Load the .mat file
mat_path = "/Users/seandumont/Desktop/cpp-personal-project/bigOProject/wiki/wiki.mat"
mat_data = scipy.io.loadmat(mat_path)

# Extract "wiki" dataset
wiki = mat_data["wiki"][0][0]

# Extract fields
image_paths = wiki["full_path"][0]  # Image file paths
names = wiki["name"][0]  # Celebrity names
dob = wiki["dob"][0]  # Date of birth
photo_taken = wiki["photo_taken"][0]  # Year when photo was taken
genders = wiki["gender"][0]  # Gender (0 = Female, 1 = Male, NaN = Unknown)
face_scores = wiki["face_score"][0]  # Face detection score
second_face_scores = wiki["second_face_score"][0]  # Second face detection score

# Ensure all lists have the same length
min_length = min(len(image_paths), len(names), len(dob), len(photo_taken), len(genders), len(face_scores))

# Create DataFrame with only valid entries
df = pd.DataFrame({
    "name": [str(names[i][0]) if i < len(names) and len(names[i]) > 0 else "Unknown" for i in range(min_length)],
    "image_path": [str(image_paths[i][0]) if i < len(image_paths) and len(image_paths[i]) > 0 else "Unknown" for i in range(min_length)],
    "dob": [dob[i] if i < len(dob) else np.nan for i in range(min_length)],
    "photo_taken": [photo_taken[i] if i < len(photo_taken) else np.nan for i in range(min_length)],
    "gender": [genders[i] if i < len(genders) else np.nan for i in range(min_length)],
    "face_score": [face_scores[i] if i < len(face_scores) else np.nan for i in range(min_length)],
    "second_face_score": [second_face_scores[i] if i < len(second_face_scores) else np.nan for i in range(min_length)]
})

# Filter out images with bad face scores (keep only good face detections)
df = df[df["face_score"] > 0]

# Save to CSV
csv_path = "/Users/seandumont/Desktop/cpp-personal-project/bigOProject/wiki_metadata.csv"
df.to_csv(csv_path, index=False)

print(f"✅ Metadata extracted and saved as {csv_path}!")