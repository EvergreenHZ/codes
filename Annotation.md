# iterate times
```C
while (n--) {}  // loops for n times
while (--n) {}  // loops for n - 1 times
```

# Boundary Case
pay attention to **Boundary Situation**

# 除基取余法
do {
        a[i++] = n % base;
        n /= base;
} while (n);
reverse a;

# find first appearance in a c_string
```C
char *p = strchr(s, ' ');
```
p may be NULL if ' ' not exist


# read a line from stdin
```C
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

string s;
getline(cin, s);  // get a line from stdin
```

# round
```C
#include <cmath>
round(0.9);  // 1  四舍五入
```

# INPUT
scanf("%s %d:%d:%d", s, &hh, &mm, &ss);

# sort and cmp
```C
bool cmp(T a, T b) {
        if (a.key != b.key)
                return a.key < b.key;
}

vector<T> A[100];
sort(A, cmp);
```

# judge even or odd
```C
if (x % 2 == 0) {
        return "Even";
} else {
        return "Odd";
}
```

# String


# N--
如果还要用到N, 要保存N

# 感觉做对了，但是有case过不了，再看一下题目  list_sorting

# 注意输入情况， 是否重复输入  gang, same person to same person call
AAA BBB 1
AAA BBB 3

# Node* root = NULL  bst a1043
赋值很重要， 初始化, 否则很可能段错误
传指针类型的引用
如果有不清晰的， 一定要用笔先模拟一下
**先用笔写下， 大步骤**

# 循环控制再一轮  a1098
int flag = 0;
int limit = 0;
if satisfy:
        flag ++;
        limit = j + 1;
if (flag && limit == j):
        return;

# find_and_union 务必初始化!!!!!

# 输出大小写

# 审题第一， 注意题目给的数据范围
printf: output->stdout
scanf: input->variable
sprintf: output->string
sscanf: string->variable

# 没有什么比数组下表映射更快的 a1149

# G[MAXN][MAXN]
two dimension
```C
fill(G[0], G[0] + MAXN * MAXN, INF);
```

# read a line from stdin withour newline
```C
#include <cstring>
char s[100];
fgets(s, 100, stdin);
char *p = strchr(s, '\n');
*p = '\0';
```
