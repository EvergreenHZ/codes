#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 10000000;
const int MAXN = 1000;

class Node {
        public:
                int d;
                int pre;

                Node(): d(INF), pre(-1) {}
                bool operator < (const Node &n) {
                        if (d != n.d) {
                                return d < n.d;
                        }
                }
};

void test() {
        vector<Node> heap;
        Node n;
        for (int i = 0; i < 10; i++) {
                n.d = i;
                heap.push_back(n);
        }

        // heapify
        make_heap(heap.begin(), heap.end());

        for (int i = 0; i < 10; i++) {
                cout << heap[i].d << endl;
        }
}
        

int main() {
        test();
        return 0;
}
