/*
 * BST Implimentation,
 * RECURSION
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
        int key;
        Node* left, *right, *parent;

        Node():key(0), left(NULL), right(NULL), parent(NULL) {}
        Node(int k):key(k), left(NULL), right(NULL), parent(NULL) {}
};

Node* search(Node* root, int key) {
        if (root == NULL) {  // empty tree
                return NULL;
        } else {
                if (key == root->key) {
                        return root;
                } else if (key < root->key) {
                        return search(root->left, key);
                } else {
                        return search(root->right, key);
                }
        }
}

/* keep going right */
Node* maximum(Node* root) {
        if (root == NULL) return NULL;
        Node* tmp = root->right;
        if (tmp != NULL) {
                if (tmp->right == NULL) {
                        return tmp;
                } else {
                        return maximum(tmp);
                }

        }
}

Node* minimum(Node* root) {
        if (root == NULL) return NULL;
        Node* tmp = root->left;
        if (tmp != NULL) {
                if (tmp->left == NULL) {
                        return tmp;
                } else {
                        return minimum(tmp);
                }
        }
}

Node* successor(Node* root) {
        if (root == NULL) return NULL;
        if (root->right) {
                return minimum(root->right);
        } else {
                Node* p = root->parent;
                while (p && (p->right == root)) {
                        root = p;
                        p = root->parent;
                }
                return p;
        }
}

Node* predecessor(Node* root) {
        if (root == NULL) return NULL;
        if (root->left) {
                return maximum(root->left);
        } else {
                Node* p = root->parent;
                while (p && (p->left == root)) {
                        root = p;
                        p = root->parent;
                }
                return p;
        }
}

/* *** TAKE CARE ***
 * pass reference of pointer
 */
Node* insert(Node* &root, int key) {
        if (root == NULL) {  // empty tree
                Node *node = new Node(key);
                return root = node;
        } else {
                // >= or >
                if (key >= root->key) {  // go right
                        if (root->right == NULL) {  // insert here
                                Node *node = new Node(key);
                                root->right = node;
                                node->parent = root;
                                return node;
                        } else {
                                return insert(root->right, key);
                        }
                } else if (key == root->key) {  // current key is already existed
                        return NULL;
                } else{  // go left
                        if (root->left == NULL) {  // insert here
                                Node *node = new Node(key);
                                root->left = node;
                                node->parent = root;
                                return node;
                        } else {
                                return insert(root->left, key);
                        }
                }
        }
}

void preoreder(Node* root) {
        if (root == NULL) return;
        cout << root->key << endl;
        preoreder(root->left);
        preoreder(root->right);
}

void preoreder_vec(Node* root, vector<int> &v) {
        if (root == NULL) return;
        v.push_back(root->key);
        preoreder_vec(root->left, v);
        preoreder_vec(root->right, v);
}

void mirror_preorder_vec(Node* root, vector<int> &v) {
        if (root == NULL) return;
        v.push_back(root->key);
        mirror_preorder_vec(root->right, v);
        mirror_preorder_vec(root->left, v);
}

void test_insert() {
        Node* root = NULL;
        int keys[10] = {8, 6, 5, 7, 10, 9, 11};
        for (int i = 0; i < 7; i++) {
                insert(root, keys[i]);
        }
        preoreder(root);
}

bool cmp_vec(vector<int> &v1, vector<int> &v2) {
        for (int i = 0; i < v1.size(); i++) {
                if (v1[i] != v2[i]) {
                        return false;
                }
        }
        return true;
}

void post_order_vec(Node* root, vector<int> &post_vec) {
        if (root == NULL) return;
        post_order_vec(root->left, post_vec);
        post_order_vec(root->right, post_vec);
        post_vec.push_back(root->key);
}

void getMirrorTree(Node* &root) {
        if (root == NULL) return;
        Node* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        getMirrorTree(root->left);
        getMirrorTree(root->right);

}
int main() {
        vector<int> v;
        int N;
        scanf("%d", &N);
        while (N--) {
                int x;
                scanf("%d", &x);
                v.push_back(x);
        }
        Node *root = NULL;
        for (int i = 0; i < v.size(); i++) {
                insert(root, v[i]);
        }

        vector<int> pre_vec, mirror_pre_vec;
        preoreder_vec(root, pre_vec);
        mirror_preorder_vec(root, mirror_pre_vec);

        if (cmp_vec(pre_vec,v)) {
                vector<int> post_vec;
                post_order_vec(root, post_vec);
                cout << "YES" <<endl;
                for (int i = 0; i < post_vec.size(); i++) {
                        cout << post_vec[i];
                        printf("%c", i == post_vec.size() - 1 ? '\n':' ');
                }
                return 0;
        }
        if (cmp_vec(mirror_pre_vec, v)) {
                getMirrorTree(root);
                vector<int> post_vec;
                post_order_vec(root, post_vec);
                cout << "YES" << endl;
                for (int i = 0; i < post_vec.size(); i++) {
                        cout << post_vec[i];
                        printf("%c", i == post_vec.size() - 1 ? '\n':' ');
                }
                return 0;
        }
        cout << "NO" <<endl;
        return 0;
}
