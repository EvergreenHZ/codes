#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<int, int> addr_index;  // address->index

class Node {
public:
        int key;
        int next;
        int addr;
        string addr_s;
        string next_s;
        Node(int k, int n, int add, const string &a_s, const string &n_s):
                key(k), next(n), addr(add), addr_s(a_s), next_s(n_s) {}
        Node(): key(-1), next(-1) {}
};

int main() {
        int N, K, head_addr;
        scanf("%d%d%d", &head_addr, &N, &K);
        vector<Node*> v;
        for (int i = 0; i < N; i++) {
                int add, k, next;
                string a_s;
                cin >> a_s;
                sscanf(a_s.c_str(), "%d", &add);
                scanf("%d", &k);
                string n_s;
                cin >> n_s;
                sscanf(n_s.c_str(), "%d", &next);
                v.push_back(new Node(k, next, add, a_s, n_s));
                //cout << add << endl;
                addr_index[add] = i;
        }
        int node_index = addr_index[head_addr];  // head index
        vector<Node> nodes;
        for (int i = 0; i < N; i++) {
                nodes.push_back(*v[node_index]);
                node_index = addr_index[v[node_index]->next];
        }
        reverse(nodes.begin(), nodes.begin() + K);

        for (int i = 0; i < N - 1; i++) {
                nodes[i].next = nodes[i + 1].addr;
                nodes[i].next_s = nodes[i + 1].addr_s;
        }
        nodes[N - 1].next = -1;
        nodes[N - 1].next_s = "-1";

        for (int i = 0; i < N; i++) {
                cout << nodes[i].addr_s << " "<<nodes[i].key<<" " << nodes[i].next_s<<endl;
        }
}
