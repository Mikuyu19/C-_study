#include "color.hpp"
#include <iostream>
using namespace std;

int main()
{
    Color color;
    color.setValue(255, 0, 0);

    cout << color.toInt() << endl;
    cout << hex << color.getRed() << endl;
    return 0;
}
