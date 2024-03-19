#ifndef FUNCTIONS
#define FUNCTIONS

#include <string>
#include <vector>
#include "dataTypes.h"

using namespace std;

vector<int> generateGrades();
int generateExamScore();
std::string generateFirstName();
std::string generateLastNames();
bool compareFisrtName(const studentInfo &a, const studentInfo &b);
bool compareLastName(const studentInfo &a, const studentInfo &b);
bool compareLastVid(const studentInfo &a, const studentInfo &b);
bool compareLastMed(const studentInfo &a, const studentInfo &b);
bool fileExistanceValidator(std::string fileName);
// vector<studentInfo> sortingAlgo(int selection, vector<studentInfo> data);
void singleSutdentInfoPrinter(studentInfo studentInfoToBePrinted);
double calculateAverage(double score, double examScore);
int findLongestName(vector<studentInfo> data);
int findLongestLastname(vector<studentInfo> data);
void invalidInput();
int selectionOptionValidator();
int selectionSortingValidator();
int selectionEntryValidator();
int selectionOutputValidator();
int selectionGenerationValidator();
int selectionDisplayValidator();
studentInfo singleInputModule(int selection);
// void resulter(vector<studentInfo> allStudentInfo);
void consoleLog(std::string data);
// vector<studentInfo> readData(std::string fileName, int readingType);
// void writeData(vector<studentInfo> allStudentInfo, std::string fileName, int spec);
void scenarioTester();
void generateTestFiles();
void dotests();

#endif 