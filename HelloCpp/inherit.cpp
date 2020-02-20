/*
c++继承

数据封装是一种把数据和操作数据的函数捆绑在一起的机制，
数据抽象是一种仅向用户暴露接口而把具体的实现细节隐藏起来的机制。
*/
#include<iostream>
using namespace std;
//基类
class Shape
{
public:
	void setWidth(int width)
	{
		this->width = width;
	}
	void setHeight(int height) {
		this->height = height;
	}

	Shape(int a = 0, int b = 0)
	{
		width = a;
		height = b;
	}
	//虚函数
	virtual int area()
	{
		cout << "Parent class area :" << endl;
		return 0;
	}

	//纯虚函数
	//= 0 告诉编译器，函数没有主体，下面的虚函数是纯虚函数。
	//virtual int area() = 0;
protected:
	int width;
	int height;
};

class PrintCost
{
public:
	int getCost(int area)
	{
		return area * 50;
	}

};

//派生类 多继承
class Rectangle :public Shape, public PrintCost
{
public:
	int getArea()
	{
		return width * height;
	}
	Rectangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		cout << "Rectangle class area :" << endl;
		return (width * height);
	}
};

class Triangle : public Shape {
public:
	Triangle(int a = 0, int b = 0) :Shape(a, b) { }
	int area()
	{
		cout << "Triangle class area :" << endl;
		return (width * height / 2);
	}
};
/*
	函数重载
	这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同，
	但是，不能通过函数返回类型来重载函数
*/
class printData
{
public:
	void print(int i) {
		cout << "整数为: " << i << endl;
	}

	void print(double  f) {
		cout << "浮点数为: " << f << endl;
	}

	void print(char c[]) {
		cout << "字符串为: " << c << endl;
	}
};
int main()
{
	Rectangle Rect;
	Rect.setWidth(3);
	Rect.setHeight(4);

	//计算面积
	cout << "Rect's area is :" << Rect.getArea() << endl;
	//计算花费
	cout << "total cost is :$" << Rect.getCost(Rect.getArea()) << endl;

	//动态
	Shape* shape;
	Rectangle rec(10, 7);
	Triangle  tri(10, 5);

	// 存储矩形的地址
	shape = &rec;
	// 调用矩形的求面积函数 area
	shape->area();

	// 存储三角形的地址
	shape = &tri;
	// 调用三角形的求面积函数 area
	shape->area();
	return 0;
}