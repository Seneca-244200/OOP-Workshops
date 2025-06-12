# Workshop #5: Helper functions and operators, IO operators and output formatting
* Version (1.0)

---
> ⚠️ **Before You Begin**
> You **must read and understand** the [Workshop Regulations and Policies](../README.md) before starting this or any other workshop. This document outlines important rules about academic integrity, submission procedures, and expectations.
> These policies apply to **all workshops** in OOP244. If you have already read it once, please ensure you continue to follow its guidelines throughout the course.
---

In this workshop, you will complete the implementation of the `Mark` class, which encapsulates a mark for an assessment. Your tasks include adding support for formatted display, developing helper functions to facilitate input and output using `fstream` and `iostream`, and implementing basic arithmetic operations involving primitive types.

---

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the ability to:

* Write helper functions that work with classes
* Overload helper operators to work seamlessly with classes
* Overload insertion and extraction operators for input and output
* Generate formatted text output effectively
* Implement foolproof data entry

---

# Part 1 – LAB (100%)

Study and understand the existing implementation of the `Mark` class. Then, enhance the class by adding the following methods, helper functions, and operator overloads:

---

## `display` Method

This method should:

* Return a reference to an `ostream` object
* Receive an `ostream` reference as a parameter, defaulted to `cout`

### Output Behavior

Depending on the validity and type of the mark, the output should be formatted as follows:

* **If the mark is invalid**:

  * If the type is **GRADE**, print two asterisks: `"**"`
  * Otherwise, print three asterisks: `"***"`

* **If the type is GPA**:

  * Print the `Mark` as a `double` (via casting)
  * Display with **1 digit after the decimal point**
  * Use a **width of 3**

* **If the type is MARK**:

  * Print the `Mark` as an `int` (via casting)
  * Use a **width of 3**
  * **Right-justify** the output
  * Fill unused width with underscores (`'_'`)

* **If the type is GRADE**:

  * Print the `Mark` as a `const char*` (via casting)
  * Use a **width of 3**
  * **Left-justify** the output
  * Fill unused width with spaces

At the end, the function must return the reference to the output stream.

---

## Non-Friend Helper Functions

For all the following helper functions, **do not use the `friend` keyword**.
Use only the public methods and operator overloads provided in the `Mark` class to implement the required functionality.


### `display` Helper Function (non-member)

This helper function:

* Returns a reference to an `ostream` object
* Receives:

  * A constant reference to a `Mark` object
  * A character indicating the desired display type (`MARK`, `GRADE`, or `GPA`)
  * An `ostream` reference (defaulted to `cout`)

#### Output Behaviour

* Always prints the `Mark` object using the `MARK` display type first
* If the specified type is **not** `MARK`, it appends a colon and space, followed by the same `Mark` object displayed in the given type

#### Example:

```cpp
Mark M = 77;
display(M, MARK) << endl;
display(M, GRADE) << endl;
display(M, GPA) << endl <<
   "==============" << endl;
```

**Output:**

```text
_77
_77: B+
_77: 3.1
==============
```

This function is useful for comparing different representations of a mark side by side.

---

### `ostream` Insertion Helper Operator Overload

Overload the insertion operator (`operator<<`) to allow a `Mark` object to be inserted into an `ostream`. This operator should behave exactly like the `display` method of the class.

#### Example:

```cpp
Mark M = 77, G, P;
P = G = M;
cout << M << ": " << G << ", " << P << endl 
     << "===============" << endl;
```

#### Output:

```text
_77: B+ , 3.1
===============
```

This allows seamless output of `Mark` objects using `cout` or any other output stream.

---

### `istream` Extraction Helper Operator Overload

Overload the extraction operator (`operator>>`) to read a `Mark` object from an `istream` in a **foolproof** manner.

The function must ensure the user enters **only an integer between 0 and 100**, with **no trailing non-digit characters**.

Use the following exact error messages for invalid input:

```cpp
"Invalid integer, try again.\n> "
"Invalid trailing characters. Please enter only an integer.\n> "
"Invalid mark. Enter a value between 0 and 100.\n> "
```

---

#### Example:

```cpp
Mark M;
cout << "Please enter the mark:\n> ";
cin >> M;
M = MARK;
cout << "You entered: " << M << endl;
```

#### Output:

```text
Please enter the mark:
> abc
Invalid integer, try again.
> -1
Invalid mark. Enter a value between 0 and 100.
> 101
Invalid mark. Enter a value between 0 and 100.
> 77.0
Invalid trailing characters. Please enter only an integer.
> 77abc
Invalid trailing characters. Please enter only an integer.
> 77
You entered: _77
```

---

#### Hint:

```text
1. Read one integer.
   - If reading fails, it's not a valid integer → flush and retry.
2. If reading succeeds:
   - Read the next character.
     - If it's not a newline, there are trailing characters → flush and retry.
     - If it's a newline, validate that the integer is between 0 and 100.
```

---

### `ifstream` Extraction Helper Operator Overload

Overload the extraction operator (`operator>>`) to read a `Mark` object from an `ifstream` using the following format:

```
mark,type
```

The function should:

* Read an integer value
* ignore the comma
* Then read a single character representing the type (`G`, `M`, or `R`)
* If the stream remains in a good state after the read, update the `Mark` object with the read values
* Return the reference to the input stream


#### File Format Example:

```text
100,M
```


#### Example Usage:

```cpp
ifstream file("marks.csv");
Mark M;
while (file) {
   file >> M;
   if (file)
      cout << M << endl;
}
```

---

#### File Content:

```text
100,M
90,G
70,R
```

---

#### Output:

```text
100
3.6
B
```

---


### Helper `operator+` Overload for `double` and `int` Values

Overload the `operator+` to support arithmetic between a primitive value and a `Mark` object:

* Overload `operator+` so that a `double` can be added to the **raw** `double` value of a `Mark`, returning a `double`
* Overload `operator+` so that an `int` can be added to the **rounded** integer value of a `Mark`, returning an `int`


#### Example:

```cpp
Mark M(77.7);
double r, v = 20.0;
int ir, iv = 20;
r = v + M;        // helper operator+ for double values
ir = iv + M;      // helper operator+ for integer values
cout.precision(1);
cout.setf(ios::fixed);
cout << "double: " << r << endl;
cout << "   int: " << ir << endl;
```


#### Output:

```text
double: 97.7
   int: 98
```

---

### Helper `operator-` Overload for `double` and `int` Values

Overload the `operator-` to support arithmetic between a primitive value and a `Mark` object:

* Overload `operator-` so that a `double` value can be reduced by the **raw** `double` value of a `Mark`, returning a `double`
* Overload `operator-` so that an `int` value can be reduced by the **rounded** integer value of a `Mark`, returning an `int`


#### Example:

```cpp
Mark M(30.7);
double r, v = 99.9;
int ir, iv = 99;
r = v - M;
ir = iv - M;
cout.precision(1);
cout.setf(ios::fixed);
cout << "double: " << r << endl;
cout << "   int: " << ir << endl;
```


#### Output:

```text
double: 69.2
   int: 68
```

---

###

## Friend Helper Functions
In object-oriented programming, **`friend` functions** in C++ are often considered **bad practice** or **something to avoid** for the following reasons:

### **1. Breaks Encapsulation**

* The core principle of OOP is **encapsulation** — keeping data hidden and protected inside objects.
* A `friend` function can **access private and protected members** of a class, **bypassing** the class’s own interface.
* This **violates the idea of data hiding**, making the internal state more exposed than it should be.

### **2. Tight Coupling**

* `friend` functions require **intimate knowledge** of the class internals.
* This creates a **tight coupling** between the class and the friend, making future changes harder and increasing maintenance costs.

### **3. Reduced Reusability and Testability**

* Code that relies on `friend` functions is **harder to reuse** in other contexts because the function is **tailored to internal implementation details**.
* Also, such functions are harder to test in isolation, since they’re dependent on class internals.

### **4. Makes Refactoring Riskier**

* When internal details are exposed to `friend` functions, any change to those internals **requires changes to the friend** as well.
* This makes **refactoring difficult**, especially in large codebases.


### **5. Encourages Procedural Thinking**

* Instead of using **object behavior** through **member functions**, `friend` functions tend to **manipulate objects externally**, which is more procedural than object-oriented.
* This **goes against the OOP paradigm**, where behavior should be encapsulated within the class.

---
---
That said, since we are learning how to program in C++, it’s important to understand the syntax and mechanics of `friend` functions. For this reason, in this workshop, you are asked to create two `friend` helper operator overloads for practice. However, keep in mind that in real-world object-oriented design, the use of `friend` functions should generally be avoided. Instead, access to private members should be managed through well-defined **queries** and **mutators**.

---

### Friend Helper `operator/` Overload for `double` and `int` Values

Overload the `operator/` to support arithmetic between a primitive value and a `Mark` object:

* Overload `operator/` so that a `double` value is divided by the `m_value` of a `Mark`, returning a `double`
* Overload `operator/` so that an `int` value is divided by the **rounded** `m_value` of a `Mark` (casted to `int`), returning an `int`

> ⚠️ These functions must **not** use the public queries of the `Mark` class.
> Instead, they should **directly access** the private member `m_value`, which is allowed because the functions are declared as `friend`.

---

#### Example:

```cpp
Mark M(30.3);
double r, v = 99.9;
int ir, iv = 99;
r = v / M;
ir = iv / M;
cout.precision(1);
cout.setf(ios::fixed);
cout << "double: " << r << endl;
cout << "   int: " << ir << endl;
```

---

#### Output:

```text
double: 3.3
   int: 3
```




## The tester program.
[main.cpp](./lab/main.cpp)

## Expected output

[correct_output.txt](./lab/correct_output.txt)

## LAB Submission (part 1)

### Files to Submit:

```text
Mark.cpp  
Mark.h  
main.cpp  
marks.csv  
```

> **Note:** During submission, `marks.csv` will be replaced with a version containing a much larger dataset.


### Data Entry

```text
> abc
> -1
> 101
> 67.8
> 67abc
> 67
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
No DIY for this workshop



# FYI
### the std::round() function

The `round` function in C++ rounds a floating-point number (like a `double` or `float`) to the **nearest whole number** (integer). Here’s how it works:

* If the fractional part is **0.5 or greater**, it rounds **up** to the next integer.
* If the fractional part is **less than 0.5**, it rounds **down** to the previous integer.

**Notes:**

* The function returns a floating-point value, but you can cast it to an `int` if needed.
* The function is part of the `<cmath>` header.

Here’s an example:

```cpp
#include <iostream>
#include <cmath> // for std::round

int main() {
    std::cout << int(std::round(4.3)) << std::endl; // Outputs: 4
    std::cout << int(std::round(4.5)) << std::endl; // Outputs: 5
    std::cout << int(std::round(-2.7)) << std::endl; // Outputs: -3
    std::cout << int(std::round(-2.3)) << std::endl; // Outputs: -2
}
```

