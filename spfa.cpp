#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
const int INF = 0x3fffffff;
const int MAXN = 510;
class Node {
public:
        int to;
        int w;
        Node(): to(-1), w(INF) {}
};

vector<Node> adj[MAXN];
bool dist[MAXN];
bool inque[MAXN];
int num[MAXN];
int N;

bool spfa(int s) {
        fill(inque, inque + MAXN, false);
        fill(dist, dist + MAXN, INF);
        fill(num, num + MAXN, 0);
        dist[s] = 0;
        queue<int> Q;
        Q.push(s);
        inque[s] = true;
        num[s]++;
        while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                inque[u] = false;
                for (int i = 0; i < adj[u].size(); i++) {  // for each (u, v)
                        int v = adj[u][i].to;
                        int w = adj[u][i].w;
                        if (dist[v] > dist[u] + w) {
                                dist[v] = dist[u] + w;
                                if (!inque[v]) {
                                        Q.push(v);
                                        inque[v] = true;
                                        num[v]++;
                                        if (num[v] >= N) return false;
                                }
                        }
                }
        }
        return true;
}

int main() {
        
}
