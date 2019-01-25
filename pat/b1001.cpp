#include <cstdio>

inline bool isEven(int n) {
        if (n % 2 == 0) {
                return true;
        } else {
                return false;
        }
}

inline bool isOdd(int n) {
        return isEven(n) ? false : true;
}

int calculate(int n) {
        if (isEven(n)) {
                return n / 2;
        } else {
                return (3 * n + 1) / 2;
        }
}

int count(int n) {
        int count = 0;
        if (n == 1) {
                return 1;
        }

        do {
                count++;
        } while ( (n = calculate(n)) != 1);

        return count;
}

int main()
{
        int n;
        scanf("%d", &n);
        int num = count(n);
        printf("%d\n", num);

        return 1;
}
