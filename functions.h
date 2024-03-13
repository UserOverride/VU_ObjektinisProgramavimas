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