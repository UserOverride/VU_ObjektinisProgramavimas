## Code Overview

The provided code is a C++ program for managing student information. It includes functionalities to input student data, calculate averages and medians, and display the results. Below is a summary of the key components and functionalities:

## File Generation Performance Investigation 1

The following data represents the time taken to generate files with varying amounts of student data.

| File Name         | Number of Students | Time Taken (s) |
|-------------------|--------------------|----------------|
| "test1000.txt"    | 1,000              | 0.006719       |
| "test10000.txt"   | 10,000             | 0.053824       |
| "test100000.txt"  | 100,000            | 1.039215       |
| "test1000000.txt" | 1,000,000          | 6.718065       |
| "test10000000.txt"| 10,000,000         | 56.34281       |

Overall, the file generation has completed with the following total time:

| Description      | Time Taken (s) |
|------------------|----------------|
| Total time       | 64.1606644     |

![file generation](/img/1.png "file generation")

## File Processing Performance Investigation 2

The following table represents the time taken at each stage of processing files with various numbers of student records.

### Test File: test1000.txt
| Process                    | Time Taken (s) |
|----------------------------|----------------|
| Time taken to read file    | 0.007024       |
| Time to separate students  | 0.001002       |
| Time to write good students| 0.003000       |
| Time to write bad students | 0.003229       |
| **Total time taken**       | 0.014254       |

### Test File: test10000.txt
| Process                    | Time Taken (s) |
|----------------------------|----------------|
| Time taken to read file    | 0.065032       |
| Time to separate students  | 0.006636       |
| Time to write good students| 0.036107       |
| Time to write bad students | 0.035537       |
| **Total time taken**       | 0.142712       |

### Test File: test100000.txt
| Process                    | Time Taken (s) |
|----------------------------|----------------|
| Time taken to read file    | 0.640436       |
| Time to separate students  | 0.047090       |
| Time to write good students| 0.373138       |
| Time to write bad students | 0.435846       |
| **Total time taken**       | 1.496509       |

### Test File: test1000000.txt
| Process                    | Time Taken (s) |
|----------------------------|----------------|
| Time taken to read file    | 6.418524       |
| Time to separate students  | 0.509076       |
| Time to write good students| 3.735303       |
| Time to write bad students | 3.689919       |
| **Total time taken**       | 14.352821      |

### Test File: test10000000.txt
| Process                    | Time Taken (s) |
|----------------------------|----------------|
| Time taken to read file    | 64.757721      |
| Time to separate students  | 5.572400       |
| Time to write good students| 40.514532      |
| Time to write bad students | 39.176791      |
| **Total time taken**       | 150.021444     |

![File Processing](/img/2.png "File Processing")
