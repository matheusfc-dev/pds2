# Tic-Tac-Toe

A C++ object-oriented implementation of the classic Tic-Tac-Toe (Jogo da Velha) game for two human players, played on the terminal.

## 📋 Description

This exercise implements a two-player Tic-Tac-Toe game using four classes that separate the board logic, player data, and match/turn control:

- **`Tabuleiro` (Board)**: holds the 3x3 grid, validates and applies moves, checks the game state (ongoing, win, or draw), and prints the board.
- **`Jogador` (Player)**: stores a player's name and symbol (`X` or `O`).
- **`Partida` (Match)**: owns the board and the two players, keeps track of whose turn it is, and drives move execution.
- **`main.cpp`**: runs the game loop, reads moves from the terminal, and announces the winner or a draw.

## 🎮 How to play

1. The program starts a match between two players, "Ana" (`X`) and "Bernardo" (`O`).
2. On each turn, the current board is printed and the active player is prompted for a row and a column (0-indexed, 0 to 2).
3. If the move is valid (inside the board and on an empty cell), it's applied and the turn passes to the other player. Invalid moves print an error message and do not advance the turn.
4. The loop continues until a player wins or the board fills up in a draw, at which point the final board and result are printed.

## 📥 Input

For each turn, two integers separated by whitespace:
```
<linha> <coluna>
```
- `linha` (row) and `coluna` (column) range from `0` to `2`.

## 📤 Output

- The board printed before every move, in the format:
  ```
   X |   | O
  -----------
     | X |  
  -----------
   O |   |  
  ```
- A prompt indicating whose turn it is (name and symbol)
- An error message (`Jogada invalida!`) if the chosen cell is occupied or out of bounds
- At the end: the winner's name and symbol, or `Empate!` (Draw) if the board fills up with no winner

## 🗂️ Class overview

### `Tabuleiro`
- `Tabuleiro()` — initializes an empty 3x3 board
- `bool validaJogada(int linha, int coluna, char simbolo)` — checks if a move is within bounds, uses a valid symbol, and targets an empty cell
- `void fazerJogada(int linha, int coluna, char simbolo)` — applies a validated move to the board
- `char verificarEstadoPartida()` — returns `'X'` or `'O'` if that player won, `'E'` for a draw, or `'P'` if the match is still in progress
- `void imprimir()` — prints the current board

### `Jogador`
- `Jogador(std::string nome, char simbolo)` — constructor
- `std::string getNome() const` / `char getSimbolo() const` — accessors

### `Partida`
- `Partida(Jogador jogador1, Jogador jogador2)` — constructor; starts with `jogador1` as the active player
- `Jogador& getJogadorAtual()` — returns a reference to the current player
- `void executarJogada(int linha, int coluna)` — validates and executes a move for the current player, then switches turns
- `char statusPartida()` — delegates to the board to get the current match state
- `void exibirPartida()` — prints the board

## 🧠 Key concepts practiced

- Object-oriented design with multiple collaborating classes
- Header/source separation (`.hpp`/`.cpp`)
- Composition (`Partida` contains a `Tabuleiro` and two `Jogador` objects)
- Pointers and references (`Jogador*` for the current player, `Jogador&` return types)
- 2D arrays for grid-based state
- Encapsulating game rules and turn logic outside of `main`

## 🛠️ How to compile and run

```bash
g++ -std=c++17 -Wall -o tictactoe main.cpp Partida.cpp Tabuleiro.cpp Jogador.cpp
./tictactoe
```

## 📁 Files

| File | Description |
|---|---|
| `main.cpp` | Game loop: reads moves, drives the match, prints the result |
| `Partida.hpp` / `Partida.cpp` | Match class: turn control and move execution |
| `Tabuleiro.hpp` / `Tabuleiro.cpp` | Board class: grid state, move validation, and win/draw detection |
| `Jogador.hpp` / `Jogador.cpp` | Player class: name and symbol |
