//#pragma once
//#include<iostream>
//using namespace std;
//class Box
//{
//public:
//	double length;//box长
//	double breadth;//box宽
//	double height;//高
//
//	//成语函数声明
//	double getVolume(void);
//	void setLength(double len);
//	void setBreadth(double bre);
//	void setHeight(double hei);
//	void setWidth(double wid);
//	double getWidth(void);
//	//友元函数
//	friend void printWidth(Box box);
//private:
//	double width;
//};
//
//void printWidth(Box box)
//{
//	cout << "box of width:" << box.width << endl;
//}
////成员函数定义
//double Box::getVolume(void)
//{
//	return length * breadth * height;
//}
//
//void Box::setLength(double len)
//{
//	length = len;
//}
//
//void Box::setBreadth(double bre)
//{
//	breadth = bre;
//}
//
//void Box::setHeight(double hei)
//{
//	height = hei;
//}
//
//double Box::getWidth(void) {
//	return width;
//}
//
//void Box::setWidth(double wid) {
//	width = wid;
//}
//int main2()
//{
//	Box Box1;
//	Box Box2;
//	double volume = 0;
//
//	/*Box1.length = 5.0;
//	Box1.breadth = 6.0;
//	Box1.height = 7;*/
//
//	Box1.setLength(5.0);
//	Box1.setBreadth(6.0);
//	Box1.setHeight(7);
//
//	//box1的体积
//	//volume = Box1.length * Box1.breadth * Box1.height;
//	volume = Box1.getVolume();
//	cout << "box1的体积" << volume <<"width:" << Box2.getWidth() << endl;
//
//	/*Box2.length = 10.0;
//	Box2.breadth = 20.0;
//	Box2.height = 30.0;*/
//
//	Box2.setLength(6.0);
//	Box2.setBreadth(7.0);
//	Box2.setHeight(8.0);
//	Box2.setWidth(10);
//
//	//box1的体积
//	//volume = Box2.length * Box2.breadth * Box2.height;
//	volume = Box2.getVolume();
//	cout << "box2的体积" << volume << "width:"<< Box2.getWidth() << endl;
//
//	printWidth(Box2);
//	return 0;
//}