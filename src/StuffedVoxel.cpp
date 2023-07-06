#include "StuffedVoxel.h"


StuffedVoxel::StuffedVoxel(): 
	x(0), y(0), z(0), funcIndex(0),
	compFuncPtr(NULL)
{
}

void StuffedVoxel::init(int x, int y, int z)
{
	this->x = (short) x;
	this->y = (short) y;
	this->z = (short) z;
}

//bool StuffedVoxel::operator>(const StuffedVoxel &andere)
//{
//	if (z > andere.z)
//	{
//		return true;
//	}
//	else if (z == andere.z && y > andere.y)
//	{
//		return true;
//	}
//	else if (z == andere.z && y == andere.y && x > andere.x)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool StuffedVoxel::operator==(const StuffedVoxel &andere)
//{
//	return z = andere.z && y == andere.y && x == andere.x;
//}
//
//bool StuffedVoxel::operator<(const StuffedVoxel &andere)
//{
//	return !(*this > andere || *this == andere);
//}