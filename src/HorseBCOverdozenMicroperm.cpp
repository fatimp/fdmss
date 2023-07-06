#include "HorseBCOverdozenMicroperm.h"
#include "AccuracyOrder.h"
#include "MouseFuncX.h"
#include "MouseFuncY.h"
#include "MouseFuncZ.h"

extern void (*compFuncX[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncY[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncZ[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);

void HorseBCOverdozenMicroperm::CreateOuterLayers()
{
	// Along X
	for (int z = 0; z < dim; z++)
	{
		for (int y = 0; y < dim; y++)
		{
			if (y >= ACCURACY_ORDER && y < dim - ACCURACY_ORDER && z >= ACCURACY_ORDER && z < dim - ACCURACY_ORDER)
			{
				unsigned char value = image->get(ACCURACY_ORDER, y, z);
				for (int x = 0; x < ACCURACY_ORDER; x++)
				{
					image->set(x, y, z, value);
				}

				value = image->get(dim - ACCURACY_ORDER - 1, y, z);
				for (int x = dim - ACCURACY_ORDER; x < dim; x++)
				{
					image->set(x, y, z, value);
				}
			}
			else
			{
				for (int x = 0; x < ACCURACY_ORDER; x++)
				{
					image->set(x, y, z, 1);
				}

				for (int x = dim - ACCURACY_ORDER; x < dim; x++)
				{
					image->set(x, y, z, 1);
				}
			}
		}
	}

	// Along Y
	for (int z = 0; z < dim; z++)
	{
		for (int x = 0; x < dim; x++)
		{
			if (x >= ACCURACY_ORDER && x < dim - ACCURACY_ORDER && z >= ACCURACY_ORDER && z < dim - ACCURACY_ORDER)
			{
				unsigned char value = image->get(x, ACCURACY_ORDER, z);
				for (int y = 0; y < ACCURACY_ORDER; y++)
				{
					image->set(x, y, z, value);
				}

				value = image->get(x, dim - ACCURACY_ORDER - 1, z);
				for (int y = dim - ACCURACY_ORDER; y < dim; y++)
				{
					image->set(x, y, z, value);
				}
			}
			else
			{
				for (int y = 0; y < ACCURACY_ORDER; y++)
				{
					image->set(x, y, z, 1);
				}

				for (int y = dim - ACCURACY_ORDER; y < dim; y++)
				{
					image->set(x, y, z, 1);
				}
			}
		}
	}

	// Along Z
	for (int y = 0; y < dim; y++)
	{
		for (int x = 0; x < dim; x++)
		{
			if (x >= ACCURACY_ORDER && x < dim - ACCURACY_ORDER && y >= ACCURACY_ORDER && y < dim - ACCURACY_ORDER)
			{
				unsigned char value = image->get(x, y, ACCURACY_ORDER);
				for (int z = 0; z < ACCURACY_ORDER; z++)
				{
					image->set(x, y, z, value);
				}

				value = image->get(x, y, dim - ACCURACY_ORDER - 1);
				for (int z = dim - ACCURACY_ORDER; z < dim; z++)
				{
					image->set(x, y, z, value);
				}
			}
			else
			{
				for (int z = 0; z < ACCURACY_ORDER; z++)
				{
					image->set(x, y, z, 1);
				}

				for (int z = dim - ACCURACY_ORDER; z < dim; z++)
				{
					image->set(x, y, z, 1);
				}
			}
		}
	}
}

void HorseBCOverdozenMicroperm::ReadFailo(const string filename)
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
		dim = innerDim + 2 * ACCURACY_ORDER;

		image = new FreeArea3d<unsigned char>();
		image->resize(dim, dim, dim);
		for (int z = 0; z < innerDim; z++)
		{
			for (int y = 0; y < innerDim; y++)
			{
				for (int x = 0; x < innerDim; x++)
				{
					unsigned char nextVoxel = (unsigned char)fgetc(fp);
					image->set(x + ACCURACY_ORDER, y + ACCURACY_ORDER, z + ACCURACY_ORDER, nextVoxel);
				}
			}
		}
		fclose(fp);

		CreateOuterLayers();
	}
}

HorseBCOverdozenMicroperm::HorseBCOverdozenMicroperm() : OverdozenMicroperm()
{
}

HorseBCOverdozenMicroperm::~HorseBCOverdozenMicroperm(void)
{
}

long HorseBCOverdozenMicroperm::EvalPressureCellsCount()
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

long HorseBCOverdozenMicroperm::EvalEffectivePorosityX()
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

long HorseBCOverdozenMicroperm::EvalEffectivePorosityY()
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

long HorseBCOverdozenMicroperm::EvalEffectivePorosityZ()
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

long HorseBCOverdozenMicroperm::GetVoxelDataX(StuffedVoxel **pVoxelData)
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

long HorseBCOverdozenMicroperm::GetVoxelDataY(StuffedVoxel **pVoxelData)
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

long HorseBCOverdozenMicroperm::GetVoxelDataZ(StuffedVoxel **pVoxelData)
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

long HorseBCOverdozenMicroperm::GetVoxelDataP(StuffedVoxel **pVoxelData)
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

float HorseBCOverdozenMicroperm::GetSquareFactor()
{
	if (squareFactor != -1.0f)
	{
		return squareFactor;
	}

	float sqr = 0.0;
	if (image != NULL)
	{
		for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
		{
			for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
			{
				if (image->get(0, j, k) == 0)
				{
					sqr += 1.0f;
				}
			}
		}
	}
	return (float)(dim - 2 * ACCURACY_ORDER) * (dim - 2 * ACCURACY_ORDER) / sqr;
}