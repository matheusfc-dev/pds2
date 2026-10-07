
# 🚘 ManyVision

### Geometric Analysis Core for Autonomous Perception

---

## 📌 About the Project

**ManyVision** is a geometric analysis core developed in **C++** to simulate part of an autonomous vehicle perception system.

The system works with geometric shapes that represent obstacles, occupied areas, and risk zones detected in the environment.

The application can store, query, sort, filter, and analyze different shapes using **Object-Oriented Programming** concepts and features from the **STL**.

---

## ✨ Features

- 🔵 Add circles
    
- 🟩 Add rectangles
    
- 🔺 Add triangles
    
- 📋 List stored shapes
    
- 📐 Calculate total area
    
- 📊 Sort shapes by area
    
- 🔎 Filter shapes by minimum area
    
- 🔢 Count shapes by type
    
- 🧮 Retrieve unique areas
    
- 🧹 Dynamically release allocated memory
    
- 🚘 Check whether the environment is traversable
    

---

## 🧠 Concepts Applied

This project explores important C++ concepts such as:

- Object-Oriented Programming
    
- Inheritance
    
- Polymorphism
    
- Abstract classes
    
- Virtual methods
    
- Static methods
    
- Operator overloading
    
- Base class pointers
    
- Dynamic memory allocation
    
- Virtual destructors
    
- STL
    

Some of the main containers and algorithms used are:

```
std::vector
std::map
std::set

std::sort
std::accumulate
std::copy_if
std::for_each
```

---

## 🏗️ Architecture

The abstract class `Shape` defines the common interface for all geometric shapes.

```
                    Shape
                      │
          ┌───────────┼───────────┐
          │           │           │
       Circle      Rectangle    Triangle
```

Each derived class implements:

```
virtual std::string name() const = 0;
virtual double area() const = 0;
```

This makes it possible to store different object types in a single structure:

```
std::vector<Shape*> shapes;
```

and use **polymorphism** to access their behavior through the base class.

---

## 📐 Geometric Shapes

### 🔵 Circle

Represented by its radius.

```
A = pi * r^2
```

---

### 🟩 Rectangle

Represented by width and height.

```
A = width * height
```

---

### 🔺 Triangle

Represented by its three sides.

Its area is calculated using Heron's formula:

```
s = (a + b + c) / 2

A = sqrt(s * (s-a) * (s-b) * (s-c))
```

---

## 🧰 ShapeFunctions

The `ShapeFunctions` class groups the analysis operations used by the system.

|Method|Description|
|---|---|
|`printShapes()`|Prints all stored shapes|
|`totalArea()`|Calculates the total occupied area|
|`getShapesWithAreaGreaterThan()`|Filters shapes by area|
|`sortShapesByArea()`|Sorts shapes by increasing area|
|`countShapesByName()`|Counts shapes by type|
|`uniqueAreas()`|Returns distinct areas|
|`verificarTraversable()`|Checks the free area of the environment|

---

## ⌨️ Commands

The program operates through standard input.

|Command|Description|
|---|---|
|`CIRCLE R`|Adds a circle|
|`RECT W H`|Adds a rectangle|
|`TRIANGLE A B C`|Adds a triangle|
|`LIST`|Lists all shapes|
|`TOTAL`|Displays the total area|
|`SORT`|Sorts shapes by increasing area|
|`FILTER X`|Displays shapes with area greater than `X`|
|`COUNT`|Counts shapes by type|
|`UNIQUE`|Displays unique areas|
|`CLEAR`|Removes all stored shapes|
|`TRAVERSABLE A T`|Checks whether the environment is traversable|

---

## 🚘 Traversability

The traversability check considers the total environment area, the area occupied by the shapes, and a safety tolerance.

```
area_livre = area_ambiente - area_dos_obstaculos
```

The environment is considered traversable when:

```
area_livre > tolerancia
```

Example:

```
Ambiente trafegavel. Area livre: 40.90
```

or:

```
Ambiente nao trafegavel. Area livre insuficiente: 20.90
```

The output messages remain in Portuguese because they are part of the program's defined interface.

---

## ▶️ Usage Example

### Input

```
CIRCLE 5.0
RECT 10.0 2.0
TRIANGLE 3.0 4.0 5.0
LIST
TOTAL
SORT
TRAVERSABLE 150.0 30.0
```

### Output

```
Circulo com area 78.54
Retangulo com area 20.00
Triangulo com area 6.00
Total: 104.54
Triangulo com area 6.00
Retangulo com area 20.00
Circulo com area 78.54
Ambiente trafegavel. Area livre: 45.46
```

---

## 📁 Project Structure

```
ManyVision/
├── main.cpp
├── shape.hpp
├── circle.hpp
├── circle.cpp
├── rectangle.hpp
├── rectangle.cpp
├── triangle.hpp
├── triangle.cpp
├── shapeFunctions.hpp
├── shapeFunctions.cpp
└── README.md
```

---

## ⚙️ Compilation

Compile all `.cpp` files:

```
g++ *.cpp -o manyvision
```

Run the program:

```
./manyvision
```

---

## 💾 Memory Management

The shapes are dynamically allocated and stored using pointers to the base class:

```
std::vector<Shape*> shapes;
```

Example:

```
shapes.push_back(new Circle(5.0));
```

Since the objects are allocated using `new`, their memory must be explicitly released:

```
for (Shape* shape : shapes) {
    delete shape;
}

shapes.clear();
```

The destructor of `Shape` is virtual to ensure derived objects are properly destroyed through base class pointers.

---

## 🛠️ Technologies

<div align="center">

|Technology|Usage|
|---|---|
|**C++**|Main programming language|
|**STL**|Containers and algorithms|
|**G++ / GCC**|Compilation|
|**Git / GitHub**|Version control|

</div>

---

## 🎯 Goal

This project was developed to strengthen core **Object-Oriented Programming concepts in C++**, especially inheritance and polymorphism, while also practicing the use of containers and algorithms from the **Standard Template Library**.

<div align="center">

### C++ • OOP • STL • Polymorphism

</div>