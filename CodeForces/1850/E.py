import math

t = int(input())
for tt in range(t):
    n, c = map(int, input().split())
    a = [x for x in map(int, input().split())]
    s = 0
    p = 0
    for x in a:
        s += x
        p += x * x
    print(int((math.sqrt(s * s - n * (p - c)) - s) // (2 * n)))