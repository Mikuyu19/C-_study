#include <iostream>
using namespace std;


void print1(int x)
{
    cout << x << ' ';
}
void print2(int x)
{
    cout << x << '#';
}
void print3(int x)
{
    cout << x << '$';
}

void print_array(int a[], int n, void(*func)(int))
{
    for (int i = 0; i < n; i++)
    {
        func(a[i]);
    }
    cout << endl;
}


class PrintInt
{
public:
    PrintInt(char c=' '): c(c) {}
    void operator()(int x)
    {
        cout << x << c;
    }
    void setChar(char c)
    {
        this->c = c;
    }
private:
    char c;
};

void print_array(int a[], int n, PrintInt func)
{
    for (int i = 0; i < n; i++)
    {
        func(a[i]);
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int a[5] = {1,2,3,4,5};
    print_array(a, 5, print1);
    print_array(a, 5, print2);
    print_array(a, 5, print3);

    PrintInt p1;
    print_array(a, 5, p1);
    p1.setChar('^');
    print_array(a, 5, p1);

    print_array(a, 5, PrintInt('~'));
    print_array(a, 5, PrintInt('+'));
    return 0;
}


