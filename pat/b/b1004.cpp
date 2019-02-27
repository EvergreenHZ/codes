#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

class Stu {
public:
        string name;
        string id;
        int grade;

        Stu(string s, string i, int g): name(s), id(i), grade(g) {}
        Stu() {}
        Stu(const Stu& s): name(s.name), id(s.id), grade(s.grade) {}

        //bool operator<(const Stu& s) {
        //        return this.grade < s.grade;
        //}
};

bool cmp(Stu &s1, Stu &s2) {
        return s1.grade < s2.grade;
}

void read(vector<Stu> &s) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                char name[11], course_id[11];
                int grade;
                scanf("%s %s %d", name, course_id, &grade);
                s.push_back(Stu(name, course_id, grade));
        }
}

void search(vector<Stu> &s) {
        sort(s.begin(), s.end(), cmp);
        cout << s[s.size() - 1].name <<  " " << s[s.size() - 1].id << endl;
        cout << s[0].name << " " << s[0].id << endl;
}

int main() {
        vector<Stu> s;
        read(s);
        search(s);
}
