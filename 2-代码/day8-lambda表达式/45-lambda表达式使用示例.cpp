#include <iostream>
using namespace std;


bool even_number(int x)
{
    if (x % 2 == 0)
        return true;
    return false;
}


int find_array(int a[], int n, bool(*func)(int))
{
    for (int i = 0; i < n; i++)
    {
        if (func(a[i]))
            return i;
    }
    return -1;
}


class EvenNumber
{
public:
    bool operator()(int x)
    {
        return x % 2 == 0;
    }
    
};

bool find_array(int a[], int n, EvenNumber func)
{
    for (int i = 0; i < n; i++)
    {
        if (func(a[i]))
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int a[5] = {1,2,3,4,5};
    int index = find_array(a, 5, even_number);
    cout << "index = " << index << endl;
    
    index = find_array(a, 5, EvenNumber());
    cout << "index = " << index << endl;

    // 使用lambda表达式实现 查找第一个偶数
    index = find_array(a, 5, [](int x){return x % 2 == 0;});
    cout << "index = " << index << endl;
    

    return 0;
}


