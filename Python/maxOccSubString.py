from collections import Counter

def max_occurring_substring(substring_list):
    count = Counter(substring_list)
    max_occurrence = max(count.values())
    return [k for k, v in count.items() if v == max_occurrence]

print(max_occurring_substring(["apple", "banana", "apple", "cherry", "banana", "apple"]))  
