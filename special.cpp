#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <deque>
#include <vector>
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

// //===================== VECTOR ================
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
// //===================== VECTOR ================

// //===================== LIST ================
// // class customCst {    
// // public:
// // list<studentInfo> storage;
// //     void deleteE(int i) {
// //         auto it = storage.begin();
// //         std::advance(it, i); 
// //         storage.erase(it); 
// //     }
// //   void sort(int selection){
// //     switch (selection)
// //     {
// //     case 1:
// //       storage.sort(compareFisrtName); 
// //       break;
// //     case 2:
// //       storage.sort(compareLastName); 
// //       break;
// //     case 3:
// //       storage.sort(compareLastVid); 
// //       break;
// //     case 4:
// //       storage.sort(compareLastMed); 
// //       break;
// //     default:
// //       storage.sort(compareLastVid); 
// //       break;
// //     }
// //   };
// //   void push_back(studentInfo next){
// //     storage.push_back(next);
// //   };
// //   int size(){
// //     return storage.size();
// //   };
// //   void clear(){
// //     storage.clear();
// //   };
// //   studentInfo& operator[](int index) {
// //     auto it = storage.begin();
// //     std::advance(it, index);
// //     return *it;
// //   };
// // };
// // class customCi { 
// // list<int> storage;      
// // public:       
// //     void reverseSort() {
// //         // Sorts the list in descending order using a lambda that returns true if the first argument is greater than the second
// //         storage.sort([](const int& a, const int& b) {
// //             return a > b;
// //         });
// //     };      
// //   void sort(){
// //     storage.sort();
// //   };
// //   void push_back(int next){
// //     storage.push_back(next);
// //   };
// //   int size(){
// //     return storage.size();
// //   };
// //   void clear(){
// //     storage.clear();
// //   };
// //   int& operator[](int index) {
// //     auto it = storage.begin();
// //     std::advance(it, index);
// //     return *it;
// //   };
// // };
// //===================== LIST ================

// //===================== deque ================
// // class customCst {    
// // public:
// // deque<studentInfo> storage;
// //   void deleteE(int i){
// //     auto it = storage.begin();
// //     std::advance(it, i); 
// //     storage.erase(it);
// //   };
// //   void sort(int selection){
// //     switch (selection)
// //     {
// //     case 1:
// //       std::sort(storage.begin(), storage.end(), compareFisrtName); 
// //       break;
// //     case 2:
// //       std::sort(storage.begin(), storage.end(), compareLastName); 
// //       break;
// //     case 3:
// //       std::sort(storage.begin(), storage.end(), compareLastVid); 
// //       break;
// //     case 4:
// //       std::sort(storage.begin(), storage.end(), compareLastMed); 
// //       break;
// //     default:
// //       std::sort(storage.begin(), storage.end(), compareLastVid); 
// //       break;
// //     }
// //   };
// //   void push_back(studentInfo next){
// //     storage.push_back(next);
// //   };
// //   int size(){
// //     return storage.size();
// //   };
// //   studentInfo& operator[](int index) {
// //       return storage[index];
// //   };
// //   void clear(){
// //     storage.clear();
// //   };
// // };
// // class customCi { 
// //   std::deque<int> storage;      
// // public:         
// //   void reverseSort(){
// //     std::sort(storage.rbegin(), storage.rend());
// //   };   
// //   void sort(){
// //     std::sort(storage.begin(), storage.end());
// //   };
// //   void push_back(int next){
// //     storage.push_back(next);
// //   };
// //   int size(){
// //     return storage.size();
// //   };
// //   int& operator[](int index) {
// //       return storage[index];
// //   };
// //   void clear(){
// //     storage.clear();
// //   };
// // };
// //===================== deque ================
