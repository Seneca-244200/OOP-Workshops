# Workshop #1: Modules   
- Version 1.0
- Version 1.1 (DIY) Added [a sort algorithm](#sort-algorithm) to sort the marks with

In the process of doing your first workshop, in part 1 you are to subdivide a program into modules, compile each module separately and construct an executable from the results of each compilation. In Part 2 (**DIY**) you are to write a modular program based on your knowledge of the IPC144 subject. 

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:
- Organize source code into modules, using header and implementation files;
- Compile and link modular programs;
- distinguish the contents of a header and an implementation file;
- Describe to your instructor what you have learned in completing this workshop.



## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates
Part 1 (lab) is due 2 days after your lab day and Part 2 (DIY) is due 6 days after your lab day.
 
The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

> Note that the submission usually opens by the end of Monday.

```bash
~profname.proflastname/submit 2??/wX/pY_sss -due<ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

## Late penalties
You are allowed to submit you work up to 2 days after due date with 30% penalty for each day. After that the submission will be closed and the mark will be zero.

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

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

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

> Note: All the code written in workshops and the project must be implemented in the **seneca** namespace, unless instructed otherwise.

# Part 1  (Lab - 50%)
## Original source code "The SeneGraph Program" (w1p1.cpp)

**SeneGraph** is a program that receives several statistical sample values and compares those values using a horizontal Bar Chart.

Here is a sample execution of the program 

[Part 1 Execution example](lab/correct_output.txt)



## Step 1: *Test the Program*

### On Visual Studio
- Open Visual Studio 2022 (VS) and create an Empty C++ Windows Console Project:<br />
![Empty Project](images/emptyproj.png)
- In VS, (if not open already) open the Solution Explorer (click on View/Solution Explorer) and then add **w1p1.cpp** file to your project:<br />
-Right-click on **“Source Files”**<br />
-Select **“Add/Existing Item”**<br />
-Select **w1p1.cpp** from the file list<br />
-Click on **“Ok”**
- Now you can run the program by selecting **“Debug/Start Without Debugging”** or pressing the **“Ctr-F5”** button. 
### On Linux, in your Matrix account
- Connect to Seneca with [Global Protect VPN](https://students.senecapolytechnic.ca/spaces/186/it-services/wiki/view/1024/vpn)
- Upload **w1p1.cpp** to your matrix account (Ideally to a designated directory for your workshop solutions).  Then, enter the following command to compile the source file and create an executable called ws:
```bash
g++ w1p1.cpp -Wall -std=c++11 -g -o ws<ENTER>


-Wall: Display all warnings
-std=c++11: compile using C++11 standards
-g: generates debugging information 
-o ws: name the executable ws
```
- Type the following to run and test the execution:
```bash
ws<ENTER>
```

## Step 2: Create the Modules
### On Windows, using Visual Studio (VS)
In the solution explorer, add three new modules to your project:
- **io**; A module for input/output related functions 
- **graph**; A module to hold the functions related to "graph" data entry, processing and creation.
- **main**; a module containing `main()` and `samplesFirst()` functions

The **main** module has an implementation (.cpp) file but no header file. The **io** and **graph** modules have both implementation (.cpp) and header (.h) files:

#### Header files
Add **io.h** and  **graph.h** to the “Header Files” directory (right-click on “Header Files” and select “Add/New Item” and add a header file)<br />

Make sure you add the compilation safeguards to the header files.

Also remember that all the C++ code in the modules are to be placed in a namespace called `seneca`, except the main module that uses the `seneca` namespace.

##### Compilation Safeguards
**Compilation safeguards** refer to a technique to guard against multiple inclusion of header files. It does so by applying macros that check against a defined name:
```c++
#ifndef SENECA_HEADERFILENAME_H // replace with relevant names
#define SENECA_HEADERFILENAME_H
namespace seneca{

// Your header file content goes here

}
#endif
```
If the name isn’t yet defined, the **#ifndef** will allow the code to proceed onward to define that same name. Following that the header is then included. If the name is already defined, meaning the file has been included prior (otherwise the name wouldn’t have been defined), the check fails, the code proceeds no further and the header is not included again.<br />
Compilation safeguards prevent multiple inclusions of a header in a module. They do not protect against including the header again in a different module (remember that each module is compiled independently from other modules).<br />
Additionally, here is an instructional video showing how the compiler works and why you need these safeguards in all of your header files. Do note that this video describes the intent and concept behind safeguards, the naming scheme isn’t the standard for our class. Follow the standard for safeguards as described in your class.<br />
[Compilation Safegards](https://www.youtube.com/watch?v=EGak2R7QdHo): https://www.youtube.com/watch?v=EGak2R7QdHo

#### CPP Source Files
Add **io.cpp**, **graph.cpp** and **main.cpp** to the “Source Files” directory (right-click on “Source Files” and select “Add/New Item” and add a C++ file)<br />

## Step 3: the main module

Your main module must contain only the following two functions:

```c++
int main(){
...
}
void samplesFirst(){
...
}
```
## Step 4: Organize the code in modules

Separate the rest of the functions in **w1p1.cpp** and copy them into the remaining modules as described below. Copy the body of the functions into the cpp files and the prototypes into the header files. 

> `io` module should hold the io functions: printInt, intDigits(int value), getInt, goBack, menu, labelLine and line. <br />
`graph` module should hold graph related functions: getSamples, findMax, printBar and printGraph.

### Guideline for creating modules
#### #includes
Avoid unnecessary random includes and only include a header file in a cpp file in which the header file functions are called or the header file definitions are used. <br />
 Do not include a header file inside another header file unless it is absolutely necessary (i.e the header file uses values defined in another headerfile).

##### Constant value declarations 
The Constant value declarations are to be added to the cpp file they are used in; unless the values are used in the header file, in that case, the constant values should be moved to the header file instead.

##### Namespace
All your code (in header files and CPP files) must be surrounded by the `seneca` namespace except in the module holding the **main** function.<br />


## Expected output

[correct_output.txt](./lab/correct_output.txt)

## LAB Submission (part 1)

### Files to submit:  
```Text
main.cpp  <- this file will be replaced with professor's tester at submission
io.h
io.cpp
graph.h
graph.cpp

```

### Data Entry

```text
3
1
3
2
20
50
100
3
0
```

### Submission Process


Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.


> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.




# DIY (50%)
# The Students' mark destribution program

The "Student's mark distribution program" generates a report based on student mark records saved in a file in a comma-separated format. 

A student record holds the student's name, surname and mark. These data are held in the following structure in the `StMark.h` header file:

```c++
   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct StMark {
      char name[21];
      char surname[31];
      int mark;
   };
```

The values of the StMark structure are kept in comma separated format as follows in separate lines:

```csv
Duncan,Anderson,70
```

Here is a [sample data file](DIY/group1.csv).

## The `file` module

All functions needed to read all these records and keep them in an array of `StMark` structures are provided in a module called `file`. 

A unit test for the file module is provided:

[file_tester](DIY/file_tester.cpp)

Study the file module and understand how it works.

## DIY implementation
To start the DIY section, copy the `io` and `graph` modules from part 1 to part 2 (DIY).


### `bool printReport(const char* filename);`
Complete the `StMark` module by adding `StMarks.cpp` to the project and implementing a function called `printReport`:

```c++
/// <summary>
/// Tries to open the students' mark data file. 
/// If successful it will print a report based on the 
/// date in the file.
/// </summary>
/// <param name="filename">, holds the data file name</param>
/// <returns>True if the date files is opened succesfully, 
/// otherwise returns false</returns>

bool printReport(const char* filename);
```

This function prints a graph showing the number of students in 10 groups:

- number of students with marks between 91 and 100
- number of students with marks between 81 and 90
- number of students with marks between 71 and 80
...
- number of students with marks between 0 and 10

And then prints the student records sorted in descending order based on the marks:

```text
+---Students' mark distribution-----------------------------------------------+
100 | **************************************** 61                             |
90  | **************************************************** 78                 |
80  | ***************************************** 62                            |
70  | **************************************** 61                             |
60  | ************************************* 56                                |
50  | ******************************************** 67                         |
40  | ************************************ 55                                 |
30  | ******************************************* 65                          |
20  | ******************************************** 66                         |
10  | ***************************************************************** 97    |
+-----------------------------------------------------------------------------+
1  : [100] Harris Garcia
2  : [100] Natalia Simon
3  : [100] Esme McKay
4  : [100] Jared Berger
5  : [99 ] Callan Copeland
6  : [99 ] Davion Rios
7  : [99 ] Haisley Russo
8  : [99 ] Riggs Munoz
9  : [99 ] Brantley OÆDonnell
10 : [99 ] Kameron McPherson
11 : [99 ] Osiris Ellison
...
...
660: [2  ] Madisyn Mathis
661: [1  ] Denver Arnold
662: [1  ] Kevin Lucas
663: [1  ] Augustine Short
664: [1  ] Mallory Page
665: [0  ] Wes Lyons
666: [0  ] Ishaan Sampson
667: [0  ] Kai Jacobs
668: [0  ] Melani Hodge
```
#### Sort Algorithm 
V1.1
> Use the following bubble sort algorithm for sorting:
> ```text
> Sort the Array "studentArray" with the array size kept in "size" as follows:
>   loop with i from 0  up to  i less than size - 1
>      loop with j from 0 up to j less than size - i - 1
>         if  mark of studentArray[j] is less than  mark of studentArray[j + 1]
>            swap them
>         end if
>      end loop
>   end loop
> end sort
> ```

Modify the printGraph function to add the number labels to the beginning of the bar charts.

Use the `printInt` function in `io` module to print the marks and the graph bar labels in widths of 3.

The `printReport` function is the only mandatory function using in the `main` module.

> Please note that you can (and probably should) add more functions to `StMark` module to make the DIY part work.


## The tester program.
[main.cpp](DIY/main.cpp)

## Expected output

[correct_output.txt](DIY/correct_output.txt) Based on the data in [group1.csv](DIY/group1.csv)

> note that when submitting, [`group3.csv`](DIY/group3.csv) will be used as data file.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 graphs in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

### Files to submit:  
```Text
main.cpp
file.h
file.cpp
io.h
io.cpp
graph.h
graph.cpp
StMark.h
StMark.cpp
```

### Data Entry

```text
group3.csv
x
```
### Submission Process


Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```bash
~profname.proflastname/submit 2??/wX/upY_sss  <ENTER>
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.



