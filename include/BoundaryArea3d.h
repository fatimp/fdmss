#ifndef BOUNDARY_AREA_3D_H
#define BOUNDARY_AREA_3D_H

#include "Area3d.h"

template <typename T>
class BoundaryArea3d : public Area3d<T>
{
public:
	BoundaryArea3d();
	virtual inline T boundaryGet(int x, int y, int z) = 0;
	virtual inline void boundarySet(int x, int y, int z, T value) = 0;
	virtual ~BoundaryArea3d();
};

template <typename T>
BoundaryArea3d<T>::BoundaryArea3d()
{
}

template <typename T>
BoundaryArea3d<T>::~BoundaryArea3d()
{
}

#endif // BOUNDARY_AREA_3D_H