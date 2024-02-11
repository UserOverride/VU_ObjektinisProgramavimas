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
        cout << "1 - \"Galutinis(Vid.)\", 2 - \"Galutinis(Med.)\", 3 - \"Galutinis(Vid.) / Galutinis(Med.)\"" << endl;
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

int main() {
    // ifstream inFile("data.dat");

    vector<studentInfo> allStudentInfo;
    cout << "Hello,\nYou will be asked to enter students data.\nPress Enter to Continue.\n";
    cin.ignore();
    int selection = selectionOptionValidator();
    bool doneWithDataEntry = false;
    switch (selection)
    {
    case 1:
        allStudentInfo.push_back(singleInputModule());
        while (!doneWithDataEntry)
        {
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
        resulter(allStudentInfo);
        break;
    case 2:
        cout << "Not done"<<endl;
        break;
    case 3:
        cout << "Not done"<<endl;
        break;
    case 4:
        cout<< "Ending the program..." << endl <<endl;
        break;
    default:
        invalidInput();
        break;
    }
    
    return 0;
}

