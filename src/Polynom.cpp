#include "Polynom.h"

Polynom::Polynom(int p): pData(NULL), P(p)
{
	pData = new float[p + 1];
	for (int i = 0; i <= p; i++)
	{
		pData[i] = 0.0f;
	}
}

Polynom* Polynom::operator+(const Polynom& src) const
{
	int maxp = this->P > src.P ? this->P : src.P;
	int minp = this->P < src.P ? this->P : src.P;
	Polynom* res = new Polynom(maxp);
	for (int i = 0; i <= minp; i++)
	{
		res->pData[i] = this->pData[i] + src.pData[i];
	}
	return res;
}

Polynom Polynom::operator +=(const Polynom& src)
{
	int maxp = this->P > src.P ? this->P : src.P;
	int minp = this->P < src.P ? this->P : src.P;
	Polynom* res = new Polynom(maxp);
	for (int i = 0; i <= minp; i++)
	{
		this->pData[i] += src.pData[i];
	}
	return *this;
}

Polynom* Polynom::operator-(const Polynom& src) const
{
	int maxp = this->P > src.P ? this->P : src.P;
	int minp = this->P < src.P ? this->P : src.P;
	Polynom* res = new Polynom(maxp);
	for (int i = 0; i <= minp; i++)
	{
		res->pData[i] = this->pData[i] - src.pData[i];
	}
	return res;
}

//Polynom* Polynom::operator +(const float num) const
//{
	//Polynom* res = new Polynom(P);
	//res->pData[0] = this->pData[0];
    //// Windows memcpy_s(void* dest, size_t numberOfElements, const void* source, size_t count);
    //// Therefore this is copying only 4 elements (sizeof(float) == 4) from this
    //// to res. The first element is copied in the assignment above.
    //// The numberofelements argument is not an element size. It should be the
    //// number of elements (or size) of the destination array.
    //// First, this is a bizarre way to copy the data.
    //// Second, I don't see how this represents addition. If anything, it could
    //// be called a clone operation.
    //// I will replicate this as-is with a standard memcpy now, but I don't like
    //// it!
	////memcpy_s(res->pData + 1, sizeof(float), this->pData + 1, P);
	//memcpy(res->pData + 1, this->pData + 1, P);
	//return res;
//}

Polynom* Polynom::operator -(const float num) const
{
	return (*this) + (-1.0f * num);
}

Polynom* Polynom::operator*(const float cf) const
{
	Polynom* res = new Polynom(P);
	for (int i = 0; i <= P; i++)
	{
		res->pData[i] = this->pData[i] * cf;
	}
	return res;
}

Polynom* Polynom::operator/(const float cf) const
{
	return (*this) * (1.0f / cf);
}

void Polynom::add(const Polynom* src, const float coeff)
{
	int minp = this->P < src->P ? this->P : src->P;
	for (int i = 0; i <= minp; i++)
	{
		this->pData[i] += src->pData[i] * coeff;
	}
}

float Polynom::operator[](const int idx) const
{
	assert(idx >= 0 && idx <= P);
    return pData[idx];
}

float& Polynom::operator[](const int idx)
{
	assert(idx >= 0 && idx <= P);
    return pData[idx];
}

Polynom::~Polynom(void)
{
	if (pData != NULL)
	{
		delete[] pData;
		pData = NULL;
	}
}
