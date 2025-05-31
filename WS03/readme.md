# Workshop #3: Member Functions and Privacy 
V(0.9) being reviewed

In this workshop, you will implement member functions, constructors, destructor and apply privacy and a safe empty state for a class.

---
> ⚠️ **Before You Begin**
> You **must read and understand** the [Workshop Regulations and Policies](../README.md) before starting this or any other workshop. This document outlines important rules about academic integrity, submission procedures, and expectations.
> These policies apply to **all workshops** in OOP244. If you have already read it once, please ensure you continue to follow its guidelines throughout the course.
---

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define a class type
- privatize data and methods within the class type
- instantiate an object of class type
- use member functions to query the state of an object
- use member functions to change the state of an object
- use constructors and destructor to manage the resources of the class
- describe to your instructor what you have learned in completing this workshop

# Part 1 - LAB (100%)

Your task for part one of workshop 3 is to create a class called "CC" that encapsulates a Credit Card (in CC.h and CC.cpp) and displays the credit card information.

## the `cstr` module
The `cstr` is provided and is fully functional to be used for Cstring-related operations.

Study this module and understand how it works. Use the functions provided in this module for your string actions like copying and length extraction. Do not include the `<cstring>` header file module provides all the functionalities you need for these matters. 

## Implementing the CC class
### Private Attributes

This class must keep the following information:

- **The cardholder's name**: stored dynamically as a C-style string (`char*`)
- **CVV**, **expiry month**, and **expiry year**: stored as short integers (`short`)
- **Credit card number**: stored as an unsigned long long integer (`unsigned long long`)

### Private Methods
  
#### Dynamic Memory Management

##### Dynamic Memory Allocation and Copying

Create a private method that receives one argument:
- a constant C-string for the cardholder's name.

    Dynamically allocate a C-string, pointed to by the character pointer attribute of the class, and copy the name into it.

    This function returns nothing.

##### Deallocating the Dynamic Memory

Create a private method (receives and returns nothing) to deallocate the memory pointed to by the character pointer attribute of the class, and then set the pointer to `nullptr`.

#### Validation and Displaying the class

The CC class has the following private methods.
- display 
- validate
- prnNumber
These methods cannot modify the CC class and therefore must be constant.


#### display (with five arguments)
Since formatting the output using `ostream` is not covered yet, the private method `display` is provided below to be added to the `CC` class. 

```c++
void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
   char lname[31]{};
   strcpy(lname, name, 30); // declared in "cstr.h"
   cout << "| ";
   cout.width(30);
   cout.fill(' ');
   cout.setf(ios::left);
   cout << lname << " | ";
   prnNumber(number);
   cout << " | " << cvv << " | ";
   cout.unsetf(ios::left);
   cout.setf(ios::right);
   cout.width(2);
   cout << expMon << "/" << expYear << " |" << endl;
   cout.unsetf(ios::right);
}
```
 
#### validate

```C++
bool validate(const char* name, 
              unsigned long long cardNo, 
              short cvv, 
              short expMon, 
              short expYear)const;
```
Implement this private method to validate the credit card information received through the argument list as follows:
- name: should not be a null pointer and should be more than 2 characters long
- cardNo: values between 4000000000000000ull and 4099999999999999ull 
  > `ull` makes the literal number an `unsigned long long integer`)
- cvv: a three-digit number
- expMon: values between 1 and 12
- expYear: values between 24 and 32
  
The method should return true if all the conditions are met, otherwise, it will return false

This function does not modify the object (is constant).

#### prnNumber

```C++
void prnNumber(unsigned long long CCnum)const; 
```
The code for this method is provided

This function prints a 16-digit number in a set of 4-digit numbers separated by spaces.

For example:  

`4098645375646543` will be printed as `4098 6453 7564 6543`

You can accomplish this by utilizing repeated division and modulus operations. 

- Divide the number by 1000000000000ull to get the left four digits and print it. 
- Add a space. 
- Extract the right 12 digits (remainder) by using modulus and now Divide id by 100000000ull and repeat until all the numbers are printed.

This function does not modify the object (is constant).

### Public methods

#### set
```C++
void set();
```
Sets the object to a safe empty state by setting all the values to zero and the name pointer to `nullptr`.


#### isEmpty
```C++
bool isEmpty() const;
```
Returns if the CC object is in a safe empty state or not; by returning true if the cardholder name pointer attribute of the object is `nullptr`, otherwise, it will return false.

#### set (overloaded with five arguments)
```C++
void set(const char* cc_name, 
         unsigned long long cc_no, 
         short cvv, 
         short expMon, 
         short expYear);
```
First, it will set the object to a safe empty state. Then if all the arguments are valid using `validate()`, it will dynamically keep a copy of the name in the name attribute (using `aloCopy function`) and then sets the rest of the attributes to their corresponding values. 

If validation fails, nothing will be set.

#### display (overload with no arguments)
```C++
void display() const;
```
If the object `isEmpty()`, print `"Invalid Credit Card Record"` and go to newline;

If it is not in a safe empty state, display the `CC` class using the private `display` method.

This method does not modify the class. (it is constant)

### Constructors

#### No-Argument Constructor

Initializes the object to a safe empty state.

#### Five-Argument Constructor

The five arguments align to the [five data members](#private-attributes) of the CC class. The arguments representing the expiry month and year will default to 12 and 26 respectively.

First, it sets the object to a safe empty state. Then, if all the arguments are valid using the `validate()` function, it dynamically stores a copy of the name in the name attribute (using the `aloCopy` function) and sets the rest of the attributes to their corresponding values.

If validation fails, nothing will be set.

### Destructor

Deallocates any dynamic resources belonging to the class. 

## The tester program.
[main.cpp](./lab/main.cpp)

## Expected output

[correct_output.txt](./lab/correct_output.txt)

## LAB Submission (part 1)

### Files to submit:  
```Text
cstr.h
cstr.cpp
CC.h
CC.cpp
main.cpp
cc.csv
```

### Data Entry

No data entry is needed

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

Your task for the DIY section is to create a NameTag class to hold a name up to 50 chars (not dynamic) and print it with a frame around it. 

Then you must create a class called TagList that holds a dynamic array of NameTags and prints all the tags with the frame size matching the longest name in the list.

## NameTag class
A name tag holding "Fred Soley" is printed as follows:

Smallest frame possible:
```text
**************
* Fred Soley *
**************
```
Or it can be printed with a bigger frame as follows:
```text
*******************************
* Fred Soley                  *
*******************************
```

The length of the frame must be modifiable (using a modifier method) so the TagList can change it, to set all the frames to the same size.


### Methods of NameTag used in the main.
Only one method of the NameTag is used in the main function:  
  
```C++
void set(const chat* name).
```
This method sets the name, held by the NameTag object.

The rest of the methods or attributes of NameTag are to be designed by you. 

## TagList

TagList needs to have the following:

```C++
TagList(int num);
```
Sets TagList to an empty state and then if num is greater than zero it dynamically creates an array of `num` NameTags.

```C++
void add(const NameTag& nt);
```
Adds a NameTag to the TagList up to `num` (of the set method) NameTags.
```C++
void print();
```
Prints all the tags with the same size which is the frame size of the longest name in the list.
```C++
~TagList();
```
Deallocates the NameTags;

## Tester Program

[main.cpp](DIY/main.cpp)

## Execution Sample

[correct_output.txt](DIY/correct_output.txt)


## DIY Testing

### Files needed to test with the submit command:  

```Text
NameTag.h
NameTag.cpp
TagList.h
TagList.cpp
main.cpp
simpsons.txt
```


### Data Entry

No data entry is needed!

### Testing Process

Log in to Matrix using an SSH terminal client (e.g., **PuTTY**).

Commit and push your code to GitHub, then pull the changes to your Matrix account.  
Follow the instructions in [Compiling and Testing Your Program](../README.md#compiling-and-testing-your-program) to ensure everything runs correctly.

Next, run the **submission command** from within your workshop repository folder on your Matrix account to test the execution of your DIY Part.
