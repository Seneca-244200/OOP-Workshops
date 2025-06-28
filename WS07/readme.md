# Workshop #7: Derived Classes & Custom I/O Operators

---
> ⚠️ **Before You Begin**
> You **must read and understand** the [Workshop Regulations and Policies](../README.md) before starting this or any other workshop. This document outlines important rules about academic integrity, submission procedures, and expectations.
> These policies apply to **all workshops** in OOP244. If you have already read it once, please ensure you continue to follow its guidelines throughout the course.
---


In this workshop, you will work with classes organized in a hierarchical structure, focusing on creating derived classes and implementing custom input/output operators.

## Learning Outcomes

Upon successful completion of this workshop, you will be able to:

- Inherit a derived class from a base class.
- Override a base class member function with a derived class member function.
- Access a shadowed (overridden) member function defined in a base class.
- Implement and utilize custom input/output operators with derived classes.
- Explain to your instructor the key concepts and techniques learned in this workshop.


# Part 1 - LAB (100%) 

## Utils Module
A Module called `Utils` is provided and is almost identical to the `Utils` module in the project. Use this module for dynamic memory allocations and C-string-related functions. Feel free to add any additional functions you find necessary for commonly used tasks.

## Employee class

The base class, `Employee`, encapsulates common attributes of an employee. This class is fully implemented and **must not be modified**; it is intended to be used as-is. Study the class carefully, then use the [`employeeTester.cpp`](lab/employeeTester.cpp) unit test and walkthrough to understand how the `Employee` class is designed and functions.

## Professor class

Create a module called `Professor` (`Professor.h` and `Professor.cpp`). Derive a class from `Employee` named `Professor` that adds two attributes:

- Subject Name: A dynamically allocated C-string that stores the subject the professor teaches.
- Number of Sections: An integer that stores the number of sections the professor teaches.

### Constructors

#### No-Argument Constructor
By default, a `Professor` is constructed in a safe, empty state, with pointers set to nullptr and numerical values set to zero.

#### 5-Argument Constructor
A `Professor` can also be constructed with the following arguments:

- name: Passed to the Employee constructor.
- subject name: Dynamically stored in the subject attribute.
- number of sections: Stored in the Number of Sections attribute.
- employee number: Passed to the Employee constructor.
- salary: Passed to the Employee constructor.

### Methods
The Professor class adds one private method and overrides all methods of Employee, except salary.

#### double devPay() const;  
This method returns a `double` and does not modify the `Professor` object. It calculates an additional pay based on the `number of sections` the `professor` teaches. The calculation multiplies 1% of the professor’s salary by the `number of sections`.

#### istream& read(istream& istr = cin);
Reads the Professor data in the following format from an `istream`: 

`Name,Employee Number,Salary,Subject Name,Number of Sections<NEWLINE>`

- Invokes the `Employee` class’s read function to read the first three values.
- Dynamically reads the `subject name` (up to 1024 characters).
- Reads `Number of Sections`.
- Ignores the newline character.

#### ostream& write(ostream& ostr = cout) const;
Outputs Professor data with the following details:

- Begins with one space.
- Calls the Employee class’s write function to output the Employee portion.
- Prints the first 20 characters of the `subject name`, `left-justified` and `padded with spaces` if shorter than 20 characters.
- Adds `" | "`.
- Writes the `Number of Sections`, `right-justified` within `5 spaces` and `padded with spaces` if necessary.
- Adds `" | "`.
- Writes the `devPay` value, `right-justified`, formatted to occupy `8 space`s with `2 digits after the decimal` point, `padded with spaces`.
- Adds `" |"` and returns the `ostream` object.

#### ostream& title(ostream& ostr = cout) const;
Outputs the title header for Professor data:

- Calls the Employee class’s title function, followed by `" Teaching Subject | Sec # | $Dev Pay |"`.
- Returns the ostream object.

### Input and Output Helper Operator Overloads
Following the same logic used in the `Employee` class implementation, overload the insertion (`<<`) and extraction (`>>`) operators to handle output and input with `ostream` and `istream` for the Professor class.

## The tester program.
[main.cpp](lab/main.cpp)

## Expected output
[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)
Files to submit:  
```Text
Utils.cpp
Utils.h
Employee.cpp
Employee.h
Professor.h
Professor.cpp
main.cpp
```
### Data Entry

Follow the instructions of the unit test.

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
