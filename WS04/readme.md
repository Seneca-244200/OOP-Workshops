# Workshop #4: Constructors Destructors and Current object
* Version 1.0)


In this workshop, you will use Constructors, a Destructor and a reference of the current object to simulate a **Canister** to hold liquid food products.

## Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define a default constructor
- define custom constructors with different number of arguments
- define a Destructor to prevent memory leaks.
- Use the reference of the current object 
- describe to your instructor what you have learned in completing this workshop

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
Your task for this lab is to complete a **Canister** module designed to hold liquid edible products.

A **Canister** is a cylindrical container defined by its height and diameter, and it is labeled with the name of its contents (e.g., Milk, Orange Juice, etc.). The **Canister** dynamically holds these contents and also tracks the volume of the liquid inside, ensuring it does not exceed its capacity. Any container filled higher than 0.267 centimeters from the top of the **Canister** is considered unusable.

The smallest **Canister** can have dimensions of 10.0 centimeters in height and diameter, while the largest can be 40.0 centimeters in height and 30.0 centimeters in diameter.


## Construction

The **Canister** can be created in three different ways:

- By default, a **Canister** is created with the following specifications:
    - Height and diameter: 13.0 x 10.0 centimeters
    - Content volume: 0
    - Content name: nullptr
- With a content name only
- With height, diameter, and content name (if the name is not provided, it should default to nullptr)

> In any case, when a **Canister** is created using initial values and any of the provided values are invalid, the **Canister** is rendered unusable. (Note: nullptr for the content name is not considered an invalid value.)


## Adding to the content of a canister
You can pour contents into the Canisters as per their labels. If too much is poured into a Canister, causing it to overflow, the Canister is rendered unsalable.

## Pouring contents of one canister into another

You can pour all or some of the contents from one Canister into another. If this results in mixed contents (i.e., the contents are not the same), the target Canister will be rendered unusable (not the source).

For example, you can fill an empty Canister (with no content name) with the contents of a Canister holding olive oil. Since the target Canister was empty, everything will be fine, and the Canister will be labeled as olive oil. However, if the Canister was labeled as orange juice (whether empty or not), it would be rendered unusable.

An unusable Canister cannot be used or cleared to become usable.

## Memory Leak
You must design your code in a way that ensures the construction, pouring, and destruction of Canisters do not result in a memory leak.

## Implementation
The provided module `cstr` is fully implemented and is used for C-string related functions and dynamic memory allocation routines.

The **Canister** class is partially implemented; all the private methods and the display method are fully implemented and functional. Reuse these methods or the `cstr` module functions for the implementation of other parts if needed.


### Private attributes or member variables (implemented)

```C++
char* m_contentName; // points to a dynamically allocated Cstring.
double m_diameter; // in centimeters 
double m_hieght;   // in centimeters
double m_contentVolume;  // in CCs
```

### Private methods or member functions (implemented)

```C++
  // renders the canister unusable by freeing the content name memory and setting the diameter and height to -1
  void setToUnusable();
  // Returns true if canister volume is below 0.00001
  bool isEmpty()const;
  // Returns true if height and diameters are within acceptable values
  bool usable()const;
  // Returns true if the content names of the two canisters are the same
  bool hasSameContent(const Canister& C)const;
  // returns the capacity of the canister
  double capacity()const;
  // Returns the content volume. Always less than capacity
  double volume()const;
```
All the above methods are commented on in detail in the code. Study and understand them before starting the implementation.

```c++
// displays the canister information on the screen.
std::ostream& display()const;
```

### Constructors
#### No-Argument Constructor (Default)
Sets the attributes to their default values.

#### one-Argument Constructor:
```c++
Argument: const char* contentName
```
- Sets the attributes to their default values.
- Dynamically allocates and copies the contentName into memory pointed to by m_contentName (use the provided alocpy function).

#### Three-Argument Constructor:
```c++
Arguments: double height, double diameter, const char* contentName
```
Use usable method and alocpy function in this logic

##### Logic 
- Sets the content name and the content value to their default values.
- Sets the height and diameter attributes to the corresponding incoming arguments.
- If the object is usable (use the private method):
    - Dynamically allocates and copies the contentName into memory pointed to by m_contentName (use alocpy).
    
### Destructor

Deallocates the dynamic memory pointed to by the content name attribute (use freemem).

### Public Methods (Member Functions)
#### `clear` Method

```c++
Receives: nothing
Returns: Reference to the current Canister object
```
Clears a **Canister** back to an empty state by:
- Deallocating the memory pointed to by the content name attribute (use the freemem function)
- Setting the content volume attribute to 0.0

At the end, it returns the reference to the current object.

#### `setContent` Method
```c++
Receives: const char* contentName
Returns: Reference to the current Canister object
```
If the received name is not null and the **Canister** is usable, it will set the content name of the **Canister** only if the **Canister** does not have a name (nullptr) or it is empty. Otherwise, if the **Canister** already has a name and it does not match the received name, the **Canister** will be rendered unusable.

The function will do nothing if the names are the same. At the end, the method will return the reference to the current **Canister**.

##### Logic

Use the usable, isEmpty, alocpy, hasSameContent, and setToUnusable functions in this logic:

- If the contentName argument is not null and the **Canister** is usable:
    - If the content name is null or the **Canister** is empty, it will set the name to the value pointed to by the contentName argument dynamically using the provided alocpy function.
    - Otherwise, if the contentName argument and the object’s content name are not the same, the **Canister** will be rendered unusable.

#### `pour` Method
```c++
Receives: double quantity
Returns: Reference to the current Canister object
```
If the **Canister** is usable, it adds the quantity argument to the content volume of the **Canister** if the quantity fits in the **Canister**. Otherwise, it will render the **Canister** unusable. In any case, it will return the reference to the current object.

##### Logic
Use the usable, volume, capacity, and setToUnusable methods in this logic:

- If the **Canister** is usable:
    - If the quantity is positive and the sum of the quantity and the current volume is less than the capacity, add the quantity to the content volume.
    - Otherwise, render the **Canister** unusable.

#### the `pour` method overload

```C++
receives: Canister& can
returns: Reference of the current Canister object
```
Pours the content of the **Canister** argument into the current **Canister** following the [Specs stated at the top](#pouring-contents-of-one-canister-into-another)

##### Logic
use usable, volume, capacity, pour(double) and setContent in this logic

- if the **Canister** is usable
    - if the volume of the **Canister** argument is more than the (capacity - volume) of the current **Canister**
        - the content volume of the **Canister** argument will be reduced by the (capacity - volume) of the current **Canister**
        - the content volume of the current **Canister** will be set to the maximum that is the capacity of the **Canister**
    - otherwise, since there is enough space to hold all the volume of the argument **Canister**
        - pour the content volume of the argument **Canister**  into the current **Canister**
        - set the content volume of the argument to zero
    - in any set the content of the current canister to the content name of the argument canister. This will automatically render the current canister unusable if the contents are not the same. 


```C++
      std::ostream& display()const;
```
This method is already implemented




## LAB Submission (part 1)

## The tester program.
[main.cpp](./lab/main.cpp)

## Expected output

[correct_output.txt](./lab/correct_output.txt)

## LAB Submission (part 1)

### Files to submit:  
```Text
Canister.cpp
Canister.h
cstr.cpp
cstr.h
main.cpp
```

### Data Entry

no data entry needed

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
Write a program in two modules for a Label Maker application:
> Use the `cstr` module from the lab section for C-string tools

The Two modules are used as follows to print labels:  

## The Label Module  

The label class creates a label by drawing a frame around a one-line text with an unknown size (maximum of 70 chars, **must be kept dynamically**).

The frame is dictated by series of 8 characters in a Cstring. These characters indicate how the frame is to be drawn:
```Text
character 1: top left corner character.
character 2: character to repeat for the top line.
character 3: top right corner character
character 4: character to repeat for the right line.
character 5: bottom right corner character
character 6: character to repeat for the bottom line.
character 7: bottom left corner character
character 8: character to repeat for the left line.
```
For example the following CString: ``` "AbCdEfGh" ``` <br />
will generate the following frame around a text:
```Text
AbbbbbbbbbbbbbbbbbbbbbbbbbC
h                         d
h                         d
h                         d
GfffffffffffffffffffffffffE
```

## Mandatory constructors and methods:
### `Label()`
Creates an empty label and defaults the frame to ```"+-+|+-+|"```
### `Label(const char* frameArg)`
Creates an empty label and sets the frame to the **frameArg** argument.
### `Label(const char* frameArg, const char* content)`
Creates a Label with the **frame** set to **frameArg** and the content of the Label set to the corresponding argument. Note that you must keep the content dynamically even though it should never be more than 70 characters.

### destructor
Makes sure there is no memory leak when the label goes out of scope.

###  `void readLabel();`
Reads the label from console up to 70 characters and stores it in the Label as shown in the [correct_output.txt](DIY/correct_output.txt) file

###  `std::ostream& printLabel()const;`
Print the label by drawing the frame around the content ad shown in the [correct_output.txt](DIY/correct_output.txt) file. Note that no newline is printed after the last line and cout is returned at the end.

## The LabelMaker Module  

The LabelMaker class creates a dynamic array of Labels and gets their content from the user one by one and prints them all at once. 

## Mandatory constructors and methods:
### `LabelMaker(int noOfLabels);`
creates a dynamic array of Labels to the size of **noOfLabels**
### `void readLabels();`
Gets the contents of the Labels as demonstrated in the [correct_output.txt](DIY/correct_output.txt) file
### `void printLabels();`
Prints the Labels as demonstrated in the [correct_output.txt](DIY/correct_output.txt) file
### `~LabelMaker();`
Deallocates the memory when LabelMaker goes out of scope.



## The tester program.
[main.cpp](DIY/main.cpp)

## Expected output

[correct_output.txt](DIY/correct_output.txt)



## DIY Testing

### Files needed to test with the submit command:  
```Text
cstr.h
cstr.cpp
Label.h
Label.cpp
LabelMaker.h
LabelMaker.cpp
main.gpp
```


### Data Entry

Follow the instructions in tester program.

### Testing Process


Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the submit command from your matrix account to test the execution of your DIY section
