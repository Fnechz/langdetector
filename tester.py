import pickle
import sys
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.tree import DecisionTreeClassifier

# Load the trained vectorizer and classifier
vectorizer = pickle.load(open("vectorizer.pkl", "rb"))
classifier = pickle.load(open("classifier.pkl", "rb"))

# Get the code snippet from the command line argument
code_snippet = sys.argv[1]

# Vectorize the code snippet
code_snippet_vectorized = vectorizer.transform([code_snippet])

# Predict the programming language
prediction = classifier.predict(code_snippet_vectorized)

# Print the predicted programming language
print(prediction[0])