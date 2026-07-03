# C++ 学习笔记

# Day 1：认识 C++ 与基础语法

今天目标：了解 C++ 的基本特点，掌握第一个 C++ 程序、命名空间、`bool`、引用和函数重载。

---

## 1、C++ 基础认识

### 1.1、C++ 简介

C++ 是在 C 语言基础上发展出来的编程语言，最初叫 **C with Classes**，后来正式命名为 **C++**。

C++ 兼容大部分 C 语言语法，同时增加了面向对象、泛型编程、标准库等能力。

常见应用领域：

- 系统软件
- 嵌入式开发
- 后端服务
- 游戏开发
- 图形界面
- 科学计算

常见标准：

```text
C++98 / C++03
C++11
C++14
C++17
C++20
C++23
C++26
```

如果代码使用了 C++11 及以上的新特性，编译时可能需要指定标准：

```bash
g++ main.cpp -std=c++11
```

---

## 2、第一个 C++ 程序

```cpp
#include <iostream>

int main()
{
    std::cout << "hello cpp world" << std::endl;
    return 0;
}
```

### 核心解释

```cpp
#include <iostream>
```

引入 C++ 标准输入输出库。

```cpp
std::cout
```

标准输出流，用来向屏幕输出内容，类似 C 语言中的 `printf`。

```cpp
std::endl
```

表示换行，类似 `\n`。

```cpp
::
```

作用域运算符，用于访问指定作用域中的名字。

常见标准 IO 对象：

```text
std::cin    标准输入流
std::cout   标准输出流
std::cerr   标准错误流
```

常见输入输出运算符：

```text
<<   输出运算符，配合 cout / cerr 使用
>>   输入运算符，配合 cin 使用
```

---

## 3、using 和 namespace

`namespace` 称为**命名空间**，作用是把变量、函数、类等名字放到指定范围中，避免名字冲突。

```cpp
namespace A
{
    int value = 10;
}

namespace B
{
    int value = 20;
}
```

虽然 `A` 和 `B` 中都有 `value`，但它们属于不同命名空间，所以不会冲突。

访问命名空间中的内容，需要使用 `::`：

```cpp
std::cout << A::value << std::endl;
std::cout << B::value << std::endl;
```

`std` 是 C++ 标准库所在的命名空间，例如：

```cpp
std::cin
std::cout
std::endl
```

`using` 可以简化命名空间的使用：

```cpp
using namespace std;
```

写了之后：

```cpp
cout << "hello cpp world" << endl;
```

就不需要每次都写 `std::`。

但正式项目中不建议随便使用 `using namespace std;`，因为可能造成名字冲突。更推荐写：

```cpp
std::cout
std::cin
std::endl
```

或者只引入需要的名字：

```cpp
using std::cout;
using std::endl;
```

### 小结

```text
namespace：创建命名空间，防止名字冲突
::       ：访问指定作用域中的名字
using    ：简化命名空间的使用
std      ：C++ 标准库所在的命名空间
```

---

## 4、布尔类型 bool

`bool` 是 C++ 的布尔类型，用来表示**真**或**假**。

它只有两个值：

```cpp
true    // 真
false   // 假
```

示例：

```cpp
#include <iostream>

int main()
{
    bool flag = true;

    std::cout << flag << std::endl;

    return 0;
}
```

输出：

```text
1
```

在 C++ 中：

```text
true  默认输出为 1
false 默认输出为 0
```

### 小结

```text
bool  ：布尔类型
true  ：真
false ：假
常用于条件判断、状态标志、函数返回结果
```

---

## 5、引用

引用本质上是**给已有变量起一个别名**。

```cpp
int a = 10;
int& ref = a;
```

其中：

```cpp
int& ref
```

表示 `ref` 是 `a` 的引用，也就是 `a` 的别名。

修改引用，就等于修改原变量：

```cpp
int a = 10;
int& ref = a;

ref = 20;

std::cout << a << std::endl;  // 输出 20
```

### 5.1、引用的特点

引用必须初始化：

```cpp
int& ref;  // 错误
```

正确写法：

```cpp
int a = 10;
int& ref = a;
```

引用一旦绑定，不能再改绑：

```cpp
int a = 10;
int b = 20;

int& ref = a;
ref = b;
```

这里 `ref = b;` 不是让 `ref` 改成引用 `b`，而是把 `b` 的值赋给 `a`。

---

### 5.2、引用作为函数参数

引用常用于函数参数，可以让函数直接修改外部变量。

```cpp
#include <iostream>

void change(int& x)
{
    x = 100;  // 修改 x，其实就是修改外部变量
}

int main()
{
    int a = 10;

    change(a);

    std::cout << a << std::endl;  // 输出 100

    return 0;
}
```

---

### 5.3、const 引用

如果函数只需要读取数据，不希望修改数据，可以使用 `const` 引用。

```cpp
void print(const int& x)
{
    std::cout << x << std::endl;
}
```

`const int& x` 表示：

```text
x 是引用，但不能通过 x 修改原变量
```

`const` 引用的作用：

```text
1. 避免拷贝，提高效率
2. 防止函数内部误修改数据
3. 可以接收临时值
```

常见写法：

```cpp
void show(const std::string& name);
```

### 小结

```text
引用就是变量的别名
引用必须初始化
引用绑定后不能改绑
修改引用就是修改原变量
只读参数常用 const 引用
```

---

## 6、函数重载

函数重载指的是：在**同一个作用域**中，可以定义多个**函数名相同**，但**参数列表不同**的函数。

简单理解：

```text
函数名可以相同，但参数必须不同。
```

示例：

```cpp
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    cout << add(10, 20) << endl;      // 调用 int add(int, int)
    cout << add(1.5, 2.5) << endl;    // 调用 double add(double, double)
    cout << add(1, 2, 3) << endl;     // 调用 int add(int, int, int)

    return 0;
}
```

编译器会根据实参的类型和个数，自动选择对应函数。

### 6.1、构成函数重载的条件

函数名相同，参数列表不同。

参数列表不同包括：

```cpp
void func(int a);              // 参数类型不同
void func(double a);

void func(int a);              // 参数个数不同
void func(int a, int b);

void func(int a, double b);    // 参数顺序不同
void func(double a, int b);
```

### 6.2、不能只靠返回值重载

错误示例：

```cpp
int func(int a)
{
    return a;
}

double func(int a)
{
    return a;
}
```

原因是调用时：

```cpp
func(10);
```

编译器只能根据参数判断调用哪个函数，不能只根据返回值判断。

### 6.3、注意事项

函数重载时，要避免写出容易产生歧义的函数。

例如：

```cpp
void func(int a);
void func(int& a);
```

当调用：

```cpp
int x = 10;
func(x);
```

编译器可能不知道该调用哪一个。

### 小结

```text
函数重载核心：
1. 函数名相同
2. 参数列表不同
3. 返回值不同不能构成重载
4. 编译器根据实参自动匹配函数
```

函数重载可以理解为：

```text
同一个函数名，根据不同参数，执行不同版本。
```

# Day 2：C++语法再学习

## 1、默认参数

默认参数是 C++ 中的一种函数语法，作用是：

```text
调用函数时，如果没有给某个参数传值，就使用提前设置好的默认值。
```

### 1.1、基本写法

```cpp
#include <iostream>

void print(int count = 1)
{
    std::cout << count << std::endl;
}

int main()
{
    print(10);  // 输出 10，使用传入的参数
    print();    // 输出 1，使用默认参数

    return 0;
}
```

其中：

```cpp
int count = 1
```

表示如果调用 `print()` 时没有传入参数，就默认使用 `1`。

------

### 1.2、多个默认参数

函数可以有多个默认参数：

```cpp
#include <iostream>
#include <string>

void showStudent(const std::string& name, int age = 18, double score = 60)
{
    std::cout << "姓名：" << name << std::endl;
    std::cout << "年龄：" << age << std::endl;
    std::cout << "分数：" << score << std::endl;
}

int main()
{
    showStudent("Tom", 20, 95.5);
    showStudent("Jack", 19);
    showStudent("Lucy");

    return 0;
}
```

调用效果：

```text
showStudent("Tom", 20, 95.5)  使用传入的所有参数
showStudent("Jack", 19)       score 使用默认值 60
showStudent("Lucy")           age 使用默认值 18，score 使用默认值 60
```

------

### 1.3、默认参数的规则

默认参数必须从右往左连续设置。

正确写法：

```cpp
void func(int a, int b = 10, int c = 20)
{
}
```

可以这样调用：

```cpp
func(1, 2, 3);
func(1, 2);
func(1);
```

错误写法：

```cpp
void func(int a = 10, int b, int c)
{
}
```

原因：

```text
如果左边参数有默认值，那么它右边的参数也必须有默认值。
```

------

### 1.4、声明和定义分开时

如果函数声明和定义分开写，默认参数一般写在声明中，定义中不要重复写。

正确写法：

```cpp
void print(int count = 1);

void print(int count)
{
    std::cout << count << std::endl;
}
```

错误写法：

```cpp
void print(int count = 1);

void print(int count = 1)
{
    std::cout << count << std::endl;
}
```

原因：

```text
默认参数只能指定一次。
```

------

### 1.5、默认参数和函数重载

默认参数和函数重载一起使用时，可能产生歧义。

例如：

```cpp
void func(int a)
{
}

void func(int a, int b = 10)
{
}
```

调用：

```cpp
func(1);
```

编译器可能不知道应该调用哪一个函数。

所以要注意：

```text
默认参数和函数重载不要设计得太相似，否则容易产生二义性。
```

------

### 6、总结

```text
1. 默认参数用于简化函数调用
2. 没有传参时，使用提前设置好的默认值
3. 默认参数必须从右往左连续设置
4. 声明和定义分开时，默认值只能写一次
5. 默认参数和函数重载一起使用时，要避免二义性
```

## 2、内联函数 inline

内联函数是 C++ 中用于减少函数调用开销的一种语法。

普通函数调用时，需要经历参数传递、函数跳转、返回等过程。
内联函数会建议编译器把函数代码直接展开到调用位置，从而减少函数调用开销。

基本写法：

```cpp
inline int add(int a, int b)
{
    return a + b;
}
```

调用：

```cpp
int ret = add(10, 20);
```

编译器可能会将其优化成：

```cpp
int ret = 10 + 20;
```

### 2.1、inline 的特点

```text
1. inline 只是给编译器的建议，不是强制要求
2. 是否真正展开，由编译器决定
3. 适合短小、简单、频繁调用的函数
4. 不适合函数体很长、逻辑复杂的函数
```

### 2.2、inline 和宏函数的区别

C 语言中常用宏函数：

```cpp
#define ADD(a, b) ((a) + (b))
```

C++ 更推荐使用内联函数：

```cpp
inline int add(int a, int b)
{
    return a + b;
}
```

区别：

```text
宏函数：本质是文本替换，没有类型检查，容易出错
内联函数：是真正的函数，有类型检查，更安全
```

### 2.3、总结

```text
inline 的作用：建议编译器将函数在调用处展开，减少函数调用开销。

适合：短小、简单、频繁调用的函数。
不适合：函数体复杂、代码量大的函数。

一句话理解：
内联函数就是用函数的写法，实现类似宏展开的效果，但比宏更安全。
```

## 3、extern "C" 关键字

`extern "C"` 是 C++ 中用于 **C 和 C++ 混合编程** 的关键字。

它的作用是：

```text
告诉 C++ 编译器：这个函数按照 C 语言的方式进行链接，不要使用 C++ 的函数名修饰规则。
```

------

### 3.1、为什么需要 extern "C"

C++ 支持函数重载，例如：

```cpp
void func(int a);
void func(double a);
```

为了区分同名函数，C++ 编译器会对函数名进行修饰，这个过程叫：

```text
函数名修饰 / name mangling
```

而 C 语言不支持函数重载，函数名通常不会被修饰。

所以当 C++ 调用 C 语言写的函数时，可能出现：

```text
C 语言生成的函数名 和 C++ 查找的函数名 对不上
```

这时就需要使用 `extern "C"`。

------

### 3.2、基本写法

单个函数：

```cpp
extern "C" int add(int a, int b);
```

多个函数：

```cpp
extern "C" {
    int add(int a, int b);
    int sub(int a, int b);
}
```

------

### 3.3、常见头文件写法

如果一个 C 语言头文件既要给 C 使用，也要给 C++ 使用，通常这样写：

```c
#ifndef ADD_H
#define ADD_H

#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
```

其中：

```cpp
#ifdef __cplusplus
```

表示：

```text
如果当前使用的是 C++ 编译器，就启用 extern "C"。
```

原因是 C 语言不认识 `extern "C"`，所以必须用 `#ifdef __cplusplus` 进行判断。

------

### 3.4、add 库函数示例

头文件 `add.h`：

```c
#ifndef ADD_H
#define ADD_H

#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
```

源文件 `add.c`：

```c
#include "add.h"

int add(int a, int b)
{
    return a + b;
}
```

C 程序调用：

```c
#include <stdio.h>
#include "add.h"

int main()
{
    printf("%d\n", add(10, 20));
    return 0;
}
```

C++ 程序调用：

```cpp
#include <iostream>
#include "add.h"

int main()
{
    std::cout << add(10, 20) << std::endl;
    return 0;
}
```

------

### 3.5、注意事项

```text
1. extern "C" 只影响函数名的链接方式，不会把 C++ 代码变成 C 代码
2. extern "C" 常用于 C++ 调用 C 函数或 C 库
3. extern "C" 修饰的函数不能进行函数重载
4. C 语言不认识 extern "C"，所以头文件中要配合 __cplusplus 使用
```

错误示例：

```cpp
extern "C" {
    void func(int a);
    void func(double a);  // 错误，C 链接方式下不能函数重载
}
```

------

### 3.6、总结

```text
extern "C" 的作用：
让 C++ 编译器按照 C 语言的方式处理函数名，解决 C 和 C++ 混合编程时的链接问题。
```

常用模板：

```c
#ifdef __cplusplus
extern "C" {
#endif

// C 函数声明

#ifdef __cplusplus
}
#endif
```

一句话记忆：

```text
extern "C" 是 C++ 调用 C 代码时，用来防止函数名被 C++ 编译器改掉的。
```
---

# Day 3：类与对象

今天目标：理解 C++ 面向对象的基本思想，掌握类、对象、封装、成员函数、构造函数和成员初始化列表。

---

## 1、面向过程和面向对象

面向过程关注的是**解决问题的步骤**，常见写法是把任务拆成多个函数，按顺序执行。

例如：在开发板屏幕上画矩形：

```text
open 打开屏幕
mmap 内存映射
draw_point 绘制像素点
munmap 解除映射
close 关闭文件
```

面向对象关注的是**解决问题需要哪些对象**，把数据和操作数据的函数放到对象内部。

例如：

```text
定义 Screen 类，描述屏幕
创建 Screen 对象
定义 Rect 类，描述矩形
创建 Rect 对象
让 Rect 对象绘制到 Screen 对象上
```

一句话理解：

```text
面向过程：围绕步骤写代码。
面向对象：围绕对象写代码。
```

---

## 2、面向对象三大特性

C++ 面向对象有三个核心特征：

```text
封装：把数据和函数放到类中，隐藏内部实现，只暴露必要接口。
继承：在已有类基础上扩展新类。
多态：同一个接口，在不同对象上表现出不同效果。
```

当前阶段先重点掌握**封装、类和对象**。

---

## 3、类和对象

### 3.1、类 class

类是 C++ 的**自定义类型**，用来描述一类事物的属性和行为。

```text
属性：成员变量
行为：成员函数
```

例如坐标点：

```cpp
class Point
{
public:
    void setX(int x);
    void setY(int y);
    void move(int x, int y);

    int getX() const;
    int getY() const;

private:
    int _x = 0;  // x 坐标
    int _y = 0;  // y 坐标
};
```

### 3.2、对象 object

对象就是用类创建出来的具体变量，也叫**实例化对象**。

```cpp
Point p1;  // 创建一个 Point 对象
Point p2;  // 再创建一个 Point 对象
```

简单理解：

```text
类是图纸，对象是根据图纸造出来的具体东西。
```

---

## 4、封装和访问权限

封装就是把数据和函数放到类里面，并通过访问权限控制外部能不能直接访问。

常见写法：

```text
private：放成员变量，保护数据
public ：放成员函数，对外提供接口
```

访问权限：

```text
public      公有，类外可以访问
private     私有，只能类内访问
protected   保护，类内和子类可以访问
```

示例：

```cpp
Point p;
p.setX(100);  // 正确，通过 public 函数修改

// p._x = 100;  // 错误，_x 是 private，类外不能直接访问
```

### class 和 struct 的区别

```text
class  默认权限是 private
struct 默认权限是 public
```

实际开发中：

```text
需要封装数据和行为：常用 class
只是简单保存数据：可以用 struct
```

---

## 5、类的声明和定义分离

标准 C++ 中，类一般分成三个文件：

```text
point.hpp    类的声明
point.cpp    类的实现
main.cpp     类的使用
```

### 5.1、point.hpp：类的声明

```cpp
#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:
    void setX(int x);
    void setY(int y);
    void move(int x, int y);

    int getX() const;
    int getY() const;

private:
    int _x = 0;  // x 坐标
    int _y = 0;  // y 坐标
};

#endif
```

头文件保护：

```cpp
#ifndef POINT_HPP
#define POINT_HPP
...
#endif
```

作用是防止头文件被重复包含。

### 5.2、point.cpp：类的定义

```cpp
#include "point.hpp"

void Point::setX(int x)
{
    _x = x;
}

void Point::setY(int y)
{
    _y = y;
}

void Point::move(int x, int y)
{
    _x = x;
    _y = y;
}

int Point::getX() const
{
    return _x;
}

int Point::getY() const
{
    return _y;
}
```

注意：

```cpp
void Point::setX(int x)
```

这里的 `Point::` 表示 `setX` 属于 `Point` 类。

类外定义成员函数时，必须写：

```text
类名::函数名
```

### 5.3、main.cpp：类的使用

```cpp
#include <iostream>
#include "point.hpp"

void printPoint(const Point& pos)
{
    std::cout << "x = " << pos.getX() << std::endl;
    std::cout << "y = " << pos.getY() << std::endl;

    // pos.setX(100); // 错误，const 引用只能调用 const 成员函数
}

int main()
{
    Point pos;

    pos.move(100, 200);
    printPoint(pos);

    return 0;
}
```

编译：

```bash
g++ main.cpp point.cpp -o app
```

---

## 6、只读成员函数 const

如果成员函数只读取数据，不修改成员变量，就应该在函数后面加 `const`。

声明：

```cpp
int getX() const;
```

定义：

```cpp
int Point::getX() const
{
    return _x;
}
```

作用：

```text
1. 表示这个函数不会修改对象内部数据
2. const 对象或 const 引用只能调用 const 成员函数
3. get 函数通常都写成 const 成员函数
```

错误示例：

```cpp
int Point::getX() const
{
    _x = 100;  // 错误，const 成员函数不能修改成员变量
    return _x;
}
```

---

## 7、构造函数

构造函数是类中的特殊成员函数，用来在创建对象时初始化成员变量。

特点：

```text
1. 函数名和类名相同
2. 没有返回类型
3. 创建对象时自动调用
4. 可以重载
5. 如果没有写构造函数，编译器会自动生成默认构造函数
```

示例：

```cpp
class Point
{
public:
    Point()
    {
        _x = 0;
        _y = 0;
    }

    Point(int x, int y)
    {
        _x = x;
        _y = y;
    }

private:
    int _x;
    int _y;
};
```

使用：

```cpp
Point p1;          // 调用无参构造函数
Point p2(100, 200); // 调用有参构造函数
Point p3{1, 2};     // C++11 写法
```

注意：

```cpp
Point p4();  // 这不是创建对象，而是声明一个函数
Point p5{};  // 这是创建对象
```

### 默认构造函数

默认构造函数指**不传参数也能调用的构造函数**。

两种常见形式：

```cpp
Point();                      // 无参构造
Point(int x = 0, int y = 0);  // 参数都有默认值
```

### 匿名对象

直接调用构造函数会产生一个没有名字的临时对象，也叫匿名对象。

```cpp
foo(Point(100, 200));  // 用临时对象作为函数参数
```

---

## 8、成员初始化列表

成员初始化列表写在构造函数参数列表后面，用冒号 `:` 开始。

格式：

```cpp
类名(参数列表) : 成员1(初值), 成员2(初值)
{
}
```

示例：

```cpp
class Point
{
public:
    Point(int x, int y) : _x(x), _y(y)
    {
    }

private:
    int _x;
    int _y;
};
```

这比在构造函数体里赋值更推荐，因为它是**初始化**，效率更高。

### 必须使用成员初始化列表的情况

```text
1. 成员变量是 const 常量
2. 成员变量是引用
3. 成员对象没有默认构造函数
```

示例：

```cpp
class Other
{
public:
    Other(int value) : _value(value)
    {
    }

private:
    int _value;
};

class Demo
{
public:
    Demo(int x, int y) : _x(x), _y(y), _r(_x), _oth(100)
    {
    }

private:
    int _x;
    const int _y; // const 成员必须初始化
    int& _r;      // 引用成员必须初始化
    Other _oth;   // Other 没有默认构造函数，必须初始化
};
```

---

## 9、总结

```text
1. 类是自定义类型，用来描述一类事物的属性和行为。
2. 对象是由类创建出来的具体变量。
3. 封装是把数据隐藏起来，通过 public 函数安全访问。
4. public 可以类外访问，private 只能类内访问。
5. class 默认 private，struct 默认 public。
6. 类的声明通常写 .hpp，定义通常写 .cpp。
7. 类外定义成员函数要写 类名::函数名。
8. get 函数通常写 const，因为它只读取数据。
9. 构造函数在创建对象时自动调用，用于初始化成员变量。
10. 成员初始化列表更推荐，const 成员、引用成员、无默认构造的成员对象必须用它。
```

一句话记忆：

```text
类负责描述，对象负责使用；封装负责保护数据，构造函数负责初始化对象。
```

---

# Day 4：explicit、析构函数、动态内存和常用类

今天目标：继续学习类与对象后面的内容，理解 `explicit`、析构函数、`new/delete`、`nullptr`，并通过链表、`string`、目录读取代码练习对象封装。

对应代码：

```text
2-代码/day4-/18-explicit示例.cpp
2-代码/day4-/19-析构函数示例.cpp
2-代码/day4-/20-动态内存示例.cpp
2-代码/day4-/test.cpp
2-代码/day4-/list.hpp
2-代码/day4-/list.cpp
2-代码/day4-/21-test-list.cpp
2-代码/day4-/22-string使用示例.cpp
2-代码/day4-/dir.hpp
2-代码/day4-/dir.cpp
2-代码/day4-/23-test-dir.cpp
```

---

## 1、explicit 关键字

`explicit` 通常用来修饰构造函数，作用是：**禁止编译器通过这个构造函数进行隐式类型转换**。

先看没有 `explicit` 的情况：

```cpp
class Demo
{
public:
    Demo(int x)
    {
        _x = x;
    }

private:
    int _x;
};

int main()
{
    Demo d1(100);  // 正常：直接调用构造函数
    Demo d2 = 200; // 也能通过：编译器会自动转换成 Demo(200)

    return 0;
}
```

这里的：

```cpp
Demo d2 = 200;
```

表面上看是把 `int` 赋给 `Demo`，实际上编译器会偷偷帮你变成：

```cpp
Demo d2 = Demo(200);
```

这就叫隐式类型转换。

如果构造函数前面加上 `explicit`：

```cpp
class Demo
{
public:
    explicit Demo(int x)
    {
        _x = x;
    }

private:
    int _x;
};

int main()
{
    Demo d1(100);  // 正确：明确调用构造函数
    Demo d2{200};  // 正确：明确调用构造函数

    // Demo d3 = 300; // 错误：explicit 禁止隐式转换

    return 0;
}
```

一句话记忆：

```text
explicit 用来防止“看起来不像创建对象，但实际被编译器偷偷转成对象”的写法。
```

常见建议：

```text
如果一个构造函数只接收一个参数，通常建议加 explicit，避免意外转换。
```

---

## 2、析构函数

析构函数也是类中的特殊成员函数，作用是：**对象销毁时自动调用，一般用来释放资源**。

基本特点：

```text
1. 函数名是 ~类名
2. 没有返回值
3. 不能写参数
4. 一个类只能有一个析构函数
5. 对象生命周期结束时自动调用
```

示例：

```cpp
#include <iostream>
using namespace std;

class Demo
{
public:
    Demo()
    {
        cout << "Demo()" << endl;
    }

    ~Demo()
    {
        cout << "~Demo()" << endl;
    }
};

int main()
{
    Demo d1;
    cout << "-------" << endl;
    return 0;
}
```

执行过程：

```text
1. 创建 d1，自动调用构造函数 Demo()
2. main 函数结束，d1 销毁，自动调用析构函数 ~Demo()
```

构造函数和析构函数可以这样理解：

```text
构造函数：对象出生时自动调用
析构函数：对象死亡时自动调用
```

---

## 3、全局对象的构造和析构顺序

练习代码 `test.cpp` 中定义了一个全局对象：

```cpp
#include <iostream>
using namespace std;

class Print
{
public:
    Print()
    {
        cout << "hello" << endl;
    }

    ~Print()
    {
        cout << "world" << endl;
    }
};

Print p;

int main()
{
    cout << "cpp" << endl;
    return 0;
}
```

输出结果：

```text
hello
cpp
world
```

原因：

```text
1. 全局对象 p 在 main 函数执行之前创建，所以先输出 hello
2. main 函数执行，输出 cpp
3. 程序结束时，全局对象 p 被销毁，所以最后输出 world
```

这个练习说明：不修改 `main` 函数，也可以通过全局对象的构造和析构，在 `main` 前后执行代码。

---

## 4、动态内存 new 和 delete

C++ 中，对象的内存大致分为三类：

```text
局部对象              栈区
全局对象 / 静态对象    静态存储区
动态对象              堆区
```

C 语言中常用：

```cpp
malloc();
free();
```

C++ 中处理对象时更推荐：

```cpp
new;
delete;
```

原因是：`new/delete` 不只是分配和释放内存，还会自动调用构造函数和析构函数。

### 4.1、创建单个对象

```cpp
Demo* p1 = new Demo(100);
p1->print();
delete p1;
```

执行过程：

```text
new Demo(100)  分配内存，并调用构造函数
p1->print()    通过指针调用成员函数
delete p1      调用析构函数，并释放内存
```

注意：

```cpp
p1->print();
```

等价于：

```cpp
(*p1).print();
```

`->` 是通过对象指针访问成员时使用的运算符。

### 4.2、创建对象数组

```cpp
Demo* p2 = new Demo[5];
delete []p2;
```

注意匹配关系：

```text
new 单个对象       对应 delete
new [] 对象数组    对应 delete []
```

错误示例：

```cpp
Demo* p = new Demo[5];
delete p; // 错误，应该使用 delete []
```

一句话记忆：

```text
怎么 new，就怎么 delete；带 [] 的释放时也要带 []。
```

---

## 5、nullptr 空指针

传统 C/C++ 中经常用 `NULL` 表示空指针，但在 C++ 中，`NULL` 有时会造成函数重载匹配不清楚。

示例：

```cpp
void foo(int x);
void foo(int* p);

// foo(NULL); // 可能产生二义性
foo(nullptr); // 明确表示空指针
```

`nullptr` 是 C++11 引入的空指针字面值，专门表示空指针。

对比：

```text
NULL       本质上通常是 0，可能被当作整数
nullptr    专门表示空指针，类型更明确
```

建议：

```text
C++ 中表示空指针，优先使用 nullptr。
```

---

## 6、双向链表 List

今天的 `list.hpp` 和 `list.cpp` 用类封装了一个简单的双向链表。

链表类的主要成员：

```cpp
class List
{
public:
    List();
    ~List();

    void push_back(Type x);
    void push_front(Type x);
    void pop_back();
    void pop_front();

    Type back() const;
    Type front() const;

    int size() const;
    bool empty() const;
    void print() const;

private:
    struct Node
    {
        Node(Type data);
        Type _data;
        Node* _next;
        Node* _prev;
    };

    Node* _head;
    Node* _tail;
    int _size;
};
```

成员含义：

```text
_head   指向第一个结点
_tail   指向最后一个结点
_size   记录链表中结点个数
_next   指向下一个结点
_prev   指向上一个结点
```

### 6.1、push_back 尾插

```cpp
void List::push_back(Type x)
{
    Node* p = new Node(x);

    if (_size == 0)
    {
        _head = p;
        _tail = p;
    }
    else
    {
        p->_prev = _tail;
        _tail->_next = p;
        _tail = p;
    }

    ++_size;
}
```

逻辑：

```text
1. 先 new 一个新结点
2. 如果链表为空，新结点同时是头和尾
3. 如果链表不为空，把新结点接到原来的尾结点后面
4. 更新 _tail
5. _size 加 1
```

### 6.2、push_front 头插

```cpp
void List::push_front(Type x)
{
    Node* p = new Node(x);

    if (_size == 0)
    {
        _head = p;
        _tail = p;
    }
    else
    {
        p->_next = _head;
        _head->_prev = p;
        _head = p;
    }

    ++_size;
}
```

逻辑和尾插类似，只是插入位置变成链表头部。

### 6.3、pop_back 和 pop_front

删除结点时要注意三件事：

```text
1. 空链表不能删除
2. 删除结点前，要先保存要删除的结点指针
3. delete 后，要修正 _head、_tail、_next、_prev
```

尾删：

```cpp
void List::pop_back()
{
    if (_size == 0)
    {
        return;
    }

    Node* p = _tail;
    _tail = p->_prev;
    delete p;
    --_size;

    if (_size == 0)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
        _tail->_next = nullptr;
    }
}
```

### 6.4、链表和析构函数

链表中的每个结点都是通过 `new Node(x)` 创建的，所以最终应该在析构函数里释放所有结点。

推荐写法：

```cpp
List::~List()
{
    while (!empty())
    {
        pop_front();
    }
}
```

这样当 `List` 对象销毁时，链表中的所有动态结点都会被释放。

---

## 7、字符串类型 std::string

C++ 标准库提供了 `std::string` 表示字符串。

使用前包含头文件：

```cpp
#include <string>
```

常见创建方式：

```cpp
std::string s1;           // 空字符串
std::string s2("hello");  // 使用 C 字符串初始化
std::string s3{"hello"};  // C++11 大括号初始化
std::string s4 = "hello"; // 直接赋值初始化
std::string s5(5, 'a');   // "aaaaa"
```

今天代码中的常用接口：

```cpp
std::string s1 = "hello";

cout << s1.size() << endl;  // 字符个数
cout << s1.empty() << endl; // 是否为空

const char* str = s1.c_str(); // 转成 const char*

size_t index = s1.find("oo"); // 查找子串
if (index == std::string::npos)
{
    cout << "not found" << endl;
}
```

### 7.1、[] 和 at() 的区别

```cpp
cout << s1[10] << endl;    // 越界时结果未知
cout << s1.at(10) << endl; // 越界时会抛出异常
```

简单理解：

```text
[]      速度快，但不检查越界
at()    会检查越界，更安全
```

### 7.2、find 和 npos

```cpp
size_t index = s1.find("oo");
```

如果找到，返回子串第一次出现的位置；如果没找到，返回：

```cpp
std::string::npos
```

判断方式：

```cpp
if (index == std::string::npos)
{
    cout << "not found" << endl;
}
```

---

## 8、目录操作 Dir 类

`dir.hpp` 和 `dir.cpp` 把 Linux 目录读取封装成了一个 `Dir` 类。

相关头文件：

```cpp
#include <dirent.h>
```

核心函数：

```text
opendir()   打开目录
readdir()   读取目录项
closedir()  关闭目录
```

类的声明：

```cpp
class Dir
{
public:
    Dir(std::string path);
    ~Dir();
    List getAllFilenames();

private:
    std::string _path;
    DIR* _pdir;
};
```

### 8.1、构造函数打开目录

```cpp
Dir::Dir(std::string path) : _path(path)
{
    _pdir = opendir(_path.c_str());
    if (_pdir == nullptr)
    {
        perror("opendir error");
        exit(1);
    }
}
```

说明：

```text
_path.c_str() 把 std::string 转成 const char*
opendir() 打开成功会返回 DIR*，失败返回 nullptr
```

### 8.2、析构函数关闭目录

```cpp
Dir::~Dir()
{
    closedir(_pdir);
}
```

这个例子很好地体现了析构函数的作用：

```text
构造函数负责打开资源
析构函数负责释放资源
```

### 8.3、读取所有文件名

```cpp
List Dir::getAllFilenames()
{
    List list;

    while (1)
    {
        struct dirent* p = readdir(_pdir);
        if (p == nullptr)
        {
            break;
        }

        std::string pathfile = _path + p->d_name;
        list.push_back(pathfile);
    }

    return list;
}
```

使用方式：

```cpp
Dir dir("./");
List list = dir.getAllFilenames();
list.print();
```

注意：

```text
Dir 这部分代码依赖 Linux/POSIX 的 dirent.h，在 Windows 原生环境下可能不能直接编译。
```

---

## 9、Day4 总结

```text
1. explicit 用来禁止构造函数参与隐式类型转换。
2. 析构函数写成 ~类名()，对象销毁时自动调用。
3. 构造函数适合申请或打开资源，析构函数适合释放或关闭资源。
4. new 创建动态对象，会调用构造函数。
5. delete 释放动态对象，会调用析构函数。
6. new[] 要配 delete[]，new 要配 delete。
7. C++ 中空指针优先使用 nullptr，不推荐继续用 NULL。
8. 链表结点通常用 new 创建，删除时必须 delete。
9. std::string 比 C 字符串更方便，常用 size、empty、at、c_str、find。
10. opendir/readdir/closedir 可以读取 Linux 目录内容。
```

一句话记忆：

```text
explicit 管转换，析构函数管收尾，new/delete 管堆内存，string 管字符串，Dir 类把目录操作封装成对象。
```

---

# Day 5：异常、this、static 和 BMP 图片显示

今天目标：继续完善类的封装，掌握异常处理、`this` 指针、静态成员，并用类封装屏幕绘制和 BMP 图片显示。

对应代码：

```text
2-代码/day5-异常/list.hpp
2-代码/day5-异常/list.cpp
2-代码/day5-异常/dir.hpp
2-代码/day5-异常/dir.cpp
2-代码/day5-异常/24-异常示例.cpp
2-代码/day5-异常/25-this指针.cpp
2-代码/day5-异常/26-static成员示例.cpp
2-代码/day5-异常/tongxun_v3.cpp
2-代码/day5-异常/28-绘制位图/
```

---

## 1、List 链表补充

Day5 的 `List` 链表用来保存字符串，例如文件名：

```cpp
using Type = std::string;
```

常用接口：

```cpp
void push_back(Type x);
void push_front(Type x);
void pop_back();
void pop_front();
int size() const;
bool empty() const;
Type getElem(int n) const;
```

按位置获取元素：

```cpp
Type List::getElem(int n) const
{
    if (n < 1 or n > _size)
        throw std::out_of_range("n out of range!");

    Node *p = _head;
    for (int i = 1; i < n; i++)
    {
        p = p->_next;
    }

    return p->_data;
}
```

说明：

```text
1. 当前链表下标从 1 开始。
2. 获取元素前要判断范围。
3. 越界时抛出 std::out_of_range，避免访问空指针。
```

---

## 2、Dir 类筛选 BMP 文件

`Dir` 类负责打开目录、读取目录项、筛选 BMP 文件。

主要接口：

```cpp
class Dir
{
public:
    Dir(std::string path);
    ~Dir();

    List getAllFilenames();
    List getBitmaps();
    bool isBitmap(std::string pathfile);
};
```

构造函数打开目录：

```cpp
_pdir = opendir(_path.c_str());
if (_pdir == nullptr)
    throw std::runtime_error("open dir error");
```

析构函数关闭目录：

```cpp
closedir(_pdir);
```

筛选 BMP 文件：

```cpp
bool Dir::isBitmap(std::string pathfile)
{
    return pathfile.find(".bmp") != std::string::npos;
}
```

使用方式：

```cpp
Dir dir("./");
List list = dir.getBitmaps();
list.print();
```

一句话理解：

```text
Dir 把 opendir、readdir、closedir 封装成对象操作，并用 List 保存读取到的文件名。
```

---

## 3、异常处理

异常用于处理运行时错误。

抛出异常：

```cpp
throw std::logic_error("x out of range!");
```

捕获异常：

```cpp
try
{
    foo(-1);
}
catch (int err)
{
    cout << "捕获int类型异常" << endl;
}
catch (double err)
{
    cout << "捕获double类型异常" << endl;
}
```

如果抛出的是标准异常，例如 `std::logic_error`，通常这样接：

```cpp
try
{
    foo(-1);
}
catch (const std::exception& e)
{
    cout << e.what() << endl;
}
```

标准异常类型需要头文件：

```cpp
#include <stdexcept>
```

常见异常：

```text
std::logic_error      逻辑错误
std::runtime_error    运行时错误
std::out_of_range     越界错误
std::bad_alloc        内存申请失败
```

注意：

```text
1. throw 后面的代码不会继续执行。
2. catch 按顺序匹配异常类型。
3. 没有被捕获的异常会继续向上抛出。
4. 析构函数中不建议抛异常。
```

---

## 4、this 指针

对象调用非静态成员函数时，编译器会自动把对象地址传给函数，这个隐藏参数就是 `this`。

示例：

```cpp
class Demo
{
public:
    void setX(int x)
    {
        _x = x;       // 等价于 this->_x = x;
    }

    int getX() const
    {
        return _x;    // 等价于 return this->_x;
    }

private:
    int _x;
};
```

理解：

```text
this 指向当前调用成员函数的那个对象。
```

类型：

```text
普通成员函数中：this 是 类名* const
const 成员函数中：this 是 const 类名* const
```

补充：

```text
成员变量存放在每个对象里。
成员函数存放在代码段，同类型对象共用一份。
this 用来区分当前函数正在操作哪个对象。
```

空类对象：

```text
没有数据成员的对象也占空间，通常 sizeof(空类) == 1。
原因是每个对象都需要有唯一地址。
```

---

## 5、static 静态成员

`static` 修饰类成员时，表示这个成员属于类，而不是属于某一个对象。

静态成员变量：

```cpp
class Demo
{
private:
    static int cnt;
};

int Demo::cnt = 0;
```

特点：

```text
1. 所有对象共享同一份静态成员变量。
2. 不占用普通对象的成员空间。
3. 必须在类外单独定义和初始化。
```

静态成员函数：

```cpp
static int getCnt()
{
    return cnt;
}
```

调用方式：

```cpp
Demo::getCnt();
```

注意：

```text
1. 静态成员函数没有 this 指针。
2. 静态成员函数不能直接访问普通成员变量。
3. 静态成员函数不能写成 const 成员函数。
```

Day5 示例中用 `cnt` 统计当前 `Demo` 对象数量：

```text
构造函数中 cnt++
析构函数中 cnt--
```

---

## 6、通讯录封装

`tongxun_v3.cpp` 把通讯录封装成 `Addressbooks` 类型。

成员数据：

```text
Person personArray[MAX]   联系人数组
int m_Size                当前联系人数量
```

主要接口：

```text
addPerson()       添加联系人
showPerson()      显示联系人
isExist()         判断联系人是否存在
deletePerson()    删除联系人
findPerson()      查找联系人
modifyPerson()    修改联系人
cleanPerson()     清空联系人
```

封装思想：

```text
1. Person 结构体放在 Addressbooks 内部，只服务通讯录。
2. 联系人数组和数量设为 private，外部不能随便修改。
3. 外部只能通过 public 成员函数操作通讯录。
```

---

## 7、屏幕与图形类封装

`28-绘制位图` 目录把屏幕绘制拆成多个类。

类的分工：

```text
Point   保存坐标 x、y
Color   保存 RGB 颜色，并转换成整数颜色值
Screen  打开 /dev/fb0，mmap 映射显存，提供 drawPoint
Rect    保存矩形宽高、位置、颜色，并绘制矩形
Circle  保存圆心、半径、颜色，并绘制圆
Bitmap  读取 BMP 文件，并绘制图片
```

屏幕绘制核心：

```cpp
*(_addr + _w * y + x) = color;
```

含义：

```text
显存可以看成一维数组。
第 y 行第 x 列的位置 = _addr + _w * y + x。
```

构造函数适合做初始化：

```cpp
Screen screen("/dev/fb0");
```

使用方式：

```cpp
Bitmap bmp("./1.bmp");
bmp.draw(screen);
```

---

## 8、BMP 图片显示

BMP 是无压缩位图文件，常见 24 位和 32 位格式。

文件关键位置：

```text
0x00    文件标识，BMP 文件以 'B' 'M' 开头
0x0A    像素数组起始偏移
0x12    图片宽度
0x16    图片高度
0x1C    色深
0x1E    压缩方式，0 表示无压缩
```

像素格式：

```text
24 位 BMP：B G R
32 位 BMP：B G R A
```

每行补齐：

```text
BMP 每一行字节数必须是 4 的倍数，不足部分要跳过。
```

方向判断：

```text
width  > 0：每行从左往右保存
width  < 0：每行从右往左保存
height > 0：整张图从下往上保存
height < 0：整张图从上往下保存
```

绘制坐标：

```cpp
int x = _w > 0 ? j : width - 1 - j;
int y = _h > 0 ? height - 1 - i : i;
screen.drawPoint(x + x0, y + y0, Color(r, g, b).toInt());
```

说明：

```text
如果 height > 0，BMP 第一行像素其实是图片最下面一行，
所以要画到屏幕的 height - 1 - i 行，避免图片上下颠倒。
```

---

## 9、循环播放 BMP 图片

把一个目录中的 BMP 文件名读取出来，保存到 `List`，再循环显示：

```cpp
Dir dir("./bmp");
List bmp_list = dir.getBitmaps();
Screen screen("/dev/fb0");

while (true)
{
    for (int i = 1; i <= bmp_list.size(); i++)
    {
        std::string filename = bmp_list.getElem(i);
        Bitmap bmp(filename);
        bmp.draw(screen);
        sleep(1);
    }
}
```

运行方式：

```bash
./a.out ./bmp
./a.out ./bmp 2
```

说明：

```text
第 1 个参数：BMP 文件夹路径。
第 2 个参数：每张图片显示的秒数。
```

---

## 10、Day5 总结

```text
1. List::getElem 通过范围判断和异常避免越界访问。
2. Dir 类封装目录读取，并筛选 BMP 文件。
3. throw 抛异常，try/catch 捕获异常。
4. this 指针表示当前对象地址，由编译器自动传入。
5. static 成员属于类，所有对象共享，没有 this。
6. 通讯录示例体现了 private 数据 + public 接口的封装。
7. Screen 类封装了 framebuffer 打开、mmap 映射和画点。
8. Rect、Circle、Bitmap 都通过 draw(Screen&) 绘制到屏幕。
9. BMP 像素按 BGR 保存，每行 4 字节对齐。
10. BMP 高度为正时，像素数据从下往上保存，绘制时要翻转 y 坐标。
```

一句话记忆：

```text
Day5 的重点是把错误处理、对象自身 this、类共享 static 和屏幕图片显示，都放进类的封装思路里理解。
```

---

# Day 6：拷贝构造、深浅拷贝和类型转换

今天目标：理解对象复制时会发生什么，掌握拷贝构造函数、深拷贝与浅拷贝、`delete/default`，并认识 C++ 的四种显式类型转换。

对应代码：

```text
2-代码/day6-/29-拷贝构造函数示例.cpp
2-代码/day6-/30-拷贝构造函数示例2.cpp
2-代码/day6-/31-delete与default示例.cpp
2-代码/day6-/32-显示类型转换示例.cpp
```

---

## 1、拷贝构造函数

拷贝构造函数用于用一个已经存在的对象，初始化另一个同类型的新对象。

基本格式：

```cpp
class Demo
{
public:
    Demo(const Demo& rhs);
};
```

说明：

```text
Demo(const Demo& rhs)
```

表示参数是本类类型的 `const` 引用，这种构造函数就是拷贝构造函数。

示例：

```cpp
class Demo
{
public:
    Demo(int x, int y) : _x(x), _y(y) {}

    Demo(const Demo& rhs)
    {
        _x = rhs._x;
        _y = rhs._y;
        cout << "Demo(const Demo&)" << endl;
    }

private:
    int _x;
    int _y;
};
```

如果没有自己写拷贝构造函数，编译器会自动生成一个，默认按成员变量逐个复制。

---

## 2、拷贝构造函数的调用时机

常见调用场景有三种。

### 2.1、用已有对象创建新对象

```cpp
Demo d1(100, 200);

Demo d2(d1);
Demo d3{d1};
Demo d4 = d1;
```

这些都是用 `d1` 初始化一个新的 `Demo` 对象，会调用拷贝构造函数。

### 2.2、对象作为函数参数按值传递

```cpp
void foo(Demo d)
{
}

Demo d1(100, 200);
foo(d1);
```

调用 `foo(d1)` 时，形参 `d` 是一个新对象，需要用 `d1` 拷贝初始化。

### 2.3、函数按值返回对象

```cpp
Demo foo()
{
    Demo d(1, 1);
    return d;
}
```

返回对象时，可能调用拷贝构造函数。

注意：

```text
现代编译器可能会进行返回值优化，省略某些拷贝构造函数调用。
所以实际运行时，不一定每次都能看到拷贝构造函数输出。
```

---

## 3、浅拷贝和深拷贝

### 3.1、浅拷贝

浅拷贝就是简单复制成员变量的值。

如果成员变量是普通类型，例如 `int`、`double`，浅拷贝通常没有问题。

但如果成员变量是指针，浅拷贝只会复制指针地址：

```text
两个对象的指针成员指向同一块堆内存。
```

这样会产生问题：

```text
1. 修改一个对象的数据，可能影响另一个对象。
2. 两个对象析构时，会对同一块内存 delete 两次。
3. 程序可能崩溃。
```

### 3.2、深拷贝

深拷贝是在拷贝对象时，重新申请一块新的内存，再把原对象中的数据复制过去。

示例：

```cpp
class Demo
{
public:
    Demo(int x, int y)
    {
        _x = new int(x);
        _y = new int(y);
    }

    ~Demo()
    {
        delete _x;
        delete _y;
    }

    Demo(const Demo& rhs)
    {
        _x = new int(*rhs._x);
        _y = new int(*rhs._y);
    }

private:
    int* _x;
    int* _y;
};
```

这样拷贝后：

```text
d1._x 和 d2._x 指向不同的内存。
d1._y 和 d2._y 指向不同的内存。
两个对象互不影响，析构时也不会重复释放同一块内存。
```

一句话理解：

```text
浅拷贝：只复制地址。
深拷贝：重新申请内存，再复制内容。
```

---

## 4、delete 和 default 关键字

这里的 `delete` 和释放堆内存的 `delete p;` 不是同一种用法。

### 4.1、= delete

`= delete` 用来删除某些函数，禁止别人调用。

常见用途：禁止对象拷贝。

```cpp
class Demo
{
public:
    Demo() = default;
    Demo(const Demo&) = delete;
};

int main()
{
    Demo d1;
    // Demo d2 = d1;  // 错误，拷贝构造函数被删除
}
```

适合场景：

```text
对象管理独占资源，不希望被复制。
例如文件描述符、锁、某些硬件资源等。
```

### 4.2、= default

`= default` 表示要求编译器生成默认版本的函数。

```cpp
class Demo
{
public:
    Demo() = default;
};
```

常见用途：

```text
1. 明确保留默认构造函数。
2. 让代码意图更清楚。
3. 配合 = delete 控制类能做什么、不能做什么。
```

小结：

```text
= delete   禁止编译器生成或禁止调用某个函数。
= default  要求编译器生成默认版本的函数。
```

---

## 5、C++ 显式类型转换

C 语言风格转换：

```cpp
int a = (int)3.14;
```

C++ 更推荐使用下面四种显式类型转换，因为语义更清楚。

---

## 6、static_cast

`static_cast` 用于比较正常、风险较低的类型转换。

常见用途：

```text
1. 基础类型之间转换。
2. void* 和其他类型指针之间转换。
3. 有继承关系的类指针之间转换。
```

示例：

```cpp
double d = 3.14;
int a = static_cast<int>(d);
```

说明：

```text
3.14 转成 int 后，小数部分会被丢掉，结果是 3。
```

---

## 7、reinterpret_cast

`reinterpret_cast` 用于非常底层、风险较高的强制解释。

常见用途：

```text
1. 不同类型指针之间强转。
2. 整数和指针之间强转。
```

示例：

```cpp
double d = 3.14;
int* p = reinterpret_cast<int*>(&d);
```

注意：

```text
reinterpret_cast 只是换一种类型去解释同一块内存。
它不保证转换后的结果合理，也不保证访问是安全的。
```

普通业务代码中应尽量少用。

---

## 8、const_cast

`const_cast` 用来去掉指针或引用上的 `const` 属性。

示例：

```cpp
int a = 100;
const int* p = &a;

int* q = const_cast<int*>(p);
*q = 200;
```

这种情况中，`a` 本身不是常量，只是通过 `const int*` 不能修改，所以去掉 `const` 后修改通常可以。

但如果原对象本身就是 `const`，再强行修改就是未定义行为：

```cpp
const int a = 100;
const int* p = &a;

int* q = const_cast<int*>(p);
*q = 200;  // 未定义行为
```

注意：

```text
const_cast 只能去掉访问路径上的 const。
如果对象本身真的是 const，不应该修改它。
```

---

## 9、dynamic_cast

`dynamic_cast` 主要用于多态类型之间的安全向下转换。

一般用于继承和虚函数相关场景：

```cpp
Base* p = new Derived;
Derived* q = dynamic_cast<Derived*>(p);
```

当前阶段先记住：

```text
dynamic_cast 常用于有继承关系、有虚函数的类之间转换。
后面学习继承和多态时再重点掌握。
```

---

## 10、Day6 总结

```text
1. 拷贝构造函数用于用已有对象初始化新对象。
2. 拷贝构造函数参数通常写成 const 类名&。
3. 对象按值传参、按值返回、用已有对象创建新对象时，可能调用拷贝构造。
4. 类中有指针成员并管理堆内存时，要注意深拷贝。
5. 浅拷贝只复制地址，深拷贝会重新申请内存并复制内容。
6. = delete 可以禁止某些函数被调用，例如禁止拷贝。
7. = default 可以要求编译器生成默认版本的函数。
8. static_cast 用于常规转换。
9. reinterpret_cast 用于底层重新解释，风险较高。
10. const_cast 用于去掉 const，但不能修改真正的 const 对象。
11. dynamic_cast 用于多态类型转换，后面继承多态再深入。
```

一句话记忆：

```text
Day6 的重点是对象复制：有资源就想深拷贝，不想被复制就 delete；类型转换要选语义明确的 C++ 写法。
```
