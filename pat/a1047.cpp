#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//map<int, set<string> > m_course_to_students;
//int main() {
//        int N, M;
//        scanf("%d %d", &N, &M);
//        while (N--) {
//                string name;
//                int K;
//                cin >> name;
//                scanf("%d", &K);
//                while (K--) {
//                        int course_id;
//                        scanf("%d", &course_id);
//                        m_course_to_students[course_id].insert(name);
//                }
//        }
//        for (int i = 1; i <= m_course_to_students.size(); i++) {
//                printf("%d %d\n", i, m_course_to_students[i].size());
//                set<string>::iterator it = m_course_to_students[i].begin();
//                for (; it != m_course_to_students[i].end(); it++) {
//                        cout << *it << endl;
//                }
//        }
//        return 0;
//}

int main() {
        vector<string> course_list[2501];
        int N, M;
        scanf("%d %d", &N, &M);
        int count = 1;
        int max_course_id = -1;
        while (N--) {
                string name;
                int K;
                cin >> name;
                scanf("%d", &K);
                while (K--) {
                        int course_id;
                        scanf("%d", &course_id);
                        if (course_id > max_course_id) {
                                max_course_id = course_id;
                        }
                        course_list[course_id].push_back(name);
                }
        }
        for (int i = 1; i <= max_course_id; i++) {
                sort(course_list[i].begin(), course_list[i].end());
                printf("%d %d\n", i, course_list[i].size());
                for (int j = 0; j < course_list[i].size(); j++) {
                        printf("%s\n", course_list[i][j].c_str());
                }
        }
}
