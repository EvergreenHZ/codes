#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 10000000;
const int MAXN = 1000;
int G[MAXN][MAXN];  // weights on edges
int vis[MAXN];

class Node {
public:
        int d;
        int pre;
        int node_num;

        Node(int i): d(INF), pre(-1), node_num(i) {}
        bool operator < (const Node &n) {
                if (n.d != d) return d < n.d;
        }
};

vector<Node> nodes;

void init(int s) {
        /* fill G */
        int K = 100;  // number of Nodes
        for (int i = 0; i < K; i++) {
                nodes.push_back(Node(i));
        }
        /* init s to 0 */
        nodes[s].d = 0;
}

void relax(int u, int v) {
        if (nodes[v].d > nodes[u].d + G[u][v]) {
                nodes[v].d = nodes[u].d + G[u][v];
                nodes[v].pre = u;
        }
}

void dijkstra(int s) {
        make_heap(nodes.begin(), nodes.end());

        while (nodes.size()) {
                /* extract min */
                int u = (nodes.front()).node_num;
                pop_heap(nodes.begin(), nodes.end());
                nodes.pop_back();

                /* for each node adjacent to u */
                for (int i = 0; i < MAXN; i++) {
                        if (G[u][i] < INF) {
                                relax(u, i);
                        }
                }

                /* because relax change nodes[i].d
                 * should remake the heap
                 */
                make_heap(nodes.begin(), nodes.end());
        }
}

int main() {
        return 0;
}
