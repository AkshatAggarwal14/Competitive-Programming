import random
print(1)
print(2000)
for i in range(1,2001):
    print(random.randint(1,2000), file=open('output.txt','a'))
