#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Stu {
public:
        long long admission_ticket_number;
        long long vir_seat_number;
        long long phy_seat_number;
        Stu(): admission_ticket_number(0),
               vir_seat_number(0),
               phy_seat_number(0) {}
        Stu(long long a, long long b, long long c):
                admission_ticket_number(a),
                vir_seat_number(b),
                phy_seat_number(c) {}
};

void read(vector<Stu> &s, vector<long long> &vir_seat_numbers) {
        int N, M;
        scanf("%d", &N);
        for (int i = 0; i < N; i ++) {
                long long a, b, c;
                scanf("%lld %lld %lld", &a, &b, &c);
                s.push_back(Stu(a, b, c));
        }
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
                long long vsn;
                scanf("%lld", &vsn);
                vir_seat_numbers.push_back(vsn);
        }

}

int main() {
        vector<Stu> s;
        vector<long long> vir_seat_numbers;
        read(s, vir_seat_numbers);

        for (int i = 0; i < vir_seat_numbers.size(); i++) {
                for (int j = 0; j < s.size(); j++) {
                        if (vir_seat_numbers[i] == s[j].vir_seat_number) {
                                printf("%lld %lld\n",s[j].admission_ticket_number, s[j].phy_seat_number);
                                break;
                        }
                }
        }
}
