#include <iosteam>
#include <vector>
using namespace std;

class Point {
        int x;
        int y;

        Point(): x(0), y(0) {}
        ~Point() {}
        Point(const Point p): x(p.x), y(p.y) {};
};

void tranverse_vector(vector<int> & v) {
        for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
                cout << *it << " ";
        }
        cout << endl;
}

void test_vector() {
        vector<int> vec_i;
        vector<vector<int> > matrix_i;
        vector<Point> vec_P;
}
