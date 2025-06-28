
# Workshop #9: Derived Classes and Resources
**Version 1.0**

---
> ⚠️ **Before You Begin**
> You **must read and understand** the [Workshop Regulations and Policies](../README.md) before starting this or any other workshop. This document outlines important rules about academic integrity, submission procedures, and expectations.
> These policies apply to **all workshops** in OOP244. If you have already read it once, please ensure you continue to follow its guidelines throughout the course.
---


In this workshop, you will complete a derived class called `Transcript`, ensuring proper management of resources and implementing its functionality effectively. The `Transcript` class inherits from the fully developed `Marks` class.

---

## Learning Outcomes

Upon successful completion of this workshop, you will be able to:

- Design and implement a constructor for a derived class with dynamic memory allocation.
- Develop a copy constructor for a derived class, ensuring deep copying of resources.
- Overload the copy assignment operator for a derived class while managing resource ownership.
- Implement a destructor for a derived class with dynamically allocated resources.
- Reflect on and describe your learning experience from completing this workshop.

---



# Part 1 - LAB (100%)
## Marks Module 

The **Marks Module** is a fully implemented module that manages a collection of marks, each associated with a title (e.g., "Math: 85"). The module consists of two classes:

1. **Mark Class**: Represents a single mark with a title and a score. It manages its own dynamic memory for the title string and provides functionality to set, retrieve, and copy marks.

2. **Marks Class**: Represents a collection of `Mark` objects, dynamically managing their storage. It supports adding marks, accessing individual marks by index, and displaying the collection in a formatted manner.

Students are **strongly encouraged** to carefully review the provided code for the `Marks` module to understand its design and implementation. This understanding will help when extending it in the derived `Transcript` class.

---

### Unit Test for the Marks Module

Below is a simple unit test to verify the functionality of the `Marks` module. Complete this test using the provided `Marks` module code:

```cpp
#include <iostream>
#include "Marks.h"

using namespace std;
using namespace seneca;

int main() {
    // Step 1: Create a Marks object
    Marks studentMarks;

    // Step 2: Add some marks to the collection
    studentMarks.addMark("Math", 85)
                .addMark("Science", 92)
                .addMark("History", 78);

    // Step 3: Display the marks
    cout << "Displaying Student Marks:" << endl;
    cout << studentMarks << endl;

    // Step 4: Verify index operator
    cout << "Accessing Marks using the Index Operator:" << endl;
    cout << "Mark 1: " << studentMarks[0].title() << ", " << studentMarks[0].mark() << endl;
    cout << "Mark 2: " << studentMarks[1].title() << ", " << studentMarks[1].mark() << endl;

    // Step 5: Copy the Marks object and display
    Marks copiedMarks = studentMarks;
    cout << "Displaying Copied Marks:" << endl;
    cout << copiedMarks << endl;

    return 0;
}
```
### Expected Output

```text
Displaying Student Marks:
Math                                                              85
Science                                                           92
History                                                           78

Accessing Marks using the Index Operator:
Mark 1: Math, 85
Mark 2: Science, 92

Displaying Copied Marks:
Math                                                              85
Science                                                           92
History                                                           78
```

## Transcript Class

The **Transcript** class extends the **Marks** class by introducing two additional attributes:

1. **Student Name**: Dynamically allocated memory holds the student's name.
2. **Student Number**: An unsigned integer representing the student's number.

---

### Requirements (your task)


> **Note:**  
You are encouraged to reuse the `Utils` module's methods for managing dynamic memory allocation (DMA) in your implementation.


#### 1. Constructor
- Create a two-argument constructor to initialize a `Transcript` object.
- The constructor should:
  - Dynamically allocate memory for the student's name.
  - Set the student number.

---

#### 2. Rule of Three
- Implement the **copy constructor**, **copy assignment operator**, and **destructor** for the `Transcript` class.


**Instructions:**

- **Copy Constructor:**
  - When creating a copy of a `Transcript` object:
    - Start by invoking the copy constructor of the `Marks` base class explicitly. This ensures that all attributes managed by `Marks` are properly copied into the new `Transcript` object.
    - Copy the `Transcript`-specific attributes (e.g., dynamically allocate memory for the student name and copy its content, and directly copy the student number).

- **Copy Assignment Operator:**
  - For assignment:
    - First, check for self-assignment to avoid unnecessary work and potential errors.
    - Call the copy assignment operator of the `Marks` base class explicitly to copy its attributes.
    - Properly manage the `Transcript`-specific resources:
      - Free any existing memory allocated for the student name to prevent memory leaks.
      - Allocate new memory for the student name and copy the content from the source object.
      - Copy the student number directly.

- **Destructor:**
  - For destruction:
    - Free any dynamically allocated memory in the `Transcript` class (e.g., the student name).
    - The base class (`Marks`) destructor will automatically be invoked after the `Transcript` destructor finishes, cleaning up any resources managed by the base class.

---

#### 3. Override the Virtual `display` Function
- Override the `display` function of the `Marks` class.
- The `Transcript`'s `display` function should:
  1. Print the student's name and student number in the following format:

     ```
     [Student Name] ([Student Number])
     --------------------------------------------------------------------------
     ```

  2. Invoke the `display` function of the `Marks` base class to display all the marks.

---

### Notes for Students
- **Focus on Proper Resource Management**: Ensure no memory leaks occur, and all dynamically allocated resources are safely freed in the destructor.
- **Understand Inheritance and Overriding**: Carefully review how `Marks` works and how to extend its functionality in `Transcript`.


## The tester program.
[main.cpp](lab/main.cpp)

## Expected output
[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)
Files to submit:  
```Text
Utils.h
Utils.cpp
Marks.h
Marks.cpp
Transcript.h
Transcript.cpp
main.cpp
```
### Data Entry

No data entry needed

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

No DIY this time!

Work on your project code instead.