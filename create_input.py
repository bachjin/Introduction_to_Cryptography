mu_init = float(input("mu first value:"))
mu_pace = float(input("mu increase pace:"))
x_init = float(input("x first value:"))
x_pace = float(input("x increase pace:"))

file_name = "1.in"
directory= "./data/"

def add_filename(file_name):
    tmp = int(file_name.split('.')[0])
    tmp += 1
    new_name = str(tmp) + '.' + file_name.split('.')[1]
    return new_name

mu = mu_init
x = x_init

mu_list = open('./data/mu_list.txt', 'w')

for precise in range(8, 40, 8):
    mu = mu_init
    while mu < 4 and mu > 3.57:
        mu_list.write("%f\n" % mu)
        x = x_init
        while 1 - x > 1e-10 and x > 0:
            if precise >= 10:
                full_name = directory + '%2d-'%precise + \
                    '%5f'%mu + '-' + file_name
            else:
                p = '0' + '%1d'%precise + '-'
                full_name = directory + p + \
                    '%5f'%mu + '-' + file_name

            f = open(full_name, "w")
            print(precise, mu, x, file=f)
            f.close()

            x += x_pace
            file_name = add_filename(file_name)
        mu += mu_pace
        file_name = "1.in"
    
mu_list.close()