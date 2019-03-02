#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100010;
int P[MAXN] = {0};
int index[MAXN] = {0};
int N;
int count = 0;

void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
        count ++;
}

int main() {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                int x;
                scanf("%d", &x);
                P[i] = x;
                index[x] = i;
        }
        int k = 0;

        while (true) {
                while (index[0] != 0) {
                        swap(index[0], index[index[0]]);
                }
                while (index[k] == k)
                        k++;
                if (k == N)
                        break;
                swap(index[0], index[k]);

        }
        cout << count << endl;
}
