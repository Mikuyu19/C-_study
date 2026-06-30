#include <iostream>
using namespace std;

class Print
{
public:
    Print()
    {
        cout << "hello" << endl;
    }
    ~Print()
    {
        cout << "world" << endl;
    }
};

Print p;

int main()
{
    cout << "cpp" << endl;
    return 0;
}