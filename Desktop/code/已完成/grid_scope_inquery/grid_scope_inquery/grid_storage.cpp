#include "grid_storage.h"
grid_storage::grid_storage(double xm, double yn,double xl, double xr, double yd, double yu)
{	
	x_left = xl;
	x_right = xr;
	y_up = yu;
	y_down = yd;
	x_num= xm;
	y_num= yn;
	block_size_x = (xr-xl)/x_num;
	block_size_y = (yu-yd)/y_num;
	vecs.resize(xm*yn);
	cout << vecs.size() << endl;
}
void grid_storage::data_input(coordinate coor)
{
	double x=coor.getX();
	double y = coor.getY();
	if (x >= 180)
	{
		x = x - 1;
	}
	if (y >= 90)
	{
		y = y - 1;
	}
	int index =(floor((x - x_left) / block_size_x))+(floor((y-y_down)/block_size_y))*x_num;
	//cout << index << endl;
	vecs[index].push_back(coor);
	return;
}
const vector<coordinate> grid_storage::get_points_from_grid(int i, int j) const
{
	//cout << vecs[i + j*x_num].size() << endl;
	return vecs[i + j*x_num];
}
void grid_storage::get_xy_index(coordinate coor, int &i, int &j)
{
	double x = coor.getX();
	double y = coor.getY();
	i = floor((x - x_left) / block_size_x);
	j = floor((y - y_down) / block_size_y);
	return;
}
