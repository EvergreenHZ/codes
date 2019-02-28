#include <iostream>
#include <cstdio>
#include <vector>

const int INF = 1000000;
const int MAXN = 510;
int N, M;
int C1, C2;
int rescue_teams[MAXN] = {0};
int G[MAXN][MAXN] = {0};
int num[MAXN] = {0};
int vis[MAXN] = {0};
int dist[MAXN] = {0};
int weights[MAXN] = {0};  // C1 -> i: max_rescue_team

void read_input() {
        scanf("%d %d %d %d", &N, &M, &C1, &C2);
        for (int i = 0; i < N; i++) {
                int x;
                scanf("%d", &x);
                rescue_teams[i] = x;
        }
        for (int i = 0; i < M; i++) {
                int c1, c2, l;
                scanf("%d %d %d", &c1, &c2, &l);
                G[c1][c2] = l;
                G[c2][c1] = l;
        }
}

void init() {
        read_input();
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (G[i][j] == 0) G[i][j] = INF;
                                                  }
        }
        num[C1] = 1;
        for (int i = 0; i < N; i++) {
                dist[i] = INF;
        }
        dist[C1] = 0;
        weights[C1] = rescue_teams[C1];
}

void dijstra_walk(int s, int end) {
        
}

int main() {
        init();
}
