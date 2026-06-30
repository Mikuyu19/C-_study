#include <iostream>

namespace china
{
    int a;
    void print()
    {
        std::cout << "a = " << a << std::endl;
    }
} // namespace china

int main()
{

    using namespace std;
    china::a = 400;
    cout << "china::a = " << china::a << endl;

    return 0;
}