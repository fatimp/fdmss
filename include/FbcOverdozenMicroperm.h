#ifndef FBC_OVERDOZEN_MICROPERM_H
#define FBC_OVERDOZEN_MICROPERM_H

#include "OverdozenMicroperm.h"
#include "FreeArea3d.h"

class FbcOverdozenMicroperm : public OverdozenMicroperm
{
private:
	virtual long EvalEffectivePorosityX();
	virtual long EvalEffectivePorosityY();
	virtual long EvalEffectivePorosityZ();
	virtual long EvalPressureCellsCount();

public:
	FbcOverdozenMicroperm();
	virtual void ReadFailo(const string filename);

	virtual long GetVoxelDataX(StuffedVoxel **voxelData);
	virtual long GetVoxelDataY(StuffedVoxel **voxelData);
	virtual long GetVoxelDataZ(StuffedVoxel **voxelData);
	virtual long GetVoxelDataP(StuffedVoxel **voxelData);

	virtual ~FbcOverdozenMicroperm();
};

#endif // FBC_OVERDOZEN_MICROPERM_H