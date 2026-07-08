#include <iostream>
using namespace std;

class Demo
{
public:
    Demo(int x = 0, int y = 0) : x(x), y(y) {}
    friend ostream &operator<<(ostream &out, const Demo &d)
    {
        out << "Demo(" << d.x << ", " << d.y << ")";
        return out;
    }
    // 赋值运算符
    Demo & operator=(const Demo & rhs)
    {
        cout << "operator=" << endl;
        this->x = rhs.x;
        this->y = rhs.y;

        // 返回自引用
        return *this;
    }

private:
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    Demo d1(1, 1);
    cout << d1 << endl;

    Demo d2(2, 2);
    cout << d2 << endl;

    d1 = d2;
    cout << d1 << endl;

    
    return 0;
}
