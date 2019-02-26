#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *starting from 1 to MAXN - 1;
 */
const int SIZE = 11;
int MAXN = 11;
int heap[SIZE];

const inline int LEFT(int i) {
        return 2 * i;
}

const inline int RIGHT(int i) {
        return 2 * i + 1;
}

const inline int PARENT(int i) {
        /* if it returns 0
         * that means i is root
         */
        return i / 2;
}

void max_heapify(int i) {
        int left = LEFT(i);
        int right = RIGHT(i);
        int largest = i;
        /*
         * find the largest among i, left and right
         * record the index of the largest
         */
        if (left <= MAXN) {
                if (heap[left] > heap[i]) {
                        largest = left;
                }
        }
        if (right <= MAXN) {
                if (heap[right] > heap[largest]) {
                        largest = right;
                }
        }
        if (largest != i) {
                /* swap and heapify recursively */
                swap(heap[largest], heap[i]);
                max_heapify(largest);
        }
}

void build_max_heap() {
        /* starting from the last inside node */
        int last = MAXN / 2;
        for (int i = last; i >= 0; i--) {
                max_heapify(i);
        }
}

int extract_max() {
        if (MAXN >= 1) {
                swap(heap[1], heap[MAXN]);
        }
        MAXN --;
        max_heapify(1);
        return heap[MAXN + 1];
}

void test() {
        for (int i = 0; i <= MAXN; i++) {
                heap[i] = i;
        }
        build_max_heap();
        for (int i = 0; i < SIZE; i++) {
                cout << extract_max() << " ";
        }
        cout << endl;
}
int main() {
        test();
        return 0;
}
