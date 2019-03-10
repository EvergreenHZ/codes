#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
public:
        int parent, left, right;
        int key, node_id;

        Node(int p, int l, int r, int k, int n):
                parent(p), left(l), right(r), key(k), node_id(n) {}
        Node():parent(-1), left(-1), right(-1), key(-1), node_id(-1) {}
        Node(int n): node_id(n) {}
};

vector<Node> nodes;
int N;
vector<int> keys;

void read_input() {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                nodes.push_back(Node(i));
        }
        for (int i = 0; i < N; i++) {
                int l, r;
                scanf("%d %d", &l, &r);
                nodes[i].left = l;
                nodes[i].right = r;
                if (l != -1)
                        nodes[l].parent = i;
                if (r != -1)
                        nodes[r].parent = i;
        }
        for (int i = 0; i < N; i++) {
                int x;
                scanf("%d", &x);
                keys.push_back(x);
        }
        sort(keys.begin(), keys.end());
}

// the tree can't be empty
void inorder(int root, vector<int> &order_of_walk) {
        if (nodes[root].left != -1) {
                inorder(nodes[root].left, order_of_walk);
        }
        order_of_walk.push_back(nodes[root].node_id);
        if (nodes[root].right != -1) {
                inorder(nodes[root].right, order_of_walk);
        }
}

void level_order(int root, vector<int> &result) {
        queue<Node> Q;
        Q.push(nodes[root]);
        while (!Q.empty()) {
                Node &t = Q.front();
                result.push_back(t.key);
                Q.pop();
                if (t.left != -1)
                        Q.push(nodes[t.left]);
                if (t.right != -1)
                        Q.push(nodes[t.right]);
        }
}

void print_vec(vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
                printf("%d", v[i]);
                printf("%c", i == v.size() - 1?'\n':' ');
        }
}
int main() {
        read_input();
        vector<int> order_of_walk;
        inorder(0, order_of_walk);
        //print_vec(order_of_walk);
        for (int i = 0; i < N; i++) {
                nodes[order_of_walk[i]].key = keys[i];
        }

        vector<int> result;
        level_order(0, result);
        print_vec(result);
}
