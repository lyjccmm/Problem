#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 20000 + 10;

int n, B;
int a[N];

int main(){
    scanf("%d%d", &n, &B);
    for (int i = 0; i < n; ++ i){
        scanf("%d", a+i);
    }
    sort(a, a+n, greater<int>());
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        sum += a[i];
        if (sum >= B){
            printf ("%d\n", i+1);
            break;
        }
    }
}
