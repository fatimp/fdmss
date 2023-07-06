#include "EnvCaseGenerator.h"


EnvCaseGenerator::EnvCaseGenerator(int p): pmax(p), px(0), offsetx(0), py(0), offsety(0) { }

bool EnvCaseGenerator::has_next_x()
{
	return px <= pmax;
}

void EnvCaseGenerator::reset_x()
{
	px = 0;
	offsetx = 0;
}

void EnvCaseGenerator::inc_x()
{
	offsetx++;
	if (offsetx > px)
	{
		px++;
		offsetx = 0;
	}

	if (!has_next_x())
	{
		reset_x();
		inc_y();
	}
}

bool EnvCaseGenerator::has_next()
{
	return py <= pmax;
}

void EnvCaseGenerator::inc_y()
{
	offsety++;
	if (offsety > py)
	{
		py++;
		offsety = 0;
	}
}

void EnvCaseGenerator::reset()
{
	px = 0;
	offsetx = 0;
	py = 0;
	offsety = 0;
}

EnvCase EnvCaseGenerator::next()
{
	EnvCase cs(px - offsetx, offsetx, py - offsety, offsety, pmax);
	inc_x();	
	return cs;
}