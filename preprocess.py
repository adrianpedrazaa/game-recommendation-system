import pandas as pd
import re
import csv
from nltk.stem import PorterStemmer

# 1) Read only the "Tags" and "Title" columns from the CSV
df = pd.read_csv(
    r"C:\Users\Sero0\Downloads\Steam Trends 2023 by @evlko and @Sadari - Games Data.csv",
    usecols=["Tags", "Title", "Reviews Score Fancy"],
    encoding="latin1"
)

# Example synonym dictionary – you can expand this as needed.
synonyms = {
    "role playing game": "rpg",
    "action-adventure": "action",
    "first-person shooter": "fps",
    "massively multiplayer online": "mmo",
    "real-time strategy": "rts",
    "simulation": "sim",
    "sports": "sport",
    "puzzle": "puzz",
    "platformer": "plat",
    "survival": "surv",
    "open world": "openworld",
    "sandbox": "sand",
    "multiplayer": "mp",
    "single player": "sp",
    "cooperative": "coop",
    "competitive": "comp",
    "indie": "ind",
    "casual": "cas",
    "horror": "hor",
    "adventure": "adv",
    "strategy": "strat",
    "action role playing": "arpg",
    "tactical": "tact",
    "text-based": "text",
    "visual novel": "vn",
    "card game": "card",
    "board game": "board",
    "turn-based": "tb",
    "real-time": "rt",
    "first-person": "fp",
    "third-person": "tp",
    "top-down": "td",
    "isometric": "iso",
    "2d": "2d",
    "3d": "3d",
    "pixel graphics": "pixel",
    "retro": "retro",
    "fantasy": "fant",
    "sci-fi": "scifi",
    "historical": "hist",
    "post-apocalyptic": "postapoc",
    "stealth": "stealth",
    "hacking": "hack",
    "exploration": "explore",
    "crafting": "craft",
    "building": "build",
    "farming": "farm",
    "city-building": "citybuild",
}

# Simple normalization function
ps = PorterStemmer()
def normalize_tag(tag):
    tag = tag.lower()                    # Lowercase
    tag = re.sub(r"[^\w\s]", "", tag)      # Remove punctuation
    tag = tag.strip()                     # Trim whitespace
    # Optionally, apply stemming:
    tag = ps.stem(tag)
    # Map synonyms if they exist:
    return synonyms.get(tag, tag)

def process_tags(tag_string):
    # If the tag_string is null or empty, handle appropriately
    if not isinstance(tag_string, str):
        return []
    tags = tag_string.split(",")
    norm_tags = {normalize_tag(tag) for tag in tags}
    return list(norm_tags)

df["normalized_tags"] = df["Tags"].apply(process_tags)


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


# Combine selected columns for demonstration
combined_list = []
num_rows = min(100, len(df)) 
for i in range(num_rows): 
    combined_list.append(( df["names_clean"].iloc[i], df["reviews_score_clean"].iloc[i], df["tags_clean"].iloc[i] ))

print(combined_list)

# 5) Save combined_list to a CSV file
with open("cleaned_game_data.csv", "w", newline="", encoding="utf-8") as f:
    writer = csv.writer(f)
    # If you want headers, write them first
    writer.writerow(["Title", "Reviews Score Fancy", "Tags"])
    # Write each tuple (title, tag) to the CSV
    writer.writerows(combined_list)
