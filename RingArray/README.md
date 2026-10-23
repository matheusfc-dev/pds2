# RingArray — Generic Circular Buffer in C++

A generic **circular buffer (ring array)** implementation in C++ using templates, operator overloading, and the Standard Template Library (STL).

This project demonstrates how to build a fixed-capacity data structure that efficiently manages elements in circular order. When the buffer reaches its maximum capacity, inserting a new element automatically overwrites the oldest one.

The implementation supports primitive data types such as `int`, `float`, and `double`, as well as custom objects through a template-based design.

## Features

- **Generic implementation:** Supports multiple data types using C++ templates.
- **Fixed capacity:** Allocates a predefined number of elements during initialization.
- **Circular indexing:** Uses modular arithmetic to manage element positions.
- **Automatic overwriting:** Replaces the oldest element when the buffer is full.
- **FIFO removal:** Removes elements in First-In, First-Out order.
- **Element access:** Retrieves elements relative to the oldest element.
- **Maximum value retrieval:** Finds the largest element using the `>` operator.
- **Custom object support:** Demonstrates operator overloading with the `Item` class.
- **Header-only implementation:** Both class declarations and implementations are contained in `.hpp` files.

## Project Structure

```text
RingArray/
├── main.cpp           # Main program and test cases
├── ringArray.hpp       # Generic circular buffer implementation
├── item.hpp            # Custom Item class and operator overloads
└── README.md           # Project documentation
```

## Technologies and Concepts

- **Language:** C++
- **Standard:** C++11 or later
- **Libraries:** `<vector>`, `<iostream>`
- **Concepts:**
  - Templates and generic programming
  - Object-Oriented Programming (OOP)
  - Operator overloading
  - Friend functions
  - Constructor initialization lists
  - Circular data structures
  - Modular arithmetic
  - FIFO (First-In, First-Out)
  - Standard Template Library (STL)

## Class Overview

### 1. RingArray\<T>

`RingArray<T>` is a generic class that implements a fixed-capacity circular buffer.

It uses a `std::vector<T>` internally to store elements while maintaining the positions of the oldest and newest elements.

**Private Attributes**

| Attribute | Type | Description |
|---|---|---|
| `_buffer` | `std::vector<T>` | Stores the elements |
| `_capacidade` | `int` | Maximum buffer capacity |
| `_tamanho` | `int` | Current number of elements |
| `_head` | `int` | Index of the oldest element |
| `_tail` | `int` | Index of the newest element |

**Public Methods**

| Method | Description |
|---|---|
| `RingArray(int capacidade)` | Initializes the buffer with a fixed capacity |
| `void push(T item)` | Inserts an element, overwriting the oldest when full |
| `T get(int index)` | Retrieves an element using its logical index |
| `T pop()` | Removes and returns the oldest element |
| `void print()` | Prints all current elements in logical order |
| `T get_maior()` | Returns the largest element |
| `int size()` | Returns the current number of elements |
| `bool is_empty()` | Checks whether the buffer is empty |
| `bool is_full()` | Checks whether the buffer is full |

### 2. Item

The `Item` class represents a custom object containing two integer attributes: a key and a value.

It demonstrates how operator overloading allows custom objects to work with generic data structures.

**Private Attributes**

| Attribute | Type | Description |
|---|---|---|
| `_key` | `int` | Item identifier |
| `_val` | `int` | Item value used for comparisons |

**Constructors**

```cpp
Item();
Item(int key, int val);
```

**Overloaded Operators**

The output operator `<<` allows `Item` objects to be printed directly.

```cpp
Item item(1, 100);
std::cout << item;
```

Output:

```text
(1,100)
```

The comparison operator `>` compares objects based on their `_val` attribute, rather than their keys.

```cpp
Item a(1, 50);
Item b(2, 100);

std::cout << (b > a); // 1 (true)
```

Both operators are implemented as `friend` functions, allowing them to access private attributes.

## How the Circular Buffer Works

A circular buffer uses a fixed-size array where the last position is logically connected to the first.

Consider a buffer with capacity 3.

**Step 1 — Insert three elements**

```cpp
RingArray<int> ringArray(3);

ringArray.push(10);
ringArray.push(20);
ringArray.push(30);
```

Buffer representation:

```text
Index:       0     1     2
           +----+----+----+
Buffer:    | 10 | 20 | 30 |
           +----+----+----+
             ^         ^
            head      tail
```

The buffer is now full.

**Step 2 — Insert another element**

```cpp
ringArray.push(40);
```

Since the buffer is full, the oldest element (`10`) is overwritten.

```text
Index:       0     1     2
           +----+----+----+
Buffer:    | 40 | 20 | 30 |
           +----+----+----+
             ^     ^
            tail  head
```

Although the physical storage order is `[40, 20, 30]`, the logical order is:

```text
20 -> 30 -> 40
```

Calling:

```cpp
ringArray.print();
```

Produces:

```text
20
30
40
```

**Step 3 — Remove the oldest element**

```cpp
int removed = ringArray.pop();
```

The operation returns `20` and advances the head.

The remaining logical elements are:

```text
30 -> 40
```

### Circular Indexing

The implementation uses the modulo operator (`%`) to ensure indexes wrap around the buffer.

For example, retrieving an element uses:

```cpp
(_head + index) % _capacidade
```

This translates a logical index into the appropriate physical position.

The same approach is used when advancing the head or updating the tail.

## Usage Examples

### Example 1 — Integer Buffer

```cpp
#include <iostream>
#include "ringArray.hpp"

int main() {
    RingArray<int> ringArray(4);

    ringArray.push(10);
    ringArray.push(20);
    ringArray.push(30);

    ringArray.print();

    std::cout << "Size: " << ringArray.size() << "\n";
    std::cout << "Max: " << ringArray.get_maior() << "\n";

    return 0;
}
```

Output:

```text
10
20
30
Size: 3
Max: 30
```

### Example 2 — Floating-Point Buffer

```cpp
RingArray<float> ringArray(3);

ringArray.push(1.5f);
ringArray.push(2.5f);
ringArray.push(3.5f);

std::cout << ringArray.get_maior() << "\n";
std::cout << ringArray.is_full() << "\n";
```

Output:

```text
3.5
1
```

### Example 3 — Custom Item Objects

```cpp
#include <iostream>
#include "ringArray.hpp"
#include "item.hpp"

int main() {
    RingArray<Item> ringArray(3);

    ringArray.push(Item(1, 50));
    ringArray.push(Item(2, 100));
    ringArray.push(Item(3, -20));

    std::cout << "Largest: "
              << ringArray.get_maior() << "\n";

    std::cout << "Removed: "
              << ringArray.pop() << "\n";

    ringArray.print();

    return 0;
}
```

Output:

```text
Largest: (2,100)
Removed: (1,50)
(2,100)
(3,-20)
```

The `get_maior()` method works with `Item` objects because the class implements the `>` operator.

## Compilation and Execution

### Requirements

- A C++11-compatible compiler (GCC, Clang, or equivalent)
- A terminal or command-line environment

### Compile

Using `g++`:

```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o ringarray
```

### Run

On Linux or macOS:

```bash
./ringarray
```

The provided `main.cpp` reads an integer from standard input to select a test case.

For example:

```bash
echo 1 | ./ringarray
```

Executes test case 1.

Alternatively, execute the program and enter a test number from 1 to 10.

## Test Cases

The provided `main.cpp` contains 10 test scenarios covering the main features of the implementation.

| Test | Description |
|---|---|
| `t1()` | Basic insertion and printing of integers |
| `t2()` | FIFO element removal |
| `t3()` | Automatic overwriting in a buffer with capacity 1 |
| `t4()` | Element access using `get()` |
| `t5()` | Maximum element retrieval |
| `t6()` | Circular indexing after overwriting elements |
| `t7()` | Full-buffer verification using floating-point numbers |
| `t8()` | Insertion, removal, comparison, and printing of `Item` objects |
| `t9()` | Multiple removals, size verification, and access using `Item` |
| `t10()` | Circular overwriting and access with custom objects |

These scenarios exercise the template implementation using both primitive data types and user-defined objects.

**Note:** The assignment specifies that `get()` receives a valid logical index. Some provided test cases use indexes outside that range, so their behavior depends on how such accesses are interpreted by the test requirements.

## Design Decisions

### Header-Only Template Implementation

The `RingArray<T>` class is entirely implemented in `ringArray.hpp`.

C++ templates generally require their definitions to be visible when instantiated with a specific type. Keeping the template implementation in the header allows the compiler to generate the necessary code for `int`, `float`, `double`, and `Item` without separate explicit instantiations.

### Generic Programming

The same `RingArray<T>` implementation can store different types without rewriting its methods.

For example:

```cpp
RingArray<int> integers(10);
RingArray<double> decimals(10);
RingArray<Item> items(10);
```

The compiler generates the appropriate template instantiations based on the types used.

### Operator Overloading

Instead of introducing special logic for custom objects, the `Item` class overloads the operators required by the generic buffer.

- `operator<<` enables printing with `std::cout`.
- `operator>` enables comparisons in `get_maior()`.

This allows `RingArray<T>` to remain independent of the internal structure of `Item`.

### Fixed-Capacity Storage

The internal vector is allocated during construction:

```cpp
_buffer(capacidade)
```

The buffer reuses those positions as elements are inserted and removed, avoiding the need to grow the vector during normal operations.

### FIFO Behavior

The oldest element is always identified by `_head`.

Calling `pop()` retrieves this element, advances `_head`, and decreases `_tamanho`.

When the buffer is full, `push()` overwrites the oldest element and updates the circular indexes.

## Time Complexity

Assuming constant-time element copying, comparison, and output operations:

| Operation | Time Complexity |
|---|---|
| `push()` | O(1) |
| `get()` | O(1) |
| `pop()` | O(1) |
| `size()` | O(1) |
| `is_empty()` | O(1) |
| `is_full()` | O(1) |
| `get_maior()` | O(n) |
| `print()` | O(n) |

Where `n` represents the current number of elements.

**Space Complexity:** O(C), where C is the fixed buffer capacity.

## Limitations

The implementation follows the assignment's assumptions:

- Buffer capacity must be positive.
- `pop()` and `get_maior()` require a non-empty buffer.
- `get()` is intended to receive a valid logical index.
- Elements must support the operations used by the respective methods, such as comparison (`>`) and output (`<<`).
- This implementation is not designed for concurrent access from multiple threads.

## Educational Objectives

This project was developed as a practical C++ exercise to reinforce:

1. Understanding templates and generic classes.
2. Implementing custom data structures using the STL.
3. Applying operator overloading to user-defined types.
4. Managing circular indexes through modular arithmetic.
5. Working with constructors and object initialization.
6. Understanding FIFO behavior and fixed-capacity storage.
7. Separating class interfaces and implementations while following C++ template requirements.

---

**Developed as part of an Object-Oriented Programming exercise in C++.**
