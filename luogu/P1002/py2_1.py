# python2
n, m, hn, hm = map(int, raw_input().split())
dp = {(0, 0): 1, (hn, hm): 0}
for i in [-1, 1]:
    for j in [-1, 1]:
        for k in [1, 2]:
            dp[(i*k+hn, j*(3-k)+hm)] = 0
for i in xrange(n+1):
    for j in xrange(m+1):
        if dp.get((i, j)) is None:
            dp[(i, j)] = dp.get((i-1, j), 0) + dp.get((i, j-1), 0)
print dp[(n, m)]