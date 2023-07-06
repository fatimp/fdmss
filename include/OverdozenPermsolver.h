#ifndef OVERDOZEN_PERMSOLVER_H
#define OVERDOZEN_PERMSOLVER_H

#include "PbcOverdozenMicroperm.h"
#include "FbcOverdozenMicroperm.h"
#include "NfbcOverdozenMicroperm.h"
#include "HorseBCOverdozenMicroperm.h"
#include "InputParameters.h"
#include "CmdLineParameters.h"
#include <fstream>
using namespace std;

#define PERIODIC_BC 0
#define NOFLOW_BC 1
#define SOLUTION_CONVERGES 0
#define ERROR_CONVERGES 1
#define ERROR_DOESNT_EXCEED 2
#define CONFIG_FILE_NAME ""
#define IMAGE_FILE_NAME ""
#define COMPUTATION_LOG_FILE_NAME "/dev/null"
#define SUMMARY_FILE_NAME "output.xml"
#define COMPUTED_VELOCITIES_FILE_NAME "/dev/null"
#define VELOCITIES_X_FILENAME "/dev/null"
#define VELOCITIES_Y_FILENAME "/dev/null"
#define VELOCITIES_Z_FILENAME "/dev/null"
#define PRESSURES_FILENAME "/dev/null"
#define FULL_VELOCITIES_FILENAME "/dev/null"

class OverdozenPermsolver
{
	long voxelDataLengthX;
	long voxelDataLengthY;
	long voxelDataLengthZ;
	long voxelDataLengthP;

	int dim;
	float squareFactor, squareFactorInner;
	float permeability;

	StuffedVoxel *voxelDataX;
	StuffedVoxel *voxelDataY;
	StuffedVoxel *voxelDataZ;
	StuffedVoxel *voxelDataP;

	//char directionAxis;

	InputParameters *params;
	CmdLineParameters *cmdline_params;
	//void (*pBalancedXPtr) (int, int, int, Area3d<float>*, Area3d<float>*, Area3d<float>*, float, float);

	Area3d<float> *xVals;
	Area3d<float> *yVals;
	Area3d<float> *zVals;
	Area3d<float> *pVals;

	Area3d<float> *xValsInner;
	Area3d<float> *yValsInner;
	Area3d<float> *zValsInner;
	Area3d<float> *pValsInner;

	int continueVelsCount;
	int *velocityComputationIndices;
	float *continueVelsPrev;
	float *continueVelsCurr;
	float prevCriterionErrorValue; // For error convergence. Initial value = -1.0f

	float *errorSmoothingArray;
	unsigned int errorSmoothingArrayWritePosition;
	bool errorSmoothingArrayFull;

	void initialize();
	void initializeContinueDataStructures();
	void updateBoundaryElements(const char directionAxis);
	void printFields(float *v);
	void printFieldsIndexed(float *v);
	float printFieldsAlles(float *v);
	float printFieldsAllesNoFlowBC(float *v);
	float printFieldsAllesHorseBC(float *v);
	void printFieldsAlles3dir(float *v);
	void outputComputedVelocities();
	void outputComputedVelocitiesNoFlowBC();
	void outputComputedVelocitiesHorseBC();
	bool shouldContinue();
	void releasePrintFieldsMemory();
	void updateVelocities(const char directionAxis); // may be X, Y or Z
	void updateVelocities();
	void applyPeriodicBC(Area3d<float> *buff);
	void applyPeriodicBCforPrs(Area3d<float> *buff);
	void applyPeriodicBCforPrs_FlowX(Area3d<float> *buff);
	void applyPeriodicBCforPrs_FlowY(Area3d<float> *buff);
	void applyPeriodicBCforPrs_FlowZ(Area3d<float> *buff);
	void applyFreeBC_X(Area3d<float> *buff);
	void applyFreeBC_Y(Area3d<float> *buff);
	void applyFreeBC_Z(Area3d<float> *buff);
	void applyFreeBCforPrs(Area3d<float> *buff);
	void updatePressures();
	void printFieldsImpl(Area3d<float> *data[], const char *fnames[]);
	void printFieldsImplPbc(Area3d<float> *data[], const char *fnames[]);
	void printFieldsImplNfbc(Area3d<float> *data[], const char *fnames[]);

public:
	bool ReadFailo(const string &paramsFileName, const string &filename);
	void SetCmdLineParameters(CmdLineParameters *cmdline_params);
	float launch();
	int GetInnerDimension();
	float GetPermeability();
	float GetSquareFactor();
	float GetErrorMostaghimiStyle();

	float GetAugeCriterionError();

	float GetAugeCriterionErrorV1();
	float GetAugeCriterionErrorV2();
	float GetAugeCriterionErrorV3();

	float GetHaifischCriterionError();
	void printVelPrsFields(); // Mainstream implementation
	void printVelPrsFieldsCustom(const char *fnames[]);
	void printFieldsWithoutWaterLayer();
	void printFieldsWithBorders(); // Debug method
	OverdozenPermsolver(void);
	~OverdozenPermsolver(void);
};

#endif // OVERDOZEN_PERMSOLVER_H
