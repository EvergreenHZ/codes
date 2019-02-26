#ifndef XSTRING_H
#define XSTRING_H

namespace xstd {
        class xstring {
                char *data;
                int size;

                public:
                xstring();
                xstring(const xstring &);
                xstring(const char*);
                xstring operator=(const xstring&);
                xstring operator+=(const xstring&);
                char& operator[](int);
                const char operator[](int);

                int size();
                char at(int);

                ~xstring();
        };

        xstring::xstring() {
                data = NULL;
                size = 0;
        }

        xstring::xstring(const xstring &s) {
                size = s.size();
                data = new char[size + 1];
                for (int i = 0; i < size; i++) {
                        data[i] = s[i];
                }
                data[size] = '\0';
        }

        xstring::xstring(const char *s) {
                data = const_cast<char*> s;
                int size = 0;
                while(s[size]) {
                        size++;
                }

                data = new char[size];

                for (int i = 0; i < size; i ++) {
                        data[i] = s[i];
                }
                data[size] = '\0';
        }
}
