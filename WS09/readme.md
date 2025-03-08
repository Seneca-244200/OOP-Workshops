
# Workshop #9: Derived Classes and Resources
**Version 1.0**

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

## Submission Policy and Instructions

This workshop is divided into two sections: a coding part with reflection and a DIY section for practice.

The DIY homework is presented at the end; do it on your own for practice (DIY is neither submitted nor marked).

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop’s total mark.
> Please note that Part 1 **is not** to be started in your lab session of the week. You should start it on your own before the day of your lab and then join the lab session to possibly seek assistance to complete your lab. These workshops must be submitted in the lab to receive 100% of the mark.

- Reflection: A non-coding part, to be submitted a few days later (due date decided by your professor). The reflection doesn’t have marks associated with it but can incur a penalty of up to 40% of the whole workshop’s mark if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

- Part 2 (**DIY**): A Do It Yourself type of practice that is much more open-ended. This part does not need to be submitted to your professor and does not have any marks tied to it. However, you can always test your program using the automated submitter program or ask your professor for help or feedback.


## Due Dates
### Coding
Part 1 coding is due by the end of your lab session and is to be submitted from one of the desktop computers in the lab for 100% of the mark. You will receive 60% of the mark if you submit your code after the lab by midnight. No submissions are accepted after that.

> You have to submit your code using an SSH terminal client logged into the Matrix cluster from one of the desktop computers in the lab (we recommend using [PuTTY](https://www.putty.org/)). Note that you must only have one connection to the Matrix client; before logging into Matrix to submit your lab, make sure you are logged off all other terminal client sessions.

## Late Penalties
You are allowed to submit your workshop by midnight on the same day of your lab session with a 40% penalty. No submission is accepted after that.


## Citation
Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone by providing part of your code. Let them know of these regulations and in your 'reflect.txt' for reflection submission, write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the code recipient does not honour these regulations.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the c++11 standard
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

### Submission Process


Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the submission command from your matrix account


#### Submitting Utils Module

If you have any custom code in your Utils module from previous workshops, include it in the Utils module for this submission. For this workshop, submitting the Utils module is mandatory and it is included with normal submission.



> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take around 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

### Reflection Submission.
Transfer your `reflect.txt` to the matrix cluster and issue the submit command.

# DIY  

No DIY this time!

Work on your project code instead.