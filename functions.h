#ifndef FUNCTIONS
#define FUNCTIONS

#include <string>
#include <vector>
#include "dataTypes.h"
#include "special.h"

using namespace std;

vector<int> generateGrades();
int generateExamScore();
std::string generateFirstName();
std::string generateLastNames();
bool fileExistanceValidator(std::string fileName);
customCst sortingAlgo(int selection, customCst data);
void singleSutdentInfoPrinter(studentInfo studentInfoToBePrinted);
double calculateAverage(double score, double examScore);
int findLongestName(customCst data);
int findLongestLastname(customCst data);
void invalidInput();
int selectionOptionValidator();
int selectionSortingValidator();
int selectionEntryValidator();
int selectionOutputValidator();
int selectionGenerationValidator();
int selectionDisplayValidator();
studentInfo singleInputModule(int selection);
void resulter(customCst allStudentInfo);
void consoleLog(std::string data);
customCst readData(std::string fileName, int readingType);
void writeData(customCst allStudentInfo, std::string fileName, int spec);
void scenarioTester();
void generateTestFiles();
void dotests();

#endif 