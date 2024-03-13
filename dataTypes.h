#ifndef DATA_TYPES
#define DATA_TYPES

#include <string>
#include <vector>

struct studentInfo {
    std::string fisrtname, lastname;
    double homeworkScore, examScore, median, average, averageM;
};

class customCst {       
public:             
    void sort();
    void sort(int selection);
    void push_back(studentInfo next);
    int size();
    studentInfo& operator[](int index);
    void clear();
};

class customCi {       
public:             
    void sort();
    void sort(int selection);
    void push_back(int next);
    int size();
    int& operator[](int index);
    void clear();
};

extern std::vector<std::string> availableNames;
extern std::vector<std::string> availableLastnames;

#endif 