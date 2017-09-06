#include "coorSet.h"
#include <vector>
class grid_storage
{
public:
	/*
	*  xm:x方向上网格块数
	*  yn:y方向上网格块数
	*  xl,xr：分别为网格的左边界与右边界。默认为-180,180.
	*  yl,yr:分别为网格左边界与右边界。默认为-90到90.
	*/
	grid_storage(double xm, double yn,double xl=-180, double xr = 180, double yd = -90, double yu = 90);

	/* 读取coordinate点到网格中的vectors里面。
	*  coor,为要存入的坐标元素
	*/
	void data_input(coordinate coor);


	//按索引获取网格中的元素
	//根据网格的横纵坐标，获取该网格中所有的点。
	//0<=i<x_num;0<=j<y_num;
	//输入：i，j横纵索引。
	//返回：装有coordinate的vector的引用。
	const vector<coordinate> get_points_from_grid(int i, int j) const;


	//根据所给的点，确定出该点所在的网格横纵坐标。
	//输入coordinate.
	//返回：i，j索引。
	void get_xy_index(coordinate coor, int &i, int &j);
	
	
private:
	double x_left;
	double x_right;
	double y_up;
	double y_down;
	double block_size_x;
	double block_size_y;
	int x_num;
	int y_num;	
	vector<vector<coordinate>> vecs;
};