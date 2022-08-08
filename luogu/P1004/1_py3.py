n = int(input())
mat = {}
while 1:
    x, y, v = map(int, input().split())
    if x == 0: break
    mat[(x-1, y-1)] = v
dp = {}
# dp[i, j]在step下表示，第1个人走到了(i, step-i)这个点，第2个人走到了(j, step-j)这个点的时候，能够获取的最多的值
for step in range(0, (n-1)*2+1):
    for i in range(step, 0-1, -1):
        for j in range(step, 0-1, -1):
            dp[(i, j)] = max({
                dp.get((i  , j  ), 0),
                dp.get((i  , j-1), 0),
                dp.get((i-1, j  ), 0),
                dp.get((i-1, j-1), 0),
                })
            if i == j:
                dp[(i, j)] += mat.get((i, step-i), 0)
            else:
                dp[(i, j)] += mat.get((i, step-i), 0) + mat.get((j, step-j), 0)
print (dp[(n-1, n-1)])

