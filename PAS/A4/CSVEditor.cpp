#include "CSVEditor.hpp"

//creates a new hastable of type string, opens various files, and sets regex to expr
CSVEditor::CSVEditor(string &inputPath, string &rosterPath, string &outputPath, regex expr, int m)
{
	hashTable = new HashTable<string>(m);
	input.open(inputPath);
	roster.open(rosterPath);
	output.open(outputPath);
	regexPattern = expr;
};

//closes all the files.
CSVEditor::~CSVEditor()
{
	input.close();
	roster.close();
	output.close();
};
// reads from files into our hashtable
void CSVEditor::readCSVToTable()
{
	string line;
	string grade;
	smatch match;
	int UIN;
	while (getline(input, line))
	{
		if (regex_search(line, match, regexPattern))
		{
			UIN = stoi(match.str(1));
			grade = match.str(2);
			hashTable->insert(UIN, grade);
		}
	};
};
//outputs to our hashtable
void CSVEditor::writeCSVToFile()
{
	string line;
	string info;
	smatch match;
	string outputGrade;
	int UIN;
	while (getline(roster, line))
	{
		if (regex_search(line, match, regexPattern))
		{
			info = match.str(0);
			UIN = stoi(match.str(1));
			string *grade = hashTable->search(UIN);
			if (grade == nullptr)
			{
				outputGrade = "";
			}
			else
			{
				outputGrade = *grade;
			}
			output << info << outputGrade << endl;
		}
	};
};

std::tuple<int, int, double> CSVEditor::getStats()
{
	int min = hashTable->minChainLen();
	int max = hashTable->maxChainLen();
	float avg = hashTable->averageChainLen();
	return std::make_tuple(min, max, avg);
};