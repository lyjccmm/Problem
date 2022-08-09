#include <cstdio>
#include <algorithm>
using namespace std;
constexpr int N = 10;
constexpr int INF = 0x3f3f3f3f;
int n;
int x, y, val, mx;
int grid[N][N];
int dp[2][N][N]; // 2表示滚动数组，dp[i][j] 表示在当前斜线k上，第1个人走到第i个格子，第2个人走到第j个格子，的最大收益
bool ok(int x, int y) {
    if (x <= y)
        if (1 <= x && x <= n)
            if (1 <= y && y <= n)
                return true;
    return false;
}
int main() {
    scanf("%d", &n);
    while (1) {
        scanf("%d%d%d", &x, &y, &val);
        if (x == 0) break;
        grid[x][y] = val;
    }
    if (n == 1) {
        printf("%d\n", grid[1][1]);
        return 0;
    }
    dp[0][1][1] = grid[1][1];
    for (int k = 2; k <= n; ++ k) { // k表示斜线上格子的数量
        for (int i = 1; i <= k; ++ i) {
            for (int j = i; j <= k; ++ j) {
                mx = -INF;
                if (ok(i-1, j-1)) mx = max(mx, dp[k&1][i-1][j-1]);
                if (ok(i-1, j)) mx = max(mx, dp[k&1][i-1][j]);
                if (ok(i, j-1)) mx = max(mx, dp[k&1][i][j-1]);
                if (ok(i, j)) mx = max(mx, dp[k&1][i][j]);
                if (i == j) dp[k&1^1][i][j] = mx + grid[k-i+1][i];
                else dp[k&1^1][i][j] = mx + grid[k-i+1][i] + grid[k-j+1][j];
            }
        }
    }
    for (int k = n-1; k >= 1; -- k) {
        for (int i = 1; i <= k; ++ i) {
            for (int j = i; j <= k; ++ j) {
                mx = -INF;
                if (ok(i, j)) mx = max(mx, dp[k&1][i][j]);
                if (ok(i, j+1)) mx = max(mx, dp[k&1][i][j+1]);
                if (ok(i+1, j)) mx = max(mx, dp[k&1][i+1][j]);
                if (ok(i+1, j+1)) mx = max(mx, dp[k&1][i+1][j+1]);
                if (i == j) dp[k&1^1][i][j] = mx + grid[n-i+1][n-k+i];
                else dp[k&1^1][i][j] = mx + grid[n-i+1][n-k+i] + grid[n-j+1][n-k+j];
            }
        }
    }
    printf("%d\n", dp[0][1][1]);
}