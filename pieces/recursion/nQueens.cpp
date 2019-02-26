#include <iostream>
#include <vector>
using namespace std;

const int N = 6;

class Point {
public: 
        int row;
        int col;

        Point(): row(0), col(0) {}
        ~Point() {}
        Point(const int r, const int c): row(r), col(c) {}
        Point(const Point& p): row(p.row), col(p.col) {}
};

inline int absval(int a) {
        return a > 0 ? a : -a;

}

inline void print_vec(vector<Point> v) {
        for (int i = 0; i < v.size(); i++) {
                cout << v[i].row << " " << v[i].col << endl;
        }
        cout << endl;
}

bool isLegal(const vector<Point> &previous_k, const Point &p) {
        for (int i = 0; i < previous_k.size(); i++) {
                if (p.row == previous_k[i].row ||
                    absval(p.row - previous_k[i].row) ==
                    absval(p.col - previous_k[i].col)) {
                        return false;
                }
        }
        return true;
}

void nQueens(int column_n, vector<Point> result) {
        if (column_n == N) {
                print_vec(result);
        } else {
                /* for each row in current column */
                for (int row = 0; row < N; row++) {
                        if (isLegal(result, Point(row, column_n))) {
                                vector<Point> tmp_result = result;
                                tmp_result.push_back(Point(row, column_n));
                                nQueens(column_n + 1, tmp_result);
                        }
                }
        }
}

int main() {
        vector<Point> result;
        nQueens(0, result);

        return 0;
}
