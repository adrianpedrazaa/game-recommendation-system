import pandas as pd
import re


df = pd.read_csv(r"C:\Users\Sero0\OneDrive - UNT System\games.csv", usecols=["description"])

# Basic text preprocessing
def preprocess_text(text):
    # Convert to lowercase
    text = text.lower()
    # Remove punctuation (keep words, digits, and whitespace only)
    
    text = re.sub(r"[^\w\s]", "", text)
    # Strip extra whitespace
    text = text.strip()
    return text

# Apply the preprocessing function to each description
df["description_clean"] = df["description"].apply(preprocess_text)


descriptions = df["description_clean"].tolist()

# Print the first few cleaned descriptions
for i in range(3):
    print(descriptions[i])
