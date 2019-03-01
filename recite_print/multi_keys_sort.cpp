#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int C;
class Stu {
public:
        string id_s;
        int id_i;
        string name;
        int grade;

        Stu(const string &is, int ii, const string& n, int g):
                id_s(is), id_i(ii),name(n), grade(g) {}
};

bool cmp1(const Stu& s1, const Stu& s2) {
        if (s1.id_s != s2.id_s)
                return s1.id_s < s2.id_s;
}

bool cmp2(const Stu& s1, const Stu &s2) {
        if (s1.name != s2.name)
                return s1.name < s2.name;
        else {
                return s1.id_s < s2.id_s;
        }
}

bool cmp3(const Stu& s1, const Stu& s2) {
        if (s1.grade != s2.grade)
                return s1.grade < s2.grade;
        else {
                return s1.id_s < s2.id_s;
        }
}

void print_vec(vector<Stu> &v) {
        for (int i = 0; i < v.size(); i++) {
                cout << v[i].id_s << " " << v[i].name << " " << v[i].grade << endl;
        }
}
int main() {
        int N;
        scanf("%d %d", &N,&C);
        vector<Stu> v;
        for (int i = 0; i < N; i++) {
                char id[20];
                char name[20];
                int grade;
                scanf("%s %s %d", id, name, &grade);
                int id_i;
                sscanf(id, "%d", &id_i);
                v.push_back(Stu(id, id_i, name, grade));
        }

        switch (C) {
        case 1: sort(v.begin(), v.end(), cmp1);
                break;
        case 2: sort(v.begin(), v.end(), cmp2);
                break;
        case 3: sort(v.begin(), v.end(), cmp3);
                break;
        }
        print_vec(v);
        return 0;
}
