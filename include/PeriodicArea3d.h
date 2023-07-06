#ifndef PERIODIC_AREA_3D_H
#define PERIODIC_AREA_3D_H

#include "BoundaryArea3d.h"

template <typename T>
class PeriodicArea3d : public BoundaryArea3d<T>
{
public:
	PeriodicArea3d();
	virtual inline T boundaryGet(int x, int y, int z);
	virtual inline void boundarySet(int x, int y, int z, T value);
	virtual ~PeriodicArea3d();

private:
	using Area3d<T>::dimX;
	using Area3d<T>::dimY;
	using Area3d<T>::dimZ;
	using Area3d<T>::pData;
	using Area3d<T>::strideZ;
};

template <typename T>
PeriodicArea3d<T>::PeriodicArea3d()
{
}

template <typename T>
PeriodicArea3d<T>::~PeriodicArea3d()
{
}

template <typename T>
T PeriodicArea3d<T>::boundaryGet(int x, int y, int z)
{
	if (pData)
	{
		int px = x % dimX;
		px = px < 0 ? px + dimX : px;
		int py = y % dimY;
		py = py < 0 ? py + dimY : py;
		int pz = z % dimZ;
		pz = pz < 0 ? pz + dimZ : pz;
		return pData[strideZ * pz + dimX * py + px];
	}
	else
	{
		return -10;
	}
}

template <typename T>
void PeriodicArea3d<T>::boundarySet(int x, int y, int z, T value)
{
	if (pData != NULL)
	{
		int px = x % dimX;
		px = px < 0 ? px + dimX : px;
		int py = y % dimY;
		py = py < 0 ? py + dimY : py;
		int pz = z % dimZ;
		pz = pz < 0 ? pz + dimZ : pz;
		pData[strideZ * pz + dimX * py + px] = value;
	}
}

#endif // PERIODIC_AREA_3D_H
