t = int(input())
for i in range(0, t):
    n = int(input())
    s = input()
    first1 = last1 = -1
    for i in range(0, n):
        if s[i] == '1':
            first1 = i
            break
    for i in range(0, n):
        if s[i] == '1':
            last1 = i
    ans = n
    if first1 != -1:
        ans = max(ans, 2 * (n - first1), 2 * (last1 + 1))
    print(ans)