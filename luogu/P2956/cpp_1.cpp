#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 240 + 10;

int n, m, q;
int a[N][N];

int main(){
    scanf("%d%d%d", &n, &m, &q);
    int x1, y1, x2, y2;
    for (int i = 0; i < q; ++ i){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        a[x1  ][y1  ] += 1;
        a[x1  ][y2+1] -= 1;
        a[x2+1][y1  ] -= 1;
        a[x2+1][y2+1] += 1;
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            a[i][j] += a[i][j-1];
        }
    }
    for (int j = 1; j <= m; ++ j){
        for (int i = 1; i <= n; ++ i){
            a[i][j] += a[i-1][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            ans += a[i][j] == 0 ? 0 : 1;
        }
    }
    printf ("%d\n", ans);

}
