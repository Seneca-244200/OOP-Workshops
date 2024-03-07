# Workshop #6: Classes and resources, IO operators

* Version 1.0

In this workshop, you will learn to make classes and resources, following the "[the rule of 3](https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming))" for safe copying. You'll also practice simple file handling using **ifstream** and **ofstream**.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- Define and create copy constructors
- Define and create a copy assignment operator
- Prevent copying and assignment in a class
- Understand when and why to use friend classes  
- Do simple file IO using ifstream and ofstream 


## Submission Policy


The workshop is divided into one coding part and one non-coding part (two separate submissions):

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

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

# Part 1 - LAB (100%)

In this section of the workshop, you need to finish setting up the **EmailFile** module. This module connects to a file saved on the computer and loads the email details into an array of **Emails**.

The **Email** class represents a single email record, including the email address, the name of the sender or recipient, and the year associated with the email. 

The **EmailFile** class manages a collection of **Email** records. It is responsible for higher-level operations including file-handling tasks. Therefore, the **Email** class should be fully private and should not be able to exist outside of an **EmailFile** class. 

An **EmailFile** object can be safely copied and assigned to another **EmailFile** object.

An **EmailFile** object can be saved to the hard drive. 

The contents of two **EmailFile** instances can be merged, with the option to append the consolidated email records into a new file.

The input file is a CSV (Comma-Separated Values) file where each line represents an individual email record. Each line/record is divided into three fields: email address, name, and year. These fields are separated by commas. This format is consistent throughout the file, and each record is on a new line. The maximum possible size for all the fields of the Email record is assumed to be 1024 which is defined as a global variable **BUFFER_SIZE**. Example record: 

```text
jeremiah_morris85@office.mobi, Jeremiah Morris,2019
```

## The Email Class
The **Email** class is fully private and should be accessible by the **EmailFile** class. 
```C++
class Email
	{
		char* m_email{ nullptr };
		char* m_name{ nullptr };
		char m_year[5]{'\0'};
		Email() {};
		Email& operator=(const Email&);
		bool load(std::ifstream& in);
		~Email();
		// incomplete
	};
```
Complete the **Email** class by prohibiting the copy constructor for this class and making the **EmailFile** class a friend of the **Email** class. 

### Attributes (Member variables)
#### char* m_email
holds the address of the dynamically allocated Cstring (to hold the email address)
#### char* m_name
holds the address of the dynamically allocated Cstring (to hold the name associated with the email)
#### char m_year[5]
A Cstring to store the year information.
### Implemented Methods (Member Functions)

#### Default constructor
Initializes the **m_email**, **m_name**, and **m_year**  attributes to a safe empty state.  

#### Destructor
This is the destructor, responsible for cleaning up and releasing memory when an **Email** object goes out of scope.

#### Copy Assignment Operator
```
Email& operator=(const Email&);
```
This function is used to assign the values from one **Email** object to another. It performs a deep copy to ensure that the source object's data is correctly copied into the target object, with its own separate memory allocation. The function safeguards against self-assignment. 

#### load function
```C++
bool load(std::ifstream& in);
```
This function reads data from an input file stream and populates the **Email** object's members with this data. It reads the email address, name, and year from the file and stores them in the object's members. It returns a boolean value indicating the success or failure of the loading process.

## The EmailFile Class

### Attributes (Member variables)
**EmailFile** has three private member variables:
```C++
Email* m_emailLines;
```
A pointer to hold an array of **Email** objects. Each object represents a single email record (containing the email address, name, and associated year). This attribute should be initialized to **nullptr**.
```C++
char* m_filename;
```
A pointer intended to hold the name of the file associated with an **EmailFile** object. The file name indicates where the email data can be read from or written to. This attribute should be initialized to **nullptr**.
```C++
int m_noOfEmails;
```
An integer to be set to the number of emails in the file. This attribute should be initialized to zero.

### Private Methods (Member Functions)
#### setEmpty (already implemented)
```C++
void setEmpty();
```
Deletes the **m_emailLines** dynamic array and sets it to **nullptr**. Deletes the **m_filename** dynamic Cstring and sets it to **nullptr**. Sets **m_noOfEmails** to zero.

#### setFilename (already implemented)
```C++
void setFilename(const char* filename);
```
Dynamically allocates a Cstring in **m_filename** and copies the content of the **filename** argument into it. 

#### setNoOfEmails (already implemented)
```C++
bool setNoOfEmails();
```
This module counts the number of email records in the file by counting the number of lines:

Creates a local **ifstream** object to open the file with the name held in **m_filename**. If the file fails to open, it returns a false to indicate that the operator was unsuccessful and prints to the screen: "Failed to open file: [m_filename]". 

If the program can open the file without problems, it starts going through the file one character at a time, counting how many times it finds a new line. This count is kept in the **m_noOfEmails** attribute.

When it finishes checking the whole file, the program adds one more to the count in **m_noOfEmails**. It does this because the very last line might not end with a new line, so this ensures that the last email is still counted.

If it turns out there are no lines in the file, the program will delete the **m_filename** and set it to **nullptr**. 

#### loadEmails (to be implemented by students)
```C++
void loadEmails();
```
Load the file m_filename into a dynamic array of **Emails** pointed by **m_emailLines**:

If the **m_filename** is null, this function does nothing. 

If the **m_filename** is not null (EmailFile is not in a safe empty state), **loadEmails()** will dynamically allocate an array of **Emails** pointed by **m_emailLines** with the size kept in m_noOfEmails. Hint: Make sure **m_emailLines** is deleted before this to prevent memory leaks.

Open a file for reading by creating an **ifstream** object, using the file name stored in **m_filename**. Start a loop that will read the file one line at a time, where each line represents a single email record. For every line read, call the **Email::load** function to process and store the data in a new **Email** object.

If a line cannot be correctly processed and turned into an **Email** object, perhaps because of incorrect formatting, stop reading any further by breaking the loop. After finishing the file reading, adjust **m_noOfEmails** to reflect the actual number of emails read from the file, ensuring it accounts for the scenario where there might be an extra empty line at the file's end that shouldn't be considered a valid email record.

### Type conversion overloads:
#### boolean cast (to be implemented by students)
```C++
operator bool()const;
```
Returns true if the EmailFile is not in an empty state and returns false if it is. 

### Constructors (to be implemented by students)
```C++
EmailFile();
```
Creates an empty **EmailFile** and sets it to a safe empty state.
```C++
EmailFile(const char* filename);
```
If the input argument is **nullptr** sets the **EmailFile** object to a safe empty state. Otherwise, it will set the filename, set the **m_noOfEmails** and finally load the Emails (using the corresponding private methods.)

### Rule of three implementations for classes with resources
Implement The Copy Constructor, Copy assignment, and destructor. To make your code more efficient and avoid repetition, you can employ a strategy known as "Localization." Here's what it entails:
* **Localization Technique:** Create a single private function in your class that performs the copying process. This function isn't used on its own but is called by both the Copy Constructor and the Copy Assignment Operator. By doing this, you're centralizing the copy logic in one place, ensuring consistency and reducing duplicate code.

Alternatively, there's another method to simplify your code:

* **Reusing Copy Assignment in Copy Constructor:** You can design your Copy Constructor in a way that it calls the Copy Assignment Operator. This method ensures that the same operations are performed when a copy is made, regardless of whether it's via construction or assignment, helping keep your code DRY (Don't Repeat Yourself) and consistent.

#### Copy Constructor
Start by setting the object to a safe empty state. If the provided **EmailFile** object is correct and usable, do these steps to make a safe copy of the **EmailFile** and its details:

* **Copy the File Name:** Take the file name from the given **EmailFile** object and use it as the file name for the new one.

* **Record the Email Count:** Make a note of the number of emails from the original **EmailFile** object.

* **Copy Each Email:** For the emails in the original **EmailFile**, create new memory spaces and fill them with the exact content from the old emails.

#### Copy Assignment
Overwrite the current data by the content of the incoming **EmailFile**.

* Check self-assignment and check if the source object is valid
* If the source and destination objects are different, the function removes the old data from the destination object.
* Create a new memory space in the current object and then take each piece of data in the source object and copy it over to the destination object.

#### Destructor
Deletes all the dynamic data. 

### Public Methods
#### saveToFile (to be implemented by students)
```C++
bool saveToFile(const char* filename) const;
```
This method takes a Cstring as an input argument and tries to save email information to this file. It gives back a simple 'yes' (true) or 'no' (false) if it could open the file or not.

* First, it tries to create or open the file. 
* If it can't open the file, it reports, "Error: Could not open file: [filename]."

Once the file is open, it proceeds to write the email data:

* It looks at each email saved in its memory (each one is an "Email" object in a big list called "m_emailLines").
* For every email, it writes down the details following the CSV format to the file.

#### fileCat (to be implemented by students)
```C++
void fileCat(const EmailFile& obj, const char* name = nullptr);
```
The **fileCat** method merges emails from another **EmailFile** object into the current object and optionally renames the resulting file. Here's a breakdown of its actions:

1. **Initial Check**: It first ensures both the current **EmailFile** and the one provided as an argument is in a valid state. If either doesn't, it exits silently.

2. **Counting Emails**: It totals up the number of emails from both files, preparing to consolidate them.

3. **Preparing Space**: If there are emails in either file, it makes room to gather all emails from both into one combined space.

4. **Combining Emails**: The method then brings all emails together. It starts with emails from the current object, followed by those from the provided object, assembling them into one comprehensive list.

5. **Cleaning Up**: It discards the previous, separate lists since they've been merged into a larger, unified one.

6. **Handling File Name**: If a specific name is provided (meaning the second argument isn't **nullptr**), it renames the file accordingly. Otherwise, it retains the original name.

7. **Saving**: To finalize, it saves the unified list of emails under the designated file name (whether original or newly assigned) to preserve the merged data.

#### view (already implemented) 
```C++
std::ostream& view(std::ostream& ostr) const;
```
This method accepts an **ostream** object by reference as an input argument. If the file is valid, it initiates the output by displaying the filename, underlined for emphasis. Subsequently, the method iterates through each email record within the object.

### Insertion helper operator overload
#### operator<< (already implemented)
```C++
std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);
```
Uses the **view()** method to print the EmailFile. 

## Tester Program

[main.cpp](lab/main.cpp).

## Execution Sample

[Output Sample(correct_output.txt)](lab/correct_output.txt)

## PART 1 Submission (lab)
### Files to submit:  
```Text
EmailFile.h
EmailFile.cpp
main.cpp
```
#### Custom code submission

If you have any additional custom code, (i.e. functions, classes etc) that you want to reuse in this workshop save them under a module called Utils (`Utils.cpp and Utils.h`) and submit them with your workshop using the instructions in the "[Submitting Utils Module](#submitting-utils-module)" section.

### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account
- replace `profname.proflastname` with your professor’s Seneca userid
- replace **??** with your subject code (2**00** or 2**44**)
- replace **#** with the workshop number
- replace **X** with the workshop part number (**1** or **2**) 
```text
~profname.proflastname/submit 2??/w#/pX
```
and follow the instructions.

#### Submitting Utils Module
To have your custom Utils module compiled with your workshop and submitted, add a **u** to the part number of your workshop (i.e **u**p1 for part one and **u**p2 for part two) and issue the following submission command instead of the above:
```text
~profname.proflastname/submit 2??/w#/upX
```
See [Custom Code Submission](#custom-code-submission) section for more detail

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.


# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 2??/wX/pY_sss  <ENTER>
```
- Replace **??** with your subject code (`00 or 44`)
- Replace **X** with Workshop number: [`1 to 10`]
- Replace **Y** with the part number: [`1 or 2`]
- Replace **sss** with the section: [`naa, nbb, nra, zaa, etc...`]

and follow the instructions.

> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
