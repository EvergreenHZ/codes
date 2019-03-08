#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Stu {
public:
        string name, id;
        int grade;
        Stu(const string &n, const string &i, int g):
                name(n), id(i), grade(g) {}

        bool operator<(const Stu &s) {
                if (grade != s.grade) return grade < s.grade;
        }
};

int main() {
        int N;
        scanf("%d", &N);
        vector<Stu> v;
        for (int i = 0; i < N; i ++) {
                string name, id;
                int grade;
                cin >> name >> id >> grade;
                v.push_back(Stu(name, id, grade));
        }
        int min, max;
        scanf("%d %d", &min, &max);
        sort(v.begin(), v.end());
        int i = 0, j = v.size() - 1;
        for ( ; i <= j; ) {
                if (v[i].grade < min) i++;
                if (v[j].grade > max) j--;
                if (v[i].grade >= min && v[j].grade <= max)
                        break;
        }
        if (i > j) {
                printf("NONE\n");
        } else {
                for (int k = j; k >= i; k--) {
                        cout << v[k].name << " " << v[k].id << endl;
                }
        }
        return 0;
}
