#include <iostream>
using namespace std;

class Demo
{
public:
    Demo()
    {
        p = new int[5]{1, 2, 3, 4, 5};
    }
    ~Demo()
    {
        delete[] p;
    }

    // 可读可写
    int &operator[](int index) //  Demo* const this
    {
        return p[index];
    }
    // 只读
    const int &operator[](int index) const //  const Demo* const this
    {
        return p[index];
    }

private:
    int *p;
};

void print(const Demo &d)
{
    for (int i = 0; i < 5; i++)
    {
        cout << d[i] << ' '; // d.operator[](i)
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Demo d1;
    d1[0] = 100;
    cout << "d1[0] = " << d1[0] << endl;
    print(d1);
    return 0;
}
