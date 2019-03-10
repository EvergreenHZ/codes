#include <cstdio>
#include <utility>
#include <cstring>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Node {
public:
        int parent;
        int id;
        int left, right;
        Node(): parent(-1), left(-1), right(-1) {}
};

const int MAXN = 11;
Node nodes[MAXN];
int N;

int find_root() {
        for (int i = 0; i < N; i++) {
                if (nodes[i].parent == -1)
                        return i;
        }
        return -1;
}

void print_vec(vector<int> &v) {
        for (int i = 0; i < v.size() ;i++) {
                printf("%d%c", v[i], i == v.size() - 1? '\n':' ');
        }
}

vector<int> level_seq;
void level_order(int root) {
        queue<int> Q;
        Q.push(root);
        while (!Q.empty()) {
                int t = Q.front();
                level_seq.push_back(t);
                Q.pop();
                if (nodes[t].left != -1) {
                        Q.push(nodes[t].left);
                }
                if (nodes[t].right != -1) {
                        Q.push(nodes[t].right);
                }
        }
}

vector<int> in_seq;
void in_order(int root) {
        if (root == -1) return ;
        in_order(nodes[root].left);
        in_seq.push_back(root);
        in_order(nodes[root].right);
}

int main() {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                string l, r;
                int ll = -1, rr = -1;
                cin >> l >> r;
                if (l != "-") {
                        ll = stoi(l);
                        nodes[ll].parent = i;
                }
                if (r != "-") {
                        rr = stoi(r);
                        nodes[rr].parent = i;
                }
                nodes[i].left = rr;
                nodes[i].right = ll;
        }
        int root = find_root();
        level_order(root);
        print_vec(level_seq);
        in_order(root);
        print_vec(in_seq);
        return 0;
}
