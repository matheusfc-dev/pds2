# Priority Queue with Linked Lists

Exercise for the **PDS2** course, implementing a basic Priority Queue using the Linked List concept (manually implemented, without using ready-made STL containers).

## Description

The program simulates process control in an operating system, where each process has a priority (LOW, MEDIUM or HIGH) and is inserted into a queue ordered in **descending** order of priority. In case of a tie, insertion order is respected (FIFO within the same priority level).

## Implemented ADTs

### `Processo`

| Attribute | Type | Description |
|---|---|---|
| `_id` | `int` | Unique identifier, assigned sequentially by the queue |
| `_nome` | `std::string` | Process name |
| `_prioridade` | `int` | LOW (0), MEDIUM (1) or HIGH (2) |

**Main methods:**
- `getID()`, `getPrioridade()`, `getNome()` — getters for the attributes
- `tempo_reservado_processo()` — returns the execution time reserved according to priority (LOW = 0.5s, MEDIUM = 1.5s, HIGH = 3.0s)
- `imprimir_dados()` — prints `id`, `nome` and priority (spelled out) separated by tabs

### `FilaProcessos`

Linked list that stores processes in descending order of priority.

**Main methods:**
- `adicionar_processo(nome, prioridade)` — inserts a new process at the correct position, assigning a sequential `id` (starting at 1)
- `remover_processo_maior_prioridade()` — removes and returns the process at the front of the queue (highest priority); `nullptr` if the queue is empty
- `remover_processo_por_id(id)` — removes and returns the process with the given `id`; `nullptr` if not found
- `estimativa_tempo_para_execucao(id)` — prints the estimated waiting time, summing the reserved time of all processes ahead of the given one
- `imprimir_fila()` — prints all processes in the queue, from front to back

## Input commands (`main.cpp`)

| Command | Effect |
|---|---|
| `a name priority` | Adds a new process to the queue |
| `r` | Removes the highest-priority process (oldest in case of a tie) |
| `i id` | Removes the process with the given `id` |
| `p` | Prints the current state of the queue |
| `e id` | Prints the estimated waiting time for the process with the given `id` |
| `b` | Runs `avaliacao_basica()`, defined in `avaliacao_basica_controle.hpp` |

## File structure

```
.
├── Processo.hpp
├── Processo.cpp
├── FilaProcessos.hpp
├── FilaProcessos.cpp
├── main.cpp
└── avaliacao_basica_controle.hpp
```

## Build

```bash
g++ -o programa main.cpp Processo.cpp FilaProcessos.cpp
```

## Run

```bash
./programa < input.txt
```

## Implementation notes

- No built-in container from the language (such as `std::list`, `std::queue`, etc.) is used to store or manipulate the processes — the linked list is implemented manually through each `Processo`'s `next` pointer.
- Local variables follow a naming convention with two trailing underscores (`nome__`, `atual__`, etc.).
- Removed processes are not deallocated from memory, as specified in the assignment.
