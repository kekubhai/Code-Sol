 
def find_nth_occurrence(haystack, needle, n):
    count = 0
    for i in range(len(haystack) - len(needle) + 1):
        if haystack[i:i+len(needle)] == needle:
            count += 1
            if count == n:
                return i
    return -1


haystack = "This is a test string. This is only a test."
needle = "is"
n = 3

index = find_nth_occurrence(haystack, needle, n-1)
if index != -1:
    print(f"The {n} occurrence of '{needle}' is at index {index}.")
else:
    print(f"The substring '{needle}' does not occur {n} times.")

# def nth_occurrence(s, sub, n):
#     index = -1
#     for _ in range(n):
#         index = s.find(sub, index + 1)
#         if index == -1:
#             return -1
#     return index

# print(nth_occurrence("hello hello hello", "hello", 3))
