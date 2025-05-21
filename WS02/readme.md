# Workshop #2: Dynamic Memory Allocation (DMA)
* Version 0.6 (submissions are not open yet)

In this workshop, you will implement a dynamic memory management module that works with structured sensor data. You'll practice:

- Allocating and managing dynamic memory for strings and arrays
- Appending dynamically to arrays
- Modular programming and integration with other modules

You are given:

- `cstr` module: contains utility functions like `strlen`, `strcpy`, etc.
- `sensorAnalysis` module: contains functions that analyze integer sensor data
- `main.cpp`: provided as a test harness that loads sensor data from a file and produces a report

You will implement:

- The `dma` module, which defines a `Samples` structure and manages its dynamic memory

## Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the abilities to:

- Dynamically allocate and deallocate memory for both strings and arrays using raw pointers.
- Implement dynamic memory management logic to grow arrays at runtime using new and delete[].
- Safely manage ownership of dynamic resources using structured cleanup routines (e.g., freemem).
- Use modular design by separating interface (.h) and implementation (.cpp) files.
- Integrate with existing modules to build reusable components.
- Use chunked reading and memory appending techniques to manage data of unknown size.


## Submission Policy and Instructions

This workshop is divided into two sections: a coding part and a reflection

The DIY section may also be presented at the end; do it on your own for practice (DIY is neither submitted nor marked).

- Part 1 **Homework**: A step-by-step guided workshop, worth 100% of the workshop’s total mark.
> Please note that Part 1 **is not** to be started in your lab session of the week. You should start it on your own before the day of your lab and then join the lab session to possibly seek assistance to complete your lab. These workshops must be submitted in the lab to receive 100% of the mark.

- Part 2, **Reflection**: A non-coding part, to be submitted a few days later (due date decided by your professor). The reflection doesn’t have marks associated with it but can incur a penalty of up to 40% of the whole workshop’s mark if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

- **DIY**: A Do It Yourself type of practice that is much more open-ended. This part does not need to be submitted to your professor and does not have any marks tied to it. However, you can always test your program using the automated submitter program or ask your professor for help or feedback.


## Due Dates
### Coding
Part 1 coding is due by the end of your lab session and is to be submitted from one of the desktop computers in the lab for 100% of the mark. You will receive 60% of the mark if you submit your code after the lab by midnight. No submissions are accepted after that.

> You have to submit your code using an SSH terminal client logged into the Matrix cluster from one of the desktop computers in the lab (we recommend using [PuTTY](https://www.putty.org/)). Note that you must only have one connection to the Matrix client; before logging into Matrix to submit your lab, make sure you are logged off all other terminal client sessions.

## Late Penalties
You are allowed to submit your workshop by midnight on the same day of your lab session with a 40% penalty. No submission is accepted after that.


## Citation Policy

Every submitted file must begin with a citation comment including:

- Your full name  
- Seneca email address  
- Seneca student ID  
- Subject and section  
- Dates of changes, debugging, and commits

**Workshops with a file without a citation will not be marked and will receive a grade of zero.**

> Do not copy and paste blindly. Read this policy, understand it, and apply it properly by updating the citation to match your work.

---

### If the Code Is Entirely Yours

If the file contains only your own work and/or code provided by your professor, add the following statement:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

---

### If the Code Includes External Help

If any part of your code is not yours (e.g., copied from online or from someone else), you must clearly state:

- Which part was not your own  
- Who provided it, or the source it came from

Also, in your `reflect.txt` file, list exactly what was added, in which file, and where or from whom it was received.

> You will lose marks only for the parts you received help on. Stating this clearly also protects the person who helped you.

---

### If You Helped Someone

If you shared part of your code with someone else, notify them of this policy. In your own `reflect.txt`, state:

- Which part of your code was shared  
- The name of the recipient

> This protects you if the recipient fails to cite the help properly.

---

> ⚠️ **Important:** Workshops are not group assignments.  
Submitting identical work or citing it as a group effort will result in the mark being **divided among all contributors**.

---

### Citation Example

### ✅ Code Done by You

```cpp
/* Citation and Sources...
-----------------------------------------------------------
Workshop ?? 
Module: Whatever
Filename: Whatever.cpp
-----------------------------------------------------------
Author: John Doe
Student number: 999,999,999
Email: jdoe@myseneca.ca
Subject: ABC123NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/?/?  Completing whatever
V0.8    2025/?/?  Debugged DMA
V0.9    2025/?/?  Asked prof for help for XYZ
V1.0    2025/?/?  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
```
---

### 🛠️ Code Done with Help

```cpp
/* Citation and Sources...
-----------------------------------------------------------
Workshop ?? 
Module: Whatever
Filename: Whatever.cpp
-----------------------------------------------------------
Author: John Doe
Student number: 999,999,999
Email: jdoe@myseneca.ca
Subject: ABC123NAA
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date      Reason
V0.7    2025/?/?  Completing whatever
V0.8    2025/?/?  Debugged DMA
V0.9    2025/?/?  Asked Jane Doe for function XYZ code
V1.0    2025/?/?  Ready for submission
-----------------------------------------------------------
Done all the work by myself apart from function XYZ.
Copied the code provided by Jane Doe for function XYZ
-----------------------------------------------------------  
*/
```

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **seneca** namespace unless instructed otherwise.

## Submission
SSH to matrix and then:
### Lab Submission
```bash
~profname.proflastname/submit 2??/wX/lab_sss <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

### Reflection Submission
```bash
~profname.proflastname/submit 2??/wX/ref_sss <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

### DIY Testing (No Submission)
DIY does not need submission and is for practice only, however, if you want to test your solution you can use the submit command as follows.
 
>This will not submit anything and only tests your program

```bash
~profname.proflastname/submit 2??/wX/diy_sss <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]


### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`utils.cpp and utils.h`) and submit them with your workshop using the following instructions.

To have your custom Utils module compiled with your workshop, add a **u** to the submission name of your workshop (i.e **u**lab_sss or **u**diy_sss) and issue the submission:

Example:
```bash
~profname.proflastname/submit 2??/wX/ulab_sss  <ENTER>
~profname.proflastname/submit 2??/wX/udiy_sss  <ENTER>
```

- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

### Testing Your lab before submission opens
You can always test your code before submission is open (providing your professor makes it available) and after submission is closed using the `-feedback` option:


Example:
```bash
~profname.proflastname/submit 2??/wX/lab_sss -feedback <ENTER>
~profname.proflastname/submit 2??/wX/ulab_sss -feedback <ENTER>
```

### submission options

To see all the options for submission issue the submit command with no arguments

Example:
```bash
~profname.proflastname/submit <ENTER>
```
---

# Coding Style

You must follow a consistent and readable coding style throughout your workshop. This includes:

* Use a consistent number of spaces (recommended: 4) or tabs for indentation. The indentation size must remain uniform across your entire codebase.
* Use a consistent block style for opening and closing braces `{}`. You may choose any of the common styles below, but **you must stick to one style** throughout your code.

### Common Brace Styles

**K\&R Style (Kernighan & Ritchie) – Recommended**
Opening brace on the same line as the control statement or function declaration:

```cpp
int main() {
    if (condition) {
        doSomething();
    } 
    else {
        doSomethingElse();
    }
}
```

**Allman Style**
Opening brace on a new line:

```cpp
int main()
{
    if (condition)
    {
        doSomething();
    }
    else
    {
        doSomethingElse();
    }
}
```

**Whitesmiths Style**
Opening brace is indented to align with the block:

```cpp
int main()
    {
    if (condition)
        {
        doSomething();
        }
    else
        {
        doSomethingElse();
        }
    }
```

---

### Naming Conventions

* **Structure and Class Names**
  Start with a capital letter and use CamelCase notation:
  Example: `ClassNameIsLikeThis`

* **Attributes (Structure and Class Member Variables)**
  Begin with `m_`, followed by a lowercase letter and then camelCase notation:
  Example: `m_memberVariableLikeThis`

* **Local Variables, Function Names, Parameters, and Others**
  Start with a lowercase letter and use camelCase notation. All names must be meaningful:
  Examples:

  * Variable: `orderCount`
  * Function: `calculateTotal()`
  * Parameter: `inputValue`





# Part 1 - LAB (100%) - SenecaTech Thermal Monitoring Facility

SenecaTech is a smart industrial automation company that manages multiple factory floors equipped with temperature sensors installed on motors, pipes, and equipment. These sensors monitor the thermal health of the machinery in real time.

However, due to bandwidth and storage limits, sensor data is not streamed continuously. Instead, compressed snapshots of readings are collected and sent in batches every hour by a third-party monitoring app in a file called `sensor_readings.txt`. 

You are a software developer at SenecaTech. Your team is building a backend system that processes this incoming sensor reading file. They have already developed the senesor analysis logic in `sensorAnalysis` module and the main logic, reading the data in small chunks in the `main` module

## Your Task

Your task is to develop a module called `dma` that receives the title of the sensor data and chunks of readings, and stores them in a structure containing a dynamically allocated title and a dynamically allocated integer array. The data is then used in the main module to generate a report.

### 🗂 Files You Will Work With

#### Provided:
- `sensorAnalysis.h` / `sensorAnalysis.cpp`
- `cstr.h` / `cstr.cpp`
- `main.cpp` (contains `loadStats()` and the report logic)

#### To Be Completed by You:
- `dma.h`
- `dma.cpp`
---

## 📦 Part A – The `Samples` Structure

Create a structure called `Samples` in `dma.h`:

```cpp
struct Samples {
    char* m_title;   // Dynamically allocated title
    int* m_data;     // Dynamically allocated array of integers
    int m_size;   // Number of elements in m_data
};
```

---

## ⚙️ Part B – Functions to Implement

Implement the following four functions in `dma.cpp`:

### 1. `Samples* CreateSamples(const char* title);`
- Allocates a new `Samples` object on the heap.
    - Dynamically allocates a single Sample object in a Sample pointer
- Dynamically copies the `title` into `m_title`.
    - Dynamically allocates an array of characters in m_title to the size of title and then copies the title into it.
- Sets `m_data` to `nullptr` and `m_size` to 0.
- Returns the allocated pointer.

### 2. `void add(Samples& S, const int data[], int size);`
- Adds a set of new readings to the `Samples` structure:
  - If `m_data` is `nullptr`, allocates and copies the incoming values.
    1. Allocate an array of int with same size of `data` pointer by `m_data`
    2. Copies all the elements of `data` into elements of dynamic `m_data`
  - If `m_data` already exists, uses `append()` to expand it and add the new values.
- Updates `m_size` accordingly.

### 3. `void append(int*& data, int size, const int appendedData[], int dataSize);`
- Dynamically creates a new array of size `size + dataSize`.
- Copies existing values and then appends new values.
- Frees the old array
- Updates the deleted `data` pointer to the newly allocated memory
> reflect: Why `int*&` is needed here and not `int*`?
### 4. `void freemem(Samples*& s);`
- Deallocates:
  - `m_title`
  - `m_data`
  - The `Samples` structure itself
- Sets the pointer `s` to `nullptr`.
> reflect: Why `Sample*&` is needed here and not `Sample*`
---


## The tester programs

### `testCreateSamples()`

```cpp
void testCreateSamples() {
    std::cout << "Test: CreateSamples()... ";

    const char* title = "Test Data Set";
    Samples* s = CreateSamples(title);

    bool ok = s && s->m_title && strcmp(s->m_title, title) == 0
              && s->m_data == nullptr && s->m_size == 0;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    freemem(s);
}
```

---

### `testAppend()`

```cpp
void testAppend() {
    std::cout << "Test: append()... ";

    int original[] = {1, 2, 3};
    int toAppend[] = {4, 5};
    int* data = new int[3];
    for (int i = 0; i < 3; ++i) data[i] = original[i];

    append(data, 3, toAppend, 2);

    bool ok = data[0] == 1 && data[1] == 2 && data[2] == 3 &&
              data[3] == 4 && data[4] == 5;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    delete[] data;
}
```

---

### `testAdd()`

```cpp
void testAdd() {
    std::cout << "Test: add()... ";

    Samples s;
    s.m_title = nullptr;
    s.m_data = nullptr;
    s.m_size = 0;

    int values1[] = {10, 20};
    int values2[] = {30};

    add(s, values1, 2); // Adds [10, 20]
    add(s, values2, 1); // Appends [30]

    bool ok = s.m_size == 3 &&
              s.m_data[0] == 10 &&
              s.m_data[1] == 20 &&
              s.m_data[2] == 30;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    delete[] s.m_data;
}
```

---

### `testFreemem()`

```cpp
void testFreemem() {
    std::cout << "Test: freemem()... ";

    Samples* s = new Samples;
    s->m_title = new char[6];
    strcpy(s->m_title, "Hello");

    s->m_data = new int[3]{1, 2, 3};
    s->m_size = 3;

    freemem(s);

    bool ok = (s == nullptr);

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;
}
```
To ensure that your implementation of the DMA module is memory-safe and correctly manages dynamic memory, you must [run all the unit tests using Valgrind](#compiling-and-testing-your-program) 
    
These tests check for:

- Correct memory allocation and deallocation
- No memory leaks
- No use of uninitialized or deleted memory

After compiling your test file and running the executable through Valgrind, there should be `in use at exit: 0 bytes in 0 blocks` and `All heap blocks were freed -- no leaks are possible` reported for all test cases.

Failure to ensure memory safety will result in a loss of marks, even if the program appears to function correctly.

## Submission tester

[main.cpp](./lab/main.cpp)

## Expected output

[correct_output.txt](./lab/correct_output.txt)

## LAB Submission (part 1) 


### Files to submit:  
```Text
cstr.cpp
cstr.h
sensorAnalysis.cpp
sensorAnalysis.h
dma.h
dma.cpp
main.cpp
sensor_readings.txt
```

### Data Entry

No data entry is needed

---

### Submission Process

Log in to Matrix using an SSH terminal client (e.g., **PuTTY**).

Commit and push your code to GitHub, then pull the changes to your Matrix account.  
Follow the instructions in [Compiling and Testing Your Program](#compiling-and-testing-your-program) to ensure everything runs correctly.

Next, run the **submission command** from within your workshop repository folder on your Matrix account.

---

#### Submitting Utils Module

Refer to the [Custom Code Submission](#custom-code-submission) section for details on how to submit the `Utils` module.

> ⚠️ **Important:** A successful submission **does not guarantee full credit** for this workshop.  
> If your professor is not satisfied with your implementation, you may be asked to **resubmit**, and **a penalty will apply**.

---

### Reflection

Review your final solutions, revisit the related course material, and ensure you understand the concepts covered in this workshop.  
**This review should take about 30 minutes**, and the written reflection should be **at least 150 words**.

Create a file named `reflect.txt` describing:

- What you learned during the workshop  
- Any difficulties you encountered  
- Any feedback or suggestions for your professor

You may be asked to present your reflection in class.

---

#### Reflection Submission

Add and  commit the `reflect.txt` file to your workshop repository folder and then push it to GitHub. Then pull it to your Matrix account, and run the submission command from that folder.


# DIY  
No DIY for this workshop

