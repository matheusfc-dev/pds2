# Planetary Defense Simulation

A small C++ console simulation of a military base (`BaseMilitar`) equipped with different types of defenses (`Defesa`) that can be used to attack an incoming enemy and reduce its health.

The project demonstrates polymorphism and inheritance in C++: an abstract base class (`Defesa`) defines a common interface, and concrete defense types (`Canhao`, `CanhaoOrbital`, `LancadorMissil`) implement their own attack behavior.

## Project Structure

| File | Description |
|---|---|
| `Defesa.hpp` / `Defesa.cpp` | Abstract base class for all defenses |
| `Canhao.hpp` / `Canhao.cpp` | A basic cannon defense |
| `CanhaoOrbital.hpp` / `CanhaoOrbital.cpp` | An orbital cannon, a specialization of `Canhao` |
| `LancadorMissil.hpp` / `LancadorMissil.cpp` | A missile launcher defense |
| `BaseMilitar.hpp` / `BaseMilitar.cpp` | Manages a collection of defenses and coordinates attacks |
| `main.cpp` | Reads commands from standard input and drives the simulation |

## Class Overview

### `Defesa` (abstract base class)
Holds the common state and behavior shared by every defense:
- `_id` (`int`): identifier of the defense.
- `_energia` (`double`): current energy available for attacks.
- `_consumirEnergia(double qtd)` (protected): decreases `_energia` by `qtd`, clamped at `0.0`.
- `_getEnergia()` (protected): returns the current `_energia`.
- `atacar(double &danoAcumulado)`: pure virtual method that every subclass must implement, adding damage to `danoAcumulado`.
- Destructor prints a deactivation message with `_id`.

### `Canhao` (inherits from `Defesa`)
- `_intensidade` (`double`): damage dealt per shot.
- `atacar`: if `_getEnergia() >= 10`, consumes 10 energy and adds `_intensidade` to `danoAcumulado`.

### `CanhaoOrbital` (inherits from `Canhao`)
- `_multiplicadorGravitacional` (`double`): multiplier applied to the base cannon's damage.
- `atacar`: calls `Canhao::atacar` to compute the base damage, then multiplies it by `_multiplicadorGravitacional` before adding it to `danoAcumulado`. Also prints `"Ataque Orbital realizado!"`.

### `LancadorMissil` (inherits from `Defesa`)
- `_misseis` (`int`): number of missiles remaining.
- `atacar`: if there is at least one missile (`_misseis > 0`) and energy is sufficient (`_getEnergia() >= 5`), consumes 5 energy, decrements `_misseis`, and adds a fixed `40` damage to `danoAcumulado`.

### `BaseMilitar`
- `_defesas` (`Defesa*[100]`): fixed-size array of pointers to defenses installed in the base.
- `_qtdAtual` (`int`): number of defenses currently added.
- `adicionarDefesa(Defesa* d)`: adds a new defense to `_defesas`.
- `defender(double &saudeInimigo)`: calls `atacar` on every defense, accumulates the total damage, subtracts it from `saudeInimigo`, and prints the enemy's remaining health.
- Destructor: deletes all defenses stored in `_defesas`.

## Building

Compile all `.cpp` files together, for example with g++:

```bash
g++ -std=c++17 -o base_militar main.cpp BaseMilitar.cpp Canhao.cpp CanhaoOrbital.cpp Defesa.cpp LancadorMissil.cpp
```

## Running

```bash
./base_militar
```

The program reads commands from standard input until it receives `s` (stop). Each command line begins with a letter identifying the action, followed by the required parameters:

| Command | Meaning | Parameters (in order) |
|---|---|---|
| `c` | Add a `Canhao` | `id energia intensidade` |
| `o` | Add a `CanhaoOrbital` | `id energia intensidade multiplicadorGravitacional` |
| `m` | Add a `LancadorMissil` | `id energia misseis` |
| `d` | Trigger a defense round | `saudeInimigo` (enemy's current health) |
| `s` | Stop reading input and end the program | — |

### Example

```
c 1 20 5
m 2 10 3
d 100
s
```

This adds a cannon and a missile launcher to the base, then triggers a defense round against an enemy with `100` health, printing the enemy's remaining health after the attack.

## Note

- `BaseMilitar` owns the defenses it stores and is responsible for freeing their memory in its destructor.
