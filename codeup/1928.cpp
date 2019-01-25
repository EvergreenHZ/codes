#include "../include/common.h"
using namespace std;

const int leap_year[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int common_year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year) {
        if (year % 400 == 0 || 
            (year % 100 != 0 && year % 4 == 0)) {
                return true;
        } else {
                return false;
        }
}

bool isCommon(int year) {
        return isLeap(year)? false : true;
}


int strtodate(char* s, int *year, int *month, int *day) {
        char *y = s;
        char *m = s + 4;
        char *d = s + 6;
        *day   = atoi(d);
        *d = '\0';
        *month = atoi(m);
        *m = '\0';
        *year  = atoi(y);
        printf("%d:%d:%d\n", *year, *month, *day);
}

int kthDay(int year, int month, int day) {
        int sum = 0;
        for (int i = 1; i < month; i++) {
                if (isLeap(year)) {
                        sum += leap_year[i];
                } else {
                        sum += common_year[i];
                }
        }
        sum += day;
}

int countDays(char *s1_date, char* s2_date) {
        int s_year, s_month, s_day;
        int e_year, e_month, e_day;
        strtodate(s1_date, &s_year, &s_month, &s_day);
        strtodate(s2_date, &e_year, &e_month, &e_day);

        int span = e_year - s_year;
        if (span == 0) {
                return kthDay(e_year, e_month, e_day) - kthDay(s_year, s_month, s_day);
        } else {
                int days = 0;
                int t_year = s_year + 1;
                for (int i = 1; i < span; i++) {
                        if (isLeap(t_year)) {
                                days += 366;
                        } else {
                                days += 365;
                        }
                }

                // s_year last half year
                if (isLeap(s_year)) {
                        days += 366 - kthDay(s_year, s_month, s_day);
                } else {
                        days += 365 - kthDay(s_year, s_month, s_day);
                }

                // e_year first half year
                days += kthDay(e_year, e_month, e_day);
                return days;
        }
}

int main()
{
        char s1_date[10];
        char s2_date[10];
        scanf("%s", s1_date);
        scanf("%s", s2_date);
        int days = countDays(s1_date, s2_date);
        printf("%d\n", days);
}
