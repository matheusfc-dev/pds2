# Robot Soccer

A C++ object-oriented simulation of a robot soccer team, where each robot has a 2D position, can move, calculate distances to teammates, find the nearest teammate, and pass the ball.

## 📋 Description

This exercise models a simple robot soccer team using two classes:

- **`Ponto2D`**: represents a 2D point/coordinate and knows how to compute the Euclidean distance to another point.
- **`Robo`**: represents a robot with an id, a position (`Ponto2D`), a ball-possession flag, and an energy level. Robots can move, compute distances to other robots, find their nearest teammate, and pass the ball to the closest teammate.

The `main.cpp` reads the team setup and then processes a sequence of commands from standard input, simulating actions on the team.

## 🗂️ Class overview

### `Ponto2D`
- `Ponto2D(double x = 0.0, double y = 0.0)` — constructor
- `double calcular_distancia(Ponto2D* ponto)` — Euclidean distance to another point

### `Robo`
- `Robo(int id, Ponto2D posicao, bool com_bola)` — constructor (starts with 100.0 energy)
- `void mover(double v, double th, double t)` — moves the robot given speed, angle (radians) and time; consumes energy proportional to distance traveled
- `double calcular_distancia(Robo* robo)` — distance to another robot
- `Robo* determinar_robo_mais_proximo(Robo** time, int n)` — returns the closest teammate (excluding itself)
- `void passar_bola(Robo** time, int n)` — passes the ball to the nearest teammate, if this robot currently has the ball
- `void imprimir_status()` — prints id, position (x, y), ball possession, and energy

## 📥 Input format

```
<num_robos>
<x1> <y1> <com_bola1>
<x2> <y2> <com_bola2>
...
<command stream>
```

- First line: number of robots on the team.
- Next `num_robos` lines: initial `x`, `y` position and whether the robot starts with the ball (`0`/`1`).
- Followed by a stream of single-character commands, each possibly followed by extra arguments:

| Command | Arguments | Action |
|---|---|---|
| `s` | — | Print status of all robots |
| `d` | — | Print pairwise distances between all robots |
| `m` | `idx v th t` | Move robot `idx` with speed `v`, angle `th`, time `t` |
| `p` | `idx` | Print the status of the robot closest to robot `idx` |
| `b` | `idx` | Robot `idx` passes the ball to its nearest teammate |

## 📤 Output

Output depends on the commands processed:
- `s` → one line per robot: `id  x  y  com_bola  energia` (2 decimal places)
- `d` → distances between every pair of robots (including a robot to itself, distance 0)
- `p` → status line of the nearest robot found
- `m` and `b` produce no direct output (they change internal state), except `b` may print a message if the robot has no ball

## 🧠 Key concepts practiced

- Object-oriented programming with structs/classes and header/source separation (`.hpp`/`.cpp`)
- Composition (`Robo` contains a `Ponto2D`)
- Pointers and dynamic memory allocation (`new`/`delete`)
- Arrays of pointers (`Robo* time[]`)
- Passing objects/pointers between methods
- Command-driven simulation loop with `switch`
- Formatted output with `iomanip` (`fixed`, `setprecision`)

## 🛠️ How to compile and run

```bash
g++ -std=c++17 -Wall -o robot_soccer main.cpp Ponto2D.cpp Robo.cpp
./robot_soccer
```

## 📁 Files

| File | Description |
|---|---|
| `main.cpp` | Reads input, sets up the team, and processes commands |
| `Ponto2D.hpp` / `Ponto2D.cpp` | 2D point class with distance calculation |
| `Robo.hpp` / `Robo.cpp` | Robot class with movement, distance, and ball-passing logic |
