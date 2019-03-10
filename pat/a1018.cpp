#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 510;
const int INF = 1000000;
int Capacity_max, N_stations, S_problem, M_roads;
int G[MAXN][MAXN];
int capacities[MAXN];
int perfect_bikes_n;
bool known[MAXN];
int dist[MAXN];
vector<int> pre[MAXN];

int take_back;
int send_out;
vector<int> opt_path;
int g_count = 0;

void dijkstra(int s) {
        fill(known, known + N_stations + 1, false);
        fill(dist, dist + N_stations + 1, INF);
        dist[s] = 0;

        for (int i = 0; i <= N_stations; i++) {
                int u = -1, min = INF;
                for (int j = 0; j <= N_stations; j++) {
                        if (!known[j] && min > dist[j]) {
                                u = j;
                                min = dist[j];
                        }
                }
                if (u == -1) return ;
                known[u] = true;
                for (int k = 0; k <= N_stations; k++) {
                        if (!known[k] && G[u][k] < INF) {
                                if (dist[k] > dist[u] + G[u][k]) {
                                        dist[k] = dist[u] + G[u][k];
                                        pre[k].clear();
                                        pre[k].push_back(u);
                                } else if (dist[k] == dist[u] + G[u][k]) {
                                        pre[k].push_back(u);
                                }
                        }
                }
        }
}

void dfs(int s, int sum_of_bikes, int num_of_stations, vector<int> &t_path) {
        t_path.push_back(s);
        if (s == 0) {  // root
                int diff = sum_of_bikes - perfect_bikes_n * num_of_stations;  // maybe negtive

                int t_take_back, t_send_out;
                if (diff > 0) {
                        t_send_out = 0;
                        t_take_back = diff;
                } else {
                        t_send_out = -diff;
                        t_take_back = 0;
                }
                if (send_out > t_send_out) {
                        send_out = t_send_out;
                        take_back = t_take_back;
                        opt_path = t_path;
                } else if (send_out == t_send_out) {
                        if (take_back > t_take_back) {
                                take_back = t_take_back;
                                opt_path = t_path;
                        }
                }
                g_count ++;
                return ;
        }
        for (int i = 0; i < pre[s].size(); i++) {
                vector<int> tt = t_path;
                dfs(pre[s][i], sum_of_bikes + capacities[s], num_of_stations + 1, tt);
        }
}

int main() {
        scanf("%d %d %d %d", &Capacity_max, &N_stations, &S_problem, &M_roads);
        fill(G[0], G[0] + MAXN * MAXN, INF);
        perfect_bikes_n = Capacity_max / 2;
        for (int i = 1; i <= N_stations; i++) {  // node weight
                scanf("%d", &capacities[i]);
        }
        for (int i = 1; i <= M_roads; i++) {  // edge weight
                int si, sj, time_ij;
                scanf("%d %d %d", &si, &sj, &time_ij);
                G[si][sj] = time_ij;
                G[sj][si] = time_ij;
        }

        take_back = INF;
        send_out = INF;
        dijkstra(0);
        vector<int> t_path;
        dfs(S_problem, 0, 0, t_path);

        printf("%d ", send_out);
        for (int i = opt_path.size() - 1; i >= 0; i--) {
                printf("%d%s", opt_path[i], i == 0? " ": "->");
        }
        printf("%d\n", take_back);
        return 0;
}
