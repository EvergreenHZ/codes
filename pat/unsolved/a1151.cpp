#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 10010;

class node {
public:
        int key;
        node *left, *right;
        int layer;
        node(): left(NULL), right(NULL) {}
        node(int k): key(k), left(NULL), right(NULL) {}
};

int preseq[maxn];
int inseq[maxn];

int* intchr(int* a, int len, int key) {
        for (int i = 0; i < len; i++) {
                if (key == a[i])
                        return &a[i];
        }
        return NULL;
}

node* reconstruct_tree(int* preseq, int* inseq, int len) {
        if (len == 0) return NULL;
        int root_key = preseq[0];
        int* p = intchr(inseq, len, root_key);
        int l_len = p - inseq;
        int r_len = len - l_len - 1;

        node* root = new node(root_key);
        root->left = reconstruct_tree(preseq + 1, inseq, l_len);
        root->right = reconstruct_tree(preseq + 1 + l_len, inseq + 1 + l_len, r_len);
        return root;
}

void put_level(node* root, int layer) {
        if (!root) return;
        root->layer = layer;

        put_level(root->left, layer + 1);
        put_level(root->right, layer + 1);
}

node* find_key(node* root, int key) {
        if (!root) return NULL;
        if (root->key == key) return root;
        node* p = NULL;
        p = find_key(root->left, key);
        if (p) return p;
        p = find_key(root->right, key);
        return p;
}

// b must not be NULL
bool is_a_ancestor_b(node* a, node* b) {
        if (a == b) return true;
        if (a == NULL) return false;
        return is_a_ancestor_b(a->left, b) ||
                is_a_ancestor_b(a->right, b);
}

void getallancestors(node* root, node* p, vector<node*> &v) {
        if (root == NULL) return;
        if (is_a_ancestor_b(root, p)) v.push_back(root);
        getallancestors(root->left, p, v);
        getallancestors(root->right, p, v);
}

node* getlca(node* root, node* pu, node* pv) {
        vector<node*> u;
        getallancestors(root, pu, u);
        vector<node*> v;
        for (int i = 0; i < u.size(); i++) {
                if (is_a_ancestor_b(u[i], pv))
                        v.push_back(u[i]);
        }
        int layer = v[0]->layer;
        int index = 0;
        for (int i = 0; i < v.size(); i++) {
                if (v[i]->layer > layer) {
                        layer = v[i]->layer;
                        index = i;
                }
        }
        return v[index];
}

int main() {
        int m_pairs, n_keys;
        scanf("%d%d", &m_pairs, &n_keys);
        for (int i = 0; i < n_keys; i++) {
                scanf("%d", &inseq[i]);
        }
        for (int i = 0; i < n_keys; i++) {
                scanf("%d", &preseq[i]);
        }

        node* root = reconstruct_tree(preseq, inseq, n_keys);
        put_level(root, 0);

        for (int i = 0; i < m_pairs; i++) {
                int u, v;
                scanf("%d%d", &u, &v);
                node* pu = find_key(root, u);
                node* pv = find_key(root, v);

                if (!pu && !pv) {
                        cout << "Error: " << u <<" and " << v << " are not found." << endl;
                } else if (pu && !pv) {
                        cout << "Error: " << v << " is not found." << endl;
                } else if (!pu && pv) {
                        cout << "Error: " << u << " is not found." << endl;
                } else {
                        if (is_a_ancestor_b(pu, pv)) {
                                cout << u << " is an ancestor of " << v << "."<<endl;
                                continue;
                        }
                        if (is_a_ancestor_b(pv, pu)) {
                                cout << v << " is an ancestor of " << u <<  "."<<endl;
                                continue;
                        }
                        node* p = getlca(root, pu, pv);
                        cout << "LCA of " << u << " and " << v << " is " << p->key << "."<<endl;
                }
        }
}
