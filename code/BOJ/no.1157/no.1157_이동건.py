word = input()
max = 0
alpha = ''
k = word.upper()
y = set(k)
for x in y:
    if(alpha != x):
        t = k.count(x)
        if (t > max):
            max = t
            alpha = x
        elif (t == max):
            alpha = "?"
    else:
        pass

print(alpha)