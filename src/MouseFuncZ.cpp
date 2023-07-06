#pragma once
#include "MouseFuncZ.h"

void Mouse_Z_XL0_XR0_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL0_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -8.000000f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL1_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 2.666667f * data->get(x, y - 1, z) + -5.333334f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL0_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL2_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -0.600000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.400002f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL1_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 1.800001f * data->get(x, y - 1, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL0_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x, y + 1, z) + -0.600000f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL3_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 0.142853f * data->get(x, y - 3, z) + -0.533330f * data->get(x, y - 2, z) + 2.466670f * data->get(x, y - 1, z) + -5.428571f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL2_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -0.190474f * data->get(x, y - 2, z) + 1.533328f * data->get(x, y - 1, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL1_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 1.761905f * data->get(x, y - 1, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x, y + 1, z) + -0.190476f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL0_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x, y + 1, z) + -0.533333f * data->get(x, y + 2, z) + 0.142857f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL4_YR0(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -0.009259f * data->get(x, y - 4, z) + 0.095236f * data->get(x, y - 3, z) + -0.500000f * data->get(x, y - 2, z) + 2.444445f * data->get(x, y - 1, z) + -5.416672f * data->get(x, y, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL3_YR1(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 0.009259f * data->get(x, y - 3, z) + -0.142855f * data->get(x, y - 2, z) + 1.499996f * data->get(x, y - 1, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x, y + 1, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL2_YR2(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -0.083333f * data->get(x, y - 2, z) + 1.333333f * data->get(x, y - 1, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x, y + 1, z) + -0.083333f * data->get(x, y + 2, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL1_YR3(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += 1.750001f * data->get(x, y - 1, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x, y + 1, z) + -0.142857f * data->get(x, y + 2, z) + 0.009259f * data->get(x, y + 3, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR0_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -8.000000f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR0_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 2.666667f * data->get(x - 1, y, z) + -5.333334f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR1_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.333333f * data->get(x, y, z) + 2.666667f * data->get(x + 1, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR0_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.600000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.400002f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR1_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.800001f * data->get(x - 1, y, z) + -2.888890f * data->get(x, y, z) + 1.800000f * data->get(x + 1, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR2_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.400001f * data->get(x, y, z) + 2.444445f * data->get(x + 1, y, z) + -0.600000f * data->get(x + 2, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR0_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.142853f * data->get(x - 3, y, z) + -0.533330f * data->get(x - 2, y, z) + 2.466670f * data->get(x - 1, y, z) + -5.428571f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR1_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.190474f * data->get(x - 2, y, z) + 1.533328f * data->get(x - 1, y, z) + -2.799994f * data->get(x, y, z) + 1.761902f * data->get(x + 1, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR2_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.761905f * data->get(x - 1, y, z) + -2.800000f * data->get(x, y, z) + 1.533333f * data->get(x + 1, y, z) + -0.190476f * data->get(x + 2, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR3_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.428572f * data->get(x, y, z) + 2.466666f * data->get(x + 1, y, z) + -0.533333f * data->get(x + 2, y, z) + 0.142857f * data->get(x + 3, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL4_XR0_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.009259f * data->get(x - 4, y, z) + 0.095236f * data->get(x - 3, y, z) + -0.500000f * data->get(x - 2, y, z) + 2.444445f * data->get(x - 1, y, z) + -5.416672f * data->get(x, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL3_XR1_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 0.009259f * data->get(x - 3, y, z) + -0.142855f * data->get(x - 2, y, z) + 1.499996f * data->get(x - 1, y, z) + -2.777770f * data->get(x, y, z) + 1.749995f * data->get(x + 1, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL2_XR2_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -0.083333f * data->get(x - 2, y, z) + 1.333333f * data->get(x - 1, y, z) + -2.500000f * data->get(x, y, z) + 1.333333f * data->get(x + 1, y, z) + -0.083333f * data->get(x + 2, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL1_XR3_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += 1.750001f * data->get(x - 1, y, z) + -2.777778f * data->get(x, y, z) + 1.500000f * data->get(x + 1, y, z) + -0.142857f * data->get(x + 2, y, z) + 0.009259f * data->get(x + 3, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void Mouse_Z_XL0_XR4_YL0_YR4(int x, int y, int z, Area3d<float>* data, Area3d<float>* output, Area3d<float>* prs, float timeStep, float revReynodlsNum)
{
	float d2vx = (-data->get(x, y, z - 2) + 16.0f * data->get(x, y, z - 1) - 30.0f * data->get(x, y, z) + 16.0f * data->get(x, y, z + 1) - data->get(x, y, z + 2)) / 12.0f;
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x + 1, y, z) + -0.500000f * data->get(x + 2, y, z) + 0.095238f * data->get(x + 3, y, z) + -0.009259f * data->get(x + 4, y, z);
	d2vx += -5.416667f * data->get(x, y, z) + 2.444444f * data->get(x, y + 1, z) + -0.500000f * data->get(x, y + 2, z) + 0.095238f * data->get(x, y + 3, z) + -0.009259f * data->get(x, y + 4, z);
	output->set(x, y, z, data->get(x, y, z) + timeStep * (prs->get(x, y, z - 1) - prs->get(x, y, z) + d2vx * revReynodlsNum));
}

void (*compFuncZ[]) (int, int, int, Area3d<float>*, Area3d<float>*, Area3d<float>*, float, float) =
{
	Mouse_Z_XL0_XR0_YL0_YR0,
	Mouse_Z_XL1_XR0_YL0_YR0,
	Mouse_Z_XL0_XR1_YL0_YR0,
	Mouse_Z_XL2_XR0_YL0_YR0,
	Mouse_Z_XL1_XR1_YL0_YR0,
	Mouse_Z_XL0_XR2_YL0_YR0,
	Mouse_Z_XL3_XR0_YL0_YR0,
	Mouse_Z_XL2_XR1_YL0_YR0,
	Mouse_Z_XL1_XR2_YL0_YR0,
	Mouse_Z_XL0_XR3_YL0_YR0,
	Mouse_Z_XL4_XR0_YL0_YR0,
	Mouse_Z_XL3_XR1_YL0_YR0,
	Mouse_Z_XL2_XR2_YL0_YR0,
	Mouse_Z_XL1_XR3_YL0_YR0,
	Mouse_Z_XL0_XR4_YL0_YR0,
	Mouse_Z_XL0_XR0_YL1_YR0,
	Mouse_Z_XL1_XR0_YL1_YR0,
	Mouse_Z_XL0_XR1_YL1_YR0,
	Mouse_Z_XL2_XR0_YL1_YR0,
	Mouse_Z_XL1_XR1_YL1_YR0,
	Mouse_Z_XL0_XR2_YL1_YR0,
	Mouse_Z_XL3_XR0_YL1_YR0,
	Mouse_Z_XL2_XR1_YL1_YR0,
	Mouse_Z_XL1_XR2_YL1_YR0,
	Mouse_Z_XL0_XR3_YL1_YR0,
	Mouse_Z_XL4_XR0_YL1_YR0,
	Mouse_Z_XL3_XR1_YL1_YR0,
	Mouse_Z_XL2_XR2_YL1_YR0,
	Mouse_Z_XL1_XR3_YL1_YR0,
	Mouse_Z_XL0_XR4_YL1_YR0,
	Mouse_Z_XL0_XR0_YL0_YR1,
	Mouse_Z_XL1_XR0_YL0_YR1,
	Mouse_Z_XL0_XR1_YL0_YR1,
	Mouse_Z_XL2_XR0_YL0_YR1,
	Mouse_Z_XL1_XR1_YL0_YR1,
	Mouse_Z_XL0_XR2_YL0_YR1,
	Mouse_Z_XL3_XR0_YL0_YR1,
	Mouse_Z_XL2_XR1_YL0_YR1,
	Mouse_Z_XL1_XR2_YL0_YR1,
	Mouse_Z_XL0_XR3_YL0_YR1,
	Mouse_Z_XL4_XR0_YL0_YR1,
	Mouse_Z_XL3_XR1_YL0_YR1,
	Mouse_Z_XL2_XR2_YL0_YR1,
	Mouse_Z_XL1_XR3_YL0_YR1,
	Mouse_Z_XL0_XR4_YL0_YR1,
	Mouse_Z_XL0_XR0_YL2_YR0,
	Mouse_Z_XL1_XR0_YL2_YR0,
	Mouse_Z_XL0_XR1_YL2_YR0,
	Mouse_Z_XL2_XR0_YL2_YR0,
	Mouse_Z_XL1_XR1_YL2_YR0,
	Mouse_Z_XL0_XR2_YL2_YR0,
	Mouse_Z_XL3_XR0_YL2_YR0,
	Mouse_Z_XL2_XR1_YL2_YR0,
	Mouse_Z_XL1_XR2_YL2_YR0,
	Mouse_Z_XL0_XR3_YL2_YR0,
	Mouse_Z_XL4_XR0_YL2_YR0,
	Mouse_Z_XL3_XR1_YL2_YR0,
	Mouse_Z_XL2_XR2_YL2_YR0,
	Mouse_Z_XL1_XR3_YL2_YR0,
	Mouse_Z_XL0_XR4_YL2_YR0,
	Mouse_Z_XL0_XR0_YL1_YR1,
	Mouse_Z_XL1_XR0_YL1_YR1,
	Mouse_Z_XL0_XR1_YL1_YR1,
	Mouse_Z_XL2_XR0_YL1_YR1,
	Mouse_Z_XL1_XR1_YL1_YR1,
	Mouse_Z_XL0_XR2_YL1_YR1,
	Mouse_Z_XL3_XR0_YL1_YR1,
	Mouse_Z_XL2_XR1_YL1_YR1,
	Mouse_Z_XL1_XR2_YL1_YR1,
	Mouse_Z_XL0_XR3_YL1_YR1,
	Mouse_Z_XL4_XR0_YL1_YR1,
	Mouse_Z_XL3_XR1_YL1_YR1,
	Mouse_Z_XL2_XR2_YL1_YR1,
	Mouse_Z_XL1_XR3_YL1_YR1,
	Mouse_Z_XL0_XR4_YL1_YR1,
	Mouse_Z_XL0_XR0_YL0_YR2,
	Mouse_Z_XL1_XR0_YL0_YR2,
	Mouse_Z_XL0_XR1_YL0_YR2,
	Mouse_Z_XL2_XR0_YL0_YR2,
	Mouse_Z_XL1_XR1_YL0_YR2,
	Mouse_Z_XL0_XR2_YL0_YR2,
	Mouse_Z_XL3_XR0_YL0_YR2,
	Mouse_Z_XL2_XR1_YL0_YR2,
	Mouse_Z_XL1_XR2_YL0_YR2,
	Mouse_Z_XL0_XR3_YL0_YR2,
	Mouse_Z_XL4_XR0_YL0_YR2,
	Mouse_Z_XL3_XR1_YL0_YR2,
	Mouse_Z_XL2_XR2_YL0_YR2,
	Mouse_Z_XL1_XR3_YL0_YR2,
	Mouse_Z_XL0_XR4_YL0_YR2,
	Mouse_Z_XL0_XR0_YL3_YR0,
	Mouse_Z_XL1_XR0_YL3_YR0,
	Mouse_Z_XL0_XR1_YL3_YR0,
	Mouse_Z_XL2_XR0_YL3_YR0,
	Mouse_Z_XL1_XR1_YL3_YR0,
	Mouse_Z_XL0_XR2_YL3_YR0,
	Mouse_Z_XL3_XR0_YL3_YR0,
	Mouse_Z_XL2_XR1_YL3_YR0,
	Mouse_Z_XL1_XR2_YL3_YR0,
	Mouse_Z_XL0_XR3_YL3_YR0,
	Mouse_Z_XL4_XR0_YL3_YR0,
	Mouse_Z_XL3_XR1_YL3_YR0,
	Mouse_Z_XL2_XR2_YL3_YR0,
	Mouse_Z_XL1_XR3_YL3_YR0,
	Mouse_Z_XL0_XR4_YL3_YR0,
	Mouse_Z_XL0_XR0_YL2_YR1,
	Mouse_Z_XL1_XR0_YL2_YR1,
	Mouse_Z_XL0_XR1_YL2_YR1,
	Mouse_Z_XL2_XR0_YL2_YR1,
	Mouse_Z_XL1_XR1_YL2_YR1,
	Mouse_Z_XL0_XR2_YL2_YR1,
	Mouse_Z_XL3_XR0_YL2_YR1,
	Mouse_Z_XL2_XR1_YL2_YR1,
	Mouse_Z_XL1_XR2_YL2_YR1,
	Mouse_Z_XL0_XR3_YL2_YR1,
	Mouse_Z_XL4_XR0_YL2_YR1,
	Mouse_Z_XL3_XR1_YL2_YR1,
	Mouse_Z_XL2_XR2_YL2_YR1,
	Mouse_Z_XL1_XR3_YL2_YR1,
	Mouse_Z_XL0_XR4_YL2_YR1,
	Mouse_Z_XL0_XR0_YL1_YR2,
	Mouse_Z_XL1_XR0_YL1_YR2,
	Mouse_Z_XL0_XR1_YL1_YR2,
	Mouse_Z_XL2_XR0_YL1_YR2,
	Mouse_Z_XL1_XR1_YL1_YR2,
	Mouse_Z_XL0_XR2_YL1_YR2,
	Mouse_Z_XL3_XR0_YL1_YR2,
	Mouse_Z_XL2_XR1_YL1_YR2,
	Mouse_Z_XL1_XR2_YL1_YR2,
	Mouse_Z_XL0_XR3_YL1_YR2,
	Mouse_Z_XL4_XR0_YL1_YR2,
	Mouse_Z_XL3_XR1_YL1_YR2,
	Mouse_Z_XL2_XR2_YL1_YR2,
	Mouse_Z_XL1_XR3_YL1_YR2,
	Mouse_Z_XL0_XR4_YL1_YR2,
	Mouse_Z_XL0_XR0_YL0_YR3,
	Mouse_Z_XL1_XR0_YL0_YR3,
	Mouse_Z_XL0_XR1_YL0_YR3,
	Mouse_Z_XL2_XR0_YL0_YR3,
	Mouse_Z_XL1_XR1_YL0_YR3,
	Mouse_Z_XL0_XR2_YL0_YR3,
	Mouse_Z_XL3_XR0_YL0_YR3,
	Mouse_Z_XL2_XR1_YL0_YR3,
	Mouse_Z_XL1_XR2_YL0_YR3,
	Mouse_Z_XL0_XR3_YL0_YR3,
	Mouse_Z_XL4_XR0_YL0_YR3,
	Mouse_Z_XL3_XR1_YL0_YR3,
	Mouse_Z_XL2_XR2_YL0_YR3,
	Mouse_Z_XL1_XR3_YL0_YR3,
	Mouse_Z_XL0_XR4_YL0_YR3,
	Mouse_Z_XL0_XR0_YL4_YR0,
	Mouse_Z_XL1_XR0_YL4_YR0,
	Mouse_Z_XL0_XR1_YL4_YR0,
	Mouse_Z_XL2_XR0_YL4_YR0,
	Mouse_Z_XL1_XR1_YL4_YR0,
	Mouse_Z_XL0_XR2_YL4_YR0,
	Mouse_Z_XL3_XR0_YL4_YR0,
	Mouse_Z_XL2_XR1_YL4_YR0,
	Mouse_Z_XL1_XR2_YL4_YR0,
	Mouse_Z_XL0_XR3_YL4_YR0,
	Mouse_Z_XL4_XR0_YL4_YR0,
	Mouse_Z_XL3_XR1_YL4_YR0,
	Mouse_Z_XL2_XR2_YL4_YR0,
	Mouse_Z_XL1_XR3_YL4_YR0,
	Mouse_Z_XL0_XR4_YL4_YR0,
	Mouse_Z_XL0_XR0_YL3_YR1,
	Mouse_Z_XL1_XR0_YL3_YR1,
	Mouse_Z_XL0_XR1_YL3_YR1,
	Mouse_Z_XL2_XR0_YL3_YR1,
	Mouse_Z_XL1_XR1_YL3_YR1,
	Mouse_Z_XL0_XR2_YL3_YR1,
	Mouse_Z_XL3_XR0_YL3_YR1,
	Mouse_Z_XL2_XR1_YL3_YR1,
	Mouse_Z_XL1_XR2_YL3_YR1,
	Mouse_Z_XL0_XR3_YL3_YR1,
	Mouse_Z_XL4_XR0_YL3_YR1,
	Mouse_Z_XL3_XR1_YL3_YR1,
	Mouse_Z_XL2_XR2_YL3_YR1,
	Mouse_Z_XL1_XR3_YL3_YR1,
	Mouse_Z_XL0_XR4_YL3_YR1,
	Mouse_Z_XL0_XR0_YL2_YR2,
	Mouse_Z_XL1_XR0_YL2_YR2,
	Mouse_Z_XL0_XR1_YL2_YR2,
	Mouse_Z_XL2_XR0_YL2_YR2,
	Mouse_Z_XL1_XR1_YL2_YR2,
	Mouse_Z_XL0_XR2_YL2_YR2,
	Mouse_Z_XL3_XR0_YL2_YR2,
	Mouse_Z_XL2_XR1_YL2_YR2,
	Mouse_Z_XL1_XR2_YL2_YR2,
	Mouse_Z_XL0_XR3_YL2_YR2,
	Mouse_Z_XL4_XR0_YL2_YR2,
	Mouse_Z_XL3_XR1_YL2_YR2,
	Mouse_Z_XL2_XR2_YL2_YR2,
	Mouse_Z_XL1_XR3_YL2_YR2,
	Mouse_Z_XL0_XR4_YL2_YR2,
	Mouse_Z_XL0_XR0_YL1_YR3,
	Mouse_Z_XL1_XR0_YL1_YR3,
	Mouse_Z_XL0_XR1_YL1_YR3,
	Mouse_Z_XL2_XR0_YL1_YR3,
	Mouse_Z_XL1_XR1_YL1_YR3,
	Mouse_Z_XL0_XR2_YL1_YR3,
	Mouse_Z_XL3_XR0_YL1_YR3,
	Mouse_Z_XL2_XR1_YL1_YR3,
	Mouse_Z_XL1_XR2_YL1_YR3,
	Mouse_Z_XL0_XR3_YL1_YR3,
	Mouse_Z_XL4_XR0_YL1_YR3,
	Mouse_Z_XL3_XR1_YL1_YR3,
	Mouse_Z_XL2_XR2_YL1_YR3,
	Mouse_Z_XL1_XR3_YL1_YR3,
	Mouse_Z_XL0_XR4_YL1_YR3,
	Mouse_Z_XL0_XR0_YL0_YR4,
	Mouse_Z_XL1_XR0_YL0_YR4,
	Mouse_Z_XL0_XR1_YL0_YR4,
	Mouse_Z_XL2_XR0_YL0_YR4,
	Mouse_Z_XL1_XR1_YL0_YR4,
	Mouse_Z_XL0_XR2_YL0_YR4,
	Mouse_Z_XL3_XR0_YL0_YR4,
	Mouse_Z_XL2_XR1_YL0_YR4,
	Mouse_Z_XL1_XR2_YL0_YR4,
	Mouse_Z_XL0_XR3_YL0_YR4,
	Mouse_Z_XL4_XR0_YL0_YR4,
	Mouse_Z_XL3_XR1_YL0_YR4,
	Mouse_Z_XL2_XR2_YL0_YR4,
	Mouse_Z_XL1_XR3_YL0_YR4,
	Mouse_Z_XL0_XR4_YL0_YR4
};

