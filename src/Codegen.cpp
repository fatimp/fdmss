#include "Codegen.h"

Codegen::Codegen(int _p) : gen(_p), p(_p)
{
}

void Codegen::GenerateForX(const string &filename)
{
	gen.reset();
	FILE *codefile = fopen((filename + ".cpp").c_str(), "wt");
	fprintf(codefile, "#pragma once\n");
	fprintf(codefile, "#include \"%s\"\n\n", (filename + ".h").c_str());

	while (gen.has_next())
	{
		EnvCase cs = gen.next();
		sprintf(namebuffer, "Mouse_X_YL%d_YR%d_ZL%d_ZR%d", cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		xNames.push_back(string(namebuffer));
		fprintf(codefile, "void Mouse_X_YL%d_YR%d_ZL%d_ZR%d(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)\n",
				cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		fprintf(codefile, "{\n");
		// Write code here :)
		// Parallel part
		int ppar = p % 2 == 0 ? p : p + 1;
		if (ppar == 2)
		{
			fprintf(codefile, "\tfloat d2vx = data->get(x - 1, y, z) - 2.0f * data->get(x, y, z) + data->get(x + 1, y, z);\n");
		}
		else if (ppar == 4)
		{
			fprintf(codefile, "\tfloat d2vx = (-data->get(x - 2, y, z) + 16.0f * data->get(x - 1, y, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x + 1, y, z) - data->get(x + 2, y, z)) / 12.0f;\n");
		}
		else
		{
			EnvCase pcase(ppar / 2, ppar / 2, 0, 0, ppar);
			Slau s(&pcase, 1);
			Polynom rkc = s.SolveForSecondDerivative();
			fprintf(codefile, "\tfloat d2vx = ");
			for (int cfIdx = 1; cfIdx <= ppar + 1; cfIdx++)
			{
				int offset = cfIdx - pcase.centerX();
				if (offset > 0)
				{
					fprintf(codefile, "%.6ff * data->get(x + %d, y, z)", rkc[cfIdx], offset);
				}
				else if (offset < 0)
				{
					fprintf(codefile, "%.6ff * data->get(x - %d, y, z)", rkc[cfIdx], -offset);
				}
				else
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z)", rkc[cfIdx]);
				}

				if (cfIdx <= ppar)
				{
					fprintf(codefile, " + ");
				}
			}
			fprintf(codefile, ";\n");
		}

		// First perpendicular part
		Slau slauY(&cs, 1);
		Polynom coeffsY = slauY.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		int initCf = cs.LeftXIncluded() ? 2 : 1;
		int maxCf = cs.RightXIncluded() ? cs.pX() : cs.pX() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerX();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y + %d, z)", coeffsY[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y - %d, z)", coeffsY[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsY[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");

		// Second perpendicular part
		Slau slauZ(&cs, 2);
		Polynom coeffsZ = slauZ.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		initCf = cs.LeftYIncluded() ? 2 : 1;
		maxCf = cs.RightYIncluded() ? cs.pY() : cs.pY() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerY();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z + %d)", coeffsZ[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z - %d)", coeffsZ[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsZ[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");

		// Update value
		fprintf(codefile, "\toutput->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x - 1, y, z) - prs->get(x, y, z) + d2vx * revReynodlsNum));\n");
		fprintf(codefile, "}\n\n");
	}

	GenerateFPArray(codefile, 'X', xNames);
	fclose(codefile);

	// Header generation
	FILE *hFile = fopen((filename + ".h").c_str(), "wt");
	if (hFile != NULL)
	{
		fprintf(hFile, "#pragma once\n");
		fprintf(hFile, "#include \"stdafx.h\"\n");
		fprintf(hFile, "#include \"Area3d.h\"\n\n");
		int sz = xNames.size();
		for (int i = 0; i < sz; i++)
		{
			fprintf(hFile, ("void " + xNames[i] + "(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum);\n").c_str());
		}
		xNames.clear();
		fclose(hFile);
	}
}

void Codegen::GenerateCrtForX(const string &filename)
{
	gen.reset();
	FILE *codefile = fopen((filename + ".cpp").c_str(), "wt");
	fprintf(codefile, "#pragma once\n");
	fprintf(codefile, "#include \"%s\"\n\n", (filename + ".h").c_str());

	while (gen.has_next())
	{
		EnvCase cs = gen.next();
		sprintf(namebuffer, "Crt_X_YL%d_YR%d_ZL%d_ZR%d", cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		xNames.push_back(string(namebuffer));
		fprintf(codefile, "float Crt_X_YL%d_YR%d_ZL%d_ZR%d(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)\n",
				cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		fprintf(codefile, "{\n");
		// Write code here :)
		// Parallel part
		int ppar = p % 2 == 0 ? p : p + 1;
		if (ppar == 2)
		{
			fprintf(codefile, "\tfloat d2vx = data->get(x - 1, y, z) - 2.0f * data->get(x, y, z) + data->get(x + 1, y, z);\n");
		}
		else if (ppar == 4)
		{
			fprintf(codefile, "\tfloat d2vx = (-data->get(x - 2, y, z) + 16.0f * data->get(x - 1, y, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x + 1, y, z) - data->get(x + 2, y, z)) / 12.0f;\n");
		}
		else
		{
			EnvCase pcase(ppar / 2, ppar / 2, 0, 0, ppar);
			Slau s(&pcase, 1);
			Polynom rkc = s.SolveForSecondDerivative();
			fprintf(codefile, "\tfloat d2vx = ");
			for (int cfIdx = 1; cfIdx <= ppar + 1; cfIdx++)
			{
				int offset = cfIdx - pcase.centerX();
				if (offset > 0)
				{
					fprintf(codefile, "%.6ff * data->get(x + %d, y, z)", rkc[cfIdx], offset);
				}
				else if (offset < 0)
				{
					fprintf(codefile, "%.6ff * data->get(x - %d, y, z)", rkc[cfIdx], -offset);
				}
				else
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z)", rkc[cfIdx]);
				}

				if (cfIdx <= ppar)
				{
					fprintf(codefile, " + ");
				}
			}
			fprintf(codefile, ";\n");
		}

		// First perpendicular part
		Slau slauY(&cs, 1);
		Polynom coeffsY = slauY.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		int initCf = cs.LeftXIncluded() ? 2 : 1;
		int maxCf = cs.RightXIncluded() ? cs.pX() : cs.pX() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerX();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y + %d, z)", coeffsY[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y - %d, z)", coeffsY[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsY[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");

		// Second perpendicular part
		Slau slauZ(&cs, 2);
		Polynom coeffsZ = slauZ.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		initCf = cs.LeftYIncluded() ? 2 : 1;
		maxCf = cs.RightYIncluded() ? cs.pY() : cs.pY() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerY();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z + %d)", coeffsZ[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z - %d)", coeffsZ[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsZ[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");

		// Update value
		fprintf(codefile, "\treturn fabs(prs->get(x - 1, y, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);\n");
		fprintf(codefile, "}\n\n");
	}

	GenerateCrtFPArray(codefile, 'X', xNames);
	fclose(codefile);

	// Header generation
	FILE *hFile = fopen((filename + ".h").c_str(), "wt");
	if (hFile != NULL)
	{
		fprintf(hFile, "#pragma once\n");
		fprintf(hFile, "#include \"stdafx.h\"\n");
		fprintf(hFile, "#include \"Area3d.h\"\n\n");
		int sz = xNames.size();
		for (int i = 0; i < sz; i++)
		{
			fprintf(hFile, ("float " + xNames[i] + "(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum);\n").c_str());
		}
		xNames.clear();
		fclose(hFile);
	}
}

void Codegen::GenerateForY(const string &filename)
{
	gen.reset();
	FILE *codefile = fopen((filename + ".cpp").c_str(), "wt");
	fprintf(codefile, "#pragma once\n");
	fprintf(codefile, "#include \"%s\"\n\n", (filename + ".h").c_str());

	while (gen.has_next())
	{
		EnvCase cs = gen.next();
		sprintf(namebuffer, "Mouse_Y_XL%d_XR%d_ZL%d_ZR%d", cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		yNames.push_back(string(namebuffer));
		fprintf(codefile, "void Mouse_Y_XL%d_XR%d_ZL%d_ZR%d(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)\n",
				cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		fprintf(codefile, "{\n");
		// Write code here :)
		// Parallel part
		int ppar = p % 2 == 0 ? p : p + 1;
		if (ppar == 2)
		{
			fprintf(codefile, "\tfloat d2vx = data->get(x, y - 1, z) - 2.0f * data->get(x, y, z) + data->get(x, y + 1, z);\n");
		}
		else if (ppar == 4)
		{
			fprintf(codefile, "\tfloat d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;\n");
		}
		else
		{
			EnvCase pcase(ppar / 2, ppar / 2, 0, 0, ppar);
			Slau s(&pcase, 1);
			Polynom rkc = s.SolveForSecondDerivative();
			fprintf(codefile, "\tfloat d2vx = ");
			for (int cfIdx = 1; cfIdx <= ppar + 1; cfIdx++)
			{
				int offset = cfIdx - pcase.centerX();
				if (offset > 0)
				{
					fprintf(codefile, "%.6ff * data->get(x, y + %d, z)", rkc[cfIdx], offset);
				}
				else if (offset < 0)
				{
					fprintf(codefile, "%.6ff * data->get(x, y - %d, z)", rkc[cfIdx], -offset);
				}
				else
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z)", rkc[cfIdx]);
				}

				if (cfIdx <= ppar)
				{
					fprintf(codefile, " + ");
				}
			}
			fprintf(codefile, ";\n");
		}

		// First perpendicular part
		Slau slauY(&cs, 1);
		Polynom coeffsY = slauY.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		int initCf = cs.LeftXIncluded() ? 2 : 1;
		int maxCf = cs.RightXIncluded() ? cs.pX() : cs.pX() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerX();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x + %d, y, z)", coeffsY[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x - %d, y, z)", coeffsY[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsY[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");
		// Second perpendicular part
		Slau slauZ(&cs, 2);
		Polynom coeffsZ = slauZ.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		initCf = cs.LeftYIncluded() ? 2 : 1;
		maxCf = cs.RightYIncluded() ? cs.pY() : cs.pY() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerY();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z + %d)", coeffsZ[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z - %d)", coeffsZ[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsZ[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");

		// Update value
		fprintf(codefile, "\toutput->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum));\n");

		fprintf(codefile, "}\n\n");
	}

	GenerateFPArray(codefile, 'Y', yNames);
	fclose(codefile);

	// Header generation
	FILE *hFile = fopen((filename + ".h").c_str(), "wt");
	if (hFile != NULL)
	{
		fprintf(hFile, "#pragma once\n");
		fprintf(hFile, "#include \"stdafx.h\"\n");
		fprintf(hFile, "#include \"Area3d.h\"\n\n");
		int sz = yNames.size();
		for (int i = 0; i < sz; i++)
		{
			fprintf(hFile, ("void " + yNames[i] + "(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum);\n").c_str());
		}
		yNames.clear();
		fclose(hFile);
	}
}

void Codegen::GenerateCrtForY(const string &filename)
{
	gen.reset();
	FILE *codefile = fopen((filename + ".cpp").c_str(), "wt");
	fprintf(codefile, "#pragma once\n");
	fprintf(codefile, "#include \"%s\"\n\n", (filename + ".h").c_str());

	while (gen.has_next())
	{
		EnvCase cs = gen.next();
		sprintf(namebuffer, "Crt_Y_XL%d_XR%d_ZL%d_ZR%d", cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		yNames.push_back(string(namebuffer));
		fprintf(codefile, "float Crt_Y_XL%d_XR%d_ZL%d_ZR%d(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)\n",
				cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		fprintf(codefile, "{\n");
		// Write code here :)
		// Parallel part
		int ppar = p % 2 == 0 ? p : p + 1;
		if (ppar == 2)
		{
			fprintf(codefile, "\tfloat d2vx = data->get(x, y - 1, z) - 2.0f * data->get(x, y, z) + data->get(x, y + 1, z);\n");
		}
		else if (ppar == 4)
		{
			fprintf(codefile, "\tfloat d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;\n");
		}
		else
		{
			EnvCase pcase(ppar / 2, ppar / 2, 0, 0, ppar);
			Slau s(&pcase, 1);
			Polynom rkc = s.SolveForSecondDerivative();
			fprintf(codefile, "\tfloat d2vx = ");
			for (int cfIdx = 1; cfIdx <= ppar + 1; cfIdx++)
			{
				int offset = cfIdx - pcase.centerX();
				if (offset > 0)
				{
					fprintf(codefile, "%.6ff * data->get(x, y + %d, z)", rkc[cfIdx], offset);
				}
				else if (offset < 0)
				{
					fprintf(codefile, "%.6ff * data->get(x, y - %d, z)", rkc[cfIdx], -offset);
				}
				else
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z)", rkc[cfIdx]);
				}

				if (cfIdx <= ppar)
				{
					fprintf(codefile, " + ");
				}
			}
			fprintf(codefile, ";\n");
		}

		// First perpendicular part
		Slau slauY(&cs, 1);
		Polynom coeffsY = slauY.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		int initCf = cs.LeftXIncluded() ? 2 : 1;
		int maxCf = cs.RightXIncluded() ? cs.pX() : cs.pX() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerX();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x + %d, y, z)", coeffsY[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x - %d, y, z)", coeffsY[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsY[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");
		// Second perpendicular part
		Slau slauZ(&cs, 2);
		Polynom coeffsZ = slauZ.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		initCf = cs.LeftYIncluded() ? 2 : 1;
		maxCf = cs.RightYIncluded() ? cs.pY() : cs.pY() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerY();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z + %d)", coeffsZ[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z - %d)", coeffsZ[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsZ[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");

		// Update value
		fprintf(codefile, "\treturn fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);\n");

		fprintf(codefile, "}\n\n");
	}

	GenerateCrtFPArray(codefile, 'Y', yNames);
	fclose(codefile);

	// Header generation
	FILE *hFile = fopen((filename + ".h").c_str(), "wt");
	if (hFile != NULL)
	{
		fprintf(hFile, "#pragma once\n");
		fprintf(hFile, "#include \"stdafx.h\"\n");
		fprintf(hFile, "#include \"Area3d.h\"\n\n");
		int sz = yNames.size();
		for (int i = 0; i < sz; i++)
		{
			fprintf(hFile, ("float " + yNames[i] + "(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum);\n").c_str());
		}
		yNames.clear();
		fclose(hFile);
	}
}

void Codegen::GenerateForZ(const string &filename)
{
	gen.reset();
	FILE *codefile = fopen((filename + ".cpp").c_str(), "wt");
	fprintf(codefile, "#pragma once\n");
	fprintf(codefile, "#include \"%s\"\n\n", (filename + ".h").c_str());

	while (gen.has_next())
	{
		EnvCase cs = gen.next();
		sprintf(namebuffer, "Mouse_Z_XL%d_XR%d_YL%d_YR%d", cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		zNames.push_back(string(namebuffer));
		fprintf(codefile, "void Mouse_Z_XL%d_XR%d_YL%d_YR%d(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)\n",
				cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		fprintf(codefile, "{\n");
		// Write code here :)
		// Parallel part
		int ppar = p % 2 == 0 ? p : p + 1;
		if (ppar == 2)
		{
			fprintf(codefile, "\tfloat d2vx = data->get(x, y, z - 1) - 2.0f * data->get(x, y, z) + data->get(x, y, z + 1);\n");
		}
		else if (ppar == 4)
		{
			fprintf(codefile, "\tfloat d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;\n");
		}
		else
		{
			EnvCase pcase(ppar / 2, ppar / 2, 0, 0, ppar);
			Slau s(&pcase, 1);
			Polynom rkc = s.SolveForSecondDerivative();
			fprintf(codefile, "\tfloat d2vx = ");
			for (int cfIdx = 1; cfIdx <= ppar + 1; cfIdx++)
			{
				int offset = cfIdx - pcase.centerX();
				if (offset > 0)
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z + %d)", rkc[cfIdx], offset);
				}
				else if (offset < 0)
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z - %d)", rkc[cfIdx], -offset);
				}
				else
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z)", rkc[cfIdx]);
				}

				if (cfIdx <= ppar)
				{
					fprintf(codefile, " + ");
				}
			}
			fprintf(codefile, ";\n");
		}

		// First perpendicular part
		Slau slauY(&cs, 1);
		Polynom coeffsY = slauY.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		int initCf = cs.LeftXIncluded() ? 2 : 1;
		int maxCf = cs.RightXIncluded() ? cs.pX() : cs.pX() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerX();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x + %d, y, z)", coeffsY[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x - %d, y, z)", coeffsY[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsY[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");
		// Second perpendicular part
		Slau slauZ(&cs, 2);
		Polynom coeffsZ = slauZ.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		initCf = cs.LeftYIncluded() ? 2 : 1;
		maxCf = cs.RightYIncluded() ? cs.pY() : cs.pY() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerY();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y + %d, z)", coeffsZ[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y - %d, z)", coeffsZ[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsZ[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");

		// Update value
		fprintf(codefile, "\toutput->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));\n");

		fprintf(codefile, "}\n\n");
	}

	GenerateFPArray(codefile, 'Z', zNames);
	fclose(codefile);

	FILE *hFile = fopen((filename + ".h").c_str(), "wt");
	if (hFile != NULL)
	{
		fprintf(hFile, "#pragma once\n");
		fprintf(hFile, "#include \"stdafx.h\"\n");
		fprintf(hFile, "#include \"Area3d.h\"\n\n");
		int sz = zNames.size();
		for (int i = 0; i < sz; i++)
		{
			fprintf(hFile, ("void " + zNames[i] + "(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum);\n").c_str());
		}
		zNames.clear();
		fclose(hFile);
	}
}

void Codegen::GenerateCrtForZ(const string &filename)
{
	gen.reset();
	FILE *codefile = fopen((filename + ".cpp").c_str(), "wt");
	fprintf(codefile, "#pragma once\n");
	fprintf(codefile, "#include \"%s\"\n\n", (filename + ".h").c_str());

	while (gen.has_next())
	{
		EnvCase cs = gen.next();
		sprintf(namebuffer, "Crt_Z_XL%d_XR%d_YL%d_YR%d", cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		zNames.push_back(string(namebuffer));
		fprintf(codefile, "float Crt_Z_XL%d_XR%d_YL%d_YR%d(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)\n",
				cs.xLeft, cs.xRight, cs.yLeft, cs.yRight);
		fprintf(codefile, "{\n");
		// Write code here :)
		// Parallel part
		int ppar = p % 2 == 0 ? p : p + 1;
		if (ppar == 2)
		{
			fprintf(codefile, "\tfloat d2vx = data->get(x, y, z - 1) - 2.0f * data->get(x, y, z) + data->get(x, y, z + 1);\n");
		}
		else if (ppar == 4)
		{
			fprintf(codefile, "\tfloat d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;\n");
		}
		else
		{
			EnvCase pcase(ppar / 2, ppar / 2, 0, 0, ppar);
			Slau s(&pcase, 1);
			Polynom rkc = s.SolveForSecondDerivative();
			fprintf(codefile, "\tfloat d2vx = ");
			for (int cfIdx = 1; cfIdx <= ppar + 1; cfIdx++)
			{
				int offset = cfIdx - pcase.centerX();
				if (offset > 0)
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z + %d)", rkc[cfIdx], offset);
				}
				else if (offset < 0)
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z - %d)", rkc[cfIdx], -offset);
				}
				else
				{
					fprintf(codefile, "%.6ff * data->get(x, y, z)", rkc[cfIdx]);
				}

				if (cfIdx <= ppar)
				{
					fprintf(codefile, " + ");
				}
			}
			fprintf(codefile, ";\n");
		}

		// First perpendicular part
		Slau slauY(&cs, 1);
		Polynom coeffsY = slauY.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		int initCf = cs.LeftXIncluded() ? 2 : 1;
		int maxCf = cs.RightXIncluded() ? cs.pX() : cs.pX() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerX();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x + %d, y, z)", coeffsY[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x - %d, y, z)", coeffsY[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsY[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");
		// Second perpendicular part
		Slau slauZ(&cs, 2);
		Polynom coeffsZ = slauZ.SolveForSecondDerivative();
		fprintf(codefile, "\td2vx += ");
		initCf = cs.LeftYIncluded() ? 2 : 1;
		maxCf = cs.RightYIncluded() ? cs.pY() : cs.pY() + 1;
		for (int cfIdx = initCf; cfIdx <= maxCf; cfIdx++)
		{
			int offset = cfIdx - cs.centerY();
			if (offset > 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y + %d, z)", coeffsZ[cfIdx], offset);
			}
			else if (offset < 0)
			{
				fprintf(codefile, "%.6ff * data->get(x, y - %d, z)", coeffsZ[cfIdx], -offset);
			}
			else
			{
				fprintf(codefile, "%.6ff * data->get(x, y, z)", coeffsZ[cfIdx]);
			}

			if (cfIdx < maxCf)
			{
				fprintf(codefile, " + ");
			}
		}
		fprintf(codefile, ";\n");

		// Update value
		fprintf(codefile, "\treturn fabs(prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum);\n");

		fprintf(codefile, "}\n\n");
	}

	GenerateCrtFPArray(codefile, 'Z', zNames);
	fclose(codefile);

	FILE *hFile = fopen((filename + ".h").c_str(), "wt");
	if (hFile != NULL)
	{
		fprintf(hFile, "#pragma once\n");
		fprintf(hFile, "#include \"stdafx.h\"\n");
		fprintf(hFile, "#include \"Area3d.h\"\n\n");
		int sz = zNames.size();
		for (int i = 0; i < sz; i++)
		{
			fprintf(hFile, ("float " + zNames[i] + "(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum);\n").c_str());
		}
		zNames.clear();
		fclose(hFile);
	}
}

void Codegen::GenerateAccuracyFile(const char *filename)
{
	string filename_s = filename;
	FILE *hFile = fopen((filename_s + ".h").c_str(), "wt");
	if (hFile != NULL)
	{
		fprintf(hFile, "#pragma once\n");
		fprintf(hFile, "#define ACCURACY_ORDER %d\n", this->p);
		fclose(hFile);
	}
}

void Codegen::Generate(const char *filenameX, const char *filenameY, const char *filenameZ)
{
	GenerateForX(filenameX);
	GenerateForY(filenameY);
	GenerateForZ(filenameZ);
}

void Codegen::GenerateCrt(const char *filenameX, const char *filenameY, const char *filenameZ)
{
	GenerateCrtForX(filenameX);
	GenerateCrtForY(filenameY);
	GenerateCrtForZ(filenameZ);
}

void Codegen::GenerateFPArray(FILE *codefile, const char ltr, vector<string> &fnames)
{
	// Generate function pointer array
	fprintf(codefile, "void (*compFunc%c[]) (int, int, int, Area3d<float>*, Area3d<float>*, Area3d<float>*, float, float) =\n", ltr);
	fprintf(codefile, "{\n");
	int sz = fnames.size();
	for (int i = 0; i < sz; i++)
	{
		fprintf(codefile, ("\t" + fnames[i]).c_str());
		//fprintf(codefile, "\t%s", fnames[i].c_str());
		if (i != sz - 1)
		{
			fprintf(codefile, ",\n");
		}
		else
		{
			fprintf(codefile, "\n");
		}
	}
	fprintf(codefile, "};\n\n");
}

void Codegen::GenerateCrtFPArray(FILE *codefile, const char ltr, vector<string> &fnames)
{
	// Generate function pointer array
	fprintf(codefile, "float (*crtFunc%c[]) (int, int, int, Area3d<float>*, Area3d<float>*, float) =\n", ltr);
	fprintf(codefile, "{\n");
	int sz = fnames.size();
	for (int i = 0; i < sz; i++)
	{
		fprintf(codefile, ("\t" + fnames[i]).c_str());
		//fprintf(codefile, "\t%s", fnames[i].c_str());
		if (i != sz - 1)
		{
			fprintf(codefile, ",\n");
		}
		else
		{
			fprintf(codefile, "\n");
		}
	}
	fprintf(codefile, "};\n\n");
}