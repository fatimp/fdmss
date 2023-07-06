#include "OverdozenPermsolver.h"
#include "AccuracyOrder.h"

#include <chrono>
#include <cmath>
#include <omp.h>

//extern void (*compFuncX[]) (int, int, int, Area3d<float>*, Area3d<float>*, Area3d<float>*, float, float);

extern float (*crtFuncX[])(int, int, int, Area3d<float> *, Area3d<float> *, float);
extern float (*crtFuncY[])(int, int, int, Area3d<float> *, Area3d<float> *, float);
extern float (*crtFuncZ[])(int, int, int, Area3d<float> *, Area3d<float> *, float);

bool OverdozenPermsolver::ReadFailo(const string &paramsFileName, const string &image3dFilename)
{
	printf("Reading input parameters... ");
	params->read(paramsFileName.c_str());
	printf("complete\n");
	// Set threads number here
	if (params->threadsNumber > 0)
	{
		omp_set_num_threads(params->threadsNumber);
	}
	OverdozenMicroperm *mp = NULL;
	switch (params->boundaryCondition)
	{
	case NOFLOW_BC:
		printf("Hardwall boundary condition is chosen\n");
		mp = new NfbcOverdozenMicroperm(params->flowDirectionAxis);
		printf("Reading 3D geometry... ");
		mp->ReadFailo(image3dFilename, 0U);
		break;
	case PERIODIC_BC:
	default:
		printf("Periodic boundary condition is chosen\n");
		mp = new PbcOverdozenMicroperm(params->flowDirectionAxis);
		printf("Reading 3D geometry... ");
		mp->ReadFailo(image3dFilename, params->waterLayerWidth);
		break;
		//case 1:
		//	mp = new FbcOverdozenMicroperm(ACCURACY_ORDER);
		//	break;
		//case 3:
		//	mp = new HorseBCOverdozenMicroperm(ACCURACY_ORDER);
		//	break;
	}

	printf("complete\n");
	squareFactor = mp->GetSquareFactor();
	printf("Dimension of image data = %d vx\n", mp->GetDimension());
	//squareFactorInner = mp->GetInnerSquareFactor(); [not used now]
	if (!mp->CheckSizeConstraint())
	{
		return false;
	}
	printf("Analyzing 3D geometry... ");
	voxelDataLengthX = mp->GetVoxelDataX(&voxelDataX);
	voxelDataLengthY = mp->GetVoxelDataY(&voxelDataY);
	voxelDataLengthZ = mp->GetVoxelDataZ(&voxelDataZ);
	voxelDataLengthP = mp->GetVoxelDataP(&voxelDataP);
	dim = mp->GetDimension() + 2 * ACCURACY_ORDER;
	params->pl = 1.0f + dim;
	params->pr = 1.0f;
	printf("complete\n");
	// Output an image for MathMod paper
	//int trgz = mp.dim / 2;
	//FILE *outStr = NULL, *outCmp = NULL;
	//fopen_s(&outStr, "str", "wb");
	//fopen_s(&outCmp, "cmp", "wb");
	//bool* cmpData = (bool*) calloc(mp.dim * mp.dim, sizeof(bool));
	//for (int vx = 0; vx < voxelDataLengthX; vx++)
	//{
	//	StuffedVoxel* sv = &voxelDataX[vx];
	//	if (sv->z == trgz)
	//	{
	//		cmpData[sv->x * mp.dim + sv->y] = true;
	//	}
	//}

	//printf("dim = %d\n", mp.dim);
	//for (int x = 0; x < mp.dim; x++)
	//{
	//	for (int y = 0; y < mp.dim; y++)
	//	{
	//		if (mp.image->periodicGet(x, y + 1, trgz + 1) != 0)
	//		{
	//			fputc(0, outStr);
	//			fputc(0, outCmp);
	//		}
	//		else
	//		{
	//			fputc(1, outStr);
	//			if (cmpData[x * mp.dim + y] == true)
	//			{
	//				fputc(2, outCmp);
	//			}
	//			else
	//			{
	//				fputc(1, outCmp);
	//			}
	//		}
	//	}
	//}
	//free(cmpData);
	//fclose(outStr);
	//fclose(outCmp);

	printf("Creating computational domain... ");
	xVals->resize(dim, dim, dim);
	yVals->resize(dim, dim, dim);
	zVals->resize(dim, dim, dim);
	pVals->resize(dim, dim, dim);
	printf("complete\n");
	return true;
}

void OverdozenPermsolver::printFieldsWithBorders()
{
	const char *fnames[] = {"velocities_i", "velocities_j", "velocities_k", "pressures"};
	ofstream *perms[] = {NULL, NULL, NULL, NULL};
	Area3d<float> *data[] = {xVals, yVals, zVals, pVals};

	for (int dm = 0; dm < 4; dm++)
	{
		perms[dm] = new ofstream(fnames[dm], ios::out | ios::binary);
	}
	if (!perms[0] || !perms[1] || !perms[2] || !perms[3])
	{
		return;
	}

	for (int dm = 0; dm < 4; dm++)
	{
		for (int x = 0; x < dim; x++)
		{
			for (int y = 0; y < dim; y++)
			{
				for (int z = 0; z < dim; z++)
				{
					float val = data[dm]->get(x, y, z);
					perms[dm]->write((char *)&val, sizeof(float));
				}
			}
		}
	}

	for (int dm = 0; dm < 4; dm++)
	{
		perms[dm]->close();
	}

	// Output abs values of velocities
	ofstream absvels("fullvels", ios::out | ios::binary);
	for (int x = 0; x < dim; x++)
	{
		for (int y = 0; y < dim; y++)
		{
			for (int z = 0; z < dim; z++)
			{
				float vx = xVals->get(x, y, z);
				float vy = xVals->get(x, y, z);
				float vz = xVals->get(x, y, z);
				float val = sqrtf(vx * vx + vy * vy + vz * vz);
				absvels.write((char *)&val, sizeof(float));
			}
		}
	}
	absvels.close();
}

void OverdozenPermsolver::printVelPrsFields()
{
	Area3d<float> *data[] = {xVals, yVals, zVals, pVals};
	const char *fnames[] = {
		VELOCITIES_X_FILENAME,
		VELOCITIES_Y_FILENAME,
		VELOCITIES_Z_FILENAME,
		PRESSURES_FILENAME,
		FULL_VELOCITIES_FILENAME};
	printFieldsImpl(data, fnames);
}

void OverdozenPermsolver::printVelPrsFieldsCustom(const char *fnames[])
{
	Area3d<float> *data[] = {xVals, yVals, zVals, pVals};
	printFieldsImpl(data, fnames);
}

//void OverdozenPermsolver::printFieldsWithoutWaterLayer()
//{
//	Area3d<float>* data[] = { xValsInner, yValsInner, zValsInner, pValsInner };
//	const char* fnames[] = { "velocities_i_inner", "velocities_j_inner", "velocities_k_inner", "pressures_inner", "fullvels_inner" };
//	printFieldsImpl(data, fnames);
//}

void OverdozenPermsolver::printFieldsImpl(Area3d<float> *data[], const char *fnames[])
{
	switch (params->boundaryCondition)
	{
	case PERIODIC_BC:
		printFieldsImplPbc(data, fnames);
		break;
	// Obsolete
	//case 1:
	//	printFieldsExFbc(data, fnames);
	//	break;
	case NOFLOW_BC:
		printFieldsImplNfbc(data, fnames);
		break;
	//case 3:
	//	printFieldsExHorseBC(data, fnames);
	//	break;
	default:
		printFieldsImplPbc(data, fnames);
		break;
	}
}

void OverdozenPermsolver::printFieldsImplPbc(Area3d<float> *data[], const char *fnames[])
{
	ofstream *perms[] = {NULL, NULL, NULL, NULL};

	for (int dm = 0; dm < 4; dm++)
	{
		perms[dm] = new ofstream(fnames[dm], ios::out | ios::binary);
	}
	if (!perms[0] || !perms[1] || !perms[2] || !perms[3])
	{
		return;
	}

	for (int z = ACCURACY_ORDER - 1; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER - 1; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER - 1; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float val = (data[0]->get(x, y, z) + data[0]->get(x + 1, y, z)) * 0.5f * params->resolution;
				perms[0]->write((char *)&val, sizeof(float));
			}
		}
	}

	for (int z = ACCURACY_ORDER - 1; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER - 1; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER - 1; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float val = (data[1]->get(x, y, z) + data[1]->get(x, y + 1, z)) * 0.5f * params->resolution;
				perms[1]->write((char *)&val, sizeof(float));
			}
		}
	}

	for (int z = ACCURACY_ORDER - 1; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER - 1; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER - 1; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float val = (data[2]->get(x, y, z) + data[2]->get(x, y, z + 1)) * 0.5f * params->resolution;
				perms[2]->write((char *)&val, sizeof(float));
			}
		}
	}

	for (int z = ACCURACY_ORDER - 1; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER - 1; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER - 1; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float val = data[3]->get(x, y, z) / params->resolution;
				perms[3]->write((char *)&val, sizeof(float));
			}
		}
	}

	for (int dm = 0; dm < 4; dm++)
	{
		perms[dm]->close();
	}

	// Output abs values of velocities
	ofstream absvels(fnames[4], ios::out | ios::binary);
	for (int z = ACCURACY_ORDER - 1; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER - 1; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER - 1; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float vx = (data[0]->get(x, y, z) + data[0]->get(x + 1, y, z)) * 0.5f * params->resolution;
				float vy = (data[1]->get(x, y, z) + data[1]->get(x, y + 1, z)) * 0.5f * params->resolution;
				float vz = (data[2]->get(x, y, z) + data[2]->get(x, y, z + 1)) * 0.5f * params->resolution;
				float val = sqrtf(vx * vx + vy * vy + vz * vz);
				absvels.write((char *)&val, sizeof(float));
			}
		}
	}
	absvels.close();
}

void OverdozenPermsolver::printFieldsImplNfbc(Area3d<float> *data[], const char *fnames[])
{
	ofstream *perms[] = {NULL, NULL, NULL, NULL};

	for (int dm = 0; dm < 4; dm++)
	{
		perms[dm] = new ofstream(fnames[dm], ios::out | ios::binary);
	}
	if (!perms[0] || !perms[1] || !perms[2] || !perms[3])
	{
		return;
	}

	for (int z = ACCURACY_ORDER; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float val = (data[0]->get(x, y, z) + data[0]->get(x + 1, y, z)) * 0.5f * params->resolution;
				perms[0]->write((char *)&val, sizeof(float));
			}
		}
	}

	for (int z = ACCURACY_ORDER; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float val = (data[1]->get(x, y, z) + data[1]->get(x, y + 1, z)) * 0.5f * params->resolution;
				perms[1]->write((char *)&val, sizeof(float));
			}
		}
	}

	for (int z = ACCURACY_ORDER; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float val = (data[2]->get(x, y, z) + data[2]->get(x, y, z + 1)) * 0.5f * params->resolution;
				perms[2]->write((char *)&val, sizeof(float));
			}
		}
	}

	for (int z = ACCURACY_ORDER; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float val = data[3]->get(x, y, z) / params->resolution;
				perms[3]->write((char *)&val, sizeof(float));
			}
		}
	}

	for (int dm = 0; dm < 4; dm++)
	{
		perms[dm]->close();
	}

	// Output abs values of velocities
	ofstream absvels(fnames[4], ios::out | ios::binary);
	for (int z = ACCURACY_ORDER; z < dim - ACCURACY_ORDER - 1; z++)
	{
		for (int y = ACCURACY_ORDER; y < dim - ACCURACY_ORDER - 1; y++)
		{
			for (int x = ACCURACY_ORDER; x < dim - ACCURACY_ORDER - 1; x++)
			{
				float vx = (data[0]->get(x, y, z) + data[0]->get(x + 1, y, z)) * 0.5f * params->resolution;
				float vy = (data[1]->get(x, y, z) + data[1]->get(x, y + 1, z)) * 0.5f * params->resolution;
				float vz = (data[2]->get(x, y, z) + data[2]->get(x, y, z + 1)) * 0.5f * params->resolution;
				float val = sqrtf(vx * vx + vy * vy + vz * vz);
				absvels.write((char *)&val, sizeof(float));
			}
		}
	}
	absvels.close();
}

//void OverdozenPermsolver::printFieldsExHorseBC(Area3d<float>* data[], const char* fnames[])
//{
//	ofstream* perms[] = { NULL, NULL, NULL, NULL };
//
//	for (int dm = 0; dm < 4; dm++)
//	{
//		perms[dm] = new ofstream(fnames[dm], ios::out | ios::binary);
//	}
//	if (!perms[0] || !perms[1] || !perms[2] || !perms[3])
//	{
//		return;
//	}
//
//	int boundaryLayerWidth = 2 * ACCURACY_ORDER;
//	for (int x = boundaryLayerWidth; x < dim - boundaryLayerWidth; x++)
//	{
//		for (int y = boundaryLayerWidth; y < dim - boundaryLayerWidth; y++)
//		{
//			for (int z = boundaryLayerWidth; z < dim - boundaryLayerWidth; z++)
//			{
//				float val = (data[0]->get(x, y, z) + data[0]->get(x + 1, y, z)) * 0.5;
//				perms[0]->write((char*)&val, sizeof(float));
//			}
//		}
//	}
//
//	for (int x = boundaryLayerWidth; x < dim - boundaryLayerWidth; x++)
//	{
//		for (int y = boundaryLayerWidth; y < dim - boundaryLayerWidth; y++)
//		{
//			for (int z = boundaryLayerWidth; z < dim - boundaryLayerWidth; z++)
//			{
//				float val = (data[1]->get(x, y, z) + data[1]->get(x, y + 1, z)) * 0.5;
//				perms[1]->write((char*)&val, sizeof(float));
//			}
//		}
//	}
//
//	for (int x = boundaryLayerWidth; x < dim - boundaryLayerWidth; x++)
//	{
//		for (int y = boundaryLayerWidth; y < dim - boundaryLayerWidth; y++)
//		{
//			for (int z = boundaryLayerWidth; z < dim - boundaryLayerWidth; z++)
//			{
//				float val = (data[2]->get(x, y, z) + data[2]->get(x, y, z + 1)) * 0.5;
//				perms[2]->write((char*)&val, sizeof(float));
//			}
//		}
//	}
//
//	for (int x = boundaryLayerWidth; x < dim - boundaryLayerWidth; x++)
//	{
//		for (int y = boundaryLayerWidth; y < dim - boundaryLayerWidth; y++)
//		{
//			for (int z = boundaryLayerWidth; z < dim - boundaryLayerWidth; z++)
//			{
//				float val = data[3]->get(x, y, z);
//				perms[3]->write((char*)&val, sizeof(float));
//			}
//		}
//	}
//
//
//	for (int dm = 0; dm < 4; dm++)
//	{
//		perms[dm]->close();
//	}
//
//	// Output abs values of velocities
//	ofstream absvels(fnames[4], ios::out | ios::binary);
//	for (int x = boundaryLayerWidth; x < dim - boundaryLayerWidth; x++)
//	{
//		for (int y = boundaryLayerWidth; y < dim - boundaryLayerWidth; y++)
//		{
//			for (int z = boundaryLayerWidth; z < dim - boundaryLayerWidth; z++)
//			{
//				float vx = data[0]->get(x, y, z);
//				float vy = data[1]->get(x, y, z);
//				float vz = data[2]->get(x, y, z);
//				float val = sqrtf(vx * vx + vy * vy + vz * vz);
//				absvels.write((char*)&val, sizeof(float));
//			}
//		}
//	}
//	absvels.close();
//}

void OverdozenPermsolver::initialize()
{
	xVals->clear();
	yVals->clear();
	zVals->clear();
	pVals->clear();

	printf("Initialization of pressure field... ");
	float pinc = (params->pl - params->pr) / (dim - 2.0f * ACCURACY_ORDER);

	switch (params->boundaryCondition)
	{
	case PERIODIC_BC:
	case NOFLOW_BC:
		// Periodic BC
		for (long idx = 0; idx < voxelDataLengthP; idx++)
		{
			StuffedVoxel *cvx = &voxelDataP[idx];
			float fi(0.0f);
			switch (params->flowDirectionAxis)
			{
			case 'y':
				fi = cvx->y + 1.0f;
				break;
			case 'z':
				fi = cvx->z + 1.0f;
				break;
			case 'x':
			default:
				fi = cvx->x + 1.0f;
				break;
			}
			float pd = params->pl - fi * pinc;
			pVals->set(cvx->x + ACCURACY_ORDER, cvx->y + ACCURACY_ORDER, cvx->z + ACCURACY_ORDER, pd);
		}
		break;
		//case 1:
		//case 3:
		//	// Free BC
		//	for (long idx = 0; idx < voxelDataLengthP; idx++)
		//	{
		//		StuffedVoxel* cvx = &voxelDataP[idx];
		//		float fi = cvx->x + 1.0f;
		//		float pd = params->pl - fi * pinc;
		//		pVals->set(cvx->x + ACCURACY_ORDER + 1, cvx->y + ACCURACY_ORDER, cvx->z + ACCURACY_ORDER, pd);
		//	}
		//	break;
	}

	switch (params->boundaryCondition)
	{
	case PERIODIC_BC:
	case NOFLOW_BC:
		// Periodic BC
		switch (params->flowDirectionAxis)
		{
		case 'y':
			for (int i = ACCURACY_ORDER - 1; i < dim - ACCURACY_ORDER; i++)
			{
				for (int k = ACCURACY_ORDER - 1; k < dim - ACCURACY_ORDER; k++)
				{
					pVals->set(i, ACCURACY_ORDER - 1, k, params->pl);
					pVals->set(i, dim - ACCURACY_ORDER - 1, k, params->pr);
				}
			}
			break;
		case 'z':
			for (int i = ACCURACY_ORDER - 1; i < dim - ACCURACY_ORDER; i++)
			{
				for (int j = ACCURACY_ORDER - 1; j < dim - ACCURACY_ORDER; j++)
				{
					pVals->set(i, j, ACCURACY_ORDER - 1, params->pl);
					pVals->set(i, j, dim - ACCURACY_ORDER - 1, params->pr);
				}
			}
			break;
		case 'x':
		default:
			for (int j = ACCURACY_ORDER - 1; j < dim - ACCURACY_ORDER; j++)
			{
				for (int k = ACCURACY_ORDER - 1; k < dim - ACCURACY_ORDER; k++)
				{
					pVals->set(ACCURACY_ORDER - 1, j, k, params->pl);
					pVals->set(dim - ACCURACY_ORDER - 1, j, k, params->pr);
				}
			}
			break;
		}
		break;
		//case 1:
		//case 3:
		//	// Free BC
		//	for (int j = ACCURACY_ORDER - 1; j < dim - ACCURACY_ORDER; j++)
		//	{
		//		for (int k = ACCURACY_ORDER - 1; k < dim - ACCURACY_ORDER; k++)
		//		{
		//			pVals->set(ACCURACY_ORDER, j, k, params->pl);
		//			pVals->set(dim - ACCURACY_ORDER, j, k, params->pr);
		//		}
		//	}
		//	break;
	}
	printf("complete\n");

	printf("Initialization of velocity field... ");
	float voxelVelocity = params->vinit / params->resolution;
	switch (params->flowDirectionAxis)
	{
	case 'y':
		for (long idx = 0; idx < voxelDataLengthY; idx++)
		{
			StuffedVoxel *cvx = &voxelDataY[idx];

			// Initialize start velocity
			if (voxelDataY[idx].compFuncPtr != NULL) //== pBalancedXPtr)
			{
				yVals->set(cvx->x + ACCURACY_ORDER, cvx->y + ACCURACY_ORDER, cvx->z + ACCURACY_ORDER, voxelVelocity);
			}
		}
		break;
	case 'z':
		for (long idx = 0; idx < voxelDataLengthZ; idx++)
		{
			StuffedVoxel *cvx = &voxelDataZ[idx];

			// Initialize start velocity
			if (voxelDataZ[idx].compFuncPtr != NULL) //== pBalancedXPtr)
			{
				zVals->set(cvx->x + ACCURACY_ORDER, cvx->y + ACCURACY_ORDER, cvx->z + ACCURACY_ORDER, voxelVelocity);
			}
		}
		break;
	case 'x':
	default:
		for (long idx = 0; idx < voxelDataLengthX; idx++)
		{
			StuffedVoxel *cvx = &voxelDataX[idx];

			// Initialize start velocity
			if (voxelDataX[idx].compFuncPtr != NULL) //== pBalancedXPtr)
			{
				xVals->set(cvx->x + ACCURACY_ORDER, cvx->y + ACCURACY_ORDER, cvx->z + ACCURACY_ORDER, voxelVelocity);
			}
		}
		break;
	}

	switch (params->boundaryCondition)
	{
	case PERIODIC_BC:
	case NOFLOW_BC:
		updateBoundaryElements(params->flowDirectionAxis);
		break;
		//case 1:
		//case 3:
		//	applyFreeBC_X(xVals);
		//	break;
	}
	printf("complete\n");

	//updateBoundaryElements(directionAxis);
}

void OverdozenPermsolver::updateBoundaryElements(const char directionAxis) // perbc in newperbc.f
{
	// ���� ��������� ���������� ��� ��������... ����� � �� �����������, ��
	Area3d<float> *vals = NULL;
	int isize = dim - 2 * ACCURACY_ORDER;
	switch (directionAxis)
	{
	case 'x':
		vals = xVals;
		break;
	case 'y':
		vals = yVals;
		break;
	case 'z':
		vals = zVals;
		break;
	default:
		return;
	}
	int irght = isize + 1;

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			int i1 = i;
			int j1 = j;

			i1 = i1 < ACCURACY_ORDER ? i1 + isize : i1;
			j1 = j1 < ACCURACY_ORDER ? j1 + isize : j1;
			i1 = i1 > irght ? i1 - isize : i1;
			j1 = j1 > irght ? j1 - isize : j1;
			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				vals->set(
					i, j, offset,
					vals->get(i1, j1, isize + offset));
				vals->set(
					i, j, dim - ACCURACY_ORDER + offset,
					vals->get(i1, j1, dim - ACCURACY_ORDER - isize + offset));
			}
		}
	}

	for (int i = 0; i < dim; i++)
	{
		for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
		{
			int i1 = i;

			i1 = i1 < ACCURACY_ORDER ? i1 + isize : i1;
			i1 = i1 > irght ? i1 - isize : i1;

			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				vals->set(i, offset, k, vals->get(i1, isize + offset, k));
				vals->set(i, dim - ACCURACY_ORDER + offset, k, vals->get(i1, dim - ACCURACY_ORDER - isize + offset, k));
			}
		}
	}

	for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
	{
		for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
		{
			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				vals->set(offset, j, k, vals->get(isize + offset, j, k));
				vals->set(dim - ACCURACY_ORDER + offset, j, k, vals->get(dim - ACCURACY_ORDER - isize + offset, j, k));
			}
		}
	}
}

void OverdozenPermsolver::printFields(float *v)
{
	float area = 1.0f / (dim - 2.0f * ACCURACY_ORDER) / (dim - 2.0f * ACCURACY_ORDER);
	float vx = 0.0f, px = 0.0f;

	for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
	{
		for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
		{
			vx += xVals->get(0, j, k);
			px += pVals->get(0, j, k);
		}
	}

	vx *= area;
	px *= area;

	FILE *perm = fopen(cmdline_params->compLogFileName, "at");
	FILE *press = fopen("press256", "at");
	if (perm == NULL && press == NULL)
	{
		printf("Couldn't open output files");
		return;
	}

	fprintf(perm, "%6.9f\n", vx);
	fprintf(press, "%6.9f\n", px);
	fclose(perm);
	fclose(press);
	*v = vx;
}

void OverdozenPermsolver::printFieldsIndexed(float *v)
{
	float area = 1.0f / (dim - 2.0f * ACCURACY_ORDER) / (dim - 2.0f * ACCURACY_ORDER);

	for (int layerIdx = 0; layerIdx < continueVelsCount; layerIdx++)
	{
		int layer = velocityComputationIndices[layerIdx];
		float vx = 0.0f;
		for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
		{
			for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
			{
				vx += xVals->get(layer, j, k);
			}
		}
		v[layerIdx] = vx * area;
	}

	FILE *perm = fopen(cmdline_params->compLogFileName, "at");
	if (perm == NULL)
	{
		printf("Could'n open output file");
		return;
	}

	fprintf(perm, "%6.9f\n", v[0]);
	fclose(perm);
}

// Returns average X-velocity
float OverdozenPermsolver::printFieldsAlles(float *v)
{
	int wtr = int(params->waterLayerWidth);
	float area = 1.0f /
				 (dim - 2.0f * (ACCURACY_ORDER + wtr)) /
				 (dim - 2.0f * (ACCURACY_ORDER + wtr));
	float avgVelocity = 0.0f;

	switch (params->flowDirectionAxis)
	{
	case 'y':
		for (int layer = ACCURACY_ORDER - 1 + wtr; layer < dim - ACCURACY_ORDER - 1 - wtr; layer++)
		{
			float vy = 0.0f;
			for (int i = ACCURACY_ORDER - 1 + wtr; i < dim - ACCURACY_ORDER - 1 - wtr; i++)
			{
				for (int k = ACCURACY_ORDER - 1 + wtr; k < dim - ACCURACY_ORDER - 1 - wtr; k++)
				{
					vy += 0.5f * (yVals->get(i, layer, k) + yVals->get(i, layer + 1, k));
				}
			}
			v[layer - ACCURACY_ORDER + 1] = vy * area;
			avgVelocity += v[layer - ACCURACY_ORDER + 1];
		}
		break;
	case 'z':
		for (int layer = ACCURACY_ORDER - 1 + wtr; layer < dim - ACCURACY_ORDER - 1 - wtr; layer++)
		{
			float vz = 0.0f;
			for (int i = ACCURACY_ORDER - 1 + wtr; i < dim - ACCURACY_ORDER - 1 - wtr; i++)
			{
				for (int j = ACCURACY_ORDER - 1 + wtr; j < dim - ACCURACY_ORDER - 1 - wtr; j++)
				{
					vz += 0.5f * (zVals->get(i, j, layer) + zVals->get(i, j, layer + 1));
				}
			}
			v[layer - ACCURACY_ORDER + 1] = vz * area;
			avgVelocity += v[layer - ACCURACY_ORDER + 1];
		}
		break;
	case 'x':
	default:
		for (int layer = ACCURACY_ORDER - 1 + wtr; layer < dim - ACCURACY_ORDER - 1 - wtr; layer++)
		{
			float vx = 0.0f;
			for (int j = ACCURACY_ORDER - 1 + wtr; j < dim - ACCURACY_ORDER - 1 - wtr; j++)
			{
				for (int k = ACCURACY_ORDER - 1 + wtr; k < dim - ACCURACY_ORDER - 1 - wtr; k++)
				{
					vx += 0.5f * (xVals->get(layer, j, k) + xVals->get(layer + 1, j, k));
				}
			}
			v[layer - ACCURACY_ORDER + 1] = vx * area;
			avgVelocity += v[layer - ACCURACY_ORDER + 1];
		}
		break;
	}

	avgVelocity /= (float)(dim - 2 * (ACCURACY_ORDER + wtr));

	FILE *perm = fopen(cmdline_params->compLogFileName, "at");
	if (perm == NULL)
	{
		printf("Could'n open output file");
		return 0.0f;
	}

	permeability = avgVelocity * params->rre * params->resolution * params->resolution;

	fprintf(perm, "%6.9f\t%6.9f\t%6.9f\n", permeability, permeability * MILLIDARCY_CONVERT_RATE, GetAugeCriterionError());
	fclose(perm);
	return avgVelocity;
}

// Returns average X-velocity, ignores redundant boundary layers
float OverdozenPermsolver::printFieldsAllesNoFlowBC(float *v)
{
	float area = 1.0f / (dim - 2.0f * ACCURACY_ORDER - 1) / (dim - 2.0f * ACCURACY_ORDER - 1);
	float avgVelocity = 0.0f;

	switch (params->flowDirectionAxis)
	{
	case 'y':
		for (int layer = ACCURACY_ORDER; layer < dim - ACCURACY_ORDER - 1; layer++)
		{
			float vy = 0.0f;
			for (int i = ACCURACY_ORDER; i < dim - ACCURACY_ORDER - 1; i++)
			{
				for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER - 1; k++)
				{
					vy += 0.5f * (yVals->get(i, layer, k) + yVals->get(i, layer + 1, k));
				}
			}
			v[layer - ACCURACY_ORDER] = vy * area;
			avgVelocity += v[layer - ACCURACY_ORDER];
		}
		break;
	case 'z':
		for (int layer = ACCURACY_ORDER; layer < dim - ACCURACY_ORDER - 1; layer++)
		{
			float vz = 0.0f;
			for (int i = ACCURACY_ORDER; i < dim - ACCURACY_ORDER - 1; i++)
			{
				for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER - 1; j++)
				{
					vz += 0.5f * (zVals->get(i, j, layer) + zVals->get(i, j, layer + 1));
				}
			}
			v[layer - ACCURACY_ORDER] = vz * area;
			avgVelocity += v[layer - ACCURACY_ORDER];
		}
		break;
		break;
	case 'x':
	default:
		for (int layer = ACCURACY_ORDER; layer < dim - ACCURACY_ORDER - 1; layer++)
		{
			float vx = 0.0f;
			for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER - 1; j++)
			{
				for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER - 1; k++)
				{
					vx += 0.5f * (xVals->get(layer, j, k) + xVals->get(layer + 1, j, k));
				}
			}
			v[layer - ACCURACY_ORDER] = vx * area;
			avgVelocity += v[layer - ACCURACY_ORDER];
		}
		break;
	}
	avgVelocity /= (float)(dim - 2 * ACCURACY_ORDER - 1);

	FILE *perm = fopen(cmdline_params->compLogFileName, "at");
	if (perm == NULL)
	{
		printf("Could'n open output file");
		return 0.0f;
	}

	//fprintf(perm, "%6.9f\t%6.9f\t%6.9f\t%6.9f\n", avgVelocity, GetAugeCriterionErrorV1(), GetAugeCriterionErrorV2(), GetErrorMostaghimiStyle());
	permeability = avgVelocity * params->rre * params->resolution * params->resolution;
	fprintf(perm, "%6.9f\t%6.9f\t%6.9f\n", permeability, permeability * MILLIDARCY_CONVERT_RATE, GetAugeCriterionError());
	fclose(perm);
	return avgVelocity;
}

// Returns average X-velocity, ignores redundant boundary layers
float OverdozenPermsolver::printFieldsAllesHorseBC(float *v)
{
	float area = 1.0f / (dim - 4.0f * ACCURACY_ORDER) / (dim - 4.0f * ACCURACY_ORDER);
	float avgVelocity = 0.0f;

	int boundaryLayerWidth = 2 * ACCURACY_ORDER;
	for (int layer = boundaryLayerWidth; layer < dim - boundaryLayerWidth; layer++)
	{
		float vx = 0.0f;
		for (int j = boundaryLayerWidth; j < dim - boundaryLayerWidth; j++)
		{
			for (int k = boundaryLayerWidth; k < dim - boundaryLayerWidth; k++)
			{
				vx += xVals->get(layer, j, k);
			}
		}
		v[layer - boundaryLayerWidth] = vx * area;
		avgVelocity += v[layer - boundaryLayerWidth];
	}
	avgVelocity /= (float)(dim - 2 * boundaryLayerWidth);

	FILE *perm = fopen(cmdline_params->compLogFileName, "at");
	if (perm == NULL)
	{
		printf("Could'n open output file");
		return 0.0f;
	}

	fprintf(perm, "%6.9f\n", avgVelocity);
	fclose(perm);
	return avgVelocity;
}

void OverdozenPermsolver::printFieldsAlles3dir(float *v)
{
	float area = 1.0f / (dim - 2.0f * ACCURACY_ORDER) / (dim - 2.0f * ACCURACY_ORDER);
	// X velocities
	for (int layer = ACCURACY_ORDER; layer < dim - ACCURACY_ORDER; layer++)
	{
		float vx = 0.0f;
		for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
		{
			for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
			{
				vx += xVals->get(layer, j, k);
			}
		}
		v[layer - ACCURACY_ORDER] = vx * area;
	}

	// Y velocities
	int offset = dim - 2 * ACCURACY_ORDER;
	for (int layer = ACCURACY_ORDER; layer < dim - ACCURACY_ORDER; layer++)
	{
		float vy = 0.0f;
		for (int i = ACCURACY_ORDER; i < dim - ACCURACY_ORDER; i++)
		{
			for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
			{
				vy += yVals->get(i, layer, k);
			}
		}
		v[layer - ACCURACY_ORDER + offset] = vy * area;
	}

	// Z velocities
	offset *= 2;
	for (int layer = ACCURACY_ORDER; layer < dim - ACCURACY_ORDER; layer++)
	{
		float vz = 0.0f;
		for (int i = ACCURACY_ORDER; i < dim - ACCURACY_ORDER; i++)
		{
			for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
			{
				vz += zVals->get(i, j, layer);
			}
		}
		v[layer - ACCURACY_ORDER + offset] = vz * area;
	}

	FILE *perm = fopen(cmdline_params->compLogFileName, "at");
	if (perm == NULL)
	{
		printf("Could'n open output file");
		return;
	}

	fprintf(perm, "%6.9f\n", v[0]);
	fclose(perm);
}

void OverdozenPermsolver::outputComputedVelocities()
{
	FILE *perm = fopen(cmdline_params->compVelsFileName, "wt");
	if (perm == NULL)
	{
		printf("Could'n open output file");
		return;
	}

	for (int idx = 0; idx < continueVelsCount; idx++)
	{
		fprintf(perm, "%6.9f\n", continueVelsCurr[idx]);
	}
	fclose(perm);
}

void OverdozenPermsolver::outputComputedVelocitiesNoFlowBC()
{
	FILE *perm = fopen(COMPUTED_VELOCITIES_FILE_NAME, "wt");
	if (perm == NULL)
	{
		printf("Could'n open output file");
		return;
	}

	for (int idx = 0; idx < continueVelsCount - 1; idx++)
	{
		fprintf(perm, "%6.9f\n", continueVelsCurr[idx]);
	}
	fclose(perm);
}

void OverdozenPermsolver::outputComputedVelocitiesHorseBC()
{
	FILE *perm = fopen(COMPUTED_VELOCITIES_FILE_NAME, "wt");
	if (perm == NULL)
	{
		printf("Could'n open output file");
		return;
	}

	for (int idx = 0; idx < continueVelsCount - 2 * ACCURACY_ORDER; idx++)
	{
		fprintf(perm, "%6.9f\n", continueVelsCurr[idx]);
	}
	fclose(perm);
}

bool OverdozenPermsolver::shouldContinue()
{
	float crtError = 0.0f;

	switch (params->terminationCondition)
	{
	case ERROR_CONVERGES:
	{
		// �������� ������ ������������� ������ �� ��������,
		// �������� �� � ������
		errorSmoothingArray[errorSmoothingArrayWritePosition] = GetAugeCriterionError();
		errorSmoothingArrayWritePosition++;
		if (errorSmoothingArrayWritePosition >= params->errorSmoothingArrayLength)
		{
			errorSmoothingArrayFull = true;
			errorSmoothingArrayWritePosition = 0;
		}

		// ����� ��������, ���� ������ �� ��������,
		// �.�. ������ errorSmoothingArrayLength �������� ��� �� ������
		if (errorSmoothingArrayFull == false)
		{
			return true;
		}

		// ��������� ���������� ������ �� ��������
		// �� ��������� errorSmoothingArrayLength ��������
		float currCriterionErrorValue = 0.0f;
		for (unsigned int i = 0; i < params->errorSmoothingArrayLength; i++)
		{
			currCriterionErrorValue += errorSmoothingArray[i];
		}
		currCriterionErrorValue /= params->errorSmoothingArrayLength;

		if (prevCriterionErrorValue == -1.0f)
		{
			//printf("*** TRACE *** first iteration\n");
			prevCriterionErrorValue = currCriterionErrorValue;
			return true;
		}
		else
		{
			float diff = abs((currCriterionErrorValue - prevCriterionErrorValue) / currCriterionErrorValue);
			if (diff > params->tolerance)
			{
				//printf("\n*** TRACE ***\tdiff = %.4f; tolerance = %.4f computation continues\n", diff, params->tolerance);
				prevCriterionErrorValue = currCriterionErrorValue;
				return true;
			}
			//printf("*** TRACE ***\tdiff = %.4f; tolerance = %.4f computation is being terminated\n", diff, params->tolerance);
			//int i = getchar();
			return false;
		}
	}
	case ERROR_DOESNT_EXCEED:
		crtError = GetAugeCriterionError();
		return crtError > params->tolerance;
	case SOLUTION_CONVERGES:
	default:
		for (int valueIndex = 0; valueIndex < continueVelsCount; valueIndex++)
		{
			float diff = abs((continueVelsCurr[valueIndex] - continueVelsPrev[valueIndex]) / continueVelsCurr[valueIndex]);
			if (diff > params->tolerance)
			{
				return true;
			}
		}
		return false;
	}
}

void OverdozenPermsolver::updateVelocities(const char directionAxis)
{
	float timeStep = params->dt;
	float revReynoldsNum = params->rre;

	switch (directionAxis)
	{
	case 'x':
#pragma omp parallel for schedule(static)
		for (int vx = 0; vx < voxelDataLengthX; vx++)
		{
			StuffedVoxel *sv = &voxelDataX[vx];
			void (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float) = sv->compFuncPtr;
			if (funcPtr != NULL)
			{
				funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, xVals, xVals, pVals, timeStep, revReynoldsNum);
			}
		}

		switch (params->boundaryCondition)
		{
		case PERIODIC_BC:
		case NOFLOW_BC:
			applyPeriodicBC(xVals);
			break;
			//case 1:
			//case 3:
			//	applyFreeBC_X(xVals);
			//	break;
		}
		break;
	case 'y':
#pragma omp parallel for schedule(static)
		for (int vx = 0; vx < voxelDataLengthY; vx++)
		{
			StuffedVoxel *sv = &voxelDataY[vx];
			void (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float) = sv->compFuncPtr;
			if (funcPtr != NULL)
			{
				funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, yVals, yVals, pVals, timeStep, revReynoldsNum);
			}
		}

		switch (params->boundaryCondition)
		{
		case PERIODIC_BC:
		case NOFLOW_BC:
			applyPeriodicBC(yVals);
			break;
			//case 1:
			//case 3:
			//	applyFreeBC_Y(yVals);
			//	break;
		}
		break;
	case 'z':
#pragma omp parallel for schedule(static)
		for (int vx = 0; vx < voxelDataLengthZ; vx++)
		{
			StuffedVoxel *sv = &voxelDataZ[vx];
			void (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float) = sv->compFuncPtr;
			if (funcPtr != NULL)
			{
				funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, zVals, zVals, pVals, timeStep, revReynoldsNum);
			}
		}

		switch (params->boundaryCondition)
		{
		case PERIODIC_BC:
		case NOFLOW_BC:
			applyPeriodicBC(zVals);
			break;
			//case 1:
			//case 3:
			//	applyFreeBC_Z(zVals);
			//	break;
		}
		break;
	default:
		return;
	}

	//applyPeriodicBC();
}

void OverdozenPermsolver::applyFreeBC_X(Area3d<float> *buff)
{
	int isize = dim - 2 * ACCURACY_ORDER;
	int irght = isize + ACCURACY_ORDER - 1;

#pragma omp parallel for schedule(static)
	for (int offset = 0; offset < ACCURACY_ORDER; offset++)
	{
		for (int j = 0; j < dim; j++)
		{
			for (int i = 0; i < dim; i++)
			{
				buff->set(i, j, offset, buff->get(i, j, ACCURACY_ORDER));
				buff->set(i, j, dim - ACCURACY_ORDER + offset, buff->get(i, j, dim - ACCURACY_ORDER - 1));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int offset = 0; offset < ACCURACY_ORDER; offset++)
		{
			for (int i = 0; i < dim; i++)
			{
				buff->set(i, offset, k, buff->get(i, ACCURACY_ORDER, k));
				buff->set(i, dim - ACCURACY_ORDER + offset, k, buff->get(i, dim - ACCURACY_ORDER - 1, k));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
		{
			for (int offset = 0; offset < ACCURACY_ORDER + 1; offset++)
			{
				buff->set(offset, j, k, buff->get(ACCURACY_ORDER + 1, j, k));
			}

			for (int offset = 0; offset < ACCURACY_ORDER - 1; offset++)
			{
				buff->set(dim - ACCURACY_ORDER + 1 + offset, j, k, buff->get(dim - ACCURACY_ORDER, j, k));
			}
		}
	}
}

void OverdozenPermsolver::applyFreeBC_Y(Area3d<float> *buff)
{
	int isize = dim - 2 * ACCURACY_ORDER;
	int irght = isize + ACCURACY_ORDER - 1;

#pragma omp parallel for schedule(static)
	for (int offset = 0; offset < ACCURACY_ORDER; offset++)
	{
		for (int j = 0; j < dim; j++)
		{
			for (int i = 0; i < dim; i++)
			{
				buff->set(i, j, offset, buff->get(i, j, ACCURACY_ORDER));
				buff->set(i, j, dim - ACCURACY_ORDER + offset, buff->get(i, j, dim - ACCURACY_ORDER - 1));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int offset = 0; offset < ACCURACY_ORDER + 1; offset++)
		{
			for (int i = 0; i < dim; i++)
			{
				buff->set(i, offset, k, buff->get(i, ACCURACY_ORDER + 1, k));
			}
		}

		for (int offset = 0; offset < ACCURACY_ORDER - 1; offset++)
		{
			for (int i = 0; i < dim; i++)
			{
				buff->set(i, dim - ACCURACY_ORDER + 1 + offset, k, buff->get(i, dim - ACCURACY_ORDER, k));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
		{
			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				buff->set(offset, j, k, buff->get(ACCURACY_ORDER, j, k));
			}

			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				buff->set(dim - ACCURACY_ORDER + offset, j, k, buff->get(dim - ACCURACY_ORDER - 1, j, k));
			}
		}
	}
}

void OverdozenPermsolver::applyFreeBC_Z(Area3d<float> *buff)
{
	int isize = dim - 2 * ACCURACY_ORDER;
	int irght = isize + ACCURACY_ORDER - 1;

#pragma omp parallel for schedule(static)
	for (int offset = 0; offset < ACCURACY_ORDER + 1; offset++)
	{
		for (int j = 0; j < dim; j++)
		{
			for (int i = 0; i < dim; i++)
			{
				buff->set(i, j, offset, buff->get(i, j, ACCURACY_ORDER + 1));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int offset = 0; offset < ACCURACY_ORDER - 1; offset++)
	{
		for (int j = 0; j < dim; j++)
		{
			for (int i = 0; i < dim; i++)
			{
				buff->set(i, j, dim - ACCURACY_ORDER + 1 + offset, buff->get(i, j, dim - ACCURACY_ORDER));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int offset = 0; offset < ACCURACY_ORDER; offset++)
		{
			for (int i = 0; i < dim; i++)
			{
				buff->set(i, offset, k, buff->get(i, ACCURACY_ORDER, k));
				buff->set(i, dim - ACCURACY_ORDER + offset, k, buff->get(i, dim - ACCURACY_ORDER - 1, k));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
		{
			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				buff->set(offset, j, k, buff->get(ACCURACY_ORDER, j, k));
				buff->set(dim - ACCURACY_ORDER + offset, j, k, buff->get(dim - ACCURACY_ORDER - 1, j, k));
			}
		}
	}
}

void OverdozenPermsolver::applyPeriodicBC(Area3d<float> *buff)
{
	int isize = dim - 2 * ACCURACY_ORDER;
	int irght = isize + ACCURACY_ORDER - 1;

#pragma omp parallel for schedule(static)
	for (int offset = 0; offset < ACCURACY_ORDER; offset++)
	{
		for (int j = 0; j < dim; j++)
		{
			for (int i = 0; i < dim; i++)
			{
				int i1 = i, j1 = j;
				i1 = i1 < ACCURACY_ORDER ? i1 + isize : i1;
				j1 = j1 < ACCURACY_ORDER ? j1 + isize : j1;
				i1 = i1 > irght ? i1 - isize : i1;
				j1 = j1 > irght ? j1 - isize : j1;

				buff->set(i, j, offset, buff->get(i1, j1, isize + offset));
				buff->set(i, j, dim - ACCURACY_ORDER + offset, buff->get(i1, j1, dim - ACCURACY_ORDER - isize + offset));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int offset = 0; offset < ACCURACY_ORDER; offset++)
		{
			for (int i = 0; i < dim; i++)
			{
				int i1 = i;
				i1 = i1 < ACCURACY_ORDER ? i1 + isize : i1;
				i1 = i1 > irght ? i1 - isize : i1;

				buff->set(i, offset, k, buff->get(i1, isize + offset, k));
				buff->set(i, dim - ACCURACY_ORDER + offset, k, buff->get(i1, dim - ACCURACY_ORDER + offset - isize, k));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int j = ACCURACY_ORDER; j < dim - ACCURACY_ORDER; j++)
		{
			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				buff->set(offset, j, k, buff->get(isize + offset, j, k));
				buff->set(dim - ACCURACY_ORDER + offset, j, k, buff->get(dim - ACCURACY_ORDER + offset - isize, j, k));
			}
		}
	}
}

void OverdozenPermsolver::applyFreeBCforPrs(Area3d<float> *buff)
{
	int isize = dim - 2 * ACCURACY_ORDER;
	int irght = isize + 1;

	float pinc = (params->pl - params->pr) / (dim - 2.0f * ACCURACY_ORDER);

#pragma omp parallel for schedule(static)
	for (int j = 0; j < dim; j++)
	{
		for (int i = ACCURACY_ORDER; i <= dim - ACCURACY_ORDER; i++)
		{
			float fi = float(i - ACCURACY_ORDER);
			float pd = params->pl - fi * pinc;
			pVals->set(i, j, dim - ACCURACY_ORDER, pd);
		}
	}

#pragma omp parallel for schedule(static)
	for (int j = 0; j < dim; j++)
	{
		for (int i = ACCURACY_ORDER; i <= dim - ACCURACY_ORDER; i++)
		{
			float fi = float(i - ACCURACY_ORDER);
			float pd = params->pl - fi * pinc;
			pVals->set(i, j, ACCURACY_ORDER, pd);
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = 0; k < dim; k++)
	{
		for (int i = ACCURACY_ORDER; i <= dim - ACCURACY_ORDER; i++)
		{
			float fi = float(i - ACCURACY_ORDER);
			float pd = params->pl - fi * pinc;

			pVals->set(i, dim - ACCURACY_ORDER, k, pd);
		}

		for (int i = ACCURACY_ORDER; i <= dim - ACCURACY_ORDER; i++)
		{
			float fi = float(i - ACCURACY_ORDER);
			float pd = params->pl - fi * pinc;

			pVals->set(i, ACCURACY_ORDER, k, pd);
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = 0; k < dim; k++)
	{
		for (int j = 0; j < dim; j++)
		{
			pVals->set(dim - ACCURACY_ORDER, j, k, params->pr);
			pVals->set(ACCURACY_ORDER, j, k, params->pl);
		}
	}
}

void OverdozenPermsolver::applyPeriodicBCforPrs(Area3d<float> *buff)
{
	switch (params->flowDirectionAxis)
	{
	case 'y':
		applyPeriodicBCforPrs_FlowY(buff);
		break;
	case 'z':
		applyPeriodicBCforPrs_FlowZ(buff);
		break;
	case 'x':
	default:
		applyPeriodicBCforPrs_FlowX(buff);
		break;
	}
}

void OverdozenPermsolver::applyPeriodicBCforPrs_FlowX(Area3d<float> *buff)
{
	int isize = dim - 2 * ACCURACY_ORDER;
	int irght = isize + 1;

	//#pragma omp parallel for schedule(static)
	//for (int k = 0; k < dim; k++)
	//{
	//	for (int j = 0; j < dim; j++)
	//	{
	//		for (int offset = 0; offset < ACCURACY_ORDER - 1; offset++)
	//		{
	//			float delta = buff->get(isize - 1 + offset, j, k) - buff->get(isize + offset, j, k);
	//			buff->set(offset, j, k, buff->get(offset + 1, j, k) + delta);
	//		}

	//		for (int offset = 0; offset < ACCURACY_ORDER; offset++)
	//		{
	//			float delta = buff->get(ACCURACY_ORDER + offset + 1, j, k) - buff->get(ACCURACY_ORDER + offset, j, k);
	//			buff->set(dim - ACCURACY_ORDER + offset, j, k, buff->get(dim - ACCURACY_ORDER + offset - 1, j, k) + delta);
	//		}
	//	}
	//}

#pragma omp parallel for schedule(static)
	for (int j = 0; j < dim; j++)
	{
		for (int i = 0; i < dim; i++)
		{
			int i1 = i, j1 = j;
			i1 = i1 < ACCURACY_ORDER ? i1 + isize : i1;
			j1 = j1 < ACCURACY_ORDER ? j1 + isize : j1;
			i1 = i1 > irght ? i1 - isize : i1;
			j1 = j1 > irght ? j1 - isize : j1;

			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				if (offset < ACCURACY_ORDER - 1)
				{
					buff->set(i, j, offset, buff->get(i1, j1, isize + offset));
				}
				buff->set(i, j, dim - ACCURACY_ORDER + offset, buff->get(i1, j1, dim - ACCURACY_ORDER - isize + offset));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int i = 0; i < dim; i++)
		{
			int i1 = i;
			i1 = i1 < ACCURACY_ORDER ? i1 + isize : i1;
			i1 = i1 > irght ? i1 - isize : i1;

			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				if (offset < ACCURACY_ORDER - 1)
				{
					buff->set(i, offset, k, buff->get(i1, isize + offset, k));
				}
				buff->set(i, dim - ACCURACY_ORDER + offset, k, buff->get(i1, dim - ACCURACY_ORDER + offset - isize, k));
			}
		}
	}
}

void OverdozenPermsolver::applyPeriodicBCforPrs_FlowY(Area3d<float> *buff)
{
	int isize = dim - 2 * ACCURACY_ORDER;
	int irght = isize + 1;

#pragma omp parallel for schedule(static)
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			int i1 = i, j1 = j;
			i1 = i1 < ACCURACY_ORDER ? i1 + isize : i1;
			j1 = j1 < ACCURACY_ORDER ? j1 + isize : j1;
			i1 = i1 > irght ? i1 - isize : i1;
			j1 = j1 > irght ? j1 - isize : j1;

			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				if (offset < ACCURACY_ORDER - 1)
				{
					buff->set(i, j, offset, buff->get(i1, j1, isize + offset));
				}
				buff->set(i, j, dim - ACCURACY_ORDER + offset, buff->get(i1, j1, dim - ACCURACY_ORDER - isize + offset));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int k = ACCURACY_ORDER; k < dim - ACCURACY_ORDER; k++)
	{
		for (int j = 0; j < dim; j++)
		{
			int j1 = j;
			j1 = j1 < ACCURACY_ORDER ? j1 + isize : j1;
			j1 = j1 > irght ? j1 - isize : j1;

			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				if (offset < ACCURACY_ORDER - 1)
				{
					buff->set(offset, j, k, buff->get(isize + offset, j1, k));
				}
				buff->set(dim - ACCURACY_ORDER + offset, j, k, buff->get(dim - ACCURACY_ORDER + offset - isize, j1, k));
			}
		}
	}
}

void OverdozenPermsolver::applyPeriodicBCforPrs_FlowZ(Area3d<float> *buff)
{
	int isize = dim - 2 * ACCURACY_ORDER;
	int irght = isize + 1;

#pragma omp parallel for schedule(static)
	for (int j = 0; j < dim; j++)
	{
		for (int k = 0; k < dim; k++)
		{
			int k1 = k, j1 = j;
			k1 = k1 < ACCURACY_ORDER ? k1 + isize : k1;
			j1 = j1 < ACCURACY_ORDER ? j1 + isize : j1;
			k1 = k1 > irght ? k1 - isize : k1;
			j1 = j1 > irght ? j1 - isize : j1;

			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				if (offset < ACCURACY_ORDER - 1)
				{
					buff->set(offset, j, k, buff->get(isize + offset, j1, k1));
				}
				buff->set(dim - ACCURACY_ORDER + offset, j, k, buff->get(dim - ACCURACY_ORDER - isize + offset, j1, k1));
			}
		}
	}

#pragma omp parallel for schedule(static)
	for (int i = ACCURACY_ORDER; i < dim - ACCURACY_ORDER; i++)
	{
		for (int k = 0; k < dim; k++)
		{
			int k1 = k;
			k1 = k1 < ACCURACY_ORDER ? k1 + isize : k1;
			k1 = k1 > irght ? k1 - isize : k1;

			for (int offset = 0; offset < ACCURACY_ORDER; offset++)
			{
				if (offset < ACCURACY_ORDER - 1)
				{
					buff->set(i, offset, k, buff->get(i, isize + offset, k1));
				}
				buff->set(i, dim - ACCURACY_ORDER + offset, k, buff->get(i, dim - ACCURACY_ORDER + offset - isize, k1));
			}
		}
	}
}

void OverdozenPermsolver::updateVelocities()
{
	static const char tab[3] = {'x', 'y', 'z'};
	for (int axisIndex = 0; axisIndex < 3; axisIndex++)
	{
		updateVelocities(tab[axisIndex]);
	}
}

void OverdozenPermsolver::updatePressures()
{
#pragma omp parallel for schedule(static)
	for (int vx = 0; vx < voxelDataLengthP; vx++)
	{
		StuffedVoxel *sv = &voxelDataP[vx];
		int x = sv->x + ACCURACY_ORDER,
			y = sv->y + ACCURACY_ORDER,
			z = sv->z + ACCURACY_ORDER;

		float dot = -params->dtc2 * (xVals->get(x + 1, y, z) - xVals->get(x, y, z) +
									 yVals->get(x, y + 1, z) - yVals->get(x, y, z) +
									 zVals->get(x, y, z + 1) - zVals->get(x, y, z));

		pVals->inplace_add(x, y, z, dot);
	}

	// Variant for periodic BC
	//#pragma omp parallel for schedule(static)
	//for (int z = ACCURACY_ORDER - 1; z < dim - ACCURACY_ORDER; z++)
	//{
	//	for (int j = ACCURACY_ORDER - 1; j < dim - ACCURACY_ORDER; j++)
	//	{
	//		float dot = -params->dtc2 * (
	//			xVals->get(ACCURACY_ORDER, j, z) - xVals->get(ACCURACY_ORDER - 1, j, z) +
	//			yVals->get(ACCURACY_ORDER - 1, j + 1, z) - yVals->get(ACCURACY_ORDER - 1, j, z) +
	//			zVals->get(ACCURACY_ORDER - 1, j, z + 1) - zVals->get(ACCURACY_ORDER - 1, j, z));

	//		pVals->set(ACCURACY_ORDER - 1, j, z, pVals->get(ACCURACY_ORDER - 1, j, z) + dot);
	//		pVals->set(dim - ACCURACY_ORDER - 1, j, z, pVals->get(dim - ACCURACY_ORDER - 1, j, z) + dot);
	//	}
	//}

	// Variant for free BC
	//#pragma omp parallel for schedule(static)
	//for (int z = ACCURACY_ORDER; z <= dim - ACCURACY_ORDER; z++)
	//{
	//	for (int j = ACCURACY_ORDER; j <= dim - ACCURACY_ORDER; j++)
	//	{
	//		float dot = -params->dtc2 * (
	//			xVals->get(ACCURACY_ORDER + 1, j, z) - xVals->get(ACCURACY_ORDER, j, z) +
	//			yVals->get(ACCURACY_ORDER, j + 1, z) - yVals->get(ACCURACY_ORDER, j, z) +
	//			zVals->get(ACCURACY_ORDER, j, z + 1) - zVals->get(ACCURACY_ORDER, j, z));

	//		pVals->set(ACCURACY_ORDER, j, z, pVals->get(ACCURACY_ORDER, j, z) + dot);

	//		dot = -params->dtc2 * (
	//			xVals->get(dim - ACCURACY_ORDER + 1, j, z) - xVals->get(dim - ACCURACY_ORDER, j, z) +
	//			yVals->get(dim - ACCURACY_ORDER, j + 1, z) - yVals->get(dim - ACCURACY_ORDER, j, z) +
	//			zVals->get(dim - ACCURACY_ORDER, j, z + 1) - zVals->get(dim - ACCURACY_ORDER, j, z));

	//		pVals->set(dim - ACCURACY_ORDER, j, z, pVals->get(dim - ACCURACY_ORDER, j, z) + dot);
	//	}
	//}
}

void OverdozenPermsolver::initializeContinueDataStructures()
{
	int stride = 0;

	switch (params->boundaryCondition)
	{
	case PERIODIC_BC:
		continueVelsCount = dim - 2 * ACCURACY_ORDER;
		break;
	case NOFLOW_BC:
		continueVelsCount = dim - 2 * ACCURACY_ORDER - 1;
		break;
	}
	//printFieldsFuncPtr = &OverdozenPermsolver::printFieldsAlles;
	continueVelsPrev = new float[continueVelsCount];
	continueVelsCurr = new float[continueVelsCount];
	errorSmoothingArray = new float[params->errorSmoothingArrayLength];

	FILE *perm = fopen(cmdline_params->compLogFileName, "at");
	if (perm == NULL)
	{
		printf("Could'n open output file");
		return;
	}

	fprintf(perm, "Permeability, um^2:\tPermeability, mD:\tAccuracy criterion E:\n");
	fclose(perm);

	switch (params->boundaryCondition)
	{
	case PERIODIC_BC:
		printFieldsAlles(continueVelsPrev);
		break;
	case NOFLOW_BC:
		printFieldsAllesNoFlowBC(continueVelsPrev);
		break;
	}
}

float OverdozenPermsolver::launch()
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;

	printf("Flow direction axis: %c\n", params->flowDirectionAxis);
	initialize();
	initializeContinueDataStructures();

	printf("Solving started, MAX %d iterations... \n", params->itsc * params->ntot);

	std::chrono::time_point<clock_t> beg = clock_t::now();
	float averageVelocity(0.0f);
	for (int it = 0; it < params->itsc; it++)
	{
		for (int i = 0; i < params->ntot; i++)
		{
			updateVelocities();
			updatePressures();
			switch (params->boundaryCondition)
			{
			case PERIODIC_BC:
			case NOFLOW_BC:
				applyPeriodicBCforPrs(pVals);
				break;
				//case 1:
				//case 3:
				//	applyFreeBCforPrs(pVals);
				//	break;
			}
			printf("\r%d iterations passed", it * params->ntot + i + 1);
		}

		// Recompute average velocity
		switch (params->boundaryCondition)
		{
		case PERIODIC_BC:
			averageVelocity = printFieldsAlles(continueVelsCurr);
			break;
		case NOFLOW_BC:
			averageVelocity = printFieldsAllesNoFlowBC(continueVelsCurr);
			break;
		}

		if (shouldContinue() == false)
		{
			break;
		}
		else
		{
			float *buffPtr = continueVelsPrev;
			continueVelsPrev = continueVelsCurr;
			continueVelsCurr = buffPtr;
		}
	}
	printf("\n");
	auto elapsed = std::chrono::duration_cast<second_t>(clock_t::now() - beg).count();
	printf("Solving complete. Elapsed time: %.1lf s\n", elapsed);

	outputComputedVelocities();
	// Free memory used by continue-functions
	releasePrintFieldsMemory();

	permeability = averageVelocity * params->rre * params->resolution * params->resolution;
	// TODO: think about what should it mean
	// squareFactor = this->squareFactor;
	return averageVelocity * params->resolution;
}

void OverdozenPermsolver::releasePrintFieldsMemory()
{
	if (continueVelsPrev != NULL)
	{
		delete[] continueVelsPrev;
		continueVelsPrev = NULL;
	}
	if (continueVelsCurr != NULL)
	{
		delete[] continueVelsCurr;
		continueVelsCurr = NULL;
	}
	if (velocityComputationIndices != NULL)
	{
		delete[] velocityComputationIndices;
		velocityComputationIndices = NULL;
	}
	if (errorSmoothingArray != NULL)
	{
		delete[] errorSmoothingArray;
		errorSmoothingArray = NULL;
	}
}

int OverdozenPermsolver::GetInnerDimension()
{
	return dim - 2 * ACCURACY_ORDER;
}

// Permeability in square micrometers
float OverdozenPermsolver::GetPermeability()
{
	return permeability;
}

float OverdozenPermsolver::GetSquareFactor()
{
	return squareFactor;
}

OverdozenPermsolver::OverdozenPermsolver(void) : voxelDataX(NULL), voxelDataY(NULL), voxelDataZ(NULL), voxelDataP(NULL),
												 voxelDataLengthX(0), voxelDataLengthY(0), voxelDataLengthZ(0), voxelDataLengthP(0),
												 dim(0), params(NULL), // pBalancedXPtr(compFuncX[EnvCase::GetIndexInFuncArrayS(ACCURACY_ORDER / 2, ACCURACY_ORDER / 2, ACCURACY_ORDER / 2, ACCURACY_ORDER / 2, ACCURACY_ORDER)]),
												 xVals(NULL), yVals(NULL), zVals(NULL), pVals(NULL),
												 xValsInner(NULL), yValsInner(NULL), zValsInner(NULL), pValsInner(NULL),
												 squareFactor(-1.0f), squareFactorInner(-1.0f),
												 continueVelsPrev(NULL), continueVelsCurr(NULL), velocityComputationIndices(NULL), continueVelsCount(1),
												 permeability(0.0f), prevCriterionErrorValue(-1.0f),
												 errorSmoothingArray(NULL), errorSmoothingArrayWritePosition(0U), errorSmoothingArrayFull(false)
{
	params = new InputParameters();
	xVals = new Area3d<float>();
	yVals = new Area3d<float>();
	zVals = new Area3d<float>();
	pVals = new Area3d<float>();
}

float OverdozenPermsolver::GetErrorMostaghimiStyle()
{
	//float totalError(0.0);
	//float averageVel(0.0);
	//for (int z = ACCURACY_ORDER; z < dim - ACCURACY_ORDER; z++)
	//{
	//	for (int y = ACCURACY_ORDER; y < dim - ACCURACY_ORDER; y++)
	//	{
	//		for (int x = ACCURACY_ORDER; x < dim - ACCURACY_ORDER; x++)
	//		{
	//			float sumFlux(0.0);
	//			bool incorporateCurrentVoxel(false);
	//			float vxl = xVals->get(x, y, z),
	//				vxr = xVals->get(x + 1, y, z),
	//				vyl = yVals->get(x, y, z),
	//				vyr = yVals->get(x, y + 1, z),
	//				vzl = zVals->get(x, y, z),
	//				vzr = zVals->get(x, y, z + 1);
	//			if (vxl != 0.0 || vxr != 0.0) {
	//				float deltax = vxl - vxr;
	//				sumFlux += deltax;
	//				incorporateCurrentVoxel = true;
	//			}
	//			if (vyl != 0.0 || vyr != 0.0) {
	//				float deltay = vyl - vyr;
	//				sumFlux += deltay;
	//				incorporateCurrentVoxel = true;
	//			}
	//			if (vzl != 0.0 || vzr != 0.0) {
	//				float deltaz = vzl - vzr;
	//				sumFlux += deltaz;
	//				incorporateCurrentVoxel = true;
	//			}

	//			if (incorporateCurrentVoxel == true) {
	//				totalError += fabs(sumFlux);
	//				float
	//					vx = (fabs(vxl) + fabs(vxr)) * 0.5,
	//					vy = (fabs(vyl) + fabs(vyr)) * 0.5,
	//					vz = (fabs(vzl) + fabs(vzr)) * 0.5;
	//				averageVel += vx + vy + vz;
	//			}
	//		}
	//	}
	//}

	//return fabs(totalError / averageVel);

	float error(0.0f), flowRate(0.0f);
#pragma omp parallel for schedule(static)
	for (int vx = 0; vx < voxelDataLengthP; vx++)
	{
		StuffedVoxel *sv = &voxelDataP[vx];
		int x = sv->x + ACCURACY_ORDER,
			y = sv->y + ACCURACY_ORDER,
			z = sv->z + ACCURACY_ORDER;

		float imbalance =
			xVals->get(x + 1, y, z) - xVals->get(x, y, z) +
			yVals->get(x, y + 1, z) - yVals->get(x, y, z) +
			zVals->get(x, y, z + 1) - zVals->get(x, y, z);
		flowRate += 0.5f * (fabs(xVals->get(x + 1, y, z)) +
							fabs(xVals->get(x, y, z)));

		error += fabs(imbalance);
	}

	return error / flowRate;
}

// Criterion selector function
float OverdozenPermsolver::GetAugeCriterionError()
{
	return GetAugeCriterionErrorV2();
}

float OverdozenPermsolver::GetAugeCriterionErrorV1()
{
	float revReynoldsNum = params->rre;
	float error = 0.0, flowRate = 0.0;

#pragma omp parallel for reduction(+ \
								   : error, flowRate) schedule(static)
	for (int vx = 0; vx < voxelDataLengthX; vx++)
	{
		StuffedVoxel *sv = &voxelDataX[vx];
		float (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, float) = crtFuncX[sv->funcIndex];
		if (funcPtr != NULL)
		{
			error += funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, xVals, pVals, revReynoldsNum);
			flowRate += fabs(xVals->get(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER));
		}
	}

#pragma omp parallel for reduction(+ \
								   : error, flowRate) schedule(static)
	for (int vx = 0; vx < voxelDataLengthY; vx++)
	{
		StuffedVoxel *sv = &voxelDataY[vx];
		float (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, float) = crtFuncY[sv->funcIndex];
		if (funcPtr != NULL)
		{
			error += funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, yVals, pVals, revReynoldsNum);
			flowRate += fabs(yVals->get(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER));
		}
	}

#pragma omp parallel for reduction(+ \
								   : error, flowRate) schedule(static)
	for (int vx = 0; vx < voxelDataLengthZ; vx++)
	{
		StuffedVoxel *sv = &voxelDataZ[vx];
		float (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, float) = crtFuncZ[sv->funcIndex];
		if (funcPtr != NULL)
		{
			error += funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, zVals, pVals, revReynoldsNum);
			flowRate += fabs(zVals->get(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER));
		}
	}

#pragma omp parallel for reduction(+ \
								   : error) schedule(static)
	for (int vx = 0; vx < voxelDataLengthP; vx++)
	{
		StuffedVoxel *sv = &voxelDataP[vx];
		int x = sv->x + ACCURACY_ORDER,
			y = sv->y + ACCURACY_ORDER,
			z = sv->z + ACCURACY_ORDER;

		float imbalance =
			xVals->get(x + 1, y, z) - xVals->get(x, y, z) +
			yVals->get(x, y + 1, z) - yVals->get(x, y, z) +
			zVals->get(x, y, z + 1) - zVals->get(x, y, z);
		flowRate += 0.5f * (fabs(xVals->get(x + 1, y, z)) +
							fabs(xVals->get(x, y, z)) +
							fabs(yVals->get(x, y + 1, z)) +
							fabs(yVals->get(x, y, z)) +
							fabs(zVals->get(x, y, z + 1)) +
							fabs(zVals->get(x, y, z)));

		error += fabs(imbalance);
	}

	return error / flowRate;
}

float OverdozenPermsolver::GetAugeCriterionErrorV2()
{
	float revReynoldsNum = params->rre;
	float errorX = 0.0, errorY = 0.0, errorZ = 0.0, errorBal = 0.0;
	float flowRateX = 0.0, flowRateY = 0.0, flowRateZ = 0.0, flowRateBal = 0.0;

#pragma omp parallel for reduction(+ \
								   : errorX, flowRateX) schedule(static)
	for (int vx = 0; vx < voxelDataLengthX; vx++)
	{
		StuffedVoxel *sv = &voxelDataX[vx];
		float (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, float) = crtFuncX[sv->funcIndex];
		if (funcPtr != NULL)
		{
			errorX += funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, xVals, pVals, revReynoldsNum);
			flowRateX += fabs(xVals->get(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER));
		}
	}

#pragma omp parallel for reduction(+ \
								   : errorY, flowRateY) schedule(static)
	for (int vx = 0; vx < voxelDataLengthY; vx++)
	{
		StuffedVoxel *sv = &voxelDataY[vx];
		float (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, float) = crtFuncY[sv->funcIndex];
		if (funcPtr != NULL)
		{
			errorY += funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, yVals, pVals, revReynoldsNum);
			flowRateY += fabs(yVals->get(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER));
		}
	}

#pragma omp parallel for reduction(+ \
								   : errorZ, flowRateZ) schedule(static)
	for (int vx = 0; vx < voxelDataLengthZ; vx++)
	{
		StuffedVoxel *sv = &voxelDataZ[vx];
		float (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, float) = crtFuncZ[sv->funcIndex];
		if (funcPtr != NULL)
		{
			errorZ += funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, zVals, pVals, revReynoldsNum);
			flowRateZ += fabs(zVals->get(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER));
		}
	}

#pragma omp parallel for reduction(+ \
								   : errorBal) schedule(static)
	for (int vx = 0; vx < voxelDataLengthP; vx++)
	{
		StuffedVoxel *sv = &voxelDataP[vx];
		int x = sv->x + ACCURACY_ORDER,
			y = sv->y + ACCURACY_ORDER,
			z = sv->z + ACCURACY_ORDER;

		float imbalance =
			xVals->get(x + 1, y, z) - xVals->get(x, y, z) +
			yVals->get(x, y + 1, z) - yVals->get(x, y, z) +
			zVals->get(x, y, z + 1) - zVals->get(x, y, z);
		flowRateBal += 0.5f * (fabs(xVals->get(x + 1, y, z)) +
							   fabs(xVals->get(x, y, z)) +
							   fabs(yVals->get(x, y + 1, z)) +
							   fabs(yVals->get(x, y, z)) +
							   fabs(zVals->get(x, y, z + 1)) +
							   fabs(zVals->get(x, y, z)));

		errorBal += fabs(imbalance);
	}

	float error = 0.0f;
	if (flowRateX != 0.0f)
	{
		error += errorX / flowRateX;
	}
	if (flowRateY != 0.0f)
	{
		error += errorY / flowRateY;
	}
	if (flowRateZ != 0.0f)
	{
		error += errorZ / flowRateZ;
	}
	if (flowRateBal != 0.0f)
	{
		error += errorBal / flowRateBal;
	}
	return error;
}

float OverdozenPermsolver::GetAugeCriterionErrorV3()
{
	float revReynoldsNum = params->rre;
	float errorX = 0.0, errorY = 0.0, errorZ = 0.0, errorP = 0.0, flowRate = 0.0;

#pragma omp parallel for reduction(+ \
								   : errorX) schedule(static)
	for (int vx = 0; vx < voxelDataLengthX; vx++)
	{
		StuffedVoxel *sv = &voxelDataX[vx];
		float (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, float) = crtFuncX[sv->funcIndex];
		if (funcPtr != NULL)
		{
			errorX += funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, xVals, pVals, revReynoldsNum) /
					  fabs(xVals->get(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER));
		}
	}
	errorX /= voxelDataLengthX;

#pragma omp parallel for reduction(+ \
								   : errorY) schedule(static)
	for (int vx = 0; vx < voxelDataLengthY; vx++)
	{
		StuffedVoxel *sv = &voxelDataY[vx];
		float (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, float) = crtFuncY[sv->funcIndex];
		if (funcPtr != NULL)
		{
			errorY += funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, yVals, pVals, revReynoldsNum) /
					  fabs(yVals->get(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER));
		}
	}
	errorY /= voxelDataLengthY;

#pragma omp parallel for reduction(+ \
								   : errorZ) schedule(static)
	for (int vx = 0; vx < voxelDataLengthZ; vx++)
	{
		StuffedVoxel *sv = &voxelDataZ[vx];
		float (*funcPtr)(int, int, int, Area3d<float> *, Area3d<float> *, float) = crtFuncZ[sv->funcIndex];
		if (funcPtr != NULL)
		{
			errorZ += funcPtr(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER, zVals, pVals, revReynoldsNum) /
					  fabs(zVals->get(sv->x + ACCURACY_ORDER, sv->y + ACCURACY_ORDER, sv->z + ACCURACY_ORDER));
		}
	}
	errorZ /= voxelDataLengthZ;

#pragma omp parallel for reduction(+ \
								   : errorP) schedule(static)
	for (int vx = 0; vx < voxelDataLengthP; vx++)
	{
		StuffedVoxel *sv = &voxelDataP[vx];
		int x = sv->x + ACCURACY_ORDER,
			y = sv->y + ACCURACY_ORDER,
			z = sv->z + ACCURACY_ORDER;

		float imbalance =
			xVals->get(x + 1, y, z) - xVals->get(x, y, z) +
			yVals->get(x, y + 1, z) - yVals->get(x, y, z) +
			zVals->get(x, y, z + 1) - zVals->get(x, y, z);
		flowRate = 0.5f * (fabs(xVals->get(x + 1, y, z)) +
						   fabs(xVals->get(x, y, z)) +
						   fabs(yVals->get(x, y + 1, z)) +
						   fabs(yVals->get(x, y, z)) +
						   fabs(zVals->get(x, y, z + 1)) +
						   fabs(zVals->get(x, y, z)));

		errorP += fabs(imbalance / flowRate);
	}
	errorP /= voxelDataLengthP;

	return errorX + errorY + errorZ + errorP;
}

float OverdozenPermsolver::GetHaifischCriterionError()
{
	float error = 0.0, flowRate = 0.0;
#pragma omp parallel for schedule(static)
	for (int vx = 0; vx < voxelDataLengthP; vx++)
	{
		StuffedVoxel *sv = &voxelDataP[vx];
		int x = sv->x + ACCURACY_ORDER,
			y = sv->y + ACCURACY_ORDER,
			z = sv->z + ACCURACY_ORDER;

		float imbalance =
			xVals->get(x + 1, y, z) - xVals->get(x, y, z) +
			yVals->get(x, y + 1, z) - yVals->get(x, y, z) +
			zVals->get(x, y, z + 1) - zVals->get(x, y, z);
		flowRate += 0.5f * (fabs(xVals->get(x + 1, y, z)) +
							fabs(xVals->get(x, y, z)) +
							fabs(yVals->get(x, y + 1, z)) +
							fabs(yVals->get(x, y, z)) +
							fabs(zVals->get(x, y, z + 1)) +
							fabs(zVals->get(x, y, z)));

		error += fabs(imbalance);
	}

	return error / flowRate;
}

OverdozenPermsolver::~OverdozenPermsolver(void)
{
	delete params;
	delete xVals;
	delete yVals;
	delete zVals;
	delete pVals;

	delete xValsInner;
	delete yValsInner;
	delete zValsInner;
	delete pValsInner;

	if (voxelDataX != NULL)
	{
		delete[] voxelDataX;
		voxelDataX = NULL;
		voxelDataLengthX = 0L;
	}

	if (voxelDataY != NULL)
	{
		delete[] voxelDataY;
		voxelDataY = NULL;
		voxelDataLengthY = 0L;
	}

	if (voxelDataZ != NULL)
	{
		delete[] voxelDataZ;
		voxelDataZ = NULL;
		voxelDataLengthZ = 0L;
	}

	if (voxelDataP != NULL)
	{
		delete[] voxelDataP;
		voxelDataP = NULL;
		voxelDataLengthP = 0L;
	}
}

void OverdozenPermsolver::SetCmdLineParameters(CmdLineParameters *cmdline_params)
{
	this->cmdline_params = cmdline_params;
}