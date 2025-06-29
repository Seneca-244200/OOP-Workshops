 # Workshop #6: Classes and resources, IO operators
* Version 0.9 (being proofread)


---
> ⚠️ **Before You Begin**
> You **must read and understand** the [Workshop Regulations and Policies](../README.md) before starting this or any other workshop. This document outlines important rules about academic integrity, submission procedures, and expectations.
> These policies apply to **all workshops** in OOP244. If you have already read it once, please ensure you continue to follow its guidelines throughout the course.
---



In this workshop, you will implement copy constructor and copy assignment to prevent memory leak and resize allocated memory.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create copy constructors
- define and create copy assignment 
- Resize dynamically allocated memory.
- Overload insertion operator so the class can be printed using ostream
- Overload extraction operator so the class can be read using istream


# Part 1 - LAB (100%) The Numbers module.
The **Numbers** class is partially implemented in the **Numbers.h** and **Numbers_prof.cpp** files.  
Your task for this lab is to complete the implementation of the **Numbers** class by modifying **Numbers.h** and implementing the **Numbers.cpp** file.

> Do not modify the **Numbers_prof.cpp** file.

The **Numbers** class reads several double values from a file (one number per line) and holds them dynamically in memory. Then the caller application has the option of adding numbers to the collection. This Module can provide information about the numbers and display them on the screen:<br />
- The Module can display the values in ascending order (sort).
- The Module can find the largest value
- The Module can find the smallest value
- The Module can calculate the average of the values in the collection

Also The **Numbers** class has the following capabilities: 
- A **Numbers** object can safely be copied or assigned to another **Numbers** module
- A **Numbers** object can be displayed or streamed into an ostream object.
- A **Numbers** object can be read from an istream object.

When the **Numbers** object goes out of the scope the values overwrite the old values in the file, ONLY IF the object is the original object and not a copy.
# The Numbers class
The Numbers class has four attributes:
- Double pointer, `m_numbers`; holds the address of the dynamic array of doubles holding the number collection
- Character pointer, `m_filename`;   holds the name of the file associated with the class (if it is the original object and not a copy)
- Boolean flag, `m_isOriginal`;  flags if this object is the original (and not a copy)
- size_t integer, `m_numCount`;  holds the number of values in the m_number dynamic array


## Constructors, Destructor and Copy Assignment (Rule of three)

The **Numbers** class can be instantiated in three different ways:

### One argument constructor (implemented)
Creates an original instance of the Numbers class by receiving the data file name as a constant Cstring
- Sets the object to a safe empty state (**setEmpty()**).
- Sets the m_isOriginal flag to true.
- Sets the filename of the class (**setFilename()**)
- Sets the number of the double values to be read from the file (sets m_numCount using **numberCount()**)

Now if the number of double values in the file is greater than zero it tries to read the values from the file using the **load()** function as follows:

- If m_numCount is greater than zero and load() is successful, the values will be sorted.
- If not successful, it will free the memory pointed by m_numbers and m_filename
- sets the object back to the safe empty state and sets the class NOT TO BE original anymore.

### Default constructor  (implemented)
```C++
  Account();
```
- Sets the object to a safe empty state (**setEmpty()**).
- Sets the m_isOriginal flag to false.

### Destructor (to be implemented)
- Save the values in the file by calling the save method (see the [Save() method](#save-to-be-implemented))
- delete the memory pointed by m_numbers and m_filename

### Copy Constructor (to be implemented)
- Set the object to a safe empty state
- Set the object NOT to be the original
#### and then you could
- Assign the current object to the **Numbers** object that is being copied or directly call the Copy Assignment Operator overload method.
#### but to practice and review DMA you better
- Allocate memory and point to it by `m_numbers` to the number of the values in the object that is being copied.
- Copy all the double values in the object that is being copied into the newly allocated memory.
- set the `m_numCount` attribute to the `m_numCount` of the object that is being copied.


### Copy Assignment Operator (to be implemented)
- If this is not a self-copy (`this != &other`)
   - Delete the current collection of the double values
   - Allocate memory and point to it by `m_numbers` to the number of the values in the object that is being copied.
   - Copy all the double values in the object that is being copied into the newly allocated memory.
   - set the `m_numCount` attribute to the `m_numCount` of the object that is being copied.
- Return the reference of the current object 

## Member Functions and Member operator+= overload 

### isEmpty() (implemented)
returns true if **m_numbers** is null

### setEmpty() (implemented)
sets m_numbers and m_filename to nullptr.
sets m_numCount to zero.

### setFilename() (implemented)
- Receives a constant Cstring for the data file name
- Frees the memory pointed by m_filename pointer
- Allocates memory to hold the data file name as a Cstring.
- Copies the data file name to the newly allocated memory.

### sort() (implemented)
Sorts the double values in ascending order

### max() (implemented)
Returns the largest double number in the list

### min() (implemented)
Returns the smallest double number in the list

### average()  (implemented)
Returns the average of the double numbers in the list.

### numberCount() (to be implemented)
This private function (that is incapable of modifying the current object), will return the number of lines in the data file (hence returning the number of double values in the file).
- Create an instance of **ifstream** to open the data file name.
- While the **ifstream** object has not failed keep reading single characters from the file
- Count the number of **newline** characters in an integer variable
- Return the number of counted **newlines** when all characters in the file are scanned.

### load() (to be implemented)
This function returns true if all the double values are read from the data file and stored in a dynamically allocated memory pointed by **m_numbers**, otherwise returns false.
- If the number of double values in the file is greater than zero (m_numCount > 0)
- Allocate `m_numCouut` doubles to hold the double values in an array pointed by m_numbers.
- Create an instance of ifstream using the data file name.
- While the ifstream object has not failed, keep reading double values from the file into the elements of m_numbers dynamic array (as you do with cin)<br />
   > Make sure to add to the index of the loop only if the istream object has not failed in its last reading
- If the number of doubles read, is not equal to the m_numCount member variable, set the object to the safe empty state after deallocating the memory. Set the function to return false at the end.
- If the number of doubles read, is equal to the m_numCount member variable, set the function to return true at the end.
- return the success status.
- 
### save() (to be implemented)
- If the current object is the original and it is not in a safe empty state
- Create an instance of ofstream to overwrite the data file
- Write all the elements of the m_numbers array using the ofstream object.
- Write a newline after each double value.

### Operator += (to be implemented)
Overload the += operator to add a single double value to the list of numbers in the array and then return the reference of the current object.

You need to increase the size of the allocated memory by one (add one double to the array), to be able to do this. 

Here is the sequence of the actions to be taken to resize memory:
- Create a temporary local double pointer and allocate memory with the increased size
- Copy all the current values to the newly allocated memory.
- Update the size of the data to the new size
- Now that all the values are copied to the new memory, delete the original allocated memory
- Set the original data pointer to point to newly allocated memory
- You are done!

[View the Slides](lab/memoryResizing.pdf)

Using the above guidelines; in our case, do the following only if the object is not in an empty state:
- Create a temp double pointer and allocate memory to the size: **m_numCount + 1**
- In a loop, copy all the double **m_numbers** elements to the double **temp** number elements (up to m_numCount)
- Add one to m_numCount (to update the number of double values)
- copy the value of the double argument to the last element of the double **temp** array (and therefore add the double value to the list)
- delete m_numbers to get rid of the original allocated memory
- Set **m_numbers** to **temp** pointer; by doing this m_numbers will point to the newly allocated memory.
- sort the numbers so the added number stands at the proper location in the array

Regardless of whether the object is empty or not return the reference of the current object.

### display function. (to be implemented)
```C++
   ostream& display(ostream& ostr) const
```
Display all the numbers with 2 digits after the decimal point.

- if the object is empty, write: **"Empty list"**.
- if the object is not empty start by setting the precision of the ostream object to 2 and a fixed format.
- write:  **"========================="** on **ostr** and then go to newline
- if the object is flagged as original, then write the file name otherwise write ```"*** COPY ***"``` and then go to a new line
- write all the double numbers separated by **", "** (A comma and a space) and then go to a new line
- write **"-------------------------"** and go to new line
- Write **"Total of " << m_numCount << " number(s)"** and go to new line
- write **"Largest number:  "** and the largest number in the list and go to new line
- write **"Smallest number: "** and the smallest number in the list and go to new line
- write **"Average:         "** and the average of all the numbers in the list and go to a new line
- write **"========================="** and DO NOT GO TO NEWLINE

At the end return the ostr object.

#### Execution sample
A Numbers object that has the double values 34.1, 3, 6, 12.2 and 34.56 in a file called **numbers.txt**<br />
should be displayed as follows:  
```Text
=========================
numbers.txt
3, 6, 12.2, 34.1, 34.56
-------------------------
Total of 5 number(s)
Largest number:  34.56
Smallest number: 3.00
Average:         17.97
=========================
```
If a Number object is empty, it will be displayed as follows:
```Text
Empty list
```

## Helper function overloads (to be implemented)
```C++    
ostream& operator<<(ostream& os, const Numbers& N);
```
Overload the insertion operator to display the Numbers object using istream.
- call the display function of N and return it

```C++
istream& operator>>(istream& istr, Numbers& N);
```
Overload the extraction operator to display the Numbers object using istream.
- read a double value using istr
- if the read is successful add the double value to N using += operator
- return istr;


## The tester program.
[main.cpp](lab/main.cpp)

## Expected output
[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)
Files to submit:  
```Text
Numbers.cpp
NUmbers.h
Numbers_prof.cpp
main.cpp
```
### Data Entry

```text
50<enter>
```
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



# DIY  (Practice only)

Create a module called **Stats** that can represent a file on the hard disk containing comma-separated numbers. 

This module should be able to load the numbers and perform the following tasks.

- A **Stats** object should be able to display the numbers in a tabular format on ostream in a specified number of columns, column width and precision. 
- A **Stats** object should be able to display the numbers that fall within a specific range and the number of their occurrence.
- A **Stats** object should be able to sort the numbers in an ascending or descending order.
- Copying a **Stats** object should be done safely and doing so should also copy the data file on the hard disk. The new file name should be the same as the original file with an added **"C_"** prefix. 
- Assigning a **Stats** object to another should be done safely and the content of the target file should also be overwritten by the source file.
- A **Stats** object should also make the numbers available to the user program by indexing like an array. 
- A **Stats** object should be able to receive the data file name from the istream and load the data from the file on the hard drive.

## Required public functionalities

### construction
#### 3 Argument Constructor
```C++
Stats(unsigned columnWidth = 15, 
      unsigned noOfColumns = 4, 
      unsigned precision = 2);
```
- columnWidth: width of each column in characters
- noOfColumns: number of columns to display the numbers in
- precision: number of digits after the decimal point for each number

In this case, the "**Stats**" object is not tied to any file on the hard drive and is empty.

#### 4 Argument Constructor


```C++
Stats(const char* filename, 
      unsigned columnWidth = 15, 
      unsigned noOfColumns = 4, 
      unsigned precision = 2);
```
Same as the previous constructor, but in this case, if the filename argument is not null and is successfully opened, the numbers in the file will be loaded into the **Stats** object.

#### Copy Constructor
Copying a **Stats** object should be done safely and doing so it should also copy the data file on the hard disk. The new file name should be the same as the original file with an added **"C_"** prefix. 

### Operator overloads
#### Copy assignment
Assigning a **Stats** object to another should be done safely and the content of the target file should also be overwritten by the content of the source file.

#### Index operator overloads  
```C++
double& operator[](unsigned idx);
```
Returns the reference of the number at idx index. If the index exceeds the size of the array, it should loop back to the beginning. For example, if the array size is 10, index 10 will be the reference of the element at index 0 and index 11 will be the reference of the element at index 1.

If the **Stats** object is empty, it should return the reference of a dummy double member variable.
```C++
double operator[](unsigned idx)const;
```
Returns the value of the number at idx index. If the index exceeds the size of the array, it should loop back to the beginning. For example, if the array size is 10, index 10 will be the value of the element at index 0 and index 11 will be the value of the element at index 1.

If the **Stats** object is empty, it should return zero.

### Boolean type conversion overload
If **Stats** is casted to boolean, it should return true only if it is not empty. Otherwise, it should return false.

### Methods (Member variables)
#### sort()
```C++
void sort(bool ascending);
```
Sorts the numbers in ascending or descending order.
#### size()
```C++
unsigned size()const;
```
Returns the number of numbers in the **Stats** object.
#### name()
```C++
const char* name()const;
```
Returns the name of the file tied to the **Stats** object.
#### occurrence()
```C++
unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
```
Displays the numbers that fall within a specific range and the number of their occurrence on ostream. 

The format of the printout should be the same as printing all the numbers.

## helper implementations 
### ostream insertion operator<<

**Stats** should be printable by ostream (cout) using the ```operator<<```. 

A Stats object should be able to display the numbers in a tabular format on ostream in a specified number of columns, column width and precision. See the execution sample file.

### istream extraction operator>>

**Stats** object should be able to receive the data file name from ostream (cin) using operator>>. After receiving the name, if the data file is open successfully, the numbers should be loaded into the **Stats** object.

## The tester program.
[main.cpp](DIY/main.cpp)

## Expected output

[correct_output.txt](DIY/correct_output.txt)

## DIY Testing

### Files needed to test with the submit command:  
 
```text
Stats.h
Stats.cpp
main.cpp
```
### Data Entry
```text
numbers.csv<ENTER>
```
### Testing Process


Log in to Matrix using an SSH terminal client (e.g., **PuTTY**).

Commit and push your code to GitHub, then pull the changes to your Matrix account.  
Follow the instructions in [Compiling and Testing Your Program](../README.md#compiling-and-testing-your-program) to ensure everything runs correctly.

Next, run the **submission command** from within your workshop repository folder on your Matrix account to test the execution of your DIY section.
