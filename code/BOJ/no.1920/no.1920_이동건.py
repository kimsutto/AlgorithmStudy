n = int(input())
a = list(map(int, input().split()))
a.sort()
m = int(input())
k = list(map(int, input().split()))

for i in k:
    flag = 0
    left = 0
    right = len(a)

    while(left < right):
        mid = (left + right) // 2

        if(left == mid and i != a[mid]):
            break

        if(i > a[mid]):
            left = mid
        elif(i < a[mid]):
            right = mid
        elif(i == a[mid]):
            flag = 1
            print(1)
            break

    if(flag == 0):
        print(0)


