#include <iostream>
using namespace std;

class Demo
{
public:
    Demo() = default;
    Demo(const Demo &) = delete;
};

int main(int argc, char const *argv[])
{
    Demo d1;

    // Demo d2 = d1;
    return 0;
}
