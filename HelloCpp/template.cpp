#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <csignal>
#include<Windows.h>
using namespace std;
//Ԥ���� ��
#define PI 3.14159

//������
#define MIN(a,b) (a<b ? a : b)
#define DEBUG
//����ģ��
//template <class type> ret-type func-name(parameter list)
template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a;
}

//��ģ��
//template <class type> class class-name
template <class T>
class Stack {
private:
	vector<T> elems;     // Ԫ�� 

public:
	void push(T const&);  // ��ջ
	void pop();               // ��ջ
	T top() const;            // ����ջ��Ԫ��
	bool empty() const {       // ���Ϊ���򷵻��档
		return elems.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
	// ׷�Ӵ���Ԫ�صĸ���
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	// ɾ�����һ��Ԫ��
	elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	// �������һ��Ԫ�صĸ��� 
	return elems.back();
}

/*
�����ź�
*/
void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received.\n";

	// �����ر�
	// ��ֹ����  

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

	// ��ģ��
	try {
		Stack<int>         intStack;  // int ���͵�ջ 
		Stack<string> stringStack;    // string ���͵�ջ 

		// ���� int ���͵�ջ 
		intStack.push(7);
		cout << intStack.top() << endl;

		// ���� string ���͵�ջ 
		stringStack.push("hello");
		cout << stringStack.top() << std::endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
		//return -1;
	}

	//��������
#ifdef DEBUG
	cerr << "Trace: Inside main function" << endl;
#endif

#if 0
	/* ����ע�Ͳ��� */
	cout << MKSTR(HELLO C++) << endl;
#endif

	cout << "The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
	cerr << "Trace: Coming out of main function" << endl;
#endif
	//����ڳ������ʱ������ǰ�кš�
	cout << "Value of __LINE__ : " << __LINE__ << endl;
	//����ڳ������ʱ������ǰ�ļ�����
	cout << "Value of __FILE__ : " << __FILE__ << endl;
	//������һ����ʽΪ month/day/year ���ַ���������ʾ��Դ�ļ�ת��ΪĿ���������ڡ�
	cout << "Value of __DATE__ : " << __DATE__ << endl;
	//������һ����ʽΪ hour:minute:second ���ַ���������ʾ���򱻱����ʱ�䡣
	cout << "Value of __TIME__ : " << __TIME__ << endl;

	// ע���ź� SIGINT ���źŴ������
	signal(SIGINT, signalHandler);
	//int i = 0;
	while (++i) {
		cout << "Going to sleep...." << endl;
		if (i == 3) {
			//����һ���ź�
			//raise(SIGINT);
		}
		Sleep(1000);
	}

	return 0;
}