def remove_after_substring(s, substring):
    index = s.find(substring)
    return s if index == -1 else s[:index + len(substring)]

print(remove_after_substring("hello_world_example", "hello"))  