#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

const int MAXN = 110;
int N_nodes, M_non_leaf_nodes;
int level_leaf_nodes[MAXN] = {0};  // level->int

class Node {
public:
        int id;
        vector<int> childs;
        Node():id(0) {}
        Node(int i): id(i) {}
};

// root id starting from 1
Node* family[MAXN];  // root: family[1]
int levels[MAXN] = {0};

int bfs(Node* root) {
        if (root == NULL) return 0;

        queue<Node*> Q;
        Q.push(root);
        int current_level = 0;
        while (!Q.empty()) {
                Node* p = Q.front();
                if (current_level < levels[p->id])
                        current_level = levels[p->id];
                Q.pop();
                for (int i = 0; i < p->childs.size(); i++) {
                        //cout << "FUCK SEGMT FAULT" << endl;
                        Q.push(family[p->childs[i]]);
                        levels[p->childs[i]] = levels[p->id] + 1;
                }
                if (p->childs.size() == 0) {
                        level_leaf_nodes[levels[p->id]]++;
                }
        }
        return current_level;
}

int main() {
        scanf("%d %d", &N_nodes, &M_non_leaf_nodes);

        if (M_non_leaf_nodes == 0) {
                cout << 1 << endl;
                return 0;
        }
        for (int i = 0; i < M_non_leaf_nodes; i++) {
                int id, k;
                scanf("%d %d", &id, &k);
                family[id] = new Node(id);
                while (k--) {
                        int child_id;
                        scanf("%d", &child_id);
                        if (!family[child_id])
                                family[child_id] = new Node(child_id);
                        family[id]->childs.push_back(child_id);
                }
        }
        int max_level = bfs(family[1]);
        for (int i = 0; i <= max_level; i++) {
                cout << level_leaf_nodes[i];
                printf("%c", i == max_level ? '\n':' ');
        }
}
