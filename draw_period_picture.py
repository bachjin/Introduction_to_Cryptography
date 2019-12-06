import matplotlib.pyplot as plt

data = {'08':[], '16':[], '24':[], '32':[]}
mu = {'08':[], '16':[], '24':[], '32':[]}

try:
    while True:
        precise = str(input())
        data[precise].append(float(input()))
        mu[precise].append(float(input()))

except EOFError:
    pass
except IndexError:
    pass


plt.title('Period')

plt.plot(data['08'], mu['08'], color='skyblue', label='08', ls='-.', marker='*')
plt.plot(data['16'], mu['16'], color='green', label='16', ls='-.', marker='*')
plt.plot(data['24'], mu['24'], color='red', label='24', ls='-.', marker='*')
plt.plot(data['32'], mu['32'], color='black', label='32', ls='-.', marker='*')

plt.legend()
plt.xlabel('mu')
plt.ylabel('avg_period')

plt.savefig('period_curve.jpg')
plt.close()