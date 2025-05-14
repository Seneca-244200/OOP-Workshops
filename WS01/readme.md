# Workshop #1: Types, References, Function Overloading
* Version 0.9

In this workshop, you will organize already implemented code into a module and then create a new module by implementing several overloaded functions.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the ability to:

- Use and understand **references** as function parameters and return values  
- Apply **function overloading** to provide multiple behaviors under the same function name  
- Manipulate **arrays of pointers** to create flexible views of existing data  
- Implement **modular programming** by organizing code into reusable source and header files  
- Use **basic input/output operations** to read from files and the console  
- Implement **custom string manipulation** functions as an alternative to `<cstring>`  
- Use **function testing strategies** to validate individual components using a test harness


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

# Part 1 – Workshop 

In Workshop 1, you will help build the components of a simple **phonebook search program**. To accomplish this, you will:

* Assemble a module called `cstr`, using pre-implemented functions.
* Create another module called `io` to perform the phonebook search functionality.

## C-style String Functions Module (`cstr`)

The `cstr` module will be used **in place of** the standard `<cstring>` header. The required functions for this module are already implemented and provided to you.

You must create two files for this module:

* `cstr.h` – the header file containing function prototypes
* `cstr.cpp` – the source file containing function definitions

Make sure to:

* Include the `cstr.h` file in `cstr.cpp`.
* Add **compilation safeguards** to the header file.
* Enclose **all code** in the `seneca` namespace.

---

### 🔒 Compilation Safeguards

Compilation safeguards are preprocessor directives that prevent a header file from being compiled more than once during the build process.

Here is the typical structure for a module with safeguards and a namespace:

```cpp
// moduleName.h
#ifndef THENAMESPACE_MODULENAME_H
#define THENAMESPACE_MODULENAME_H

namespace theNamespace {

// Declarations and prototypes go here

}
#endif // !THENAMESPACE_MODULENAME_H
```

```cpp
// moduleName.cpp
#include "moduleName.h"

namespace theNamespace {

// Definitions and functions go here

}
```

In the `cstr` module:

* Use `SENECA_CSTR_H` as your header guard identifier.

In all workshops
* Use the `seneca` namespace for all code.

---

### 📦 Adding the C-style String Functions

Below is a set of utility functions that mimic those found in the standard `<cstring>` library. These are already implemented and ready to be used in your workshop.

> 💡 **Note:** Not all of these functions are used in this workshop. Some are included for use in later workshops and projects.

---

#### ✅ Your Task

Organize the following functions into the `cstr` module by:

* Copying the **function definitions** into `cstr.cpp`.
* Declaring the **function prototypes** in `cstr.h`.

Make sure they are all wrapped inside the `seneca` namespace.


```cpp

   // Concatenates the src string to the end of des string.
  // Assumes des has enough space to hold the result.
   char* strcat(char* des, const char* src) {
      size_t len = strlen(des);
      size_t i = 0;
      while (des && src && src[i]) {
         des[i + len] = src[i];
         i++;
      }
      des[i + len] = char(0); // Null-terminate the result
      return des;
   }

   // Converts an uppercase ASCII character to lowercase.
   // If ch is not uppercase, returns it unchanged.
   char tolower(char ch) {
      if (ch >= 'A' && ch <= 'Z') {
         ch += ('a' - 'A');
      }
      return ch;
   }

   // Converts all characters in src to lowercase and copies them into des.
   // Assumes des has enough space. Null-terminated.
   char* tolower(char* des, const char* src) {
      size_t i = 0;
      for (; des && src && src[i]; i++) {
         des[i] = tolower(src[i]);
      }
      des[i] = char(0);
      return des;
   }

   // Converts all characters in the input string `str` to lowercase in place.
   // Modifies the original string and returns the same pointer.
   char* tolower(char* str) {
      for (size_t i = 0; str && str[i]; i++) {
         str[i] = tolower(str[i]); // Uses the char version of tolower()
      }
      return str;
   }


   // Compares two C-style strings lexicographically.
   // Returns 0 if equal, <0 if s1 < s2, >0 if s1 > s2.
   int strcmp(const char* s1, const char* s2) {
      size_t i{};
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }

   // Compares up to 'len' characters of two strings lexicographically.
   // Returns 0 if equal up to len, or first differing character diff.
   int strcmp(const char* s1, const char* s2, size_t len) {
      size_t i{};
      while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
         i++;
      }
      return s1[i] - s2[i];
   }

   // Copies src into des including null terminator.
   // Returns des. Assumes des has enough space.
   char* strcpy(char* des, const char* src) {
      size_t i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }

   // Copies up to 'len' characters from src to des.
   // Always null-terminates des. Safer than std::strncpy.
   // Returns des.
   char* strcpy(char* des, const char* src, size_t len) {
      size_t i;
      for (i = 0; i < len && src[i]; i++) {
         des[i] = src[i];
      }
      des[i] = 0; // Ensures null-termination
      return des;
   }

   // Copies up to 'len' characters from src to des (like std::strncpy).
   // May not null-terminate if src is longer than len.
   // Returns des.
   char* strncpy(char* des, const char* src, size_t len) {
      size_t i = 0;
      while (i < len - 1 && src[i]) {
         des[i] = src[i];
         i++;
      }
      des[i] = src[i]; // Final char copied or null terminator
      return des;
   }

   // Returns the length of the C-style string str (excluding null).
   size_t strlen(const char* str) {
      size_t len{};
      for (len = 0;str &&  str[len]; len++);
      return len;
   }

   // Finds the first occurrence of toFind in str.
   // Returns pointer to the first match or nullptr if not found.
   const char* strstr(const char* str, const char* toFind) {
      const char* faddress = nullptr;
      size_t
         i,
         flen = strlen(toFind),
         slen = strlen(str);
      for (i = 0; flen <= slen && i <= slen - flen && strcmp(&str[i], toFind, flen); i++);
      if (flen <= slen && i <= slen - flen) {
         faddress = &str[i];
      }
      return faddress;
   }

   // Returns true if ch is an alphabetic character (A-Z or a-z).
   bool isalpha(char ch) {
      return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
   }

   // Returns true if ch is a whitespace character.
   bool isspace(char ch) {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

```

## The `io` Module

Just like the `cstr` module, create two files for this module:

* `io.h` – header file
* `io.cpp` – source file

Apply the same setup:

* Add compilation safeguards in `io.h`
* Use the `seneca` namespace in both files

---

### PhoneRec Structure

In `io.h`, define a structure named `PhoneRec` with the following fields:

* A C-style string for the first name (up to 15 characters)
* A C-style string for the last name (up to 25 characters)
* A `long long` integer to store the phone number

---

### Functions to Implement

#### `read`

Reads a name from console input.

* Receives a C-style string as an argument to store the name.
* Prompts the user with: `"name>\n "`
* Reads the input into the given C-string using `cin`.
* Assumes the name entered has no spaces.
* Returns `void`.

---

#### `print` (phone number)

Prints a `long long` phone number in the format:

```text
(999) 999-9999
```

* Assumes leading zeros are preserved within each section.
* Returns `void`.

---

#### `print` (PhoneRec)

An **overloaded** version of `print` that receives:

* A constant reference to a `PhoneRec`
* A reference to a `size_t` row number
* An optional name filter (`const char*`, defaulting to `nullptr`)

This function:

* Compares the optional name filter to the name and the lastname using the `strstr` function
* If the filter is null or a match is found, prints the `PhoneRec` as:

  ```
  RowNumber: Name LastName (999) 999-9999
  ```
* Increments the `row` counter after printing
* Uses the first `print` function to format the phone number

---

#### `read` (overload)

Reads a `PhoneRec` from a tab-separated record in a file.

* Returns `true` if all three fields are read successfully; otherwise, returns `false`.
* Receives a reference to a `PhoneRec` to store the extracted data.
* Receives a `FILE*` pointer, assumed to be already open.
* Uses the following `fscanf` format string to read the data:

  ```
  "%s %s %lld"
  ```

---

#### `print` (overload)

Prints a series of `PhoneRec` records.

* Receives an array of `PhoneRec*` (pointers to `PhoneRec`)
* Receives the size of the array
* Receives an optional `const char*` filter (defaulted to `nullptr`)

This function should:

* Create a local `size_t` variable for the row number and initialize it to `1`
* Loop through the array
* For each record, call the previous `print` overload, passing the dereferenced pointer, the row number, and the filter

---

#### `setPointers`

Sets up an array of pointers to point to elements of a `PhoneRec` array.

* Receives an array of `PhoneRec*` (pointers)
* Receives an array of `PhoneRec` (records)
* Receives the size of the arrays (assumed equal)

This function assigns each pointer in the first array to the address of the corresponding element in the second array.

> This creates a “view” into the original array, allowing the order of access to be changed by rearranging the pointers rather than modifying the original data.

* Returns `void`

---

#### `sort`

Sorts an array of `PhoneRec` pointers either by first name or last name.

* Receives an array of `PhoneRec*` (pointers)
* Receives the size of the array (`size_t`)
* Receives a `bool` flag indicating the sort criteria:

  * If `true`, sort in ascending order by last name
  * If `false`, sort in ascending order by first name

This function rearranges the pointers in the array without modifying the original `PhoneRec` data.

* Returns `void`


## Testing Your Program

Use the `ioTester.cpp` program to test each function individually.

* Implement the functions in the order they are tested in the tester file.
* Uncomment each test function one at a time to verify your implementation before moving to the next.

Once all functions are completed and tested, you can use `main.cpp` to run the full program and prepare for submission.


## The tester program.
[main.cpp](./lab/main.cpp)

## Expected output

[correct_output.txt](./lab/correct_output.txt)

## LAB Submission (part 1)

### Files to submit:  
```Text
cstr.h
cstr.cpp
io.h
io.cpp
main.cpp
phones.tsv

```

### Data Entry
```text
1
2
4
3
5
Sim
5
Bar
0
```

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


# DIY  (No DIY available for this workshop)

