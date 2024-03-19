## Code Overview

The provided code is a C++ program for managing student information. It includes functionalities to input student data, calculate averages and medians, and display the results. 

## File Processing Performance Investigation 2

The following table represents the time taken at each stage of processing files with various numbers of student records.

| File Size         | Container | Read File Time | Separate Students Time | Write Good Students Time | Write Bad Students Time | Total Time |
|-------------------|-----------|----------------|------------------------|--------------------------|-------------------------|------------|
| **test1000.txt**  | Vector    | 0.0075s        | 0.0010s                | 0.0030s                  | 0.0040s                 | 0.0155s    |
|                   | List      | 0.0170s        | 0.0075s                | 0.0115s                  | 0.0155s                 | 0.0516s    |
|                   | Deque     | 0.0090s        | 0.0000s                | 0.0055s                  | 0.0045s                 | 0.0190s    |
| **test10000.txt** | Vector    | 0.0728s        | 0.0065s                | 0.0367s                  | 0.0401s                 | 0.1562s    |
|                   | List      | 0.1599s        | 1.1006s                | 2.6676s                  | 2.5545s                 | 6.4826s    |
|                   | Deque     | 0.1047s        | 0.0095s                | 0.0428s                  | 0.0436s                 | 0.2005s    |
| **test100000.txt**| Vector    | 0.6999s        | 0.0577s                | 0.3905s                  | 0.5062s                 | 1.6543s    |
|                   | List      | 1.5872s        | 226.5487s              | N/A                      | N/A                     | N/A        |
|                   | Deque     | 0.9147s        | 0.1368s                | 0.5529s                  | 0.7784s                 | 2.3828s    |
| **test1000000.txt**| Vector   | 6.9392s        | 0.6540s                | 3.9547s                  | 3.9156s                 | 15.4634s   |
|                    | List     | N/A            | N/A                    | N/A                      | N/A                     | N/A        |
|                    | Deque    | 10.8510s       | 1.4949s                | 6.9296s                  | 5.2499s                 | 24.5254s   |
| **test10000000.txt**| Vector  | 68.8495s       | 6.4124s                | 41.6457s                 | 40.3120s                | 157.2196s  |
|                     | List    | N/A            | N/A                    | N/A                      | N/A                     | N/A        |
|                     | Deque   | 91.3593s       | 11.9708s               | 60.1817s                 | 61.3513s                | 224.8631s  |

Overall, the performance testing of `std::vector`, `std::list`, and `std::deque` across different file sizes reveals distinct characteristics and efficiencies for each container:

- **`std::vector`** demonstrates the best overall performance for all tested file sizes. It shows superior efficiency in terms of read, write, and processing times. The linear memory layout likely contributes to faster access and iteration times, making it the most suitable choice for tasks involving large datasets and requiring frequent access and modifications.

- **`std::list`** exhibits significant performance challenges as the dataset size increases. Specifically, the operation to separate students into good and bad categories becomes drastically less efficient with larger files. This container's design, which allows for efficient insertion and deletion from anywhere in the list, does not compensate for its overall slower performance in the tested scenarios, particularly with large amounts of data.

- **`std::deque`** provides a middle ground in performance between `std::vector` and `std::list`. While it offers better flexibility than `std::list` for certain operations, it does not match the high efficiency of `std::vector` for larger datasets. Its performance, however, remains competitive for smaller datasets.

In conclusion, while each container has its specific use cases and advantages, `std::vector` emerges as the most efficient option for the broad range of tasks involved in this performance testing, especially for handling large datasets.


![file generation](/img/b3.png "file generation")
![file generation](/img/b2.png "file generation")
![file generation](/img/b1.png "file generation")
