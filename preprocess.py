import pandas as pd
import re
import json

# 1) Read only the "description" column from the CSV
# Replace "dataset.csv" with the actual path/filename of your dataset
# Replace "description" with the exact column name you want to read
df = pd.read_csv(r"C:\Users\Sero0\Downloads\Steam Trends 2023 by @evlko and @Sadari.csv", usecols=["Tags", "Title"], encoding="latin1")

# 'df' now contains just one column: df["description"]

# 2) Basic text preprocessing
def preprocess_text(text):
    # Convert to lowercase
    text = text.lower()
    # Remove punctuation (keep words, digits, and whitespace only)
    # You can tweak the regex as you see fit
    text = re.sub(r"[^\w\s,]", "", text)
    # Strip extra whitespace
    text = text.strip()
    return text

# Apply the preprocessing function to each description
df["tags_clean"] = df["Tags"].apply(preprocess_text)
df["names_clean"] = df["Title"].apply(preprocess_text)
# 3) If you want the cleaned text as a list
tags = df["tags_clean"].tolist()
titles = df["names_clean"].tolist()


# Print the first few cleaned descriptions
combined_list = []

for i in range(3):
    combined_list.append((titles[i], tags[i]))

print(combined_list)


