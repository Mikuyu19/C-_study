#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    // 构造函数
    Student(string name, int age)
    {
        this->name = name;
        setAge(age);
    }
    // 设置姓名
    void setName(string name)
    {
        this->name = name;
    }
    // 获取姓名
    string getName()
    {
        return name;
    }

    // 设置年龄，防止外部传入非法数据
    void setAge(int age)
    {
        if (age >= 0 && age <= 150)
        {
            this->age = age;
        }
        else
        {
            cout << "年龄不合法" << endl;
        }
    }

    int getAge()
    {
        return age;
    }

    void showInfo()
    {
        cout << "姓名：" << name << endl;
        cout << "年龄：" << age << endl;
    }

private:
    string name;
    int age = 0;
};

int main()
{
    Student stu("张三", 20);
    stu.showInfo();

    stu.setAge(-10);
    stu.showInfo();

    stu.setAge(21);
    cout << "修改后的年龄：" << stu.getAge() << endl;
    return 0;
}