#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Info {
public:
        string name;
        int age;
        int net_worth;
        Info() {}
        Info(const string &n, const int a, const int w):
                name(n), age(a), net_worth() {}
};

bool cmp(const Info &i1, const Info &i2) {
        if (i1.age != i2.age) {
                return i1.age < i2.age;
        } else {
                return i1.name < i2.name;
        }
}

bool cmp_networth(const Info &i1, const Info &i2) {
        if (i1.net_worth != i2.net_worth) {
                return i1.net_worth < i2.net_worth;
        } else {
                return i1.name < i2.name;
        }
}

int main() {
        int N, K;
        scanf("%d %d", &N, &K);
        vector<Info> v;
        for (int i = 0; i < N; i++) {
                string name;
                int age, net_worth;
                cin >> name >> age >> net_worth;
                v.push_back(Info(name, age, net_worth));
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 1; i <= K; i++) {
                int maximum, Amin, Amax;
                scanf("%d %d %d", &maximum, &Amin, &Amax);
        }
}
