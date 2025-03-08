# Workshop #10: Function Templates
**Version 1.0**

In this workshop, you will implement a module called `dynaCopy` containing three function templates. These templates are designed for dynamically copying arrays of objects and printing their contents.

You will use a fully implemented class called `Name` and the `Utils` module provided to assist in completing this workshop.

---

## Learning Outcomes

Upon successful completion of this workshop, you will be able to:

- Write and use function templates to generalize operations on different data types.
- Dynamically manage arrays of objects using templates.
- Understand and implement a header-only module for templates.
- Test and validate template functionality using provided and self-written code.
- Describe what you have learned in completing this workshop.

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
## dynaCopy Module Requirements
Implement the following three function templates in the `dynaCopy` module (header file only).

### 1. **Two-Argument `dynaCopy`**
**Description:**
- This function template dynamically allocates memory for a new array and copies the elements from a given source array into it.

**Parameters:**
1. A constant pointer to the source array. 
   - This ensures the source array is not modified by the function.
   - The type of elements in the source array is generic and determined by the template parameter.
2. An integer representing the size of the source array.
   - This indicates how many elements are in the source array.

**Return Value:**
- A pointer to a dynamically allocated array.
  - The new array contains all the elements from the source array.

---

### 2. **Three-Argument `dynaCopy`**
**Description:**
- This function template dynamically reallocates memory for an existing destination array and copies the elements from a given source array into the destination.

**Parameters:**
1. A reference to a pointer representing the destination array.
   - Since the destination pointer is passed by reference, the function can directly modify the memory it points to.
   - If the destination pointer already points to allocated memory, that memory is first deallocated.
   - The type of elements in the destination array is generic and determined by the template parameter.
2. A constant pointer to the source array.
   - This ensures the source array is not modified.
   - The type of elements in the source array is generic and determined by the template parameter.
3. An integer representing the size of the source array.
   - This indicates how many elements need to be copied into the destination array.

**Return Value:**
- The same pointer passed as the destination, now pointing to newly allocated memory containing the copied elements.


> **Hint:** The two `dynaCopy` function templates are conceptually similar to the two `alocpy` functions in the `Utils` module. However, instead of working exclusively with null-terminated character arrays, the `dynaCopy` templates are designed to handle arrays of any type, given their size.


---

### 3. **`prnArray`**
**Description:**
- This function template prints the elements of an array to the standard output in a single line.

**Parameters:**
1. A constant pointer to the array to be printed.
   - This ensures the array is not modified during the operation.
   - The type of elements in the array is generic and determined by the template parameter.
2. An integer representing the size of the array.
   - This specifies how many elements need to be printed.

**Output Behavior:**
- The elements are printed in order, separated by commas.
- A newline character is added at the end of the output for readability.

**Return Value:**
- This function does not return a value. It simply performs the printing operation.

---

## Provided Code

You are provided with:

1. The `Name` class (implementation details included in the provided code).
2. The `Utils` module for dynamic memory allocation support in the 'Name' class. (you do not need to use it)

Review and understand these files before starting the workshop.

---

### Additional Notes

- **Memory Management:** Be mindful of dynamic memory allocation. Use proper techniques to avoid memory leaks. (deleting pointers before reallcoting memory)
- **Utils Module:** The `Utils` module is used by the `Name` module for memroy management.
- **Generalization:** The function templates should work seamlessly with primitive data types (e.g., `int`) and user-defined types (e.g., `Name`).

---

## The tester program.
[main.cpp](lab/main.cpp)

## Expected output
[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)
Files to submit:  
```Text
Utils.h
Utils.cpp
Name.h
Name.cpp
dynaCopy.h
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