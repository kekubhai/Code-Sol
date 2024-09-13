input_string = input("Enter the string")

words = input_string.lower().split()
word_count = {}
for word in words:
    if word in word_count:
        word_count[word] += 1
    else:
        word_count[word] = 1


print("Word counts:")
for word, count in word_count.items():
    print(f"'{word}': {count}")