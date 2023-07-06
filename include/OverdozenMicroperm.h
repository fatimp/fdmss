#ifndef OVERDOZEN_MICROPERM_H
#define OVERDOZEN_MICROPERM_H

#include "BoundaryArea3d.h"
#include "StuffedVoxel.h"
#include "EnvCaseGenerator.h"
#include <string>
using namespace std;

// #define MAX_IMAGE_SIZE 100

class OverdozenMicroperm
{
protected:
	int dim; // Make public to output the MathMod image
	int innerDim;
	float squareFactor, squareFactorInner;
	const char flowDirectionAxis;
	BoundaryArea3d<unsigned char> *image; // Make public to output the MathMod image

	int porosityX, porosityY, porosityZ;
	int pressureCellsCount;

	virtual long EvalEffectivePorosityX() = 0;
	virtual long EvalEffectivePorosityY() = 0;
	virtual long EvalEffectivePorosityZ() = 0;
	virtual long EvalPressureCellsCount() = 0;

	EnvCase *EvalAdjacentVoxelsX(int x, int y, int z);
	EnvCase *EvalAdjacentVoxelsY(int x, int y, int z);
	EnvCase *EvalAdjacentVoxelsZ(int x, int y, int z);

	StuffedVoxel *voxelDataX;
	StuffedVoxel *voxelDataY;
	StuffedVoxel *voxelDataZ;
	StuffedVoxel *voxelDataP;

public:
	OverdozenMicroperm(const char _flowDirectionAxis = 'x');
	virtual void ReadFailo(const string image3dFilename, const unsigned int waterLayerWidth) = 0;

	virtual long GetVoxelDataX(StuffedVoxel **voxelData) = 0;
	virtual long GetVoxelDataY(StuffedVoxel **voxelData) = 0;
	virtual long GetVoxelDataZ(StuffedVoxel **voxelData) = 0;
	virtual long GetVoxelDataP(StuffedVoxel **voxelData) = 0;

	int GetDimension();

	void WritePressureFailo(); // Unknown function

	virtual float GetSquareFactor();
	float GetInnerSquareFactor();
	virtual bool CheckSizeConstraint() const;

	bool IsPore(const int x, const int y, const int z) const;

	~OverdozenMicroperm(void);
};

#endif // OVERDOZEN_MICROPERM_H