#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

//map<string, set<int> > name_to_course_id;
//map<string, vector<int> > name_to_course_id;
//
//int main() {
//        int N_queries, K_courses;
//        scanf("%d %d", &N_queries, &K_courses);
//        for (int i = 0; i < K_courses; i++) {
//                int course_id, num_of_stu;
//                scanf("%d %d", &course_id, &num_of_stu);
//                for (int j = 0; j < num_of_stu; j++) {
//                        string name;
//                        cin >> name;
//                        name_to_course_id[name].push_back(course_id);
//                }
//        }
//
//        for (int i = 0; i < N_queries; i++) {
//                string name;
//                cin >> name;
//                vector<int> &v = name_to_course_id[name];
//                cout << name << " ";
//                if (v.size() == 0) {
//                        cout << 0 << endl;
//                        continue;
//                }
//                cout <<v.size() <<" ";
//                sort(v.begin(), v.end());
//                for (int i = 0; i < v.size(); i++) {
//                        printf("%d", v[i]);
//                        printf("%c", i == v.size() - 1? '\n' : ' ');
//                }
//        }
//}
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 40010;    //总人数
const int M = 26*26*26*10 + 1;  //由姓名散列成的数字上届
vector<int> selectCourse[M];    //每个学生选择的课程编号

int getID(char name[]) {    //hash函数，将字符串name转换成数字
        int id = 0;
        for(int i = 0; i<3; i++){
                id = id*26 + (name[i] - 'A');
        }
        id = id * 10 + (name[3] - '0');
        return id;
}

int main(){
        char name[5];
        int n,k;
        scanf("%d%d",&n,&k);    //人数及课程数
        for(int i=0; i<k; i++){     //对每门课程
                int course, x;
                scanf("%d%d", &course, &x);     //输入课程编号及选课人数
                for(int j = 0; j < x; j++){
                        scanf("%s", name);      //输入选课学生姓名
                        int id = getID(name);   //将姓名散列为一个整数作为编号
                        selectCourse[id].push_back(course);     //将该课程编号加入学生选择中
                }
        }
        for(int i = 0; i < n; i++){     //n各查询
                scanf("%s", name);      //学生姓名
                int id = getID(name);       //获得学生编号
                sort(selectCourse[id].begin(),selectCourse[id].end());      //从小到大排序
                printf("%s %d",name,selectCourse[id].size());   //姓名、选课数
                for(int j = 0; j < selectCourse[id].size(); j++){
                        printf(" %d",selectCourse[id][j]);      //选课编号
                }
                printf("\n");
        }
        return 0;
}
