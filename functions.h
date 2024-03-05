#ifndef FUNCTIONS
#define FUNCTIONS

#include <vector>
#include <string>
#include "dataTypes.h"

std::vector<int> generateGrades();
int generateExamScore();
std::string generateFirstName();
std::string generateLastNames();
bool compareFisrtName(const studentInfo &a, const studentInfo &b);
bool compareLastName(const studentInfo &a, const studentInfo &b);
bool compareLastVid(const studentInfo &a, const studentInfo &b);
bool compareLastMed(const studentInfo &a, const studentInfo &b);
bool fileExistanceValidator(std::string fileName);
std::vector<studentInfo> sortingAlgo(int selection, std::vector<studentInfo> data);
void singleSutdentInfoPrinter(studentInfo studentInfoToBePrinted);
double calculateAverage(double score, double examScore);
int findLongestName(std::vector<studentInfo> data);
int findLongestLastname(std::vector<studentInfo> data);
void invalidInput();
int selectionOptionValidator();
int selectionSortingValidator();
int selectionEntryValidator();
int selectionOutputValidator();
int selectionGenerationValidator();
int selectionDisplayValidator();
studentInfo singleInputModule(int selection);
void resulter(std::vector<studentInfo> allStudentInfo);
void consoleLog(std::string data);
std::vector<studentInfo> readData(std::string fileName, int readingType);
void writeData(std::vector<studentInfo> allStudentInfo, string fileName);
void scenarioTester();
void generateTestFiles();
void dotests();

#endif 