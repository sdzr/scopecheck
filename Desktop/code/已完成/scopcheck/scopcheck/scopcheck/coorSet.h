#include "coordinate.h"
class coorSet
{
public:
	coorSet(int size);
	~coorSet();
	//控制坐标集的大小。
	//按索引获取其中的点。从0到m_iSize。
	coordinate getPoint(int index) const;

private:
	const int m_iSize;
	coordinate *m_pPoints;
	int m_iIndex;
};