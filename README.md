## Code Overview

The provided code is a C++ program for managing student information. It includes functionalities to input student data, calculate averages and medians, and display the results. Below is a summary of the key components and functionalities:

### Struct Definition

- `studentInfo`: A struct defining the structure of student information, including first name, last name, homework score, exam score, median, average, and modified average.

### Functions

1. `singleSutdentInfoPrinter`: Prints the information of a single student.
2. `calculateAverage`: Calculates the weighted average of homework and exam scores.
3. `findLongestName`: Finds the length of the longest first name among student data.
4. `findLongestLastname`: Finds the length of the longest last name among student data.
5. `invalidInput`: Prints a message for invalid input.
6. `singleInputModule`: Takes input for a single student's information.
7. `selectionOptionValidator`: Validates the selection for entering data.
8. `selectionEntryValidator`: Validates the selection for continuing data entry.
9. `selectionDisplayValidator`: Validates the selection for displaying data.
10. `resulter`: Displays the student information in a formatted manner.

### Main Function

- Handles the execution flow of the program.
- Provides options for entering data manually or generating data automatically.
- Calls appropriate functions based on user selections.

## Usage

1. Compile the code.
2. Run the executable.
3. Follow the prompts to enter or generate student data.
4. View the results displayed in the specified format.

## Dependencies

- `iostream`: Standard input/output stream.
- `string`: String handling library.
- `fstream`: File stream for handling file operations.
- `vector`: Dynamic array implementation for storing student data.
- `iomanip`: Input/output manipulators for formatting output.
- `algorithm`: Standard algorithms for operations on sequences.
- `regex`: Regular expressions for input validation.

## Notes

- The program is interactive and user-friendly, guiding the user through each step of data entry and display.
- It employs regular expressions for input validation, ensuring data integrity.
- The output is neatly formatted, providing clear visibility of student information.
