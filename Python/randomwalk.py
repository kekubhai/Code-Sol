
import random

def random_walk(n):
    x, y = 0, 0
    for _ in range(n):  
        dx, dy = random.choice([(0, 1), (0, -1), (1, 0), (-1, 0)])  
        x += dx
        y += dy
    return (x, y)  

n = 10000
final_pos = random_walk(n)
print(final_pos)
