mu_init = 3.6
x_init = 0.1
mu_pace = 0.2
x_pace = 0.3

file_name = "1.in"
directory= "./data/"

def add_filename(file_name):
    tmp = int(file_name.split('.')[0])
    tmp += 1
    new_name = str(tmp) + '.' + file_name.split('.')[1]
    return new_name

mu = mu_init
x = x_init

while mu < 4:
    x = x_init
    while x < 1:
        full_name = directory + file_name

        f = open(full_name, "w")

        print(mu, x, file=f)

        x += x_pace
        file_name = add_filename(file_name)
        f.close()
    mu += mu_pace
    