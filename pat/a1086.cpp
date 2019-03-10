#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

vector<int> pre_seq, in_seq;
int N;
class Node {
public:
        int key;
        Node *left, *right;
        Node(): left(NULL), right(NULL) {}
        Node(int k): key(k), left(NULL), right(NULL) {}
};

int find_root_index(int *in, int root_key, int len) {
        for (int i = 0; i < len; i++) {
                if (root_key == in[i])
                        return i;
        }
        return -1;
}

Node* reconstruct_tree(int* pre, int *in, int len) {
        if (len <= 0) return NULL;
        if (len == 1) {
                Node* root = new Node(pre[0]);
                return root;
        }
        int root_key = pre[0];
        int l_len = find_root_index(in, root_key, len);
        if (l_len == -1) {
                cout << "ERROR: " << len << " root_key: " << root_key << endl;
                exit(-1);
        }
        int r_len = len - l_len - 1;
        Node* root = new Node(root_key);

        root->left = reconstruct_tree(pre + 1, in, l_len);
        root->right = reconstruct_tree(pre + 1 + l_len, in + 1 + l_len, r_len);
        return root;
}

vector<int> post_seq;
void post_order(Node* root) {
        if (!root) return;
        post_order(root->left);
        post_order(root->right);
        post_seq.push_back(root->key);
}

int main() {
        scanf("%d", &N);
        stack<int> st;
        for (int i = 0; i < 2 * N; i++) {
                string command;
                int key;
                cin >> command;
                if (command == "Push") {
                        cin >> key;
                        st.push(key);
                        pre_seq.push_back(key);
                } else {  // Pop
                        int top_key = st.top();
                        in_seq.push_back(top_key);
                        st.pop();
                }
        }

        int *pre = new int[N];
        int *in = new int[N];
        for (int i = 0; i < N; i++) {
                pre[i] = pre_seq[i];
                in[i] = in_seq[i];
        }
        Node* root = reconstruct_tree(pre, in, N);
        post_order(root);
        for (int i = 0; i < post_seq.size(); i++) {
                printf("%d%c", post_seq[i], i == post_seq.size() - 1? '\n' : ' ');
        }
}
