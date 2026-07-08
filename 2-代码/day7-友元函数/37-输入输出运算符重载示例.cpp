#include <iostream>
using namespace std;

class Demo 
{
public:
    friend std::ostream& operator<<(std::ostream& out, const Demo& d1);
    friend std::istream& operator>>(std::istream& in, Demo& d1);
    Demo(int x=0): _x(x) {}

private:
    int _x;
};


std::ostream& operator<<(std::ostream& out, const Demo& d1)
{
    out << "Demo(" << d1._x << ")" ;
    return out;
}

std::istream& operator>>(std::istream& in, Demo& d1)
{
    in >> d1._x;
    return in;
}

int main(int argc, char const *argv[])
{
    Demo d1(100);
    cout << d1 << endl; 

    cout << "请输入Demo对象中的x: ";
    cin >> d1;
    cout << d1 << endl;
    
    return 0;
}
