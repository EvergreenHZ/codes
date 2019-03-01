#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_vec(vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
        }
        cout << endl;
}

void permutations(vector<int> &digits, vector<int> &result) {
        if (digits.size() == 1) {
                result.push_back(digits[0]);
                print_vec(result);
        } else {
                for (int i = 0; i < digits.size(); i++) {
                        vector<int> remained_digits = digits;
                        remained_digits.erase(remained_digits.begin() + i,
                                              remained_digits.begin() + i + 1);
                        vector<int> tmp_result = result;  // this is important
                        tmp_result.push_back(digits[i]);

                        permutations(remained_digits, tmp_result);
                }
        }
}

int main() {
        vector<int> digits;
        vector<int> result;
        for (int i = 1; i < 5; i++) {
                digits.push_back(i);
        }

        permutations(digits, result);

        return 0;
}
