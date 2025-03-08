# Workshop #7: Derived Classes & Custom I/O Operators


In this workshop, you will work with classes organized in a hierarchical structure, focusing on creating derived classes and implementing custom input/output operators.

## Learning Outcomes

Upon successful completion of this workshop, you will be able to:

- Inherit a derived class from a base class.
- Override a base class member function with a derived class member function.
- Access a shadowed (overridden) member function defined in a base class.
- Implement and utilize custom input/output operators with derived classes.
- Explain to your instructor the key concepts and techniques learned in this workshop.

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

Follow the instrutions of the unit test.

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
