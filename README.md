# CPP-Module-01
Memory Allocation, References, Pointers & Switch Statements
<p>
  <img src="https://img.shields.io/badge/Language-C++98-00599C?logo=c%2B%2B">
  <img src="https://img.shields.io/badge/Focus-Memory%20Ownership-blue">
  <img src="https://img.shields.io/badge/Paradigm-Object%20Oriented-orange">
  <img src="https://img.shields.io/badge/42-Abu%20Dhabi-black">
</p>
---
## Overview

This module focuses on understanding **how memory works in C++** and how design decisions affect object relationships.

Key learning objectives:

* - Stack vs Heap memory allocation
* - Manual memory management (`new` / `delete`)
* - Dynamic arrays (`new[]` / `delete[]`)
* - Pointers vs References
* - Member function pointers
* - File manipulation
* - `switch`-based filtering logic

* All code complies with: c++ -Wall -Wextra -Werror -std=c++98 *.cpp

---

## Memory Model
### Stack Allocation
<pre>
Zombie a("Stacky");
a.announce();
</pre>

<pre>
STACK
-----
a (Zombie object)
</pre>

* ✔ Automatically destroyed when leaving scope
* ✔ No manual memory management required

### Heap Allocation

<pre>
Zombie* b = newZombie("Heapy");
b->announce();
delete b;
</pre>
<pre>
STACK                      HEAP
------                     -------
b  --------------------->  Zombie("Heapy")
</pre>

* ✔ Lives until delete is called
* ✔ Requires manual memory management

---
## ex00 – BraiiiiiiinnnzzzZ

Demonstrates the difference between stack and heap allocation using a simple Zombie class.
Concepts learned:

* Constructor & Destructor behavior
* Manual vs Automatic lifetime management
* Pointer dereferencing (->)

## ex01 – Moar Brainz!
Dynamic allocation of multiple objects using:
<pre>
Zombie* horde = new Zombie[N];
delete[] horde;
</pre>

<pre>
HEAP
------------------------------
[Zombie][Zombie][Zombie][...]
</pre>

* ✔ Proper use of delete[]
* ✔ Initialization of each object

---
## ex02 – HI THIS IS BRAIN
Understanding references and pointers:

<pre>
std::string brain = "HI THIS IS BRAIN";
std::string* stringPTR = &brain;
std::string& stringREF = brain;
</pre>

Memory Representation

<pre>
brain       ----┐
                │
stringREF   ----┘   (same memory location)

stringPTR   → holds address of brain
</pre>

| Pointer  | Reference |
| ------------- |:-------------:|
| Stores address      | Alias     |
| Can be NULL      | Cannot be NULL     |
| Can be reassigned      | Cannot be reseated     |

---
##  ex03 – Unnecessary Violence
Designing object relationships properly.

<pre>
Weapon& _weapon;
</pre>

* ✔ Can start without weapon
* ✔ Can assign weapon later

<pre>
Weapon club
     ↑
     │
 HumanA  (reference - permanent link)

 HumanB  (pointer - optional link)
</pre>
---
## ex04 – Sed is for Losers
Reimplementation of basic sed behavior.

<pre>
./replace file.txt old new
</pre>

Creates:

<pre>
file.txt.replace
</pre>

* ✔ Safe file handling
* ✔ Manual string replacement (no std::string::replace)
* ✔ Edge case handling (empty s1 prevention)

---
## ex05 – Harl 2.0
Using member function pointers instead of multiple if/else statements.

<pre>
void (Harl::*fptr[4])() = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};
</pre>

Execution:

<pre>
(this->*fptr[i])();
</pre>

Dispatch Table Concept

<pre>
"DEBUG"   → debug()
"INFO"    → info()
"WARNING" → warning()
"ERROR"   → error()
</pre>


* ✔ Clean function dispatch
* ✔ No conditional forest

---
## ex06 – Harl Filter
Filtering complaint levels using switch.

<pre>
switch(index)
{
    case 0:
    case 1:
    case 2:
    case 3:
}
</pre>

Fall-through Behavior

<pre>
Input: WARNING

Output:
[ WARNING ]
[ ERROR ]
</pre>

Execution Flow
<pre>
DEBUG → INFO → WARNING → ERROR
</pre>
