#ifndef SLAU_H
#define SLAU_H

#include "Polynom.h"
#include "EnvCaseGenerator.h"

class Slau
{
	int p;
	float **A;
	Polynom **B;

	static float *GetTaylorCoeffs(float delta, int maxp);

	void SwapRows(int a, int b);
	int SeekRow(int col);
	void AddToRow(int row, int ccol);
	void Trianglize();

public:
	void printA();
	void printB();
	Slau(EnvCase *cs, int firstOrSecond);
	Polynom &SolveForSecondDerivative();
	~Slau(void);
};

#endif // SLAU_H