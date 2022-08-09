#include <cstdio>

int a, b, c, d;
int main(){
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (d - b < 0) printf("%d %d\n", c-a-1, d-b+60);
    else printf("%d %d\n", c-a, d-b);
}
