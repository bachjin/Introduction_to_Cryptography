import sys
import matplotlib.pyplot as plt

outlist = open('./data/outlist.txt', 'r')
for file_name in outlist.read().split('\n'):
    if file_name == '':
        break
    file_name = './data/' + file_name
    f = open(file_name, 'rb')

    y = []
    i = 0
    for line in f.read():
        i += 1
        if i < 150:
            continue
        elif i > 300:
            break
        else:
            y.append(int(line))

    x = range(1, 1 + len(y))

    plt.plot(x, y)

    file_first_name = file_name[:len(file_name) - 3]    #ends with .out
    plt.savefig(file_first_name + 'jpg')
    plt.close()
    f.close()

outlist.close()