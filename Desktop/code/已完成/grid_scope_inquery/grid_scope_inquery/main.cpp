#include "grid_storage.h"
#include <stdlib.h>
#include <iostream>
#include <random>
#include <time.h>
#define  NUM  1000000
#define R 6371 //地球半径
//在球面上生成一定数量的点的集合。用于找出，球面上距离某点一定距离的点。
using namespace std;

//指定范围的随机数生成函数。每次生成的

int main()
{
	//第一段计时开始
	clock_t t1, t2;
	t1 = clock();


	//初始化生成1000个随机坐标点的点集合。coorSet。
	coorSet *p;
	p = new coorSet(NUM);

	//初始化一个网格存储器。
	grid_storage grid(1000,1000);

	//将这些随机点一个一个从coorset中取出来，再一个一个的存入网格中。
	coordinate coor(0, 0);
	for (int index = 0; index < NUM; index++)
	{	
		coor = p->getPoint(index);
		grid.data_input(coor);
	}
	
	//第一段计时结束。
	t2 = clock();
	cout << t2 - t1 << endl;

	//给出要查询的点及其范围。
	double x, y, r, c,abx,aby,m,n;
	cout << "请输入经度-180到180：" << endl;
	cin >> m;
	cout << "请输入纬度-90到90:" << endl;
	cin >> n;
	cout << "请输入查询半径r:" << endl;
	cin >> r;

	//计时开始。
	clock_t timeBegin, timeEnd;
	timeBegin = clock();


	//根据r求出其对应的角度c；
	c = r * 180 / (double)(PI*R);
	coordinate xy(m, n);
	//由给定的要查询的点与给定的半径范围。确定外部包围的角度大小
	x = (xy.getX())*PI / 180;
	y = (xy.getY() + 90)*PI / 180;
	if (y == 0 || y == PI)
	{
		abx = 360;
	}
	else
	{
		abx = 180 * abs(acos((cos(r / R) - cos(y)*cos(y)) / (sin(y)*sin(y)))) / PI;
	}
	aby = 180 * r / (PI*R);
	//根据原始提供的点（m，n）与abx，aby组成的4个点，可以获取这四个点在网格中所包围的网格索引范围。
	coordinate coor4[4];
	double temp;
	//得到右边坐标
	temp = (m + abx);
	if (temp > 180)
	{
		temp = temp - 360;
	}
	coor4[0].setxy(temp, n);
	//得到左边的坐标
	temp = (m - abx);
	if (temp < -180)
	{
		temp = temp + 360;
	}
	coor4[1].setxy(temp, n);
	//得到上面的坐标。
	temp = n + aby;
	if (temp > 90)
	{
		temp = 180 - temp;
	}
	coor4[2].setxy(m, temp);
	//得到下面的坐标
	temp = n - aby;
	if (temp < -90)
	{
		temp = -180 - temp;
	}
	coor4[3].setxy(m, temp);


	//设置两个4维数组，存储它们。
	int i[4], j[4];
	grid.get_xy_index(coor4[0],i[0],j[0]);
	grid.get_xy_index(coor4[1], i[1], j[1]);
	grid.get_xy_index(coor4[2], i[2], j[2]);
	grid.get_xy_index(coor4[3], i[3], j[3]);	
	//设置一个vector将查询出来的网格中的点全都存储起来。
	//vector<coordinate> ve;
	vector<coordinate> ve1;
	int count=0;
	for (int n =i[1] ; n <=i[0]; n++)
	{
		for (int m = j[3]; m <= j[2]; m++)
		{
			ve1 = grid.get_points_from_grid(n,m);
			//遍历所有ve1中的点。
			//找出其中满足要求的点。
			for (auto val:ve1)
			{
				if (((abs(val.getX() - xy.getX()) < 180) ? abs(val.getX() - xy.getX()) : 360 - abs(val.getX() - xy.getX())) > abx || abs(val.getY() - xy.getY()) > aby)
				{
					continue;
				}
				if (xy.coorDistance(val, R) <= r)
				{
					cout << val;
					count++;
				}

			}
			
		}

	}	

	cout << count << endl;

	delete p;
	p = NULL;
	//计时结束
	timeEnd = clock();
	cout << timeEnd - timeBegin << endl;
	return system("pause");
}