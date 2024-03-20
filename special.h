
#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>
#include <vector>
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

bool compareFisrtName(const studentInfo &a, const studentInfo &b);
bool compareLastName(const studentInfo &a, const studentInfo &b);
bool compareLastVid(const studentInfo &a, const studentInfo &b);
bool compareLastMed(const studentInfo &a, const studentInfo &b);
//===================== VECTOR ================
 class customCst {   
  public:
  vector<studentInfo> storage;
    void deleteE(int i) {
        storage.erase(storage.begin() + i);
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
  vector<int> storage;      
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

#endif // DATATYPES_H