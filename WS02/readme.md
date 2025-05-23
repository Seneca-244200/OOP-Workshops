# Workshop #2: Dynamic Memory Allocation (DMA)
* Version 0.9 (being reviewed)


> ⚠️ **Before You Begin**
> You **must read and understand** the [Workshop Regulations and Policies](../README.md) before starting this or any other workshop. This document outlines important rules about academic integrity, submission procedures, and expectations.
> These policies apply to **all workshops** in OOP244. If you have already read it once, please ensure you continue to follow its guidelines throughout the course.



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

    const char title[] = "Test Data Set";
    Samples* s = CreateSamples(title);

    bool ok = s && s->m_title && strcmp(s->m_title, title) == 0
              && s->m_data == nullptr && s->m_size == 0;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    delete[] s->m_title;
    delete s;
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
Follow the instructions in [Compiling and Testing Your Program](../README.md#compiling-and-testing-your-program) to ensure everything runs correctly.

Next, run the **submission command** from within your workshop repository folder on your Matrix account.

---

#### Submitting Utils Module

Refer to the [Custom Code Submission](../README.md#custom-code-submission) section for details on how to submit the `Utils` module.

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

