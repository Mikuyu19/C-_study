#include <iostream>
#include <string.h>
using namespace std;

namespace china
{
    class string
    {
    public:
        string(const char *s = NULL)
        {
            if (s == NULL)
            {
                _data = new char[1];
                _data[0] = '\0';
            }
            else
            {
                _data = new char[strlen(s) + 1];
                strcpy(_data, s);
            }
        }
        ~string(){}
        string(const string &rhs){}
        string &operator=(const string &rhs){}
        friend ostream &operator<<(ostream &out, const string &s){}

        // int size() const;
        // bool empty() const;
        // char at(int index) const;
        // const char* c_str() const;
        // []
        // +
        // <
        class iterator
        {
        public:
            iterator(char *p) : p(p) {}
            char &operator*()
            {
                return *p;
            }
            iterator& operator++()
            {
                ++p;
                return *this;
            }
            bool operator!=(const iterator& rhs) const 
            {
                return this->p != rhs.p;
            }

        private:
            char *p;
        };
        iterator begin()
        {
            return iterator(_data);
        }
        iterator end()
        {
            return iterator(_data + strlen(_data));
        }

    private:
        char *_data;
    };
}

int main(int argc, char const *argv[])
{
    china::string s1 = "hello world";
    for (china::string::iterator it = s1.begin(); it != s1.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
