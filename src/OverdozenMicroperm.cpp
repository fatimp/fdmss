#include "OverdozenMicroperm.h"
#include "AccuracyOrder.h"
#include "MouseFuncX.h"
#include "MouseFuncY.h"
#include "MouseFuncZ.h"

extern void (*compFuncX[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncY[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncZ[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);

EnvCase *OverdozenMicroperm::EvalAdjacentVoxelsX(int x, int y, int z)
{
	int sd = ACCURACY_ORDER / 2;
	int yLeft = 0, yRight = 0, zLeft = 0, zRight = 0;

	// Y direction
	for (int ys = y - 1; ys >= y - sd; ys--)
	{
		if (image->boundaryGet(x, ys, z) == 0 && image->boundaryGet(x + 1, ys, z) == 0) // && image->boundaryGet(x - 1, ys, z) == 0)
		{
			yLeft++;
		}
		else
		{
			break;
		}
	}
	for (int ys = y + 1; ys <= y + sd; ys++)
	{
		if (image->boundaryGet(x, ys, z) == 0 && image->boundaryGet(x + 1, ys, z) == 0) // && image->boundaryGet(x - 1, ys, z) == 0)
		{
			yRight++;
		}
		else
		{
			break;
		}
	}

	if (yLeft < sd)
	{
		for (int ys = y + sd + 1; ys <= y + ACCURACY_ORDER - yLeft; ys++)
		{
			if (image->boundaryGet(x, ys, z) == 0 && image->boundaryGet(x + 1, ys, z) == 0) // && image->boundaryGet(x - 1, ys, z) == 0)
			{
				yRight++;
			}
			else
			{
				break;
			}
		}
	}
	if (yRight < sd)
	{
		for (int ys = y - sd - 1; ys >= y - ACCURACY_ORDER + yRight; ys--)
		{
			if (image->boundaryGet(x, ys, z) == 0 && image->boundaryGet(x + 1, ys, z) == 0) // && image->boundaryGet(x - 1, ys, z) == 0)
			{
				yLeft++;
			}
			else
			{
				break;
			}
		}
	}

	// Z direction
	for (int zs = z - 1; zs >= z - sd; zs--)
	{
		if (image->boundaryGet(x, y, zs) == 0 && image->boundaryGet(x + 1, y, zs) == 0) // && image->boundaryGet(x - 1, y, zs) == 0)
		{
			zLeft++;
		}
		else
		{
			break;
		}
	}
	for (int zs = z + 1; zs <= z + sd; zs++)
	{
		if (image->boundaryGet(x, y, zs) == 0 && image->boundaryGet(x + 1, y, zs) == 0) // && image->boundaryGet(x - 1, y, zs) == 0)
		{
			zRight++;
		}
		else
		{
			break;
		}
	}

	if (zLeft < sd)
	{
		for (int zs = z + sd + 1; zs <= z + ACCURACY_ORDER - zLeft; zs++)
		{
			if (image->boundaryGet(x, y, zs) == 0 && image->boundaryGet(x + 1, y, zs) == 0) // && image->boundaryGet(x - 1, y, zs) == 0)
			{
				zRight++;
			}
			else
			{
				break;
			}
		}
	}
	if (zRight < sd)
	{
		for (int zs = z - sd - 1; zs >= z - ACCURACY_ORDER + zRight; zs--)
		{
			if (image->boundaryGet(x, y, zs) == 0 && image->boundaryGet(x + 1, y, zs) == 0) // && image->boundaryGet(x - 1, y, zs) == 0)
			{
				zLeft++;
			}
			else
			{
				break;
			}
		}
	}

	return new EnvCase(yLeft, yRight, zLeft, zRight, ACCURACY_ORDER);
}

EnvCase *OverdozenMicroperm::EvalAdjacentVoxelsY(int x, int y, int z)
{
	int sd = ACCURACY_ORDER / 2;
	int xLeft = 0, xRight = 0, zLeft = 0, zRight = 0;

	// X direction
	for (int xs = x - 1; xs >= x - sd; xs--)
	{
		if (image->boundaryGet(xs, y, z) == 0 && image->boundaryGet(xs, y + 1, z) == 0) // && image->boundaryGet(xs, y - 1, z) == 0)
		{
			xLeft++;
		}
		else
		{
			break;
		}
	}
	for (int xs = x + 1; xs <= x + sd; xs++)
	{
		if (image->boundaryGet(xs, y, z) == 0 && image->boundaryGet(xs, y + 1, z) == 0) // && image->boundaryGet(xs, y - 1, z) == 0)
		{
			xRight++;
		}
		else
		{
			break;
		}
	}

	if (xLeft < sd)
	{
		for (int xs = x + sd + 1; xs <= x + ACCURACY_ORDER - xLeft; xs++)
		{
			if (image->boundaryGet(xs, y, z) == 0 && image->boundaryGet(xs, y + 1, z) == 0) // && image->boundaryGet(xs, y - 1, z) == 0)
			{
				xRight++;
			}
			else
			{
				break;
			}
		}
	}
	if (xRight < sd)
	{
		for (int xs = x - sd - 1; xs >= x - ACCURACY_ORDER + xRight; xs--)
		{
			if (image->boundaryGet(xs, y, z) == 0 && image->boundaryGet(xs, y + 1, z) == 0) // && image->boundaryGet(xs, y - 1, z) == 0)
			{
				xLeft++;
			}
			else
			{
				break;
			}
		}
	}

	// Z direction
	for (int zs = z - 1; zs >= z - sd; zs--)
	{
		if (image->boundaryGet(x, y, zs) == 0 && image->boundaryGet(x, y + 1, zs) == 0) // && image->boundaryGet(x, y - 1, zs) == 0)
		{
			zLeft++;
		}
		else
		{
			break;
		}
	}
	for (int zs = z + 1; zs <= z + sd; zs++)
	{
		if (image->boundaryGet(x, y, zs) == 0 && image->boundaryGet(x, y + 1, zs) == 0) // && image->boundaryGet(x, y - 1, zs) == 0)
		{
			zRight++;
		}
		else
		{
			break;
		}
	}

	if (zLeft < sd)
	{
		for (int zs = z + sd + 1; zs <= z + ACCURACY_ORDER - zLeft; zs++)
		{
			if (image->boundaryGet(x, y, zs) == 0 && image->boundaryGet(x, y + 1, zs) == 0) // && image->boundaryGet(x, y - 1, zs) == 0)
			{
				zRight++;
			}
			else
			{
				break;
			}
		}
	}
	if (zRight < sd)
	{
		for (int zs = z - sd - 1; zs >= z - ACCURACY_ORDER + zRight; zs--)
		{
			if (image->boundaryGet(x, y, zs) == 0 && image->boundaryGet(x, y + 1, zs) == 0) // && image->boundaryGet(x, y - 1, zs) == 0)
			{
				zLeft++;
			}
			else
			{
				break;
			}
		}
	}

	return new EnvCase(xLeft, xRight, zLeft, zRight, ACCURACY_ORDER);
}

EnvCase *OverdozenMicroperm::EvalAdjacentVoxelsZ(int x, int y, int z)
{
	int sd = ACCURACY_ORDER / 2;
	int xLeft = 0, xRight = 0, yLeft = 0, yRight = 0;

	// X direction
	for (int xs = x - 1; xs >= x - sd; xs--)
	{
		if (image->boundaryGet(xs, y, z) == 0 && image->boundaryGet(xs, y, z + 1) == 0) // && image->boundaryGet(xs, y, z - 1) == 0)
		{
			xLeft++;
		}
		else
		{
			break;
		}
	}
	for (int xs = x + 1; xs <= x + sd; xs++)
	{
		if (image->boundaryGet(xs, y, z) == 0 && image->boundaryGet(xs, y, z + 1) == 0) // && image->boundaryGet(xs, y, z - 1) == 0)
		{
			xRight++;
		}
		else
		{
			break;
		}
	}

	if (xLeft < sd)
	{
		for (int xs = x + sd + 1; xs <= x + ACCURACY_ORDER - xLeft; xs++)
		{
			if (image->boundaryGet(xs, y, z) == 0 && image->boundaryGet(xs, y, z + 1) == 0) // && image->boundaryGet(xs, y, z - 1) == 0)
			{
				xRight++;
			}
			else
			{
				break;
			}
		}
	}
	if (xRight < sd)
	{
		for (int xs = x - sd - 1; xs >= x - ACCURACY_ORDER + xRight; xs--)
		{
			if (image->boundaryGet(xs, y, z) == 0 && image->boundaryGet(xs, y, z + 1) == 0) // && image->boundaryGet(xs, y - 1, z - 1) == 0)
			{
				xLeft++;
			}
			else
			{
				break;
			}
		}
	}

	// Y direction
	for (int ys = y - 1; ys >= y - sd; ys--)
	{
		if (image->boundaryGet(x, ys, z) == 0 && image->boundaryGet(x, ys, z + 1) == 0) // && image->boundaryGet(x, ys, z - 1) == 0)
		{
			yLeft++;
		}
		else
		{
			break;
		}
	}
	for (int ys = y + 1; ys <= y + sd; ys++)
	{
		if (image->boundaryGet(x, ys, z) == 0 && image->boundaryGet(x, ys, z + 1) == 0) // && image->boundaryGet(x, ys, z - 1) == 0)
		{
			yRight++;
		}
		else
		{
			break;
		}
	}

	if (yLeft < sd)
	{
		for (int ys = y + sd + 1; ys <= y + ACCURACY_ORDER - yLeft; ys++)
		{
			if (image->boundaryGet(x, ys, z) == 0 && image->boundaryGet(x, ys, z + 1) == 0) // && image->boundaryGet(x, ys, z - 1) == 0)
			{
				yRight++;
			}
			else
			{
				break;
			}
		}
	}
	if (yRight < sd)
	{
		for (int ys = y - sd - 1; ys >= y - ACCURACY_ORDER + yRight; ys--)
		{
			if (image->boundaryGet(x, ys, z) == 0 && image->boundaryGet(x, ys, z + 1) == 0) // && image->boundaryGet(x, ys, z - 1) == 0)
			{
				yLeft++;
			}
			else
			{
				break;
			}
		}
	}

	return new EnvCase(xLeft, xRight, yLeft, yRight, ACCURACY_ORDER);
}

void OverdozenMicroperm::WritePressureFailo()
{
	//FILE* f = NULL;
	//fopen_s(&f, "pslist_od", "wt");
	//long count = 0L;
	//if (f != NULL)
	//{
	//	for (int z = 0; z <= dim; z++)
	//	{
	//		int z2 = z == dim ? 0 : z;
	//		for (int y = 0; y <= dim; y++)
	//		{
	//			int y2 = y == dim ? 0 : y;
	//			for (int x = 1; x < dim; x++)
	//			{
	//				if (image->get(x, y2, z2) == 0)
	//				{
	//					long encode =
	//						x + 2 +
	//						1024 * (y + 2) +
	//						1024 * 1024 * (z + 2);
	//					fprintf(f, "%ld \n", encode);
	//					count++;
	//				}
	//			}
	//		}
	//	}
	//	fprintf(f, "%ld\n", count);
	//	fseek(f, 0, SEEK_SET);
	//	fclose(f);
	//}
	FILE *f = fopen("pslist_od", "wt");
	if (f != NULL)
	{
		for (long vx = 0; vx < pressureCellsCount; vx++)
		{
			StuffedVoxel *ptr = voxelDataP + vx;
			long encode =
				ptr->x + 2 +
				1024 * (ptr->y + 2) +
				1024 * 1024 * (ptr->z + 2);
			fprintf(f, "%ld \n", encode);
		}
		fclose(f);
	}
}

int OverdozenMicroperm::GetDimension()
{
	return dim;
}

float OverdozenMicroperm::GetSquareFactor()
{
	if (squareFactor != -1.0f)
	{
		return squareFactor;
	}

	float sqr = 0.0;
	if (image != NULL)
	{
		switch (flowDirectionAxis)
		{
		case 'y':
			for (int i = 0; i < dim; i++)
			{
				for (int k = 0; k < dim; k++)
				{
					if (image->get(i, 1, k) == 0)
					{
						sqr += 1.0f;
					}
				}
			}
			break;
		case 'z':
			for (int i = 0; i < dim; i++)
			{
				for (int j = 0; j < dim; j++)
				{
					if (image->get(i, j, 1) == 0)
					{
						sqr += 1.0f;
					}
				}
			}
			break;
		case 'x':
		default:
			for (int j = 0; j < dim; j++)
			{
				for (int k = 0; k < dim; k++)
				{
					if (image->get(0, j, k) == 0)
					{
						sqr += 1.0f;
					}
				}
			}
			break;
		}
	}
	return (float)dim * dim / sqr;
}

float OverdozenMicroperm::GetInnerSquareFactor()
{
	if (squareFactorInner != -1.0f)
	{
		return squareFactorInner;
	}

	int waterLayerWidth = (dim - innerDim) / 2;
	float sqr = 0.0;
	if (image != NULL)
	{
		for (int j = 0; j < innerDim; j++)
		{
			for (int k = 0; k < innerDim; k++)
			{
				if (image->get(waterLayerWidth, j + waterLayerWidth, k + waterLayerWidth) == 0)
				{
					sqr += 1.0f;
				}
			}
		}
	}
	return (float)innerDim * innerDim / sqr;
}

bool OverdozenMicroperm::IsPore(const int x, const int y, const int z) const
{
	return image->get(x, y, z) == 0;
}

OverdozenMicroperm::OverdozenMicroperm(const char _flowDirectionAxis) : dim(0), innerDim(0),
																		image(NULL),
																		voxelDataX(NULL), voxelDataY(NULL), voxelDataZ(NULL), voxelDataP(NULL),
																		porosityX(0), porosityY(0), porosityZ(0), pressureCellsCount(0),
																		squareFactor(-1.0f), squareFactorInner(-1.0f),
																		flowDirectionAxis(_flowDirectionAxis)
{
}

OverdozenMicroperm::~OverdozenMicroperm(void)
{
	if (image != NULL)
	{
		delete image;
		image = NULL;
	}

	//if (voxelData != NULL)
	//{
	//	delete voxelData;
	//	voxelData = NULL;
	//}
}

bool OverdozenMicroperm::CheckSizeConstraint() const
{
	// TODO: Set max size as parameter of use system memory size
	return true; // dim <= MAX_IMAGE_SIZE;
}