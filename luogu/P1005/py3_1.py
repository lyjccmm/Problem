n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
sum = 0
for i in range(n):
    l, r = 0, m-1
    dp = {}
    for dis in range(m):
        for l in range(m-dis):
            r = l + dis
            dp[(l, r)] = max(
                dp.get((l, r-1), 0) * 2 + a[i][r],
                dp.get((l+1, r), 0) * 2 + a[i][l]
            )
    sum += dp[(0, m-1)] * 2
print(sum)
