# not use the fixed decimal

PRINT_TIMES = 100

def substitute(mu, x):
    return mu * x * (1 - x)

def x_output(x):
    return int(x*256)

i = input().split(' ')
mu, x = float(i[0]), float(i[1])

for i in range(1, PRINT_TIMES+1):
    x = substitute(mu, x)

    print(x_output(x))
