## 安装

双击打开在线安装器(qt-online-installer-windows-x64-4.10.0.exe)，开始安装。如下图

<img src="pic/1.png" style="zoom:75%;" />

下一步，注册或使用已有账号登录

<img src="pic/2.png" style="zoom:75%;" />



下一步，勾上同意款及个人用户

<img src="pic/3.png" style="zoom:75%;" />



下一步，修改安装路径到D盘(也可以是其他盘)，再勾选<自定义安装>

<img src="pic/4.png" style="zoom:75%;" />



下一步，同意许可协议

<img src="pic/5-1.png" style="zoom:75%;" />

<img src="pic/6.png" style="zoom:75%;" />



<img src="pic/7.png" style="zoom:75%;" />

<img src="pic/8.png" style="zoom:75%;" />

<img src="pic/9.png" style="zoom:75%;" />

<img src="pic/10.png" style="zoom:75%;" />

安装完成后，没有桌面图标，可以从开始菜单中找到 QtCreator, 如下图
![](pic/11.png)



## Qt简介

中文官网：[Qt | 软件开发全周期的各阶段工具](https://www.qt.io/zh-cn/)
下载页面：[Index of /archive/online_installers/4.10](https://download.qt.io/archive/online_installers/4.10/)

Qt 是一个基于C++ 的跨平台的软件开发框架。

现在的Qt支持多种编程语言，如C++, Python, QML

Qt支持多种平台，如Windows, Linux, Android, IOS等

Qt当前最新的版本是Qt6，但是在嵌入式领域，使用最广的还是Qt5。

Qt的应用领域：工业自动化、汽车、航空航天、消费类电子、工业车辆、医疗、嵌入式等



## 项目创建

<img src="pic/12.png" style="zoom:75%;" />
<img src="pic/13.png" style="zoom:75%;" />
<img src="pic/14.png" style="zoom:75%;" />
<img src="pic/15.png" style="zoom:75%;" />
<img src="pic/16.png" style="zoom:75%;" />
<img src="pic/17.png" style="zoom:75%;" />
<img src="pic/18.png" style="zoom:75%;" />
<img src="pic/19.png" style="zoom:75%;" />

### 项目框架说明

项目创建完成后，会自动生成5个文件，并自动跳转到【编辑】模式，如下图

<img src="pic/20.png" style="zoom:75%;" />
<img src="pic/21.png" style="zoom:75%;" />



双击ui文件，自动跳转到【设计】模式，界面设计器整体布局如下：
<img src="pic/22.png" style="zoom:75%;" />



## 常用控件

### 标签

用于显示文本与图片, 常用属性：大小、位置、文本、字体、对齐方式、边框、图像显示等

```cpp
// 设置标签的文本
ui->label_title->setText("这是标题");
// 设置边框形状
ui->label_title->setFrameShape(QFrame::Box);
ui->label_title->setFrameShadow(QFrame::Sunken);
// 设置对齐方式
ui->label_title->setAlignment(Qt::AlignCenter);
// 设置字体
QFont font;
font.setFamily("宋体");
font.setPointSize(20);
font.setBold(true);
ui->label_title->setFont(font);
// 设置几何属性, this表示当前界面
int x = this->width()/2 - ui->label_title->width()/2;
int y = this->height()/2 - ui->label_title->height()/2;
ui->label_title->move(x, y); // 调整位置到界面的中间

// 标签显示静态图片
ui->label_img->setPixmap(QPixmap("../../../pics/32.png"));
ui->label_img->resize(200,200);
ui->label_img->setScaledContents(true); // 自动缩放

// 标签显示动态图片
mv = new QMovie;
mv->setFileName("../../../pics/1.gif");
ui->label_gif->setMovie(mv);
ui->label_gif->resize(200,200);
ui->label_gif->setScaledContents(true);
mv->start();
```



### 按钮

```cpp
// 普通按钮
ui->pushButton_connet->setText("连接");
ui->pushButton_cancle->setText("取消");
ui->pushButton_connet->setFlat(true); // 扁平模式，不显示边框
ui->pushButton_connet->setShortcut(Qt::Key_Return);// 设置快捷键为 主键盘上的Enter键

// 设置控件的大小
ui->checkBox_save_sesstion->resize(90, ui->checkBox_save_sesstion->height());
// 设置复选框的状态
ui->checkBox_save_sesstion->setCheckState(Qt::Checked);
ui->checkBox_game->setChecked(true);
ui->checkBox_study->setChecked(true);
// 设置单选按钮的状态
ui->radioButton_female->setChecked(true);
```



### 文本框

```cpp
// 大小、位置、文本、对齐方式 与 标签的设置方式相同
// 设置单行文本编辑框的显示模式为密码模式
ui->lineEdit->setEchoMode(QLineEdit::Password);
```

### 组合框

```cpp
// 设置combBox的大小
ui->comboBox_protocal->resize(ui->comboBox_protocal->width()+10, ui->comboBox_protocal->height());
// 给combBox添加内容
ui->comboBox_protocal->addItem("SSH");
ui->comboBox_protocal->addItem("SSH2");
ui->comboBox_protocal->addItem("Telnet");
ui->comboBox_protocal->addItem("Serial");
// 设置当前显示的文本
ui->comboBox_protocal->setCurrentText("Serial");
// 获取组合框当前显示的文本，设置到文本框中
ui->textEdit->setText(ui->comboBox_protocal->currentText());
```



## 信号和槽  

信号和槽是Qt的核心特性，**用于Qt对象(QObject类及其派生类对象)之间的通信。**

当我们改变一个控件的状态时，希望其他控件能得到通知。例如，用户点击一个关闭按钮，我们希望界面调用它的close函数。

其他界面框架可能用的是回调机制，但Qt不是，Qt用的是信号和槽，来实现Qt对象之间的通信。

Qt的控件有许多预定义的信号和槽，如果预定义的信号和槽不能满足需求，则可以自定义信号和槽。

信号和槽是类型安全的：信号的签名必须与接收槽函数的签名匹配。（事实上，槽的参数个数可能比它接收到的信号短，因为它可以忽略额外的参数。）。基于字符串的SIGNAL和SLOT语法将在运行时检测类型不匹配。

信号和插槽是松散耦合的：发出信号的类既不知道也不关心哪个槽接收信号。Qt的信号和槽机制确保，如果你将信号连接到槽，槽将在正确的时间被调用。信号和插槽可以接受任意数量的任何类型的参数。它们是完全类型安全的。
从QObject或其子类（例如QWidget）继承的所有类都可以包含信号和插槽。当对象的内部状态发生改变时，它们会发出信号。这就是对象进行通信的全部操作。它不知道也不在乎是否有任何对象在接收它发出的信号。

槽可用于接收信号，但它们也是普通的成员函数。正如对象不知道是否有任何其他对象接收到它的信号一样，槽也不知道它是否有任何信号连接到它。这确保了可以使用Qt创建真正独立的组件。

您可以将任意数量的信号连接到单个槽，也可以将信号连接到任意数量的插槽。甚至可以将一个信号直接连接到另一个信号。（每当发出第一个信号时，这将立即发出第二个信号。）
信号和插槽共同构成了一个强大的组件编程机制。

### 信号

当对象的内部状态发生变化时，对象会发出信号。**信号是公共访问函数**，可以从任何地方发出，但我们建议只从定义信号及其子类的类中发出。
当发出信号时，连接到它的槽函数通常会立即执行，就像正常的函数调用一样。当这种情况发生时，信号和槽机制完全独立于任何GUI事件循环。一旦所有槽函数都返回，就会执行`emit`语句后面的代码。使用排队连接时，情况略有不同；在这种情况下，emit关键字后面的代码将立即继续，稍后将执行槽函数。
如果多个槽函数连接到一个信号，则在发出信号时，这些槽函数将按照连接的顺序一个接一个地执行。
信号由元对象编译器(moc)自动生成，不得在.cpp文件中实现。

### 槽

当连接到槽函数的信号发出时，会调用槽函数。**槽是普通的C++函数**，可以正常调用；它们唯一的特点是信号可以连接到它们。
由于槽是普通的成员函数，因此在直接调用时遵循普通的C++规则。
与回调相比，信号和槽的速度稍慢，因为它们提供了更大的灵活性，尽管在实际应用中差异不大。一般来说，发出连接到某些插槽的信号比使用非虚拟函数调用直接调用接收器慢大约十倍。

### 连接

信号和槽在通信之前必须进行连接，使用`connect`函数即可。

```cpp
connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
参数说明：
    sender		发出信号的对象的地址
    signal		发出的信号，一般需要使用 SIGNAL 进行包装
    receiver	信号接收对象的地址
    method		收到信号后，要执行的槽函数，一般需要使用 SLOT 进行包装
    type		连接类型，一般默认为AutoConnection。如果信号的发出者与接收者在同一线程中，则使用Qt::DirectConnection. 否则,使用 Qt::QueuedConnection. 
```

预定义的信号与槽示例：

```cpp
// 连接界面上的关闭按钮与当前界面, 当关闭按钮被点击时，自动调用界面的close函数
connect(ui->pushButton_close, SIGNAL(clicked(bool)), this, SLOT(close()));

// 连接三个按钮
connect(ui->pushButton_hide, SIGNAL(clicked(bool)), ui->pushButton_close, SLOT(hide()));
connect(ui->pushButton_show, SIGNAL(clicked(bool)), ui->pushButton_close, SLOT(show()));

// 连接slider与spinbox
connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
```

说明：信号与槽在通信前必须连接，且只需要连接一次，多数时候，在构造函数中进行连接。



### 自定义槽函数

1、在头文件中声明

```cpp
class 类名
{
public slots: 公有槽函数
	函数声明
private slots: 私有槽函数
    函数声明
protected slots: 保护的槽函数
	函数声明    	
};
说明：槽函数的返回值被忽略，一般返回类型为void即可
```



2、在源文件中定义

```
与普通的成员函数在类外定义相同
返回类型 类名::槽函数名(参数列表)
{
	函数体
}
```

3、调用

```cpp
1、像普通函数一样的调用
2、在connect中与信号连接
```



练习：

实现一个简单的计算器

提示：从界面上获取的数据都是字符串，要进行计算，必须转成数字，得到数字结果后，如果要显示到界面的控件中，必须转成字符串



### 自定义信号

1.在头文件中声明一个信号

```C++
class 类名
{
signals:
	信号声明;
};

说明：
    信号本身就是公有的函数,不需要加访问修饰符！
    信号可以带参数！
    信号只需要声明，不需要用户定义！
```

2.发送信号

```C++
通过 emit  来发送信号！
注意：
	信号在发送前需要先连接槽函数，否则，信号发出以后没有Qt对象接收它，起不到作用！
```



### 信号与槽的另一种连接方式

右键界面设计器中的某个控件，在弹出的对话框中选择某个信号，点击确定，自动跳转到【编辑】模式，自动生成槽函数声明与定义
用户只需要填写槽函数定义即可，当信号发出时，此槽函数会自动执行。

例：

![image-20251009143758992](pic/image-20251009143758992.png)

![image-20251009143602934](pic/image-20251009143602934.png)





## 消息对话框

1、包含头文件 `<QMessageBox>`

2、使用示例

```cpp
QMessageBox::information(this, "提示", "输入正确，即将跳转到主界面！");
QMessageBox::warning(this, "警告", "用户名或密码不能为空！");
QMessageBox::critical(this, "错误", "用户名或密码错误，请重试！");
```





## 调试输出

1、包含头文件 `<QDebug>`

2、使用示例

```cpp
qDebug() << "用户名或密码不能为空！"; // 自带换行
```



## 添加新的界面类

右键项目名，在弹出的右键菜单中选择 【添加新文件】

![image-20251009144149325](pic/image-20251009144149325.png)

选择【Qt】-【Qt Widgets Designer Form Class】-【选择】

![image-20251009144236620](pic/image-20251009144236620.png)

选择界面模板，提供了三种界面类，主窗体选择 【MainWindow】,对话框选择【Dialog】, 一般不选【Widget】。

![image-20251009144422485](pic/image-20251009144422485.png)

如果是主界面，则类名默认即可，其他的界面，一般要修改类名，如关于对话框可起名为 `AboutDialog`

![image-20251009144553549](pic/image-20251009144553549.png)

最后，点击完成即可。

![image-20251009144617598](pic/image-20251009144617598.png)

界面类添加完成后，在需要使用该类型实例化对象时，和一般的类的使用差不多：包含头文件，实例化对象，调用各种成员函数。





## 对话框跳转到主界面

QDialog类提供了`accept`方法, 该函数能隐藏对话框，并设置对话框的退出状态码为 QDialog::Accepted

QDialog类提供了exec方法，该函数能显示对话框，阻塞，直到对话框关闭，并获取对话框的退出状态码。

使用这两个函数，可实现界面隐藏与跳转。

### 使用示例

在登录对话框中，当输入正确时，调用它的accept函数。

```cpp
this->accept();
```

在主函数中，调用对话框的exec函数，判断退出状态码，决定是否需要显示新的界面

```cpp
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    LoginDialog w; // 创建登录界面对象，默认情况下，不显示
    MainWindow mw; // 创建主界面对象，默认情况下，不显示


    int code = w.exec(); // 调用登录对话框的exec函数，显示对话框，阻塞直到对话框关闭，并获取其退出状态码
    // 判断登录对话框的退出状态码
    if (code == QDialog::Accepted)
    {
        // 登录成功，显示主界面
        mw.show();
    }


    return a.exec();
}
```





## 添加资源文件

![image-20251009161420097](pic/image-20251009161420097.png)



![image-20251009161448774](pic/image-20251009161448774.png)

![image-20251009161555981](pic/image-20251009161555981.png)

![image-20251009161624405](pic/image-20251009161624405.png)



![image-20251009162723198](pic/image-20251009162723198.png)

![image-20251009162835100](pic/image-20251009162835100.png)

![image-20251009163126957](pic/image-20251009163126957.png)



最后，保存(ctrl+S)。添加成功后，效果如下：

![image-20251009163238593](pic/image-20251009163238593.png)





## 主窗体

主窗体MainWindow一般由四部分组成：menubar, toolbar, centeralwidget, statusbar

### 菜单

![image-20251009172814124](pic/image-20251009172814124.png)

### 工具栏

![image-20251009171536046](pic/image-20251009171536046.png)





### 状态栏

在状态栏上可显示两种信息，临时信息与持久信息。

临时信息使用 showMessage函数即可, 临时信息显示在状态栏的左侧。

```cpp
ui->statusbar->showMessage("点击了菜单项-打开"); // 一直显示，直到下一次调用showMessage函数覆盖此文本
ui->statusbar->showMessage("点击了菜单项-保存", 5000);// 显示5秒，自动清除
```

持久信息需要使用控件显示，如使用标签。持久信息显示在状态栏的右侧。

![image-20251009171234939](pic/image-20251009171234939.png)

效果如下：
![image-20251009173004035](pic/image-20251009173004035.png)



## 目录与文件

### 目录操作

1.  包含头文件

    ```cpp
    #include <QDir>
    #include <QFileDialog>
    ```

2.  目录基础操作示例

    ```cpp
    // 使用QFileDialog选择一个目录的路径
    QString path = QFileDialog::getExistingDirectory(this, "打开文件夹", "/");
    if (path.isEmpty())
        return;
    
    // 构造目录对象
    QDir dir(path);
    // 获取目录下所有的文件名
    QStringList list = dir.entryList();
    // 把文件名列表显示到界面的列表控件中
    ui->listWidget->clear();
    ui->listWidget->addItems(list);
    ```

    

### 文件操作

1.  包含头文件

    ```
    #include <QFile>
    #include <QFileDialog>
    #include <QDebug>
    ```

2.  文件读操作示例

    ```cpp
    // 通过文件对话框，选择要操作的文件名
    QString pathfile = QFileDialog::getOpenFileName(this);
    if (pathfile.isEmpty())
    	return;
    
    // 构造文件对象
    QFile file(pathfile);
    // 打开文件，以只读的方式打开文本文件
    bool ok = file.open(QFile::ReadOnly | QFile::Text);
    if (!ok)
    {
        qDebug() << "open read file error: " << file.errorString();
        return ;
    }
    // 读文件
    while (!file.atEnd())
    {
        // 一次读一行
        QByteArray line = file.readLine();
    	// 把读到的一行数据插入到界面的textBrowser中
        ui->textBrowser->insertPlainText(line);
    }
    
    // 关闭文件
    file.close();
    ```

    

3.  文件写操作示例

    ```cpp
    // 通过文件对话框获取一个用于写操作的文件名
    QString pathfile = QFileDialog::getSaveFileName(this);
    if (pathfile.isEmpty())
        return;
    
    // 构造文件对象
    QFile file(pathfile);
    // 以只写的方式打开文件
    bool ok = file.open(QFile::WriteOnly);
    if (!ok)
    {
        qDebug() << "open save file error:" << file.errorString();
        return;
    }
    // 把界面上textBrowser中的内容转成纯文本
    QString text = ui->textBrowser->toPlainText();
    // 把QString类型的字符串先转成QByteArray, 再写入文件
    file.write(text.toUtf8());
    
    // 关闭文件
    file.close();
    ```

    

## 定时器

1.  包含头文件

    ```
    #include <QTimer>
    ```

2.  初始化定时器对象

    ```cpp
    // 初始化定时器对象
    timer = new QTimer(this);
    // 设置超时时间
    timer->setInterval(1000); // 1s
    // 连接超时信号与自定义的槽函数
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    ```

    说明：`timer`对象通常是一个成员指针，在头文件中声明，初始化过程一般写在构造函数中

3.  槽函数获取显示系统时间示例

    ```cpp
    // 定时器超时后自动执行的槽函数
    void MainWindow::onTimeout()
    {
        // 获取系统的当前日期时间
        QDateTime dt = QDateTime::currentDateTime();
        // 显示到界面上的标签中
        ui->label->setText(dt.toString("yyyy/MM/dd hh:mm:ss dddd"));
    }
    ```

    







## 数据库操作(SQLite3)

1.  添加数据库模块

    在项目的pro文件中添加以下代码

    ```
    QT += sql
    ```
    
2. 包含相关头文件
   
   ```cpp
   #include <QSqlDatabase>
   #include <QSqlQuery>
   #include <QSqlError>
   ```
   
   

3.  连接数据库

    ```cpp
    // 数据库连接初始化
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");
    bool ok = db.open();
    if (!ok)
    {
        qDebug() << "open db error: " << db.lastError().text();
        return;
    }
    ```

    说明：`db`对象一般做为成员变量，在头文件中声明

4.  执行SQL语句

    ```cpp
    // 创建关系表
    QString sql = "create table if not exists t_user(name TEXT primary key, age INTEGER); ";
    QSqlQuery query;
    bool ok = query.exec(sql);
    if (!ok)
    {
        qDebug() << "create table error: " << query.lastError().text();
        return;
    }
    ```

    














## OpenCV

OpenCV（Open Source Computer Vision Library）是基于Apache2.0协议开源的跨平台计算机视觉库，2000年6月首次发布，支持[Linux](https://baike.baidu.com/item/Linux/27050?fromModule=lemma_inlink)、Windows、[Android](https://baike.baidu.com/item/Android/60243?fromModule=lemma_inlink)及[Mac OS](https://baike.baidu.com/item/Mac OS/2840867?fromModule=lemma_inlink)等操作系统，提供C 、[Python](https://baike.baidu.com/item/Python/407313?fromModule=lemma_inlink)、[Java](https://baike.baidu.com/item/Java/85979?fromModule=lemma_inlink)等多语言接口。其核心代码采用C++编写并针对实时视觉应用优化，可利用[MMX](https://baike.baidu.com/item/MMX/1152883?fromModule=lemma_inlink)和[SSE](https://baike.baidu.com/item/SSE/1190064?fromModule=lemma_inlink)指令提升性能，2022年12月发布的4.7.0版本新增对ONNX层的支持并优化[DNN](https://baike.baidu.com/item/DNN/19974079?fromModule=lemma_inlink)卷积性能，同时适配国产龙芯LoongArch架构 。该库起源于1999年CVL项目，历经多次版本迭代，2017年起强化深度学习模块支持 。OpenCV涵盖[图像处理](https://baike.baidu.com/item/图像处理/294902?fromModule=lemma_inlink)、[运动跟踪](https://baike.baidu.com/item/运动跟踪/7762888?fromModule=lemma_inlink)、人脸检测等功能模块，提供基础数据结构、图像滤波、视频分析、目标检测等核心功能，通过标准化API集成[机器学习算法](https://baike.baidu.com/item/机器学习算法/18635836?fromModule=lemma_inlink)与深度学习框架模型。作为计算机视觉领域通用算法库，其应用场景覆盖[人机交互](https://baike.baidu.com/item/人机交互/61313?fromModule=lemma_inlink)、[智能安防](https://baike.baidu.com/item/智能安防/3150607?fromModule=lemma_inlink)、医学影像分析及工业自动化检测，支持从图像加载、特征提取到视频捕捉的完整开发流程 。

### 文档
```
在线文档: https://docs.opencv.org/
离线文档: 共享文件夹/3-资料/4.5.5.zip
```

### 下载

```
从飞秋下载压缩包opencv4.5.5-MinGw7.3.0.zip。解压到磁盘的根目录即可。
```
如解压到E盘的根目录后，如下图
<img src="pic/image-20251118114225425.png" alt="image-20251118114225425" style="zoom:80%;" />





###  QtCreator中配置opencv4.5.5

创建一个新的Qt项目，在Qt项目的pro文件中添加以下代码

```
# 指定opencv头文件所在路径
INCLUDEPATH += E:/opencv4.5.5-MinGw7.3.0/include
# 指定opencv库文件路径及库名称
LIBS += -LE:/opencv4.5.5-MinGw7.3.0/x64/mingw/bin  -lopencv_world455
```

配置完成后，记得保存。

### 测试

修改Qt项目的main.cpp，进行测试。

```cpp
#include "mainwindow.h"
#include <QApplication>
// 包含opencv的常用头文件
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

	// 在主函数中添加以下代码
    cv::Mat img = cv::imread("../../../pics/lena.jpg");
    std::cout << img << std::endl;

    return a.exec();
}
```

如果配置正确，则项目构建与运行都正常的情况下，会打印图片的像素数据。

说明：opencv不支持中文字符。











### opencv简单示例

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    
    cv::Mat img = cv::imread("E:/lena.png");
    if (img.empty())
    {
        cout << "imread error" << endl;
        exit(1);
    }

    cout << img.channels() << endl ; // 通道数 
    cout << img.rows << endl; // 行数 
    cout << img.cols << endl; // 列数 


    cv::namedWindow("dialog", cv::WINDOW_NORMAL);
    cv::imshow("dialog", img);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}
```



### 图像加载

```cpp
Mat cv::imread	(const String &	filename, int	flags = IMREAD_COLOR_BGR )
功能:	从磁盘加载图像到内存
参数:	
	filename 带路径的文件名，不支持中文
	flags 打开标志，默认为IMREAD_COLOR_BGR，自动把加载的图像转成3通道的彩色图像，也可以使用其他的，如IMREAD_GRAYSCALE，自动把加载的图像转成单通道的灰度图。
返回:
	成功返回Mat类型的对象，代表要操作的图像，本质上是一个多维数组。
	失败返回一个空的Mat对象。
说明:
	加载图像后，一般需要判断是否加载成功
示例:		
cv::Mat img = cv::imread("E:/lena.png");
if (img.empty())
{
    cout << "imread error" << endl;
    exit(1);
}    		
```

### 图像属性

加载图像成功后，可以查看它的各种属性，如通道数、行数、列数等

```cpp
img.channels() ; // 通道数
img.rows ; // 行数 
img.cols ; // 列数 
img.type(); // 矩阵中元素的类型，返回的是一个整数，通过cv::typeToString()函数，可以字符串形式输出
```

注：opencv中数据类型可参考文档中的 `Data types`
```
file:///E:/%E7%8F%AD%E7%BA%A7/CS2525F-C++/3-%E8%B5%84%E6%96%99/4.5.5/d1/d1b/group__core__hal__interface.html
```
### 显示图像

使用opencv内置的gui显示图像

```cpp
void cv::namedWindow	(const String &	winname, int	flags = WINDOW_AUTOSIZE )
功能: 创建一个命名窗体
参数: 
	winname 窗体名称    
	flags 窗体标志，默认为WINDOW_AUTOSIZE，用户无法调整窗体大小，如果需要调整窗体大小，使用WINDOW_NORMAL即可        
void cv::imshow	(const String &	winname, InputArray	mat )        
功能: 使用opencv内置的窗体显示图像
参数: 
	winname 窗体名称，如果与之前的namedWindow的第一个参数相同，则使用已创建的命名窗体，否则自动创建一个新的窗体         mat 待显示的图片对象，Mat类型的对象
        
示例:
cv::namedWindow("dialog", cv::WINDOW_NORMAL);
cv::imshow("dialog", img);
```



使用Qt显示Mat类型的图像

```cpp
// 把Mat对象转成QImage，参数说明：data(图像像素在内存中的起始地址)，cols(宽)，rows(高)，step[0](一行的字节数), Format_BGR888(像素格式，即排列顺序)
QImage qimg(img.data, img.cols, img.rows, img.step[0], QImage::Format_BGR888);

QLabel label;
// 再把QImage转成QPixmap，使用QPixmap的静态函数fromImage
label.setPixmap(QPixmap::fromImage(qimg));
label.show();
```

### 等待按键

```cpp
int cv::waitKey	(	int	delay = 0	)	
功能: 阻塞程序，等待任意按键    
参数: delay 默认为0，表示一直阻塞，直到按键为止 ，单为ms
返回: int类型的键值，如果不需要，可忽略    

```



### 销毁窗体

```cpp
cv::destroyAllWindows();
```



### 颜色空间转换

```cpp

void cv::cvtColor(InputArray src, OutputArray dst, int code)
功能: 把一个Mat类型图像的颜色空间 转成 其他的颜色空间
参数: 
	src 待转换的图像    
	dst 转换后的结果，需要用户提供一个Mat对象，结果自动保存到用户提供的Mat对象中
	code 转换方式 常用如下：
        COLOR_BGR2GRAY
        COLOR_RGB2GRAY 
        COLOR_BGR2RGB
        COLOR_RGB2BGR
        ...

示例:        
// 把彩色图像转成灰度图像，结果保存到新对象中
cv::Mat grayimg;
cv::cvtColor(img, grayimg, cv::COLOR_BGR2GRAY);
cv::imshow("gray", grayimg);

// 把BGR转成RGB，结果覆盖原图
cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
cv::imshow("rgb", img);   

```



### 调整大小

```cpp
void cv::resize	(InputArray	src, OutputArray dst, Size	dsize)
参数:
	src 待转换的图像    
	dst 转换后的结果，需要用户提供一个Mat对象，结果自动保存到用户提供的Mat对象中
    dsize 大小对象，需要构造一个对象，来表示宽和高
```

练习：找一张大图片，把颜色空间转成灰度图，再调整大小，使其宽不超过640，高不超过480



### 图形与文本绘制 

```cpp
void cv::rectangle	(InputOutputArray img, Rect	rec, const Scalar &	color,int thickness = 1,
int	lineType = LINE_8)
功能: 在指定的图像上绘制矩形
参数: 
	img 待操作的图像
	rec 矩形对象，由x,y,w,h组成
	color  颜色对象，由b,g,r组成
	thickness 线条的粗细程度，一般默认即可
	lineType 线程类型，一般默认为实线LINE_8，可选其他如 LINE_4 LINE_AA
        

void cv::circle	(InputOutputArray img,Point	center,int	radius,const Scalar &color,int thickness = 1,int lineType = LINE_8)
功能: 在指定的图像上画一个圆 
参数:    
	img 待操作的图像
	center 点对象，由x,y组成，表示圆心坐标
	color  颜色对象，由b,g,r组成
	thickness 线条的数细程度，一般默认即可
	lineType 线程类型，一般默认为实线LINE_8，可选其他如 LINE_4 LINE_AA     
    

void cv::putText(InputOutputArray img,const String & text,Point	org,int	fontFace,
double	fontScale,Scalar color,int thickness = 1,int lineType = LINE_8,bool bottomLeftOrigin = false )
功能: 在指定的图像上绘制文本    
参数:
	img 待操作的图像
	text 待绘制的文本字符串，不支持中文
	org 绘制位置，文本左下角的坐标
	fontFace 字体，枚举类型，如 FONT_HERSHEY_SIMPLEX
	fontScale 缩放因子，浮点数     
	color  颜色对象，由b,g,r组成
	thickness 线条的数细程度，一般默认即可
	lineType 线程类型，一般默认为实线LINE_8，可选其他如 LINE_4 LINE_AA  
    bottomLeftOrigin 默认为false, 表示默认文本的起始位置为左下角。
        
    
```



### ROI(感兴趣的区域)

```cpp
//从给定的图像中，选择一个矩形区域，构造一个新的图片对象
cv::Mat roi(img, cv::Rect(10,10, 100,100));
cv::imshow("roi", roi);
```



### 保存图像

```cpp
bool cv::imwrite(const String &	filename, InputArray img)
功能: 把图片对象 按格式保存到磁盘
参数: 
	filename 带路径的文件名，根据文件的扩展名进行格式判断
    img 待保存的图像
返回:
	成功返回true,失败返回false

```



练习：结合Qt与opencv完成，要求实现以下功能：点击界面上的按钮，选择一张图片打开，并在图片中绘制一个圆，再保存为其他格式的图片。










### 摄像头图像采集

```cpp
// 实例化视频采集对象
cv::VideoCapture cap;
// 打开默认的摄像头，只有一个摄像头时，索引默认为0，如果有多个摄像头，则索引依次增加
cap.open(0);
// 判断摄像头是否打开成功
if (!cap.isOpened())
{
	std::cout << "open camera error" << std::endl;
    return 1;
}
// 设置图像帧的宽与高
cap.set(cv::CAP_PROP_FRAME_WIDTH, 320);
cap.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
// 实例化一个空的图片对象，用来保存采集到的视频帧
cv::Mat frame;
// 视频采集循环
while (1)
{
    // 从摄像头中读取一帧数据
    cap.read(frame);
    // 判断是否读取成功
    if (frame.empty())
    {
        break;
    }
    // 显示图像
    cv::imshow("video", frame);
    // 按键退出
    if (cv::waitKey(30) >= 0)
        break;
}
```



### 人脸检测

OpenCV自4.5.4版本起，在objdetect模块中提供了基于DNN(深度神经网络)的人脸检测器`FaceDetectorYN`，它集成在OpenCV中，无需额外安装第三方库即可使用，并随库提供了官方的YuNet模型(model download link: https://github.com/opencv/opencv_zoo/tree/master/models/face_detection_yunet)。

YuNet模型来自OpenCV China团队，该模型接口简洁，创建一次检测器，调用`detect()`即可输出每张人脸的15维向量(左上角坐标、宽、高、左右眼睛坐标、鼻尖坐标、左右嘴角坐标、置信度)。

使用示例

```cpp
// 加载带有人脸的图像
cv::Mat img = cv::imread("E:/3.jpeg");
if (img.empty())
{
    qDebug() << "img read error";
    return 1;
}

// 准备人脸检测模型
std::string fd_model = "E:/opencv4.5.5-MinGw7.3.0/face_detection_yunet_2022mar.onnx";
// 创建人脸检测对象
cv::Ptr<cv::FaceDetectorYN> faceDetector = cv::FaceDetectorYN::create(fd_model, "", cv::Size(img.cols, img.rows));
// 创建一个Mat对象，用于保存检测到的结果
cv::Mat faces_pos;
// 调用detect函数进行检测，检测结果自动保存到第二个参数中
faceDetector->detect(img, faces_pos); 
// 输出测试，检测到的人脸数据是一组32位的浮点数(15个)，分别表示人脸位置的矩形框、两个眼睛的坐标、鼻子的坐标、嘴角的坐标
std::cout << "faces_pos = " << faces_pos << std::endl; // [206.20856, 194.14378, 160.28357, 209.77396, 277.95172, 279.16061, 339.71997, 286.16574, 320.38632, 329.69275, 273.40726, 355.2948, 318.22571, 361.798, 0.91915637]
// 通过rows属性，可知检测到的人脸个数
qDebug() << "face.size = " << faces_pos.rows;
// 绘制检测到的第一个人脸地标
int x = faces_pos.at<float>(0,0);
int y = faces_pos.at<float>(0,1);
int w = faces_pos.at<float>(0,2);
int h = faces_pos.at<float>(0,3);
cv::rectangle(img,cv::Rect(x,y,w,h),cv::Scalar(0,255,255));
cv::imshow("face", img);
```



### 人脸识别

```cpp
// 准备人脸识别模型
std::string fr_model = "E:/20250928-Qt/opencv/face_recognition_sface_2021dec.onnx";
// 创建人脸识别对象
cv::Ptr<cv::FaceRecognizerSF> faceRecognizer = cv::FaceRecognizerSF::create(fr_model, "");
// 对齐规范人脸(从原图中根据人脸地标，提取人脸图像并规范为112*112大小)
cv::Mat face_align1;
faceRecognizer->alignCrop(img, faces_pos.row(1), face_align1); // 示例图像中有3个人脸，规范对齐第2个
cv::Mat face_align2;
faceRecognizer->alignCrop(img, faces_pos.row(2), face_align2); // 示例图像中有3个人脸，规范对齐第3个

// 提取特征值(特征值由128个32位的浮点数组成，共512个字节)
cv::Mat face_feature1;
faceRecognizer->feature(face_align1, face_feature1);			// 提取第2个人脸的特征值
face_feature1 = face_feature1.clone(); // 对特征值做深拷贝

cv::Mat face_feature2;
faceRecognizer->feature(face_align2, face_feature2);			// 提取第3个人脸的特征值
face_feature2 = face_feature2.clone(); // 对特征值做深拷贝


// 特征值匹配(默认使用FR_COSINE算法，该算法的默认阈值为0.363,即当两个特征值之间的距离大于等于0.363时表示同一个人的脸部特征)
double dist = faceRecognizer->match(face_feature1, face_feature2);// 匹配两个特征值
if (dist >= 0.363)
{
    qDebug() << "这两个特征值表示同一个人！";
}
else
{
    qDebug() << "这是两个不同的人" ;
}

```





## 交叉编译

1.  拷贝Qt的ARM库, 放到Ubuntu的共享文件夹中

    ```
    6818：qtlib-arm32-571.tar.xz
    3568：qtlib-aarch64-5152.tar.xz
    ```

    

2.  解压qt的arm库

    进入共享文件夹，找到qt的arm库，执行以下指令，进行解压

    ```shell
    sudo tar xvf qtlib-arm32-571.tar.xz -C /opt
    sudo tar xvf qtlib-aarch64-5152.tar.xz -C /opt
    ```

3.  进入需要交叉编译的qt项目的源码路径，假项目名为`Demo`, 创建构建目录，指令如下

    ```shell
    cd Demo
    mkdir build-arm
    cd build-arm
    ```

4.  使用arm版本的qmake构建项目

    正常情况下会生成Makefile

    ```shell
    /opt/qt库的路径名/bin/qmake  ../
    如:
    /opt/qtlib-aarch64-5152/bin/qmake  ../
    或
    /opt/qtlib-arm32-571/bin/qmake  ../
    ```

5.  编译

    如果一切正常，会生成与项目文件夹同名的 可执行文件。如果出错，则根据提示，进行修改，再重新编译。

    ```shell
    make
    ```

6.  执行

    把生成的可执行文件，传输到开发板的工作目录下，添加可执行权限，即可执行

    6818中直接执行，3568则需要加一个选项`-platform linuxfb`才能正常执行

    ```shell
    chmod +x Demo
    ./Demo 
    ./Demo -platform linuxfb
    ```

    





综合案例

基于人脸识别的考勤管理系统

要实现的功能

1、人员信息的管理，包括添加、修改、删除、查询，在添加人员人信息时，需要保存员工的人脸特征值

2、考勤打卡，通过摄像头实时采集图像，进行人脸检测以及特征值提取，用提取的特征值与之前录入的人脸特征值进行匹配，如果匹配成功，则能获取该员工的基本信息，进行考勤打卡，同时需要保存考勤记录。

3、考勤信息管理，包括考勤信息的修改、删除、查询等

4、系统设置，如上下班打卡时间的设置





## 关系表示例

```sql
-- 人员信息表
CREATE TABLE personnel (
	id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    gender TEXT,
    department TEXT,
    position TEXT,
    phone TEXT,
    face_feature BLOB UNIQUE,
    status TEXT NOT NULL DEFAULT '在职', -- 在职、离职、试用期等
    remarks TEXT
);

-- 考勤记录表
CREATE TABLE attendance_records (
    record_id INTEGER PRIMARY KEY AUTOINCREMENT,
    date DATE NOT NULL,			-- 日期
    personnel_id TEXT NOT NULL, --人员id
    check_in_time TIMESTAMP,	-- 上班打卡时间
    check_out_time TIMESTAMP,	-- 下班打卡时间
    check_in_status TEXT, 		-- 正常、迟到、早退、缺勤等
    check_out_status TEXT,
    FOREIGN KEY (personnel_id) REFERENCES personnel(id),
    UNIQUE (personnel_id, date)
);

```

```cpp
// 下班打卡示例
QString date = "2023-10-17";
QString personnelId = "P001";
QString checkOutTime = "2023-10-17 18:10:00";
QString workEndTime = "18:00:00"; // 下班时间阈值

QSqlQuery query(db);

// 步骤1：插入新记录（若不存在）
query.prepare(R"(
    INSERT OR IGNORE INTO attendance_records (
        date, personnel_id, check_in_time, check_in_status
    ) VALUES (:date, :pid, :in_time, 
              CASE WHEN :in_time <= :end_time THEN '正常' 
                   ELSE '迟到' END)
)");
query.bindValue(":date", date);
query.bindValue(":pid", personnelId);
query.bindValue(":out_time", checkOutTime);
query.bindValue(":end_time", workEndTime);
query.exec();

// 步骤2：更新已有记录
query.prepare(R"(
    UPDATE attendance_records 
    SET check_out_time = :out_time,
        check_out_status = CASE WHEN :out_time >= :end_time THEN '正常' ELSE '早退' END
    WHERE personnel_id = :pid AND date = :date
)");
query.bindValue(":out_time", checkOutTime);
query.bindValue(":end_time", workEndTime);
query.bindValue(":pid", personnelId);
query.bindValue(":date", date);
query.exec();
```












