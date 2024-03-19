#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <deque>
#include <algorithm>
#include <regex>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdexcept>
#include "dataTypes.h"

using namespace std;

bool compareFisrtName(const studentInfo &a, const studentInfo &b)
{
    return a.fisrtname < b.fisrtname;
}

bool compareLastName(const studentInfo &a, const studentInfo &b)
{
    return a.lastname < b.lastname;
}

bool compareLastVid(const studentInfo &a, const studentInfo &b)
{
    return a.average < b.average;
}

bool compareLastMed(const studentInfo &a, const studentInfo &b)
{
    return a.averageM < b.averageM;
}

//===================== VECTOR ================
//  class customCst {    
//   public:
//   vector<studentInfo> storage;
//     void deleteE(int i) {
//         storage.erase(storage.begin() + i);
//     };
//     void sort(int selection){
//       switch (selection)
//       {
//       case 1:
//         std::sort(storage.begin(), storage.end(), compareFisrtName); 
//         break;
//       case 2:
//         std::sort(storage.begin(), storage.end(), compareLastName); 
//         break;
//       case 3:
//         std::sort(storage.begin(), storage.end(), compareLastVid); 
//         break;
//       case 4:
//         std::sort(storage.begin(), storage.end(), compareLastMed); 
//         break;
//       default:
//         std::sort(storage.begin(), storage.end(), compareLastVid); 
//         break;
//       }
//     };
//     void push_back(studentInfo next){
//       storage.push_back(next);
//     };
//     int size(){
//       return storage.size();
//     };
//     studentInfo& operator[](int index) {
//         return storage[index];
//     };
//     void clear(){
//       storage.clear();
//     };
// };
// class customCi { 
//   vector<int> storage;      
//   public:           
//        void reverseSort(){
//          std::sort(storage.rbegin(), storage.rend());
//        };      
//     void sort(){
//         std::sort(storage.begin(), storage.end());
//     };
//     void push_back(int next){
//       storage.push_back(next);
//     };
//     int size(){
//       return storage.size();
//     };
//     int& operator[](int index) {
//         return storage[index];
//     };
//     void clear(){
//       storage.clear();
//     };
// };
//===================== VECTOR ================

//===================== LIST ================
// class customCst {    
// public:
// list<studentInfo> storage;
//     void deleteE(int i) {
//         auto it = storage.begin();
//         std::advance(it, i); 
//         storage.erase(it); 
//     }
//   void sort(int selection){
//     switch (selection)
//     {
//     case 1:
//       storage.sort(compareFisrtName); 
//       break;
//     case 2:
//       storage.sort(compareLastName); 
//       break;
//     case 3:
//       storage.sort(compareLastVid); 
//       break;
//     case 4:
//       storage.sort(compareLastMed); 
//       break;
//     default:
//       storage.sort(compareLastVid); 
//       break;
//     }
//   };
//   void push_back(studentInfo next){
//     storage.push_back(next);
//   };
//   int size(){
//     return storage.size();
//   };
//   void clear(){
//     storage.clear();
//   };
//   studentInfo& operator[](int index) {
//     auto it = storage.begin();
//     std::advance(it, index);
//     return *it;
//   };
// };
// class customCi { 
// list<int> storage;      
// public:       
//     void reverseSort() {
//         // Sorts the list in descending order using a lambda that returns true if the first argument is greater than the second
//         storage.sort([](const int& a, const int& b) {
//             return a > b;
//         });
//     };      
//   void sort(){
//     storage.sort();
//   };
//   void push_back(int next){
//     storage.push_back(next);
//   };
//   int size(){
//     return storage.size();
//   };
//   void clear(){
//     storage.clear();
//   };
//   int& operator[](int index) {
//     auto it = storage.begin();
//     std::advance(it, index);
//     return *it;
//   };
// };
//===================== LIST ================

//===================== deque ================
class customCst {    
public:
deque<studentInfo> storage;
  void deleteE(int i){
    auto it = storage.begin();
    std::advance(it, i); 
    storage.erase(it);
  };
  void sort(int selection){
    switch (selection)
    {
    case 1:
      std::sort(storage.begin(), storage.end(), compareFisrtName); 
      break;
    case 2:
      std::sort(storage.begin(), storage.end(), compareLastName); 
      break;
    case 3:
      std::sort(storage.begin(), storage.end(), compareLastVid); 
      break;
    case 4:
      std::sort(storage.begin(), storage.end(), compareLastMed); 
      break;
    default:
      std::sort(storage.begin(), storage.end(), compareLastVid); 
      break;
    }
  };
  void push_back(studentInfo next){
    storage.push_back(next);
  };
  int size(){
    return storage.size();
  };
  studentInfo& operator[](int index) {
      return storage[index];
  };
  void clear(){
    storage.clear();
  };
};
class customCi { 
  std::deque<int> storage;      
public:         
  void reverseSort(){
    std::sort(storage.rbegin(), storage.rend());
  };   
  void sort(){
    std::sort(storage.begin(), storage.end());
  };
  void push_back(int next){
    storage.push_back(next);
  };
  int size(){
    return storage.size();
  };
  int& operator[](int index) {
      return storage[index];
  };
  void clear(){
    storage.clear();
  };
};
//===================== deque ================

struct superStruct
{
    customCst good, bad;
};


customCi generateGrades(){
    customCi grades;
    int numberOfGrades = rand() % 200;
    for (int i = 0; i < numberOfGrades+1; i++)
    {
        grades.push_back((rand() % 11));
    }
    return grades;
}

void consoleLog(string data){
    for (int i = 0; i < data.length()+16; i++)
    {
        std::cout << "-";
    }
    std::cout << endl << "\t" << data << endl;
    for (int i = 0; i < data.length()+16; i++)
    {
        std::cout << "-";
    }
    std::cout << endl << endl;
}

int generateExamScore(){
    return (rand() % 11);
}

string generateFirstName(){
    return availableNames[rand() % 1000];
}

string generateLastNames(){
    return availableLastnames[rand() % 1000];
}

bool fileExistanceValidator (string fileName) {
    ifstream file(fileName);
    if (!file.good()) {
        throw runtime_error("Failas pavadinimui \"" + fileName + "\" neegzistuoja!");
    }
    return file.good();
}

void processException() {
    try {
        throw;
    }
    catch (const invalid_argument& e) {
        consoleLog(e.what());
    }
    catch (const runtime_error& e) {
        consoleLog(e.what());
    }
    catch (...) {
        consoleLog("Nezinomas error");
        
    }
}

customCst sortingAlgo(int selection, customCst data){
    switch (selection)
    {
    case 1:
        data.sort(1); // compareFisrtName
        return data;
        break;
    case 2:
        data.sort(2); // compareLastName
        return data;
        break;
    case 3:
        data.sort(3); // compareLastVid
        return data;
        break;
    case 4:
        data.sort(4); // compareLastMed
        return data;
        break;
    default:
        return data;
        break;
    }
}

void singleSutdentInfoPrinter(studentInfo studentInfoToBePrinted){
    std::cout<<"Fisrtname: "<<studentInfoToBePrinted.fisrtname<<endl;
    std::cout<<"lastname: "<<studentInfoToBePrinted.lastname<<endl;
    std::cout<<"homeworkScore: "<<studentInfoToBePrinted.homeworkScore<<endl;
    std::cout<<"examScore: "<<studentInfoToBePrinted.examScore<<endl;
    std::cout<<"median: "<<studentInfoToBePrinted.median<<endl;
    std::cout<<"average: "<<studentInfoToBePrinted.average<<endl;
    std::cout<<"averageM: "<<studentInfoToBePrinted.averageM<<endl;
}

double calculateAverage(double score, double examScore){
    return 0.4 * score + 0.6 * examScore;
}

int findLongestName(customCst data){
    int longestName = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (longestName < data[i].fisrtname.length())
        {
            longestName = data[i].fisrtname.length();
        }   
    }
    return longestName;
}

int findLongestLastname(customCst data){
    int longestLastname = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (longestLastname < data[i].lastname.length())
        {
            longestLastname = data[i].lastname.length();
        }   
    }
    return longestLastname;
}

void invalidInput(){
    try
    {
        throw std::invalid_argument("Neteisinga ivestis!");
    }
    catch(...)
    {
        processException();
    }
    

}

int selectionOptionValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << "How would you like to enter data?" << endl;
        std::cout << "1 - by hand, 2 - generate grades, 3 - generate grades, first and last names, 4 - read from file, 5 - generate test files, 6 - perform tests 7 - exit program" << endl;
        regex pat {R"(^([1-6]|7))"};
        string tmp = "";
        getline(cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        try
        {
            if (!inputTrue)
            {
                // invalidInput();
                throw std::invalid_argument("Neleistinas pasirinkimas. Galima tik: 1, 2, 3, 4, 5, 6, 7");

            }else{
                selection = stoi(tmp);
            }  
        }
        catch(...)
        {
            processException();
        }
        
        
    }
    return selection;
}

int selectionSortingValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << "How would you like the data to be sorted?" << endl;
        std::cout << "1 - by firstname, 2 - by lastname, 3 - by last average score, 4 - by last average median score, 5 - do not sort" << endl;
        regex pat {R"(^([1-4]|5))"};
        string tmp = "";
        getline(cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        try
        {
            if (!inputTrue)
            {
                // invalidInput();
                throw std::invalid_argument("Neleistinas pasirinkimas. Galima tik: 1, 2, 3, 4, 5");

            }else{
                selection = stoi(tmp);
            }  
        }
        catch(...)
        {
            processException();
        }
    }
    return selection;
}

int selectionEntryValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << "Are you done with data entry?" << endl;
        std::cout << "1 - no, 2 - yes" << endl;
        regex pat {R"(^(1|2))"};
        string tmp = "";
        getline(cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        try
        {
            if (!inputTrue)
            {
                // invalidInput();
                throw std::invalid_argument("Neleistinas pasirinkimas. Galima tik: 1, 2");

            }else{
                selection = stoi(tmp);
            }  
        }
        catch(...)
        {
            processException();
        }
    }
    return selection;
}

int selectionOutputValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << "How would you like to see the data?" << endl;
        std::cout << "1 - In Terminal, 2 - Writen to file" << endl;
        regex pat {R"(^(1|2))"};
        string tmp = "";
        getline(cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        try
        {
            if (!inputTrue)
            {
                // invalidInput();
                throw std::invalid_argument("Neleistinas pasirinkimas. Galima tik: 1, 2");

            }else{
                selection = stoi(tmp);
            }  
        }
        catch(...)
        {
            processException();
        }
    }
    return selection;
}

int selectionGenerationValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << "How many students data should be generated? (1-1000)" << endl;
        regex pat {R"(^([1-9]|[1-9][0-9]{1,2}|1000))"};
        string tmp = "";
        getline(cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        try
        {
            if (!inputTrue)
            {
                // invalidInput();
                throw std::invalid_argument("Neleistinas pasirinkimas. Galima tik: [1; 1000]");

            }else{
                selection = stoi(tmp);
            }  
        }
        catch(...)
        {
            processException();
        }
    }
    return selection;
}

int selectionDisplayValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        std::cout << endl << "How would you like to see the data?" << endl;
        std::cout << "1 - \"Galutinis(Vid.)\", 2 - \"Galutinis(Med.)\", 3 - \"Galutinis(Vid.) / Galutinis(Med.)\"" << endl;
        regex pat {R"(^([1-2]|3))"};
        string tmp = "";
        getline(cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        try
        {
            if (!inputTrue)
            {
                // invalidInput();
                throw std::invalid_argument("Neleistinas pasirinkimas. Galima tik: 1, 2, 3");

            }else{
                selection = stoi(tmp);
            }  
        }
        catch(...)
        {
            processException();
        }
    }
    return selection;
}

studentInfo singleInputModule(int selection){
    
    studentInfo newStudentInfo;

    switch (selection)
    {
        case 1:
        {
            bool nameValid = false;
            while (!nameValid)
            {
                regex pat {R"(^([a-zA-Z]{2,}\s[a-zA-Z]{1,}'?-?[a-zA-Z]{2,}\s?([a-zA-Z]{1,})?))"};
                std::cout<<"Please enter fullname of the student: "<<endl;
                string tmp = "";
                getline(cin, tmp);
                smatch sm;
                nameValid = regex_match(tmp,sm,pat);
                if (!nameValid)
                {
                    invalidInput();
                }else
                {
                    size_t spaceLocation = tmp.find(" ");
                    newStudentInfo.fisrtname = tmp.substr(0, spaceLocation);
                    newStudentInfo.lastname = tmp.substr(spaceLocation+1, tmp.length());
                }
            }
            break;
        }
        case 2:
        {
            bool nameValid = false;
            while (!nameValid)
            {
                regex pat {R"(^([a-zA-Z]{2,}\s[a-zA-Z]{1,}'?-?[a-zA-Z]{2,}\s?([a-zA-Z]{1,})?))"};
                std::cout<<"Please enter fullname of the student: "<<endl;
                string tmp = "";
                getline(cin, tmp);
                smatch sm;
                nameValid = regex_match(tmp,sm,pat);
                if (!nameValid)
                {
                    invalidInput();
                }else
                {
                    size_t spaceLocation = tmp.find(" ");
                    newStudentInfo.fisrtname = tmp.substr(0, spaceLocation);
                    newStudentInfo.lastname = tmp.substr(spaceLocation+1, tmp.length());
                }
            }
            break;
        }
        case 3:
        {
            string firstName = generateFirstName();
            string lastName = generateLastNames();
            std::cout<< "Generated name: " << firstName << " " << lastName << endl;
            newStudentInfo.fisrtname = firstName;
            newStudentInfo.lastname = lastName;
            break;
        }
    }
    

    
    switch (selection)
    {
        case 1:
        {
            customCi grades;
            int i = 0;
            bool areWeDone = false;
            while (!areWeDone)
            {
                std::cout<<"Please enter the grade number " << i+1 << ": "<<endl;
                regex patGrade {R"(^([0-9]|10))"};
                bool singleGradeInvalid = false;
                while (!singleGradeInvalid)
                {
                    string tmpSingle = "";
                    getline(cin, tmpSingle);
                    smatch sm;
                    singleGradeInvalid = regex_match(tmpSingle,sm,patGrade);
                    if (!singleGradeInvalid)
                    {
                        invalidInput();
                    }else{
                        grades.push_back(stoi(tmpSingle));
                        i++;
                    }
                } 
                if (selectionEntryValidator() == 2){
                    areWeDone = true;
                }
            }

            grades.sort();

            int homeWorkToalScore = 0;
            for (int i = 0; i < grades.size(); i++)
            {
                homeWorkToalScore += grades[i];
            }

            if (grades.size() != 0)
            {
                newStudentInfo.homeworkScore = (double)homeWorkToalScore/grades.size();
            }

            int numberOfHomeWork = grades.size();
            if (numberOfHomeWork%2 == 0)
            {
                newStudentInfo.median = (grades[(numberOfHomeWork/2)] + grades[(numberOfHomeWork/2)-1]) / 2.0;
            }else{
                newStudentInfo.median = grades[(numberOfHomeWork/2)];
            }

            bool examScoreValid = false;
            while (!examScoreValid)
            {
                regex pat {R"(^([0-9]|10))"};
                std::cout<<"Please enter the students exam score: "<<endl;
                string tmp = "";
                getline(cin, tmp);
                smatch sm;
                examScoreValid = regex_match(tmp,sm,pat);
                if (!examScoreValid)
                {
                    invalidInput();
                }else
                {
                    newStudentInfo.examScore = stoi(tmp);
                }
            }
            break;
        }
        case 2:
        {
            customCi generatedGrades = generateGrades();
            int examScore = generateExamScore();

            std::cout<< "Auto generated grades: ";
            for(int i = 0; i < generatedGrades.size(); i++){
                std::cout << generatedGrades[i] << " ";
            }
            std::cout << endl << "Auto generated exam score: " << examScore << endl << endl;

            generatedGrades.sort();

            int homeWorkToalScore = 0;
            for (int i = 0; i < generatedGrades.size(); i++)
            {
                homeWorkToalScore += generatedGrades[i];
            }

            if (generatedGrades.size() != 0)
            {
                newStudentInfo.homeworkScore = (double)homeWorkToalScore/generatedGrades.size();
            }

            int numberOfHomeWork = generatedGrades.size();
            if (numberOfHomeWork%2 == 0)
            {
                newStudentInfo.median = (generatedGrades[(numberOfHomeWork/2)] + generatedGrades[(numberOfHomeWork/2)-1]) / 2.0;
            }else{
                newStudentInfo.median = generatedGrades[(numberOfHomeWork/2)];
            }
            newStudentInfo.examScore = examScore;
            break;
        }
        case 3:
        {
            customCi generatedGrades = generateGrades();
            int examScore = generateExamScore();

            std::cout<< "Auto generated grades: ";
            for(int i = 0; i < generatedGrades.size(); i++){
                std::cout << generatedGrades[i] << " ";
            }
            std::cout << endl << "Auto generated exam score: " << examScore << endl << endl;

            generatedGrades.sort();

            int homeWorkToalScore = 0;
            for (int i = 0; i < generatedGrades.size(); i++)
            {
                homeWorkToalScore += generatedGrades[i];
            }

            if (generatedGrades.size() != 0)
            {
                newStudentInfo.homeworkScore = (double)homeWorkToalScore/generatedGrades.size();
            }

            int numberOfHomeWork = generatedGrades.size();
            if (numberOfHomeWork%2 == 0)
            {
                newStudentInfo.median = (generatedGrades[(numberOfHomeWork/2)] + generatedGrades[(numberOfHomeWork/2)-1]) / 2.0;
            }else{
                newStudentInfo.median = generatedGrades[(numberOfHomeWork/2)];
            }
            newStudentInfo.examScore = examScore;
            break;
        }
    }

    
            
    return newStudentInfo;
}

void resulter(customCst allStudentInfo){
    if (allStudentInfo.size() == 0)
    {
        std::cout << "No data was found..." << endl;
    }else{
        for (int i = 0; i < allStudentInfo.size(); i++)
        {
            allStudentInfo[i].average = calculateAverage(allStudentInfo[i].homeworkScore, allStudentInfo[i].examScore);
            allStudentInfo[i].averageM = calculateAverage(allStudentInfo[i].median, allStudentInfo[i].examScore);
        }
        allStudentInfo = sortingAlgo(selectionSortingValidator(), allStudentInfo);
        int longestName = findLongestName(allStudentInfo);
        int longestLastname = findLongestLastname(allStudentInfo);
        int selection = selectionDisplayValidator();

         std::cout << "Pavarde";
        if (longestLastname<10)
        {
            std::cout << "   ";
        }else{
            for (int i = 0; i < longestLastname-7+2; i++)
            {
                std::cout << " ";
            }
        }
        
        std::cout << "Vardas";
        if (longestName < 9)
        {
            std::cout << "   ";
        }else{
            for (int i = 0; i < longestName-6+2; i++)
            {
                std::cout << " ";
            }
        }

        switch (selection)
        {
        case 1:
            std::cout << "Galutinis (Vid).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                std::cout << "-";
            }
            std::cout << "-----------------" << endl;
            break;
        case 2:
            std::cout << "Galutinis (Med).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                std::cout << "-";
            }
            std::cout << "-----------------" << endl;
            break;
        case 3:
            std::cout << "Galutinis (Vid). / Galutinis (Med).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                std::cout << "-";
            }
            std::cout << "-----------------------------------" << endl;
        break;
        }

        for (int i = 0; i < allStudentInfo.size(); i++)
        {
            std::cout << allStudentInfo[i].lastname;
            if (longestLastname < 10)
            {
                for (int y = 0; y < (10 - allStudentInfo[i].lastname.length()); y++)
                {
                    std::cout << " ";
                }
            }else{
                for (int y = 0; y < (longestLastname - allStudentInfo[i].lastname.length())+2; y++)
                {
                    std::cout << " ";
                }
            }
            
            std::cout << allStudentInfo[i].fisrtname;
            if (longestName < 9)
            {
                for (int y = 0; y < (9 - allStudentInfo[i].fisrtname.length()); y++)
                {
                    std::cout << " ";
                }
            }else{
                for (int y = 0; y < (longestName - allStudentInfo[i].fisrtname.length())+2; y++)
                {
                    std::cout << " ";
                }
            }
            
            switch (selection)
            {
            case 1:
                std::cout<< fixed << setprecision(2) << allStudentInfo[i].average << endl;
                break;
            case 2:
                std::cout<< fixed << setprecision(2) << allStudentInfo[i].averageM << endl;
                break;
            case 3:
                if(allStudentInfo[i].average == 10){
                    std::cout<< fixed << setprecision(2) << allStudentInfo[i].average << "              " << allStudentInfo[i].averageM << endl;
                }else{
                    std::cout<< fixed << setprecision(2) << allStudentInfo[i].average << "               " << allStudentInfo[i].averageM << endl;
                }
                break;
            }
        }   
    }
}

customCst readData(string fileName, int readingType){
    /*
    Reading Type
    1 - word at a time
    2 - line at a time
    3 - read entire file to buffer
    */
    try
    {
        if (!fileExistanceValidator(fileName))
        {
            customCst nothing;
            return nothing;
        }else{
        
            ifstream inFile(fileName);
            string trash[3];
            for (int i = 0; i <2; i++)
            {
                inFile >> trash[i];
            }

            int nNumber = 0;
            while (true){
                string trashNumber;
                inFile >> trashNumber;
                if (trashNumber == "Egz."){
                    break;
                }else{
                    nNumber++;
                }
            }


            customCst storage;
            customCi gradesStorage;
            auto start = chrono::high_resolution_clock::now(); 

            while(true)
            {
                int quit = false;
                studentInfo data;
                switch (readingType)
                {
                case 1:
                {
                    inFile >> data.fisrtname >> data.lastname;
                    gradesStorage.clear();
                    for (int i = 0; i < nNumber; i++)
                    {
                        int tmp = 0;
                        inFile >> tmp;
                        gradesStorage.push_back(tmp);
                    }

                    inFile >> data.examScore;
                    break;
                }
                case 2:
                {
                    gradesStorage.clear();
                    string line;
                    getline(inFile, line);
                    istringstream stream(line);

                    stream >> data.fisrtname >> data.lastname;
                    for (int i = 0; i < nNumber; i++)
                    {
                        int tmp = 0;
                        stream >> tmp;
                        gradesStorage.push_back(tmp);
                    }
                    stream >> data.examScore;
                    
                    break;
                }
                case 3:
                {
                    gradesStorage.clear();
                    stringstream buffer;
                    buffer << inFile.rdbuf();
                    inFile.close();
                    while (!buffer.eof())
                    {
                        buffer >> data.fisrtname >> data.lastname;
                        for (int i = 0; i < nNumber; i++)
                        {
                            int tmp = 0;
                            buffer >> tmp;
                            gradesStorage.push_back(tmp);
                        }
                        buffer >> data.examScore;
                    }
                    quit = true;
                    break;
                }
                default:
                    inFile >> data.fisrtname >> data.lastname;
                    gradesStorage.clear();
                    for (int i = 0; i < nNumber; i++)
                    {
                        int tmp = 0;
                        inFile >> tmp;
                        gradesStorage.push_back(tmp);
                    }

                    inFile >> data.examScore;
                    break;
                }
            


                gradesStorage.sort();
                

                    int homeWorkToalScore = 0;
                    for (int i = 0; i < gradesStorage.size(); i++)
                    {
                        homeWorkToalScore += gradesStorage[i];
                    }

                    if (gradesStorage.size() != 0)
                    {
                        data.homeworkScore = (double)homeWorkToalScore/gradesStorage.size();
                    }

                    int numberOfHomeWork = gradesStorage.size();
                    if (numberOfHomeWork%2 == 0)
                    {
                        data.median = (gradesStorage[(numberOfHomeWork/2)] + gradesStorage[(numberOfHomeWork/2)-1]) / 2.0;
                    }else{
                        data.median = gradesStorage[(numberOfHomeWork/2)];
                    }
                storage.push_back(data);
                if(inFile.eof() || quit){
                    break;
                }
            }

            auto end = chrono::high_resolution_clock::now();
            // consoleLog(to_string(((end-start).count())/1000000000.0));
            
            return storage;
        }
    }
    catch(...)
    {
        processException();
        customCst nothing;
        return nothing;
    }
}

void writeData(customCst  allStudentInfo, string fileName, int spec){
    
    ofstream outFile(fileName);
    if (allStudentInfo.size() == 0)
    {
        outFile << "No data was found..." << endl;
    }else{
        for (int i = 0; i < allStudentInfo.size(); i++)
        {
            allStudentInfo[i].average = calculateAverage(allStudentInfo[i].homeworkScore, allStudentInfo[i].examScore);
            allStudentInfo[i].averageM = calculateAverage(allStudentInfo[i].median, allStudentInfo[i].examScore);
        }
        if (spec != 2)
        {
            allStudentInfo = sortingAlgo(selectionSortingValidator(), allStudentInfo);
        } else{
            allStudentInfo = sortingAlgo(3, allStudentInfo);
        }

        int longestName = findLongestName(allStudentInfo);
        int longestLastname = findLongestLastname(allStudentInfo);

        int selection;
        if (spec == 2)
        {
            selection = 1;
        }else{
            selection = selectionDisplayValidator();
        }
        

        outFile << "Pavarde";
        if (longestLastname<10)
        {
            outFile << "   ";
        }else{
            for (int i = 0; i < longestLastname-7+2; i++)
            {
                outFile << " ";
            }
        }
        
        outFile << "Vardas";
        if (longestName < 9)
        {
            outFile << "   ";
        }else{
            for (int i = 0; i < longestName-6+2; i++)
            {
                outFile << " ";
            }
        }

        switch (selection)
        {
        case 1:
            outFile << "Galutinis (Vid).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                outFile << "-";
            }
            outFile << "-----------------" << endl;
            break;
        case 2:
            outFile << "Galutinis (Med).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                outFile << "-";
            }
            outFile << "-----------------" << endl;
            break;
        case 3:
            outFile << "Galutinis (Vid). / Galutinis (Med).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                outFile << "-";
            }
            outFile << "-----------------------------------" << endl;
        break;
        }

        for (int i = 0; i < allStudentInfo.size(); i++)
        {
            outFile << allStudentInfo[i].lastname;
            if (longestLastname < 10)
            {
                for (int y = 0; y < (10 - allStudentInfo[i].lastname.length()); y++)
                {
                    outFile << " ";
                }
            }else{
                for (int y = 0; y < (longestLastname - allStudentInfo[i].lastname.length())+2; y++)
                {
                    outFile << " ";
                }
            }
            
            outFile << allStudentInfo[i].fisrtname;
            if (longestName < 9)
            {
                for (int y = 0; y < (9 - allStudentInfo[i].fisrtname.length()); y++)
                {
                    outFile << " ";
                }
            }else{
                for (int y = 0; y < (longestName - allStudentInfo[i].fisrtname.length())+2; y++)
                {
                    outFile << " ";
                }
            }
            
            switch (selection)
            {
            case 1:
                outFile<< fixed << setprecision(2) << allStudentInfo[i].average << endl;
                break;
            case 2:
                outFile<< fixed << setprecision(2) << allStudentInfo[i].averageM << endl;
                break;
            case 3:
                if(allStudentInfo[i].average == 10){
                    outFile<< fixed << setprecision(2) << allStudentInfo[i].average << "              " << allStudentInfo[i].averageM << endl;
                }else{
                    outFile<< fixed << setprecision(2) << allStudentInfo[i].average << "               " << allStudentInfo[i].averageM << endl;
                }
                break;
            }
        }   
    }
    // std::cout << endl << "Done" << endl << "Results writen to file results.txt" << endl ;
}

void scenarioTester(){
    for (int i = 0; i < 5; i++)
    {
        readData("studentai1000000.txt", 1);
    }
    
}

double generateFile(string testfileName, long int fileSize){
    auto start = chrono::high_resolution_clock::now(); 
    ofstream tmp(testfileName);
    // int numberOfGrades = (rand() % 10)+1;
    int numberOfGrades = 10; // for testing 
    tmp << "Vardas          Pavarde          ";
    for (int i = 0; i < numberOfGrades; i++)
    {
        tmp << "ND" << to_string(i+1) << "     ";
    }
    tmp << "Egz." << "\n";

    for (long int i = 0; i < fileSize; i++)
    {
        string fname = generateFirstName();
        string lname = generateLastNames();
        tmp << fname;
        for (int i = 0; i < 16-fname.length(); i++)
        {
            tmp<<" ";
        }
        tmp << lname;
        for (int i = 0; i < 17-lname.length(); i++)
        {
            tmp<<" ";
        }
        for (int i = 0; i < numberOfGrades+1; i++)
        {
            int grade = (rand() % 11);
            if (grade > 9)
            {
                tmp << " " << grade << "     ";
            }else{
                tmp << "  " << grade << "     ";
            }
        }
        tmp << "\n";
    }
    tmp.close();
    auto end = chrono::high_resolution_clock::now();
    return ((end-start).count())/1000000000.0;
    
}

void generateTestFiles(){
    std::cout << "Starting file generation...\n\n";
    std::cout << "Generating file \"test1000.txt\" with 1000 students data.\n";
    double time1 = generateFile("test1000.txt", 1000);
    std::cout << "Time taken: " << to_string(time1) << "s\n\n";
    
    std::cout << "Generating file \"test10000.txt\" with 10000 students data.\n";
    double time2 = generateFile("test10000.txt", 10000);
    std::cout << "Time taken: " << to_string(time2) << "s\n\n";

    std::cout << "Generating file \"test100000.txt\" with 100000 students data.\n";
    double time3 = generateFile("test100000.txt", 100000);
    std::cout << "Time taken: " << to_string(time3) << "s\n\n";

    std::cout << "Generating file \"test1000000.txt\" with 1000000 students data.\n";
    double time4 = generateFile("test1000000.txt", 1000000);
    std::cout << "Time taken: " << to_string(time4) << "s\n\n";

    std::cout << "Generating file \"test10000000.txt\" with 10000000 students data.\n";
    double time5 = generateFile("test10000000.txt", 10000000);
    std::cout << "Time taken: " << to_string(time5) << "s\n\n";

    std::cout << "File generation has finished.\n";
    std::cout << "Total time: " << to_string(time1+time2+time3+time4+time5)<< "s\n\n";

}

superStruct separate1(customCst datas){
    customCst good;
    customCst notGood;
    for (int i = 0; i < datas.size(); i++)
    {
        if (datas[i].fisrtname != "")
        {
            if (datas[i].average < 5)
            {
                notGood.push_back(datas[i]);
            }else{
                good.push_back(datas[i]);
            }
        }
    }
    superStruct mega;
    mega.good = good;
    mega.bad = notGood;
    return mega;
}

superStruct separate2(customCst datas){
    customCi good;
    customCst notGood;
    for (int i = 0; i < datas.size(); i++)
    {
        if (datas[i].fisrtname != "")
        {
            if (datas[i].average < 5)
            {
                notGood.push_back(datas[i]);
                good.push_back(i);
            }
        }else{
            good.push_back(i);
        }
    }
    good.reverseSort();
    for (int i = 0; i < good.size(); i++)
    {
        datas.deleteE(good[i]);
    }
    
    superStruct mega;
    mega.good = datas;
    mega.bad = notGood;
    return mega;
}

superStruct separate3(customCst datas) {
    auto it = std::stable_partition(datas.storage.begin(), datas.storage.end(), [](const studentInfo& studentInfo) {
        return studentInfo.fisrtname != "" && studentInfo.average >= 5;
    });

    customCst good;
    customCst notGood;
    for (int i = 0; i < datas.size(); i++)
    {
        if (datas[i].fisrtname != "")
        {
            if (datas[i].average < 5)
            {
                notGood.push_back(datas[i]);
            }else{
                good.push_back(datas[i]);
            }
        }
    }
    superStruct mega;
    mega.good = good;
    mega.bad = notGood;
    return mega;
}

void dotests(){
    int vals[] = {1000, 10000, 100000, 1000000, 10000000};
    for (int i = 0; i < 5; i++)
    {   
        double totaltime = 0;
        std::cout << "Test file name: test" + to_string(vals[i]) + ".txt\n"; 

        auto start = chrono::high_resolution_clock::now(); 
        customCst datas = readData("test" + to_string(vals[i]) + ".txt", 1);
        auto end = chrono::high_resolution_clock::now();
        double times = ((end-start).count())/1000000000.0;
        totaltime += times;
        std::cout << "Time taken to read file: " + to_string(times) + "s\n";

        start = chrono::high_resolution_clock::now(); 
        for (int i = 0; i < datas.size(); i++)
        {
            datas[i].average = calculateAverage(datas[i].homeworkScore, datas[i].examScore);
            // datas[i].averageM = calculateAverage(datas[i].median, datas[i].examScore);
        }
        switch (3)
        {
        case 1:
        {
            superStruct mega = separate1(datas);
            end = chrono::high_resolution_clock::now();
            times = ((end-start).count())/1000000000.0;
            totaltime += times;
            std::cout << "Time seperate students: " + to_string(times) + "s\n";

            start = chrono::high_resolution_clock::now(); 
            writeData(mega.good, "resGood" + to_string(vals[i]) + ".txt", 2);
            end = chrono::high_resolution_clock::now();
            times = ((end-start).count())/1000000000.0;
            totaltime += times;
            std::cout << "Time taken to write good students: " + to_string(times) + "s\n";

            start = chrono::high_resolution_clock::now(); 
            writeData(mega.bad, "resBad" + to_string(vals[i]) + ".txt", 2);
            end = chrono::high_resolution_clock::now();
            times = ((end-start).count())/1000000000.0;
            totaltime += times;
            std::cout << "Time taken to write bad students: " + to_string(times) + "s\n";
            break;
        }
        case 2:
        {
            superStruct mega = separate2(datas);
            end = chrono::high_resolution_clock::now();
            times = ((end-start).count())/1000000000.0;
            totaltime += times;
            std::cout << "Time seperate students: " + to_string(times) + "s\n";

            start = chrono::high_resolution_clock::now(); 
            writeData(mega.good, "resGood" + to_string(vals[i]) + ".txt", 2);
            end = chrono::high_resolution_clock::now();
            times = ((end-start).count())/1000000000.0;
            totaltime += times;
            std::cout << "Time taken to write good students: " + to_string(times) + "s\n";

            start = chrono::high_resolution_clock::now(); 
            writeData(mega.bad, "resBad" + to_string(vals[i]) + ".txt", 2);
            end = chrono::high_resolution_clock::now();
            times = ((end-start).count())/1000000000.0;
            totaltime += times;
            std::cout << "Time taken to write bad students: " + to_string(times) + "s\n";
            break;
        }
        case 3:
        {
            superStruct mega = separate3(datas);
            end = chrono::high_resolution_clock::now();
            times = ((end-start).count())/1000000000.0;
            totaltime += times;
            std::cout << "Time seperate students: " + to_string(times) + "s\n";

            start = chrono::high_resolution_clock::now(); 
            writeData(mega.good, "resGood" + to_string(vals[i]) + ".txt", 2);
            end = chrono::high_resolution_clock::now();
            times = ((end-start).count())/1000000000.0;
            totaltime += times;
            std::cout << "Time taken to write good students: " + to_string(times) + "s\n";

            start = chrono::high_resolution_clock::now(); 
            writeData(mega.bad, "resBad" + to_string(vals[i]) + ".txt", 2);
            end = chrono::high_resolution_clock::now();
            times = ((end-start).count())/1000000000.0;
            totaltime += times;
            std::cout << "Time taken to write bad students: " + to_string(times) + "s\n";
            break;
        }
        }
        

        start = chrono::high_resolution_clock::now(); 
        end = chrono::high_resolution_clock::now();
        times = ((end-start).count())/1000000000.0;
        totaltime += times;
        std::cout << "Total time taken: " + to_string(totaltime) + "s\n\n\n";
    }
    
}