#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

const int MAXN = 1001;;
vector<int> adj[MAXN];
int N, M;
vector<vector<int> > result;

void print_vec(vector<int> &v) {
        for (int i = 1; i < v.size(); i++) {
                cout << v[i] << " ";
        }
        cout << endl;

}
void print_res() {
        for (int i = 0; i < result.size(); i++) {
                for (int j = 0; j < result[i].size(); j++) {
                        cout << result[i][j] << " ";
                }
                cout << endl;
        }
        return ;
}

void all_top_sorts(vector<int> &indgree, vector<bool> &vis, vector<int> &res) {
        if (res.size() == N) {
                result.push_back(res);
                return;
        }

        vector<int> nodes_with_0_indegree;
        for (int i = 1; i <= N; i++) {
                if (!indgree[i] && !vis[i]) {
                        nodes_with_0_indegree.push_back(i);
                }
        }

        for (int i = 0; i < nodes_with_0_indegree.size(); i++) {
                vector<int> t_indegree(indgree);
                for (int j = 0; j < adj[nodes_with_0_indegree[i]].size(); j++) {
                        t_indegree[adj[nodes_with_0_indegree[i]][j]]--;
                }

                vector<bool> t_vis(vis);
                t_vis[nodes_with_0_indegree[i]] = true;

                vector<int> t_res(res);
                t_res.push_back(nodes_with_0_indegree[i]);

                all_top_sorts(t_indegree, t_vis, t_res);
        }
}

int main() {
        scanf("%d %d", &N, &M);
        vector<int> indegree(N + 1, 0);
        for (int i = 0; i < M; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                adj[u].push_back(v);
                indegree[v] ++;
        }
        vector<int> res;
        vector<bool> vis(N + 1, false);
        all_top_sorts(indegree, vis, res);
        print_res();
        return 0;
}
