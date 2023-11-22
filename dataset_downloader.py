# from  datasets  import  load_dataset
# import os

# # specific language (e.g. python)
# # dataset streaming (will only download the data as needed)
# ds = load_dataset("bigcode/the-stack",streaming=True, data_dir="data/rust", split="train")

# # Loop through the samples and write them to files
# for i, sample in enumerate(iter(ds)):
#     content = sample["content"]
#     # lang = sample["lang"]
#     size = sample["size"]

#     print("Content is: ", content)

#     if i == 5:  # Stop after n iterations
#         break


from datasets import load_dataset
import os
import random
import string

# List of programming languages


print("running like a tortoise")

# languages = [
#     "ada", "assembly", "c", "cmake",
#     "fortran", "haskell", "dockerfile", "fortran", 
#     "haskell", "html", "julia", "lua", "makefile", 
#     "markdown", "perl", "php", "rust", "tex", 
#     "typescript", "visual-basic",
# ]


languages = [
    "yaml", "ocaml", "kotlin", "common-lisp",
    "erlang", "json", "emacs-lisp",
    "matlab", "prolog", "mathematica", "pascal", 
    "scheme", "r", "asp", "cobol", "elixir", "smalltalk",
    "verilog",
]




# Create a dictionary to store code snippets by language
code_snippets = {lang: [] for lang in languages}

# Function to generate a random file name
def generate_random_filename():
    letters_and_digits = string.ascii_letters + string.digits
    return ''.join(random.choice(letters_and_digits) for _ in range(10))

# Function to save code snippets
def save_code_snippets(lang):
    folder_path = os.path.join("newdata", lang)
    os.makedirs(folder_path, exist_ok=True)
    for i, snippet in enumerate(code_snippets[lang], start=1):
        file_name = f"{generate_random_filename()}.txt"
        file_path = os.path.join(folder_path, file_name)
        with open(file_path, "w") as file:
            file.write(snippet)
    print(f"Saved code snippet for {lang}:")

# Download the dataset and stream it
for lang in languages:
    dataset_name = "bigcode/the-stack"
    ds = load_dataset(dataset_name, streaming=True, data_dir=f"data/{lang}", split="train")
    print("At the following language:" , lang)

    # Iterate through the samples and organize by language
    for sample in ds:
        content = sample["content"]
        code_snippets[lang].append(content)

        # If you've collected a sufficient number of snippets, save them to files
        if len(code_snippets[lang]) == 1500:
            save_code_snippets(lang)
            code_snippets[lang] = []  # Reset the list to save new snippets in a new folder
            break

# Save any remaining code snippets
for lang in languages:
    if code_snippets[lang]:
        save_code_snippets(lang)