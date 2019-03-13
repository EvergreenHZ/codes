#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

const int MAXN = 1001;;
vector<int> adj[MAXN];
int arr_indegree[MAXN];
vector<int> indegree;
int N, M;

bool is_satisfied(vector<int> &v, vector<int> ind) {
        vector<bool> vis(v.size(), false);
        for (int i = 0; i < v.size(); i++) {
                if (ind[v[i]] == 0) {
                        vis[v[i]] = true;
                        for (int j = 0; j < adj[v[i]].size(); j++) {
                                ind[adj[v[i]][j]]--;
                        }
                } else {
                        return false;
                }
        }
        return true;
}

int main() {
        scanf("%d %d", &N, &M);
        fill(arr_indegree, arr_indegree + MAXN, 0);
        for (int i = 0; i < M; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                adj[u].push_back(v);
                arr_indegree[v] ++;
        }

        indegree.push_back(0);  // starting from 1
        for (int i = 1; i <= N; i++)
                indegree.push_back(arr_indegree[i]);

        int K;
        scanf("%d", &K);
        vector<int> result;
        for (int i = 0; i < K; i++) {
                vector<int> v;
                for (int j = 0; j < N; j++) {
                        int u;
                        scanf("%d", &u);
                        v.push_back(u);
                }
                if (!is_satisfied(v, indegree)) {
                        result.push_back(i);
                }
        }
        for (int i = 0; i < result.size(); i++) {
                printf("%d%c", result[i], i == result.size() - 1? '\n':' ');
        }
        return 0;
}
