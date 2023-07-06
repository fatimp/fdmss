#ifndef CODEGEN_H
#define CODEGEN_H

#include "stdafx.h"
#include "EnvCaseGenerator.h"
#include "Slau.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Codegen
{
	EnvCaseGenerator gen;
	int p;
	char namebuffer[256];
	vector<string> xNames;
	vector<string> yNames;
	vector<string> zNames;

	void GenerateForX(const string &filename);
	void GenerateForY(const string &filename);
	void GenerateForZ(const string &filename);
	void GenerateCrtForX(const string &filename);
	void GenerateCrtForY(const string &filename);
	void GenerateCrtForZ(const string &filename);

	void GenerateFPArray(FILE *codefile, const char ltr, vector<string> &fnames);
	void GenerateCrtFPArray(FILE *codefile, const char ltr, vector<string> &fnames);

public:
	Codegen(int p);
	void GenerateAccuracyFile(const char *filename);
	void Generate(const char *filenameX, const char *filenameY, const char *filenameZ);
	void GenerateCrt(const char *filenameX, const char *filenameY, const char *filenameZ);
};

#endif // CODEGEN_H