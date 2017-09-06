#include "coorSet.h"


coorSet::coorSet(int size)
	:m_iSize(size)
{
	m_pPoints = new coordinate[m_iSize];
	unsigned int seed = 100;
	double rx;
	double ry;
	srand(seed);
	for (m_iIndex = 0; m_iIndex < m_iSize; m_iIndex++)
	{
		rx = rand() / (double)(RAND_MAX) * 360 - 180;
		ry = rand() / (double)(RAND_MAX) * 180 - 90;
		m_pPoints[m_iIndex] = coordinate(rx, ry);
	}
}
coorSet::~coorSet()
{
	delete []m_pPoints;
}
coordinate coorSet::getPoint(int index) const
{
	return m_pPoints[index];
}



