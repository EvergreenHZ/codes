#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void build_heap(vector<int> &v) {
        make_heap(v.begin(), v.end());
}

int extract(vector<int> &v) {
        pop_heap(v.begin(), v.end());
        int x = v.back();
        v.pop_back();

        return x;
}

void insert(vector<int> &v, int key) {
        v.push_back(key);
        push_heap(v.begin(), v.end());
}

int top(vector<int> &v) {
        return v.front();
}

void print_vec(vector<int> &v) {
        for (int i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
        }
        cout << endl;
}

void heap_sort(vector<int> &v) {
        build_heap(v);
        print_vec(v);
        sort_heap(v.begin(), v.end());
}

void test_heap() {
        vector<int> v;
        for (int i = 0; i < 10; i++) {
                if (i > 5)
                        v.push_back(i);
                else
                        v.push_back(i + 7);
        }
        print_vec(v);
        heap_sort(v);
        print_vec(v);
}

int main() {
        test_heap();
        return 0;
}
