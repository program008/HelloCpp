#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <csignal>
#include<Windows.h>
using namespace std;
//预处理 宏
#define PI 3.14159

//参数宏
#define MIN(a,b) (a<b ? a : b)
#define DEBUG
//函数模板
//template <class type> ret-type func-name(parameter list)
template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a;
}

//类模板
//template <class type> class class-name
template <class T>
class Stack {
private:
	vector<T> elems;     // 元素 

public:
	void push(T const&);  // 入栈
	void pop();               // 出栈
	T top() const;            // 返回栈顶元素
	bool empty() const {       // 如果为空则返回真。
		return elems.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
	// 追加传入元素的副本
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	// 删除最后一个元素
	elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	// 返回最后一个元素的副本 
	return elems.back();
}

/*
处理信号
*/
void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received.\n";

	// 清理并关闭
	// 终止程序  

	exit(signum);

}
int main()
{

	int i = 1;
	int j = 20;
	cout << "Max(i, j): " << Max(i, j) << endl;

	double f1 = 13.5;
	double f2 = 20.7;
	cout << "Max(f1, f2): " << Max(f1, f2) << endl;

	string s1 = "Hello";
	string s2 = "World";
	cout << "Max(s1, s2): " << Max(s1, s2) << endl;

	// 类模板
	try {
		Stack<int>         intStack;  // int 类型的栈 
		Stack<string> stringStack;    // string 类型的栈 

		// 操作 int 类型的栈 
		intStack.push(7);
		cout << intStack.top() << endl;

		// 操作 string 类型的栈 
		stringStack.push("hello");
		cout << stringStack.top() << std::endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
		//return -1;
	}

	//条件编译
#ifdef DEBUG
	cerr << "Trace: Inside main function" << endl;
#endif

#if 0
	/* 这是注释部分 */
	cout << MKSTR(HELLO C++) << endl;
#endif

	cout << "The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
	cerr << "Trace: Coming out of main function" << endl;
#endif
	//这会在程序编译时包含当前行号。
	cout << "Value of __LINE__ : " << __LINE__ << endl;
	//这会在程序编译时包含当前文件名。
	cout << "Value of __FILE__ : " << __FILE__ << endl;
	//这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。
	cout << "Value of __DATE__ : " << __DATE__ << endl;
	//这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。
	cout << "Value of __TIME__ : " << __TIME__ << endl;

	// 注册信号 SIGINT 和信号处理程序
	signal(SIGINT, signalHandler);
	//int i = 0;
	while (++i) {
		cout << "Going to sleep...." << endl;
		if (i == 3) {
			//生成一个信号
			//raise(SIGINT);
		}
		Sleep(1000);
	}

	return 0;
}