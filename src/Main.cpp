// OverdozenPermsolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EnvCaseGenerator.h"
#include "Codegen.h"
#include "PbcOverdozenMicroperm.h"
#include "MouseFuncX.h"
#include "MouseFuncY.h"
#include "MouseFuncZ.h"
#include "OverdozenPermsolver.h"
#include "tinyxml.h"

#include <omp.h>
#include <boost/program_options.hpp>

using namespace boost;
namespace po = boost::program_options;

extern void (*compFuncX[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncY[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);
extern void (*compFuncZ[])(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float);

extern float (*crtFuncX[])(int, int, int, Area3d<float> *, Area3d<float> *, float);
extern float (*crtFuncY[])(int, int, int, Area3d<float> *, Area3d<float> *, float);
extern float (*crtFuncZ[])(int, int, int, Area3d<float> *, Area3d<float> *, float);

void TaylorUnittest()
{
	//float* cf1 = Codegen::GetTaylorCoeff(-0.5, 3);
	//float* cf3 = Codegen::GetTaylorCoeff(1.0, 3);
	//float* cf4 = Codegen::GetTaylorCoeff(1.5, 3);
	//float* cf[] = { cf1, cf3, cf4 };
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int c = 0; c < 3; c++)
	//	{
	//		printf("%.4f ", cf[i][c]);
	//	}
	//	printf("\n");
	//}
}

void SlauGenUnittest()
{
	EnvCase cs(0, 1, 0, 0, 2);
	Slau slau(&cs, 1);
	slau.printA();
	printf("\n");
	slau.printB();
}

void SlauSolveUnittest()
{
	EnvCase cs(2, 2, 0, 0, 4);
	Slau slau(&cs, 1);
	Polynom res = slau.SolveForSecondDerivative();
	for (int i = 1; i <= res.P; i++)
	{
		printf("%.9f ", res[i]);
	}
	printf("\n");
}

void EnvCaseGeneratorUnittest()
{
	EnvCaseGenerator ecg(4);
	vector<EnvCase> cases;
	while (ecg.has_next())
	{
		cases.push_back(ecg.next());
	}
}

void fptest()
{
	PeriodicArea3d<float> area;
	PeriodicArea3d<float> out;
	PeriodicArea3d<float> prs;
	area.resize(4, 4, 4);
	prs.resize(4, 4, 4);
	out.resize(4, 4, 4);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
			{
				area.set(i, j, k, 1.0f);
				prs.set(i, j, k, 1.0f);
			}
	float dt = 0.0004f;
	float rre = 100.0f;

	void (*fp1)(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float) = compFuncX[0];
	void (*fp2)(int, int, int, Area3d<float> *, Area3d<float> *, Area3d<float> *, float, float) = compFuncZ[1];

	fp1(1, 1, 1, &area, &out, &prs, dt, rre);
	fp2(1, 1, 1, &area, &out, &prs, dt, rre);
}

void ECIndexingUnittest()
{
	int i1 = EnvCase::GetIndexInFuncArrayS(0, 0, 0, 0, 2);
	int i2 = EnvCase::GetIndexInFuncArrayS(1, 0, 0, 1, 2);
	int i3 = EnvCase::GetIndexInFuncArrayS(0, 0, 2, 0, 2);
	int i4 = EnvCase::GetIndexInFuncArrayS(2, 0, 2, 0, 2);
	int i5 = EnvCase::GetIndexInFuncArrayS(1, 1, 0, 1, 2);
	int i6 = EnvCase::GetIndexInFuncArrayS(0, 2, 0, 2, 2);
	printf("%d %d %d %d %d %d\n", i1, i2, i3, i4, i5, i6);
}

void MicropermUnittest()
{
	PbcOverdozenMicroperm mp;
	mp.ReadFailo(IMAGE_FILE_NAME, 0U);
	StuffedVoxel *voxelData = NULL;
	long prs = mp.GetVoxelDataP(&voxelData);
	mp.WritePressureFailo();
}

void GenerateCode(int accuracy)
{
	Codegen cg(accuracy);
	cg.GenerateAccuracyFile("AccuracyOrder");
	cg.Generate("MouseFuncX", "MouseFuncY", "MouseFuncZ");
	cg.GenerateCrt("CrtFuncX", "CrtFuncY", "CrtFuncZ");
}

void SolveImpl(CmdLineParameters *io_filenames)
{
	OverdozenPermsolver ps;
	ps.SetCmdLineParameters(io_filenames);

	float vel(0.0), squareFactor(0.0), permeability(0.0), error(0.0), limit_triggered(1.0);

	if (ps.ReadFailo(io_filenames->configFileName, io_filenames->imageFileName) == true)
	{
		printf("File loaded successfully\n");
		limit_triggered = 0.0;
		vel = ps.launch();
		squareFactor = ps.GetSquareFactor();
		permeability = ps.GetPermeability();
		error = ps.GetAugeCriterionError(); //GetErrorMostaghimiStyle();
	}

	TiXmlDocument doc;
	TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);
	TiXmlElement *rootElem = new TiXmlElement("OverdozenPermsolverOutput");

	TiXmlElement *iLimiterTriggered = new TiXmlElement("LimiterTriggered");
	iLimiterTriggered->SetDoubleAttribute("value", limit_triggered);
	TiXmlElement *iPermeabilityM2 = new TiXmlElement("Permeability_micrometer2");
	iPermeabilityM2->SetDoubleAttribute("value", permeability);
	TiXmlElement *iPermeabilityMD = new TiXmlElement("Permeability_mD");
	iPermeabilityMD->SetDoubleAttribute("value", permeability * MILLIDARCY_CONVERT_RATE);
	TiXmlElement *iAverageVelocity = new TiXmlElement("AverageVelocity");
	iAverageVelocity->SetDoubleAttribute("value", vel);
	TiXmlElement *iRelativeError = new TiXmlElement("RelativeError");
	iRelativeError->SetDoubleAttribute("value", error);
	//TiXmlElement* iAverageVelocityPS = new TiXmlElement("AverageVelocityInPoreSpace");
	//iAverageVelocityPS->SetDoubleAttribute("value", vel * squareFactor);
	//TiXmlElement* iOpenPS = new TiXmlElement("OpenPoreSpaceFraction");
	//iOpenPS->SetDoubleAttribute("value", 1.0 / squareFactor);
	//TiXmlElement* iCumulativeFlow = new TiXmlElement("CumulativeFluidFlow");
	//iCumulativeFlow->SetDoubleAttribute("value", vel * float(innerDim * innerDim));
	rootElem->LinkEndChild(iAverageVelocity);
	//rootElem->LinkEndChild(iAverageVelocityPS);
	rootElem->LinkEndChild(iPermeabilityM2);
	rootElem->LinkEndChild(iPermeabilityMD);
	rootElem->LinkEndChild(iRelativeError);
	rootElem->LinkEndChild(iLimiterTriggered);
	//rootElem->LinkEndChild(iOpenPS);
	//rootElem->LinkEndChild(iCumulativeFlow);

	printf("Average velocity, micrometers/sec = %.6f\n", vel);
	printf("Average velocity within pore space, micrometers/sec = %.6f\n", vel * squareFactor);
	printf("Permeability, sq micrometers = %.6f\n", permeability);
	printf("Permeability, mD = %.6f\n", permeability * MILLIDARCY_CONVERT_RATE);
	printf("Open pore space fraction at inlet = %.6f\n", 1.0 / squareFactor);
	//printf("Cumulative fluid flow = %.6f\n", vel * float(innerDim * innerDim));
	printf("Relative error = %.6f\n", error);

	const char *output_fnames[] = {
		io_filenames->velXFileName,
		io_filenames->velYFileName,
		io_filenames->velZFileName,
		io_filenames->pressuresFileName,
		io_filenames->fullVelsFileName};

	ps.printVelPrsFieldsCustom(output_fnames);

	doc.LinkEndChild(rootElem);
	doc.SaveFile(io_filenames->summaryFileName);
}

int main(int argc, char *argv[]) {
	po::options_description desc("Allowed options");
	po::variables_map vm;

	desc.add_options()
		("help", "Show help")
		("config", po::value<string>()->default_value(CONFIG_FILE_NAME),
		 "configuration file name")
		("image", po::value<string>()->default_value(IMAGE_FILE_NAME),
		 "image file name")
		("summary", po::value<string>()->default_value(SUMMARY_FILE_NAME),
		 "summary file name")
		("log", po::value<string>()->default_value(COMPUTATION_LOG_FILE_NAME),
		 "log file name")
		("velx", po::value<string>()->default_value(VELOCITIES_X_FILENAME),
		 "X velocities file name")
		("vely", po::value<string>()->default_value(VELOCITIES_Y_FILENAME),
		 "Y velocities file name")
		("velz", po::value<string>()->default_value(VELOCITIES_Z_FILENAME),
		 "Z velocities file name")
		("pressure", po::value<string>()->default_value(PRESSURES_FILENAME),
		 "pressure file name");

	po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
	po::notify(vm);

	if (vm.count("help")                ||
        vm["config"].as<string>() == "" ||
        vm["image"].as<string>()  == "") {
		cout << "Usage: fdmss [options]\n";
		cout << desc;
		return 0;
	}

	CmdLineParameters io_filenames (
		vm["config"].as<string>().c_str(),
		vm["image"].as<string>().c_str(),
		vm["summary"].as<string>().c_str(),
		vm["velx"].as<string>().c_str(),
		vm["vely"].as<string>().c_str(),
		vm["velz"].as<string>().c_str(),
		vm["pressure"].as<string>().c_str(),
		FULL_VELOCITIES_FILENAME,
		COMPUTED_VELOCITIES_FILE_NAME,
		vm["log"].as<string>().c_str()
		);

	SolveImpl(&io_filenames);
	return 0;
}
