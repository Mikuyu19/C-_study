#include <iostream>
using namespace std;

// 饿汉式单例实现示例(仅供参考)

class Singleton
{
public:
    // 公有的静态成员函数
    static Singleton* instance()
    {
        return &_instance;
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
    // 隐藏构造函数
    Singleton() 
    {
        cout << "构造函数" << endl;
    }
    // 静态成员对象
    static Singleton _instance;

    int x;
};

// 静态成员对象类外初始化
Singleton Singleton::_instance;


void foo()
{
    Singleton* s2 = Singleton::instance();
    cout << "s2 = " << s2 << endl;
    cout << "s2.value = " << s2->getValue() << endl;
}

int main(int argc, char const *argv[])
{
    cout << "-----------------" << endl;
    Singleton* s1 = Singleton::instance();
    cout << "s1 = " << s1 << endl;
    s1->setValue(100);
    foo();
    return 0;
}
