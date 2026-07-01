#include <iostream>
using namespace std;

class Demo 
{
public:
    Demo()
    {
        cout << "Demo()" << endl;
    };

    ~Demo()
    {
        cout << "~Demo()" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Demo d1;

    cout << "-------" << endl;
    Demo();
    cout << "-------" << endl;
    return 0;
}

