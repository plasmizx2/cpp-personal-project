import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score

# Load historical sports data (example CSV structure)
def load_data(file_path):
    data = pd.read_csv(file_path)
    return data

# Preprocess data
def preprocess_data(data):
    # Example features: Team stats, recent form, etc.
    features = data[['team1_score', 'team2_score', 'team1_rank', 'team2_rank']]
    labels = data['winner']  # 1 if team1 wins, 0 if team2 wins
    
    return train_test_split(features, labels, test_size=0.2, random_state=42)

# Train model
def train_model(X_train, y_train):
    model = RandomForestClassifier(n_estimators=100, random_state=42)
    model.fit(X_train, y_train)
    return model

# Predict outcomes
def predict(model, X_test):
    return model.predict(X_test)

# Main function
def main():
    file_path = 'sports_data.csv'  # Replace with your dataset
    data = load_data(file_path)
    X_train, X_test, y_train, y_test = preprocess_data(data)
    
    model = train_model(X_train, y_train)
    predictions = predict(model, X_test)
    
    accuracy = accuracy_score(y_test, predictions)
    print(f'Model Accuracy: {accuracy * 100:.2f}%')
    
    # Example prediction
    new_game = np.array([[90, 85, 3, 5]])  # Example stats
    prediction = model.predict(new_game)
    print('Predicted Winner:', 'Team 1' if prediction[0] == 1 else 'Team 2')

if __name__ == "__main__":
    main()
