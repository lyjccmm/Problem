# 进制转换

## 题目背景

无

## 题目描述

今天小明学会了进制转换，比如（10101）2 ，那么它的十进制表示的式子就是 :

1\*2^4+0\*2^3+1\*2^2+0\*2^1+1\*2^0，

那么请你编程实现，将一个M进制的数N转换成十进制表示的式子。

注意：当系数为0时，该单项式要省略。

## 输入格式

两个数，M和N，中间用空格隔开。

## 输出格式

共一行，一个十进制表示的式子。

## 样例 #1

### 样例输入 #1

```
2 10101
```

### 样例输出 #1

```
1*2^4+1*2^2+1*2^0
```

## 提示

对于100%的数据，1<M<10，N的位数不超过1000。