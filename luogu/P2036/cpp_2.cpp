#include <cstdio>
#include <algorithm>
using namespace std;

const int N = (1 << 10) + 10;
const int INF = 0x7fffffff;
int n;
int S[N], B[N];
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &S[1 << i], &B[1 << i]);
    }
    int ans = INF;
    int ts = 1, tb = 0;
    for (int i = 1, j = 0, k; i < 1 << n; j = k, ++ i){
        k = i^i>>1;
        if (k - j > 0){
            ts *= S[k - j];
            tb += B[k - j];
        }
        else{
            ts /= S[j - k];
            tb -= B[j - k];
        }
        ans = min(ans, abs(ts-tb));
    }
    printf("%d\n", ans);
}