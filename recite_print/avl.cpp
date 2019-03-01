#include <iostream>
#include <algorithm>

using namespace std;

//int g_count = 0;

class Node {
public:
        int key, height;
        Node *left, *right;
        Node():key(0), height(0), left(NULL), right(NULL) {}
        Node(int k):key(k), height(0), left(NULL), right(NULL) {}
};

int get_height(Node* root) {
        if (root == NULL) return -1;
        else return root->height;
}
int max_height(Node* l, Node *r) {
        return max(get_height(l), get_height(r));
}

/* right rotate, update heights and return new root
 * x must have left child and x is the first node losing balance
 */
Node* right_rotate(Node* x) {
        Node *y = x->left;
        x->left = y->right;
        y->right = x;
        x->height = max_height(x->left, x->right) + 1;
        y->height = max_height(y->left, y->right) + 1;
        return y;  // new root
}

Node* left_rotate(Node* x) {
        Node *y = x->right;
        x->right = y->left;
        y->left = x;
        x->height = max_height(x->left, x->right) + 1;
        y->height = max_height(y->left, y->right) + 1;
        return y;  // new root
}

/* y = x->left && z = y->right */
Node* double_rotate_with_LR(Node* x) {
        x->left = left_rotate(x->left);
        return right_rotate(x);
}

Node* double_rotate_with_RL(Node *x) {
        x->right = right_rotate(x->right);
        return left_rotate(x);
}

Node* insert(Node* root, int key) {
        if (root == NULL) return root = new Node(key);
        if (key >= root->key) {  // insert right
                root->right = insert(root->right, key);
                if (get_height(root->right) - get_height(root->left) == 2) {  // losing balance
                        if (key > root->right->key) {  // outside insertion, RR
                                root = left_rotate(root);
                        } else {  // inside insertoin, RL
                                root = double_rotate_with_RL(root);
                        }
                }
        } else {  // insert left
                root->left = insert(root->left, key);
                if (get_height(root->left) - get_height(root->right) == 2) {  // losing balance
                        if (key < root->left->key) {  // outside insertion, LL
                                root = right_rotate(root);
                        } else {  // inside insertion, LR
                                root = double_rotate_with_LR(root);
                        }
                }
        }
        root->height = max_height(root->left, root->right) + 1;
        return root;
}

int main() {
        int N;
        scanf("%d", &N);
        Node* root = NULL;  // very important
        while (N--) {
                int x;
                //g_count ++;
                //cout << g_count << endl;
                scanf("%d", &x);
                root = insert(root, x);
        }
        cout << root->key << endl;
}
