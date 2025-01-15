# Workshop #2: References, Overloading, Dynamic Memory Allocation(DMA) and Compound Types
* V1.0

In this workshop will create several different functions to practice the above topics

## Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the abilities to:

- Overload functions
- Dynamically allocate arrays
- Dynamically allocate compound types
- Pass variables by reference.

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
This lab is done in three steps; Overloading, DMA and Compound Types.

The main program is testing each step using function calls. You can comment these functions out to test each part separately.

## Step 1 (Overloading, references)
Work in Module `input`:

The function `int getInt();` is fully implemented and working. It performs a foolproof integer entry from the console and returns the read integer.

The features used in the function will be covered a few weeks from now, so you don’t need to fully understand it. Just use it as is, knowing that it works. However, it is not a bad idea to take a look at the code and its comments to get an idea of the features.

Your task:

Reuse the above `getInt()` function to overload it into two new functions:

1- A `getInt` function that receives two integers for minimum and maximum acceptable values to be enforced during data entry.

>Refer to the function summary in the input header file for a detailed description of the function.

Use the same logic as the original `getInt` function: get an integer in a loop, and if the value is not within limits, print an error message and keep repeating until the value is acceptable, then return it.

If the function is called with `3` and `5` as lower and upper limits, the execution will be as follows:
```text
> abc
Bad integer entry, please try again:  <<<this message is from the original getInt()
> 2 
Invalid value, [3<ENTRY<5]            <<< this is your error message
> 4
```

2- A `getInt` function that receives a reference to an integer, and two integers for upper and lower acceptable limits, returning a boolean for the validity of data entry.

> Refer to the function summary in the input header file for a detailed description of the function.

This function, unlike the other getInt, does not loop for bad data entry and simply exits, returning false. If the data entry is valid, then the reference will be set to the entered integer and a true value is returned.

If the function is called with `3` and `5` as lower and upper limits, the execution will be as follows:

```text
> abc
Bad integer entry, please try again:
> 2
```
the function ends returning false

```text
> abc
Bad integer entry, please try again:
> 4
```
the function ends returning true and the reference will be set to `4.`


`test_getInts();` in `main.cpp` is testing step 1.

## Step 2 (DMA of arrays)

Work in Module `dma`.

Create a function called `reverse` that receives and returns nothing!

This function receives an unknown number of double numbers from the console and prints them in `reverse` order.

Ask the user for the number of double numbers, then dynamically allocate an array of doubles to the size the user suggested.

In a loop, prompt the user with the sequence number of the array elements and read them one by one.

When done, do a reverse loop and print the numbers in reverse order on separate lines.

Deallocate the allocated array.

execution sample.
```text
Enter the number of double values:
> 3
1> 10.1
2> 20.2
3> 30.3
30.3
20.2
10.1
```

A call to `reverse` in `main.cpp` tests this.

## Step 3 (Working with compound types)

See the `Contact` structure in `dma.h`

Implement the following four functions:

1- `getContact`

Receives nothing and returns an address of a `Contact` structure.

Creates a Contact compound type dynamically and gets its content from the console, then returns its address.

Execution sample
```text
Name: John
Last name: Doe
Phone number: 447123456789
```
and then the address of the `Contact` structure is returned. No validation is done for entry.

2- `display`

Receives a constant `Contact` reference and prints the contents as follows:
```text
Name Lastname, +Phonenumber
```
and goes to newline

3- `deallocate`

Receives a `Contact` pointer and returns nothing. 
This function deallocates the single `Contact` structure pointed by the address. 

4- `setEmpty`

Receives a `Contact` reference and returns nothing
Empties the Contact reference member variables to set the names to empty C-strings and the phone number to zero.

`test_Contact` function tests this step in `main.cpp`.

## The tester program.
[main.cpp](./lab/main.cpp)

## Expected output

[correct_output.txt](./lab/correct_output.txt)

## LAB Submission (part 1)

### Files to submit:  
```Text
input.cpp
input.h
dma.h
dma.cpp
main.cpp
```

### Data Entry

follow the instructions in the teste program.

### Submission Process


Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the submission command from your matrix account


#### Submitting Utils Module

See [Custom Code Submission](#custom-code-submission) section for more detail


> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take around 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

### Reflection Submission.
Transfer your `reflect.txt` to the matrix cluster and issue the submit command.



# DIY  (Practice only)
Write a **postal-code-based population report** program that reads a series of records of postal codes and their population in Canada from a comma-separated-values file and prints a report of the postal code and their population sorted in an ascending order based on the population of the account. 

The data file is called `PCpopulations.csv` and is formatted as follows:
  
```Text
Three First Characters of postal code
comma
population
newline
```

Example:

```Text
A0A,46587
A0B,19792
A0C,12587
A0E,22294
A0G,35266
A0H,17804
A0J,7880
A0K,26058
A0L,7643
A0M,6200
A0N,13815
A0P,13721
A0R,2543
A1A,30382
A1B,19867
```

## DIY Execution example (with the incomplete sample list)
```text
Postal Code: Population
-------------------------
1- A0R:  2543
2- A0M:  6200
3- A0L:  7643
4- A0J:  7880
5- A0C:  12587
6- A0P:  13721
7- A0N:  13815
8- A0H:  17804
9- A0B:  19792
10- A1B:  19867
11- A0E:  22294
12- A0K:  26058
13- A1A:  30382
14- A0G:  35266
15- A0A:  46587
-------------------------
Population of Canada: 282439
```

Implement this program in 3 modules called `main`, `File` and `Population` that can accomplish the above task.  


Files to test the application:  
```Text
main.cpp 
File.cpp
File.h
Population.cpp
Population.h
```

## `File` Module

The `File` module is partially implemented. 

Create different overloads of read functions to read a postal code or population from the file. These functions can be used in the population module to read the records.

## `Population` Module

The `Population` module is not implemented.

Create a structure to hold the postal code and the population value for the `population records` in the data file and keep the definition in `Population.h`.  

Create a file scope pointer to this structure in the cpp file of the module for dynamic data loading.

There are three mandatory functions in the `Population` module. Apart from these three functions you are free to choose any method to implement this system, however, to practice you should use function overloading, reference and dynamic memory allocation since the number of records is to big to be kept in a local array. 

Mandatory functions in this module:

- `load`: Finds the number of records, allocates memory in the file scope pointer and then Loads the data from the file into the dynamically allocated `population records`, and returns `true` if data was successfully loaded, `false` otherwise. This function receives as a parameter the name of the file
    - If the file cannot be found, print the following error message: 
    ```Text
    Could not open data file: FILENAME<ENDL>
    ```

    - If the file doesn't have correct content (reading fails prematurely), print:
    ```Text
    Error: incorrect number of records read; the data is possibly corrupted!<ENDL>
    ```

- `display`: a function with no parameters that returns nothing and prints the report as shown in the correct output

- `deallocateMemory`: a function with no parameters that return nothing and deallocate **all** dynamic memory used by the program.




## The tester program.
[main.cpp](DIY/main.cpp)

## Expected output

[correct_output.txt](DIY/correct_output.txt)


## DIY Testing

### Files needed to test with the submit command:  
```Text
File.cpp
File.h
Population.cpp
Population.h
main.cpp
```


### Data Entry

No data entry needed

### Testing Process

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the submit command from your matrix account to test the execution of your DIY section
