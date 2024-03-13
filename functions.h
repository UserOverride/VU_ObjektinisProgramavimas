#ifndef FUNCTIONS
#define FUNCTIONS

#include <string>
#include "dataTypes.h"

customCi generateGrades();
int generateExamScore();
std::string generateFirstName();
std::string generateLastNames();
bool compareFisrtName(const studentInfo &a, const studentInfo &b);
bool compareLastName(const studentInfo &a, const studentInfo &b);
bool compareLastVid(const studentInfo &a, const studentInfo &b);
bool compareLastMed(const studentInfo &a, const studentInfo &b);
bool fileExistanceValidator(std::string fileName);
customCi sortingAlgo(int selection, customCi data);
void singleSutdentInfoPrinter(studentInfo studentInfoToBePrinted);
double calculateAverage(double score, double examScore);
int findLongestName(customCi data);
int findLongestLastname(customCi data);
void invalidInput();
int selectionOptionValidator();
int selectionSortingValidator();
int selectionEntryValidator();
int selectionOutputValidator();
int selectionGenerationValidator();
int selectionDisplayValidator();
studentInfo singleInputModule(int selection);
void resulter(customCi allStudentInfo);
void consoleLog(std::string data);
customCi readData(std::string fileName, int readingType);
void writeData(customCi allStudentInfo, std::string fileName, int spec);
void scenarioTester();
void generateTestFiles();
void dotests();

#endif 