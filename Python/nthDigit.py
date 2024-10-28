def nth_digit(number, n):
    for _ in range(n - 1):
        number //= 10
    return number % 10

print(nth_digit(12645, 3))  