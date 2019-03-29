#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN];

int main() {
        int N, M;
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        int K;
        scanf("%d", &K);
        while (K--) {
                int L;
                scanf("%d", &L);
                bool flag = true;
                int u, v;
                bool isExist[MAXN];
                fill(isExist, isExist + MAXN, false);
                while (L--) {
                        scanf("%d %d", &u, &v);
                        if (isExist[u] || isExist[v]) {
                                flag = false;
                        }
                        isExist[u] = true;
                        isExist[v] = true;
                }
                if (flag == false) {
                        printf("Not a Matching\n");
                } else {  // is a matching
                        bool t_flag = false;
                        for (int i = 1; i <= N; i++) {
                                for (int j = 0; j < adj[i].size(); j++) {
                                        int u = i, v = adj[i][j];
                                        if (isExist[u] || isExist[v]) {
                                                continue;
                                        }
                                        if (!isExist[u] && !isExist[v]) {
                                                t_flag = true;
                                                break;
                                        }
                                }
                                if (t_flag) break;
                        }
                        printf(t_flag ? "Not Maximal\n" : "Yes\n");
                }
        }
        return 0;
}
