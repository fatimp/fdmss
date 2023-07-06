#ifndef POLYNOM_H
#define POLYNOM_H

class Polynom
{
	float *pData;

public:
	const int P;

	Polynom(int p);

	Polynom *operator+(const Polynom &src) const;
	Polynom *operator-(const Polynom &src) const;
	//Polynom* operator +(const float num) const;
	Polynom *operator-(const float num) const;
	Polynom *operator*(const float cf) const;
	Polynom *operator/(const float cf) const;
	float &operator[](const int i);
	float operator[](const int i) const;
	Polynom operator+=(const Polynom &src);
	void add(const Polynom *pl, const float coeff);

	~Polynom(void);
};

#endif // POLYNOM_H