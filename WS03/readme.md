# Workshop #3: Member Functions and Privacy
* Version 1.0
* [Version 1.1](#v11) (Added spec for car() query function in Customer that is used in main.cpp)

In this workshop, you will complete your work using member functions and privacy.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define class types
- privatize data within the class type
- use member functions to query the state of an object
- use member functions to change the state of an object
- format your output on the console
- describe to your instructor what you have learned in completing this workshop

## Submission Policy

This workshop is divided into two coding parts and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 50% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (**DIY**): A Do It Yourself type of workshop that is much more open-ended and is worth 50% of the workshop's total mark.  
- *reflection*: non-coding part, to be submitted together with *DIY* part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).
- Submissions of part 2 that do not contain the *reflection* (that is the **non-coding part**) are not considered valid submissions and are ignored.

## Due Dates

The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

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


### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in the workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

# Part 1 - LAB (50%)
Your task for Workshop 3 Part 1 is to create a C++ program for a car service shop that offers different maintenance services. The program should consist of three modules: 
```C++
Car.cpp
Customer.cpp
main.cpp (tester)
```
The car service shop needs to maintain information about customers and their cars, including the following information:
- Car, including license plate, make and model, service description, and cost.
- Customer, containing an ID, name, and an address pointing to their Car.

# Car class 
The Car class is typically defined in a header file named Car.h and implemented in a corresponding source file and must keep the following information:
# Private data members
- m_licencePlate: a maximum 8-character long Cstring
- m_makeModel: that holds make and model dynamically in a C string. (char *)
- m_serviceDesc: that holds the service description dynamically in a C string. (char *)
- m_cost: a double variable for the cost of the service


# Public methods

```C++
bool isEmpty() const;
```
Member function to check if the object is in a safe recognizable empty state. A car is considered empty if the either "make and model" or "service description" is either null or an empty cstring.

```C++
void setEmpty();
```
Member function sets the object a safe recognizable empty state. setEmpty accomplishes this by setting the attributes to empty cstring, nullptr and **0.0**.

```C++
void deallocateMemory();
```
Member function to deallocate dynamically allocated memory for "make and model" and "service description" member variables.

```C++
void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
```
Member function to Set car information and service details as follows.

- Deallocates existing memory and then sets it to a safe empty state.
- If the incoming information is valid (license plate is not empty and "make and model" and "description" are not null and not empty. note: the cost is not validated)
	- Copies the corresponding argument to the license plate attribute
	- Allocates memory and copies the data for car make and model
	- Allocates memory and copies the date for the service description
	- Assigns the 'serviceCost' value to the corresponding argument value.

```C++
void display() const;
```
This function displays the car in the following format:
- The labels of the data are left justified in 15 spaces.
- The data of the attributes are right justified in 20 spaces.
- The cost is displayed with 2 digits after the decimal point.
  ```text
  License Plate:                  ABC
  Model:                 Toyota Camry
  Service Name:     Engine oil change
  Service Cost:                 50.00
  ```


# Customer class 
The Customer class is typically defined in a header file named Customer.h and implemented in a corresponding source file and must keep the following information:
# Private data members
- m_id: an integer holds the customer ID
- m_name: that is held dynamically in a C string. (char *)
- m_car: that is a pointer to an unmodifiable Car object. (customer's car).
  > Note that this is not dynamically allocated. It is only a pointer to be set to the address of a "Car" object that exists somewhere.


# Public methods

The Customer class has the following Private function:
```C++
bool isEmpty() const;
```
This query method checks if the object is in a safe empty state. A customer is considered empty if the name pointer is null or empty cString or the car pointer is null.


```C++
void setEmpty();
```
This method sets the customer to a safe empty state by setting the pointers to null and the id to 0.

```C++
void deallocateMemory();
```
This Member function deallocates the dynamically allocated memory for the m_name member variable.


```C++
void set(int customerId, const char* name, const Car* car);
```
Member function to Set the Customer name, ID and Car.

- Deallocates existing memory and then sets it to a safe empty state.
- If the incoming information is valid (i.e. the name is not null and not empty and the Car pointer is not null. The ID is not validated)
	- Copies the corresponding argument to the ID attribute
	- Allocates memory and copies the data for the name of the customer
	- Assigns the Car pointer attribute to the corresponding argument


```C++
void display() const;
```
This function displays the Customer in the following format:
- The labels of the data are left justified in 15 spaces.
- The data of the attributes are right justified in 20 spaces.
After the customer information is printed, the Car will be displayed. 
  ```text
	Customer ID:                   1005
	First Name:              Jane Smith
	License Plate:                  ABC
	Model:                 Toyota Camry
	Service Name:     Engine oil change
	Service Cost:                 50.00
  ```

#### V1.1
```C++
const Car& car()const;
```
This function returns the car object pointed to by m_car pointer by dereferencing it.
There is no need to validate the pointer prior to dereferencing. It can be assumed to be valid.


## The Tester Program

[main.cpp](./lab/main.cpp)

This module is fully provided. Please do not change it.
Please review it and make sure you understand how the functions that you have developed are being used.

## Expected output
[correct_output.txt](./lab/correct_output.txt)


## Files to submit:
```C++
Car.h
Car.cpp
Customer.h
Customer.cpp
main.cpp

```
## Data Entry
- No data entry is required for this part. Check the execution sample.

#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

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





# DIY (50%) 
## Implementation  
You are tasked with creating a C++ module for an ice cream vendor called Vendor. The module should allow customers to select from five flavours (chocolate, strawberry, mango, tutti fruit, and almond crunch) and specify the number of scoops they want. Additionally, customers have the option to purchase a vanilla wafer for an extra cost, and if they choose chocolate ice cream, there is an additional charge. To accomplish this, the Vendor module requires implementation of an Icecream module too.

Your program should follow the given rules:

- Each scoop costs $5
- Vanilla wafer cone costs $5 extra
- Chocolate Icecream costs $1 extra per scoop
- Displays a menu asking the customer for their flavour choice, the number of scoops, and whether they want to add a vanilla wafer:
- Displays the final payable amount, along with detailed pricing.

Remember to include any necessary libraries, data structures, and member functions to achieve the desired functionality.

### Modules to be created:
- Icecream
- Vendor


### Icecream Module
There are no required member functions for the Icecream class, but the following two methods are suggested. You are free to design this class any way you like, as long as the execution matches [the sample execution](DIY/Icecream_test_output.txt).

```C++
void getOrder();
```
Gets an fool-proof order for an icecream. [(See execution sample)](DIY/Icecream_test_output.txt)

#### Sample execution
```text
Select flavour:
----------------
1: Chocolate
2: Strawberry
3: Mango
4: Tutti fruit
5: Almond crunch
----------------
> 1
Number of Scoops (max 3)
> 2
Vanilla wafer cone?
(Y)es/(N)o > y
```

```C++
void printOrder();
```
Prints the order details of an icecream order. [(See excution sample)](DIY/Icecream_test_output.txt)

#### Sample execution
```text
Order details:                Price
-----------------------------------
Number of scoops, 2 total:    10.00
Chocolate flavour:             2.00
Vanilla Wafer:                 5.00
Price:                        17.00

Or

Order details:                Price
-----------------------------------
Number of scoops, 2 total:    10.00
Mango flavour
Vanilla Wafer:                 0.00
Price:                        10.00
```


# Vendor class
The Vendor class requires these four mandatory methods:

- Add to the seneca namespace the following member functions:

```C++
setEmpty();
```
A member function to set the Vendor object to an empty state.

```C++
takeOrders();
```
A member function responsible for taking customer orders. This function interacts with customers to gather order details.
- It will get the number of orders for Icecreams
- Gets each order for the Icecream

```C++
displayOrders();
```
- Prints the details of all the orders
- Prints the total price, tax (13%) and the Total price after tax.

```C++
clearData();
```
A member function for cleaning up and releasing resources associated with the Vendor object. This function is used to avoid memory leaks and perform cleanup when the Vendor object is no longer needed.

## Tester program (main.cpp)

[main.cpp](DIY/main.cpp)

This module is fully provided. Please don't change it. Please review it and make sure you understand how the functions that you have developed are being used.

## Data Entry
```text
2
1
3
y
one
0
6
3
one
0
4
2
x
no
n
```
  
## Expected output

[correct_output.txt](DIY/correct_output.txt)

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

### Files to submit:  


```Text
Icecream.h
Icecream.cpp
Vendor.h
Vendor.cpp
main.cpp (tester) 
reflect.txt
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


