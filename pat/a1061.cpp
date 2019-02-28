
#include <map>
#include <iostream>
#include <string>

using namespace std;
// A-Z: 65-90
// a-z: 97-122
map<char, string> map_week;
map<char, int> map_hour;

void init() {
        map_week['A'] = string("MON");
        map_week['B'] = string("TUE");
        map_week['C'] = string("WED");
        map_week['D'] = string("THU");
        map_week['E'] = string("FRI");
        map_week['F'] = string("SAT");
        map_week['G'] = string("SUN");

        map_hour['0'] = 0;
        map_hour['1'] = 1;
        map_hour['2'] = 2;
        map_hour['3'] = 3;
        map_hour['4'] = 4;
        map_hour['5'] = 5;
        map_hour['6'] = 6;
        map_hour['7'] = 7;
        map_hour['8'] = 8;
        map_hour['9'] = 9;
        map_hour['A'] = 10;
        map_hour['B'] = 11;
        map_hour['C'] = 12;
        map_hour['D'] = 13;
        map_hour['E'] = 14;
        map_hour['F'] = 15;
        map_hour['G'] = 16;
        map_hour['H'] = 17;
        map_hour['I'] = 18;
        map_hour['J'] = 19;
        map_hour['K'] = 20;
        map_hour['L'] = 21;
        map_hour['M'] = 22;
        map_hour['N'] = 23;
}

bool is_captital_letter(char c) {
        if (c >= 'A' && c <= 'G')
                return true;
        return false;
}

char find_same_capital_letter(string& s1, string &s2, int &s1_i, int &s2_j) {
        for (int i = 0; i < s1.size(); i++) {
                if (is_captital_letter(s1[i]) && is_captital_letter(s2[i]) &&
                    s1[i] == s2[i]) {
                        s1_i = i;
                        s2_j = i;
                        return s1[i];
                }
        }
}

bool is_legal(char c) {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'N')) {
                return true;
        }
        return false;
}

char find_hour(string& s1, string &s2, int s1_start, int s2_start) {
        for (int i = s1_start + 1; i < s1.size(); i++) {
                if (is_legal(s1[i])) {
                        for (int j = s2_start + 1; j < s2.size(); j++) {
                                if (s2[j] == s1[i]) {
                                        return s1[i];
                                }
                        }
                }
        }
}

bool is_letter(char c) {
        if (c >= 'A' && c <= 'Z')
                return true;
        if (c >= 'a' && c<='z')
                return true;
        return false;
}

int same_place(string &s1, string &s2) {
        //cout << s1 << " " << s2 << " " << s1.size() <<endl;
        for (int i = 0; i < s1.size(); i++) {
                if (is_letter(s1[i]) && is_letter(s2[i])) {
                        //cout << s1[i] << " " << s2[i] <<endl;
                        if (s1[i] == s2[i]) {
                                //cout << s1[i] << " " << s2[i] << endl;
                                return i;
                        }
                        //cout << "FUCK FUCK" << endl;
                }
        }
        return -1;
}

int main() {
        init();
        string s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;

        int s1_start, s2_start;
        char w = find_same_capital_letter(s1, s2, s1_start, s2_start);
        char h = find_hour(s1, s2, s1_start, s2_start);
        int m = same_place(s3, s4);

        cout << map_week[w] << " ";
        printf("%02d:",map_hour[h]);
        printf("%02d\n",m);

        return 0;
}
