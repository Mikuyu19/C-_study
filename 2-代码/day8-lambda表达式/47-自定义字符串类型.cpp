#include <iostream>
#include <cstring>
using namespace std;

namespace china
{
    class string
    {
    public:
        // 构造函数
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
        // 析构函数
        ~string()
        {
            delete[] _data;
        }
        // 拷贝构造函数
        string(const string &rhs)
        {
            _data = new char[strlen(rhs._data) + 1];
            strcpy(_data, rhs._data);
        }
        // 拷贝赋值运算符
        string &operator=(const string &rhs)
        {
            if (this != &rhs)
            {
                delete[] _data;
                _data = new char[strlen(rhs._data) + 1];
                strcpy(_data, rhs._data);
            }

            return *this;
        }

        // 友元函数声明
        friend ostream &operator<<(ostream &out, const string &s);
        // 返回字符串长度
        int size() const
        {
            return strlen(_data);
        }
        // 判断字符串是否为空
        bool empty() const
        {
            return size() == 0;
        }
        // 返回指定下标
        char at(int index) const
        {
            if (index < 0 || index >= size())
            {
                return '\0';
            }

            return _data[index];
        }
        const char *c_str() const
        {
            return _data;
        }
        // [] 运算符重载：非 const 版本
        char &operator[](int index)
        {
            return _data[index];
        }
        // [] 运算符重载：const 版本
        char operator[](int index) const
        {
            return _data[index];
        }
        // + 运算符重载：字符串拼接
        string operator+(const string &rhs) const
        {
            char *tmp = new char[size() + rhs.size() + 1];
            strcpy(tmp, _data);
            strcat(tmp, rhs._data);
            string ret(tmp);
            delete[] tmp;
            return ret;
        }
        // < 运算符重载
        bool operator<(const string &rhs) const
        {
            return strcmp(_data, rhs._data) < 0;
        }

    private:
        char *_data;
    };
    // << 运算符重载
    ostream &operator<<(ostream &out, const string &s)
    {
        out << s._data;
        return out;
    }
}

int main(int argc, char const *argv[])
{
    china::string s1 = "hello";
    china::string s2 = "world";
    china::string s3;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    s3 = s1 + s2;
    cout << "s3 = " << s3 << endl;

    // 测试函数
    cout << "s3.size() = " << s3.size() << endl;
    cout << "s3.empty() = " << s3.empty() << endl;
    cout << "s3.at(1) = " << s3.at(1) << endl;
    cout << "s3.c_str() = " << s3.c_str() << endl;

    // 测试 [] 运算符
    s3[0] = 'H';
    cout << "s3 = " << s3 << endl;
    // 测试拷贝构造函数
    china::string s4 = s3;
    cout << "s4 = " << s4 << endl;

    // 测试 < 运算符
    if (s1 < s2)
    {
        cout << "s1 < s2" << endl;
    }
    else
    {
        cout << "s1 >= s2" << endl;
    }
    return 0;
}
