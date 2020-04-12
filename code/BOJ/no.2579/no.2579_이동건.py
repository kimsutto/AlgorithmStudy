import sys

n = int(sys.stdin.readline())

k = []

for _ in range(n):
    k.append(int(sys.stdin.readline()))

dp = [0 for i in range(n)]

dp[0] = k[0]
dp[1] = k[0] + k[1]
dp[2] = max(k[0] + k[2], k[1] + k[2])

for i in range(3, n):
    dp[i] = k[i] + max(k[i-1] + dp[i-3], dp[i-2])

print(dp[-1])