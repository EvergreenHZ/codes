#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 501;
const int INF = 1000000;
int G[MAXN][MAXN] = {0};
int cost[MAXN][MAXN] = {0};
int dist[MAXN] = {0};
bool known[MAXN] = {false};
int pre[MAXN] = {0};
int c[MAXN] = {0};
int N, M, S, D;

void dijkstra(int s) {
        // init
        fill(pre, pre + N, -1);
        fill(dist, dist + N, INF);
        fill(known, known + N, false);
        fill(c, c + N, INF);
        c[s] = 0;
        dist[s] = 0;
        for (int i = 0; i < N; i++) {
                int u = -1, min = INF;
                for (int j = 0; j < N; j++) {
                        if (!known[j] && min > dist[j]) {
                                min = dist[j];
                                u = j;
                        }
                }

                if (u == -1) return;  // not connected

                known[u] = true;
                for (int k = 0; k < N; k++) {  // for each unknown node adjacent to u
                        if (!known[k] && G[u][k] < INF) {
                                if (dist[k] > dist[u] + G[u][k]) {
                                        dist[k] = dist[u] + G[u][k];
                                        pre[k] = u;
                                        c[k] = c[u] + cost[u][k];
                                } else if (dist[k] == dist[u] + G[u][k]) {
                                        if (c[k] > c[u] + cost[u][k]) {
                                                pre[k] = u;
                                                c[k] = c[u] + cost[u][k];
                                        }
                                }
                        }
                }
        }
}

void print_path(int u) {
        if (pre[u] == -1) {
                printf("%d", u);
        } else {
                print_path(pre[u]);
                printf(" %d", u);
        }
}

int main() {
        fill(G[0], G[0] + MAXN * MAXN, INF);
        fill(cost[0], cost[0] + MAXN * MAXN, INF);

        scanf("%d %d %d %d", &N, &M, &S, &D);
        for (int i = 0; i < M; i++) {
                int c1, c2, d, cc;
                scanf("%d %d %d %d", &c1, &c2, &d, &cc);
                G[c1][c2] = d;
                G[c2][c1] = d;
                cost[c1][c2] = cc;
                cost[c2][c1] = cc;
        }
        dijkstra(S);
        print_path(D);
        printf(" %d %d\n", dist[D], c[D]);
        return 0;
}
