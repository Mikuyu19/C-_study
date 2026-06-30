# C++学习笔记

# day1

今天开始学习c++

今天的目标是认识c++以及了解c++基本语法

## 1、c++基础

### 1.1、C++起源

历史
    1979年，本贾尼-斯特劳斯特卢普 在C语言的基础上设计了一门新的编程语言，最初称为 C With Classes.
    1984年，正式命名为 c plus plus.
    C++兼容C语言的，现在一般称C和C++为一个系列的语言，用 c/c++ 进行描述。
     
领域
    C++主要应用于 系统软件、嵌入式、图形界面应用、后端(服务端)、游戏开发、科学计算等
    
标准
    1998年，发布了第一个世界标准：C++98/03
    2011年，发布了第二个世界标准：C++11
    再后来，每隔三年，发布一个新的标准：C++14、C++17、C++20、C++23、C++26
    如果在代码中使用了C++11及以上标准中的语言特性，在(交叉)编译时，可能需要加上编译选项 -std=c++11
    
环境
    在Ubuntu中，使用g++, 一般需要自行安装：
        sudo apt install g++

    在ARM-LINUX中，使用arm-linux-g++, 需要自己配置，方式与arm-linux-gcc类似。
        6818：5.4/5.5
        3568: 7.5
    
    在windows中，使用微软的IDE: visual studio 2026

### 1.2、第一个c++程序

```c++
#include <iostream>

int main()
{
    std::cout << "hello cpp world" << std::endl;
    return 0;
}
```

1. 标准C++库中的头文件没有扩展名称
   如果是使用标准C或操作系统的头文件，使用方式与C相同。
   如果是自已编写的头文件，还是要写扩展名，可以是 *.h , 也可以是 *.hpp
   `iostream` 是用于输入输出相关功能的头文件。
2. std 是C++标准库中一个作用域的名字，用于存放C++标准库中的各种名字，这种用来存放名字的作用域，称为 `namespace`(命名空间/名字空间)
3. :: 称为作用域运算符，用于访问指定作用域中的某个名字
4. 标准IO流对象
   `cin`     标准输入流  stdin
   `cout`    标准输出流  stdout
   `cerr`    标准错误流  stderr
5. 输入输出运算符
    `<<`  输出运算符  结合cout或cerr使用
    `>>`  输入运算符  结合cin使用
6. `endl` 指 end line, 相当于 '\n'

### 1.3、using 和 namespace

在 C++ 中，`namespace` 称为**命名空间**，主要作用是把变量、函数、类等名字放到一个指定范围中，避免不同代码之间出现**名字冲突**。

例如：

```c++
namespace A
{
    int value = 10;
}

namespace B
{
    int value = 20;
}
```

虽然两个命名空间中都有 `value`，但它们互不冲突。访问时需要使用 `::` 作用域运算符：

```c++
std::cout << A::value << std::endl;
std::cout << B::value << std::endl;
```

其中：

```c++
A::value
```

表示访问 `A` 命名空间中的 `value`。

`std` 是 C++ 标准库的命名空间，标准输入输出对象都在 `std` 中，例如：

```c++
std::cin
std::cout
std::cerr
std::endl
```

所以第一个 C++ 程序中要写：

```c++
std::cout << "hello cpp world" << std::endl;
```

`using` 的作用是简化命名空间的使用。

如果写：

```c++
using namespace std;
```

之后就可以省略 `std::`，直接写：

```c++
cout << "hello cpp world" << endl;
```

但在大型项目中，不建议随便使用 `using namespace std;`，因为可能引起名字冲突。更推荐在正式代码中使用：

```c++
std::cout
std::cin
std::endl
```

或者只引入需要的名字：

```c++
using std::cout;
using std::endl;
```

#### 总结

> 总结：
>
> `namespace` 用于创建命名空间，防止名字冲突。
>
> `::` 用于访问指定命名空间中的名字。
>
> `using` 用于简化命名空间中的名字使用。
>
> `std` 是 C++ 标准库所在的命名空间。

### 1.4、布尔类型 bool

`bool` 是 C++ 中的布尔类型，用来表示**真**或**假**。

它只有两个取值：

```cpp
true   // 真
false  // 假
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

输出结果：

```text
1
```

在 C++ 中，`true` 输出时默认显示为 `1`，`false` 输出时默认显示为 `0`。

#### 总结

> 总结：
>
> `bool` 表示布尔类型，常用于条件判断、状态标志和函数返回结果。
>
> `true` 表示真。
>
> `false` 表示假。

### 1.5、引用

引用是 C++ 中的一种语法，本质上是**给已有变量起一个别名**。

引用的基本格式：

```cpp
int a = 10;
int& ref = a;
```

其中：

```cpp
int& ref
```

表示 `ref` 是一个 `int` 类型的引用，也就是变量 `a` 的别名。

修改引用，就等于修改原变量：

```cpp
int a = 10;
int& ref = a;

ref = 20;

std::cout << a << std::endl;  // 输出 20
```

#### 1.5.1、引用的特点

1. 引用必须初始化

```cpp
int& ref;  // 错误
```

正确写法：

```cpp
int a = 10;
int& ref = a;
```

1. 引用一旦绑定，不能再改绑

```cpp
int a = 10;
int b = 20;

int& ref = a;
ref = b;
```

这里 `ref = b;` 不是让 `ref` 改成引用 `b`，而是把 `b` 的值赋给 `a`。

#### 1.5.2、引用作为函数参数

引用最常用于函数参数中，可以让函数直接修改外部变量。

```cpp
#include <iostream>

void change(int& x)
{
    x = 100;
}

int main()
{
    int a = 10;

    change(a);

    std::cout << a << std::endl;  // 输出 100

    return 0;
}
```

如果函数只需要读取变量，不希望修改它，可以使用 `const` 引用：

```cpp
void print(const int& x)
{
    std::cout << x << std::endl;
}
```

`const int& x` 表示 `x` 是引用，但不能通过 `x` 修改原变量。

#### 1.5.3、总结

> ```cpp
> int& ref = a;
> ```
>
> 表示 `ref` 是 `a` 的引用，也就是 `a` 的别名。
>
> 引用的核心特点：
>
> ```text
> 1. 必须初始化
> 2. 绑定后不能改绑
> 3. 修改引用就是修改原变量
> 4. 常用于函数参数，避免拷贝或修改外部变量
> ```

### 1.6、函数重载

函数重载是 C++ 中的一种语法，指的是在**同一个作用域**中，可以定义多个**函数名相同**，但**参数列表不同**的函数。

简单理解：

```text
函数名可以相同，但参数必须不同。
```

#### 1.6.1、函数重载的作用

函数重载可以让功能相似的函数使用同一个名字，使代码更加统一、方便。

例如：

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

编译器会根据传入参数的类型和个数，自动选择调用哪个函数。

#### 1.6.2、构成函数重载的条件

函数重载要求：

```text
函数名相同，参数列表不同。
```

参数列表不同包括：

1. 参数个数不同

```cpp
void func(int a);
void func(int a, int b);
```

1. 参数类型不同

```cpp
void func(int a);
void func(double a);
```

1. 参数顺序不同

```cpp
void func(int a, double b);
void func(double a, int b);
```

#### 1.6.3、不能构成函数重载的情况

只靠返回值不同，不能构成函数重载。

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

所以要记住：

```text
函数重载只看参数列表，不看返回值。
```

#### 1.6.4、注意事项

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

编译器可能不知道该调用哪一个，容易产生歧义。

#### 1.6.5、总结

函数重载的核心：

```text
1. 函数名相同
2. 参数列表不同
3. 返回值不同不能构成重载
4. 编译器会根据实参自动匹配对应函数
```

函数重载可以理解为：

```text
同一个函数名，根据不同参数，执行不同版本。
```

## 2、综合练习

### 2.1、compare 函数重载

要求：

```text
如果第一个参数小于第二个参数，返回 -1
如果第一个参数大于第二个参数，返回 1
如果两个参数相等，返回 0
```

代码：

```cpp
#include <iostream>
#include <string>
#include <cmath>

// 比较整数
int compare(int a, int b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

// 比较小数
int compare(double a, double b)
{
    const double EPS = 1e-6;  // 小数比较误差范围

    if (a - b < -EPS)
        return -1;
    if (a - b > EPS)
        return 1;
    return 0;
}

// 比较字符串
int compare(const std::string& a, const std::string& b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}
```

说明：

```text
1. 这里使用了函数重载，三个函数都叫 compare
2. 编译器会根据参数类型自动选择调用哪个函数
3. 小数不能直接用 == 比较，通常要设置误差范围 EPS
4. string 可以直接用 <、>、== 比较，比较规则类似字典顺序
```

------

### 2.2、find 函数重载

要求：

```text
在数组中查找指定值
找到则返回下标
找不到返回 -1
```

代码：

```cpp
// 查找整数数组
int find(const int arr[], int len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

// 查找浮点数数组
int find(const float arr[], int len, float target)
{
    const float EPS = 1e-6f;  // 浮点数误差范围

    for (int i = 0; i < len; i++)
    {
        if (std::fabs(arr[i] - target) < EPS)
            return i;
    }

    return -1;
}

// 查找字符串数组
int find(const std::string arr[], int len, const std::string& target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}
```

说明：

```text
1. 三个函数都叫 find，属于函数重载
2. 数组参数需要额外传入长度 len
3. 字符串参数使用 const string&，避免拷贝，也防止修改
4. 浮点数查找不建议直接用 ==，应该使用误差范围 EPS
```

------

### 2.3、完整测试代码

```cpp
#include <iostream>
#include <string>
#include <cmath>

// 比较整数
int compare(int a, int b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

// 比较小数
int compare(double a, double b)
{
    const double EPS = 1e-6;

    if (a - b < -EPS)
        return -1;
    if (a - b > EPS)
        return 1;
    return 0;
}

// 比较字符串
int compare(const std::string& a, const std::string& b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

// 查找整数数组
int find(const int arr[], int len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

// 查找浮点数数组
int find(const float arr[], int len, float target)
{
    const float EPS = 1e-6f;

    for (int i = 0; i < len; i++)
    {
        if (std::fabs(arr[i] - target) < EPS)
            return i;
    }

    return -1;
}

// 查找字符串数组
int find(const std::string arr[], int len, const std::string& target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

int main()
{
    std::cout << compare(10, 20) << std::endl;
    std::cout << compare(3.14, 3.14) << std::endl;
    std::cout << compare(std::string("abc"), std::string("abd")) << std::endl;

    int nums[] = {10, 20, 30, 40};
    float scores[] = {1.1f, 2.2f, 3.3f};
    std::string names[] = {"Tom", "Jack", "Lucy"};

    std::cout << find(nums, 4, 30) << std::endl;
    std::cout << find(scores, 3, 2.2f) << std::endl;
    std::cout << find(names, 3, "Jack") << std::endl;

    return 0;
}
```

------

## 3、引用和指针的区别

引用和指针都可以间接操作变量，但使用方式不同。

```text
引用：变量的别名
指针：保存变量地址的变量
```

主要区别：

```text
1. 引用必须初始化，指针可以先不初始化
2. 引用绑定后不能改绑，指针可以指向其他变量
3. 引用使用时像普通变量，指针需要通过 * 解引用
4. 引用一般不能为 null，指针可以为 nullptr
```

示例：

```cpp
int a = 10;
int b = 20;

int& ref = a;
ref = b;       // 不是改绑，而是把 b 的值赋给 a

int* p = &a;
p = &b;        // 指针可以改为指向 b
```

------

## 4、不同类型如何与零值比较

### 4.1、int 与 0 比较

```cpp
if (num == 0)
{
}
```

或者判断非零：

```cpp
if (num != 0)
{
}
```

------

### 4.2、float / double 与 0 比较

浮点数不建议直接和 0 比较，应该使用误差范围。

```cpp
#include <cmath>

const double EPS = 1e-6;

if (std::fabs(x) < EPS)
{
    // x 可以认为等于 0
}
```

原因：

```text
浮点数在计算机中可能存在精度误差
```

------

### 4.3、bool 与 0 比较

`bool` 本身就表示真假，不需要和 0 比较。

推荐写法：

```cpp
if (flag)
{
}
```

判断假：

```cpp
if (!flag)
{
}
```

不推荐写：

```cpp
if (flag == true)
{
}
```

------

### 4.4、指针与 0 比较

C++ 中推荐使用 `nullptr`。

```cpp
if (p == nullptr)
{
    // 空指针
}
```

判断指针非空：

```cpp
if (p != nullptr)
{
}
```

也可以简写：

```cpp
if (p)
{
}
```

------

## 5、cout 输出整数的十六进制

使用 `std::hex` 可以让整数按十六进制输出。

```cpp
#include <iostream>

int main()
{
    int num = 255;

    std::cout << std::hex << num << std::endl;

    return 0;
}
```

输出：

```text
ff
```

如果想带 `0x` 前缀，可以使用 `std::showbase`：

```cpp
std::cout << std::showbase << std::hex << num << std::endl;
```

输出：

```text
0xff
```

如果后面还想恢复十进制输出，需要使用：

```cpp
std::cout << std::dec;
```

完整示例：

```cpp
int num = 255;

std::cout << std::hex << num << std::endl;  // 十六进制
std::cout << std::dec << num << std::endl;  // 十进制
```

------

## 6、本节复习重点

```text
1. 函数重载：函数名相同，参数列表不同
2. compare 可以通过重载实现 int、double、string 的比较
3. find 可以通过重载实现不同类型数组的查找
4. 引用是变量别名，指针是保存地址的变量
5. 浮点数比较要考虑精度误差
6. 指针推荐和 nullptr 比较
7. cout 使用 std::hex 输出十六进制，使用 std::dec 恢复十进制
```

# day2

今天学习 C++ 的**默认参数**。

默认参数是 C++ 对 C 语言函数的一个增强，作用是：

> 调用函数时，如果某些参数没有传值，就使用提前设置好的默认值。

------

## 1、默认参数

普通函数：

```cpp
void print(int count)
{
    std::cout << count << std::endl;
}
```

调用时必须传参数：

```cpp
print(10);
```

如果你不传：

```cpp
print();  // 错误
```

因为 `count` 没有值。

------

使用默认参数后：

```cpp
void print(int count = 1)
{
    std::cout << count << std::endl;
}
```

这时可以这样调用：

```cpp
print(10);  // 使用传入的 10
print();    // 没传参数，使用默认值 1
```

完整代码：

```cpp
#include <iostream>

void print(int count = 1)
{
    std::cout << count << std::endl;
}

int main()
{
    print(10);  // 输出 10
    print();    // 输出 1

    return 0;
}
```

------

### 1.2、默认参数的基本格式

格式：

```cpp
返回值类型 函数名(参数类型 参数名 = 默认值)
{
    函数体
}
```

例子：

```cpp
void show(int age = 18)
{
    std::cout << age << std::endl;
}
```

这里：

```cpp
int age = 18
```

表示如果调用 `show()` 时没有传入 `age`，就默认使用 `18`。

------

1.3、多个默认参数

函数可以有多个默认参数。

```cpp
#include <iostream>

void showInfo(std::string name = "unknown", int age = 18)
{
    std::cout << "name = " << name << std::endl;
    std::cout << "age = " << age << std::endl;
}

int main()
{
    showInfo("Tom", 20);  // name = Tom, age = 20
    showInfo("Jack");     // name = Jack, age = 18
    showInfo();           // name = unknown, age = 18

    return 0;
}
```

------

### 1.4、默认参数必须从右往左设置

这是重点。

正确写法：

```cpp
void func(int a, int b = 10, int c = 20)
{
}
```

意思是：

```text
a 必须传
b 可以不传
c 可以不传
```

可以这样调用：

```cpp
func(1, 2, 3);
func(1, 2);
func(1);
```

------

错误写法：

```cpp
void func(int a = 10, int b, int c)
{
}
```

原因是：

```cpp
func(1, 2);
```

编译器不知道 `1` 是给 `a`，还是想省略 `a` 后给 `b`。

所以规则是：

> **如果某个参数有默认值，那么它右边的参数也必须有默认值。**

------

### 1.5、声明和定义分开时，默认值只能写一次

如果函数声明和函数定义分开写，默认参数一般写在**函数声明**里。

正确写法：

```cpp
#include <iostream>

// 函数声明中写默认参数
void print(int count = 1);

// 函数定义中不要再写默认参数
void print(int count)
{
    std::cout << count << std::endl;
}

int main()
{
    print();
    print(10);

    return 0;
}
```

错误写法：

```cpp
void print(int count = 1);

void print(int count = 1)  // 错误，默认参数重复定义
{
    std::cout << count << std::endl;
}
```

记住：

> **默认参数只能指定一次，通常写在函数声明处。**

------

### 1.6、默认参数和函数重载容易冲突

比如：

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

这时会出问题。

因为编译器不知道你要调用：

```cpp
func(int a)
```

还是：

```cpp
func(int a, int b = 10)
```

所以默认参数和函数重载一起使用时，要小心产生歧义。

------

### 1.7、默认参数的作用

默认参数的主要作用：

```text
1. 减少重复代码
2. 简化函数调用
3. 让常用参数不用每次都传
```

例如：

```cpp
#include <iostream>

void connect(std::string ip, int port = 8080)
{
    std::cout << "ip = " << ip << std::endl;
    std::cout << "port = " << port << std::endl;
}

int main()
{
    connect("192.168.1.10", 8888);  // 指定端口
    connect("192.168.1.20");        // 使用默认端口 8080

    return 0;
}
```

------

### 1.8、总结

默认参数就是：

```text
调用函数时，如果没有传某个参数，就使用提前设置好的默认值。
```

核心规则：

```text
1. 默认参数写法：参数名 = 默认值
2. 默认参数必须从右往左连续设置
3. 如果声明和定义分开，默认值只能写在一个地方
4. 默认参数可以简化函数调用
5. 默认参数和函数重载一起使用时，可能产生歧义
```

## 2、内联函数

内联函数是 C++ 中用来**减少函数调用开销**的一种语法。

简单理解：

> 普通函数是“跳过去执行函数”。
> 内联函数是“把函数代码直接展开到调用位置”。

------

### 2.1、普通函数调用

```cpp
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int ret = add(10, 20);
    return 0;
}
```

普通函数调用时，程序大概会经历：

```text
跳转到 add 函数
传递参数
执行函数体
返回结果
回到 main 函数
```

这个过程有一定开销。

------

### 2.2、内联函数写法

在函数前面加 `inline`：

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

编译器可能会把它优化成类似：

```cpp
int ret = 10 + 20;
```

这就是“内联展开”。

------

### 2.3、完整示例

```cpp
#include <iostream>

// inline 表示建议编译器将函数进行内联展开
inline int add(int a, int b)
{
    return a + b;
}

int main()
{
    int ret = add(10, 20);

    std::cout << ret << std::endl;

    return 0;
}
```

输出：

```text
30
```

------

### 2.4、inline 的本质

`inline` 不是强制命令，而是给编译器的一个建议。

也就是说：

```cpp
inline int add(int a, int b)
```

意思不是“这个函数一定会内联”，而是：

```text
建议编译器把这个函数在调用处展开。
```

最终是否真的展开，由编译器决定。

------

### 2.5、内联函数适合什么情况？

适合函数体很短、调用频繁的函数。

例如：

```cpp
inline int max(int a, int b)
{
    return a > b ? a : b;
}
inline bool isPositive(int x)
{
    return x > 0;
}
```

这些函数逻辑很简单，如果调用很多次，使用内联可能减少函数调用开销。

------

### 2.6、不适合写成内联函数的情况

如果函数体很长，不适合内联。

例如：

```cpp
inline void func()
{
    // 大量循环
    // 大量判断
    // 很多复杂逻辑
}
```

原因是：

```text
内联会把函数代码展开到每个调用位置。
如果函数太大，会导致生成的代码体积变大。
```

所以：

```text
短小、简单、频繁调用的函数适合 inline。
复杂、大量代码的函数不适合 inline。
```

------

### 2.7、inline 和宏函数的区别

C 语言中经常用宏来减少函数调用开销：

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
宏函数：只是简单文本替换，不做类型检查，容易出错
内联函数：是真正的函数，有类型检查，更安全
```

例如宏可能出问题：

```cpp
#define SQUARE(x) x * x

int ret = SQUARE(2 + 3);
```

展开后变成：

```cpp
int ret = 2 + 3 * 2 + 3;
```

结果不是 25，而是 11。

应该写成：

```cpp
#define SQUARE(x) ((x) * (x))
```

但宏仍然不如内联函数安全。

C++ 推荐：

```cpp
inline int square(int x)
{
    return x * x;
}
```

------

### 2.8、类中的成员函数默认可能是内联

后面学类的时候会遇到这种写法：

```cpp
class Student
{
public:
    void show()
    {
        std::cout << "hello" << std::endl;
    }
};
```

这种在类里面直接定义的成员函数，默认会被当作内联函数处理。

现在先知道即可，后面学类再详细讲。

------

### 2.9、总结

内联函数核心：

```text
1. inline 用来建议编译器把函数在调用处展开
2. 目的是减少函数调用开销
3. inline 只是建议，不是强制
4. 适合短小、简单、频繁调用的函数
5. 不适合函数体很长、逻辑复杂的函数
6. C++ 中 inline 比宏函数更安全
```

一句话记忆：

> **内联函数就是用函数的写法，达到类似宏展开的效果，但比宏更安全。**

## 3、C++ 关键字 `extern "C"`

`extern "C"` 是 C++ 用来和 C 语言代码进行混合编译时使用的语法。

一句话理解：

> `extern "C"` 的作用是告诉 C++ 编译器：
> **这个函数按照 C 语言的方式生成函数名，不要按照 C++ 的方式改名。**

------

### 3.1、为什么需要 `extern "C"`？

C++ 支持函数重载，例如：

```cpp
void func(int a);
void func(double a);
```

这两个函数名字都叫 `func`，但是参数不同。

为了区分它们，C++ 编译器会在底层对函数名进行处理，这个过程叫：

```text
名字修饰 / 函数名改编 / name mangling
```

例如表面上是：

```cpp
func(int)
func(double)
```

底层可能会变成类似：

```text
_Z4funci
_Z4funcd
```

但是 C 语言不支持函数重载，所以 C 编译器不会改函数名。

C 语言中的：

```c
void func(int a);
```

编译后通常还是类似：

```text
func
```

所以问题来了：

```text
C++ 编译器找的是改名后的函数
C 编译器生成的是原始函数名
两边名字对不上，就会链接失败
```

这时就需要 `extern "C"`。

------

### 3.2、extern "C" 的基本作用

```cpp
extern "C" void func(int a);
```

意思是：

```text
告诉 C++ 编译器：
func 这个函数按照 C 语言规则处理函数名。
```

也就是说，不要把 `func` 改成 C++ 风格的名字。

------

### 3.3、基本示例

假设有一个 C 文件：

```c
// add.c
int add(int a, int b)
{
    return a + b;
}
```

对应头文件：

```c
// add.h
int add(int a, int b);
```

如果 C++ 直接调用：

```cpp
// main.cpp
#include <iostream>
#include "add.h"

int main()
{
    std::cout << add(10, 20) << std::endl;
    return 0;
}
```

可能会出现链接错误。

因为 `add.c` 是 C 编译器编译的，函数名是 C 风格；
`main.cpp` 是 C++ 编译器编译的，默认会按 C++ 风格去找函数名。

正确做法是在头文件中加入：

```c
// add.h
#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b);

#ifdef __cplusplus
}
#endif
```

这样这个头文件既可以给 C 用，也可以给 C++ 用。

------

### 3.4、`__cplusplus` 是什么？

```cpp
#ifdef __cplusplus
```

意思是：

```text
如果当前是 C++ 编译器，就执行下面的代码。
```

因为 C 语言不认识：

```cpp
extern "C"
```

所以不能直接在 C 代码里写它。

因此常用写法是：

```cpp
#ifdef __cplusplus
extern "C" {
#endif

// C 风格函数声明

#ifdef __cplusplus
}
#endif
```

这样：

```text
C++ 编译器能看到 extern "C"
C 编译器会忽略 extern "C"
```

------

### 3.5、单个函数写法

如果只有一个函数，可以这样写：

```cpp
extern "C" int add(int a, int b);
```

------

### 3.6、多个函数写法

如果有多个 C 函数，一般用大括号包起来：

```cpp
extern "C" {
    int add(int a, int b);
    int sub(int a, int b);
    void print_msg(void);
}
```

表示这些函数都按照 C 语言方式链接。

------

### 3.7、extern "C" 常用在哪里？

最常见场景：

```text
1. C++ 调用 C 写的库
2. C++ 调用 C 语言头文件
3. C 和 C++ 混合编程
4. 嵌入式项目中 C 驱动和 C++ 业务代码混合使用
```

例如你以后如果用 C++ 写 STM32 项目，但底层 HAL 库是 C 写的，就可能遇到类似问题。

------

### 3.8、注意事项

#### 1. `extern "C"` 不是把 C++ 代码变成 C 代码

它只是影响函数名的链接方式。

也就是说，它不会让 C++ 语法变成 C 语法。

------

#### 2. `extern "C"` 里面不能函数重载

因为 C 语言不支持函数重载。

错误示例：

```cpp
extern "C" {
    void func(int a);
    void func(double a);  // 错误，C 链接方式下不能重载
}
```

------

#### 3. 通常只写在头文件的函数声明中

常见写法：

```c
#ifndef ADD_H
#define ADD_H

#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b);
int sub(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
```

这是最标准、最常见的写法。

------

### 3.9、总结

```text
extern "C" 的作用：
告诉 C++ 编译器，某些函数按照 C 语言方式处理函数名。
```

核心原因：

```text
C++ 支持函数重载，会对函数名进行修饰。
C 不支持函数重载，函数名通常保持原样。
C 和 C++ 混合编译时，函数名可能对不上。
extern "C" 就是为了解决这个问题。
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

> **extern "C" 是 C++ 调用 C 代码时，用来防止函数名被 C++ 编译器改掉的。**
