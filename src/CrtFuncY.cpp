#pragma once
#include "CrtFuncY.h"

float Crt_Y_XL0_XR0_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL0_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL1_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 2.666667f * data->get(x, y, z - 1) + -5.333334f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL0_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL2_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -0.600000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.400002f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL1_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 1.800001f * data->get(x, y, z - 1) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL0_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y, z + 1) + -0.600000f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL3_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 0.142853f * data->get(x, y, z - 3) + -0.533330f * data->get(x, y, z - 2) + 2.466670f * data->get(x, y, z - 1) + -5.428571f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL2_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -0.190474f * data->get(x, y, z - 2) + 1.533328f * data->get(x, y, z - 1) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL1_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 1.761905f * data->get(x, y, z - 1) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y, z + 1) + -0.190476f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL0_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y, z + 1) + -0.533333f * data->get(x, y, z + 2) + 0.142857f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL4_ZR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -0.009259f * data->get(x, y, z - 4) + 0.095236f * data->get(x, y, z - 3) + -0.500000f * data->get(x, y, z - 2) + 2.444445f * data->get(x, y, z - 1) + -5.416672f * data->get(x, y, z);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL3_ZR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 0.009259f * data->get(x, y, z - 3) + -0.142855f * data->get(x, y, z - 2) + 1.499996f * data->get(x, y, z - 1) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y, z + 1);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL2_ZR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -0.083333f * data->get(x, y, z - 2) + 1.333333f * data->get(x, y, z - 1) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y, z + 1) + -0.083333f * data->get(x, y, z + 2);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL1_ZR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 1.750001f * data->get(x, y, z - 1) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y, z + 1) + -0.142857f * data->get(x, y, z + 2) + 0.009259f * data->get(x, y, z + 3);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR0_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR0_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR1_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR0_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR1_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR2_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR0_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR1_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR2_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR3_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL4_XR0_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL3_XR1_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL2_XR2_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL1_XR3_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float Crt_Y_XL0_XR4_ZL0_ZR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* prs, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y - 2, z) + 16.0f * data->get(x, y - 1, z) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y + 1, z) - data->get(x, y + 2, z)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y, z + 1) + -0.500000f * data->get(x, y, z + 2) + 0.095238f * data->get(x, y, z + 3) + -0.009259f * data->get(x, y, z + 4);
	return fabs(prs->get(x, y - 1, z) - prs->get(x, y, z) + d2vx * revReynodlsNum);
}

float (*crtFuncY[]) (int, int, int, Area3d<float>*, Area3d<float>*, float) =
{
	Crt_Y_XL0_XR0_ZL0_ZR0,
	Crt_Y_XL1_XR0_ZL0_ZR0,
	Crt_Y_XL0_XR1_ZL0_ZR0,
	Crt_Y_XL2_XR0_ZL0_ZR0,
	Crt_Y_XL1_XR1_ZL0_ZR0,
	Crt_Y_XL0_XR2_ZL0_ZR0,
	Crt_Y_XL3_XR0_ZL0_ZR0,
	Crt_Y_XL2_XR1_ZL0_ZR0,
	Crt_Y_XL1_XR2_ZL0_ZR0,
	Crt_Y_XL0_XR3_ZL0_ZR0,
	Crt_Y_XL4_XR0_ZL0_ZR0,
	Crt_Y_XL3_XR1_ZL0_ZR0,
	Crt_Y_XL2_XR2_ZL0_ZR0,
	Crt_Y_XL1_XR3_ZL0_ZR0,
	Crt_Y_XL0_XR4_ZL0_ZR0,
	Crt_Y_XL0_XR0_ZL1_ZR0,
	Crt_Y_XL1_XR0_ZL1_ZR0,
	Crt_Y_XL0_XR1_ZL1_ZR0,
	Crt_Y_XL2_XR0_ZL1_ZR0,
	Crt_Y_XL1_XR1_ZL1_ZR0,
	Crt_Y_XL0_XR2_ZL1_ZR0,
	Crt_Y_XL3_XR0_ZL1_ZR0,
	Crt_Y_XL2_XR1_ZL1_ZR0,
	Crt_Y_XL1_XR2_ZL1_ZR0,
	Crt_Y_XL0_XR3_ZL1_ZR0,
	Crt_Y_XL4_XR0_ZL1_ZR0,
	Crt_Y_XL3_XR1_ZL1_ZR0,
	Crt_Y_XL2_XR2_ZL1_ZR0,
	Crt_Y_XL1_XR3_ZL1_ZR0,
	Crt_Y_XL0_XR4_ZL1_ZR0,
	Crt_Y_XL0_XR0_ZL0_ZR1,
	Crt_Y_XL1_XR0_ZL0_ZR1,
	Crt_Y_XL0_XR1_ZL0_ZR1,
	Crt_Y_XL2_XR0_ZL0_ZR1,
	Crt_Y_XL1_XR1_ZL0_ZR1,
	Crt_Y_XL0_XR2_ZL0_ZR1,
	Crt_Y_XL3_XR0_ZL0_ZR1,
	Crt_Y_XL2_XR1_ZL0_ZR1,
	Crt_Y_XL1_XR2_ZL0_ZR1,
	Crt_Y_XL0_XR3_ZL0_ZR1,
	Crt_Y_XL4_XR0_ZL0_ZR1,
	Crt_Y_XL3_XR1_ZL0_ZR1,
	Crt_Y_XL2_XR2_ZL0_ZR1,
	Crt_Y_XL1_XR3_ZL0_ZR1,
	Crt_Y_XL0_XR4_ZL0_ZR1,
	Crt_Y_XL0_XR0_ZL2_ZR0,
	Crt_Y_XL1_XR0_ZL2_ZR0,
	Crt_Y_XL0_XR1_ZL2_ZR0,
	Crt_Y_XL2_XR0_ZL2_ZR0,
	Crt_Y_XL1_XR1_ZL2_ZR0,
	Crt_Y_XL0_XR2_ZL2_ZR0,
	Crt_Y_XL3_XR0_ZL2_ZR0,
	Crt_Y_XL2_XR1_ZL2_ZR0,
	Crt_Y_XL1_XR2_ZL2_ZR0,
	Crt_Y_XL0_XR3_ZL2_ZR0,
	Crt_Y_XL4_XR0_ZL2_ZR0,
	Crt_Y_XL3_XR1_ZL2_ZR0,
	Crt_Y_XL2_XR2_ZL2_ZR0,
	Crt_Y_XL1_XR3_ZL2_ZR0,
	Crt_Y_XL0_XR4_ZL2_ZR0,
	Crt_Y_XL0_XR0_ZL1_ZR1,
	Crt_Y_XL1_XR0_ZL1_ZR1,
	Crt_Y_XL0_XR1_ZL1_ZR1,
	Crt_Y_XL2_XR0_ZL1_ZR1,
	Crt_Y_XL1_XR1_ZL1_ZR1,
	Crt_Y_XL0_XR2_ZL1_ZR1,
	Crt_Y_XL3_XR0_ZL1_ZR1,
	Crt_Y_XL2_XR1_ZL1_ZR1,
	Crt_Y_XL1_XR2_ZL1_ZR1,
	Crt_Y_XL0_XR3_ZL1_ZR1,
	Crt_Y_XL4_XR0_ZL1_ZR1,
	Crt_Y_XL3_XR1_ZL1_ZR1,
	Crt_Y_XL2_XR2_ZL1_ZR1,
	Crt_Y_XL1_XR3_ZL1_ZR1,
	Crt_Y_XL0_XR4_ZL1_ZR1,
	Crt_Y_XL0_XR0_ZL0_ZR2,
	Crt_Y_XL1_XR0_ZL0_ZR2,
	Crt_Y_XL0_XR1_ZL0_ZR2,
	Crt_Y_XL2_XR0_ZL0_ZR2,
	Crt_Y_XL1_XR1_ZL0_ZR2,
	Crt_Y_XL0_XR2_ZL0_ZR2,
	Crt_Y_XL3_XR0_ZL0_ZR2,
	Crt_Y_XL2_XR1_ZL0_ZR2,
	Crt_Y_XL1_XR2_ZL0_ZR2,
	Crt_Y_XL0_XR3_ZL0_ZR2,
	Crt_Y_XL4_XR0_ZL0_ZR2,
	Crt_Y_XL3_XR1_ZL0_ZR2,
	Crt_Y_XL2_XR2_ZL0_ZR2,
	Crt_Y_XL1_XR3_ZL0_ZR2,
	Crt_Y_XL0_XR4_ZL0_ZR2,
	Crt_Y_XL0_XR0_ZL3_ZR0,
	Crt_Y_XL1_XR0_ZL3_ZR0,
	Crt_Y_XL0_XR1_ZL3_ZR0,
	Crt_Y_XL2_XR0_ZL3_ZR0,
	Crt_Y_XL1_XR1_ZL3_ZR0,
	Crt_Y_XL0_XR2_ZL3_ZR0,
	Crt_Y_XL3_XR0_ZL3_ZR0,
	Crt_Y_XL2_XR1_ZL3_ZR0,
	Crt_Y_XL1_XR2_ZL3_ZR0,
	Crt_Y_XL0_XR3_ZL3_ZR0,
	Crt_Y_XL4_XR0_ZL3_ZR0,
	Crt_Y_XL3_XR1_ZL3_ZR0,
	Crt_Y_XL2_XR2_ZL3_ZR0,
	Crt_Y_XL1_XR3_ZL3_ZR0,
	Crt_Y_XL0_XR4_ZL3_ZR0,
	Crt_Y_XL0_XR0_ZL2_ZR1,
	Crt_Y_XL1_XR0_ZL2_ZR1,
	Crt_Y_XL0_XR1_ZL2_ZR1,
	Crt_Y_XL2_XR0_ZL2_ZR1,
	Crt_Y_XL1_XR1_ZL2_ZR1,
	Crt_Y_XL0_XR2_ZL2_ZR1,
	Crt_Y_XL3_XR0_ZL2_ZR1,
	Crt_Y_XL2_XR1_ZL2_ZR1,
	Crt_Y_XL1_XR2_ZL2_ZR1,
	Crt_Y_XL0_XR3_ZL2_ZR1,
	Crt_Y_XL4_XR0_ZL2_ZR1,
	Crt_Y_XL3_XR1_ZL2_ZR1,
	Crt_Y_XL2_XR2_ZL2_ZR1,
	Crt_Y_XL1_XR3_ZL2_ZR1,
	Crt_Y_XL0_XR4_ZL2_ZR1,
	Crt_Y_XL0_XR0_ZL1_ZR2,
	Crt_Y_XL1_XR0_ZL1_ZR2,
	Crt_Y_XL0_XR1_ZL1_ZR2,
	Crt_Y_XL2_XR0_ZL1_ZR2,
	Crt_Y_XL1_XR1_ZL1_ZR2,
	Crt_Y_XL0_XR2_ZL1_ZR2,
	Crt_Y_XL3_XR0_ZL1_ZR2,
	Crt_Y_XL2_XR1_ZL1_ZR2,
	Crt_Y_XL1_XR2_ZL1_ZR2,
	Crt_Y_XL0_XR3_ZL1_ZR2,
	Crt_Y_XL4_XR0_ZL1_ZR2,
	Crt_Y_XL3_XR1_ZL1_ZR2,
	Crt_Y_XL2_XR2_ZL1_ZR2,
	Crt_Y_XL1_XR3_ZL1_ZR2,
	Crt_Y_XL0_XR4_ZL1_ZR2,
	Crt_Y_XL0_XR0_ZL0_ZR3,
	Crt_Y_XL1_XR0_ZL0_ZR3,
	Crt_Y_XL0_XR1_ZL0_ZR3,
	Crt_Y_XL2_XR0_ZL0_ZR3,
	Crt_Y_XL1_XR1_ZL0_ZR3,
	Crt_Y_XL0_XR2_ZL0_ZR3,
	Crt_Y_XL3_XR0_ZL0_ZR3,
	Crt_Y_XL2_XR1_ZL0_ZR3,
	Crt_Y_XL1_XR2_ZL0_ZR3,
	Crt_Y_XL0_XR3_ZL0_ZR3,
	Crt_Y_XL4_XR0_ZL0_ZR3,
	Crt_Y_XL3_XR1_ZL0_ZR3,
	Crt_Y_XL2_XR2_ZL0_ZR3,
	Crt_Y_XL1_XR3_ZL0_ZR3,
	Crt_Y_XL0_XR4_ZL0_ZR3,
	Crt_Y_XL0_XR0_ZL4_ZR0,
	Crt_Y_XL1_XR0_ZL4_ZR0,
	Crt_Y_XL0_XR1_ZL4_ZR0,
	Crt_Y_XL2_XR0_ZL4_ZR0,
	Crt_Y_XL1_XR1_ZL4_ZR0,
	Crt_Y_XL0_XR2_ZL4_ZR0,
	Crt_Y_XL3_XR0_ZL4_ZR0,
	Crt_Y_XL2_XR1_ZL4_ZR0,
	Crt_Y_XL1_XR2_ZL4_ZR0,
	Crt_Y_XL0_XR3_ZL4_ZR0,
	Crt_Y_XL4_XR0_ZL4_ZR0,
	Crt_Y_XL3_XR1_ZL4_ZR0,
	Crt_Y_XL2_XR2_ZL4_ZR0,
	Crt_Y_XL1_XR3_ZL4_ZR0,
	Crt_Y_XL0_XR4_ZL4_ZR0,
	Crt_Y_XL0_XR0_ZL3_ZR1,
	Crt_Y_XL1_XR0_ZL3_ZR1,
	Crt_Y_XL0_XR1_ZL3_ZR1,
	Crt_Y_XL2_XR0_ZL3_ZR1,
	Crt_Y_XL1_XR1_ZL3_ZR1,
	Crt_Y_XL0_XR2_ZL3_ZR1,
	Crt_Y_XL3_XR0_ZL3_ZR1,
	Crt_Y_XL2_XR1_ZL3_ZR1,
	Crt_Y_XL1_XR2_ZL3_ZR1,
	Crt_Y_XL0_XR3_ZL3_ZR1,
	Crt_Y_XL4_XR0_ZL3_ZR1,
	Crt_Y_XL3_XR1_ZL3_ZR1,
	Crt_Y_XL2_XR2_ZL3_ZR1,
	Crt_Y_XL1_XR3_ZL3_ZR1,
	Crt_Y_XL0_XR4_ZL3_ZR1,
	Crt_Y_XL0_XR0_ZL2_ZR2,
	Crt_Y_XL1_XR0_ZL2_ZR2,
	Crt_Y_XL0_XR1_ZL2_ZR2,
	Crt_Y_XL2_XR0_ZL2_ZR2,
	Crt_Y_XL1_XR1_ZL2_ZR2,
	Crt_Y_XL0_XR2_ZL2_ZR2,
	Crt_Y_XL3_XR0_ZL2_ZR2,
	Crt_Y_XL2_XR1_ZL2_ZR2,
	Crt_Y_XL1_XR2_ZL2_ZR2,
	Crt_Y_XL0_XR3_ZL2_ZR2,
	Crt_Y_XL4_XR0_ZL2_ZR2,
	Crt_Y_XL3_XR1_ZL2_ZR2,
	Crt_Y_XL2_XR2_ZL2_ZR2,
	Crt_Y_XL1_XR3_ZL2_ZR2,
	Crt_Y_XL0_XR4_ZL2_ZR2,
	Crt_Y_XL0_XR0_ZL1_ZR3,
	Crt_Y_XL1_XR0_ZL1_ZR3,
	Crt_Y_XL0_XR1_ZL1_ZR3,
	Crt_Y_XL2_XR0_ZL1_ZR3,
	Crt_Y_XL1_XR1_ZL1_ZR3,
	Crt_Y_XL0_XR2_ZL1_ZR3,
	Crt_Y_XL3_XR0_ZL1_ZR3,
	Crt_Y_XL2_XR1_ZL1_ZR3,
	Crt_Y_XL1_XR2_ZL1_ZR3,
	Crt_Y_XL0_XR3_ZL1_ZR3,
	Crt_Y_XL4_XR0_ZL1_ZR3,
	Crt_Y_XL3_XR1_ZL1_ZR3,
	Crt_Y_XL2_XR2_ZL1_ZR3,
	Crt_Y_XL1_XR3_ZL1_ZR3,
	Crt_Y_XL0_XR4_ZL1_ZR3,
	Crt_Y_XL0_XR0_ZL0_ZR4,
	Crt_Y_XL1_XR0_ZL0_ZR4,
	Crt_Y_XL0_XR1_ZL0_ZR4,
	Crt_Y_XL2_XR0_ZL0_ZR4,
	Crt_Y_XL1_XR1_ZL0_ZR4,
	Crt_Y_XL0_XR2_ZL0_ZR4,
	Crt_Y_XL3_XR0_ZL0_ZR4,
	Crt_Y_XL2_XR1_ZL0_ZR4,
	Crt_Y_XL1_XR2_ZL0_ZR4,
	Crt_Y_XL0_XR3_ZL0_ZR4,
	Crt_Y_XL4_XR0_ZL0_ZR4,
	Crt_Y_XL3_XR1_ZL0_ZR4,
	Crt_Y_XL2_XR2_ZL0_ZR4,
	Crt_Y_XL1_XR3_ZL0_ZR4,
	Crt_Y_XL0_XR4_ZL0_ZR4
};

