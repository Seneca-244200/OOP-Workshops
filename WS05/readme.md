# Workshop #5: Member Operators and Helper Functions
* Version 1.0

In this workshop, you will have the opportunity to implement a bank account class which uses overloaded operators and type conversion operators. In addition, you will make use of helper functions, and generate formatted output.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- Define and create type conversion operators
- Define and create unary operators
- Define and create binary member operators
- Define and create helper functions
- Generate formatted output via cout


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
You are allowed to submit your work up to 2 days after the due date with a 30% penalty for each day. After that, the submission will be closed and the mark will be zero.

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

Your task is to implement a class to manage a bank account. The bank account class needs to support the tracking of funds, deposits, withdrawals, fees and interest. All deposits, withdrawals, or transfers count as a transaction which the customer will be charged a fee for.  

# The bankAccount class (Partially Provided)

## bankaccount Module (Provided)

The bankAccount class resides inside of a bankaccount module. `bankaccount.h` for the class definition and `bankaccounnt.cpp` for the implementation. 

## Data Attributes (Partially Provided)

A bank account can either be a Checking or Savings account.  Each `bankAccount` object stores the following:

1- A username, maximum of 16 characters in length and statically allocated as a `cstring`.
2- The funds in the account are stored as a `double` 
3- A `bool` to identify if this is a checking account 
4- An `int` for the number of monthly transactions.  

You are free to create additional private data members which may be helpful.

### Fees & Interest

Checking and Savings accounts have different interest rates and fees as outlined below, your class will need to be aware of these.  Instead of hard-coding these values in the code, create `const double` data members as part of the class for a cleaner solution:

| Account      | Transaction Fee | Interest Rate |
| ----------- | ----------- | - |
| Checking      | $1.25       | 0.5% |
| Savings   | $3.50        | 2.5% |

## Methods (Partially Provided)

### Constructor, Setup and isOpen (Provided)

If you read through `main()` you will note it requires a no argument default constructor and a 2 argument constructor.   We can combine both of these into a single method by creating a 2-argument constructor with default parameters; the 1st parameter is the user name for the bank account, and the 2nd parameter is a bool flag to identify if this is a checking account.

Note default parameters are only included in the class definition and not specified in the implementation within the .cpp file.

The constructor performs the following operations:
- Initialize the user name by setting the first char in the array to '\0' identifying this account as **not yet open**
- Calls the method `setup` to complete the setup
 - Calls `isOpen` to prevent an existing account from being re-initialized and setup again.  A number of your methods below should call `isOpen` to confirm the account has been opened.
  - Copy the user name to the class data attribute
  - Copy the checking flag to the class data attribute
  - Set monthly transactions to zero; set $ funds to zero

## Cast Operators

```C++
operator bool() const
```
Returns true if the account isOpen(); false otherwise.  This method does not modify the object.

```C++
operator double() const
```
Returns the total $ funds held in the account. Does not modify the object

## Unary Operators

```C++
bankAccount& operator++()
```
Calculates interest (ie: funds x rate) and adds it to existing funds in the account. Note the rate is based on the account type (see Fees & Interest above).  Interest can only be earned for accounts which have a positive value and have been opened. Returns reference to the current object.

```C++
bankAccount& operator--()
```
Calculates fees (ie: Monthly transactions multiplied by transaction fee) and subtracts it from existing funds in the account.  Note the transaction fee is based on the account type (see Fees & Interest above).  Can only be used if the account has been opened. Returns reference to the current object.

## Binary Operators

```C++
bool operator+= (double)
```
Deposits specified value by adding it to existing funds and increments the number of transactions.  `operator+=` Can only be used if the account has been opened. This method returns true on success; false otherwise.

Application example:
```Text
Deposit $100.00 for Joe Williams
```

***
```c++
bool operator-= (double)
```
Withdraws specified value by subtracting it from existing funds and increments the number of transactions.   It can only be used if the account has been opened. It returns true on success and outputs sample text below; false otherwise. It can be implemented by simply multiplying the specified value by -1 and invoking operator+= above.

Application example:
```Text
Withdraw $5.00 for Raya Chandok
```
***
```C++
bool operator== (const bankAccount&) const
```
`Operator==` checks if the specified bank account has the same user name, funds and type as this. It returns true if all 3 are identical; false otherwise.  This method does not modify the object.
> Note that the funds are considered the same if their difference is less than `0.001`

```C++
bool operator> (double) const
```
Returns true if funds in account > specified value. `operator>` can only be used if the account has been opened.  This method does not modify the object.

```C++
bool operator<= (double) const
```

Returns true if funds in account <= specified value.  It can only be used if the account has been opened.  `operator<=` Does not modify the object.  It can be implemented by simply invoking `operator>` from above and reversing the result.

## Additional Methods

```C++
bool operator<<(bankAccount&)
```
Transfer all funds from the specified account to this account.  First, check if both this account and the source account are open, and if the source account has positive funds.  Then display Formatted output as per the example below.  Finally use `operator+=` and `operator-=` (ie: what you just implemented above) to perform a transfer of funds.  This method returns true on success; false otherwise.

Application example:
```Text
Transfer $100.00 from Joe Williams to Cindy Kofler
```

***
```C++
void display (void) const
```
Display formatted output for this object as per the sample output below.

If the account is open:

```Text
Display Account -> User:----Cindy Kofler |  Savings | Balance: $  -52.00 | Transactions:012
```
If the account is not open:
```Text
Display Account -> User:------- NOT OPEN
```


## Global Helpers (non-member helper functions/operators)

```C++
bool operator> (double lhs, const bankAccount& rhs)
```
You will need to implement this global helper operator to support the case where the lhs (ie: left operand) is not a class (it is a primitive data type) and therefore not capable of having a method.  Use the (bool) cast operator to confirm the rhs account is open and the (double) cast operator to get the funds from the rhs account, then return the result of the comparison.

```C++
bool operator<= (double lhs, const bankAccount& rhs)
```
This global helper is required for the same reasons as above. It can be implemented by simply invoking the above global helper `operator>` and reversing the result.



## The tester program.
[main.cpp](lab/main.cpp)

## Expected output

[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)

### Files to submit:  

```text
bankaccount.cpp
bankaccount.h
main.cpp
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Data Entry

There is no data entry required for this submission.

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
> Please note that you can (and probably should) add more member functions to make the DIY part work.

In this part of the lab, you will create a Module with the name **Hero**.

## The Power module
Already fully implemented. Study this module and understand how it works.

## The Hero Class (module).
needs to be implemented.

### Hero Data Members
Declare four private data members:
1) Declare an array to hold the name of a hero, not exceeding MAX_NAME_LEN characters.
2) Declare a Pointer of type Power that will hold a dynamic set of powers a hero may have.
3) Declare an integer variable for the number of powers a hero may have.
4) Declare an integer variable for the power level of a hero.<br />This will be a calculated value. Every time you need to calculate/update this variable it will be done as follows:<br />
The sum of the rarity of all the heroes' powers multiplied by the total count of powers.

Store your class definition in a header file named `Hero.h` and your member function definitions in an implementation file named `Hero.cpp`.

### Constructors
- Default constructor to set a hero to a safe empty state.

- Overloaded constructor with 3 parameters to set the name, list of powers and the count of powers a hero has. This constructor will also set/update the `powerlevel` of a hero.

### Display Function
- A display function that will send the information about a hero to ostream in the following format and then return the reference of ostream;
```
Name: XXXXXXXXXXX<ENDL>
List of available powers:
  powers listed here...
  powers listed here...
  powers listed here...
  powers listed here...
Power Level: XXXX<ENDL>
```

### Operator and conversion overloads

- overload the **+= operator** that accepts a power reference. The power should be added to the dynamic list of powers of your hero. Your heroes' power level and power count should be updated too.

- overload the **-= operator** that accepts an integer reference. This operator will decrease the power level of the hero by the integer value received.


### Logical operators

- operator< : This operator takes two references to two hero parameters. It will return true if the first hero's power level is less than the second hero's power level. It will return false otherwise.

- operator> : This operator takes two references to two hero parameters. It will return true if the first hero's power level is greater than the second hero's power level. It will return false otherwise.

### `<<` and `>>` operator overloads 

- operator>> : This operator will take two parameters. The left parameter is a reference to a power. The right parameter is a reference to a hero. This operator will add power to the hero and update the hero accordingly.
    > Note: this is not an istream extraction operator and you are not allowed to modify the power module

- operator<< : This operator will take two parameters. The left parameter is a reference to a hero. The right parameter is a reference to a power. This operator will add power to the hero and update the hero accordingly.
    > Note: this is not an ostream insertion operator

## The tester program.

[main.cpp](DIY/main.cpp)

## Output

[correct_output.txt](DIY/correct_output.txt)

> Modify the tester program to test all the different circumstances/cases of the application if desired and note that the professor's tester may have many more samples than the tester program here.

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

### Files to submit:  
```Text
power.h
power.cpp
hero.h
hero.cpp
main.cpp
```


### Data Entry

No data entry needed

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


