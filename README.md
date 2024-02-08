# Documentation for v.pradinė version

## Overview

This program is designed to manage student information including their names, homework scores, exam scores, and calculated averages and medians. It generates random student data, calculates statistics, and displays the information in a formatted manner.

## File Structure

The program consists of a single source code file named `student_info_management.cpp`.

## Functions

### calculateAverage(double homeworkScore, double examScore)
- Calculates the weighted average of a student's homework and exam scores.
- Parameters:
  - `homeworkScore`: The score obtained from homework assignments.
  - `examScore`: The score obtained from exams.
- Returns: Weighted average of homework and exam scores.

### dataGeneration(int numberOfStudents)
- Generates random student data and writes it to a file named `data.dat`.
- Parameters:
  - `numberOfStudents`: The number of students for which data should be generated.

### findLongestName(vector<studentInfo> data)
- Finds the length of the longest name among the student data.
- Parameters:
  - `data`: A vector containing student information.
- Returns: Length of the longest name.

### findLongestLastname(vector<studentInfo> data)
- Finds the length of the longest last name among the student data.
- Parameters:
  - `data`: A vector containing student information.
- Returns: Length of the longest last name.

### main()
- The main function of the program.
- Reads student data from the `data.dat` file, calculates statistics, and displays the information in a formatted table.
- Utilizes the other functions defined in the program to accomplish its tasks.

## Usage

To use this program:

1. Compile the source code file `student_info_management.cpp`.
2. Run the compiled executable.
3. Optionally, uncomment the `dataGeneration(100)` call in the `main()` function to generate random student data.
4. Run the program again to see the results.

## Dependencies

- `iostream`: Standard input/output stream.
- `fstream`: Input/output stream class to operate on files.
- `vector`: Standard template library (STL) container for dynamic arrays.
- `string`: String class for handling strings.
- `algorithm`: Standard template library (STL) algorithms like `sort`.
- `ctime`: Standard library for date and time manipulation.
- `iomanip`: Standard library for manipulating input/output format.

## Notes

- The program generates 100 random student data if the `dataGeneration(100)` call in the `main()` function is uncommented.
- The `data.dat` file is used to store and retrieve the student data.
- The program calculates the average and median scores for each student based on their homework and exam scores.
- The output is displayed in a formatted table showing each student's last name, first name, average score, and median score.
