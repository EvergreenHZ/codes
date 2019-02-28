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

/* suppose right tree is not empty
 * keep going right */
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

// suppose left tree is not empty
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

Node* copy_tree(const Node* root) {
        if (root == NULL) return NULL;
        else {
                Node *new_root = new Node(root->key);
                new_root->left = copy_tree(root->left);
                new_root->right = copy_tree(root->right);
                if (new_root->left != NULL)
                        new_root->left->parent = new_root;
                if (new_root->right != NULL)
                        new_root->right->parent = new_root;
                return new_root;
        }
}

/* very elegant */
Node* insert_v2(Node* &root, int key) {
        if (root == NULL) return root = new Node(key);  // empty tree
        if (key >= root->key) {
                root->right = insert_v2(root->right, key);
        } else {
                root->left = insert_v2(root->left, key);
        }
        return root;
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
                insert_v2(root, keys[i]);
        }
        Node* copy = copy_tree(root);
        preoreder(root);
        preoreder(copy);
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

// delete a node


int main() {
        test_insert();
        return 0;
}
