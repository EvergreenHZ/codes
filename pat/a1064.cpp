#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 101;
class Node {
public:
        int parent;
        int w;
        vector<int> childs;
        Node(): parent(-1), w(0) {}
};

Node nodes[MAXN];
int N_nodes, M_non_leaves, S;
vector<vector<int> > path;

bool cmp(const vector<int> &v1, const vector<int> &v2) {
        int len = min(v1.size(), v2.size());
        for (int i = 0; i < len; i++) {
                if (nodes[v1[i]].w != nodes[v2[i]].w)
                        return nodes[v1[i]].w > nodes[v2[i]].w;
        }
        return true;
}

void dfs(int root, int current_w, vector<int> &v) {
        current_w += nodes[root].w;
        v.push_back(root);
        if (nodes[root].childs.size() == 0) {  // leaf node
                if (current_w == S) {
                        path.push_back(v);
                };
                return ;
        }

        for (int i = 0; i < nodes[root].childs.size(); i++) {
                vector<int> tmp = v;
                dfs(nodes[root].childs[i], current_w, tmp);
        }
}

//vector<int> weights;
void print_path(vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
                printf("%d%c", nodes[v[i]].w, i == v.size() - 1? '\n':' ');
        }
}

int main() {
        scanf("%d %d %d", &N_nodes, &M_non_leaves, &S);
        for (int i = 0; i < N_nodes; i++) {
                scanf("%d", &nodes[i].w);
        }
        for (int i = 0; i < M_non_leaves; i++) {
                int id, K, x;
                scanf("%d %d", &id, &K);
                for (int j = 0; j < K; j++) {
                        scanf("%d", &x);
                        nodes[id].childs.push_back(x);
                        nodes[x].parent = id;
                }
        }
        vector<int> v;
        dfs(0, 0, v);

        sort(path.begin(), path.end(), cmp);
        //sort(path.begin(), path.end(), greater<vector<int> >());
        for (int i = 0; i < path.size(); i++) {
                print_path(path[i]);
        }
        return 0;
}
