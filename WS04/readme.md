## Workshop #4: Member Operators and Helper Functions
V0.9 (being reviewed)

In this workshop, you will implement different types of member operator overloads in a partially developed class.

---
> ⚠️ **Before You Begin**
> You **must read and understand** the [Workshop Regulations and Policies](../README.md) before starting this or any other workshop. This document outlines important rules about academic integrity, submission procedures, and expectations.
> These policies apply to **all workshops** in OOP244. If you have already read it once, please ensure you continue to follow its guidelines throughout the course.
---

### Learning Outcomes

Upon successful completion of this workshop, you will be able to:

* Define and implement binary member operators.
* Define and implement type conversion operators.
* Define and implement unary member operators.
* Define and implement the subscript (index) operator.
* Use `*this` to return the current object from member functions.

---

## Part 1 — LAB (100%): The Account Module

Your task for this lab is to complete the implementation of the **Account** module, which models a bank account with an account number (an integer), a balance (a double value), and the account holder’s name (a character array).

## The Account Class

The **Account** class has three attributes:

* A C-string (up to 30 characters) for the name of the account holder (`m_holderName`).
* An integer for the account number (`m_number`).
* A double for the balance of the account (`m_balance`).

The **Account** class can be in three different states:

* **Invalid Empty State**
  An account is in an **invalid** state if invalid information is provided. In this case, the account number is set to **-1**, the balance is set to **0.0**, and the account holder name is set to an empty string. When in this state, the account object is rendered inactive and cannot be used anymore.

* **New**
  An account is considered **new** (or **not set**) when it is just created and the account number has not yet been assigned. This state is indicated by setting the account number (`m_number`) to **0**, while the account holder name (`m_holderName`) is set to a valid name.

* **Valid**
  An account is considered **valid** if it has a 5-digit integer account number, a non-negative balance, and a non-empty C-string for the account holder name.


Here’s a polished version of the section you provided, with corrected grammar, spelling, and improved readability:

---

## Already Implemented Parts

### Constructors

The **Account** can be created in two different ways:

* **One-argument constructor** *(implemented)*

  ```c++
  Account(const char* holderName);
  ```

  This constructor sets the account as **new**, with a balance of **0.0**.

* **Three-argument constructor** *(implemented)*

  ```c++
  Account(const char* holderName, int number, double balance);
  ```

  This constructor sets the account holder’s name, the account number, and the balance to the provided values, but only if all values are valid. If an invalid or empty C-string is provided, or if an invalid account number or a negative balance is passed to the constructor, the object is set to the invalid empty state.

---

### `display` Function

```c++
ostream& display() const;
```

Displays the account information on the screen.

* If the account is invalid, it prints **Bad Account**.
* If the account is new, it prints **New** instead of the account number.
* The function returns the `cout` object to allow chaining.

---

## To Be Implemented

### Type Conversion Member Operators

* **`operator bool`**
    
   Returns `true` if the account is **valid**; otherwise, returns `false`. This operator does not modify the **Account** object.

* **`operator int`**

   Returns the **account number**. This operator does not modify the **Account** object.

* **`operator double`**
  
   Returns the **balance value**. This operator does not modify the **Account** object.

* **`operator const char*`**
  
   Returns the address of the **account holder’s name**. This operator does not modify the **Account** object.

---

### Subscription (Index) Member Operators

* **`char& operator[](int index);`**
  Returns a reference to the character at the specified `index` in the account holder’s name. This operator allows modification of the character at that position. If the `index` is out of bounds, it should safely handle the request by looping back (e.g., `A[30]` should behave the same as `A[0]`).

* **`const char operator[](int index) const;`**
  Returns a copy of the character at the specified `index` in the account holder’s name. This operator does not allow modification of the character. If the `index` is out of bounds, it should safely handle the request by looping back (e.g., `A[30]` should behave the same as `A[0]`).


---


 
This section is **very well-structured and clear**! I only recommend some **minor edits** for consistency, grammar, and readability—no major changes were needed. Here’s the revised version with slight improvements:

---

### Binary Member Operators

> **Note:** All binary member operators **should not take any action** if the **Account** is in an **invalid** state.

#### Assignment Member Operators

* Overload the **assignment operator** so a **new Account** can be set to an **integer**. This should set the **account number** of the **Account** to the integer value.
  If the integer value is not a valid account number, the object should be set to an **invalid empty state** instead.
  If the account is not new, then this operator should not perform any action.
  In any case, a reference to the **current object** (**Account**) should be returned.

  ```c++
  Account A, B; 
  A = 55555;     // The account number of A will be set to 55555
  B = 555;       // The account B will be set to an invalid state
  B = 66666;     // No action will be taken since B is not new
  A = 66666;     // No action will be taken since A is not new
  ```

* Overload the **assignment operator** so an **Account** can be set to a **double** value. This should set the balance of the Account to the double value if it is not negative.
  An invalid (negative) value should set the Account into the invalid empty state.
  In any case, a reference to the **current object** (**Account**) should be returned.

  ```c++
  Account A("Holder", 77777, 123), B("Holder", 66666, 400);
  A = 333.33;   // A will have a balance of 333.33 dollars
  B = -123;     // B will be set into an invalid empty state
  ```

* Overload the **`+=` operator** to add a double value to an Account. This should act like depositing money into an Account (i.e., the value should be added to the balance).
  If the Account is invalid or the value is negative, no action should be taken.
  In any case, a reference to the **current object** (**Account**) should be returned.

  ```c++
  Account A("Holder", 55555, 400.0), Bad("Holder", 555, -10);
  A += 200.0;    // A will have a balance of 600.0
  Bad += 300.0;  // Nothing will happen since Bad is invalid
  A += -20.0;    // Nothing will happen since the value is negative
  ```

* Overload the **`-=` operator** to reduce an Account’s balance by a double value. This should act like withdrawing money from an Account (i.e., the balance should be reduced by the value).
  If the Account is invalid, the value is negative, or there is not enough money in the Account, no action should be taken.
  In any case, a reference to the **current object** (**Account**) should be returned.

  ```c++
  Account A("Holder", 55555, 400.0), Bad("Holder", 555, -10);
  A -= 150.0;    // A will have a balance of 250.0
  A -= 300.0;    // Nothing will happen since there is not enough money in A
  A -= -20.0;    // Nothing will happen since the value is negative
  Bad -= 20.0;   // Nothing will happen since Bad is invalid
  ```

* Overload the **`<<` operator** (left shift) to move funds from the right Account to the left. After this operation, the balance of the left Account will be the sum of both balances, and the balance of the right Account will be set to zero.
  Funds cannot be moved from an Account to itself, and such cases should perform no action.
  In any case, a reference to the **current object** (**Account**) should be returned.

  ```c++
  Account A("Holder", 55555, 400.0), B("Holder", 66666, 500.0), Bad("Holder", 555, -10);
  A << B;      // A will have a balance of 900.0; B will have a balance of zero
  A << A;      // Nothing will happen
  A << Bad;    // Nothing will happen
  Bad << A;    // Nothing will happen
  ```

* Overload the **`>>` operator** (right shift) to move funds from the left Account to the right. After this operation, the balance of the right Account will be the sum of both balances, and the balance of the left Account will be set to zero.
  Funds cannot be moved from an Account to itself, and such cases should perform no action.
  In any case, a reference to the **current object** (**Account**) should be returned.

  ```c++
  Account A("Holder", 55555, 400.0), B("Holder", 66666, 500.0), Bad("Holder", 555, -10);
  A >> B;      // B will have a balance of 900.0; A will have a balance of zero
  B >> B;      // Nothing will happen
  B >> Bad;    // Nothing will happen
  Bad >> B;    // Nothing will happen
  ```

---


Here’s a polished version of your unary member operators section, with some minor adjustments for clarity, consistent language, and improved readability:

---

### Unary Member Operators

* **`bool operator~() const;`**

  Returns `true` if the Account is **new** or **not set** (i.e., if the **account number** is **zero**); otherwise, returns `false`. This operator does not modify the **Account** object.

* **`operator++` Prefix**

  Adds one dollar to the balance and returns a reference to the **current object** (**Account**).

* **`operator++(int)` Postfix**

  Adds one dollar to the balance and returns a **copy** of the Account **before the change**.

* **`operator--` Prefix**

  Subtracts one dollar from the balance and returns a reference to the **current object** (**Account**).

* **`operator--(int)` Postfix**

  Subtracts one dollar from the balance and returns a **copy** of the Account **before the change**.

---



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

No data entry is needed

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

Add and  commit the `reflect.txt` file to your local workshop repository folder and then push it to GitHub. Then pull it to your Matrix account, and run the submission command from that folder.


# DIY  (Practice only)

No DIY for this workshop