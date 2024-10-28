def insert_in_string(s, sub, pos):
    return s[:pos] + sub + s[pos:]

print(insert_in_string("hello world", "awesome ", 7))
