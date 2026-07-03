#include <iostream>
using namespace std;

class Demo
{
public:
    Demo(int x, int y)
    {
        this->_x = new int(x);
        this->_y = new int(y);
    }
    ~Demo()
    {
        delete _x;
        delete _y;
    }

    Demo(const Demo& rhs)
    {
        // 给左边侧对象申请新的内存空间
        this->_x = new int;
        // 把右侧对象内存空间中的值拷贝过来
        *this->_x = *rhs._x;

        this->_y = new int(*rhs._y);

        cout << "Demo(const Demo&)" << endl;
    }

    void print() const
    {
        cout << "Demo(" << *this->_x << ", " << *this->_y << ")" << endl;
    }

private:
    int *_x;
    int *_y;
};



int main(int argc, char const *argv[])
{
    Demo d1(100, 200);
    d1.print();

    Demo d2 = d1; // 1
    d2.print();
    
    return 0;
}
