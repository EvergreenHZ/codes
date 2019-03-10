#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1001;
class Node {
public:
        int key;
        int left, right;
        int parent;
        Node(): key(-1), left(-1), right(-1), parent(-1) {}
};

int inline LEFT(int root) { return root * 2;}
int inline RIGHT(int root) { return root * 2 + 1;}
Node nodes[MAXN];
int N;
vector<int> in_num_seq;

void init() {
        for (int i = 1; i <= N; i++) {
                int l = LEFT(i);
                int r = RIGHT(i);
                if (l > N) l = -1;
                if (r > N) r = -1;
                nodes[i].left = l;
                nodes[i].right = r;
        }
}

void inorder(int root) {
        if (root == -1) return;
        inorder(nodes[root].left);
        in_num_seq.push_back(root);
        inorder(nodes[root].right);
}

vector<int> level_seq;
void level_order() {
        int root = 1;
        queue<Node> Q;
        Q.push(nodes[root]);
        while (!Q.empty()) {
                Node &t = Q.front();
                level_seq.push_back(t.key);
                Q.pop();
                if (t.left != -1)
                        Q.push(nodes[t.left]);
                if (t.right != -1)
                        Q.push(nodes[t.right]);
        }
}
int main() {
        scanf("%d", &N);
        vector<int> keys;
        for (int i = 1; i <= N; i++) {
                int x;
                scanf("%d", &x);
                keys.push_back(x);
        }
        sort(keys.begin(), keys.end());

        init();
        inorder(1);
        for (int i = 0; i < N; i++) {
                nodes[in_num_seq[i]].key = keys[i];
        }
        level_order();
        for (int i = 0; i < level_seq.size(); i++) {
                printf("%d%c", level_seq[i], i == level_seq.size() -1 ? '\n':' ');
        }
        return 0;
}
