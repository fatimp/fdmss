#include "InputParameters.h"

InputParameters::InputParameters() : rre(0.f), dt(0.f), re(0.01f), vinit(0.f), dtc2(0.f), pl(0.f), pr(0.f),
									 c2(1500000.0f), itsc(0), ntot(0), flowDirectionAxis('x'),
									 cof1(5.333333333f), cof2(2.666666667f), boundaryCondition(0), errorSmoothingArrayLength(10U), threadsNumber(0U), resolution(1.0f),
									 waterLayerWidth(0U)
{
}

void InputParameters::read(const char *filename)
{
	TiXmlDocument paramsFile(filename);
	paramsFile.LoadFile();
	TiXmlElement *rootElement = paramsFile.RootElement();
	if (rootElement != NULL)
	{
		// Traverse XML tree
		rootElement->Accept(new InputParametersParser(this));

		rre = 1.0f / re;
		dtc2 = dt * c2;
		c2 = (.25f / dt - rre) * 2.f / dt;
	}
}

InputParametersParser::InputParametersParser(InputParameters *parameters) : TiXmlVisitor(), params(parameters) {}

InputParametersParser::~InputParametersParser() {}

const char *InputParametersParser::GetFormatSpecifier(const TiXmlElement &element)
{
	static const char *specifiers[] = {"%d", "%f", "%u", "%c"};

	const char *datatype = element.Attribute("datatype");
	if (strcmp(datatype, "int") == 0)
	{
		return specifiers[0];
	}
	else if (strcmp(datatype, "float") == 0)
	{
		return specifiers[1];
	}
	else if (strcmp(datatype, "unsigned int") == 0)
	{
		return specifiers[2];
	}
	else if (strcmp(datatype, "char") == 0)
	{
		return specifiers[3];
	}
	else
	{
		return NULL;
	}
}

/// Visit an element.
bool InputParametersParser::VisitEnter(const TiXmlElement &element, const TiXmlAttribute *firstAttribute)
{
	if (strcmp(element.Value(), "Parameter") != 0)
	{
		if (element.FirstChild() != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (firstAttribute == NULL || strcmp(firstAttribute->Name(), "name") != 0)
	{
		return false;
	}

	void *dataWriteTarget = NULL;
	if (strcmp(firstAttribute->Value(), "Resolution") == 0)
	{
		dataWriteTarget = &(params->resolution);
	}
	else if (strcmp(firstAttribute->Value(), "ArtificalCompressibility") == 0)
	{
		dataWriteTarget = &(params->c2);
	}
	else if (strcmp(firstAttribute->Value(), "TimeStep") == 0)
	{
		dataWriteTarget = &(params->dt);
	}
	else if (strcmp(firstAttribute->Value(), "IterationsPerStep") == 0)
	{
		dataWriteTarget = &(params->ntot);
	}
	else if (strcmp(firstAttribute->Value(), "MaximumStepsCount") == 0)
	{
		dataWriteTarget = &(params->itsc);
	}
	else if (strcmp(firstAttribute->Value(), "InitialVelocityValue") == 0)
	{
		dataWriteTarget = &(params->vinit);
	}
	else if (strcmp(firstAttribute->Value(), "Accuracy") == 0)
	{
		dataWriteTarget = &(params->tolerance);
	}
	else if (strcmp(firstAttribute->Value(), "BoundaryCondition") == 0)
	{
		dataWriteTarget = &(params->boundaryCondition);
	}
	else if (strcmp(firstAttribute->Value(), "TerminationCondition") == 0)
	{
		dataWriteTarget = &(params->terminationCondition);
	}
	else if (strcmp(firstAttribute->Value(), "ErrorSmoothingLength") == 0)
	{
		dataWriteTarget = &(params->errorSmoothingArrayLength);
	}
	else if (strcmp(firstAttribute->Value(), "ThreadsNumber") == 0)
	{
		dataWriteTarget = &(params->threadsNumber);
	}
	else if (strcmp(firstAttribute->Value(), "ReynoldsNumber") == 0)
	{
		dataWriteTarget = &(params->re);
	}
	else if (strcmp(firstAttribute->Value(), "FlowDirectionAxis") == 0)
	{
		dataWriteTarget = &(params->flowDirectionAxis);
	}
	else if (strcmp(firstAttribute->Value(), "WaterLayerWidth") == 0)
	{
		dataWriteTarget = &(params->waterLayerWidth);
	}
	else
	{
		return false;
	}

	// Parse value here
	const char *formatSpecifier = GetFormatSpecifier(element);
	if (const TiXmlNode *valueElement = element.FirstChild("ParameterValue"))
	{
		const char *elementText = valueElement->ToElement()->GetText();
		sscanf(elementText, formatSpecifier, dataWriteTarget);
	}
	else
	{
		return false;
	}

	return true;
}