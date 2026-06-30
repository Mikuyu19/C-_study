#include <iostream>
#include "dir.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Dir dir("./");
    List list = dir.getAllFilenames();
    list.print();
    return 0;
}
