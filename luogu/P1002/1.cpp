#include <cstdio>
#include <cstring>
typedef long long LL;
const int N = 21;
int bn, bm, cn, cm;
LL dp[N][N];
bool judge(int x1, int y1){
    return x1 >= 0 && x1 < N && y1 >= 0 && y1 < N;
}
LL get(int x, int y){
    if (judge(x, y)) return dp[x][y];
    return 0;
}
void set(int x, int y, LL val){
    if (judge(x, y)) dp[x][y] = val;
}
int main()
{
    scanf("%d%d%d%d", &bn, &bm, &cn, &cm);
    memset(dp, -1, sizeof(dp));
    set(0, 0, 1);
    set(cn, cm, 0);
    set(cn+1, cm+2, 0);
    set(cn+1, cm-2, 0);
    set(cn-1, cm+2, 0);
    set(cn-1, cm-2, 0);
    set(cn+2, cm+1, 0);
    set(cn+2, cm-1, 0);
    set(cn-2, cm+1, 0);
    set(cn-2, cm-1, 0);
    for (int i = 0; i <= bn; ++ i){
        for (int j = 0; j <= bm; ++ j){
            if (dp[i][j] == -1){
                set(i, j, get(i-1, j) + get(i, j-1));
            }
        }
    }
    printf("%lld\n", dp[bn][bm]);
    return 0;
}