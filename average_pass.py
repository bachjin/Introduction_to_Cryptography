class test(object):
    ''''''
    def __init__(self):
        self.n = 0
        self.psum = 0
        self.pn = 0
        self.fa = 0
        self.we = 0
        self.pa = 0

    def count(self, words):
        self.n += 1

        self.psum += float(words[4])
        if float(words[4]) != 0:
            self.pn += 1

        if words[5].find('WEAK') != -1:
            self.we += 1
        elif words[5].find('FAIL') != -1:
            self.fa += 1
        elif words[5].find('PASS') != -1:
            self.pa += 1
        
    def print(self):

        print("FAILED ", self.fa)
        print("WEAK ", self.we)
        print("PASSED ", self.pa)
        try:
            aver_p = self.psum / self.pn
        except ZeroDivisionError:
            aver_p = 0
        print("p_average ", aver_p)


def main():
    lines = []

    try:
        while True:
            lines.append(str(input()))
            if lines[-1] == '':
                break
    except EOFError:
        pass


    bitstream = test()
    count1str = test()
    count1byt = test()


    for line in lines:
        words = line.split('|')
        if words[0].find('bit') != -1:
            bitstream.count(words)
        elif words[0].find('str') != -1:
            count1str.count(words)
        elif words[0].find('byt') != -1:
            count1byt.count(words)
        else:
            pass


    print('bitstream')
    bitstream.print()
    print('count_1s_str')
    count1str.print()
    print('count_1s_byt')
    count1byt.print()

if __name__ == '__main__':
    main()