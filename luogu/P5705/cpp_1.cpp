#include <cstdio>
#include <cstring>
const int N = 1000 + 10;

char s[N];
int main(){
    scanf("%s", s);
    int l = strlen(s);
    for(int i = l-1; i >= 0; -- i){
        putchar(s[i]);
    }
}
