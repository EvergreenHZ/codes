#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 10010;
map<string, vector<string> > m_keyword_to_ids;
map<string, vector<string> > m_booktitle_to_ids;
map<string, vector<string> > m_author_to_ids;
map<string, vector<string> > m_pulishers_to_ids;
map<string, vector<string> > m_year_to_ids;

void print_map(map<string, vector<string> > &m) {
        map<string, vector<string> >::iterator it = m.begin();
        while (it != m.end()) {
                for (int i = 0; i < (it->second).size(); i++) {
                        cout << (it->second)[i] << " ";
                }
                cout << endl;
        }
}
void find_query(map<string, vector<string> > &m, string &s, vector<string> &v) {
        if (m.find(s) == m.end())
                return;
        else
                v = m[s];
}
void search(char *s, vector<string> &v) {
        int choice;
        sscanf(s, "%d: ", &choice);
        string query_string = string(&s[3]);
        switch (choice) {
        case 1: find_query(m_booktitle_to_ids, query_string, v);
        case 2: find_query(m_author_to_ids, query_string, v);
        case 3: find_query(m_keyword_to_ids, query_string, v);
        case 4: find_query(m_pulishers_to_ids, query_string, v);
        case 5: find_query(m_year_to_ids, query_string, v);
        }

}
int main() {
        int N, M;
        scanf("%d", &N);
        while (N--) {
                string id_s, title, author, year, publisher;
                char line[100];

                // read id
                cin >> id_s;
                //cout << id_s << endl;;

                // read book title
                fill(line, line + 100, '\0');
                fgets(line, 100, stdin);
                //cout << line;
                char *p = strchr(line, '\n');
                *p = '\0';
                title = string(line);
                m_booktitle_to_ids[title].push_back(id_s);

                // read author
                fill(line, line + 100, '\0');
                fgets(line, 100, stdin);
                //cout << line;
                p = strchr(line, '\n');
                *p = '\0';
                author = string(line);
                m_author_to_ids[author].push_back(id_s);

                // read keywords
                fill(line, line + 100, '\0');
                fgets(line, 100, stdin);
                //cout << line;
                p = strchr(line, '\n');
                *p = '\0';
                p = line;
                while (p) {
                        char *q = p;
                        p = strchr(p, ' ');
                        if (p) {
                                cout << p << endl;
                                *p = '\0';
                                m_keyword_to_ids[string(q)].push_back(id_s);
                                p++;
                        }
                }

                // read publisher
                fill(line, line + 100, '\0');
                fgets(line, 100, stdin);
                //cout << line;
                p = strchr(line, '\n');
                *p = '\0';
                publisher = string(line);
                m_pulishers_to_ids[publisher].push_back(id_s);

                // read year
                cin >> year;
                //cout << year << endl;
                m_year_to_ids[year].push_back(id_s);
        }
        //print_map(m_year_to_ids);
        //print_map(m_booktitle_to_ids);
        //print_map(m_author_to_ids);
        //print_map(m_pulishers_to_ids);
        //print_map(m_keyword_to_ids);
        exit(0);
        //while (1) {;}

        int n;
        scanf("%d", &n);
        while (n--) {
                char line[100];
                fgets(line, 100, stdin);
                cout << line;
                char *p = strchr(line, '\n');
                *p = '\0';
                vector<string> v;
                search(line, v);

                if (v.size() == 0) {
                        cout << "Not Found"  << endl;
                } else {
                        sort(v.begin(), v.end());
                        for (int i = 0; i < v.size(); i++) {
                                cout << v[i] << endl;
                        }
                }
        }
}
