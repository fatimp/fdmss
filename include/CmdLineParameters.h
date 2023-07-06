#ifndef CMD_LINE_PARAMETERS_H
#define CMD_LINE_PARAMETERS_H

struct CmdLineParameters
{
	const char *configFileName;
	const char *imageFileName;
	const char *summaryFileName;
	const char *velXFileName;
	const char *velYFileName;
	const char *velZFileName;
	const char *pressuresFileName;
	const char *fullVelsFileName;
	const char *compVelsFileName;
	const char *compLogFileName;

	CmdLineParameters(
		const char *_configFileName,
		const char *_imageFileName,
		const char *_summaryFileName,
		const char *_velXFileName,
		const char *_velYFileName,
		const char *_velZFileName,
		const char *_pressuresFileName,
		const char *_fullVelsFileName,
		const char *_compVelsFileName,
		const char *_compLogFileName) : configFileName(_configFileName), imageFileName(_imageFileName), summaryFileName(_summaryFileName),
										velXFileName(_velXFileName), velYFileName(_velYFileName), velZFileName(_velZFileName),
										pressuresFileName(_pressuresFileName), fullVelsFileName(_fullVelsFileName), compVelsFileName(_compVelsFileName),
										compLogFileName(_compLogFileName)
	{
	}
};

#endif // CMD_LINE_PARAMETERS_H