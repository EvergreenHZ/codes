#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
        int address;
        int data;
        int next;
        Node(): next(-1), address(-1) {}
        Node(int a, int d, int n):
                address(a), data(d), next(n) {}
};

int main() {
        int N, head;
        cin >> N >> head;
        map<int, Node> m_add_node;
        for (int i = 1; i <= N; i++) {
                int add, d, n;
                cin >> add >> d >> n;
                m_add_node[add] = Node(add, d, n);
        }

        map<int, Node>::iterator it = m_add_node.find(head);

        if (it == m_add_node.end()) {  // all the nodes are empty
                printf("0 -1\n");
                return 0;
        }

        Node &head_node = it->second;
        // recover original list
        vector<Node> ori_list, result;
        int count = 1;
        ori_list.push_back(head_node);
        for (int i = 1; i < N; i++) {
                Node &back = ori_list.back();
                it = m_add_node.find(back.next);
                if (it == m_add_node.end()) {
                        break;
                }
                Node &next_node = it->second;
                ori_list.push_back(next_node);
                count ++;
        }
        N = count;
        int pi = 0, pj;
        if (N % 2 == 0) {
                pj = N / 2;
        } else {
                pj = N / 2 + 1;
        }
        reverse(ori_list.begin() + pj, ori_list.end());

        vector<Node> v;
        bool flag = true;
        while (count --) {
                if (flag) {
                        v.push_back(ori_list[pi]);
                        pi ++;
                        flag = false;
                } else {
                        v.push_back(ori_list[pj]);
                        pj ++;
                        flag = true;
                }
        }
        printf("%d %05d\n", N, head);
        for (int i = 0; i < N - 1; i++) {
                printf("%05d %d %05d\n", v[i].address, v[i].data, v[i + 1].address);
        }
        printf("%05d %d -1\n", v[N - 1].address, v[N - 1].data);
        return 0;
}
