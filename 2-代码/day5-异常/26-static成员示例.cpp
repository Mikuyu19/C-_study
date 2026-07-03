#include <iostream>
using namespace std;

class Demo
{

public:
    Demo()
    {
        cnt++;
    }
    ~Demo()
    {
        cnt--;
    }

    static int getCnt()
    {
        return cnt;
    }

private:
    static int cnt;
};

int Demo::cnt = 0;

void foo()
{
    Demo d1;
}
void bar()
{
    Demo d2[10];
}

int main()
{
    cout << "cnt = " << Demo::getCnt() << endl;
    Demo d1;
    cout << "cnt = " << Demo::getCnt() << endl;
    foo();
    bar();
    cout << "cnt = " << Demo::getCnt() << endl;
}