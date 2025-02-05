# Workshop #5: Member Operators, Helper functions

In this workshop, you will implement different types of operator overload in a partially developed class.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define and create  binary member operator
- define and create a type conversion operator
- define and a create unary member operator 
- define and create helper binary operator between classes
- define and create a helper operator between a primitive type and a class.

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

# Part 1 - LAB (100%) The Account module.

Your task for this lab is to complete the implementation of the **Account** module for holding a bank Account number (an integer) and the balance of the Account (a double value). 

# The Account class
The Account class has two attributes; one integer for an Account number (**m_number**) and a double for the balance of the Account (**m_balance**)

The **Account** class can be in three different states: 

* Invalid Empty State<br />
An Account is in an **invalid** state if invalid information is fed into the Account. In these types of situations the Account number is set to **-1** and the balance is set to **0**. The Account object in this case is rendered inactive and can not be used anymore.
* New <br />
An Account is considered **New** or **not set** when it is just created and the Account number is not assigned yet. This state of the **Account** class is flagged by setting the Account number (**m_number**) to **0**.
* Valid<br />
An **Account** is considered **valid** if the Account number is a 5 digit integer with a zero or positive balance.

## Already implemented parts:
## Constructors
The **Account** can be created in two different ways:
- default constructor *(implemented)* 
```c++
  Account();
```
The default constructor sets the Account as **new** with a balance of **0**. 
- Two argument constructor (an integer and a double) *(implemented)*
```c++
  Account(int number, double balance);
```
The two-argument constructor sets the Account number and balance to incoming arguments only if both values are valid. If an invalid Account number or a negative balance is passed to the constructor, the object will be set into an invalid empty state.

## display function. 
*(implemented)*
```c++
   ostream& display() const
```
Displays the Account on the screen.<br />
If the Account is invalid, it is going to print:  **Bad Account**. If the Account is a new Account, instead of the Account number it will print **New**. <br />
At the end **display** will return the **cout** object.

## To be implemented:
### type conversion operators
- **operator bool**<br />
returns **true** if the Account is **valid** and otherwise **false**. This operator can not modify the **Account** object.
- **operator int**<br />
returns the **Account number**. This operator can not modify the **Account** object.
- **operator double**<br />
returns the **balance value**. This operator can not modify the **Account** object.

### Unary member operator
- **bool operator ~()**<br />
This operator returns **true** if the Account is **new** or **not set** (i.e. if the **Account number** is **zero**), otherwise it will return **false**.  This operator can not modify the **Account** object.

### Binary member operators
> Note: All the binary member operators **will not take any action** if the **Account**  is in an **invalid** state.

#### Assignment operators
- overload the **assignment operator** so a **NEW Account** can be set to an **integer**. In doing so, you should set the **Account number** of the **Account** to the **integer value**. <br />
If the **integer value** is an invalid Account number, the object should be set to an **invalid empty state** instead. <br />
If the Account is not new, then this operator should not perform any action.<br />
In any case, a reference of the **current object** (**Account**) should be returned. 
```c++
Account A,B; 
   A = 55555;  // the Account number of A will be set to 55555
   B = 555; // the Account B will be set to invalid state
   B = 66666; // no action will be taken since the B is not new
   A = 66666; // no action will be taken since the A is not new
```
- overload the **assignment operator** so a **NEW Account** can be set to another **Account** object. This action should **move** the balance and the Account number from one Account to another; therefore unlike the usual assignment operator that affects the left operand only, this operator will affect both operands; the balance of the left Account will be set to the balance of the right Account and then the balance of the right Account will be set to zero. The same will happen to the Account number<br />
If the left Account operand is not new or the right Account operand is not valid, no action should be taken.<br />
In any case, a reference of the **current object** (**Account**) should be returned. 
```c++
   Account A, B(66666, 400), Bad(555, -10);
   A = B;  // A will have the properties of B and B will become a NEW Account
   B = Bad; // Nothing will happen since Bad is not new
   Bad = B; // Nothing will happen since Bad is invalid
```
#### Binary operators with side-effect
- overload the **+= operator** to add a double value to an Account. This should act like depositing money into an Account. (i.e. the value of the double should be added to the balance)<br />
if the Account is in an invalid state or the double value is negative, no action should be taken.<br />
In any case, a reference of the **current object** (**Account**) should be returned. 
```c++
Account A(55555, 400.0), Bad(555, -10);
   A += 200.0;  // A will have a balance of 600 
   Bad += 300.0; // Nothing will happen since Bad is invalid
   A += -20.0; // Nothing will happen since the double value is negative
```
- overload the **-= operator** to reduce an Account balance by a double value. This should act like withdrawing money from an Account. (i.e. the value of the balance should be reduced by the double value)<br />
if the Account is in an invalid state, the double value is negative or there is not enough money in the Account no action should be taken.<br />
In any case, a reference of the **current object** (**Account**) should be returned. 
```c++
Account A(55555, 400.0), Bad(555, -10);
   A -= 150.0;  // A will have a balance of 250 
   A -= 300.0; // Nothing will happen since there is not enough money in A
   A -= -20.0; // Nothing will happen since double value is negative
   Bad -= 20.0 // Nothing will happen since Bad is invalid
```

- overload the **<< operator** (left shift operator) to move funds from the right Account to the left. After this operation, the balance of the left Account will be the sum of both and the balance of the right Account will be zero.<br />
Funds of an Account should not be able to be moved to itself and this operation does not affect the Account.<br />
In any case, a reference of the **current object** (**Account**) should be returned. 
```c++
Account A(55555, 400.0),B(66666, 500.0), Bad(555, -10);
   A << B;  // A will have a balance of 900.0, B will have a balance of zero
   A << A; // Nothing will happen 
   A << Bad; // Nothing will happen
   Bad << A; // Nothing will happen
```

- overload the **>> operator** (right shift operator) to move funds from the left Account to the right. After this operation, the balance of the right Account will be the sum of both and the balance of the left Account will be zero.<br />
Funds of an Account should not be able to be moved to itself and this operation does not affect the Account.<br />
In any case, a reference of the **current object** (**Account**) should be returned. 
```c++
Account A(55555, 400.0),B(66666, 500.0), Bad(555, -10);
   A >> B;  // B will have a balance of 900.0, A will have a balance of zero
   B >> B; // Nothing will happen 
   B >> Bad; // Nothing will happen
   Bad >> B; // Nothing will happen
```

### Binary helper operators

- Create a binary stand-alone helper **+ operator** that accepts a **constant Account reference** at left and another **constant Account reference** at right and returns a **double** value. <br />
The **double** value should be the **sum** of the **balances** of the two accounts.<br />
If any of the two accounts is **invalid**, then **zero** is returned.<br />
```c++
   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum;
   sum = A + B; // sum should be 1000.0
   sum = A + Bad; // sum should be 0 since Bad is invalid
   sum = Bad + B; // sum should be 0 since Bad is invalid
```
- Create a binary stand-alone helper **+= operator** that accepts a **double reference** at left and a **constant Account reference** at right and returns a **double** value. <br />
The value of the balance of the right operand (Account reference) should be added to the left operand (double reference) <br />
Then the value of the double reference is returned. 

```c++
   Account A(55555, 400.0), B(66666, 600.0), Bad(555, -10);
   double sum = 100, ret;
   ret = sum += A; // sum and ret should be 500.0
```

## The tester program.
[main.cpp](lab/main.cpp)

## Expected output
[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)
Files to submit:  
```Text
Account.cpp
Account.h
main.cpp
```
### Data Entry

No data entry needed

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

> Please note that you can (and probably should) add more member functions to make the DIY part work.



Create a Module for a **Mark** to encapsulate a mark between **0** and **100**.

| Mark              | Grade | Scale 4 mark |
|-------------------|-------|--------------|
| 0 < = Mark < 50    | F     | 0.0          |
| 50 < = Mark < 60   | D     | 1.0          |
| 60 < = Mark < 70   | C     | 2.0          |
| 70 < = Mark < 80   | B     | 3.0          |
| 80 < = Mark < = 100 | A     | 4.0          |


The class name must be **Mark**.

> :warning: No values are allowed to be kept in a mark out of the range of 0 to 100. In any circumstance and during any function if the value goes below 0 or above 100, the mark is set to an invalid empty state. This condition will not be repeated during the workshop and applies to all the functions and operators of class **Mark**

## Construction
Mark can be created using an integer value (one argument constructor)that sets the value of the mark. If this value is not provided (no-argument constructor), the value of the mark will be zero.
```c++
   Mark m, n(25), k(200), p(-10);
   // value of m is 0
   // value of n is 25
   // k is invalid
   // p is invalid
```
## Operator and conversion overloads
- Mark can be casted to an integer (int type). The result would be the value of the mark or zero if the mark is in an invalid state.
```c++
  Mark m, n(25), k(200), p(-10);
   cout << int(m) << endl;
   cout << int(n) << endl;
   cout << int(k) << endl;
   cout << int(p) << endl;
```
**Ouptut:** 
```Text
0
25
0
0
```
- An integer can be added to the value of the mark using the += operator; if the mark is invalid, the action is omitted. The reference of the mark is returned after the operation.
```c++
  Mark m, n(25), k(200);
  cout << int(m += 20) << endl;
  cout << int(n += 20) << endl;
  cout << int(k += 20) << endl;
  cout << int(n += 60) << endl;
```
**Output:** 
```Text
20
45
0
0
```
- Mark can be set to an integer using the assignment operator. If the mark is in an invalid state, the invalid value can be corrected by the assignment. Reference of the mark is returned after the operation. 
```c++
  Mark m, n(25), k(200);
  cout << int(m = 80) << endl;
  cout << int(n = 120) << endl;
  cout << int(k = 70) << endl;
```
**Output:** 
```Text
80
0
70
```
- Mark can be casted to a double, the result would be the GPA equivalent of the integer value. See the table of mark values above. Casting an invalid mark will result in a zero value.
```c++
   Mark m(50), n(80), k(120);
   cout << double(m) << endl;
   cout << double(n) << endl;
   cout << double(k) << endl;
```
**Output:** 
```Text
1
4
0
```
- Mark can be casted to a character (char type), the result would be the grade letter value of the mark. See the table of mark values above. Casting an invalid mark will result in an 'X' value.
```c++
   Mark m(50), n(80), k(120);
   cout << char(m) << endl;
   cout << char(n) << endl;
   cout << char(k) << endl;
```
**Output:** 
```Text
D
A
X
```
- Mark can be added to an integer, returning the integer after the operation. Invalid marks will not add any value to the integer.
```c++
   Mark n(80), k(120);
   cout << (val += n) << endl;
   cout << (val += k) << endl;
```
**Output:** 
```Text
140
140
```

  
## The tester program.
[main.cpp](DIY/main.cpp)

## Expected output

[correct_output.txt](DIY/correct_output.txt)

## DIY Testing

### Files needed to test with the submit command:  
 
```text
Mark.h
Mark.cpp
main.cpp
```
### Data Entry

No data entry needed

### Testing Process


Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the submit command from your matrix account to test the execution of your DIY section
