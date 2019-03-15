#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>

const int MAXN = 1010;
const int INF = 0x3fffffff;

int G[MAXN][MAXN];
vector<int> adj[MAXN];
int indegree[MAXN], indegree_origin[MAXN];
bool known[MAXN], vis[MAXN], inque[MAXN];
vector<int> pre[MAXN];
int dist[MAXN];
int N;  // 0 -> N - 1


bool cmp(vector<int> &v1, vector<int> &v2) {
        int len = min(v1.size(), v2.size());
        for (int i = 0; i < len; i++) {
                if (v1[i] < v2[i]) return true;
        }
        if (v1.size() > len) return true;
        return false;
}
void dijkstra(int s) {
        fill(known, known + MAXN, false);
        fill(dist, dist + MAXN, INF);
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

                for (int k = 0; k < N; k++) {
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

vector<vector<int> > all_shortest_path;
void dfs_precessor(int s, vector<int> &path) {
        path.push_back(s);
        if (s == 0) {
                all_shortest_path.push_back(path);
                return;
        } else {
                for (int i = 0; i < pre[s].size(); i++) {
                        vector<int> t_path(path);
                        int v =pre[s][i];
                        dfs_precessor(v, t_path);
                }
        }
}

vector<vector<int> > all_top_seq;
// set vis:false before the call
void all_top_sort(vector<int> &indeg, vector<bool> &vis, vector<int> &top_seq) {
        if (top_seq.size() == N) {
                all_top_seq.push_back(top_seq);
                return;
        }
        vector<int> Q;
        for (int i = 0; i < N; i++) {
                if (!vis[i] && indeg[i] == 0) {
                        Q.push_back(i);
                }
        }

        for (int i = 0; i < Q.size(); i++) {
                int u = Q[i];
                vector<int> t_indeg(indeg);
                for (int j = 0; j < adj[u].size(); j++) {
                        t_indeg[j]--;
                }

                vector<bool> t_vis(vis);
                t_vis[u] = true;

                vector<int> t_top_seq(top_seq);
                t_top_seq.push_back(u);

                all_top_sort(t_indeg, t_vis, t_top_seq);
        }

}

// bfs a connected component
void bfs(int s) {
        fill(inque, inque + MAXN, false);
        vector<int> Q;
        Q.push(s);
        inque[s] = true;

        while (!Q.empty()) {
                int u = Q.front();

                for (int i = 0; i < adj[u].size(); i++) {
                        if (!inque[i]) {
                                Q.push_back(i);
                                inque[i] = true;
                        }
                }
        }
}

void bfs_graph() {
        for (int i = 0; i < N; i++) {
                if (!inque[i])
                        bfs(i);
        }
}

bool vis_dfs[MAXN];  // all to false
void dfs(int s, int depth) {  // add extra information
        vis_dfs[s] = true;
        for (int i = 0; i < adj[s].size(); i++) {
                if (!vis_dfs[i])
                        dfs(i, depth + 1);
        }
}

void dfs_graph() {
        // TODO
}


class Edge {
public:
        int v;
        int w;
        Edge(): v(-1), w(INF) {}
};
vector<Edge> Graph[MAXN];
int indegree_origin[MAXN];
int ve[MAXN], vl[MAXN];
int e[MAXN][MAXN], l[MAXN];
vector<int> activities[MAXN];
stack<int> top_sort_seq;

bool topological_sort() {
        fill(ve, ve + MAXN, 0);
        vector<int> Q;
        for (int i = 0; i < N; i++) {
                if (indegree_origin[i] == 0)
                        Q.push_back(i);
        }

        while (!Q.empty()) {
                int u = Q.front();
                top_sort_seq.push(u);

                for (int i = 0; i < Graph[u].size(); i++) {
                        indegree_origin[i]--;
                        if (indegree_origin[i] == 0) {
                                Q.push(i);
                        }
                        int v = Graph[u][i].v, w = Graph[u][i].w;
                        if (ve[v] < ve[u] + w)
                                ve[v] = ve[u] + w;
                }
        }
        if (top_sort_seq.size() != N) return false;
        return true;
}

int critical_path() {
        if (!topological_sort()) return -1;
        int max_len = -1;

        for (int i = 0; i < N; i++) {
                if (max_len < ve[i])
                        max_len = ve[i];
        }
        fill(vl, vl + MAX_LEN, max_len);

        while (!top_sort_seq.empty()) {
                int u = top_sort_seq.top();
                top_sort_seq.pop();

                for (int i = 0; i < Graph[u].size(); i++) {
                        int v = Graph[u][i].v, w = Graph[u][i].w;
                        if (vl[u] > vl[v] - w)
                                vl[u] = vl[v] - w;
                }
        }

        for (int u = 0; u < Graph.size(); u++) {
                for (int j = 0; j < Graph[u].size(); j++ ) {
                        int v = Graph[u][j].v, w = Graph[u][j].w;

                        e[u][v] = ve[u];
                        l[u][v] = vl[v] - w;
                        if (e[u][v] == l[u][v])
                                activities[u].push_back(v);
                }
        }
}
