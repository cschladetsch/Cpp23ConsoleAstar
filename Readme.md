# Iterative Deepening A* (IDA*) Pathfinding Visualiser

This project implements an Iterative Deepening A* (IDA*) algorithm for pathfinding on a 2D grid, including diagonal movements. It features a non-scrolling ASCII visualisation of the search process, demonstrating the algorithm's behavior in both time and space.

## Sample

https://user-images.githubusercontent.com/cschladetsch/IdAstarCpp23/raw/main/path/to/your/video.mp4
https://user-images.githubusercontent.com/cschladetsch/IdAstarCpp23/raw/master/resources/Flamingo.mp4

![anim](resources/Flamingo.mp4)

## Features

- IDA* algorithm implementation
  - Finds a path from start to goal if one exists
  - Supports both cardinal and diagonal movements
  - Uses Euclidean distance heuristic
  - Employs iterative deepening for memory efficiency
- Non-scrolling ASCII-based grid visualisation
- Customisable grid size and obstacles
- Easy-to-use build and run script

## Requirements

- C++23 compatible compiler (gcc or g++ recommended)
- CMake (version 3.12 or higher)
- Bash shell (for running the `./r` script)

## Quick Start

To quickly build and run the project, use the provided `r` script:

1. Ensure the script is executable:
   ```
   chmod +x r
   ```

2. Run the script:
   ```
   ./r
   ```

This script will:
- Remove any existing build directory
- Create a new build directory
- Configure the project with CMake using gcc/g++
- Build the project
- Run the executable

## Manual Build and Run

If you prefer to build the project manually or can't use the `r` script, follow these steps:

1. Create a build directory:
   ```
   mkdir build && cd build
   ```

2. Configure the project:
   ```
   cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
   ```

3. Build the project:
   ```
   cmake --build .
   ```

4. Run the executable:
   ```
   ./ida_star
   ```

## Algorithm Details

The IDA* algorithm implemented in this project works as follows:

1. It starts with an initial bound based on the Euclidean distance heuristic from the start to the goal.
2. It performs a depth-first search, considering both cardinal and diagonal movements.
3. It prunes branches when f(n) = g(n) + h(n) exceeds the current bound.
4. Diagonal movements are assigned a cost of √2, while cardinal movements have a cost of 1.
5. If the goal is not found within the current bound, the bound is increased to the minimum f(n) value that exceeded the previous bound.
6. The search is repeated with the new bound until a path is found or the problem is proven unsolvable.

While this implementation aims to find an efficient path, it may not always guarantee the shortest path in all scenarios. The effectiveness of the algorithm can vary depending on the specific grid configuration and heuristic accuracy.

## Visualisation

The program features a non-scrolling ASCII visualisation of the pathfinding process. The grid is updated in place, providing a real-time view of the algorithm's progress.

- '.' represents open cells
- '#' represents obstacles
- 'S' marks the start point
- 'G' marks the goal point
- 'C' shows the current position being explored
- '*' indicates the path found

## Customisation

You can modify the grid size, obstacles, start point, and goal point in the `main.cpp` file. After making changes, rebuild the project using the `./r` script or by following the manual build steps.

## Project Structure

- `main.cpp`: Contains the main function and program entry point.
- `ida_star.hpp` / `ida_star.cpp`: Implementation of the IDA* algorithm.
- `point.hpp`: Definition of the Point structure.
- `visualisation.hpp` / `visualisation.cpp`: Functions for ASCII visualisation of the grid.
- `r`: Bash script for easy building and running of the project.
- `CMakeLists.txt`: CMake configuration file.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is open source and available under the [MIT License](LICENSE).

## Limitations and Future Improvements

- The current implementation may not always find the optimal path in all scenarios.
- Performance can be improved for larger grids or more complex obstacle patterns.
- The visualisation is basic and could be enhanced for better clarity.

Future work could focus on optimizing the algorithm, improving the heuristic function, and enhancing the visualisation capabilities.

## Contact

If you have any questions, feedback, or suggestions for improvement, please open an issue on the GitHub repository.
