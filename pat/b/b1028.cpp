#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int STANDARD_YEAR = 2014;
const int MAX_YEARS = 200;

class Person {
public:
        string name;
        int year;
        int month;
        int day;

        Person() {}
        Person(string n, int y, int m, int d):
                name(n), year(y), month(m), day(d) {}
        Person(const Person &p): name(p.name), year(p.year), day(p.day) {}

        bool operator<(const Person& p) {
                if (year != p.year) return year < p.year;
                if (month != p.month) return month < p.month;
                if (day != p.day) return day < p.day;
                return false;
        }
};

void print_vec(vector<Person> &p) {
        for (int i = 0; i < p.size(); i++) {
                cout << p[i].name << " " << p[i].year <<"/" << p[i].month <<"/"<<p[i].day<<endl;
        }
}
int main() {
        vector<Person> p;
        int N;
        scanf("%d", &N);
        Person up = Person("bar", STANDARD_YEAR, 9, 6);
        Person down = Person("foo", STANDARD_YEAR - 200, 9, 6);
        Person oldest = up, youngest = down;
        for (int i = 0; i < N; i++) {
                char n[10];
                int y, m, d;
                scanf("%s %d/%d/%d", n, &y, &m, &d);
                Person newbie = Person(n, y, m, d);
                if (newbie < down || up < newbie) {  // illegal
                        continue;
                }
                p.push_back(Person(n, y, m, d));
                if (newbie < oldest) {
                        oldest = newbie;
                }
                if (youngest < newbie) {
                        youngest = newbie;
                }
        }

        if (p.size() == 0) {
                cout << 0 << endl;
        } else {
                //sort(p.begin(), p.end());
                //cout << p.size() << " " << p[0].name << " " << p[p.size() - 1].name << endl;
                cout << p.size() << " " << oldest.name << " " << youngest.name << endl;
        }
        return 0;
}
/* WHY ???? */
