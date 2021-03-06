# C++ Primer Plus 第六版 学习笔记

> C++系统学习笔记，Created in 20180516
---

## 7 函数 —— C++编程模块

### 7.1 函数Basics

+ c++对函数返回值类型有一定限制：不能返回数组，其它类型均可；虽然不能返回数组，但能够将数组作为结构或对象的组成部分来返回
+ 函数原型一般隐藏在include文件中，函数原型将函数返回值类型和参数类型、数量告诉编译器，达到捕获错误、提升效率的目的；函数原型的参数列表中，一般只指明参数类型即可，无需写明参数名称

### 7.2 函数参数和按值传递

### 7.3 函数和数组

+ `int sum_arr(int arr[], int n)` 语句中，arr实际上不是数组，而是指针，但在函数中可以将arr当作数组使用
+ c++将数组名解释为其第一个元素的地址：
  ```cpp
  arr == &arr[0];
  ```
  以下几种情况例外：
  + 数组声明使用数组名来标记存储位置
  + 对数组名使用sizeof会得到整个数组的长度
  + 将地址运算符&应用于数组名时，将返回整个数组的地址（加1会增加整个数组长度）
+ 对于函数头`int sum_arr(int arr[], int n)`，以下的函数头也是正确的，`int sum_arr(int * arr, int n)`. c++中，仅当用于函数头或者函数原型中，`int arr[]`和`int * arr`才是等价的
+ 传递常规变量时，函数使用该变量的拷贝；但传递数组时，函数使用原来的数组；这不违背函数按值传递的方法，只是这个值换成了地址
+ 使用const保护数组：
  ```cpp
  void show_array(const double ar[], int n);
  ```
  这意味着不能使用ar修改该数据，即不能再show_array函数中修改数组内容
+ 使用数组区间的函数：通过数组头尾两个指针和指针加法遍历数组内容
+ 指针和const：
  + 两种不同方式将const应用于指针：
    + 让指针指向一个常量对象，方式使用该指针修改所指向的值
    + 将指针本身声明为常量，防止改变指针所指向的位置
  + **const变量的地址可赋给指向const的指针，不能赋给常规指针**
    ```cpp
    const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum(int arr[], int n)
    {...}
    int i = sum(months, 12); //not allowed
    ```
  + const与指针结合的三种方式：
    ```cpp
    int sloth = 3;
    const int * pt = &sloth;//防止通过pt修改其所指向的sloth
    int * const ps = &sloth;//防止改变ps所指向的位置
    const int * const pp =&sloth;//指向const对象的const指针
    ```

### 7.4 函数和二维数组
```cpp
int data[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int sum_data = sum(data, int size);
int sum(int (*arr)[4], int size)
//int sum(int arr[][4], int size)
{...}
```

### 7.5 函数和C-风格字符串
函数处理字符串的标准方式：
```cpp
while(*str)
{
  statements
  str++;
}
```
```cpp
#include"stdafx.h"
#include <iostream>
#include <ctime>
int print_str(const char * str)
{
    using namespace std;
    while (*str)
    {
      cout <<* str << endl;
      str++;
    }
    return 0;
}
int main()
{
    using namespace std;
    char str[] = "Hello";
    print_str(str);
    cout<<str<<endl;
    clock_t start = clock();
    while (clock() - start < 5 * CLOCKS_PER_SEC)
      ;
    return 0;
}
```

### 7.6 函数和结构

+ 结构与普通变量一样，按值传递，函数使用原结构的副本；但如果结构很大，按值传递会增加内存要求，降低系统运行速度，基于这个原因，许多C程序员倾向于传递结构地址，然后使用指针访问结构内容
+ 通过传递结构地址、使用指针访问结构内容的方式，可用const修饰防止结构内容被修改，此外通过指针访问结构内容需要使用间接成员运算符->

### 7.7 函数和string对象

```cpp
int size = 5;
string list[size];
for(int i = 0; i<size; i++)
{
  cout<<i+1<<": "<<endl;
  getline(cin,list[i]);
}
...
```

### 7.8 函数与array对象

+ array默认按值传递，可通过引用的方式让函数操作原始数据
  ```cpp
  std::array<double, 4> expenses;
  show(expenses);
  fill(&expenses);
  ```
对应的函数原型：
  ```cpp
  show(std::array<double, 4> para_1);
  fill(std::array<double, 4> * para_2);
  ```
通过(*para_2)[i]访问、修改expenses元素

### 7.9 *递归*

### 7.10 *函数指针*


## 8 函数探幽

### 8.1 内联函数

+ 常规函数调用使程序跳到另一个地址，并在函数结束时返回；对于内联代码，程序无需跳到另一位置再返回，内联函数运行速度稍快，但占用更多内存；如果程序在10个地方调用10次内联函数，则该程序包含10个该函数的代码；
+ 内联函数在函数定以前加inline:
  ```cpp
  inline double square(double t) {return t*t;}
  ```
+ 内联与宏：C语言使用预处理器语句#define来提供宏，如一个计算平方的宏：
  ```cpp
  #define SQUARE(X) X*X
  ```
但这不是通过传递参数实现的，只是通过文本替换实现的，如：
  ```cpp
  double b =SQUARE(4.5+7.5);//被替换为double b = 4.5+7.5*4.5+7.5;
  ```

### 8.2 引用变量

+ 通过引用变量作为函数参数，函数可对原始数据做操作与修改，同时为函数处理大型结构提供了便捷的途径
```cpp
int rats;
int & rodents = rats;
```
+ 可以通过初始化来设置引用，但不能通过赋值来设置
+ 引用作为函数参数：
  ```cpp
  int m= 1,n=2;
  int swap(int &a, int &b)
  {
    int t =0;
    t=a;
    a=b;
    b=t
    return 0;
  }
  swap(m,n);
  ```
+ 如果只是引用变量信息，而不做修改，可加const修饰

### 8.3 默认参数

+ 必须通过函数原型设置默认值，函数原型设置后，函数定义和没有默认参数完全相同；

### 8.4 函数重载

+ 函数重载及函数多态
+ 特征标、参数数目、参数排列顺序
+ 一般只在函数实现相同功能，但使用不同形式的数据时使用函数重载

### 8.5 函数模版

+ 函数模板是通用的函数描述，使用泛型来定义函数，其中泛型可使用具体类型（double、int等）来替换

## 9 内存模型和名称空间

### 9.1单独编译

+ 常将程序组织策略分为三部分：
  + 头文件：包含结构声明和使用这些结构的函数原型；
  + 源代码文件：包含与结构有关的函数的代码；
  + 源代码文件：包含调用与结构相关的函数的代码。
+ 若文件名包含在尖括号中，编译器将在存储标准头文件的主机系统的文件系统中查找；如果文件名包含在双引号中，编译器首先查找当前的工作目录或源代码目录，若未在此找到文件，再到标准位置查找，因此在使用自己的头文件时，应使用双引号
+ 防止同一文件包含同一头文件多次：
  ```cpp
  #ifndef COORDIN_H_
  #define COORDIN_H_
  ...
  #endif
  ```

### 9.2 存储持续性、作用域和链接性
+ 存储持续性：
  + 自动存储持续性：在函数定义中声明的变量的存储持续性为自动的。它们在程序开始执行其所属函数或代码块时被创建，执行完函数或代码块时被释放；
  + 静态存储持续性：在函数定义外定义的变量和使用关键字static定义的变量的存储持续性为静态，其在程序整个运行过程中都存在；
  + 线程存储持续性：若变量使用关键字thread_local声明，则其生命周期和其所属线程一样长；
  + 动态存储持续性：使用new运算符分配的内存将一直存在，知道delete将其释放，或程序结束；这种内存的存储持续性为动态，或称堆(heap)。
+ 链接性
  + 链接性描述了名称如何在不同单元间共享；
  + 链接性为外部的名称可在文件间共享；
  + 链接性为内部的名称只能由一个文件中的函数共享，自动变量的名称没有链接性。
+ 作用域
  + 作用域为局部的变量只在定义它的代码块中可用；
  + 作用域为全局的变量从定义位置起至文件结束均可用；
  + 自动变量作用域为局部，静态变量作用域取决于其定义方式；
  + 在类中声明的成员的作用域为整个类，在名称空间中声明的变量作用域为整个名称空间；
  + 函数的作用域一般为整个类或整个名称空间。
+ 自动存储持续性
  + 使用栈管理自动变量的增减
  + 栈的特点
  + 使用register声明寄存器变量，在C++11之后此种做法没有意义，只是保留对现有代码的支持
+ 静态持续变量
  + C++为静态存储持续性变量提供了3种链接性：外部链接性（可在其它文件中访问）、内部链接性（只在当前文件中访问）、无链接性（只在当前函数或代码块访问），由于静态变量的数目在程序运行期间不变，因此不必用栈来管理;
  + 创建链接性为外部的静态持续变量，需在代码块外面声明；创建链接性为内部的静态持续变量，需在代码块外部声明，并使用static限定符；创建没有链接性的静态持续变量，应在代码块内部声明，并使用static限定符
+ 静态持续性、外部链接性
  + 单定义规则：变量只能定义一次，为满足此要求，c++提供了两种变量声明：定义声明、引用声明(extern)，引用声明不分配内存空间，而引用已有的变量。
  + `extern int blem`;
  + 在多个文件中使用外部变量，只需在一个文件中定义，其它文件声明引用；
  + 作用域解析运算符::，放在变量前，表示使用变量的全局版本（如在代码块内使用，代码块内已定义一个同名变量，则可通过作用域解析运算符使用全局变量）
  + 全局变量一般用来表示常量数据，并使用const防止数据被修改
  + 如果文件内定义一个静态外部变量，且与另一个文件中的常规外部变量同名，则在该文件中静态外部变量将隐藏常规外部变量；使用常规外部变量在不同文件中共享数据，使用链接性为内部的静态变量在同一文件中共享数据；
+ 静态存储持续性、无链接性
  + 静态无链接性变量虽然只在代码块中可用，但它在代码块不处于活动状态时仍然存在，即在函数两次调用之间值不变；此外，如果初始化了静态无链接变量，则程序只在启动时初始化一次，之后调用函数时不再初始化
+ 存储说明符&限定符
  + **volatile：即便程序代码没对内存单元进行修改，其值也可能发生改变；**
  + mutable，用其来指出，即便结构或类为const，被声明为mutable的成员也可更改；
  + const限定符对存储类型稍有影响：默认情况下，全局变量的链接性为外部，但若声明为const，则其链接性为内部（相当于static效果），假设一个常量放在头文件中，同一程序的多个文件引用此头文件，若无此规则，则违反单定义规则；
  + 若出于某种原因，希望某个变量链接性为外部，则可使用extern来覆盖默认的内部链接性`extern const ...`，需注意在所有使用该变量的文件中使用extern关键字声明。