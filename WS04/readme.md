# Workshop #4: Constructors, Destructors, and the this object
* Version 1.0

In this workshop, you will make use of constructors to initialize objects containing both static and dynamic data members as well as destructors to release those resources as the objects go out of scope. There will be use of the current object within the class to modify the state.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- The use of the default and overloaded constructors
- The use of destructors
- The use of the current object within the class's member functions
- The handling of dynamic resources via the constructor and destructor

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

This part of the workshop will involve creating a class called **Fridge** that contains some number of **Food** items up to a maximum capacity.

A Food item is defined by the following struct (see provided Fridge.h/.cpp):

```C++
// Header
#define NAME_LEN 20

  class Food{
    char m_name[NAME_LEN]{};
    int m_weight{};
  public:
    Food();
    Food(const char* nm, int wei);
    const char* name()const;
    int weight()const;
  };

// Implementation
   Food::Food() {}

   Food::Food(const char* nm, int wei){
      strncpy(m_name, nm, NAME_LEN);
      m_weight = wei;
   }
   const char* Food::name() const{
      return m_name;
   }
   int Food::weight() const{
      return m_weight;
   }

```

### Fridge Module

Design and implement a class named `Fridge` that stores the following information:

- A statically allocated array of Food items whose size is defined by the FRIDGE_CAP constant
- An integer representing the number of Food items currently stored by the Fridge
- A dynamic c-style string that represents the model name of the Fridge (Eg. FridgeMaster3000)

A Fridge object can be created in the following ways:

- By default construction where all the data is set to an empty state
- Providing all the data: an array of Food items, the number of Food items in the array and a model name to initialize the data
- Providing partial data: an array of Food items and the number of Food items in the array

A `Fridge` will have the ability to add more Food to itself after construction, change the model name, query for the state of the Fridge as a whole or if a certain Food is present and display to the standard output the details of the current object. Details of these functions will be provided below.

## Implementation

Define a constant `FRIDGE_CAP` to represent the maximum amount of Food that a Fridge can store (3 items)

Create a class named `Fridge` and have the following members:

### Private Member Variables
```C++
Food m_foods[FRIDGE_CAP]; 
int m_numFoods;
char* m_model;
```

### Constructors/Destructor

```C++
Fridge::Fridge();
```

The default constructor will initialize the data members to an empty state. The m_numFoods will be set to 0 and the m_model set to **nullptr**. The array of Food items will initialized by default from the provided Food struct code.

```C++
Fridge(Food farr[], int nf, const char* mod);
```

The 3-argument constructor will initialize the data members using the provided parameters based on the following process:

- First set the the empty state by utilizing the default constructor and assigning that to the current object
- Validate the parameters by checking if the nf value is greater than 0 and that mod c-string is not nullptr and not the empty string.
- If the above validation succeeds: 
  - set the m_numFoods to the nf value
  - allocate memory to m_model to store the string in the mod value
  - finally loop over the Food array argument (`farr`) and copy each Food to the `m_foods` array up till the `nf` value or the FRIDGE_CAP is met.

The mod parameter will have a default value of "Ice Age".

```C++
Fridge::~Fridge();
```

The destructor will deallocate the dynamic memory held by the m_model data member.

### Public Member Functions

### Modifiers

```C++
bool addFood(const Food& f);
```

This function will attempt to add a Food item to the m_foods array. If the m_numFoods is less than the FRIDGE_CAP then assign the parameter Food item to the m_foods array at the index of m_numFoods. Increment the m_numFoods by 1 to reflect the added Food item.

This function returns true if we have successfully added a Food item and false otherwise.

```C++
void changeModel(const char* m);
```
This function will modify the model_name of the Fridge using the parameter provided if it is valid (ie not nullptr or the empty string).

If it is valid then first deallocate the memory of the m_model then allocate enough memory to store the provided value and copy it to m_model.


### Queries
```C++
bool fullFridge() const; 
```

This function will return whether or not the Fridge is full. A Fridge is considered to be full if m_numFoods has reached FRIDGE_CAP.

```C++
bool findFood(const char* f) const;
```

This function will attempt to determine whether this Fridge holds a particular Food item by comparing its name to the parameter value. If a Food item is found with the same name then return true otherwise return false.

```C++
std::ostream& display(std::ostream& os = std::cout) const;
```

This function will display the details of the Fridge to the ostream parameter named **os**. Instead of printing to cout we will be using this os parameter as the destination (`cout << myvar` vs `os << myvar`). 

If the current object's m_model is in an empty state then this function will not print anything and only return.

Otherwise, print the following:

```Text
Fridge Model: [m_model]<newline>
Food count: [m_numFoods] Capacity: [FRIDGE_CAP]<newline>
List of Foods<newline>
```

If m_numFoods is greater than 0 then loop over the array m_foods and print out each Food item in the following format. The field width for the Food's name should be using the NAME_LEN constant.

```Text
[Food.m_name] | [Food.weight]<newline>
```

This function will return the parameter os.

Refer to the sample output for details on what this will look like.

## Tester Program

[main.cpp](./lab/main.cpp)

## Execution Sample

[correct_output.txt](./lab/correct_output.txt)

## PART 1 Submission (lab)

### Files to submit:  

```Text
Fridge.cpp
Fridge.h
main.cpp
```
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

This part of the workshop will involve creating a class called **Guitar** that has a dynamic number of **Guitar Strings**.

A Guitar String is defined by the following struct (see provided Guitar.h/.cpp):

```C++
// Header
#define MAT_LEN 10;
  class GuitarStr{
    char m_material[MAT_LEN]{}; 
    double m_gauge{};
  public:
    GuitarStr();
    GuitarStr(const char* ma, double ga);
    const char* material()const;
    double gauge()const;
  }; 

// Implementation
   GuitarStr::GuitarStr(){};

   GuitarStr::GuitarStr(const char* ma, double ga){
      strncpy(m_material, ma, MAT_LEN);
      m_gauge = ga;
   }; 
   const char* GuitarStr::material() const{
      return m_material;
   }
   double GuitarStr::gauge() const{
      return m_gauge;
   }
```

### Guitar Module

Design and implement a class named `Guitar` that stores the following information:

- A dynamic array of GuitarStr (m_strings)
- The number of GuitarStr in the array (m_numStrings)
- A model name for the Guitar with a maximum length of 15 characters (m_model)

## Implementation

### Constructors/Destructor

```C++
Guitar(const char* mod);
```

Initializes the current object to an empty state except for the model name which will be initialized by the value of the parameter. The parameter will also have a default value of "Stratocaster".

```C++
Guitar::Guitar(GuitarStr strs[], int ns, const char* mod);
```

The three-argument constructor initializes the data members based on the provided parameters:

- `strs` is an array of GuitarStr that will be used to populate the dynamic array.
- `ns` is the size of the array argument (`strs`)
- `mod` is a model name for the Guitar

If the parameters are not valid the current object is set to an empty state.

```C++
Guitar::~Guitar();
```

The destructor deallocates any resources stored by the current object.

## Public Members

### Modifiers

```C++
bool changeString(const GuitarStr& gs, int sn);
```

This function changes a GuitarStr on the Guitar by passing one in through the parameter `gs`. The `sn` parameter refers to the index in the array (`m_strings`) as to which GuitarStr is going to be changed. If the provided `sn` value is an invalid index for the array then no string change occurs.

This function returns true if a change occurred and false otherwise.

```C++
void reString(GuitarStr strs[], int ns);
```

This function restrings the Guitar with a new set of GuitarStr provided through the parameters (an array of GuitarStr and an integer representing the size of that array). Take note to carefully manage any allocation/deallocation of dynamic memory when replacing the GuitarStr array.

```C++
void deString();
```

This function will de-string the Guitar of all of its GuitarStr. This means to deallocate all resources currently held by the Guitar and to then set the m_numStrings to an empty state.

### Queries
```C++
bool strung() const;
```

This function will return true if the Guitar has GuitarStr and false otherwise.

```C++
bool matchGauge(double ga) const;
```

This function will return true if any GuitarStr on the Guitar has a matching gauge value to the provided parameter and false otherwise.

```C++
std::ostream& display(std::ostream& os = std::cout) const;
```

This function will display the details of a Guitar to the ostream via the parameter os.

If the Guitar is in an empty state print out the following:

```Text
***Empty Guitar***<newline>
```

Otherwise, print out the Guitar details as follows:

```Text
Guitar Model: [m_model]<newline>
Strings: [m_numStrings]<newline>
```

If the Guitar is strung/has GuitarStr then print out each string using this format:

```Text
#1 [string1.m_material] | [string1.gauge]<newline>
#2 [string2.m_material] | [string2.gauge]<newline>
...
```

For the GuitarStr material use a field width of MAT_LEN. For the gauge use 1 decimal place precision.

Return the parameter os at the end of this function regardless of what is printed out.

Refer to the sample output for details on what this will look like.

## Tester Program

[main.cpp](./DIY/main.cpp)

## Execution Sample

[correct_output.txt](./DIY/correct_output.txt)

## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.

You may be asked to talk about your reflection (as a presentation) in class.

## Part 2 Submission (DIY)

### Files to submit:  

```reflect.txt``` and:
```Text
Guitar.cpp
Guitar.h
main.cpp
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



