
#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

// 设计通讯录结构体
struct Addressbooks
{
private:
	// 设计联系人的结构体
	struct Person
	{
		// 姓名
		string m_Name;
		// 性别
		int m_Sex;
		// 年龄
		int m_Age;
		// 电话
		string m_Phone;
		// 住址
		string m_Addr;
	};
	// 通讯录中保存的联系人数组
	struct Person personArray[MAX];
	// 通讯录中当前联系人个数
	int m_Size;

	void printPerson(int index) const;

public:
	Addressbooks();
	void addPerson();
	void showPerson() const;
	int isExist(const string &name) const;
	void deletePerson();
	void findPerson();
	void modifyPerson();
	void cleanPerson();
};

Addressbooks::Addressbooks() : m_Size(0)
{
}
// 菜单界面
void showMenu()
{
	cout << "****************************" << endl;
	cout << "*****  1.添加联系人  *******" << endl;
	cout << "*****  2.显示联系人  *******" << endl;
	cout << "*****  3.删除联系人  *******" << endl;
	cout << "*****  4.查找联系人  *******" << endl;
	cout << "*****  5.修改联系人  *******" << endl;
	cout << "*****  6.清空联系人  *******" << endl;
	cout << "*****  0.退出通讯录  *******" << endl;
	cout << "****************************" << endl;
}

// 添加联系人
void Addressbooks::addPerson()
{
	// 判断是否满了，满了就不再添加
	if (m_Size == MAX)
	{
		cout << "通讯录满了，无法添加" << endl;
		return;
	}
	else
	{
		// 添加联系人

		// 姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		personArray[m_Size].m_Name = name;
		// 性别
		cout << "请输入性别" << endl;
		cout << "1-男" << endl;
		cout << "2-女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				personArray[m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		// 年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		personArray[m_Size].m_Age = age;
		// 电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		personArray[m_Size].m_Phone = phone;
		// 住址
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		personArray[m_Size].m_Addr = address;

		// 更新通讯录的人数
		m_Size++;

		cout << "添加成功" << endl;
	}
}

// 显示所有联系人
void Addressbooks::printPerson(int index) const
{
	cout << " 姓名 :" << personArray[index].m_Name << "\t";
	cout << " 性别 :" << (personArray[index].m_Sex == 1 ? "男" : "女") << "\t";
	cout << " 年龄 :" << personArray[index].m_Age << "\t";
	cout << " 电话 :" << personArray[index].m_Phone << "\t";
	cout << " 住址 :" << personArray[index].m_Addr << endl;
}

void Addressbooks::showPerson() const
{
	if (m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_Size; i++)
		{
			printPerson(i);
		}
	}
}

// 检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int Addressbooks::isExist(const string &name) const
{
	for (int i = 0; i < m_Size; i++)
	{
		// 找到用户输入的姓名
		if (personArray[i].m_Name == name)
		{
			return i; // 找到，返回这个人在数组中的下标编号
		}
	}
	return -1; // 遍历结束没有找到返回-1
}

// 删除指定联系人
void Addressbooks::deletePerson()
{
	cout << "请输入删除联系人姓名" << endl;

	string name;
	cin >> name;

	int ret = isExist(name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = ret; i < m_Size - 1; i++)
		{
			// 数据前移
			personArray[i] = personArray[i + 1];
		}
		m_Size--; // 更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
}

// 查找指定联系人信息
void Addressbooks::findPerson()
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(name);

	if (ret != -1) // 找到联系人
	{
		printPerson(ret);
	}
	else
	{
		cout << "查无此人" << endl;
	}
}

// 修改指定的联系人信息
void Addressbooks::modifyPerson()
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(name);

	if (ret != -1) // 找到联系人
	{
		// 姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;

		personArray[ret].m_Name = name;
		// 性别

		cout << "请输入性别" << endl;
		cout << "1-男" << endl;
		cout << "2-女" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		// 年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		personArray[ret].m_Age = age;
		// 电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		personArray[ret].m_Phone = phone;
		// 住址
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}

// 清空所有联系人
void Addressbooks::cleanPerson()
{
	m_Size = 0; // 逻辑清空
	cout << "通讯录已清空" << endl;
}
int main()
{
	// 创建通讯录结构体变量
	Addressbooks abs;
	int select = 0; // 创建用户选择输入的变量

	while (true)
	{
		// 菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:				 // 添加联系人
			abs.addPerson(); // 利用地址传递，可以修饰实参
			break;
		case 2: // 显示所有联系人
			abs.showPerson();
			break;
		case 3: // 删除联系人
			abs.deletePerson();
			break;
		case 4: // 查找联系人
			abs.findPerson();
			break;
		case 5: // 修改联系人
			abs.modifyPerson();
			break;
		case 6: // 清空联系人
			abs.cleanPerson();
			break;
		case 0: // 退出通讯录
			cout << "欢迎下次使用通讯录" << endl;
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
