#include <iostream>
using namespace std;

// 懒汉式单例-实现示例

class Singleton
{
public:
    // 公有的静态成员函数
    static Singleton* instance()
    {
        // 静态局部对象,从C++11起，静态局部对象保证线程安全
        static Singleton _instance;

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
    // 删除拷贝操作
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    int x;
};


void foo()
{
    Singleton* s2 = Singleton::instance();
    cout << "s2 = " << s2 << endl;
    cout << "s2.value = " << s2->getValue() << endl;
}

int main(int argc, char const *argv[])
{
    cout << "--------------------" << endl;
    Singleton* s1 = Singleton::instance();
    cout << "s1 = " << s1 << endl;
    s1->setValue(100);
    foo();

    // Singleton s3 = *s1; // 拷贝构造
    // cout << "&s3 = " << &s3 << endl;
    return 0;
}
