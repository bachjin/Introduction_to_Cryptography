a = []

try:
    while True:
        a.append(int(input()))
except:
    pass

b = 0
n = len(a)

print(sum(a) / len(a))