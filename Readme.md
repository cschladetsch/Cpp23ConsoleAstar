# IDA* Pathfinding Visualiser

This project implements the Iterative Deepening A* (IDA*) algorithm for pathfinding on a 2D grid. It includes ASCII visualisation of the search process, demonstrating the algorithm's efficiency in both time and space complexity.

## Features

- Efficient IDA* algorithm implementation
- ASCII-based grid visualisation
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

## Contact

If you have any questions or feedback, please open an issue on the GitHub repository.
