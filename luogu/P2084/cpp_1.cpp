#include <cstdio>
#include <cstring>

const int N = 1000 + 10;

int m;
char s[N];

int main(){
    scanf("%d%s", &m, s);
    int len = strlen(s);
    bool add_flag = 0;
    for (int i = 0; i < len; ++ i){
        if (s[i] != '0'){
            if (add_flag) printf("+");
            else add_flag = 1;
            printf("%d*%d^%d", s[i] - '0', m, len-i-1);
        }
    }
    puts ("");
}
