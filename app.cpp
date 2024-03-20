#include <iostream>
#include <string>
#include <ctime> 
#include <algorithm>
#include "functions.h"

using namespace std;

int runApp(){
    srand(time(0));

    customCst allStudentInfo;
    // dotests();
    cout << "Hello,\nYou will be asked to enter students data.\nPress Enter to Continue.\n";
    cin.ignore();
    // scenarioTester();
    bool notDone = true;
    while (notDone)
    {
        int selection = selectionOptionValidator();
        switch (selection)
        {
        case 1:
        {
            allStudentInfo.push_back(singleInputModule(selection));
            bool doneWithDataEntry = false;
            while (!doneWithDataEntry)
            {
                int option = selectionEntryValidator();
                switch (option)
                {
                case 1:
                    allStudentInfo.push_back(singleInputModule(selection));
                    break;
                case 2:
                    doneWithDataEntry = true;
                    break;
                default:
                    invalidInput();
                    break;
                }
            }
            if(selectionOutputValidator() == 1){
                resulter(allStudentInfo);
            }else{
                writeData(allStudentInfo, "res.txt", 1);
            }
            allStudentInfo.clear();
            cout << endl << endl;
            break;
        }
        case 2:
        {
            allStudentInfo.push_back(singleInputModule(selection));
            bool doneWithDataEntry = false;
            while (!doneWithDataEntry)
            {
                int option = selectionEntryValidator();
                switch (option)
                {
                case 1:
                    allStudentInfo.push_back(singleInputModule(selection));
                    break;
                case 2:
                    doneWithDataEntry = true;
                    break;
                default:
                    invalidInput();
                    break;
                }
            }
            if(selectionOutputValidator() == 1){
                resulter(allStudentInfo);
            }else{
                writeData(allStudentInfo, "res.txt", 1);
            }
            allStudentInfo.clear();
            cout << endl << endl;
            break;
        }
        case 3:
        {
            int numberOfStudentsToGenerate = selectionGenerationValidator();
            for (int i = 0; i < numberOfStudentsToGenerate; i++)
            {
                allStudentInfo.push_back(singleInputModule(selection));
            }
            if(selectionOutputValidator() == 1){
                resulter(allStudentInfo);
            }else{
                writeData(allStudentInfo, "res.txt", 1);
            }
            allStudentInfo.clear();
            cout << endl << endl;
            break;
        }
        case 5:
        {
            generateTestFiles();
            allStudentInfo.clear();
            cout << endl << endl;
            break;
        }
        case 6:
        {
            dotests();
            allStudentInfo.clear();
            cout << endl << endl;
            break;
        }
        case 4:
        {
            allStudentInfo = readData("studentai100000.txt", 1);
            if (allStudentInfo.size() != 0)
            {
                if(selectionOutputValidator() == 1){
                    resulter(allStudentInfo);
                }else{
                    writeData(allStudentInfo, "res.txt", 1);
                }
            }
            allStudentInfo.clear();
            cout << endl << endl;
            break;
        }
        case 7:
        {
            cout<< "Ending the program..." << endl <<endl;
            notDone = false;
            break;
        }
        default:
        {
            invalidInput();
            break;
        }
        }
    }
    return 0;
}