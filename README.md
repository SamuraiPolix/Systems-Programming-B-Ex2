# Graph Algorithms - C++ Assignment #2
## This is a follow-up assignment, Assignment #1 can be found [here](https://github.com/SamuraiPolix/CPP_EX1/).
#### (Systems Programming B @ Ariel University)
#### Author: Samuel Lazareanu (sam.lazareanu@gmail.com)


[Link to requirements](ASSIGNMENT.md)


## Overview

This C++ assignment extends the capabilities of the `Graph` class from the previous assignment by implementing various arithmetic and comparison operators for graph operations.

The primary goal is to support arithmetic operations like addition, subtraction, multiplication, and division on graphs, along with comparison operations to determine equality and order between graphs.

## Implemented Operators

### Arithmetic Operators

- **Addition (`+`):** Adds two graphs element-wise or adds a scalar value to each edge weight.
- **Subtraction (`-`):** Subtracts one graph from another element-wise or subtracts a scalar value from each edge weight.
- **Multiplication (`*`):** Performs element-wise multiplication of two graphs or multiplies each edge weight by a scalar value.
- **Division (`/`):** Divides one graph by another element-wise or divides each edge weight by a scalar value.

### Comparison Operators

- **Equality (`==`, `!=`):** Determines whether two graphs are equal by comparing their sizes and edge weights.
  
  Graphs G1 and G2 will be called equal if they are of the same order of magnitude and contain the same edges (and the weights of the edges are the same) or if G1 is not greater than G2 and neither is G2 greater than G1.
- **Ordering (`<`, `<=`, `>`, `>=`):** Compares the sizes and edge counts of two graphs to establish an order relationship between them.
  
  Graph G2 is larger than graph G1 if graph G1 is contained exactly in graph G2. If neither graph is exactly contained in the other and the graphs are not equal, then graph G2 is greater than graph G1 if the number of edges in G2 is greater than the number of edges in G1. If the number of edges is the same, then the graph G2 is larger than the graph G1 if the representative matrix of G2 has a higher order of magnitude than G1.

### Increment and Decrement Operators
These operations are done on existing edges only! This won't create new edges with new weights - only modify the existing ones.

- **Prefix (`++`, `--`):** Increments or decrements the edge weights of all edges in the graph by one.
- **Postfix (`++`, `--`):** Increments or decrements the edge weights of all edges in the graph by one, returning the original value before the increment or decrement.

## Implementation Details

- Helper functions are utilized to perform arithmetic operations on the adjacency matrices.
- Comparison operations are facilitated by comparing the sizes and edge weights of graphs.
- The operators are overloaded both as member functions and friend functions to enable seamless usage and access to private members.
- Exception handling is implemented to handle cases such as mismatched graph sizes, or row-col in graph multiplication.

## Usage
A basic usage example can be found inside the Demo.cpp file.

1. Clone the repository.
2. Build the project using the provided 'makefile' and run:
   - `make demo` -     run using `./demo`  (simple test)
   - `make test` -     run using `./test`  (advanced doctest)
   - `make tidy` -     makes sure the code is clean
   - `make valgrind` - makes sure there are no memory leaks/problems.

### Tests
#### clang-tidy and valgrind
Before submitting we ran clang-tidy to make sure the code is written well, and valgrind to make sure there are no memory errors or leaks.

#### Test.cpp
This file includes tests on the operators implemented.

This file also extends the Test.cpp file from the previous assignment, which tested the algorithms implemented. This time, we are testing the algorithms while playing around with the operators to see how they affect the algorithms.

#### personal_test folder
The `personal_test` folder includes the file `visualize_graph.py`, which can be used to visualize graphs and write good tests for them. This Python script complements the C++ implementations by providing a visualization tool.
