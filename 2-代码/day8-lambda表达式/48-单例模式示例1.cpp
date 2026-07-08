#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton &instance()
    {
        static Singleton instance;
        return instance;
    }
    void setValue(int x)
    {
        this->x = x;
    }
    int getValue() const
    {
        return x;
    }

private:
    Singleton() {}

    // 禁止拷贝构造
    Singleton(const Singleton &) = delete;
    // 禁止赋值构造
    Singleton operator=(const Singleton &) = delete;
    static Singleton _instance;
    int x;
};

Singleton Singleton::_instance;

void foo()
{
    Singleton &s2 = Singleton::instance();
    cout << "s2 = " << s2.getValue() << endl;
    cout << "s2.value = " << s2.getValue() << endl;
}

int main(int argc, char const *argv[])
{
    Singleton &s1 = Singleton::instance();
    cout << "s1 = " << s1.getValue() << endl;
    s1.setValue(100);
    foo();
    return 0;
}
