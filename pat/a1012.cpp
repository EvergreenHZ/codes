#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
class Stu {
public:
        string id;
        int C, M, E;
        float A;
        Stu() {}
        Stu(string i, int c, int m, int e):
                id(i), C(c), M(m), E(e) {
                A = (C + M + E) / 3.0;
        }
};

const float epsilon = 1.0E-8;
map<int, string> index_to_ACME;
vector<Stu> students;
vector<Stu*> students_ps;
//map<string, bool> m;  // is id exits
map<int, string> m;

void init_map() {
        m[0] = "A";
        m[1] = "C";
        m[2] = "M";
        m[3] = "E";
}

bool cmp_A(const Stu* a, const Stu* b) {
        return a->A > b->A;
}

bool cmp_C(const Stu* a, const Stu* b) {
        return a->C > b->C;
}

bool cmp_M(const Stu* a, const Stu* b) {
        return a->M > b->M;
}

bool cmp_E(const Stu* a, const Stu* b) {
        return a->E > b->E;
}

int find_max(int *a, int N) {
        int max = 0;
        for (int i = 0; i < N; i++) {
                if (a[i] < a[max])
                        max = i;
        }
        return max;
}

int find_index(const vector<Stu*> &v, string id) {
        int i = 0;
        for (; i < v.size(); i++) {
                if (id == v[i]->id)
                        return i;
        }
        return -1;
}
int main() {
        init_map();
        int N, M;
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) {
                string id;
                int c, m, e;
                cin >> id >> c >> m>> e;
                Stu* p = new Stu(id, c, m, e);
                students.push_back(*p);
                students_ps.push_back(p);
                //m[id] = true;

        }
        vector<Stu*> rank_a(students_ps);
        sort(rank_a.begin(), rank_a.end(), cmp_A);

        //for (int i = 0; i < rank_a.size(); i++) {
        //        cout << rank_a[i]->id << endl;
        //} cout << endl;
        //exit(-1);

        vector<Stu*> rank_c(students_ps);
        sort(rank_c.begin(), rank_c.end(), cmp_C);
        vector<Stu*> rank_m(students_ps);
        sort(rank_m.begin(), rank_m.end(), cmp_M);
        vector<Stu*> rank_e(students_ps);
        sort(rank_e.begin(), rank_e.end(), cmp_E);

        while (M--) {
                string id;
                cin >> id;
                int r[4];
                r[0] = find_index(rank_a, id);
                //while (r[0]) {
                //if (rank_a[r[0]]->A == rank_a[r[0] - 1]->A)
                //r[0] --;
                //else
                //break;
                //}
                if (r[0] == -1) {
                        printf("N/A\n");
                        continue;
                }
                r[1] = find_index(rank_c, id);
                //while (r[1]) {
                //if (rank_c[r[1]]->C == rank_c[r[1] - 1]->C)
                //r[1] --;
                //else
                //break;
                //}
                r[2] = find_index(rank_m, id);
                //while (r[2]) {
                //if (rank_m[r[2]]->M == rank_m[r[2] - 1]->M)
                //r[2] --;
                //else
                //break;
                //}
                r[3] = find_index(rank_e, id);
                //while (r[3]) {
                //if (rank_e[r[3]]->E == rank_e[r[3] - 1]->E)
                //r[3] --;
                //else
                //break;
                //}
                //cout << r[0] << endl;
                //cout << r[1] << endl;
                //cout << r[2] << endl;
                //cout << r[3] << endl;
                //exit(-1);

                int max_index = find_max(r, 4);
                cout << r[max_index] + 1 << " " << m[max_index] << endl;

        }
}
