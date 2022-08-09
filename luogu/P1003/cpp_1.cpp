#include <cstdio>
const int N = 10000 + 10;

struct Rect {
    int x, y, w, h;
} a[N];

bool inRect(int tx, int ty, Rect &rect) {
    if (rect.x <= tx && tx <= rect.x+rect.w)
        if (rect.y <= ty && ty <= rect.y+rect.h)
            return true;
    return false;
}
int n, x, y;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].w, &a[i].h);
    }
    scanf("%d%d", &x, &y);
    for (int i = n-1; i >= 0; -- i) {
        if (inRect(x, y, a[i])) {
            printf("%d\n", i+1);
            return 0;
        }
    }
    puts("-1");
}