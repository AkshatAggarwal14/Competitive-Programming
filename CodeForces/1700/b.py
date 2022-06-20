t = int(input())
for tc in range(t):
    n = int(input())
    s = input()
    if s[0] == '9':
        print(int('1'*(n+1)) - int(s))
    else:
        print(int('9'*n)-int(s))
