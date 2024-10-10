# Iterative Deepening A* (IDA*) Algorithm

This project implements the Iterative Deepening A* (IDA*) algorithm for pathfinding on a 2D grid. It includes ASCII visualisation of the search process.

## Requirements

- C++23 compatible compiler
- CMake (version 3.12 or higher)

## Building the Project

To build the project, follow these steps:

1. Create a build directory:
   ```
   mkdir build
   cd build
   ```

2. Run CMake:
   ```
   cmake ..
   ```

3. Build the project:
   ```
   cmake --build .
   ```

## Running the Program

After building, you can run the program from the build directory:

```
./ida_star
```

The program will display an ASCII visualisation of the pathfinding process on a 10x10 grid.

## Project Structure

- `main.cpp`: Contains the main function and program entry point.
- `ida_star.hpp` / `ida_star.cpp`: Implementation of the IDA* algorithm.
- `point.hpp`: Definition of the Point structure.
- `visualization.hpp` / `visualization.cpp`: Functions for ASCII visualisation of the grid.

## Customisation

You can modify the grid size, obstacles, start point, and goal point in the `main.cpp` file to experiment with different scenarios.
