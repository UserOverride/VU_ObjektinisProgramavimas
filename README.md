## Code Overview

The provided code is a C++ program for managing student information. It includes functionalities to input student data, calculate averages and medians, and display the results. 

## File Processing Performance Investigation 

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

## Splitting Students Using Different Methods Performance Investigation

| Test Size | Container   | Method | Read Time (s) | Separate Time (s) | Write Good Time (s) | Write Bad Time (s) | Total Time (s) |
|-----------|-------------|--------|---------------|-------------------|---------------------|--------------------|----------------|
| 1000      | std::vector | 1      | 0.008255      | 0.001004          | 0.002998            | 0.004007           | 0.016265       |
| 10000     | std::vector | 1      | 0.070629      | 0.006004          | 0.041933            | 0.037107           | 0.155674       |
| 1000      | std::vector | 2      | 0.007061      | 0.013513          | 0.004509            | 0.003841           | 0.028924       |
| 10000     | std::vector | 2      | 0.066073      | 1.252444          | 0.034570            | 0.035542           | 1.388630       |
| 1000      | std::vector | 3      | 0.010513      | 0.001000          | 0.004513            | 0.005005           | 0.021031       |
| 10000     | std::vector | 3      | 0.067732      | 0.008503          | 0.037265            | 0.036373           | 0.149873       |
| 1000      | std::list   | 1      | 0.017031      | 0.010039          | 0.012505            | 0.014509           | 0.054084       |
| 10000     | std::list   | 1      | 0.169436      | 1.169468          | 2.696068            | 2.543531           | 6.578503       |
| 1000      | std::list   | 2      | 0.016951      | 0.011502          | 0.011512            | 0.015512           | 0.055477       |
| 10000     | std::list   | 2      | 0.179428      | 1.220004          | 2.681421            | 2.930422           | 7.011275       |
| 1000      | std::list   | 3      | 0.017038      | 0.009501          | 0.014531            | 0.014511           | 0.055582       |
| 10000     | std::list   | 3      | 0.181387      | 1.178462          | 2.632897            | 2.702721           | 6.695467       |
| 1000      | std::deque  | 1      | 0.008509      | 0.001003          | 0.003997            | 0.005514           | 0.019024       |
| 10000     | std::deque  | 1      | 0.080198      | 0.008511          | 0.042773            | 0.043580           | 0.175062       |
| 1000      | std::deque  | 2      | 0.009513      | 0.011473          | 0.004508            | 0.005005           | 0.030499       |
| 10000     | std::deque  | 2      | 0.083064      | 1.097199          | 0.041712            | 0.047215           | 1.269190       |
| 1000      | std::deque  | 3      | 0.008511      | 0.001000          | 0.004506            | 0.004598           | 0.018615       |
| 10000     | std::deque  | 3      | 0.077897      | 0.010515          | 0.043049            | 0.048098           | 0.179559       |


## Summary of Findings: Overall Time Taken

### Test Size: 1000

- **std::vector**
  - Method 1: 0.016265s
  - Method 2: 0.028924s
  - Method 3: 0.021031s
- **std::list**
  - Method 1: 0.054084s
  - Method 2: 0.055477s
  - Method 3: 0.055582s
- **std::deque**
  - Method 1: 0.019024s
  - Method 2: 0.030499s
  - Method 3: 0.018615s

### Test Size: 10000

- **std::vector**
  - Method 1: 0.155674s
  - Method 2: 1.388630s
  - Method 3: 0.149873s
- **std::list**
  - Method 1: 6.578503s
  - Method 2: 7.011275s
  - Method 3: 6.695467s
- **std::deque**
  - Method 1: 0.175062s
  - Method 2: 1.269190s
  - Method 3: 0.179559s

## Observations

- For small datasets (test size 1000), `std::vector` and `std::deque` show competitive performance across all methods, with `std::deque` slightly outperforming `std::vector` in Methods 1 and 3. `std::list` is significantly slower.
- For larger datasets (test size 10000), `std::vector` and `std::deque` again show competitive performance, with `std::vector` having a slight edge in Methods 1 and 3. `std::list` performance is much slower compared to `std::vector` and `std::deque`.
- Method 2 significantly increases the overall time for both `std::vector` and `std::deque` in the larger dataset, indicating it may be less efficient compared to Methods 1 and 3 for these container types.
- `std::list` shows consistently higher overall times, making it the least efficient choice for both test sizes across all methods.

# Installing and Running a Make C++ Project on Windows

This guide will help you set up your Windows environment to compile and run Make-based C++ projects using Chocolatey and Make. It is designed for simplicity, allowing you to use `make` for compilation and executing your project with `main`.

## Step 1: Install Chocolatey

Chocolatey is a package manager for Windows that simplifies the process of managing software installations.

1. **Open Command Prompt as Administrator**
   - Press `Win + X` and select “Command Prompt (Admin)” or “Windows PowerShell (Admin)”.

2. **Install Chocolatey**
   - Copy and paste the following command:

     ```powershell
     Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
     ```

3. **Verify Installation**
   - Type `choco` and press Enter to check if Chocolatey is installed correctly.

## Step 2: Install Make

With Chocolatey installed, you can easily install Make.

1. **Install Make**
   - In the same Command Prompt window (as Administrator), type and execute:

     ```shell
     choco install make
     ```

2. **Verify Make Installation**
   - Type `make -v` to see if Make is successfully installed and to check its version.

## Step 3: Compile and Run Your C++ Project

Now that you have Make installed, you can compile and run your C++ project.

1. **Navigate to Your Project Directory**
   - Use the `cd` command to change to your project's directory that contains the `Makefile`.

2. **Compile the Project**
   - Simply type `make` and press Enter to compile your project.

3. **Run Your Project**
   - Once compiled, you can run your project by typing `main` (or the name of your executable as defined in your `Makefile`).

This setup is streamlined for testing and may not cover all the options available with Make. For more comprehensive details, refer to the Make documentation or the linked Stack Overflow guide.


![file generation](/img/b3.png "file generation")
![file generation](/img/b2.png "file generation")
![file generation](/img/b1.png "file generation")
