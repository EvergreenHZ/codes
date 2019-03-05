#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool flag[128] = {false};

bool is_letter(char c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        return false;
}

bool is_little_letter(char c) {
        if (c >= 'a' && c <= 'z') return true;
        return false;
}

int main() {
        set<char> origin;

        string ori_s, typed_s;
        cin >> ori_s >> typed_s;
        for (int i = 0; i < typed_s.size(); i++) {
                if (is_little_letter(typed_s[i]))
                        typed_s[i] += 'A' - 'a';
                origin.insert(typed_s[i]);
        }
        vector<char> v;
        for (int i = 0; i < ori_s.size(); i++) {
                if (ori_s[i] >= 'a' && ori_s[i] <= 'z')
                        ori_s[i] += 'A' - 'a';
                if (origin.find(ori_s[i]) == origin.end()) {
                        if (!flag[ori_s[i]]) {
                                v.push_back(ori_s[i]);
                        }
                        flag[ori_s[i]] = true;
                }
        }
        for (int i = 0; i < v.size(); i++)
                cout << v[i];
        cout << endl;
}
