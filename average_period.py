a = []

try:
    while True:
        a.append(int(input()))
except:
    pass

b = 0
n = len(a)

for i in range(n//2):
    b += (a[n//2 + i] - a[i]) / (n//2)

b = b / (n//2)

print(b)