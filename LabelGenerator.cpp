#include <string>
#include "LabelGenerator.h"

using namespace std;

LabelGenerator::LabelGenerator()
{
	this->label = "Label";
	this->labelNumber = 0;
}

LabelGenerator::LabelGenerator(string labelName, int labelStartNumber)
	: label(labelName), labelNumber(labelStartNumber)
{}

string LabelGenerator::nextLabel()
{
	return this->label + to_string(++this->labelNumber);
}

std::string LabelGenerator::getLabelName() const
{
	return this->label;
}

std::string LabelGenerator::getLabelStr() const
{
	return this->label + to_string(this->labelNumber);
}

int LabelGenerator::getLabelNumber() const
{
	return this->labelNumber;
}

void LabelGenerator::setLabel(std::string labelName)
{
	this->label = labelName;
}

void LabelGenerator::setLabelNumber(int labelStartNumber)
{
	this->labelNumber = labelStartNumber;
}

FileLabelGenerator::FileLabelGenerator(string labelName, int labelStartNumber, string labelHeadersFileName)
	: LabelGenerator(labelName, labelStartNumber)
{
	ifstream labels(labelHeadersFileName);
	currName = 0;

	if (labels.is_open())
	{
		string line;
		while (getline(labels, line))
			labelNames.push_back(line);
	}
	else
	{
		throw std::invalid_argument("FileNotFound");
	}
}

string FileLabelGenerator::nextLabel()
{
	if (currName >= labelNames.size())
		return "";

	return this->label + to_string(this->labelNumber++) + " " + labelNames[currName++];
}