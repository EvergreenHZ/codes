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
