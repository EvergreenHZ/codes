#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 10010;
int colors[MAXN] = {-1};
bool vis[MAXN] = {false};
int G[MAXN][MAXN] = {0};
int N, M;  // number of nodes
int edges_u[MAXN] = {0};
int edges_v[MAXN] = {0};

bool dfs(int u) {
        vis[u] = true;
        // for each unvisited node adjacent to u
        for (int i = 0; i < N; i++) {
                if (G[u][i] && vis[i] == false) {
                        if (colors[u] == colors[i]) return false;  // not k-coloring
                        else return dfs(i);
                }
        }
        return true;
}

int is_k_coloring() {
        int k = -1;
        set<int> s;
        for (int i = 0; i < N; i++) {
                s.insert(colors[i]);
                // search a connected component
                if (vis[i] == false) {
                        if (!dfs(i)) return -1;  // not k-coloring
                }
        }
        return s.size();
}

int check() {
        set<int> s;
        for (int i = 0; i < M; i++) {
                if (colors[edges_u[i]] == colors[edges_v[i]])
                        return -1;
        }
        for (int i = 0; i < N; i++) {
                s.insert(colors[i]);
        }
        return s.size();
}
int main() {
        scanf("%d %d", &N, &M);
        int l_count = 0;
        for (int i = 0; i < M; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                edges_u[l_count] = u;
                edges_v[l_count] = v;
                l_count++;
                G[u][v] = 1;
                G[v][u] = 1;
        }
        int K;  // K test case
        scanf("%d", &K);
        while (K--) {  // for each test case
                fill(colors, colors + N, -1);
                fill(vis, vis + N, false);
                for (int i = 0; i < N; i++) {
                        int x;
                        scanf("%d", &x);
                        colors[i] = x;
                }
                //int k = is_k_coloring();
                //int k = check();
                int k = is_k_coloring();
                if (k != -1) {
                        printf("%d-coloring\n", k);
                } else {
                        printf("No\n");
                }
        }
        return 0;
}
