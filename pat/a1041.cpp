#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 10010;
int g_count[MAXN] = {0};

int main() {
        int N;
        scanf("%d", &N);
        vector<int> v;
        for (int i = 0; i < N; i ++) {
                int x;
                scanf("%d", &x);
                v.push_back(x);
                g_count[x] ++;
        }

        for (int i = 0; i < v.size(); i++) {
                if(g_count[v[i]] == 1) {
                        cout << v[i] << endl;
                        return 0;
                }
        }
        cout << "None" << endl;
        return 0;
}
