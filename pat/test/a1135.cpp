#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

const bool BLACK = 0;
const bool RED = 1;
const int MAXN = 40;
int K, N;

class Node {
public:
        int key;
        bool color;
        int black_node_num;
        Node *left, *right;
        Node(int t_k):left(NULL), right(NULL) {
                if (t_k < 0) {
                        color = RED;
                        key = -t_k;
                } else {
                        key = t_k;
                        color = BLACK;
                }
                black_node_num = 0;
        }
        Node():key(0), color(0), black_node_num(0),left(NULL), right(NULL) {}
        Node(const Node &node) {
                key = node.key;
                color = node.color;
                black_node_num = node.black_node_num;
                left = node.left;
                right = node.right;
        }
        bool operator<(const Node &node) {
                if (key != node.key) return key < node.key;
        }
};

void preorder(Node *root) {
        if (root == NULL) return;
        else {
                cout << root->key << endl;
                preorder(root->left);
                preorder(root->right);
        }
}

int find_root(Node *seq, int root_key, int len) {
        for (int i = 0; i < len; i++) {
                if (seq[i].key == root_key) return i;
        }
        return -1;
}

Node* reconstruct_bst(Node* pre, Node *in, int len) {
        if (len == 0) return NULL;
        int root_key = pre[0].key;
        int l_len, r_len;
        l_len = find_root(in, root_key, len);
        r_len = len - l_len - 1;

        Node *root = new Node(pre[0]);
        root->left = reconstruct_bst(pre + 1, in, l_len);
        root->right = reconstruct_bst(pre + l_len + 1, in + l_len + 1, r_len);
        return root;
}


// the tree can not be empty
//void dfs(Node* root, int black_node_num = 0) {
//        if (root == NULL) return;
//        if (root->color == BLACK) {
//                black_node_num ++;
//                root->black_node_num = black_node_num;
//        }
//        dfs(root->left, black_node_num);
//        dfs(root->right, black_node_num);
//}

bool is_RBTree(Node* root) {
        //if (root == NULL) return true;
        //if (root->color == RED) {
        //        if (root->left && root->left->color != BLACK) return false;
        //        if (root->right && root->right->color != BLACK) return false;
        //}

        ////if (root->le)

        //return is_RBTree(root->left) && is_RBTree(root->right);
        return true;

}

int main() {
        scanf("%d", &K);
        bool flag = true;
        while (K--) {
                scanf("%d", &N);
                Node *pre_seq = new Node[N];
                Node *in_seq = new Node[N];
                for (int i = 0; i < N; i++) {
                        int t_key;
                        scanf("%d", &t_key);
                        pre_seq[i] = Node(t_key);
                        in_seq[i] = Node(t_key);
                }
                sort(in_seq, in_seq + N);  // get the inorder sequence

                Node *root = reconstruct_bst(pre_seq, in_seq, N);
                //if (root && root->color == BLACK && !root->left && !root->right) {
                //        printf("Yes");
                //        continue;
                //}
                printf("%s\n", is_RBTree(root)? "Yes":"No");
                free(pre_seq);
                free(in_seq);
        }
        return 0;
}
