﻿#pragma once
#include <stdlib.h>
#include <iostream>
#include <random>
#include "coorSet.h"
#define  NUM  1000000
#define R 6371 //地球半径
//在球面上生成一定数量的点的集合。用于找出，球面上距离某点一定距离的点。
using namespace std;

//指定范围的随机数生成函数。每次生成的
int main()
{
	//初始化生成1000个随机坐标点的点集合。coorSet。
	coorSet *p;
	double x, y,r,c,abx,aby;
	p = new coorSet(NUM);
	cout << "请输入经度-180到180：" << endl;
	cin >> x;
	cout << "请输入纬度-90到90:" << endl;
	cin >> y;
	cout << "请输入查询半径r:" << endl;
	cin >> r;
	//根据r求出其对应的角度c；
	c = r*180 / (double)(PI*R);
	coordinate xy(x, y);
	//由给定的要查询的点与给定的半径范围。确定外部包络的角度大小
	x = (xy.getX())*PI/180;
	y = (xy.getY()+90)*PI / 180;
	if (y == 0 || y ==PI )
	{
		abx = 360;
	}
	else
	{
		abx =180*abs(acos((cos(r / R) - cos(y)*cos(y)) / (sin(y)*sin(y))))/PI;
	}
	aby =180*r/(PI*R);
	coordinate coor(0,0);
	//按索引遍历所有的点。
	int index;
	for (index = 0;index < NUM;index++)
	{
		coor = p->getPoint(index);
		if (((abs(coor.getX()-xy.getX())<180)?abs(coor.getX() - xy.getX()):360- abs(coor.getX() - xy.getX()))>abx||abs(coor.getY()-xy.getY())>aby)
		{		
			continue;
		}		
		if (xy.coorDistance(coor, R)<=r)
		{
			cout << coor;
		}
	}
	delete p;
	return system("pause");
}
//int main()
//{
//	coordinate coor1(0, 90);
//	coordinate coor2(-180, 89);
//	double s;
//	s = coor1.coorDistance(coor2, R);
//	cout << s << endl;
//
//	return system("pause");
//}