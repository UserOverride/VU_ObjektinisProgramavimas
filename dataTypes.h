#ifndef DATA_TYPES
#define DATA_TYPES

#include <string>
#include <vector>

struct studentInfo {
    std::string fisrtname, lastname;
    double homeworkScore, examScore, median, average, averageM;
};

extern std::vector<std::string> availableNames;
extern std::vector<std::string> availableLastnames;

#endif 