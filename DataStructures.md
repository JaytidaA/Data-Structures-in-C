# DS.md
This file contains the information about the data structures added to the repository and their examples.

# Vectors
Defined as the `Vector` struct, Vectors provide a dynamically resizeable array similar to `std::vector` in C++. Supports generic typing using `void *` (void pointers).

Following are the structs, typedefs, functions and macros defined in vector.h
```c
/* macros */
#define INITIAL_VEC_CAP 1
// initial size of new vector
#define LINEAR_ALLOC
// defines allocation function

// define a convenient wrapper for push back (refer ahead) with the type of the element to be added.
#define push_back(vec, type, elm) do {
    type _temp = elm;                 \
    _push_back_ptr(vec, &_temp);      \
} while (0)

/* structs */
typedef struct {
    void *arr;
    size_t elm_size;
    size_t size;
    size_t capacity;
} Vector;

/* prototypes */
Vector *new_vector(size_t elm_size);                          // new vector
Vector *new_vector_cap(size_t elm_size, size_t n);            // new vector with a capacity
Vector *new_vector_fill(size_t elm_size, size_t n, Item i);   // new vector with a capacity and initial element
Vector *reset_vector(Vector *);                               // make an allocated vector same as new vector
void delete_vector(Vector *);                                 // delete a vector and it's memory

void _push_back_ptr(Vector *v, void *i);                      // add element to end
void pop_back(Vector *v);                                     // remove element from end
void *front(const Vector *v);                                 // get the first element
void *back(const Vector *v);                                  // get the last element

size_t size(const Vector *v);                                 // query the size
size_t capacity(const Vector *v);                             // query the capacity

void *at_ptr(const Vector *v, size_t i);                      // element access, similar to std::vector::at with bounds checking

bool empty(const Vector *v);                                  // check if vector is empty (size == 0)
void clear(Vector *v);                                        // make the vector empty (size = 0)
```

Conditional programming exists and is controlled via the following macros:
1. `LINEAR_ALLOC`, `EXP_ALLOC` and `ALLOC_CONST`: These three macros define the functionality of resizing and reallocating the vector when the current capacity is too small for the elements inside the vector.

    1. `LINEAR_ALLOC`: Is defined by default and sets the value of `ALLOC_CONST` to 5. The new capacity of the vector for reallocation is calculated as `v->capacity + ALLOC_CONST`.
    2. `EXP_ALLOC`: Needs to be defined via a `#define` directive and it's definition undefines `LINEAR_ALLOC`. It sets the value of `ALLOC_CONST` to 1.5 and the new capacity of the vector is calculated as `(size_t) (v->capacity * ALLOC_CONST)`


## Utilities
Printing utilities are provided for the vectors currently. Include `include/vector/vector_utils.h` to get access to the `print_vector` and `print_struct_vector` ~~function~~ parameterised macros.

### `print_vector`
```c
#define print_vector(vec, type, fmt) ...
```
The parameters are as follows:
* `vec`: A pointer to the vector data structure to be printed.
* `type`: Type of the elements stored in vector pointed to by `vec`.
* `fmt`: Format string for the vector elements. e.g. if `int`s are stored in the vector then this parameter should be `"%d"`.

Since it requires the use of a hosted implementation of C, if one is not present the function simply does nothing otherwise, it prints the Items of the vector in angular brackets and prints a new line.

### `print_struct_vector`
```c
#define print_struct_vector(vec, type, printer) ...
```
The parameters are as follows:
* `vec`: A pointer to the vector data structure to be printed.
* `type`: Type of the elements stored in the vector pointed to by `vec`.
* `printer`: A function pointer of the type `void (*printer)(type elm, char pstring[ELM_MAX_PRINT_LEN+1])`. 

The final argument replaces the format string for the built-in datatypes. The function should write whatever data is required to the `pstring` parameter ensuring the length of the element written is less than or equal to `ELM_MAX_PRINT_LEN` (defined in `include/utils.h`). The programmer should ensure that the final character of `pstring` should be a (`\0`) character. It is recommended the string utility functions from the `<string.h>` header file be used. The programmer need not worry about allocating and deallocating the `pstring` character array itself as it is taken care of inside the macro.

Since it requires the use of a hosted implementation of C, if one is not present the function simply does nothing otherwise, it prints the Items of the vector in angular brackets and prints a new line.

Example of `print_struct_vector`:
```c
typedef struct complex_number {
    double real; double imag
} cnumber;

void complex_printer(cnumber number, char pstring[ELM_MAX_PRINT_LEN + 1])
{
    if (!(number.imag))
        sprintf(pstring, "%g", number.real);
    else if (number.imag > 0)
        sprintf(pstring, "%g + %gi", number.real, number.imag);
    else
        sprintf(pstring, "%g - %gi", number.real, -number.imag);
}

Vector *v = new_vector(sizeof(cnumber));
/*
 * Note that the parenthesis around the initialiser list is required
 * to prevent the preprocessor from interpreting the struct as multiple
 * arguments.
 */
push_back(v, cnumber, ((cnumber) {1.0, 0.0}));
push_back(v, cnumber, ((cnumber) {1.5, 0.5}));
push_back(v, cnumber, ((cnumber) {2.0, -2.0}));
print_struct_vector(v, cnumber, *complex_printer);
```

Output:
```
<1, 1.5 + 0.5i, 2 - 2i>
```

## Errors
Currently only one error function is used by Vector, it is `err_null_malloc`, which prints to the standard error stream (in case of hosted implementation) if the ouput of the malloc function is NULL and exits the program.

## Examples
You can build the examples as follows (ensure that you have `make` installed on your system)
```sh
$ cd Examples/vectors
$ make build/<example>
$ ./build/<example>
```
Examples:
1. `general`: Presents the general functionality of vectors.
2. `maximum_sum`: Solves the maximum sum subarray problem.

Run `make clean` or `make clean_all` to clean up binary files and/or executables after Makefile usage.

## Usage
To make use of the `vector` data structure on your own follow the following steps:
1. Add the following line(s) to your source files.
```c
#include "vector/vector.h"
#include "vector/vector_utils.h"
```

2. Compile the `vector.c` and `utils.c` source files to their object files (I am using `gcc` in this example, use whatever compiler you would like,I am using gcc in this example, use whatever compiler you would like)
```sh
$ cd $HOME/"Data-Structures-in-C"
$ mkdir -p bin
$ gcc -o bin/vector.o -c vector/vector.c -I include
$ gcc -o bin/utils.o -c utils/vector_utils.c -I include
```

3. Compile your program with by navigating to your project's directory and add the appropriate directory.
```sh
$ cd $HOME/project-dir
$ mkdir -p bin
$ gcc -o bin/myproject.o -c src/myproject.c -I $HOME/Data\ Structures\ in\ C/include
$ gcc -o program bin/myproject.o $HOME/Data\ Structures\ in\ C/bin/*.o
```

4. Your program will be compiled as `program`
```sh
./program
```

# Stack
Defined as the `Stack` struct, this provides a LIFO (Last-In, First-Out) stack. It supports generic typing by making internal copies of the user's data, requiring the user to specify the element size upon creation.

Following are the structs, typedefs, and functions defined in `stack.h`:
```c
/* Special value to indicate that the stack is empty */
#define STACK_EMPTY NULL

/* structs */
typedef struct node {
    void *value;
    struct node *next;
} node;

typedef struct {
    node *head;
    size_t elm_size;
} Stack;

/* prototypes */
Stack *create_stack(size_t elm_size);   // Creates a new stack for elements of a given size
void free_stack(Stack *s);                  // Frees the stack and all remaining elements

void push(Stack *s, void *v);           // Pushes a copy of the element onto the stack
void *pop(Stack *s);                         // Pops an element, returns a pointer
void *top(const Stack *s);            // Returns a pointer to the top element

bool empty(const Stack *s);                 // Checks if the stack is empty
size_t stack_size(const Stack *s);          // Returns the number of elements in the stack
```

## Utilities
Currently, no utility functions like a print function are provided for the Stack.

## Errors
The Stack uses the `err_null_malloc` function from `err_handle.h`. It prints an error message to the standard error stream and exits the program if a `malloc` call fails.

## Examples
You can build the examples as follows (ensure that you have `make` installed on your system):
```sh
$ cd Examples/stack
$ make
$ ./build/general
```
Examples:
1. `general`: Presents the general functionality of the "copy-in" stack.

Run `make clean` or `make clean_all` to clean up binary files and/or executables after Makefile usage.

## Usage
Steps similar to [Vector usage](#usage).
