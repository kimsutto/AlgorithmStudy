n = input()
count = 0

for i in range(1, int(n)+1):
    j = str(i)
    if(i < 100):
        count = count + 1
    elif(100 <= i <= 1000):
        k = int(j[0]) - int(j[1])
        if(int(j[1]) - int(j[2]) == k):
            count = count + 1

print(count)


