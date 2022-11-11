#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <fstream>

class LabelGenerator
{
protected:
	std::string label;
	int labelNumber;

public:
	LabelGenerator();
	LabelGenerator(std::string labelName, int labelStartNumber);
	std::string getLabelStr() const;
	std::string getLabelName() const;
	int getLabelNumber() const;
	void setLabel(std::string labelName);
	void setLabelNumber(int labelStartNumber);
	std::string nextLabel();
};


class FileLabelGenerator : public LabelGenerator
{
private:
	int currName;
	std::vector<std::string> labelNames;

public:
	FileLabelGenerator(std::string labelName, int labelStartNumber, std::string labelHeadersFileName);
	std::string nextLabel();
};
