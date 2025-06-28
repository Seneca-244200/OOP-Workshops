### Workshop #8: Virtual Functions and Abstract Base Classes

---
> ⚠️ **Before You Begin**
> You **must read and understand** the [Workshop Regulations and Policies](../README.md) before starting this or any other workshop. This document outlines important rules about academic integrity, submission procedures, and expectations.
> These policies apply to **all workshops** in OOP244. If you have already read it once, please ensure you continue to follow its guidelines throughout the course.
---


In this workshop, you will create a hierarchy of classes to practice and understand the role of virtual functions in inheritance.  
The workshop consists of 4 classes:

- **Shape**: Encapsulates a shape that can be drawn on the screen  
  *(An interface, serving as an abstract base class with only pure virtual functions)*

- **LblShape**: Encapsulates a shape that can be labeled  
  *(An abstract base class that represents a labeled shape)*

- **Line**: Encapsulates a horizontal line on a screen with a label  
  *(This concrete class draws a labeled line)*

- **Rectangle**: Encapsulates a rectangle on the screen that can be labeled  
  *(This concrete class draws a rectangle with a label inside)*

### Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- Define pure virtual functions
- Create abstract base classes
- Implement behavior using virtual functions
- Explain the difference between an abstract base class and a concrete class
- Reflect on what you have learned in completing this workshop




# Part 1 - LAB (100%) 
Implement four modules for the following classes: **Shape, LblShape, Line**, and **Rectangle**.

![Classes](images/classes.png)

## 1 - The `Shape` Interface

### Create the following two [Pure Virtual Functions](https://intro2oop.sdds.ca/E-Polymorphism/abstract-base-classes#pure-virtual-function):

> A [pure virtual function](https://intro2oop.sdds.ca/E-Polymorphism/abstract-base-classes#pure-virtual-function) is a virtual function that has no implementation. To indicate that the pure virtual function does not have an implementation, set its prototype to zero (`= 0;`) in the class declaration.

#### `draw`
Define `draw` as a pure virtual function that returns `void` and accepts a reference to an **ostream** object as an argument. This function should not modify the current object (should be a const function).

#### `getSpecs`
Define `getSpecs` as a pure virtual function that returns `void` and accepts a reference to an **istream** object as an argument.

### Destructor
Create a virtual empty destructor for the `Shape` interface.
> This ensures that any dynamically allocated derived class from the `Shape` interface, when pointed to by a base class pointer, will be properly removed from memory when deleted.

### `Shape` Helper Functions
Overload the insertion (`<<`) and extraction (`>>`) operators to work with any `Shape` object using the `draw` and `getSpecs` pure virtual functions. This allows any derived `Shape` object to be written to or read from an **ostream** and **istream**.


## 2 - The `LblShape` Abstract Class (the Labeled Shape class)

Define an abstract class `LblShape` that inherits from the `Shape` interface. This class adds a label to a `Shape`.

The `LblShape` class will implement the pure virtual function **getSpecs** but will not implement **draw**. As a result, it remains an abstract class.

### Private Member Variable
- **m_label**: Add a character pointer member variable named `m_label` and initialize it to `nullptr`. This member variable will be used to hold the dynamically allocated label for the `Shape`.

### Protected Members
- **label()**: Add a query function named `label` that returns an unmodifiable pointer to `m_label`. This function is protected, allowing only descendants of `LblShape` to access the label.

### Public Members
#### Default (No-Argument) Constructor
Sets the `m_label` pointer to `nullptr`. (Note: If `m_label` is already initialized to `nullptr`, no additional action is required.)

#### One-Argument Constructor
Allocates memory large enough to hold the incoming C-string argument and assigns it to `m_label`. Then, copies the C-string argument to the newly allocated memory using `Utils::alocpy()`.

#### Destructor
Deletes the memory allocated for `m_label` to ensure there is no memory leak.

#### Deleted Actions (Rule of three)
Delete the copy constructor and assignment operator to prevent copying or assignment of `LblShape` instances.

#### getSpecs
Override the `Shape::getSpecs` pure virtual function to read a comma-delimited C-string from `istream`:

1. Extract up to 80 characters or until a **','** character is encountered, then ignore the comma. (use `istream::getline()`)
2. Re-allocate memory to hold the extracted C-string and copy it to the newly allocated memory using `Utils::alocpy()`.


## 3 - The `Line` Concrete Class

The `Line` class inherits from `LblShape` to create a horizontal line with a label.

### Private Member Variable
- **m_length**: A member variable to hold the length of the line (number of characters).

### Public Members

#### Default (No-Argument) Constructor
- Initializes `m_length` to zero and invokes the default constructor of the base class.

#### Two-Argument Constructor
- Accepts a `const char*` (label) and an integer (length) as arguments.
- Passes the label to the base class constructor and assigns the integer value to `m_length`.
- If the specified `m_length` is less than the length of the label, `m_length` is set to the length of the label.

#### Destructor
- This class does not require a destructor.

#### getSpecs
- This function overrides the `getSpecs` function of the base class to read comma-separated specifications for the `Line`:

  1. First, calls the base class’s `getSpecs` function to read the label.
  2. Then, reads the value of `m_length` from the `istream` argument.
  3. Ignores the rest of the characters up to and including the newline character (`'\n'`).

#### draw
- This function overrides the `draw` function of the base class to draw a labeled line:

  - If `m_length` is greater than zero and `label()` is not null:
    1. Prints the `label()`, then moves to a new line.
    2. Prints the `=` character repeatedly up to the value of `m_length`.
  - If either condition is not met, the function performs no action.

For example, if the C-string returned by `label()` is `"Separator"` and `m_length` is `40`, the `draw` function should output the following to `ostream`:

```Text
Separator
========================================
```

This section provides detailed instructions for implementing the `Rectangle` class. Here’s a refined version with a few tweaks for clarity and accuracy:

---

## 3 - The `Rectangle` Concrete Class

The `Rectangle` class inherits from `LblShape` to create a rectangular frame with a label inside.

### Private Member Variables
- **m_width**: Holds the width of the rectangular frame  (number of characters);
- **m_height**: Holds the height of the rectangular frame  (number of characters).

### Public Members

#### Default (No-Argument) Constructor
- Initializes `m_width` and `m_height` to zero and invokes the default constructor of the base class.

#### Three-Argument Constructor
- Accepts a `const char*` for the label, an integer for width, and an integer for height.
- Passes the label to the base class constructor and assigns the width and height values to `m_width` and `m_height`.
- If `m_height` is less than 3, set `m_height` to 3.
- If `m_width` is less than the length of `label() + 2`, set `m_width` to `label() + 2`.

#### Destructor
- This class does not require a destructor.

#### getSpecs
- This function overrides the `getSpecs` function of the base class to read comma-separated specifications for the `Rectangle`:

  1. Calls the base class’s `getSpecs` function to read the label.
  2. Reads `m_width` from `istream`, skips the comma, and reads `m_height`.
  3. Ignores the rest of the characters up to and including the newline character (`'\n'`).

#### draw
- This function overrides the `draw` function of the base class. If the rectangle is not empty (i.e., `m_width` > 0 and `m_height` > 0), it will draw the frame with the label inside. If either dimension is zero, the function performs no action.

  - **First Line**: Prints `+`, followed by `m_width - 2` `-` characters, then `+` again, and moves to a new line.
  
  - **Second Line**: Prints `|`, followed by `label()` left-justified within `(m_width - 2)` spaces, followed by `|`, and moves to a new line.
  
  - **Next `(m_height - 3)` Lines**: Prints `|`, fills `(m_width - 2)` spaces, then prints `|`, and moves to a new line.
  
  - **Last Line**: Exactly like the first line, prints `+`, followed by `m_width - 2` `-` characters, and then `+`.



For example, if the `label()` returns `"Container"`, `m_width` is 30, and `m_height` is 5, the `draw` function should output:

```Text
+----------------------------+
|Container                   |
|                            |
|                            |
+----------------------------+
```

> You could use `ostream::width()` and `ostream::fill()` to set the width and fill characters effectively, allowing you to print the rectangle with only one loop for the empty lines:

```Text
Using width and fill:
- Print the first line
- Print the label left justified between two `|` characters in the second line
- Use a loop to print the empty lines
- Complete the rectangle by printing the last line
```



## The tester program.
[main.cpp](lab/main.cpp)

## Expected output
[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)
Files to submit:  
```Text
Shape.h
Shape.cpp
LblShape.h
LblShape.cpp
Line.h
Line.cpp
Rectangle.h
Rectangle.cpp
main.cpp
```
### Data Entry

Follow the instructions of the unit test.

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



# DIY  

No DIY this time!

Work on your project code instead.
