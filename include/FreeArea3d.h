#ifndef FREE_AREA_3D_H
#define FREE_AREA_3D_H

#include "BoundaryArea3d.h"
template <typename T>
class FreeArea3d : public BoundaryArea3d<T>
{
public:
	FreeArea3d();
	virtual inline T boundaryGet(int x, int y, int z);
	virtual inline void boundarySet(int x, int y, int z, T value);
	virtual ~FreeArea3d();

private:
	using Area3d<T>::dimX;
	using Area3d<T>::pData;
	using Area3d<T>::strideZ;
};

template <typename T>
FreeArea3d<T>::FreeArea3d()
{
}

template <typename T>
FreeArea3d<T>::~FreeArea3d()
{
}

template <typename T>
T FreeArea3d<T>::boundaryGet(int x, int y, int z)
{
	if (pData)
	{
		x = x < 0 ? 0 : x;
		x = x >= dimX ? dimX - 1 : x;
		y = y < 0 ? 0 : y;
		y = y >= dimX ? dimX - 1 : y;
		z = z < 0 ? 0 : z;
		z = z >= dimX ? dimX - 1 : z;

		return pData[strideZ * z + dimX * y + x];
	}
	else
	{
		throw runtime_error("Out of bounds");
		return -1;
	}
}

template <typename T>
void FreeArea3d<T>::boundarySet(int x, int y, int z, T value)
{
	if (pData != NULL)
	{
		x = x < 0 ? 0 : x;
		x = x >= dimX ? dimX - 1 : x;
		y = y < 0 ? 0 : y;
		y = y >= dimX ? dimX - 1 : y;
		z = z < 0 ? 0 : z;
		z = z >= dimX ? dimX - 1 : z;
		pData[strideZ * z + dimX * y + x] = value;
	}
}

#endif // FREE_AREA_3D_H