# Workshop #10: Function Templates
**Version 1.0**

---
> ⚠️ **Before You Begin**
> You **must read and understand** the [Workshop Regulations and Policies](../README.md) before starting this or any other workshop. This document outlines important rules about academic integrity, submission procedures, and expectations.
> These policies apply to **all workshops** in OOP244. If you have already read it once, please ensure you continue to follow its guidelines throughout the course.
---



In this workshop, you will implement a module called `dynaCopy` containing three function templates. These templates are designed for dynamically copying arrays of objects and printing their contents.

You will use a fully implemented class called `Name` and the `Utils` module provided to assist in completing this workshop.

---

## Learning Outcomes

Upon successful completion of this workshop, you will be able to:

- Write and use function templates to generalize operations on different data types.
- Dynamically manage arrays of objects using templates.
- Understand and implement a header-only module for templates.
- Test and validate template functionality using provided and self-written code.
- Describe what you have learned in completing this workshop.

---



# Part 1 - LAB (100%)
## dynaCopy Module Requirements
Implement the following three function templates in the `dynaCopy` module (header file only).

### 1. **Two-Argument `dynaCopy`**
**Description:**
- This function template dynamically allocates memory for a new array and copies the elements from a given source array into it.

**Parameters:**
1. A constant pointer to the source array. 
   - This ensures the source array is not modified by the function.
   - The type of elements in the source array is generic and determined by the template parameter.
2. An integer representing the size of the source array.
   - This indicates how many elements are in the source array.

**Return Value:**
- A pointer to a dynamically allocated array.
  - The new array contains all the elements from the source array.

---

### 2. **Three-Argument `dynaCopy`**
**Description:**
- This function template dynamically reallocates memory for an existing destination array and copies the elements from a given source array into the destination.

**Parameters:**
1. A reference to a pointer representing the destination array.
   - Since the destination pointer is passed by reference, the function can directly modify the memory it points to.
   - If the destination pointer already points to allocated memory, that memory is first deallocated.
   - The type of elements in the destination array is generic and determined by the template parameter.
2. A constant pointer to the source array.
   - This ensures the source array is not modified.
   - The type of elements in the source array is generic and determined by the template parameter.
3. An integer representing the size of the source array.
   - This indicates how many elements need to be copied into the destination array.

**Return Value:**
- The same pointer passed as the destination, now pointing to newly allocated memory containing the copied elements.


> **Hint:** The two `dynaCopy` function templates are conceptually similar to the two `alocpy` functions in the `Utils` module. However, instead of working exclusively with null-terminated character arrays, the `dynaCopy` templates are designed to handle arrays of any type, given their size.


---

### 3. **`prnArray`**
**Description:**
- This function template prints the elements of an array to the standard output in a single line.

**Parameters:**
1. A constant pointer to the array to be printed.
   - This ensures the array is not modified during the operation.
   - The type of elements in the array is generic and determined by the template parameter.
2. An integer representing the size of the array.
   - This specifies how many elements need to be printed.

**Output Behavior:**
- The elements are printed in order, separated by commas.
- A newline character is added at the end of the output for readability.

**Return Value:**
- This function does not return a value. It simply performs the printing operation.

---

## Provided Code

You are provided with:

1. The `Name` class (implementation details included in the provided code).
2. The `Utils` module for dynamic memory allocation support in the 'Name' class. (you do not need to use it)

Review and understand these files before starting the workshop.

---

### Additional Notes

- **Memory Management:** Be mindful of dynamic memory allocation. Use proper techniques to avoid memory leaks. (deleting pointers before reallcoting memory)
- **Utils Module:** The `Utils` module is used by the `Name` module for memroy management.
- **Generalization:** The function templates should work seamlessly with primitive data types (e.g., `int`) and user-defined types (e.g., `Name`).

---

## The tester program.
[main.cpp](lab/main.cpp)

## Expected output
[correct_output.txt](lab/correct_output.txt)

## LAB Submission (part 1)
Files to submit:  
```Text
Utils.h
Utils.cpp
Name.h
Name.cpp
dynaCopy.h
main.cpp
```
### Data Entry

No data entry needed

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