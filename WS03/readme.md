# Workshop #3: Member Functions and Privacy
* version 1.0  
* version 1.1 (corrected the invalid empty state message)

In this workshop, you will encapsulate a Train using the name, departure time and number of passengers. You will use member functions, privacy, safe empty state and dynamic memory allocation to complete your work.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the following abilities:

- to define a class type
- to privatize data within the class type
- to instantiate objects of class type
- to use member functions to query the state of an object
- to use member functions to change the state of an object
- to use standard library facilities to format data inserted into the output stream
- to dynamically allocate and deallocate memory within a class.

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

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace, unless instructed otherwise.


# Part 1 (50%) The Train Class

Code a Train class that holds the information for a Train. The class must have private data members to include the following information:
1. the name of a train in a dynamically allocated C-string
2. the number of people on a train
3. the departure time of the train in military format.

Declare three C++ constants, for the lowest acceptable time value, the highest acceptable time value and the maximum number of passengers allowed on a train. 
```text
MIN_TIME  set to 700
MAX_TIME set to 2300
MAX_NO_OF_PASSENGERS set to 1000
```

## Attributes (member variables)

Declare three private attributes

1. a character pointer to hold the dynamic name for the Train. 
2. an integer variable for the number of people on a train. 
3. an integer variable for the departure time. 

Store your class definition in a header file named `Train.h` and your member function definitions in an implementation file named `Train.cpp`.

## Methods (member functions)
``` void initialize();```
Initializes the Train object to an invalid state by setting the name pointer to nullptr and other attributes to -1.

```bool validTime(int value)const;```
Returns true if the value is between the minimum and maximum acceptable values and if the two right digits are less than or equal to 59.

```bool validNoOfPassengers(int value)const;```

Returns true if the number of passengers is positive and less than the maximum number of passengers allowed on a train. 

```void set(const char* name);```

Sets the name of the Train dynamically: 
1. deletes the current train name
2. sets the train name pointer to nullptr
3. if the argument name is not nullptr and is not an empty string<br />
    First, allocate memory to the length of the name argument (+1 for null) in the name attribute and then copy the name argument into the dynamic name attribute.
    
```void set(int noOfPassengers, int departure);```
sets the two attributes for the number of passengers and departure time to the incomming values if the are valid. If not both will be set to `-1` to mark them as invalid.

```void set(const char* name, int noOfPassengers, int departure)```
sets the name, the number of passengers and the departure time to incomming arguments using the same logic of the other two set functions.

```void finalize();```
Finlizes the use of the Train object by deleting the memory pointed by the name attribute pointer. 

```bool isInvalid()const;```

returns true if any of the attributes are set to their invalid state. 

```int noOfPassengers() const;```
This query returns the  number of people on a train.

``` const char* getName() const; ```

This query returns the name of a train.

```int getDepartureTime() const;```

This query returns the time of departure.
   
```void display() const;```
This member function sends the information about a Train to the standard output in the following format if the object holds valid data values.
```
NAME OF THE TRAIN:    The name of the train
NUMBER OF PASSENGERS: 9999
DEPARTURE TIME:       9999
```
Otherwise it will print:
`Train in an invalid State!`


## Testing Program

[main.cpp](lab/main.cpp)

## Sample Output

[correct_output.txt](lab/correct_output.txt)

## PART 1 Submission 

### Files to submit:  

```Text
Train.h
Train.cpp
main.cpp

```
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


> **⚠️Important:**  Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty


## Part 2: DIY
Add the following functionalities to the Train class. Note that to implement these functions you can (and are encouraged to) add as many member functions you need to the class. 

### ```load```


Load returns a  boolean and has at least one integer reference argument. 

This function boards passengers onto the Train as follows:
First, it will ask the user for the number of passengers and then try to board them all. If the total number of passengers is more than the maximum number of people allowed on the train, it sets the integer reference argument of the function to the number of people who are left unboarded and sets the number of passengers of the train to the maximum allowed. 

The function returns true if everyone is boarded and false if some are left behind. 

#### load exection sample 

```text
Enter number of passengers boarding:
> 200<ENTER>
```


### ```updateDepartureTime```
Updates the departure time of a train. 

This function returns a boolean to indicate if the action was successful or not.

The function prompts the user for the new departure time. After reading the time if the value was a valid time value it will reset the departure time to the new value. If the value is not valid, it will set the departure time to -1.

#### updateDepartureTime execution sample
```text
Enter new departure time:
> 1533<ENTER>
```

### transfer
Transfers the passengers of a Train to the current Train.

Returns a boolean and receives a constant Train reference as an argument.

This function's execution is considered to be successful if both the current Train and the Train referenced by the argument are in a valid state. 

The transfer function will first change the name of the current Train to a combination of the names of the two trains. For example, if the name of the current Train is `TR one` and the name of the other Train is `TR two`, the combination of the two names will be `TR one, TR two`.  

Then the Transfer will try to board all the passengers of the other Train (referenced by the argument) to the current train. If all the passengers are boarded successfully the function will quietly exit. If some of the passengers are left behind the following message will be printed.  

```text
Train is full; 25 passengers of TR one, TR two could not be boarded!
```
In the example above we are assuming that 25 passengers were not boarded and the combined name of the current train is 'TR one, TR two`.

> Obviously the departure time of the current train remains the same.

## Testing Program

[main.cpp](DIY/main.cpp)

## Sample Output

[correct_output.txt](DIY/correct_output.txt)

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## DIY Submission (part 2)

### Files to submit:  

```Text
main.cpp <--- do not modify this.
Train.cpp
Train.h
```


Upload your source code and data file to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.


> **⚠️Important:**  Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty


