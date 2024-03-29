from collections import Counter

n = int(input())
a = []

# Input array
for i in range(n):
    a.append(int(input()))

a.sort()

# Create a Counter to store the frequency of each element in the array
element_frequency = Counter(a)

count = 0

# Iterate over all pairs (i, j)
for i in range(n):
    for j in range(0, n):
        product = a[i] * a[j]

        # Check if the product exists in the array and increment count accordingly
        count += element_frequency[product]
        if product > a[-1]:
            break

print(count)
