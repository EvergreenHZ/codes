#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
        int K;
        int V;
        int left, right;
        Node(): left(-1), right(-1) {}
};

const int MAXN = 1025;
Node nodes[MAXN];
int N;
vector<int> keys;
vector<int> in_seq;
bool isRoot[MAXN] = {false};

int find_root() {
        for (int i = 1; i <= N; i++) {
                if (isRoot[i])
                        return i;
        }
        return 1;
}
void inorder(int root) {
        if (nodes[root].left != -1) {
                inorder(nodes[root].left);
        }
        in_seq.push_back(nodes[root].K);
        if (nodes[root].right != -1) {
                inorder(nodes[root].right);
        }
}

bool is_bst(int root) {
        inorder(root);
        sort(keys.begin(), keys.end());
        for (int i = 0; i < in_seq.size() - 1; i++) {
                if (keys[i] != in_seq[i])
                        return false;
        }
        return true;
}

bool is_max_heap(int root) {
        if (root == -1) return true;
        if (nodes[root].left == -1 &&
                        nodes[root].right == -1) {  // leaf node
                return true;
        }
        if (nodes[root].left != -1 &&
                        nodes[root].right == -1) {  // empty right subtree
                return nodes[root].V > nodes[nodes[root].left].V &&
                        is_max_heap(nodes[root].left);
        }
        if (nodes[root].right != -1 &&
                        nodes[root].left == -1) {  // empty left subtree
                return nodes[root].V > nodes[nodes[root].right].V &&
                        is_max_heap(nodes[root].right);
        }
        return nodes[root].V > nodes[nodes[root].left].V &&
                nodes[root].V > nodes[nodes[root].right].V &&
                is_max_heap(nodes[root].left) &&
                is_max_heap(nodes[root].right);
}

bool is_min_heap(int root) {
        if (root == -1) return true;
        if (nodes[root].left == -1 &&
                        nodes[root].right == -1) {  // leaf node
                return true;
        }
        if (nodes[root].left != -1 &&
                        nodes[root].right == -1) {  // empty right subtree
                return nodes[root].V < nodes[nodes[root].left].V &&
                        is_min_heap(nodes[root].left);
        }
        if (nodes[root].right != -1 &&
                        nodes[root].left == -1) {  // empty left subtree
                return nodes[root].V < nodes[nodes[root].right].V &&
                        is_min_heap(nodes[root].right);
        }
        return nodes[root].V < nodes[nodes[root].left].V &&
                nodes[root].V < nodes[nodes[root].right].V &&
                is_min_heap(nodes[root].left) &&
                is_min_heap(nodes[root].right);
}
int main() {
        scanf("%d", &N);
        // K: bst?
        for (int i = 1; i <= N; i++) {
                int k;
                scanf("%d", &k);
                nodes[i].K = k;
                keys.push_back(k);
        }
        // B: heap?
        for (int i = 1; i <= N; i++) {
                int v;
                scanf("%d", &v);
                nodes[i].V = v;
        }
        for (int i = 1; i <= N; i++) {
                int l, r;
                scanf("%d %d", &l, &r);
                nodes[i].left = l;
                nodes[i].right = r;
                if (l != -1)
                        isRoot[l] = false;
                if (r != -1)
                        isRoot[r] = false;
        }
        int root = find_root();
        bool isbst = is_bst(root);
        bool isminheap = is_min_heap(1);
        bool ismaxheap = is_max_heap(1);

        if (isbst && (ismaxheap || isminheap)) {
                printf("YES\n");
                printf("%s HEAP\n", ismaxheap ? "MAX" : "MIN");
                return 0;
        }
        if (!isbst) {
                printf("NO\n");
                if (ismaxheap || isminheap) {
                        printf("NOT BST\n");
                } else {
                        printf("NOT BST AND NOT HEAP\n");
                }
                return 0;
        }
        if (!(isminheap || ismaxheap)) {
                printf("NO\n");
                if (!isbst) {
                        printf("NOT BST AND NOT HEAP\n");
                } else {
                        printf("NOT HEAP\n");
                }
        }
        return 0;
}
