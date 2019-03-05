#include <cstdio>

class Node {
public:
        int key;
        Node *left, *right;
        int level;
        Node() {}
        Node(int k): key(k), left(NULL), right(NULL) {}
};

int max_level = 0;
int num_of_nodes[2];

Node* bst_insert(Node* root, int key) {
        if (root == NULL) return new Node(key);
        if (key <= root->key) {
                root->left = bst_insert(root->left, key);
        } else {
                root->right = bst_insert(root->right, key);
        }
        return root;
}

void put_level(Node* root, int level) {
        if (root == NULL) return;
        root->level = level;
        put_level(root->left, level + 1);
        put_level(root->right, level + 1);
        if (max_level < level)
                max_level = level;
}

void dfs_bst(Node* root) {
        if (root == NULL) return;
        if (root->level == max_level)
                num_of_nodes[0] ++;
        if (root->level == max_level - 1)
                num_of_nodes[1] ++;
        dfs_bst(root->left);
        dfs_bst(root->right);
}

int main() {
        int N;
        scanf("%d", &N);
        Node* root = NULL;  // very important
        while (N--) {
                int key;
                scanf("%d", &key);
                root = bst_insert(root, key);
        }
        put_level(root, 1);
        dfs_bst(root);
        printf("%d + %d = %d\n", num_of_nodes[0], num_of_nodes[1], num_of_nodes[0] + num_of_nodes[1]);
        return 0;
}
