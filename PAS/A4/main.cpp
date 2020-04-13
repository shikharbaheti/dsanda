#include <string>
#include <regex>
#include "HashTable.hpp"
#include "CSVEditor.hpp"
using namespace std;

//counts the number of lines of file
int countLines(string path)
{
    int lines = 0;
    string line;
    ifstream file(path);
    while (getline(file, line))
    {
        lines++;
    }
    return lines;
}

int main(int argc, const char *argv[])
{
    regex expr(".*,.*,(.*),(.*)");
    string inputPath = "./input.csv";
    string rosterPath = "./roster.csv";
    string outputPath = "./output.csv";
    int m = countLines(rosterPath);
    CSVEditor editor(inputPath, rosterPath, outputPath, expr, m);
    editor.readCSVToTable();
    editor.writeCSVToFile();
    std::tuple<int, int, double> stats = editor.getStats();
    cout << "minimum chain len = " << std::get<0>(stats) << endl;
    cout << "maximum chain len = " << std::get<1>(stats) << endl;
    cout << "average chain len = " << std::get<2>(stats) << endl;
    return 0;
}
