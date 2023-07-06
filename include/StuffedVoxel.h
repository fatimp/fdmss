#ifndef STUFFED_VOXEL
#define STUFFED_VOXEL

#include "Area3d.h"

struct StuffedVoxel
{
	short x;
	short y;
	short z;
	short funcIndex;

	void (*compFuncPtr)(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);

	StuffedVoxel();
	void init(int x, int y, int z);

	//bool operator>(const StuffedVoxel &andere);
	//bool operator<(const StuffedVoxel &andere);
	//bool operator==(const StuffedVoxel &andere);
};

#endif // STUFFED_VOXEL