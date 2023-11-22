import os
import shutil
import random

print("running.... moffo...")
data_dir = 'newdata'  # Your main data directory
train_dir = 'train01'
test_dir = 'test01'
split_ratio = 0.8  # Adjust as needed (e.g., 0.8 for 80% training data)

# Create the train and test directories
os.makedirs(train_dir, exist_ok=True)
os.makedirs(test_dir, exist_ok=True)

# Get a list of subdirectories (programming languages)
languages = [lang for lang in os.listdir(data_dir) if os.path.isdir(os.path.join(data_dir, lang))]

# Split the data into train and test sets
for lang in languages:
    lang_dir = os.path.join(data_dir, lang)
    train_lang_dir = os.path.join(train_dir, lang)
    test_lang_dir = os.path.join(test_dir, lang)

    os.makedirs(train_lang_dir, exist_ok=True)
    os.makedirs(test_lang_dir, exist_ok=True)

    files = os.listdir(lang_dir)
    random.shuffle(files)  # Shuffle the files randomly

    split_index = int(len(files) * split_ratio)

    train_files = files[:split_index]
    test_files = files[split_index:]

    # Copy the files to the train and test directories
    for file in train_files:
        src = os.path.join(lang_dir, file)
        dst = os.path.join(train_lang_dir, file)
        shutil.copy(src, dst)

    for file in test_files:
        src = os.path.join(lang_dir, file)
        dst = os.path.join(test_lang_dir, file)
        shutil.copy(src, dst)

print("Data split completed.")
