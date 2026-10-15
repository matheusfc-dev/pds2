# 🤖 R2-D2 — Droid System Debugging & Unit Testing

A C++ project focused on **unit testing, debugging, and object-oriented programming (OOP)**, inspired by the Star Wars universe.

## 📌 Overview

After suffering damage during a battle, R2-D2's navigation, energy management, and communication systems began malfunctioning.

The goal of this project is to restore the droid's functionality by identifying and fixing syntax and logic errors, while implementing unit tests to verify the expected behavior of each module.

The project uses **C++** and the **doctest** testing framework to ensure system reliability and correctness.

## ⚙️ Features

The system is divided into three main modules:

### 🔋 Energy Management — `Energia`

Responsible for managing the droid's battery.

- Initializes the battery with a specified charge.
- Tracks the remaining energy.
- Consumes energy during movement.
- Prevents the battery level from dropping below zero.
- Handles invalid energy consumption values.

### 🚀 Navigation — `R2D2`

Controls the droid's position and movement.

- Starts at position `0`.
- Moves forward and backward through a corridor.
- Consumes one energy unit per meter traveled.
- Prevents movement beyond corridor boundaries.
- Detects obstacles and stops before collisions.
- Tracks the remaining battery level.
- Determines whether the droid successfully reaches its destination and returns to its starting position.

### 📡 Communication — `Comunicacao`

Handles mission reports and signal transmission.

- Generates standardized reports containing position, battery level, and mission status.
- Prevents signal transmission when the battery level is below 5 units.
- Reports whether the mission has been completed successfully.

**Report example:**

```text
R2D2 em 5, Bateria: 10%, Missao: Pendente
```

## 📁 Project Structure

```text
.
├── R2D2.hpp
├── R2D2.cpp
├── energia.hpp
├── energia.cpp
├── comunicacao.hpp
├── comunicacao.cpp
├── main.cpp
├── doctest.h
└── README.md
```

## 🧪 Unit Testing

Unit tests are implemented using [doctest](https://github.com/doctest/doctest), a lightweight C++ testing framework.

The tests validate the expected behavior of each module, including normal operations, boundary conditions, and invalid inputs.

**Main testing scenarios:**

- **Energy:** Battery initialization, consumption, and protection against invalid values.
- **Navigation:** Forward and backward movement, corridor limits, obstacle detection, and energy consumption.
- **Communication:** Report formatting, minimum battery requirements, and mission completion status.

The `CHECK(...)` assertions compare actual results against expected values, helping identify incorrect behavior and prevent regressions.

## 🛠️ Technologies

- **Language:** C++
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Testing Framework:** doctest
- **Development Practices:** Unit Testing and Debugging

## 🎯 Learning Objectives

This project provides practical experience with:

- Writing and executing unit tests in C++.
- Identifying and correcting syntax and logic errors.
- Testing edge cases and validating expected behavior.
- Applying encapsulation and class composition.
- Developing reliable and maintainable software.

## 📚 About

Developed as a practical programming exercise focused on software testing and debugging.

The project demonstrates how unit testing can help detect failures, verify correctness, and improve the reliability of interconnected software modules.
