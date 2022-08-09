#include <cctype>
#include <cstdio>
int main(){
    putchar(toupper(getchar()));
}

// cctype里面还有好多函数，c里面头文件是ctype.h
// int toupper ( int c ); 变大写字母
// int tolower ( int c ); 变小写字母
// int isupper ( int c ); 判断是大写字母
// int islower ( int c ); 判断是小写字母
// int isdigit ( int c ); 判断是数字
// int isspace ( int c ); 判断空白字符（包括' ','\t','\n','\v','\f','\r'）