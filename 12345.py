from itertools import *
alf = 'АБВГДЯ'
k = 0
for x in product(alf, repeat = 4):
    s = ''.join(x)
    if s.count('Я') == 1:
        if s[0] == 'Я' or s[-1] == 'Я': 
            k += 1
    if s.count('Я') == 0: k += 1
print(k)
