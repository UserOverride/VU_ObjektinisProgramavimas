#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <regex>

using namespace std;

struct studentInfo {
    string name = "", lastname = "";
    double homeworkScore = 0, examScore = 0, median = 0, average = 0;
};

double calculateAverage(double homeworkScore, double examScore){
    return 0.4 * homeworkScore + 0.6 * examScore;
}

int findLongestName(vector<studentInfo> data){
    int longestName = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (longestName < data[i].name.length())
        {
            longestName = data[i].name.length();
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
    regex pat {R"(^([a-zA-Z]{2,}\s[a-zA-Z]{1,}'?-?[a-zA-Z]{2,}\s?([a-zA-Z]{1,})?))"};

    while (!nameValid)
    {
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
            newStudentInfo.name = tmp.substr(0, spaceLocation);
            newStudentInfo.lastname = tmp.substr(spaceLocation+1, tmp.length());
        }
    }
  
    return newStudentInfo;
}

int main() {
    ifstream inFile("data.dat");

    vector<studentInfo> studentInfoFromFile;
    cout << "Hello,\nYou will be asked to enter students data.\nPress Enter to Continue.\n";
    // cin.ignore();
  
    singleInputModule();
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

