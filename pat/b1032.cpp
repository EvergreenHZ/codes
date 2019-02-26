#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
        int scores[100001];
        memset(scores, 0, sizeof(scores));

        int school_id, score;
        int max_school_id = 1;

        int total_schools = 0;

        scanf("%d", &total_schools);

        for (int i = 1; i <= total_schools; i++) {
                scanf("%d %d", &school_id, &score);
                scores[school_id] += score;

                if (max_school_id < school_id) {
                        max_school_id = school_id;
                }
        }

        int max_score = 0, coresponding_school_id = 1;
        for (int i = 1; i <= max_school_id; i++) {
                if (max_score < scores[i]) {
                        max_score = scores[i];
                        coresponding_school_id = i;
                }
        }
        printf("%d %d\n", coresponding_school_id, max_score);
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
        int scores[100001];
        memset(scores, 0, sizeof(scores));

        int school_id, score;
        int max_school_id = 1;

        int total_schools = 0;

        scanf("%d", &total_schools);

        for (int i = 1; i <= total_schools; i++) {
                scanf("%d %d", &school_id, &score);
                scores[school_id] += score;

                if (max_school_id < school_id) {
                        max_school_id = school_id;
                }
        }

        int max_score = 0, coresponding_school_id = 1;
        for (int i = 1; i <= max_school_id; i++) {
                if (max_score < scores[i]) {
                        max_score = scores[i];
                        coresponding_school_id = i;
                }
        }
        printf("%d %d\n", coresponding_school_id, max_score);
}
