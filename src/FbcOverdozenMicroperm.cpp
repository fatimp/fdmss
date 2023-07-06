#include "FbcOverdozenMicroperm.h"
#include "MouseFuncX.h"
#include "MouseFuncY.h"
#include "MouseFuncZ.h"

extern void (*compFuncX[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncY[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncZ[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);

FbcOverdozenMicroperm::FbcOverdozenMicroperm() : OverdozenMicroperm()
{
}

FbcOverdozenMicroperm::~FbcOverdozenMicroperm()
{
}

void FbcOverdozenMicroperm::ReadFailo(const string filename)
{
	// Reset square factor because of new data loading
	squareFactor = -1.0f;

	FILE *fp = fopen(filename.c_str(), "rb");
	if (fp != NULL)
	{
		fseek(fp, 0L, SEEK_END);
		long sz = ftell(fp);
		fseek(fp, 0L, SEEK_SET);
		innerDim = (int)floor(pow((double)sz, 1.0 / 3.0) + 0.5);
		dim = innerDim;

		image = new FreeArea3d<unsigned char>();
		image->resize(dim, dim, dim);
		for (int z = 0; z < innerDim; z++)
		{
			for (int y = 0; y < innerDim; y++)
			{
				for (int x = 0; x < innerDim; x++)
				{
					unsigned char nextVoxel = (unsigned char)fgetc(fp);
					image->set(x, y, z, nextVoxel);
				}
			}
		}
		fclose(fp);
	}
}

long FbcOverdozenMicroperm::EvalPressureCellsCount()
{
	pressureCellsCount = 0L;
	for (int z = 1; z < dim; z++)
	{
		for (int y = 1; y < dim; y++)
		{
			for (int x = 1; x < dim; x++)
			{
				if (image->get(x, y, z) == 0)
				{
					pressureCellsCount++;
				}
			}
		}
	}
	return pressureCellsCount;
}

long FbcOverdozenMicroperm::EvalEffectivePorosityX()
{
	porosityX = 0L;
	for (int z = 0; z < dim; z++)
	{
		for (int y = 0; y < dim; y++)
		{
			for (int x = 0; x < dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x + 1, y, z) == 0) // && image->boundaryGet(x - 1, y, z) == 0)
				{
					porosityX++;
				}
			}
		}
	}
	return porosityX;
}

long FbcOverdozenMicroperm::EvalEffectivePorosityY()
{
	porosityY = 0L;
	for (int z = 0; z < dim; z++)
	{
		for (int y = 0; y < dim; y++)
		{
			for (int x = 0; x < dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x, y + 1, z) == 0) // && image->boundaryGet(x, y - 1, z) == 0)
				{
					porosityY++;
				}
			}
		}
	}
	return porosityY;
}

long FbcOverdozenMicroperm::EvalEffectivePorosityZ()
{
	porosityZ = 0L;
	for (int z = 0; z < dim; z++)
	{
		for (int y = 0; y < dim; y++)
		{
			for (int x = 0; x < dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x, y, z + 1) == 0) // && image->boundaryGet(x, y, z - 1) == 0)
				{
					porosityZ++;
				}
			}
		}
	}
	return porosityZ;
}

long FbcOverdozenMicroperm::GetVoxelDataX(StuffedVoxel **pVoxelData)
{
	if (voxelDataX != NULL)
	{
		*pVoxelData = voxelDataX;
		return porosityX;
	}

	EvalEffectivePorosityX();
	voxelDataX = new StuffedVoxel[porosityX];
	long idx = 0L;
	for (int z = 0; z < dim; z++)
	{
		for (int y = 0; y < dim; y++)
		{
			for (int x = 0; x < dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x + 1, y, z) == 0) // && image->boundaryGet(x - 1, y, z) == 0)
				{
					voxelDataX[idx].init(x + 1, y, z);
					EnvCase *ec = EvalAdjacentVoxelsX(x, y, z);
					int funcPos = ec->GetIndexInFuncArray();
					voxelDataX[idx].funcIndex = (short int)funcPos;
					voxelDataX[idx].compFuncPtr = compFuncX[funcPos];
					idx++;
				}
			}
		}
	}

	*pVoxelData = voxelDataX;
	return porosityX;
}

long FbcOverdozenMicroperm::GetVoxelDataY(StuffedVoxel **pVoxelData)
{
	if (voxelDataY != NULL)
	{
		*pVoxelData = voxelDataY;
		return porosityY;
	}

	EvalEffectivePorosityY();
	voxelDataY = new StuffedVoxel[porosityY];
	long idx = 0L;
	for (int z = 0; z < dim; z++)
	{
		for (int y = 0; y < dim; y++)
		{
			for (int x = 0; x < dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x, y + 1, z) == 0) // && image->boundaryGet(x, y - 1, z) == 0)
				{
					voxelDataY[idx].init(x, y + 1, z);
					EnvCase *ec = EvalAdjacentVoxelsY(x, y, z);
					int funcPos = ec->GetIndexInFuncArray();
					voxelDataY[idx].funcIndex = (short int)funcPos;
					voxelDataY[idx].compFuncPtr = compFuncY[funcPos];
					idx++;
				}
			}
		}
	}

	*pVoxelData = voxelDataY;
	return porosityY;
}

long FbcOverdozenMicroperm::GetVoxelDataZ(StuffedVoxel **pVoxelData)
{
	if (voxelDataZ != NULL)
	{
		*pVoxelData = voxelDataZ;
		return porosityZ;
	}

	EvalEffectivePorosityZ();
	voxelDataZ = new StuffedVoxel[porosityZ];
	long idx = 0L;
	for (int z = 0; z < dim; z++)
	{
		for (int y = 0; y < dim; y++)
		{
			for (int x = 0; x < dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x, y, z + 1) == 0) // && image->boundaryGet(x, y, z - 1) == 0)
				{
					voxelDataZ[idx].init(x, y, z + 1);
					EnvCase *ec = EvalAdjacentVoxelsZ(x, y, z);
					int funcPos = ec->GetIndexInFuncArray();
					voxelDataZ[idx].funcIndex = (short int)funcPos;
					voxelDataZ[idx].compFuncPtr = compFuncZ[funcPos];
					idx++;
				}
			}
		}
	}

	*pVoxelData = voxelDataZ;
	return porosityZ;
}

long FbcOverdozenMicroperm::GetVoxelDataP(StuffedVoxel **pVoxelData)
{
	if (voxelDataP != NULL)
	{
		*pVoxelData = voxelDataP;
		return pressureCellsCount;
	}

	EvalPressureCellsCount();
	voxelDataP = new StuffedVoxel[pressureCellsCount];
	long idx = 0L;
	for (int z = 1; z < dim; z++)
	{
		for (int y = 1; y < dim; y++)
		{
			for (int x = 1; x < dim; x++)
			{
				if (image->get(x, y, z) == 0)
				{
					voxelDataP[idx].init(x, y, z);
					idx++;
				}
			}
		}
	}

	*pVoxelData = voxelDataP;
	return pressureCellsCount;
}