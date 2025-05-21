# OOP244 Workshops

## Submission Policy and Instructions

The workshops are divided into two sections: a coding part and a reflection

A DIY section may also be presented at the end; do it on your own for practice (DIY is neither submitted nor marked).

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

* Commit and push your code to your GitHub repository.
* SSH into Matrix.
* Pull your work to your Matrix account from GitHub.
* Follow the Lab Submission instructions to submit your work to your professor.

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


