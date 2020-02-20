/*
c++�̳�

���ݷ�װ��һ�ְ����ݺͲ������ݵĺ���������һ��Ļ��ƣ�
���ݳ�����һ�ֽ����û���¶�ӿڶ��Ѿ����ʵ��ϸ�����������Ļ��ơ�
*/
#include<iostream>
using namespace std;
//����
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
	//�麯��
	virtual int area()
	{
		cout << "Parent class area :" << endl;
		return 0;
	}

	//���麯��
	//= 0 ���߱�����������û�����壬������麯���Ǵ��麯����
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

//������ ��̳�
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
	��������
	��Щͬ����������ʽ������ָ�����ĸ��������ͻ���˳�򣩱��벻ͬ��
	���ǣ�����ͨ�������������������غ���
*/
class printData
{
public:
	void print(int i) {
		cout << "����Ϊ: " << i << endl;
	}

	void print(double  f) {
		cout << "������Ϊ: " << f << endl;
	}

	void print(char c[]) {
		cout << "�ַ���Ϊ: " << c << endl;
	}
};
int main()
{
	Rectangle Rect;
	Rect.setWidth(3);
	Rect.setHeight(4);

	//�������
	cout << "Rect's area is :" << Rect.getArea() << endl;
	//���㻨��
	cout << "total cost is :$" << Rect.getCost(Rect.getArea()) << endl;

	//��̬
	Shape* shape;
	Rectangle rec(10, 7);
	Triangle  tri(10, 5);

	// �洢���εĵ�ַ
	shape = &rec;
	// ���þ��ε���������� area
	shape->area();

	// �洢�����εĵ�ַ
	shape = &tri;
	// ���������ε���������� area
	shape->area();
	return 0;
}