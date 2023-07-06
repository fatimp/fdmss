#ifndef HORSEBC_OVERDOZEN_MICROPERM_H
#define HORSEBC_OVERDOZEN_MICROPERM_H

#include "OverdozenMicroperm.h"
#include "FreeArea3d.h"

class HorseBCOverdozenMicroperm : public OverdozenMicroperm
{
	virtual long EvalEffectivePorosityX();
	virtual long EvalEffectivePorosityY();
	virtual long EvalEffectivePorosityZ();
	virtual long EvalPressureCellsCount();

	void CreateOuterLayers();

public:
	HorseBCOverdozenMicroperm();

	virtual float GetSquareFactor();
	virtual void ReadFailo(const string filename);

	virtual long GetVoxelDataX(StuffedVoxel **voxelData);
	virtual long GetVoxelDataY(StuffedVoxel **voxelData);
	virtual long GetVoxelDataZ(StuffedVoxel **voxelData);
	virtual long GetVoxelDataP(StuffedVoxel **voxelData);

	virtual ~HorseBCOverdozenMicroperm(void);
};

#endif // HORSEBC_OVERDOZEN_MICROPERM_H