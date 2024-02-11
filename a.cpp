#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <regex>

using namespace std;

struct studentInfo {
    string fisrtname = "", lastname = "";
    double homeworkScore = 0, examScore = 0, median = 0, average = 0, averageM = 0;
};

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

studentInfo singleInputModule(){
    
    studentInfo newStudentInfo;
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

    bool gradesValid = false;
    while (!gradesValid)
    {
        regex pat {R"(^([1-9]|[1-9][0-9]|1[0-9]{2}|200))"};
        cout<<"Please enter the number of student grades from 1 to 200: "<<endl;
        string tmp = "";
        getline(cin, tmp);
        smatch sm;
        gradesValid = regex_match(tmp,sm,pat);
        if (!gradesValid)
        {
            invalidInput();
        }else
        {
            vector<int> grades;
            for (int i = 0; i < stoi(tmp); i++)
            {
                cout<<"Please enter the grade number " << i+1 << ": "<<endl;
                regex patGrade {R"(^([1-9]|10))"};
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
                    }
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

            int numberOfHomeWork = stoi(tmp);
            if (numberOfHomeWork%2 == 0)
            {
                newStudentInfo.median = (grades[(numberOfHomeWork/2)] + grades[(numberOfHomeWork/2)-1]) / 2.0;
            }else{
                newStudentInfo.median = grades[(numberOfHomeWork/2)];
            }
        }
    }

    bool examScoreValid = false;
    while (!examScoreValid)
    {
        regex pat {R"(^([1-9]|10))"};
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
            
    return newStudentInfo;
}

int selectionOptionValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        cout << "How would you like to enter data?" << endl;
        cout << "1 - by hand, 2 - generate grades, 3 - generate grades, first and last names, 4 - exit program" << endl;
        regex pat {R"(^([1-3]|4))"};
        string tmp = "";
        getline(cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        if (!inputTrue)
        {
            invalidInput();
        }else{
            selection = stoi(tmp);
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
        if (!inputTrue)
        {
            invalidInput();
        }else{
            selection = stoi(tmp);
        }
    }
    return selection;
}

int selectionDisplayValidator(){
    bool inputTrue = false;
    int selection = 0;
    while (!inputTrue)
    {
        cout << "How would you like to see the data?" << endl;
        cout << "1 - Vid(), 2 - yes" << endl;
        regex pat {R"(^([1-2]|3))"};
        string tmp = "";
        getline(cin, tmp);
        smatch sm;
        inputTrue = regex_match(tmp,sm,pat);
        if (!inputTrue)
        {
            invalidInput();
        }else{
            selection = stoi(tmp);
        }
    }
    return selection;
}


int main() {
    ifstream inFile("data.dat");

    vector<studentInfo> allStudentInfo;
    cout << "Hello,\nYou will be asked to enter students data.\nPress Enter to Continue.\n";
    cin.ignore();
    int selection = selectionOptionValidator();
    bool doneWithDataEntry = false;
    switch (selection)
    {
    case 1:
        while (!doneWithDataEntry)
        {
            allStudentInfo.push_back(singleInputModule());
            int option = selectionEntryValidator();
            switch (option)
            {
            case 1:
                allStudentInfo.push_back(singleInputModule());
                break;
            case 2:
                doneWithDataEntry = true;
                break;
            default:
                invalidInput();
                break;
            }
        }
        break;
    case 2:
        cout << "Now ready"<<endl;
        break;
    case 3:
        cout << "Now ready"<<endl;
        break;
    case 4:
        cout<< "Ending the program..." << endl <<endl;
        break;
    default:
        invalidInput();
        break;
    }
    // while(true)
    // {
    
    //     studentInfo newInformation;
    //     int numberHomeWork = 0;
    //     int homeWorkToalScore = 0;
    //     inFile >> newInformation.name >> newInformation.lastname >> numberHomeWork;
    //     vector<int> grades;
    //     for (int i = 0; i < numberHomeWork; i++)
    //     {
    //         int tmp;
    //         inFile >> tmp;
    //         grades.push_back(tmp);
    //     }
        
    //     sort(grades.begin(), grades.end());
        
    //     for (int i = 0; i < grades.size(); i++)
    //     {
    //         homeWorkToalScore += grades[i];
    //     }

    //     if (floor(numberHomeWork) == numberHomeWork)
    //     {
    //         newInformation.median = (grades[(numberHomeWork/2)] + grades[(numberHomeWork/2) -1 ]) / 2.0;
    //     }else{
    //         newInformation.median = grades[(numberHomeWork/2)+1];
    //     }
        
        
    //     inFile>> newInformation.examScore;
    //     if(numberHomeWork > 0){
    //       newInformation.homeworkScore = (double)homeWorkToalScore/numberHomeWork;
    //     }else{
    //       newInformation.homeworkScore = 0;
    //     }
    //     newInformation.average = calculateAverage(newInformation.homeworkScore, newInformation.examScore);

    //     studentInfoFromFile.push_back(newInformation);
    // }

    // int longestName = findLongestName(studentInfoFromFile);
    // int longestLastname = findLongestLastname(studentInfoFromFile);

    // //add min protection
    // cout << "Pavarde";
    // for (int i = 0; i < longestLastname-7+2; i++)
    // {
    //     cout << " ";
    // }

    // cout << "Vardas";
    // for (int i = 0; i < longestName-6+2; i++)
    // {
    //     cout << " ";
    // }

    // cout << "Galutinis (Vid). / Galutinis (Med).\n";
    // for (int i = 0; i < longestName+2+longestLastname+2; i++)
    // {
    //     cout << "-";
    // }
    // cout << "-----------------------------------" << endl;
    
    // for (int i = 0; i < studentInfoFromFile.size(); i++)
    // {
    //     cout << studentInfoFromFile[i].lastname;
    //     for (int y = 0; y < (longestLastname - studentInfoFromFile[i].lastname.length())+2; y++)
    //     {
    //         cout << " ";
    //     }

    //     cout << studentInfoFromFile[i].name;
    //     for (int y = 0; y < (longestName - studentInfoFromFile[i].name.length())+2; y++)
    //     {
    //         cout << " ";
    //     }
    //     cout<< fixed << setprecision(2) << studentInfoFromFile[i].average << "               " << studentInfoFromFile[i].median << endl;
    // }
    
    return 0;
}

