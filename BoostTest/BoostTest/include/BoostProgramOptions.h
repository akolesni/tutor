#pragma once
class BoostProgramOptions
{
public:
	BoostProgramOptions();
	~BoostProgramOptions();
	void Do(int argc, char* argv[]);

private:
	void ParseIni(int argc, char* argv[]);
};

