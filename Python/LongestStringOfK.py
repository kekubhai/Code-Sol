def longest_substring_of_k(s, k):
    max_length = current_length = 0
    for char in s:
        if char == k:
            current_length += 1
            max_length = max(max_length, current_length)
        else:
            current_length = 0
    return max_length

print(longest_substring_of_k("aaabbbaaaaccc", 'a'))  
