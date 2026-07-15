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

---

# Day 7：友元、运算符重载和函数对象

今天目标：掌握友元的作用，理解运算符重载的本质，并会重载常见运算符：`+`、`==`、`<<`、`>>`、`[]`、`=`、`++`、`--`、`()`.

对应代码：

```text
2-代码/day7-友元函数/33-友元示例1.cpp
2-代码/day7-友元函数/34-友元示例2.cpp
2-代码/day7-友元函数/35-友元示例3.cpp
2-代码/day7-友元函数/36-典型双目运算符重载示例.cpp
2-代码/day7-友元函数/37-输入输出运算符重载示例.cpp
2-代码/day7-友元函数/38-下标运算符示例.cpp
2-代码/day7-友元函数/39-赋值运算符重载示例.cpp
2-代码/day7-友元函数/40-赋值运算符重载示例2.cpp
2-代码/day7-友元函数/41-自增运算符示例.cpp
2-代码/day7-友元函数/42-函数调用运算符示例.cpp
2-代码/day7-友元函数/43-函数对象使用示例.cpp
```

---

## 1、友元 friend

友元用于授权某个函数或类访问本类的私有成员。

常见形式：

```cpp
class Demo
{
    friend void print_demo(Demo d);     // 友元函数
    friend class Other;                 // 友元类
};
```

注意：

```text
1. 友元声明可以写在类中任意位置。
2. 友元不是成员函数，只是被允许访问私有成员。
3. 友元关系是单向的，不会自动反向。
4. 友元关系不能传递。
```

---

## 2、运算符重载

运算符重载就是给已有运算符添加适合类对象的新功能。

本质：

```text
运算符重载本质上还是函数重载。
```

函数名格式：

```cpp
operator运算符
```

例如：

```cpp
operator+
operator==
operator<<
operator[]
```

简单理解：

```cpp
d1 + d2;
```

可能等价于：

```cpp
operator+(d1, d2);     // 全局函数
d1.operator+(d2);      // 成员函数
```

---

## 3、双目运算符

典型双目运算符：

```text
+ - * /
== != > >= < <=
```

可以重载为全局函数，也可以重载为成员函数。

全局函数示例：

```cpp
class Demo
{
public:
    friend Demo operator+(Demo d1, Demo d2);
    Demo(int x = 0) : _x(x) {}

private:
    int _x;
};

Demo operator+(Demo d1, Demo d2)
{
    return Demo(d1._x + d2._x);
}
```

成员函数示例：

```cpp
bool operator==(Demo d2) const
{
    return _x == d2._x;
}
```

建议：

```text
不修改对象的运算符函数，尽量写 const。
参数较大时，优先用 const 引用传参。
```

---

## 4、输入输出运算符

`<<` 和 `>>` 一般重载为全局函数。

原因：

```cpp
cout << d;
cin >> d;
```

左操作数是 `cout` 或 `cin`，不是当前类对象。

基本形式：

```cpp
std::ostream& operator<<(std::ostream& out, const Demo& d);
std::istream& operator>>(std::istream& in, Demo& d);
```

示例：

```cpp
class Demo
{
public:
    friend std::ostream& operator<<(std::ostream& out, const Demo& d);
    friend std::istream& operator>>(std::istream& in, Demo& d);
    Demo(int x = 0) : _x(x) {}

private:
    int _x;
};

std::ostream& operator<<(std::ostream& out, const Demo& d)
{
    out << "Demo(" << d._x << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Demo& d)
{
    in >> d._x;
    return in;
}
```

返回引用是为了支持连续输入输出：

```cpp
cout << d1 << d2 << endl;
cin >> d1 >> d2;
```

---

## 5、下标运算符 []

`[]` 必须重载为成员函数。

常见写法：

```cpp
int& operator[](int index);
const int& operator[](int index) const;
```

示例：

```cpp
class Demo
{
public:
    int& operator[](int index)
    {
        return p[index];
    }

    const int& operator[](int index) const
    {
        return p[index];
    }

private:
    int* p;
};
```

说明：

```text
非 const 版本：支持 d[0] = 100。
const 版本：支持 const 对象读取 d[0]。
返回引用：才能真正修改对象内部元素。
```

---

## 6、赋值运算符 =

拷贝构造和拷贝赋值不同：

```cpp
Demo d2 = d1;   // 拷贝构造，创建新对象
d2 = d1;        // 拷贝赋值，已有对象之间赋值
```

赋值运算符只能重载为成员函数：

```cpp
Demo& operator=(const Demo& rhs);
```

基本写法：

```cpp
Demo& operator=(const Demo& rhs)
{
    if (this != &rhs)
    {
        _x = rhs._x;
    }

    return *this;
}
```

如果类中管理堆内存，需要深拷贝：

```text
1. 判断自赋值。
2. 释放旧资源。
3. 申请新资源。
4. 复制右侧对象的数据。
5. return *this。
```

---

## 7、自增自减运算符

前置和后置写法不同。

前置：

```cpp
Demo& operator++();       // ++d
Demo& operator--();       // --d
```

后置：

```cpp
Demo operator++(int);     // d++
Demo operator--(int);     // d--
```

后置版本中的 `int` 是占位参数，只用于区分前置和后置。

核心区别：

```text
前置：先改变自己，再返回改变后的自己，通常返回引用。
后置：先保存旧值，再改变自己，返回旧值，通常返回对象。
```

示例：

```cpp
Demo& operator++()
{
    ++x;
    return *this;
}

Demo operator++(int)
{
    Demo tmp = *this;
    ++x;
    return tmp;
}
```

---

## 8、函数调用运算符 ()

`() `只能重载为成员函数。

```cpp
class Demo
{
public:
    void operator()()
    {
        cout << "hello operator()" << endl;
    }

    void operator()(int x)
    {
        cout << "x = " << x << endl;
    }
};
```

使用：

```cpp
Demo d;
d();
d(100);
```

等价于：

```cpp
d.operator()();
d.operator()(100);
```

---

## 9、函数对象

重载了 `operator()` 的对象，称为函数对象，也叫仿函数。

函数对象像函数一样调用，但它比普通函数多一个优点：

```text
函数对象可以保存状态。
```

示例：

```cpp
class PrintInt
{
public:
    PrintInt(char c = ' ') : c(c) {}

    void operator()(int x)
    {
        cout << x << c;
    }

private:
    char c;
};
```

使用：

```cpp
PrintInt p1('^');
p1(100);          // 输出 100^

PrintInt('~')(5); // 匿名函数对象
```

函数对象常用于把“行为”传给函数：

```cpp
void print_array(int a[], int n, PrintInt func)
{
    for (int i = 0; i < n; i++)
        func(a[i]);
}
```

---

## 10、Day7 总结

```text
1. friend 用于授权函数或类访问私有成员。
2. 运算符重载本质是函数重载，函数名是 operator运算符。
3. 双目运算符可写成全局函数或成员函数。
4. << 和 >> 通常写成全局函数，并返回流对象引用。
5. [] 必须写成成员函数，常提供 const 和非 const 两个版本。
6. = 只能写成成员函数，管理资源时要防止浅拷贝问题。
7. 前置++/--返回改变后的自己，后置++/--返回改变前的旧值。
8. 后置++/--的 int 参数只是占位，用来区分前置和后置。
9. operator() 让对象可以像函数一样调用。
10. 函数对象比普通函数更灵活，因为它可以保存状态。
```

一句话记忆：

```text
Day7 的重点是让类对象用起来更像内置类型：能加、能比、能输入输出、能下标访问，甚至能像函数一样调用。
```

---

# Day 8：lambda 表达式、移动语义、自定义字符串和单例模式

今天重点：掌握 lambda 的基本用法，理解移动语义和 `std::move`，复习资源管理类的写法，认识单例模式。

对应代码：

```text
2-代码/day8-lambda表达式/44-lambda表达式示例.cpp
2-代码/day8-lambda表达式/45-lambda表达式使用示例.cpp
2-代码/day8-lambda表达式/46-移动操作示例.cpp
2-代码/day8-lambda表达式/47-自定义字符串类型.cpp
2-代码/day8-lambda表达式/48-单例模式示例1.cpp
2-代码/day8-lambda表达式/49-单例模式示例2.cpp
2-代码/day8-lambda表达式/50-单例模式示例3.cpp
```

---

## 1、lambda 表达式

lambda 表达式就是匿名函数，适合临时写一段简单逻辑。

基本格式：

```cpp
[捕获列表](参数列表) -> 返回值类型
{
    函数体;
};
```

常见写法：

```cpp
auto print = []{
    cout << "hello lambda!" << endl;
};

print();
```

捕获方式：

```cpp
[=]  // 按值捕获，拿到外部变量的副本
[&]  // 按引用捕获，可以修改外部变量
```

示例：

```cpp
int x = 1;
int y = 2;

[=]() {
    cout << x << endl;
    cout << y << endl;
}();

[&](int z) {
    x += z;
    y += z;
}(100);
```

注意：

```text
无捕获 lambda 可以转换成普通函数指针。
有捕获 lambda 不能转换成普通函数指针。
```

示例：

```cpp
int index = find_array(a, 5, [](int x){
    return x % 2 == 0;
});
```

---

## 2、函数对象和 lambda

函数对象是重载了 `operator()` 的对象。

```cpp
class EvenNumber
{
public:
    bool operator()(int x)
    {
        return x % 2 == 0;
    }
};
```

使用：

```cpp
EvenNumber func;
func(10);
```

lambda 本质上也类似一个函数对象。

```cpp
[](int x){ return x % 2 == 0; }
```

简单理解：

```text
函数对象：适合复用、保存状态。
lambda：适合临时传入一小段逻辑。
```

---

## 3、移动语义

移动语义用于减少不必要的深拷贝。

如果类中管理堆内存：

```cpp
class Demo
{
private:
    char* p;
};
```

普通拷贝需要重新申请内存并复制内容。移动语义则是直接转移资源所有权。

核心思想：

```text
能移动就不拷贝。
把右边对象的资源拿过来，再把右边对象置空。
```

---

## 4、移动构造和移动赋值

移动构造函数：

```cpp
Demo(Demo&& rhs)
{
    cout << "移动构造" << endl;
    p = rhs.p;
    rhs.p = nullptr;
}
```

移动赋值运算符：

```cpp
Demo& operator=(Demo&& rhs)
{
    cout << "移动赋值" << endl;
    if (this == &rhs)
        return *this;

    delete[] p;
    p = rhs.p;
    rhs.p = nullptr;

    return *this;
}
```

关键点：

```text
1. 接管右侧对象的资源。
2. 把右侧对象的指针置空。
3. 防止两个对象释放同一块内存。
```

---

## 5、std::move

`std::move` 本身不移动数据，它只是把对象转换成右值引用。

```cpp
Demo tmp = std::move(s1);
```

含义：

```text
告诉编译器：s1 可以被当作临时对象使用。
如果类中有移动构造，就优先调用移动构造。
```

交换函数示例：

```cpp
void swap(Demo& s1, Demo& s2)
{
    Demo tmp = std::move(s1);
    s1 = std::move(s2);
    s2 = std::move(tmp);
}
```

注意：

```text
被 std::move 后的对象仍然可以析构，也可以重新赋值，
但不要再依赖它原来的值。
```

---

## 6、自定义字符串类型

`47-自定义字符串类型.cpp` 中实现了一个简单的 `china::string`。

核心成员：

```cpp
char* _data;
```

因为它管理堆内存，所以要重点写好：

```text
构造函数
析构函数
拷贝构造函数
拷贝赋值运算符
```

构造函数：

```cpp
string(const char *s = NULL)
{
    if (s == NULL)
    {
        _data = new char[1];
        _data[0] = '\0';
    }
    else
    {
        _data = new char[strlen(s) + 1];
        strcpy(_data, s);
    }
}
```

析构函数：

```cpp
~string()
{
    delete[] _data;
}
```

拷贝构造：

```cpp
string(const string &rhs)
{
    _data = new char[strlen(rhs._data) + 1];
    strcpy(_data, rhs._data);
}
```

拷贝赋值：

```cpp
string &operator=(const string &rhs)
{
    if (this != &rhs)
    {
        delete[] _data;
        _data = new char[strlen(rhs._data) + 1];
        strcpy(_data, rhs._data);
    }
    return *this;
}
```

重点：

```text
默认拷贝只复制指针地址，会造成浅拷贝问题。
自定义 string 必须深拷贝，避免重复释放同一块内存。
```

常用接口：

```cpp
int size() const;
bool empty() const;
const char* c_str() const;
char& operator[](int index);
string operator+(const string& rhs) const;
bool operator<(const string& rhs) const;
```

---

## 7、单例模式

单例模式保证一个类在程序中只有一个对象。

核心写法：

```text
1. 构造函数私有化。
2. 提供 static instance() 函数获取唯一对象。
3. 禁止拷贝构造和赋值。
```

推荐写法：

```cpp
class Singleton
{
public:
    static Singleton& instance()
    {
        static Singleton obj;
        return obj;
    }

private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
```

使用：

```cpp
Singleton& s1 = Singleton::instance();
Singleton& s2 = Singleton::instance();
```

说明：

```text
s1 和 s2 引用的是同一个对象。
C++11 以后，函数内 static 局部对象初始化是线程安全的。
```

饿汉式：

```text
程序开始时就创建对象。
```

懒汉式：

```text
第一次使用时才创建对象。
```

当前阶段推荐记住：

```text
函数内 static 局部对象是实现单例的常用写法。
```

---

## 8、Day8 总结

```text
1. lambda 是匿名函数，适合临时写一段逻辑。
2. [=] 是值捕获，[&] 是引用捕获。
3. 无捕获 lambda 可以转换成函数指针。
4. 函数对象是重载了 operator() 的对象。
5. 移动语义用于转移资源，减少深拷贝。
6. std::move 只是把对象转换成右值引用。
7. 移动构造和移动赋值都要把原对象指针置空。
8. 管理堆内存的类要注意深拷贝和析构。
9. 自定义 string 的重点是资源管理。
10. 单例模式保证一个类只有一个对象。
11. 单例要私有化构造函数，并禁止拷贝和赋值。
12. 函数内 static 局部对象是推荐的单例写法。
```

一句话记忆：

```text
Day8 重点：lambda 写临时逻辑，move 转移资源，string 练资源管理，单例控制对象数量。
```

---

# Day 9：迭代器和适配器模式

本节代码位置：

```text
2-代码/day9-迭代器/51-字符串迭代器示例.cpp
2-代码/day9-迭代器/52-test-list-迭代器版.cpp
2-代码/day9-迭代器/53-适配器示例.cpp
2-代码/day9-迭代器/list.hpp
2-代码/day9-迭代器/list.cpp
2-代码/day9-迭代器/stack.hpp
2-代码/day9-迭代器/stack.cpp
```

## 1、迭代器模式

迭代器模式的作用：

```text
提供一种方法，顺序访问一个聚合对象中的各个元素，
同时不暴露这个对象内部的存储结构。
```

简单理解：

```text
容器负责保存数据。
迭代器负责遍历数据。
外部使用者不需要知道容器内部到底是数组、链表还是其他结构。
```

C++ 标准库中常见的迭代器用法：

```cpp
for (auto it = 容器.begin(); it != 容器.end(); ++it)
{
    cout << *it << endl;
}
```

迭代器通常需要支持：

```text
*it       访问当前元素
++it      移动到下一个元素
it != end 判断是否遍历结束
```

容器通常需要提供：

```text
begin()   返回第一个元素位置的迭代器
end()     返回尾后位置的迭代器
```

注意：

```text
end() 不是最后一个元素，而是最后一个元素后面的那个位置。
end() 只能用来比较，不能解引用。
```

---

## 2、字符串迭代器示例

`51-字符串迭代器示例.cpp` 中给自定义字符串 `china::string` 添加了迭代器。

字符串内部核心数据：

```cpp
char *_data;
```

因为字符串本质上是一段连续字符，所以迭代器内部只需要保存一个字符指针：

```cpp
class iterator
{
public:
    iterator(char *p) : p(p) {}

    char &operator*()
    {
        return *p;
    }

    iterator &operator++()
    {
        ++p;
        return *this;
    }

    bool operator!=(const iterator &rhs) const
    {
        return this->p != rhs.p;
    }

private:
    char *p;
};
```

`begin()` 返回第一个字符的位置：

```cpp
iterator begin()
{
    return iterator(_data);
}
```

`end()` 返回字符串结束符 `'\0'` 的位置：

```cpp
iterator end()
{
    return iterator(_data + strlen(_data));
}
```

使用方式：

```cpp
china::string s1 = "hello world";

for (china::string::iterator it = s1.begin(); it != s1.end(); ++it)
{
    cout << *it << ' ';
}
```

输出效果：

```text
h e l l o   w o r l d
```

重点：

```text
字符串迭代器的本质就是 char*。
operator* 返回当前字符。
operator++ 让指针后移。
operator!= 比较两个迭代器是否指向同一位置。
```

---

## 3、自定义 List 迭代器

`list.hpp` 中的 `List` 是一个双向链表。

链表结点：

```cpp
struct Node
{
    Node(Type data);
    Type _data;
    struct Node *_next;
    struct Node *_prev;
};
```

这里：

```cpp
using Type = std::string;
```

所以当前链表保存的是字符串。

链表本身保存：

```cpp
Node *_head;
Node *_tail;
int _size;
```

自定义链表的迭代器定义在 `List` 类内部：

```cpp
class iterator
{
public:
    iterator();
    Type &operator*();
    iterator &operator++();
    bool operator!=(const iterator &rhs) const;

private:
    friend class List;
    Node *_p;
    iterator(Node *p);
};
```

为什么要把迭代器定义在 `List` 里面？

```text
1. 迭代器是专门为 List 服务的。
2. 它需要知道 List 的结点类型 Node。
3. 外部使用者只需要会用 iterator，不需要知道 Node 的细节。
```

为什么需要 `friend class List`？

```text
iterator(Node *p) 是私有构造函数。
外部不能随便用 Node* 创建迭代器。
只有 List 自己能通过 begin() 和 end() 创建合法迭代器。
```

迭代器默认构造：

```cpp
List::iterator::iterator() : _p(nullptr) {}
```

用结点指针构造：

```cpp
List::iterator::iterator(Node *p) : _p(p) {}
```

解引用：

```cpp
Type &List::iterator::operator*()
{
    return _p->_data;
}
```

前置自增：

```cpp
List::iterator &List::iterator::operator++()
{
    _p = _p->_next;
    return *this;
}
```

不等比较：

```cpp
bool List::iterator::operator!=(const iterator &rhs) const
{
    return _p != rhs._p;
}
```

`begin()` 返回头结点：

```cpp
List::iterator List::begin()
{
    return iterator(_head);
}
```

`end()` 返回空指针：

```cpp
List::iterator List::end()
{
    return iterator(nullptr);
}
```

因为链表最后一个结点的 `_next` 是 `nullptr`，所以遍历到 `nullptr` 就表示结束。

使用方式：

```cpp
List list;

list.push_back("hello");
list.push_back("world");
list.push_back("iterator");
list.push_front("C++");

for (auto it = list.begin(); it != list.end(); ++it)
{
    cout << *it << endl;
}
```

输出顺序：

```text
C++
hello
world
iterator
```

重点：

```text
List 迭代器的本质就是 Node*。
operator* 返回当前结点的数据。
operator++ 让指针移动到下一个结点。
begin() 是 _head。
end() 是 nullptr。
空链表时 begin() == end()。
```

注意：

```text
不能对 end() 解引用，因为 end() 内部是 nullptr。
链表删除结点后，指向被删除结点的迭代器会失效。
```

---

## 4、范围 for 的条件

范围 for 的写法：

```cpp
for (auto &x : 容器)
{
    cout << x << endl;
}
```

想让自定义容器支持范围 for，至少要提供：

```text
begin()
end()
迭代器的 operator*
迭代器的 operator++
迭代器的 operator!=
```

所以 `List` 提供了 `begin()`、`end()` 和 `iterator` 后，理论上就可以写：

```cpp
for (const auto &c : list)
{
    cout << c << endl;
}
```

当前代码中这段是注释状态：

```cpp
// for (const auto &c : list)
// {
//     cout << c << endl;
// }
```

如果要支持 `const List` 的范围 for，还需要补充 `const` 版本的 `begin()` 和 `end()`。

---

## 5、适配器模式

适配器模式的作用：

```text
把一个类的接口转换成用户希望的另一个接口。
```

简单理解：

```text
原来的类功能够用，但是接口名字或使用方式不符合当前需求。
这时可以再包一层，把旧接口包装成新接口。
```

适配器也叫包装器。

常见实现方式：

```text
对象适配器：通过组合实现，类里面保存一个已有对象。
类适配器：通过继承实现。
```

本节代码使用的是对象适配器。

---

## 6、用 List 适配 Stack

栈的特点：

```text
后进先出，LIFO。
最后放进去的数据，最先取出来。
```

`stack.hpp` 中定义了 `Stack`：

```cpp
class Stack
{
public:
    void push(Type x);
    void pop();
    Type top() const;
    bool empty() const;
    int size() const;

private:
    List _list;
};
```

这里 `Stack` 内部保存了一个 `List`：

```cpp
List _list;
```

也就是说：

```text
Stack 自己不重新实现链表。
Stack 直接复用 List 的功能。
Stack 只是把 List 的接口包装成栈的接口。
```

接口对应关系：

```text
Stack::push(x)   -> List::push_back(x)
Stack::pop()     -> List::pop_back()
Stack::top()     -> List::back()
Stack::empty()   -> List::empty()
Stack::size()    -> List::size()
```

实现：

```cpp
void Stack::push(Type x)
{
    _list.push_back(x);
}

void Stack::pop()
{
    _list.pop_back();
}

Type Stack::top() const
{
    return _list.back();
}

bool Stack::empty() const
{
    return _list.empty();
}

int Stack::size() const
{
    return _list.size();
}
```

为了兼容课堂中 `LinkStack` 的叫法，还写了类型别名：

```cpp
using LinkStack = Stack;
```

使用方式：

```cpp
LinkStack s1;

s1.push("hello");
s1.push("cpp");
s1.push("world");
s1.push("!!!");

while (!s1.empty())
{
    cout << s1.top() << endl;
    s1.pop();
}
```

输出顺序：

```text
!!!
world
cpp
hello
```

重点：

```text
Stack 是适配器。
List 是被适配的已有类。
Stack 通过组合 List，复用链表尾插、尾删、取尾元素的能力。
```

---

## 7、Day9 总结

```text
1. 迭代器用于遍历容器，同时隐藏容器内部结构。
2. begin() 返回第一个元素的位置。
3. end() 返回尾后位置，不能解引用。
4. 迭代器常用操作是 *、++、!=。
5. 字符串迭代器的本质是 char*。
6. List 迭代器的本质是 Node*。
7. 链表的 begin() 是 _head，end() 是 nullptr。
8. 空链表时 begin() == end()。
9. 自定义容器想支持范围 for，需要 begin()、end() 和基本迭代器操作。
10. 适配器模式用于把已有类的接口包装成新的接口。
11. Stack 可以通过组合 List 实现。
12. 栈的特点是后进先出。
```

一句话记忆：

```text
Day9 重点：迭代器负责遍历容器，适配器负责包装接口；List 能遍历，Stack 复用 List。
```

---

# Day 10：继承

本节代码位置：

```text
2-代码/day10-继承/54-继承规则验证.cpp
2-代码/day10-继承/55-私有继承示例.cpp
2-代码/day10-继承/56-继承中的构造函数示例.cpp
2-代码/day10-继承/57-继承中的同名成员示例.cpp
2-代码/day10-继承/58-公有派生类与基类关系示例.cpp
2-代码/day10-继承/59-类适配器示例.cpp
2-代码/day10-继承/60-多重继承示例1.cpp
2-代码/day10-继承/61-菱形继承示例.cpp
```

## 1、继承的概念

继承就是在已有类的基础上创建新类。

```text
已有类：基类，也叫父类。
新类：派生类，也叫子类。
```

继承的作用：

```text
1. 复用已有代码。
2. 减少重复成员。
3. 描述类型之间的关系。
```

示例：

```text
学生 -> 大学生、中学生、小学生
计算机 -> 台式机、笔记本、平板
车 -> 小汽车、公交车、洒水车
```

语法：

```cpp
class 派生类名 : 继承方式 基类名
{
    派生类新增成员;
};
```

例如：

```cpp
class Derived : public Base
{
};
```

根据基类数量，继承可以分为：

```text
单继承：只有一个基类。
多重继承：有两个或两个以上基类。
```

注意：

```text
class 默认是 private 继承。
struct 默认是 public 继承。
实际写代码时建议把继承方式明确写出来。
```

---

## 2、继承方式和访问权限

继承方式决定基类成员到派生类之后的访问权限。

三种继承方式：

```text
public      公有继承
private     私有继承
protected   保护继承
```

基类成员自身也有三种访问权限：

```text
public      类内可以访问，类外可以访问。
protected   类内可以访问，派生类内可以访问，类外不能访问。
private     只有本类内部可以访问，派生类和类外都不能直接访问。
```

公有继承：

```text
基类 public 成员    -> 派生类 public 成员
基类 protected 成员 -> 派生类 protected 成员
基类 private 成员   -> 派生类不可直接访问
```

私有继承：

```text
基类 public 成员    -> 派生类 private 成员
基类 protected 成员 -> 派生类 private 成员
基类 private 成员   -> 派生类不可直接访问
```

保护继承：

```text
基类 public 成员    -> 派生类 protected 成员
基类 protected 成员 -> 派生类 protected 成员
基类 private 成员   -> 派生类不可直接访问
```

重点：

```text
不管哪种继承方式，基类 private 成员都不能在派生类中直接访问。
继承方式主要影响 public 和 protected 成员在派生类中的权限。
```

---

## 3、公有继承规则

`54-继承规则验证.cpp` 中：

```cpp
class Base
{
public:
    int x;
private:
    int y;
protected:
    int z;
};

class Derived : public Base
{
public:
    void setValue()
    {
        x = 1;
        // y = 2; // 错误，派生类不能直接访问基类 private 成员
        z = 3;
    }
};
```

类外使用：

```cpp
Derived d1;
d1.x = 1;   // 可以，public 继承后 x 仍然是 public
// d1.y = 2; // 错误，private 成员类外不能访问
// d1.z = 3; // 错误，protected 成员类外不能访问
```

结论：

```text
public 继承保持基类 public/protected 的权限级别。
public 继承常用于表达 is-a 关系。
```

---

## 4、私有继承规则

`55-私有继承示例.cpp` 中：

```cpp
class Derived : private Base
{
public:
    void setValue()
    {
        x = 1;
        // y = 2; // 错误
        z = 3;
    }
};
```

在 `Derived` 内部：

```text
x 可以访问，因为 Base::x 原来是 public。
z 可以访问，因为 Base::z 原来是 protected。
y 不可以直接访问，因为 Base::y 是 private。
```

但是在类外：

```cpp
Derived d1;
// d1.x = 1; // 错误，private 继承后 x 变成 Derived 的 private 成员
// d1.z = 3; // 错误，protected/private 类外都不能访问
```

再派生一层：

```cpp
class Derived2 : public Derived
{
public:
    void test()
    {
        // x = 10; // 错误，x 在 Derived 中已经变成 private
        // z = 30; // 错误，z 在 Derived 中已经变成 private
    }
};
```

结论：

```text
private 继承会把基类 public/protected 成员变成派生类 private 成员。
下一层派生类不能再直接访问这些成员。
```

---

## 5、继承中的构造和析构

构造函数和析构函数不能被继承。

```text
基类部分由基类构造函数初始化。
派生类新增部分由派生类构造函数初始化。
```

如果基类有默认构造函数：

```text
创建派生类对象时，会自动调用基类默认构造函数。
```

如果基类没有默认构造函数，或者想调用带参数构造函数：

```text
必须在派生类构造函数初始化列表中显式调用基类构造函数。
```

示例：

```cpp
class Derived : public Base
{
public:
    Derived(int x, int y, int z) : Base(x, y, z), a(0)
    {
        cout << "Derived(int,int,int)" << endl;
    }

private:
    int a;
    Base b;
};
```

这里：

```text
Base(x, y, z) 初始化继承来的基类子对象。
a(0) 初始化派生类自己的成员。
Base b 是成员对象，会自动调用 Base 的构造函数。
```

创建派生类对象时，构造顺序：

```text
1. 基类构造函数。
2. 成员对象构造函数。
3. 派生类构造函数。
```

销毁派生类对象时，析构顺序相反：

```text
1. 派生类析构函数。
2. 成员对象析构函数。
3. 基类析构函数。
```

重点：

```text
先构造里面，再构造外面。
先析构外面，再析构里面。
```

---

## 6、继承中的同名成员

派生类可以定义和基类同名的成员。

如果出现同名成员，派生类自己的成员会隐藏基类的同名成员。

示例：

```cpp
class Base
{
public:
    void setX(int x);
    int getX() const;

protected:
    int x;
};

class Derived : public Base
{
public:
    void setX(int x);
    int getX() const;

protected:
    int x;
};
```

使用：

```cpp
Derived d1;
d1.setX(100);              // 调用 Derived::setX()
cout << d1.getX() << endl; // 调用 Derived::getX()
```

如果想访问基类中被隐藏的成员，需要加作用域：

```cpp
cout << d1.Base::getX() << endl;
```

注意：

```text
函数隐藏只看函数名。
只要派生类有同名函数，基类中同名函数都会被隐藏。
这和函数重载不同。
```

---

## 7、公有派生类与基类的关系

公有继承表示 is-a 关系。

```text
Derived 是一种 Base。
需要 Base 的地方，可以使用 Derived。
```

常见用法：

```cpp
Derived d1(100, 200);

Base b1 = d1; // 用派生类对象初始化基类对象
b1 = d1;      // 用派生类对象给基类对象赋值

Base *p1 = &d1; // 基类指针指向派生类对象
Base &r = d1;   // 基类引用绑定派生类对象
```

对象切片：

```cpp
Base b1 = d1;
```

这句只会保留 `Base` 部分，`Derived` 新增的 `y` 会被切掉。

基类指针和引用：

```cpp
Base *p1 = &d1;
p1->print();

Base &r = d1;
r.print();
```

当前代码里 `print()` 不是虚函数，所以：

```text
通过 Base* 或 Base& 调用 print()，调用的是 Base::print()。
不会自动调用 Derived::print()。
```

如果要让基类指针根据实际对象类型调用派生类函数，需要后面学习的虚函数和多态。

---

## 8、类适配器

Day9 中用组合实现了对象适配器：

```cpp
class Stack
{
private:
    List _list;
};
```

Day10 中用私有继承实现类适配器：

```cpp
class LinkStack : private List
{
public:
    void push(std::string s)
    {
        push_back(s);
    }

    void pop()
    {
        pop_back();
    }

    std::string top() const
    {
        return back();
    }

    bool empty() const
    {
        return List::empty();
    }
};
```

为什么这里是私有继承？

```text
LinkStack 不是一种 List。
LinkStack 只是用 List 的能力来实现栈。
栈只应该暴露 push、pop、top、empty 等接口。
不应该把 List 的 push_front、pop_front、getElem 等接口暴露出去。
```

如果写成公有继承：

```cpp
class LinkStack : public List
{
};
```

外部就可以这样破坏栈的规则：

```cpp
LinkStack s;
s.push_front("hello");
s.pop_front();
```

这不符合栈“后进先出”的特点。

所以这里用私有继承：

```text
private 继承表示“用基类实现自己”。
public 继承表示“自己是一种基类”。
```

一句话：

```text
LinkStack 是栈，不是链表；它只是借用 List 实现栈，所以用 private 继承。
```

---

## 9、多重继承

多重继承就是一个派生类同时继承多个基类。

语法：

```cpp
class Derived : public Base1, public Base2
{
};
```

示例：

```cpp
class Base1
{
public:
    void print() const;
};

class Base2
{
public:
    void print() const;
};

class Derived : public Base1, public Base2
{
};
```

如果两个基类中有同名成员：

```cpp
Derived d1;
// d1.print(); // 错误，二义性
```

编译器不知道你想调用 `Base1::print()` 还是 `Base2::print()`。

解决方式：显式指定作用域。

```cpp
d1.Base1::print();
d1.Base2::print();
```

重点：

```text
多重继承容易出现同名成员二义性。
遇到二义性时，用 类名::成员名 指定访问路径。
```

---

## 10、菱形继承和虚继承

菱形继承结构：

```text
    A
   / \
  B   C
   \ /
    D
```

普通写法：

```cpp
class A {};
class B : public A {};
class C : public A {};
class D : public B, public C {};
```

问题：

```text
D 通过 B 继承了一份 A。
D 通过 C 又继承了一份 A。
所以 D 对象中会有两份 A 子对象。
```

如果 `A` 中有成员 `x`：

```cpp
D d;
// d.x = 10; // 错误，不知道是 B 路线的 A::x，还是 C 路线的 A::x
```

解决方式：虚继承。

```cpp
class A
{
public:
    int x;
};

class B : virtual public A
{
};

class C : virtual public A
{
};

class D : public B, public C
{
};
```

也可以写成：

```cpp
class B : public virtual A {};
class C : public virtual A {};
```

虚继承的作用：

```text
保证最顶层的 A 在最终派生类 D 中只保留一份。
```

虚基类初始化：

```cpp
class D : public B, public C
{
public:
    D(int x) : A(x)
    {
        cout << "D(int)" << endl;
    }
};
```

重点：

```text
虚基类 A 由最底层的最终派生类 D 负责初始化。
B 和 C 不再各自初始化一份 A。
```

代价：

```text
虚继承会让对象内部多出一些隐藏指针，用来找到共享的虚基类。
因此对象大小可能变大，结构也更复杂。
```

---

## 11、Day10 总结

```text
1. 继承是在已有类基础上创建新类。
2. 基类也叫父类，派生类也叫子类。
3. public 继承表示 is-a 关系。
4. private 继承表示用基类实现自己。
5. 基类 private 成员不会因为继承而变成派生类可直接访问。
6. public 继承保留 public/protected 权限。
7. private 继承会把基类 public/protected 成员变成派生类 private 成员。
8. 构造顺序是基类、成员对象、派生类。
9. 析构顺序是派生类、成员对象、基类。
10. 派生类同名成员会隐藏基类同名成员。
11. 访问被隐藏的基类成员要用 Base::成员名。
12. 基类对象接收派生类对象会发生对象切片。
13. 当前没有虚函数时，Base* 调用的是 Base 的成员函数。
14. 多重继承可能产生同名成员二义性。
15. 菱形继承会让最顶层基类出现多份拷贝。
16. 虚继承可以让菱形继承中的顶层基类只保留一份。
```

一句话记忆：

```text
Day10 重点：public 继承表示“是一个”，private 继承表示“用来实现”；构造从基类到派生类，析构反过来；菱形继承用 virtual 解决重复基类。
```

---

# Day 11：多态、虚函数和动态类型转换

本节代码位置：

```text
2-代码/day11-多态/62-多态示例.cpp
2-代码/day11-多态/63-多态示例2.cpp
2-代码/day11-多态/64-final示例.cpp
2-代码/day11-多态/65-虚函数的默认值示例.cpp
2-代码/day11-多态/66-虚析构函数示例.cpp
2-代码/day11-多态/67-虚函数调用过程验证.cpp
2-代码/day11-多态/68-动态类型转换示例.cpp
2-代码/day11-多态/多态练习.cpp
```

## 1、多态的概念

多态指的是：

```text
不同对象收到相同消息，产生不同的行为。
```

简单理解：

```text
同一个函数调用，根据对象真实类型不同，执行不同版本的函数。
```

例如：

```text
Shape* p 指向 Rect，对 p->area() 求矩形面积。
Shape* p 指向 Circle，对 p->area() 求圆形面积。
```

C++ 中多态主要分两类：

```text
编译时多态：编译阶段就能确定调用哪个函数。
运行时多态：运行阶段根据对象真实类型决定调用哪个函数。
```

编译时多态：

```text
函数重载
运算符重载
```

运行时多态：

```text
通过虚函数实现。
```

---

## 2、虚函数

用 `virtual` 修饰的成员函数叫虚函数。

基本写法：

```cpp
class Base
{
public:
    virtual void print() const
    {
        cout << "hello" << endl;
    }
};
```

派生类中重新定义基类虚函数，叫函数重写，也叫函数覆盖。

```cpp
class Derived : public Base
{
public:
    void print() const
    {
        cout << "world" << endl;
    }
};
```

重写要求：

```text
函数名相同。
参数列表相同。
返回类型相同或满足协变返回。
const 属性也要一致。
```

重点：

```text
基类函数是 virtual，派生类重写时即使不写 virtual，也自动是虚函数。
但实际写代码时建议配合 override，让编译器帮忙检查。
```

---

## 3、动态绑定

`62-多态示例.cpp` 中：

```cpp
void foo(Base *p)
{
    p->print();
}
```

调用：

```cpp
foo(new Base);    // 输出 hello
foo(new Derived); // 输出 world
```

原因：

```text
print() 是虚函数。
p 是基类指针。
当 p 指向 Base 对象时，调用 Base::print()。
当 p 指向 Derived 对象时，调用 Derived::print()。
```

运行时多态的条件：

```text
1. 必须有继承关系。
2. 基类中有虚函数。
3. 派生类重写基类虚函数。
4. 通过基类指针或基类引用调用虚函数。
```

注意：

```text
如果不是通过基类指针或引用调用，通常不会体现运行时多态。
如果基类函数没有 virtual，通过 Base* 调用时会调用 Base 的函数。
```

---

## 4、纯虚函数和抽象类

如果基类只想规定接口，不想提供具体实现，可以写纯虚函数。

格式：

```cpp
class Shape
{
public:
    virtual double area() const = 0;
};
```

纯虚函数：

```text
函数声明后面写 = 0。
表示这个函数没有普通实现，要求派生类自己实现。
```

抽象类：

```text
包含纯虚函数的类叫抽象类。
抽象类不能直接创建对象。
```

错误示例：

```cpp
Shape s; // 错误，Shape 是抽象类
```

派生类如果没有实现所有纯虚函数：

```text
派生类仍然是抽象类，也不能创建对象。
```

---

## 5、形状多态练习

练习要求：

```text
编写形状基类 Shape。
派生 Rect 和 Circle。
用多态方式计算各种形状对象的面积和周长。
```

基类：

```cpp
class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() {}
};
```

这里：

```text
area() 是纯虚函数，求面积。
perimeter() 是纯虚函数，求周长。
~Shape() 是虚析构函数，方便通过基类指针正确释放派生类对象。
```

矩形：

```cpp
class Rect : public Shape
{
public:
    Rect(double w, double h) : m_w(w), m_h(h) {}

    double area() const override
    {
        return m_w * m_h;
    }

    double perimeter() const override
    {
        return 2 * (m_w + m_h);
    }

private:
    double m_w;
    double m_h;
};
```

圆形：

```cpp
class Circle : public Shape
{
public:
    Circle(double r) : m_r(r) {}

    double area() const override
    {
        return 3.14 * m_r * m_r;
    }

    double perimeter() const override
    {
        return 2 * 3.14 * m_r;
    }

private:
    double m_r;
};
```

统一接口：

```cpp
void foo(Shape *p)
{
    cout << "面积: " << p->area() << endl;
    cout << "周长: " << p->perimeter() << endl;
    delete p;
}
```

调用：

```cpp
foo(new Rect(100, 200));
foo(new Circle(100));
```

结果：

```text
Rect 面积：100 * 200 = 20000
Rect 周长：2 * (100 + 200) = 600
Circle 面积：3.14 * 100 * 100 = 31400
Circle 周长：2 * 3.14 * 100 = 628
```

重点：

```text
foo() 的参数是 Shape*，但可以接收 Rect* 和 Circle*。
p->area() 和 p->perimeter() 会根据实际对象类型动态绑定。
```

---

## 6、override 和 final

`override` 用于说明派生类函数重写了基类虚函数。

```cpp
class Rect : public Shape
{
public:
    double area() const override
    {
        return m_w * m_h;
    }
};
```

好处：

```text
如果函数名、参数列表、const 属性写错，编译器会报错。
可以防止本来想重写，结果写成了新的普通函数。
```

`final` 可以修饰虚函数，也可以修饰类。

修饰虚函数：

```cpp
class Base
{
public:
    virtual void bar() final {}
};

class Derived : public Base
{
public:
    // void bar() override {} // 错误，final 函数不能被重写
};
```

修饰类：

```cpp
class Demo final
{
};

// class Test : public Demo {}; // 错误，final 类不能被继承
```

总结：

```text
override：我正在重写基类虚函数，请编译器检查。
final：到此为止，不允许继续重写或继承。
```

---

## 7、虚函数的默认参数

虚函数可以有默认参数，但默认参数是静态绑定的。

示例：

```cpp
class Base
{
public:
    virtual void foo(int x = 0)
    {
        cout << "Base.foo.x = " << x << endl;
    }
};

class Derived : public Base
{
public:
    void foo(int x = 1) override
    {
        cout << "Derived.foo.x = " << x << endl;
    }
};
```

通过基类指针调用：

```cpp
void bar(Base *p)
{
    p->foo();
}

bar(new Derived);
```

结果：

```text
调用的是 Derived::foo()。
但是默认值使用的是 Base 中的 0。
输出 Derived.foo.x = 0。
```

通过派生类对象调用：

```cpp
Derived d;
d.foo();
```

结果：

```text
使用 Derived 中的默认值 1。
输出 Derived.foo.x = 1。
```

重点：

```text
虚函数调用动态绑定。
默认参数静态绑定。
所以通过 Base* 调用时，默认值看 Base。
```

---

## 8、虚析构函数

如果一个类要作为基类，并且可能通过基类指针删除派生类对象，基类析构函数应该写成虚函数。

```cpp
class Base
{
public:
    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }
};
```

派生类：

```cpp
class Derived : public Base
{
public:
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
};
```

使用：

```cpp
Base *p = new Derived;
delete p;
```

如果基类析构函数是虚函数：

```text
先调用 ~Derived()
再调用 ~Base()
```

如果基类析构函数不是虚函数：

```text
通过 Base* delete 派生类对象时，可能只调用 ~Base()。
派生类资源可能无法释放，造成资源泄漏。
```

注意：

```text
构造函数不能是虚函数。
在构造函数和析构函数中调用虚函数，不会发生正常的动态绑定。
```

---

## 9、虚函数表和虚指针

如果一个类中有虚函数，编译器会为这个类生成虚函数表。

```text
虚函数表：vtable，保存虚函数地址。
虚指针：vptr，对象内部隐藏的指针，指向该类的虚函数表。
```

示例：

```cpp
class Base
{
public:
    virtual void foo();
    virtual void bar();
};
```

大致结构：

```text
Base 的虚函数表：
索引 0 -> Base::foo()
索引 1 -> Base::bar()
```

如果派生类重写虚函数：

```cpp
class Derived : public Base
{
public:
    void foo() override;
    void bar() override;
};
```

派生类虚函数表中对应位置会被替换：

```text
Derived 的虚函数表：
索引 0 -> Derived::foo()
索引 1 -> Derived::bar()
```

通过基类指针调用虚函数时：

```text
1. 先根据对象找到隐藏的 vptr。
2. 通过 vptr 找到对象真实类型对应的 vtable。
3. 根据虚函数在表中的索引取出函数地址。
4. 调用对应函数。
```

所以：

```text
Base* p = new Derived;
p->foo();
```

最终能调用 `Derived::foo()`。

代价：

```text
有虚函数的对象通常会多一个隐藏的 vptr。
对象大小会变大一点。
虚函数调用比普通函数调用多一次查表过程。
```

---

## 10、dynamic_cast 动态类型转换

`dynamic_cast` 用于多态类型之间的安全向下转换。

多态类型：

```text
包含虚函数的类型。
```

向上转换：

```cpp
Base *p = new Derived1;
```

派生类指针转基类指针，通常可以自动完成。

向下转换：

```cpp
Derived1 *q = dynamic_cast<Derived1 *>(p);
```

基类指针转派生类指针，需要显式转换。

`dynamic_cast` 的特点：

```text
运行时检查 p 实际指向的对象是不是目标类型。
如果类型匹配，转换成功。
如果类型不匹配，转换失败。
```

指针转换失败：

```cpp
Derived2 *q2 = dynamic_cast<Derived2 *>(p);
if (q2 == nullptr)
{
    cout << "bad cast!" << endl;
}
```

结果：

```text
指针转换失败返回 nullptr。
```

引用转换失败：

```text
引用转换失败会抛出 std::bad_cast 异常。
```

使用建议：

```text
如果必须从 Base* 判断真实派生类型，再调用派生类特有接口，可以用 dynamic_cast。
如果能通过虚函数解决，优先使用虚函数。
```

---

## 11、Day11 总结

```text
1. 多态是同一接口在不同对象上产生不同行为。
2. C++ 运行时多态通过虚函数实现。
3. virtual 修饰的成员函数叫虚函数。
4. 派生类重新定义基类虚函数叫重写。
5. 运行时多态需要通过基类指针或基类引用调用虚函数。
6. 纯虚函数写成 virtual 函数声明 = 0。
7. 含有纯虚函数的类是抽象类，不能直接创建对象。
8. override 用于检查派生类是否真的重写了基类虚函数。
9. final 可以禁止虚函数继续重写，也可以禁止类继续被继承。
10. 虚函数默认参数是静态绑定，通过 Base* 调用时默认值看 Base。
11. 作为多态基类时，析构函数通常要写成 virtual。
12. 构造函数不能是虚函数。
13. 有虚函数的类通常有 vtable，对象内部通常有 vptr。
14. dynamic_cast 用于多态类型之间的安全向下转换。
15. 指针 dynamic_cast 失败返回 nullptr，引用失败抛出 std::bad_cast。
```

一句话记忆：

```text
Day11 重点：virtual 让 Base* 调用时看对象真实类型；抽象类管接口，override 防写错，虚析构防泄漏，dynamic_cast 做安全向下转换。
```

---

# Day 12：自定义异常与函数模板

本节代码：

```text
2-代码/day12-自定义异常/69-自定义异常类型示例.cpp
2-代码/day12-自定义异常/70-函数模板示例.cpp
2-代码/day12-自定义异常/70-函数模板练习.cpp
```

## 1、自定义异常

标准库异常的基类是 `std::exception`。自定义异常通常公开继承它，并重写 `what()` 返回错误说明。

```cpp
class MyException : public std::exception
{
public:
    MyException(const char *errmsg) : errmsg(errmsg) {}

    const char *what() const noexcept override
    {
        return errmsg;
    }

private:
    const char *errmsg;
};
```

抛出和捕获：

```cpp
throw MyException("this is a test!");

try
{
    foo();
}
catch (const std::exception &err)
{
    cout << err.what() << endl;
}
```

要点：

```text
1. throw 用于抛出异常对象。
2. try 包住可能出错的代码，catch 负责处理异常。
3. catch 使用 const std::exception&，既能接住基类异常，也能接住其派生类异常。
4. 用引用捕获可避免对象拷贝，也不会发生异常对象切片。
5. what() 返回 const char*，noexcept 表示该函数不会再抛异常。
6. 异常对象优先按值抛出、按 const 引用捕获。
```

## 2、函数模板

函数模板把“算法逻辑”写一次，把“数据类型”交给编译器在调用时推导。

```cpp
template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
```

```cpp
int x = 1;
int y = 2;
Swap(x, y); // T 被推导为 int

double a = 1.1;
double b = 2.2;
Swap(a, b); // T 被推导为 double
```

多个模板参数：

```cpp
template <typename T1, typename T2>
T1 sum(T1 a, T2 b)
{
    return a + b;
}

cout << sum<double, double>(1, 2.2) << endl;
```

数组长度也能作为模板参数：

```cpp
template <typename T, size_t N>
int findValue(const T (&arr)[N], const T &value)
{
    for (size_t i = 0; i < N; ++i)
    {
        if (arr[i] == value)
            return static_cast<int>(i);
    }
    return -1;
}
```

这里的 `N` 由数组实参自动推导，因此不需要额外传入数组长度。

## 3、Day12 总结

```text
1. 自定义异常可继承 std::exception，并重写 what()。
2. 用 throw 抛异常，用 try/catch 处理异常。
3. 捕获异常优先写 const 基类引用。
4. 函数模板让同一套逻辑支持多种类型。
5. 模板参数可以是类型，也可以是编译期常量，例如数组长度 N。
```

一句话记忆：

```text
Day12 重点：异常负责把错误交给调用方处理；函数模板负责把重复算法写成可复用的通用函数。
```

---

# Day 13：类模板与 vector

本节代码：

```text
2-代码/day13-类模板/71-类模板使用示例.cpp
2-代码/day13-类模板/72-vector使用示例.cpp
2-代码/day13-类模板/list.hpp
2-代码/day13-类模板/stack.hpp
2-代码/day13-类模板/myalgo.hpp
```

## 1、类模板

类模板让一个类可以保存不同类型的数据。例如 `List<int>` 保存整数，`List<string>` 保存字符串。

```cpp
template <typename Type>
class List
{
    // 节点数据、push_back、迭代器等都使用 Type
};
```

使用时由尖括号指定实际类型：

```cpp
List<int> l1;
List<string> l2;
```

`MyStack` 也被写成了类模板，并在内部复用 `List<Type>`：

```cpp
template <typename Type>
class MyStack
{
private:
    List<Type> _list;
    int _capacity;
};
```

别名模板可以给复杂类型起简短名字：

```cpp
template <typename Type>
using LinkStack = MyStack<Type>;
```

## 2、模板实现通常放在头文件

模板不是编译后只生成一份固定代码。编译器看到 `List<int>`、`List<string>` 时，才会按具体类型生成对应代码。

```text
因此模板的声明和实现通常都写在 .hpp 头文件中。
如果把模板实现单独放进 .cpp，其他源文件在实例化模板时通常看不到实现，会导致链接错误。
```

## 3、迭代器与通用算法

`myfind` 不关心容器具体是 `List` 还是 `string`，只要求传入的迭代器支持比较、递增和解引用。

```cpp
template <typename Iterator, typename T>
Iterator myfind(Iterator first, Iterator last, T x)
{
    for (; first != last; ++first)
    {
        if (*first == x)
            return first;
    }
    return last;
}
```

```cpp
auto it = myfind(l1.begin(), l1.end(), 300);
if (it != l1.end())
{
    *it = 999;
}
```

要点：

```text
begin() 指向第一个元素，end() 指向尾后位置。
查找成功返回目标元素迭代器，失败返回 end()。
迭代器解引用得到元素本身，因此可以读取或修改元素。
```

## 4、vector 动态数组

`std::vector` 是标准库的动态数组，元素连续存储，支持下标访问。

```cpp
vector<int> a;                  // 空 vector
vector<int> a2 = {1, 2, 3};    // 列表初始化
vector<int> a3(a2.begin(), a2.end()); // 迭代器区间构造
vector<int> a4(10);            // 10 个默认初始化元素
vector<int> a5{10};            // 只有 1 个元素，值为 10
```

圆括号和大括号要区分：

```text
vector<int> v(10)：创建 10 个元素。
vector<int> v{10}：创建 1 个元素，值为 10。
```

常用操作：

```cpp
a.push_back(1); // 尾部添加
a.pop_back();   // 删除最后一个元素
a[0] = 100;     // 下标修改

auto it = find(a.begin(), a.end(), 6);
auto it2 = find_if(a.begin(), a.end(),
                   [](int x) { return x < 100; });
```

`size()` 与 `capacity()`：

```text
size()：当前实际元素个数。
capacity()：已分配、可容纳的元素数量。
push_back() 发现容量不足时，vector 会重新分配更大的连续空间。
重新分配后，原有的迭代器、指针和引用可能失效。
```

## 5、Day13 总结

```text
1. 类模板让容器和数据结构支持多种元素类型。
2. 使用时写成 类名<实际类型>，例如 List<int>。
3. 模板的实现通常放在头文件。
4. 迭代器把容器和算法连接起来。
5. vector 是连续存储的动态数组，支持随机访问。
6. vector 的 () 与 {} 初始化含义不同。
7. vector 扩容可能使旧迭代器、指针和引用失效。
```

一句话记忆：

```text
Day13 重点：模板让类和算法按类型复用；迭代器让算法不绑定具体容器；vector 是可自动扩容的连续动态数组。
```

---

# Day 14：vector 深入、典型算法与关联容器

本节代码：

```text
2-代码/day14-vector/73-vector使用示例2.cpp
2-代码/day14-vector/74-典型算法示例.cpp
2-代码/day14-vector/75-array使用示例.cpp
2-代码/day14-vector/76-list使用示例.cpp
2-代码/day14-vector/77-priority_queue示例.cpp
2-代码/day14-vector/78-map使用示例.cpp
2-代码/day14-vector/79-set使用示例.cpp
2-代码/day14-vector/80-unordered_map使用示例.cpp
```

## 1、vector 的深入使用

`vector` 保存对象时，既可以先构造临时对象再插入，也可以直接在容器尾部构造对象：

```cpp
vector<Demo> a;
a.push_back(Demo(1, 1)); // 先构造临时对象，再放入 vector
a.emplace_back(2, 2);   // 直接在 vector 尾部构造 Demo(2, 2)
```

`emplace_back` 接收的是构造函数参数；`push_back` 接收的是一个已经存在的元素对象。

### 删除元素

`erase` 删除一个元素后，会返回“被删元素后面那个元素”的迭代器。遍历时删除元素，应接住这个返回值：

```cpp
for (auto it = a.begin(); it != a.end(); )
{
    if (*it % 2 != 0)
        it = a.erase(it);
    else
        ++it;
}
```

不能写成删除后再无条件 `++it`，因为原来的迭代器已经失效，可能跳过元素或产生未定义行为。

### reserve 与 resize

```cpp
vector<int> a;
a.reserve(10);
cout << a.size() << ", " << a.capacity() << endl; // 0, 10

a.resize(10);
cout << a.size() << ", " << a.capacity() << endl; // 10, 至少 10
```

```text
reserve(n)：只预留容量，size 不变，不能用 a[0] 访问还不存在的元素。
resize(n)：改变元素个数，新增加的元素会被默认初始化，可以用下标访问。
```

当预先知道大概元素数量时，`reserve` 可以减少多次扩容和元素搬迁。

## 2、常用 STL 算法

STL 算法通常接收一对迭代器 `[first, last)`，表示从 `first` 开始、到 `last` 之前的范围。

### 查找与遍历

```cpp
auto it = find(v.begin(), v.end(), 100);

auto it2 = find_if(v.begin(), v.end(), [](int x)
{
    return x > 0;
});

for_each(v.begin(), v.end(), [](int &x)
{
    ++x;
});
```

```text
find：查找等于指定值的第一个元素。
find_if：查找第一个满足条件的元素。
for_each：对范围内每个元素调用指定函数对象或 lambda。
lambda 参数写成 int& 时可以修改原容器元素；写成 const int& 时只读。
```

### 统计、比较与反转

```cpp
int count = count(v.begin(), v.end(), 3);
int positive = count_if(v.begin(), v.end(), [](int x)
{
    return x > 0;
});

bool same = equal(s1.cbegin(), s1.cbegin() + s1.size() / 2,
                  s1.crbegin());

reverse(v.begin(), v.end());
```

`equal` 可以比较两个范围；示例中用正向前半段和反向开头比较，判断字符串是否为回文。`reverse` 会直接改变范围中的元素顺序。

### 排序与最大元素

```cpp
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>());

auto maxIt = max_element(v.begin(), v.end());
if (maxIt != v.end())
{
    cout << *maxIt << endl;
}
```

```text
sort 默认升序；传入 greater<int>() 可以降序。
sort 要求随机访问迭代器，因此 vector、array 可以排序，list 不能使用 std::sort。
max_element 返回最大元素的迭代器，不是元素值本身。
```

### remove-erase 惯用法与去重

`remove` 和 `unique` 都不会真正缩短容器，它们只移动元素并返回新的逻辑结尾。要配合 `erase` 才能真正删除尾部无效元素：

```cpp
vector<int> v{1, 3, 2, 3, 4, 3, 5};
auto newEnd = remove(v.begin(), v.end(), 3);
v.erase(newEnd, v.end());

sort(v.begin(), v.end());
newEnd = unique(v.begin(), v.end());
v.erase(newEnd, v.end());
```

```text
remove：移走等于指定值的元素。
unique：移走连续重复元素，所以全局去重前通常先排序。
```

`shuffle(v.begin(), v.end(), engine)` 用随机数引擎打乱元素；`random_device` 可用于初始化 `mt19937` 引擎。

## 3、array 与 list

### array

`std::array<T, N>` 是固定长度的数组容器，大小在编译期确定：

```cpp
array<int, 5> a;
a[0] = 1;
a.fill(100);
```

它支持迭代器和下标访问，但没有插入、删除和自动扩容接口。

### list

`std::list` 是双向链表，适合已知位置的插入、删除和节点转移：

```cpp
list<int> ls;
ls.push_back(100);
ls.push_front(200);
ls.emplace_back(300);
ls.emplace_front(400);
```

`list` 的迭代器不支持 `it + n`，因此不能随机访问，也不能传给 `std::sort`。

```cpp
l1.merge(l2);                   // 合并两个有序链表，合并后 l2 为空
l1.splice(l1.begin(), l2);      // 把 l2 的节点拼接到 l1 指定位置
```

`merge` 的前提是两个链表都已按相同规则排好序；`splice` 主要是转移节点，不是逐个复制元素。

## 4、priority_queue 优先队列

`priority_queue` 默认是大顶堆，`top()` 得到当前最大元素：

```cpp
priority_queue<int> maxQueue;
maxQueue.push(8);
maxQueue.push(3);
cout << maxQueue.top() << endl; // 8
```

使用 `greater<int>` 可以构造小顶堆：

```cpp
priority_queue<int, vector<int>, greater<int>> minQueue;
```

优先队列只能访问队首元素，不能像 `vector` 一样遍历或按下标访问；想按优先级依次取出元素，就循环 `top()` 和 `pop()`。

## 5、map 与 unordered_map

`map<Key, Value>` 保存键值对，键唯一，并按比较规则有序排列：

```cpp
map<string, string> m;
m.insert({"san", "三"});
m["si"] = "四";

auto it = m.find("san");
if (it != m.end())
{
    cout << it->first << ": " << it->second << endl;
}
```

```text
it->first 是键，键不能通过迭代器修改。
it->second 是值，可以修改。
count(key) 对 map 来说通常返回 0 或 1。
operator[] 在键不存在时会插入一个默认值，因此只查找时优先使用 find。
```

`unordered_map` 也是键唯一的键值对容器，但基于哈希表实现：

```text
map：有序，查找、插入、删除通常是 O(log n)。
unordered_map：无序，平均查找、插入、删除通常是 O(1)。
```

遍历 `unordered_map` 时不要依赖元素顺序。

## 6、set 集合

`set<T>` 保存唯一且有序的元素：

```cpp
set<string> s;
s.insert("hello");
s.insert("hello"); // 重复元素不会再次插入
s.insert("cpp");
```

`set` 中的元素就是键，不能通过迭代器修改：

```cpp
auto it = s.begin();
// *it = "abc"; // 错误，修改可能破坏容器排序规则
```

查找、计数和删除的使用方式与 `map` 类似：`find`、`count`、`erase`。

## 7、Day14 总结

```text
1. emplace_back 直接在容器中构造元素；erase 返回下一个有效迭代器。
2. reserve 改容量不改元素个数；resize 会改变元素个数。
3. STL 算法通过迭代器操作范围，常见算法有 find、for_each、sort、remove、unique 等。
4. remove 和 unique 后要配合 erase，才能真正删除元素。
5. array 长度固定；list 是双向链表，不能随机访问。
6. priority_queue 默认大顶堆，使用 greater 可得到小顶堆。
7. map 有序，unordered_map 无序且平均查找更快；二者的键都唯一。
8. set 保存有序且唯一的元素，元素不能直接修改。
```

一句话记忆：

```text
Day14 重点：容器决定数据如何存，迭代器定义操作范围，算法负责处理范围中的数据。
```

---

# Day 15：智能指针与多线程基础

本节代码：

```text
2-代码/day15-智能指针/81-练习.cpp
2-代码/day15-智能指针/82-unique_ptr示例.cpp
2-代码/day15-智能指针/83-shared_ptr示例.cpp
2-代码/day15-智能指针/84-weak_ptr示例.cpp
2-代码/day15-智能指针/85-auto_ptr示例.cpp
2-代码/day15-智能指针/86-线程示例.cpp
2-代码/day15-智能指针/87-mutex使用示例.cpp
2-代码/day15-智能指针/88-条件变量示例.cpp
```

## 1、智能指针的作用

智能指针是管理动态内存的对象，位于 `<memory>`。它们在离开作用域时自动释放资源，避免手动 `new`/`delete` 容易出现的内存泄漏、重复释放和异常路径遗漏释放。

```text
unique_ptr：独占所有权。
shared_ptr：共享所有权，使用引用计数。
weak_ptr：弱引用，不增加 shared_ptr 的引用计数。
```

优先使用 `make_unique`、`make_shared` 创建对象，代码更简洁，异常安全性也更好。

## 2、unique_ptr 独占所有权

`unique_ptr` 同一时刻只能有一个指针拥有对象，因此不能直接拷贝：

```cpp
auto p = std::make_unique<int>(200);
cout << *p << endl;

// auto p2 = p; // 错误，不能拷贝
auto p2 = std::move(p); // 所有权转移给 p2，p 变为空
```

管理数组时，类型需要写成数组形式：

```cpp
auto p = std::make_unique<int[]>(5);
p[1] = 300;
```

`unique_ptr` 适合“一个对象只有一个明确拥有者”的场景，例如类的私有资源、工厂函数返回对象等。

## 3、shared_ptr 共享所有权

`shared_ptr` 通过引用计数管理对象。每复制一个 `shared_ptr`，计数加一；最后一个拥有者销毁或 `reset()` 后，对象才会被释放。

```cpp
auto p1 = std::make_shared<Demo>(400);
cout << p1.use_count() << endl; // 1

auto p2 = p1;
cout << p1.use_count() << endl; // 2
```

常用接口：

```cpp
p.reset(new Demo(200)); // 放弃旧对象，改为管理新对象
Demo *raw = p.get();    // 取得裸指针，但不转移所有权
```

`get()` 返回的裸指针只能临时使用，不能对它单独 `delete`，因为对象仍由 `shared_ptr` 管理。

## 4、weak_ptr 弱引用

`weak_ptr` 用来观察 `shared_ptr` 管理的对象，但不拥有对象，也不会增加引用计数：

```cpp
std::weak_ptr<int> gw;

auto sp = std::make_shared<int>(42);
gw = sp;
```

对象可能已被释放，因此使用前要检查：

```cpp
if (!gw.expired())
{
    auto sp = gw.lock();
    cout << *sp << endl;
}
```

```text
expired()：判断跟踪对象是否已经释放。
lock()：对象仍存在时返回 shared_ptr；对象已释放时返回空 shared_ptr。
```

`weak_ptr` 常用于打破两个 `shared_ptr` 互相持有形成的循环引用。

## 5、auto_ptr 已废弃

`auto_ptr` 复制时会悄悄转移所有权：

```cpp
auto_ptr<int> p1(new int(100));
auto p2 = p1; // 资源转移给 p2，p1 变为空
```

这种“拷贝后原指针失效”的行为容易引发错误，`auto_ptr` 已在 C++11 中弃用，并在 C++17 中移除。现代 C++ 应使用 `unique_ptr` 替代它。

## 6、thread 线程

`std::thread` 用于创建并发执行的线程：

```cpp
void task(int n)
{
    while (n--)
    {
        // 执行任务
    }
}

std::thread t(task, 5);
t.join();
```

```text
join()：等待线程执行结束；线程对象与执行线程汇合。
detach()：让线程在后台独立运行；之后不能再 join。
```

线程函数参数默认会复制。需要传引用时必须使用 `std::ref`：

```cpp
int n = 5;
std::thread t(task3, std::ref(n));
t.join();
```

成员函数作为线程入口时，还要传入对象地址：

```cpp
Demo d;
std::thread t(&Demo::task4, &d, std::ref(n));
```

线程对象销毁前必须 `join()` 或 `detach()`，否则程序会调用 `std::terminate()`。

## 7、mutex 与条件变量

多个线程同时读写共享数据会产生数据竞争。互斥锁保证同一时刻只有一个线程进入临界区：

```cpp
std::mutex m;
int g = 0;

void task()
{
    for (int i = 0; i < 10000; ++i)
    {
        std::lock_guard<std::mutex> lock(m);
        ++g;
    }
}
```

`lock_guard` 使用 RAII：构造时加锁，离开作用域自动解锁，适合简单的临界区。

条件变量用于线程之间等待“某个条件成立”，避免循环空转：

```cpp
std::unique_lock lock(m);
cv.wait(lock, []
{
    return processed;
});
```

生产者修改共享状态后，用 `notify_one()` 或 `notify_all()` 唤醒等待线程：

```cpp
{
    std::lock_guard lock(m);
    ready = true;
}
cv.notify_one();
```

```text
wait(lock, predicate) 会先检查条件；条件不满足时释放锁并等待通知。
被唤醒后会重新获得锁并再次检查条件，因此可以处理虚假唤醒。
```

## 8、Day15 总结

```text
1. 智能指针用 RAII 自动管理动态资源。
2. unique_ptr 独占所有权，只能移动，不能拷贝。
3. shared_ptr 用引用计数共享所有权；get() 不转移所有权。
4. weak_ptr 不增加引用计数，使用时通过 lock() 获取临时 shared_ptr。
5. auto_ptr 已被移除，使用 unique_ptr 替代。
6. thread 用于并发执行，销毁前必须 join 或 detach。
7. std::ref 用于向线程函数传递引用参数。
8. mutex 保护共享数据；lock_guard 自动管理锁。
9. condition_variable 用于等待和通知线程间的状态变化。
```

一句话记忆：

```text
Day15 重点：智能指针管资源生命周期，mutex 管共享数据访问，条件变量负责线程间等待与唤醒。
```
