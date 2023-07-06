#ifndef PBC_OVERDOZEN_MICROPERM_H
#define PBC_OVERDOZEN_MICROPERM_H

#include "OverdozenMicroperm.h"
#include "PeriodicArea3d.h"

class PbcOverdozenMicroperm : public OverdozenMicroperm
{
private:
	virtual long EvalEffectivePorosityX();
	virtual long EvalEffectivePorosityY();
	virtual long EvalEffectivePorosityZ();
	virtual long EvalPressureCellsCount();

	long EvalPressureCellsCount_FlowX();
	long EvalPressureCellsCount_FlowY();
	long EvalPressureCellsCount_FlowZ();
	long GetVoxelDataP_FlowX(StuffedVoxel **voxelData);
	long GetVoxelDataP_FlowY(StuffedVoxel **voxelData);
	long GetVoxelDataP_FlowZ(StuffedVoxel **voxelData);

public:
	PbcOverdozenMicroperm(const char _flowDirectionAxis = 'x');

	virtual long GetVoxelDataX(StuffedVoxel **voxelData);
	virtual long GetVoxelDataY(StuffedVoxel **voxelData);
	virtual long GetVoxelDataZ(StuffedVoxel **voxelData);
	virtual long GetVoxelDataP(StuffedVoxel **voxelData);

	virtual void ReadFailo(const string filename, const unsigned int waterLayerWidth);
	virtual ~PbcOverdozenMicroperm();
};

#endif // PBC_OVERDOZEN_MICROPERM_H