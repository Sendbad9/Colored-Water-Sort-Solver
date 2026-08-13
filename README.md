# Colored Water Sort Solver

A C++ console application that solves the Colored Water Sort Puzzle using Breadth-First Search (BFS).

## Features

- Finds a valid solution.
- Finds the minimum number of moves.
- Detects unsolvable puzzles.
- Uses BFS for shortest-path search.
- Uses visited-state detection to avoid repeated states.

## Project Structure

- `src/main.cpp` - Program entry point and input/output.
- `src/Tube.h/.cpp` - Tube representation and operations.
- `src/Puzzle.h/.cpp` - Puzzle state and move generation.
- `src/Solver.h/.cpp` - BFS solver.
- `tests/` - Sample test cases.

## Input Format

```text
N
C
tube 1
tube 2
...
tube N