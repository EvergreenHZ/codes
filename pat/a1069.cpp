#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int to_int(int *digit) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
                sum *= 10;
                sum += digit[i];
        }
        return sum;
}

void to_array(int *digit, int x) {
        fill(digit, digit + 4, 0);
        int i = 0;
        do {
                digit[i++] = x % 10;
                x /= 10;
        } while (x);
        reverse(digit, digit + i);
}

int main() {
        int N;
        scanf("%d", &N);
        while (true) {
                int digit[4];
                to_array(digit, N);
                sort(digit, digit + 4);
                int min = to_int(digit);
                reverse(digit, digit + 4);
                int max = to_int(digit);
                int result = max - min;
                printf("%04d - %04d = %04d\n", max, min, result);
                if (result == 0 || result == 6174)
                        break;
                N = result;
        }
        return 0;
}

