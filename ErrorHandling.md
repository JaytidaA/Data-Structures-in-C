# ErrorHandling
Almost all of the error handling is done in one single file, contributors are free to modify this file and add more functions, macros, etc. if required. The rest of this markdown file is to be used as documentation for the same.

# err\_handle.h
A single header file defined for handling errors. All functions must be declared and defined in this file alone.

List of structs, typedefs, functions and macros:
```c
void err_null_malloc(const char *func, size_t size);
// prints to the standard error stream if __STDC_HOSTED__ is defined and exits.
// Usually the __func__ string is passed as the first parameter.
```
