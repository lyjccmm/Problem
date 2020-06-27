#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10 + 10;
const int INF = 0x7fffffff;
int n;
int S[N], B[N];
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &S[i], &B[i]);
    }
    int ans = INF;
    int ts, tb;
    for (int i = 1; i < 1 << n; ++ i){
        ts = 1;
        tb = 0;
        for (int j = 0; i >> j ; ++ j){
            if ((i >> j) & 1){
                ts *= S[j];
                tb += B[j];
            }
        }
        ans = min(ans, abs(ts-tb));
    }
    printf("%d\n", ans);
}