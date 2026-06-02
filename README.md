*This project has been created as part of the 42 curriculum by dcoelho, hede-car.*

# Push_swap

## 1. Description

Push_swap is a sorting algorithm project from the 42 curriculum focused on algorithmic complexity and optimization.

The goal is to sort a stack of integers using only two stacks (`a` and `b`) and a restricted set of operations. The challenge is not only to sort the numbers correctly, but also to minimize the total number of operations generated.

This implementation includes three different sorting algorithms with distinct complexity classes and an adaptive strategie that automatically selects the most appropriate algorithm according to the initial disorder of the input stack.

The project also includes a benchmark mode for performance analysis and a fully functional checker program as a bonus.

### Features

- Parsing of integers from multiple argument formats
- Complete error handling
- Linked-list based stack implementation
- Four sorting strategies:
  * Insertion Sort — O(*n*²)
  * Chunk Sort — O(*n*√*n*)
  * Quick Sort — O(*n*log*n*)
  * Adaptive Strategy
- Disorder metric calculation
- Benchmark mode (`--bench`)
- Bonus checker program
- Memory leak free
- Norm compliant

### Project Structure

The project does not use subdirectories. Files are grouped and numbered according to their purpose:

| Group | Description |
|---------|-------------|
| 0 | General utilities and helper functions |
| 1 | String handling |
| 2 | Parsing and error checking |
| 3 | General algorithm utilities |
| 4 | Insertion Sort implementation |
| 5 | Chunk Sort implementation |
| 6 | Quick Sort implementation |
| 7 | Benchmark system |
| 8 | Bonus (checker) |

Instead of using Libft directly, only the necessary utility functions were integrated into the project source files.

### Data Structures

Stacks are implemented using **linked lists**.

This approach allows efficient insertion and removal of elements from the top of the stack while keeping the implementation close to the stack abstraction required by the subject.

---

## 2. Instructions

Compile the mandatory project:

```bash
make
```

Compile the bonus:

```bash
make bonus
```

Clean object files:

```bash
make clean
```

Remove object files and binaries:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```

### 2.1. Usage

### Default behavior (Adaptive Strategy)

```bash
./push_swap 4 67 3 87 23
```

### Explicit strategy selection

#### Simple Strategy (O(*n*²))

```bash
./push_swap --simple 4 67 3 87 23
```

#### Medium Strategy (O(*n*√*n*))

```bash
./push_swap --medium 4 67 3 87 23
```

#### Complex Strategy (O(*n*log*n*))

```bash
./push_swap --complex 4 67 3 87 23
```

#### Adaptive Strategy

```bash
./push_swap --adaptive 4 67 3 87 23
```

### Benchmark Mode

```bash
./push_swap --bench 4 67 3 87 23
```

Benchmark information is printed to `stderr` and includes:

- Disorder percentage
- Strategy used
- Theoretical complexity
- Total operation count
- Individual operation statistics

## 3. Implementation Details

### 3.1. Accepted Input Formats

The parser accepts both formats required by the project:

```bash
./push_swap 1 2 3 4 5
```

```bash
./push_swap "1 2 3 4 5"
```

### 3.2 Error Handling

The program validates:

- Non-numeric arguments
- Integer overflows
- Duplicate values
- Invalid characters
- Incorrect formatting

In case of error:

```bash
Error
```

is printed to `stderr`.

If no arguments are provided, the program exits silently.

### 3.3. Algorithms

### Disorder Metric

Before selecting a strategy, the program computes the disorder of the input stack.

The disorder metric is defined as:

```text
disorder = mistakes / total_pairs * 100
```

Where:

- `mistakes` = number of inverted pairs
- `total_pairs` = total number of possible pairs

A disorder of:

- `0` means completely sorted
- `100` means completely reversed
- values in between represent partially sorted inputs

### 3.3.1. Simple Strategy — Insertion Sort

**Complexity: O(*n*²)**

Insertion Sort was selected as the baseline algorithm because of its simplicity and efficiency on nearly sorted data.

The algorithm repeatedly places elements into their correct position using stack operations.

### Advantages

- Simple implementation
- Good performance on nearly sorted inputs
- Low overhead

### Drawbacks

- Poor scalability on large random datasets

### 3.3.2. Medium Strategy — Chunk Sort

**Complexity: O(*n*√*n*)**

Chunk Sort divides the dataset into approximately √n chunks.

Elements are pushed to stack B according to their chunk range and then reconstructed into stack A in sorted order.

### Advantages

- Significant reduction in operation count compared to quadratic algorithms
- Well suited for medium-sized inputs

### Drawbacks

- Requires careful chunk size tuning
- Performance depends on distribution of values

### 3.3.3. Complex Strategy — Quick Sort

**Complexity:** O(*n*log*n*)

Quick Sort is implemented as a stack-adapted recursive partitioning algorithm.

The algorithm partitions values around pivots and recursively sorts subgroups while respecting Push_swap operation constraints.

### Advantages

- Excellent scalability
- Efficient for highly disordered inputs
- Strong asymptotic complexity

### Drawbacks

- More complex implementation
- Requires recursive logic and careful stack management

### 3.3.4. Adaptive Strategy

The adaptive strategy automatically selects a sorting method according to the measured disorder.

### Selection Rules

| Disorder | Strategy |
|-----------|-----------|
| disorder < 0.2 | Insertion Sort |
| 0.2 ≤ disorder < 0.5 | Chunk Sort |
| disorder ≥ 0.5 | Quick Sort |

### Rationale

Nearly sorted inputs benefit from simple quadratic algorithms because the number of required operations remains low.

Moderately disordered inputs benefit from Chunk Sort, providing a balance between complexity and operation count.

Highly disordered inputs are delegated to Quick Sort, which offers superior scalability and lower operation counts for large random datasets.

### 3.4. Complexity Summary

| Strategy | Complexity |
|-----------|------------|
| Insertion Sort | O(n²) |
| Chunk Sort | O(n√n) |
| Quick Sort | O(n log n) |
| Adaptive | Depends on measured disorder |

---

## 4. Bonus

### Checker

The bonus includes a fully functional `checker` program.

Usage:

```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

Output:

```text
OK
```

or

```text
KO
```

The checker validates:

- All Push_swap instructions
- Invalid operations
- Parsing errors
- Duplicate values
- Integer overflows

---

## 5. Learning Outcomes

This project provided practical experience in:

- Designing and implementing sorting algorithms
- Understanding algorithmic complexity
- Working with multiple algorithmic strategies
- Linked list manipulation
- Command-line argument parsing
- Flag-based program behavior
- Recursive algorithm design
- Advanced debugging techniques
- Detecting and fixing memory leaks
- Performance analysis and benchmarking
- Writing maintainable and modular C code

---

## 6. Challenges Faced

- Adapting Classical Algorithms
- Parsing Input - supporting both:
```bash
./push_swap 1 2 3
```
and
```bash
./push_swap "1 2 3"
```
while maintaining strict validation introduced additional complexity.
- Debugging
  * Linked list manipulation
  * Recursive partitioning
  * Edge cases
  * Operation generation
- Memory Management

---

## 7. Contributions

### hede-car
- Parsing
- Error handling
- Benchmark system

### dcoelho
- Stack operations
- Algorithm implementation

### Both
- Algorithm design discussions
- Debugging
- Optimization
- Code cleanup and refactoring
- Bonus

---
## 8. Resources
- https://www.geeksforgeeks.org/
- YouTube tutorials on:
  * Insertion Sort
  * Chunk/Bucket-based Sorting
  * Quick Sort
  * Linked Lists in C
  * Algorithm Complexity Analysis

### 8.1. AI Usage
AI tools were used as support resources during development:
 - README structure and documentation
 - Debugging assistance
 - Clarification of implementation ideas

All generated suggestions were reviewed, understood, tested, and adapted before being integrated into the project.

---

## 9. License

This project was developed as part of the 42 School curriculum and is intended for educational purposes.