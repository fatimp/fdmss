#ifndef NFBC_OVERDOZEN_MICROPERM_H
#define NFBC_OVERDOZEN_MICROPERM_H

#include "OverdozenMicroperm.h"
#include "PeriodicArea3d.h"

class NfbcOverdozenMicroperm : public OverdozenMicroperm
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

	void CreateBarriers();
	void CreateBarriersX();
	void CreateBarriersY();
	void CreateBarriersZ();

public:
	virtual float GetSquareFactor();
	NfbcOverdozenMicroperm(const char _flowDirectionAxis = 'x');

	virtual long GetVoxelDataX(StuffedVoxel **voxelData);
	virtual long GetVoxelDataY(StuffedVoxel **voxelData);
	virtual long GetVoxelDataZ(StuffedVoxel **voxelData);
	virtual long GetVoxelDataP(StuffedVoxel **voxelData);

	virtual void ReadFailo(const string filename, const unsigned int waterLayerWidth);
	virtual bool CheckSizeConstraint() const;
	virtual ~NfbcOverdozenMicroperm();
};

#endif // NFBC_OVERDOZEN_MICROPERM_H