````````````````````````````
# Colored Water Sort Solver

A C++ console application that solves the Colored Water Sort Puzzle using Breadth-First Search (BFS).

## Features

- Finds a valid solution.
- Finds the minimum number of moves.
- Detects unsolvable puzzles.
- Uses BFS for shortest-path search.
- Uses visited-state detection to avoid repeated states.
- Supports different numbers of tubes and tube capacities.

## Project Structure

```text
Colored-Water-Sort-Solver/
│
├── src/
│   ├── main.cpp
│   ├── Tube.h
│   ├── Tube.cpp
│   ├── Puzzle.h
│   ├── Puzzle.cpp
│   ├── Solver.h
│   └── Solver.cpp
│
├── tests/
│   ├── test1.txt
│   ├── test2.txt
│   ├── test3.txt
│   ├── test4.txt
│   ├── test5.txt
│   ├── test6.txt
│   └── test7.txt
│
├── README.md
└── .gitignore
````

## Input Format

The program expects:

```text
N
C
tube 1
tube 2
...
tube N
```

Where:

* `N` = number of tubes.
* `C` = capacity of every tube.
* Positive integers represent colors.
* `0` represents an empty position.
* Empty positions must appear at the end of each tube line.

## Output

If a solution exists, the program prints:

```text
Solution found.
Minimum moves: M
1. Tube S1 -> Tube D1
2. Tube S2 -> Tube D2
...
Final state:
Tube 1: [...]
Tube 2: [...]
...
```

If the puzzle cannot be solved:

```text
No solution exists.
```

## Compilation

Using g++:

```bash
g++ src/main.cpp src/Tube.cpp src/Puzzle.cpp src/Solver.cpp -o solver
```

## Running the Program

On Windows PowerShell:

```powershell
Get-Content tests\test1.txt | .\solver.exe
```

For another test:

```powershell
Get-Content tests\test2.txt | .\solver.exe
```

## Testing

The project was tested using seven test cases.

### Test 1

A solvable puzzle based on the project specification example.

Expected result:

```text
Solution found.
Minimum moves: 3
```

### Test 2

A valid puzzle with no possible solution.

Expected result:

```text
No solution exists.
```

### Test 3

An additional unsolvable puzzle.

Expected result:

```text
No solution exists.
```

### Test 4

A puzzle that is already solved.

Expected result:

```text
Solution found.
Minimum moves: 0
```

### Test 5

Tests pouring multiple layers of the same color.

Expected result:

```text
Solution found.
Minimum moves: 2
```

### Test 6

Tests pouring a group of matching top layers into another tube.

Expected result:

```text
Solution found.
Minimum moves: 1
```

### Test 7

Tests pouring multiple matching layers from one tube into another tube.

Expected result:

```text
Solution found.
Minimum moves: 1
```

## Algorithm

The solver uses Breadth-First Search (BFS).

Each puzzle arrangement is treated as a state, and every valid pour creates a new state.

A visited-state set is used to prevent exploring the same state multiple times.

Because every move has the same cost, BFS guarantees that the first solution found uses the minimum possible number of moves.

````
