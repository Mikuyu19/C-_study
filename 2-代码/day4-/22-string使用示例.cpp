#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    std::string s1 = "hello";
    cout << s1.size() << ", " << s1.empty() << endl;

    // cout << s1[10] << endl;    // 下标越界，结果未知
    // cout << s1.at(10) << endl; // 下标越界，异常结束


    const char* str = s1.c_str(); // 把string转换成了const char*

    size_t index = s1.find("oo");
    cout << "index = " << index << endl;
    if (index == std::string::npos)
    {
        cout << "not found" << endl;
    }

    if (s1 == "hello")
    {
        cout << "==" << endl;
    }

    return 0;
}
