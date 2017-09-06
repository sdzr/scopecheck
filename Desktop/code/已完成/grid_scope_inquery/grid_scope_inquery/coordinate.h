#pragma once
#include <stdlib.h>
#include <iostream>
#define PI 3.1415926535
using namespace std;
class coordinate 
{
	//友函数重构<<.
	friend ostream &operator<<(ostream &output, const coordinate &coor);
public:
	//用于初始化球面座标点，坐标以角度表示而非弧度-180<=x<=180,-90<=y<=90。
	coordinate(double x, double y);
	coordinate():m_dx(0.0), m_dy(0.0) {};
	//拷贝构造函数。
	coordinate( const coordinate &coor);
	//打印坐标。
	void printCoor() const;
	//用于求球面两坐标点之间的最短球面积距离,R是球面的半径。
	double coorDistance(const coordinate &coor,double R) const;
	//分别获取x，y。
	double getX() const;
	double getY() const;
	//设置coordinate的值
	void setxy(double x, double y);
	//析构函数
	~coordinate();
	//赋值符号的重载。
	void operator=(const coordinate& coor);
private:
	double m_dx;
	double m_dy;
};