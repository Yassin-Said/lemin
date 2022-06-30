import random
alphabet = "abcdefghijklmnopqrstuvwxyz"
a = 0
b = 0
c = 0
d = 0
e = 0
i = 0

while (a != 'r' or b != 'u' or c != 'k' or d != 'i' or e != 'a') and (a != 'l' or b != 'u' or c != 'x' or d != 'a' or e != 'n') and (a != 'h' or b != 'u' or c != 't' or d != 'a' or e != 'o'):
    a = alphabet[random.randint(0,25)]
    b = alphabet[random.randint(0,25)]
    c = alphabet[random.randint(0,25)]
    d = alphabet[random.randint(0,25)]
    e = alphabet[random.randint(0,25)]
    print (i)
    i += 1
    print (a, b, c, d, e)

