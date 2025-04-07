import pandas as pd
import re
import csv

# 1) Read only the "Tags" and "Title" columns from the CSV
df = pd.read_csv(
    r"C:\Users\Sero0\Downloads\Steam Trends 2023 by @evlko and @Sadari - Games Data.csv",
    usecols=["Tags", "Title", "Reviews Score Fancy"],
    encoding="latin1"
)

# 2) Basic text preprocessing
def preprocess_text(text):
    text = str(text)  # Ensure the text is a string
    text = text.lower()
    text = re.sub(r"[^\w\s,]", "", text)  # keep commas
    text = text.strip()
    return text

# Apply the preprocessing function
df["tags_clean"] = df["Tags"].apply(preprocess_text)
df["names_clean"] = df["Title"].apply(preprocess_text)
df["reviews_score_clean"] = df["Reviews Score Fancy"].apply(preprocess_text)

# 3) Convert cleaned columns to lists
tags = df["tags_clean"].tolist()
titles = df["names_clean"].tolist()
reviews_scores = df["reviews_score_clean"].tolist()

# 4) Combine into a list of tuples for demonstration
combined_list = []
for i in range(100):
    combined_list.append((titles[i], reviews_scores[i], tags[i]))

print(combined_list)

# 5) Save combined_list to a CSV file
with open("cleaned_game_data.csv", "w", newline="", encoding="utf-8") as f:
    writer = csv.writer(f)
    # If you want headers, write them first
    writer.writerow(["Title", "Reviews Score Fancy", "Tags"])
    # Write each tuple (title, tag) to the CSV
    writer.writerows(combined_list)
