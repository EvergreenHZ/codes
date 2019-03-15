#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <set>

using namespace std;

const int MAXN = 510;
class Edge {
public:
        int u;
        int w;
};

vector<Edge> adj[MAXN];
stack<int> top_order;
int ve[MAXN], vl[MAXN];
int e[MAXN][MAXN], l[MAXN][MAXN];
int origin_indegree[MAXN], indegree[MAXN];
int N;
//set<pair<int, int> > activities;
vector<int> activities;

bool top_sort() {
        fill(ve, ve + MAXN, 0);
        queue<int> Q;
        for (int i = 0; i < N; i++) {
                if (indegree[i] == 0)
                        Q.push(i);
        }

        while (!Q.empty()) {
                int u = Q.front();
                top_order.push(u);

                for (int i = 0; i < adj[u].size(); i++) {
                        int v = adj[u][i].u, w = adj[u][i].w;
                        if (!--indegree[v])
                                Q.push(v);
                        if (ve[v] < ve[u] + w)
                                ve[v] = ve[u] + w;
                }
        }
        return top_order.size() == N ? true : false;
}

int critical_path() {
        if (!top_sort()) {
                return -1;
        }
        int max_len = -1;
        for (int i = 0; i < N; i++) {
                if (max_len < ve[i])
                        max_len = ve[i];
        }
        fill(vl, vl + MAXN, max_len);  // init all the vl
        while (!top_order.empty()) {
                int u = top_order.top();
                top_order.pop();

                for (int i = 0; i < adj[u].size(); i++) {
                        int v = adj[u][i].u, w = adj[u][i].w;
                        if (vl[u] > vl[v] - w)
                                vl[u] = vl[v] - w;
                }
        }

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < adj[i].size(); i++) {
                        int u = i, v = adj[i][j].u, w = adj[i][j].w;
                        e[u][v] = ve[u];
                        l[u][v] = vl[v] - w;
                        if (e[u][v] == l[u][v]) {
                                activities[u].push_back(v);
                                //activities.insert(pair<int, int>(u, v));
                        }
                }
        }
        return max_len;
}

int main() {
        return 0;
}
