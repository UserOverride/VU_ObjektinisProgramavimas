#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <regex>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdexcept>
#include "dataTypes.h"

using namespace std;

vector<int> generateGrades(){
    vector<int> grades;
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
        cout << "-";
    }
    cout << endl << "\t" << data << endl;
    for (int i = 0; i < data.length()+16; i++)
    {
        cout << "-";
    }
    cout << endl << endl;
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

vector<studentInfo> sortingAlgo(int selection, vector<studentInfo> data){
    switch (selection)
    {
    case 1:
        sort(data.begin(), data.end(), compareFisrtName);
        return data;
        break;
    case 2:
        sort(data.begin(), data.end(), compareLastName);
        return data;
        break;
    case 3:
        sort(data.begin(), data.end(), compareLastVid);
        return data;
        break;
    case 4:
        sort(data.begin(), data.end(), compareLastMed);
        return data;
        break;
    default:
        return data;
        break;
    }
}

void singleSutdentInfoPrinter(studentInfo studentInfoToBePrinted){
    cout<<"Fisrtname: "<<studentInfoToBePrinted.fisrtname<<endl;
    cout<<"lastname: "<<studentInfoToBePrinted.lastname<<endl;
    cout<<"homeworkScore: "<<studentInfoToBePrinted.homeworkScore<<endl;
    cout<<"examScore: "<<studentInfoToBePrinted.examScore<<endl;
    cout<<"median: "<<studentInfoToBePrinted.median<<endl;
    cout<<"average: "<<studentInfoToBePrinted.average<<endl;
    cout<<"averageM: "<<studentInfoToBePrinted.averageM<<endl;
}

double calculateAverage(double score, double examScore){
    return 0.4 * score + 0.6 * examScore;
}

int findLongestName(vector<studentInfo> data){
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

int findLongestLastname(vector<studentInfo> data){
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
    cout<<"-----------------------------------" << endl;
    cout<<"           Invalid Input           " << endl;
    cout<<"-----------------------------------" << endl << endl;

}

int selectionOptionValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        cout << "How would you like to enter data?" << endl;
        cout << "1 - by hand, 2 - generate grades, 3 - generate grades, first and last names, 4 - read from file, 5 - exit program" << endl;
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

int selectionSortingValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        cout << "How would you like the data to be sorted?" << endl;
        cout << "1 - by firstname, 2 - by lastname, 3 - by last average score, 4 - by last average median score, 5 - do not sort" << endl;
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
        cout << "Are you done with data entry?" << endl;
        cout << "1 - no, 2 - yes" << endl;
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
        cout << "How would you like to see the data?" << endl;
        cout << "1 - In Terminal, 2 - Writen to file" << endl;
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
        cout << "How many students data should be generated? (1-1000)" << endl;
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
        cout << endl << "How would you like to see the data?" << endl;
        cout << "1 - \"Galutinis(Vid.)\", 2 - \"Galutinis(Med.)\", 3 - \"Galutinis(Vid.) / Galutinis(Med.)\"" << endl;
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
                cout<<"Please enter fullname of the student: "<<endl;
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
                cout<<"Please enter fullname of the student: "<<endl;
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
            cout<< "Generated name: " << firstName << " " << lastName << endl;
            newStudentInfo.fisrtname = firstName;
            newStudentInfo.lastname = lastName;
            break;
        }
    }
    

    
    switch (selection)
    {
        case 1:
        {
            vector<int> grades;
            int i = 0;
            bool areWeDone = false;
            while (!areWeDone)
            {
                cout<<"Please enter the grade number " << i+1 << ": "<<endl;
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

            sort(grades.begin(), grades.end());

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
                cout<<"Please enter the students exam score: "<<endl;
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
            vector<int> generatedGrades = generateGrades();
            int examScore = generateExamScore();

            cout<< "Auto generated grades: ";
            for(int i = 0; i < generatedGrades.size(); i++){
                cout << generatedGrades[i] << " ";
            }
            cout << endl << "Auto generated exam score: " << examScore << endl << endl;

            sort(generatedGrades.begin(), generatedGrades.end());

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
            vector<int> generatedGrades = generateGrades();
            int examScore = generateExamScore();

            cout<< "Auto generated grades: ";
            for(int i = 0; i < generatedGrades.size(); i++){
                cout << generatedGrades[i] << " ";
            }
            cout << endl << "Auto generated exam score: " << examScore << endl << endl;

            sort(generatedGrades.begin(), generatedGrades.end());

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

void resulter(vector<studentInfo> allStudentInfo){
    if (allStudentInfo.size() == 0)
    {
        cout << "No data was found..." << endl;
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

         cout << "Pavarde";
        if (longestLastname<10)
        {
            cout << "   ";
        }else{
            for (int i = 0; i < longestLastname-7+2; i++)
            {
                cout << " ";
            }
        }
        
        cout << "Vardas";
        if (longestName < 9)
        {
            cout << "   ";
        }else{
            for (int i = 0; i < longestName-6+2; i++)
            {
                cout << " ";
            }
        }

        switch (selection)
        {
        case 1:
            cout << "Galutinis (Vid).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                cout << "-";
            }
            cout << "-----------------" << endl;
            break;
        case 2:
            cout << "Galutinis (Med).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                cout << "-";
            }
            cout << "-----------------" << endl;
            break;
        case 3:
            cout << "Galutinis (Vid). / Galutinis (Med).\n";
            for (int i = 0; i < longestName+2+longestLastname+2; i++)
            {
                cout << "-";
            }
            cout << "-----------------------------------" << endl;
        break;
        }

        for (int i = 0; i < allStudentInfo.size(); i++)
        {
            cout << allStudentInfo[i].lastname;
            if (longestLastname < 10)
            {
                for (int y = 0; y < (10 - allStudentInfo[i].lastname.length()); y++)
                {
                    cout << " ";
                }
            }else{
                for (int y = 0; y < (longestLastname - allStudentInfo[i].lastname.length())+2; y++)
                {
                    cout << " ";
                }
            }
            
            cout << allStudentInfo[i].fisrtname;
            if (longestName < 9)
            {
                for (int y = 0; y < (9 - allStudentInfo[i].fisrtname.length()); y++)
                {
                    cout << " ";
                }
            }else{
                for (int y = 0; y < (longestName - allStudentInfo[i].fisrtname.length())+2; y++)
                {
                    cout << " ";
                }
            }
            
            switch (selection)
            {
            case 1:
                cout<< fixed << setprecision(2) << allStudentInfo[i].average << endl;
                break;
            case 2:
                cout<< fixed << setprecision(2) << allStudentInfo[i].averageM << endl;
                break;
            case 3:
                if(allStudentInfo[i].average == 10){
                    cout<< fixed << setprecision(2) << allStudentInfo[i].average << "              " << allStudentInfo[i].averageM << endl;
                }else{
                    cout<< fixed << setprecision(2) << allStudentInfo[i].average << "               " << allStudentInfo[i].averageM << endl;
                }
                break;
            }
        }   
    }
}

vector<studentInfo> readData(string fileName, int readingType){
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
            vector<studentInfo> nothing;
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


            vector<studentInfo> storage;
            vector<int> gradesStorage;
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
            


                sort(gradesStorage.begin(), gradesStorage.end());

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
        vector<studentInfo> nothing;
        return nothing;
    }
}

void writeData(vector<studentInfo>  allStudentInfo){
    
    ofstream outFile("results.txt");
    if (allStudentInfo.size() == 0)
    {
        outFile << "No data was found..." << endl;
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
    cout << endl << "Done" << endl << "Results writen to file results.txt" << endl ;
}

void scenarioTester(){
    for (int i = 0; i < 5; i++)
    {
        readData("studentai1000000.txt", 1);
    }
    
}