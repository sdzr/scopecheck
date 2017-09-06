#pragma once
#include "coordinate.h"
#include <math.h>

coordinate::coordinate(double x, double y)
{
	if (x < -180 || x>180)
	{
		cout << "注意：经度坐标输入错误，可能影响程序结果！！！" << endl;
	}
	if (y > 90 || y < -90)
	{
		cout << "注意：纬度坐标输入错误，可能影响程序结果！！！" << endl;
	}
	m_dx = x;
	m_dy = y;
}
coordinate::~coordinate()
{};
coordinate::coordinate(const coordinate &coor)
{
	m_dx = coor.m_dx;
	m_dy = coor.m_dy;
}
void coordinate::printCoor() const
{
	cout << "(" << m_dx <<" , "<< m_dy << ")" << endl;
}
double coordinate::coorDistance(const coordinate &coor,const double R) const
{
	double  x1 = coor.m_dx*PI / 180;
	double y1= (coor.m_dy+90)*PI / 180;
	double x2 = m_dx*PI/180;
	double y2 = (m_dy+90)*PI/180;
	double s = R*acos(sin(y1)*sin(y2)*cos(x1 - x2) + cos(y1)*cos(y2));
	return s;
}
ostream &operator<<(ostream &output, const coordinate &coor)
{
	output << "(" << coor.m_dx << " , " << coor.m_dy << ")" << endl;
	return output;
}
void coordinate::operator=(const coordinate& coor)
{
	m_dx = coor.m_dx;
	m_dy = coor.m_dy;
}
double coordinate::getX() const
{
	return m_dx;
}
double coordinate::getY() const
{
	return m_dy;
}
void coordinate::setxy(double x, double y)
{
	m_dx = x;
	m_dy = y;
}

