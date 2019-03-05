#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// starting from 1
const int MAXN = 10010;
vector<int> roots;
int g_max_depth = -1;
//bool G[MAXN][MAXN] = {0};
int father[MAXN];
bool vis[MAXN] = {false};
int N;  // number of nodes
vector<int> adj[MAXN];
//map<int, vector<int> > adj;  // node_id -> adjacent edges

int dfs(int u, int current_depth) {
        vis[u] = true;
        int max = current_depth;
        for (int i = 0; i < adj[u].size(); i++) {
                int next_depth = current_depth + 1;
                if (!vis[adj[u][i]]) {
                        int tmp = dfs(adj[u][i], next_depth);
                        if (max < tmp)
                                max = tmp;
                }
        }
        return max;
}

void init_father() {
        for (int i = 1; i <= N; i++) {
                father[i] = i;
        }
}

int find_root(int i) {
        if (father[i] == i) return i;
        else return father[i] = find_root(father[i]);
}

void Union(int i, int j) {
        int root_i = find_root(i);
        int root_j = find_root(j);
        if (root_i != root_j)
                father[root_i] = root_j;
}

int main() {
        scanf("%d", &N);
        for (int i = 1; i < N; i++) {
                int u, v;
                scanf("%d%d", &u, &v);
                //G[u][v] = true;
                //G[v][u] = true;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        init_father();
        for (int i = 1; i <= N; i++) {
                for (int j = 0; j < adj[i].size(); j++) {
                        //cout << adj[i][j] << " ";
                        Union(i, adj[i][j]);
                }
                //cout << endl;
        }
        int K = 0;
        for (int i = 1; i <= N; i++) {
                //cout << father[i] << " ";
                if (father[i] == i) {
                        K++;
                        //cout << "Root FOUND" << endl;
                }
        }
        //cout << endl;
        if (K > 1) {
                cout << "Error: " << K << " components" << endl;
        } else {
                //cout << "Here are " << K <<" components"<< endl<< "starting DFS" << endl;
                for (int i = 1; i <= N; i++) {
                        fill(vis, vis + N + 1, false);
                        int tmp = dfs(i, 0);
                        if (tmp > g_max_depth) {
                                roots.clear();
                                roots.push_back(i);
                                g_max_depth = tmp;
                        } else if (tmp == g_max_depth) {
                                roots.push_back(i);
                        }
                        //cout << tmp<< " : " << g_max_depth << endl;
                }
                for (int j = 0; j < roots.size(); j++)
                        cout << roots[j] << endl;
        }
}
