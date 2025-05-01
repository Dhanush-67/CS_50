from cs50 import get_string

text = get_string("Enter: ")
sentence_count = text.count(".") + text.count("!") + text.count("?")
word_count = 0
letter_count = 0

for word in text.split():
    word_count += 1
    for c in word:
        if c.isalpha():
            letter_count += 1

index = round(0.0588 * (letter_count/word_count*100) -
              0.296 * (sentence_count/word_count*100) - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
