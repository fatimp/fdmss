#ifndef ENV_CASE_GENERATOR_H
#define ENV_CASE_GENERATOR_H

struct EnvCase
{
	int xLeft;
	int xRight;
	int yLeft;
	int yRight;
	int p;

	EnvCase(int _xLeft, int _xRight, int _yLeft, int _yRight, int _p) : xLeft(_xLeft), xRight(_xRight), yLeft(_yLeft), yRight(_yRight), p(_p)
	{
	}

	int centerX()
	{
		return xLeft + 1 + (LeftXIncluded() ? 1 : 0);
	}

	int centerY()
	{
		return yLeft + 1 + (LeftYIncluded() ? 1 : 0);
	}

	int pX()
	{
		int s = xLeft + xRight;
		if (s < p)
		{
			return s + 2;
		}
		else if (xLeft != xRight)
		{
			return s + 1;
		}
		else
		{
			return s;
		}
	}

	int pY()
	{
		int s = yLeft + yRight;
		if (s < p)
		{
			return s + 2;
		}
		else if (yLeft != yRight)
		{
			return s + 1;
		}
		else
		{
			return s;
		}
	}

	bool LeftXIncluded()
	{
		int s = xLeft + xRight;
		if (s < p)
		{
			return true;
		}
		else if (xLeft < xRight)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool RightXIncluded()
	{
		int s = xLeft + xRight;
		if (s < p)
		{
			return true;
		}
		else if (xLeft > xRight)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool LeftYIncluded()
	{
		int s = yLeft + yRight;
		if (s < p)
		{
			return true;
		}
		else if (yLeft < yRight)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool RightYIncluded()
	{
		int s = yLeft + yRight;
		if (s < p)
		{
			return true;
		}
		else if (yLeft > yRight)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetIndexInFuncArray()
	{
		int sx = xLeft + xRight;
		int sy = yLeft + yRight;
		int sect = (p + 2) * (p + 1) / 2;
		int lower = (sx + 1) * sx / 2 + xRight;
		int higher = (sy + 1) * sy / 2 + yRight;
		return higher * sect + lower;
	}

	static int GetIndexInFuncArrayS(int lx, int rx, int ly, int ry, int p)
	{
		int sx = lx + rx;
		int sy = ly + ry;
		int sect = (p + 2) * (p + 1) / 2;
		int lower = (sx + 1) * sx / 2 + rx;
		int higher = (sy + 1) * sy / 2 + ry;
		return higher * sect + lower;
	}
};

class EnvCaseGenerator
{
	const int pmax;
	int px, py;
	int offsetx, offsety;

	bool has_next_x();
	void reset_x();
	void inc_x();
	void inc_y();

public:
	EnvCaseGenerator(int p);

	void reset();
	bool has_next();
	EnvCase next();
};

#endif // ENV_CASE_GENERATOR_H