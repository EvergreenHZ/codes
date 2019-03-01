#include <iostream>
#include <cstdio>
#include <cstring>

char m[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

using namespace std;

int main() {
        char s[102];
        scanf("%s", s);
        int count = 0, sum = 0;
        count = strlen(s);

        while (count --) {
                sum += s[count] - '0';
        }
        //cout << endl << "sum is " << sum << endl;
        //cout << count << endl;
        count++;
        int b[10];
        do {
                b[count ++ ] = sum % 10;
                sum /= 10;
        } while (sum);
        //cout << count << endl;
        for (int i = count - 1; i >= 0; i--) {
                //cout << b[i];
                cout << m[b[i]];
                printf("%c", i == 0?'\n':' ');
        }
}
