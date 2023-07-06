#ifndef INPUT_PARAMETERS_H
#define INPUT_PARAMETERS_H

#include "tinyxml.h"

struct InputParameters
{
	int ntot, itsc;
	float re, dt, pl, pr, c2, vinit, tolerance;
	float rre, dtc2;
	const float cof1, cof2;
	// 0 - periodic BC,
	// 1 - free BC
	// 2 - no flow BC
	int boundaryCondition;
	// 0 - solution converges (����������� �������)
	// 1 - criterion converges (����������� ��������
	int terminationCondition;
	unsigned int errorSmoothingArrayLength;
	unsigned int threadsNumber;
	float resolution;
	char flowDirectionAxis;
	unsigned int waterLayerWidth;
	InputParameters();
	void read(const char *filename);
};

class InputParametersParser : public TiXmlVisitor
{
private:
	InputParameters *params;
	const char *GetFormatSpecifier(const TiXmlElement &element);

public:
	InputParametersParser(InputParameters *parameters);

	virtual ~InputParametersParser();

	/// Visit an element.
	virtual bool VisitEnter(const TiXmlElement &element, const TiXmlAttribute *firstAttribute);
};

#endif // INPUT_PARAMETERS_H