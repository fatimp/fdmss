#include "PbcOverdozenMicroperm.h"
#include "MouseFuncX.h"
#include "MouseFuncY.h"
#include "MouseFuncZ.h"

extern void (*compFuncX[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncY[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncZ[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);

PbcOverdozenMicroperm::PbcOverdozenMicroperm(const char _flowDirectionAxis) : OverdozenMicroperm(_flowDirectionAxis)
{
}

PbcOverdozenMicroperm::~PbcOverdozenMicroperm()
{
}

void PbcOverdozenMicroperm::ReadFailo(const string filename, const unsigned int waterLayerWidth)
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
		dim = innerDim + 2 * int(waterLayerWidth);

		image = new PeriodicArea3d<unsigned char>();
		image->resize(dim, dim, dim);
		image->clear();
		for (int z = waterLayerWidth; z < innerDim + waterLayerWidth; z++)
		{
			for (int y = waterLayerWidth; y < innerDim + waterLayerWidth; y++)
			{
				for (int x = waterLayerWidth; x < innerDim + waterLayerWidth; x++)
				{
					unsigned char nextVoxel = (unsigned char)fgetc(fp);
					image->set(x, y, z, nextVoxel);
				}
			}
		}
		fclose(fp);
	}
}

long PbcOverdozenMicroperm::EvalPressureCellsCount()
{

	switch (flowDirectionAxis)
	{
	case 'y':
		return EvalPressureCellsCount_FlowY();
		break;
	case 'z':
		return EvalPressureCellsCount_FlowZ();
		break;
	case 'x':
	default:
		return EvalPressureCellsCount_FlowX();
		break;
	}
}

long PbcOverdozenMicroperm::EvalPressureCellsCount_FlowX()
{
	pressureCellsCount = 0L;
	for (int z = 0; z <= dim; z++)
	{
		int z2 = z == dim ? 0 : z;
		for (int y = 0; y <= dim; y++)
		{
			int y2 = y == dim ? 0 : y;
			for (int x = 1; x < dim; x++)
			{
				if (image->get(x, y2, z2) == 0)
				{
					pressureCellsCount++;
				}
			}
		}
	}
	return pressureCellsCount;
}

long PbcOverdozenMicroperm::EvalPressureCellsCount_FlowY()
{
	pressureCellsCount = 0L;
	for (int z = 0; z <= dim; z++)
	{
		int z2 = z == dim ? 0 : z;
		for (int x = 0; x <= dim; x++)
		{
			int x2 = x == dim ? 0 : x;
			for (int y = 1; y < dim; y++)
			{
				if (image->get(x2, y, z2) == 0)
				{
					pressureCellsCount++;
				}
			}
		}
	}
	return pressureCellsCount;
}

long PbcOverdozenMicroperm::EvalPressureCellsCount_FlowZ()
{
	pressureCellsCount = 0L;
	for (int y = 0; y <= dim; y++)
	{
		int y2 = y == dim ? 0 : y;
		for (int x = 0; x <= dim; x++)
		{
			int x2 = x == dim ? 0 : x;
			for (int z = 1; z < dim; z++)
			{
				if (image->get(x2, y2, z) == 0)
				{
					pressureCellsCount++;
				}
			}
		}
	}
	return pressureCellsCount;
}

long PbcOverdozenMicroperm::EvalEffectivePorosityX()
{
	porosityX = 0L;
	for (int z = 1; z <= dim; z++)
	{
		for (int y = 1; y <= dim; y++)
		{
			for (int x = 0; x < dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x + 1, y, z) == 0)
				{
					porosityX++;
				}
			}
		}
	}
	return porosityX;
}

long PbcOverdozenMicroperm::EvalEffectivePorosityY()
{
	porosityY = 0L;
	for (int z = 1; z <= dim; z++)
	{
		for (int y = 0; y < dim; y++)
		{
			for (int x = 1; x <= dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x, y + 1, z) == 0)
				{
					porosityY++;
				}
			}
		}
	}
	return porosityY;
}

long PbcOverdozenMicroperm::EvalEffectivePorosityZ()
{
	porosityZ = 0L;
	for (int z = 0; z < dim; z++)
	{
		for (int y = 1; y <= dim; y++)
		{
			for (int x = 1; x <= dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x, y, z + 1) == 0)
				{
					porosityZ++;
				}
			}
		}
	}
	return porosityZ;
}

long PbcOverdozenMicroperm::GetVoxelDataX(StuffedVoxel **pVoxelData)
{
	if (voxelDataX != NULL)
	{
		*pVoxelData = voxelDataX;
		return porosityX;
	}

	EvalEffectivePorosityX();
	voxelDataX = new StuffedVoxel[porosityX];
	long idx = 0L;
	for (int z = 1; z <= dim; z++)
	{
		for (int y = 1; y <= dim; y++)
		{
			for (int x = 0; x < dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x + 1, y, z) == 0)
				{
					voxelDataX[idx].init(x, y - 1, z - 1);
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

long PbcOverdozenMicroperm::GetVoxelDataY(StuffedVoxel **pVoxelData)
{
	if (voxelDataY != NULL)
	{
		*pVoxelData = voxelDataY;
		return porosityY;
	}

	EvalEffectivePorosityY();
	voxelDataY = new StuffedVoxel[porosityY];
	long idx = 0L;
	for (int z = 1; z <= dim; z++)
	{
		for (int y = 0; y < dim; y++)
		{
			for (int x = 1; x <= dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x, y + 1, z) == 0)
				{
					voxelDataY[idx].init(x - 1, y, z - 1);
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

long PbcOverdozenMicroperm::GetVoxelDataZ(StuffedVoxel **pVoxelData)
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
		for (int y = 1; y <= dim; y++)
		{
			for (int x = 1; x <= dim; x++)
			{
				if (image->boundaryGet(x, y, z) == 0 && image->boundaryGet(x, y, z + 1) == 0)
				{
					voxelDataZ[idx].init(x - 1, y - 1, z);
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

long PbcOverdozenMicroperm::GetVoxelDataP(StuffedVoxel **pVoxelData)
{
	switch (flowDirectionAxis)
	{
	case 'y':
		return GetVoxelDataP_FlowY(pVoxelData);
	case 'z':
		return GetVoxelDataP_FlowZ(pVoxelData);
	case 'x':
	default:
		return GetVoxelDataP_FlowX(pVoxelData);
	}
}

long PbcOverdozenMicroperm::GetVoxelDataP_FlowX(StuffedVoxel **pVoxelData)
{
	if (voxelDataP != NULL)
	{
		*pVoxelData = voxelDataP;
		return pressureCellsCount;
	}

	EvalPressureCellsCount();
	voxelDataP = new StuffedVoxel[pressureCellsCount];
	long idx = 0L;
	for (int z = 0; z <= dim; z++)
	{
		int z2 = z == dim ? 0 : z;
		for (int y = 0; y <= dim; y++)
		{
			int y2 = y == dim ? 0 : y;
			for (int x = 1; x < dim; x++)
			{
				if (image->get(x, y2, z2) == 0)
				{
					voxelDataP[idx].init(x - 1, y - 1, z - 1);
					idx++;
				}
			}
		}
	}

	*pVoxelData = voxelDataP;
	return pressureCellsCount;
}

long PbcOverdozenMicroperm::GetVoxelDataP_FlowY(StuffedVoxel **pVoxelData)
{
	if (voxelDataP != NULL)
	{
		*pVoxelData = voxelDataP;
		return pressureCellsCount;
	}

	EvalPressureCellsCount();
	voxelDataP = new StuffedVoxel[pressureCellsCount];
	long idx = 0L;
	for (int z = 0; z <= dim; z++)
	{
		int z2 = z == dim ? 0 : z;
		for (int x = 0; x <= dim; x++)
		{
			int x2 = x == dim ? 0 : x;
			for (int y = 1; y < dim; y++)
			{
				if (image->get(x2, y, z2) == 0)
				{
					voxelDataP[idx].init(x - 1, y - 1, z - 1);
					idx++;
				}
			}
		}
	}

	*pVoxelData = voxelDataP;
	return pressureCellsCount;
}

long PbcOverdozenMicroperm::GetVoxelDataP_FlowZ(StuffedVoxel **pVoxelData)
{
	if (voxelDataP != NULL)
	{
		*pVoxelData = voxelDataP;
		return pressureCellsCount;
	}

	EvalPressureCellsCount();
	voxelDataP = new StuffedVoxel[pressureCellsCount];
	long idx = 0L;
	for (int y = 0; y <= dim; y++)
	{
		int y2 = y == dim ? 0 : y;
		for (int x = 0; x <= dim; x++)
		{
			int x2 = x == dim ? 0 : x;
			for (int z = 1; z < dim; z++)
			{
				if (image->get(x2, y2, z) == 0)
				{
					voxelDataP[idx].init(x - 1, y - 1, z - 1);
					idx++;
				}
			}
		}
	}
	*pVoxelData = voxelDataP;
	return pressureCellsCount;
}