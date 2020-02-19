// HelloCpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;
/*
 这里是程序执行的入口
*/
#define AGE 10
int test();
int max(int ,int );

int sum(int a, int b = 50) {
    return a + b;
}

int runrand()
{
    int i, j;

    // 设置种子
    //srand((unsigned)time(NULL));

    /* 生成 10 个随机数 */
    for (i = 0; i < 10; i++)
    {
        // 生成实际的随机数
        j = rand();
        cout << "随机数： " << j << endl;
    }

    return 0;
}

// 函数声明
void swap(int& x, int& y);

void printBook(struct Books book);

// 声明一个结构体类型 Books 
struct Books
{
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
};

int main()
{
    //int a = 2;
    //cout << "Hello World! hello c plus plus\n";

    //// 常量定义
    //const int  LENGTH = 10;
    //const int  WIDTH = 5;
    //const char NEWLINE = '\n';
    //int area;
    //area = LENGTH * WIDTH;
    //cout << area;
    //cout << NEWLINE;

    //cout << AGE;
    //test();

    //函数调用
    int num1 = 20, num2 = 30;
    //int maxnumber = max(num1, num2);
    //cout << maxnumber << endl;

    //调用带默认参数
    //int total = sum(num1, num2);
    //cout << total << endl;
    ////
    //int total2 = sum(num1);
    //cout << total2 << endl;

    //cout << sqrt(4) << endl;

    //runrand();

    // 局部变量声明
    int a = 100;
    int b = 200;

    //cout << "交换前，a 的值：" << a << endl;
    //cout << "交换前，b 的值：" << b << endl;

    ///* 调用函数来交换值 */
    //swap(a, b);

    //cout << "交换后，a 的值：" << a << endl;
    //cout << "交换后，b 的值：" << b << endl;

    Books Book1;        // 定义结构体类型 Books 的变量 Book1
    Books Book2;        // 定义结构体类型 Books 的变量 Book2

     // Book1 详述
    strcpy_s(Book1.title, "C++ 教程");
    strcpy_s(Book1.author, "Runoob");
    strcpy_s(Book1.subject, "编程语言");
    Book1.book_id = 12345;

    // Book2 详述


    strcpy_s(Book2.title, "CSS 教程");
    strcpy_s(Book2.author, "Runoob");
    strcpy_s(Book2.subject, "前端技术");
    Book2.book_id = 12346;

    // 输出 Book1 信息
    printBook(Book1);

    // 输出 Book2 信息
    printBook(Book2);

    return 0;
}

/*
 * 这个程序演示了有符号整数和无符号整数之间的差别
*/
int test()
{
    short int i;           // 有符号短整数
    short unsigned int j;  // 无符号短整数

    j = 50000;

    i = j;
    cout << i << " " << j;
    return 0;
}

int max(int num1, int num2) {
    int result;
    if (num1>num2)
    {
        result = num1;
    }
    else
    {
        result = num2;
    }

    return result;
}

// 函数定义
/*
    注：引用可以这样理解，这个swap交换函数交换的是传入的实参，而不是形参，如果没有使用引用，
    那么交换的是形参，实参不会变化。
*/
void swap(int& x, int& y)
{
    int temp;
    temp = x; /* 保存地址 x 的值 */
    x = y;    /* 把 y 赋值给 x */
    y = temp; /* 把 x 赋值给 y  */

    return;
}

void printBook(struct Books book)
{
    cout << "书标题 : " << book.title << endl;
    cout << "书作者 : " << book.author << endl;
    cout << "书类目 : " << book.subject << endl;
    cout << "书 ID : " << book.book_id << endl;
}
