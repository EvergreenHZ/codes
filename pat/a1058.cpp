#include <iostream>
#include <cstdio>
using namespace std;

int main() {
        int g1, g2, s1, s2, k1, k2;
        scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
        int g, s, k;
        g = g1 + g2;
        s = s1 + s2;
        k = k1 + k2;
        if (k >= 29) {
                k = k % 29;
                s++;
        }
        if (s >= 17) {
                s = s % 17;
                g++;
        }
        cout << g <<"."<<s<<"."<<k<<endl;
}
