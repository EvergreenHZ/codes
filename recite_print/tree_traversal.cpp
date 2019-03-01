#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Node {
public:
        int key;  // suppose all keys are unique
        Node* left, *right;

        Node(): key(-1), left(NULL), right(NULL) {}
        Node(int k): key(k), left(NULL), right(NULL) {}
};

void pre_order(Node* root) {
        if (root == NULL) { //empty tree
                return ;
        } else {
                cout << root->key << endl;
                pre_order(root->left);
                pre_order(root->right);
        }
}

void in_order(Node* root) {
        if (root == NULL) { //empty tree
                return ;
        } else {
                in_order(root->left);
                cout << root->key << endl;
                in_order(root->right);
        }
}

void post_order(Node* root) {
        if (root == NULL) { //empty tree
                return ;
        } else {
                post_order(root->left);
                post_order(root->right);
                cout << root->key << endl;
        }
}

void level_order(Node* root) {
        if (root == NULL) {
                return;
        }
        queue<Node*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
                Node* t = nodes.front();
                nodes.pop();
                if (t->left)
                        nodes.push(t->left);
                if (t->right)
                        nodes.push(t->right);
                cout << t->key << endl;
        }
}

void level_order_vec(Node* root, vector<int> &v) {
        if (root == NULL) {
                return;
        }
        queue<Node*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
                Node* t = nodes.front();
                nodes.pop();
                if (t->left)
                        nodes.push(t->left);
                if (t->right)
                        nodes.push(t->right);
                v.push_back(t->key);
        }
}

        for (int i = 0; i < v.size(); i++) {
                if (v[i] == x) {
                        return i;
                }
        }
        return -1;

}

void copy_vec(vector<int> &v, int s, int len, vector<int> &cp) {
        for (int i = s; i < s + len; i++) {
                cp.push_back(v[i]);
        }
}

void print_vec(vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
                printf("%d", v[i]);
                printf("%c", i == v.size() - 1? '\n' : ' ');
        }
}
Node* reconstruct_from_ipre(vector<int> &inorder, vector<int> &preorder) {
        if (inorder.empty()) return NULL;
        if (inorder.size() == 1) {
                Node* root = new Node(inorder[0]);
                return root;
        }
        int root_key = preorder.front();
        int root_key_idx = find_first(inorder, root_key);
        int l_len = root_key_idx;
        int r_len = inorder.size() - l_len - 1;

        Node *root = new Node(root_key);
        vector<int> l_inorder, r_inorder, l_preorder, r_preorder;
        copy_vec(inorder, 0, l_len, l_inorder);
        copy_vec(inorder, root_key_idx + 1, r_len, r_inorder);
        copy_vec(preorder, 1, l_len, l_preorder);
        copy_vec(preorder, l_len + 1, r_len, r_preorder);
        root->left = reconstruct_from_ipre(l_inorder, l_preorder);
        root->right = reconstruct_from_ipre(r_inorder, r_preorder);
        return root;
}

Node* reconstruct_from_ipost(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) return NULL;

        Node *root;
        int root_key = postorder[postorder.size() - 1];

        if (inorder.size() == 1) {
                root = new Node(root_key);
                return root;
        }
        root = new Node(root_key);
        int root_key_idx = find_first(inorder, root_key);
        int l_len = root_key_idx;
        int r_len = inorder.size() - l_len - 1;
        vector<int> l_inorder, r_inorder, l_postorder, r_postorder;
        copy_vec(inorder, 0, l_len, l_inorder);
        copy_vec(inorder, l_len + 1, r_len, r_inorder);
        copy_vec(postorder, 0, l_len, l_postorder);
        copy_vec(postorder, l_len, r_len, r_postorder);

        root->left = reconstruct_from_ipost(l_inorder, l_postorder);
        root->right = reconstruct_from_ipost(r_inorder, r_postorder);
        return root;
}

void test() {
        vector<int> inorder, preorder;
        for (int i = 1; i <= 10; i++) {
                inorder.push_back(i);
        }

        preorder.push_back(2);
        preorder.push_back(1);
        preorder.push_back(4);
        preorder.push_back(5);
        preorder.push_back(3);
        preorder.push_back(7);
        preorder.push_back(8);
        preorder.push_back(10);
        preorder.push_back(9);
        preorder.push_back(6);

        //Node *root = reconstruct_from_ipre(inorder, preorder);
        Node *root = reconstruct_from_ipost(inorder, preorder);
        //post_order(root);
        level_order(root);
}

int main() {
        int N;
        vector<int> postorder, inorder;
        scanf("%d", &N);

        int x;
        int t = N;
        while (t--) {
                scanf("%d", &x);
                postorder.push_back(x);
        }
        t = N;
        while (t--) {
                scanf("%d", &x);
                inorder.push_back(x);
        }

        Node* root = reconstruct_from_ipost(inorder, postorder);
        vector<int> v;
        level_order_vec(root, v);

        print_vec(v);
        return 0;
}
