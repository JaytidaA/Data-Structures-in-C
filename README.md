# Data Structures
C++ provides a rich collection of data structures and algorithms via the STL. Since DSA is an important topic for many college level courses and interview programs, being a fun topic to learn in general. I decided to make this repository a place to hold my personal files for the Data Structures written in C.

# Code Standards
* The `C99` standard is used and expected from other contributors who may wish to contribute.
* The `includes` follow a Include What You Use (IWYU) pattern.
* Each new data structure should be added as defined by the rules below.
* Any build system is recommended as this repository is mostly a collection of header files and source files, although examples and Makefiles to build them are provided in this repository.

# Directory Structure
```
.
├── DataStructures.md : Contains documentation information for each Data Structure added to this repo.
├── ErrorHandling.md  : Contains rules for updating include/err_handle.h and documentation information.
├── Examples          : Contains examples and Makefiles to build them.
├── include           : Contains the header files of every data structure, utils and err_handle.
├── README.md         : This document.
├── utils             : Contains utility functions and error handling.
└── vector            : Contains the source files for the functionality of std::vector to C.
```

# Rules to add new data structures (for contributors and my own reference)
If you want to add the data structure `foo` to this repository, do the following:
1. Create the directories `foo`, `include/foo`, `Examples/foo`.
2. The `include/foo` directory will contain the required header files (mostly `foo.h`), although they can contain more if required (see `vector_utils.h`)
3. The `foo` directory is the source directory. Add the file `foo.c` to this directory and define all the functions required in `foo.h`
    1. As a general rule of thumb, functions which are not to be called by the user but only are present as helpers must be declared and defined in `foo.c`, `foo.h` should only contain the macros, typedefs, structs and prototypes of the functions which are to be used by the users of library.
4. The `Examples/foo` should contain atleast one example and a fully completed Makefile which builds the example(s). Look at the Makefile for Vectors for more details.
5. The [DataStructures.md](https://github.com/JaytidaA/Data-Structures-in-C/tree/main/DataStructures.md) file should be updated as well. Adding documentations for the added functionality, Makefile and Usage instructions is a must.
6. The [ErrorHandling.md](https://github.com/JaytidaA/Data-Structures-in-C/tree/main/ErrorHandling.md) file should be updated if new error handlers have been added in `err_handle.h`.
7. The [Directory Structure](https://github.com/JaytidaA/Data-Structures-in-C/tree/main/README.md#directory-structure) section of this README should be updated as well. The steps to do so are presented [below](https://github.com/JaytidaA/Data-Structures-in-C/tree/main/README.md#steps-to-update-directory-structure).

# Steps to update Directory Structure
Ensure that the `tree` command line utility is installed on your system.
```sh
cd "Data Structures in C"
tree -L 1
```
Copy the output to your clipboard and paste it in the README. DO NOT REMOVE THE DESCRIPTIONS PROVIDED BY OLDER CONTRIBUTORS.

# Instructions for contributors
1. Fork this repository and create your own branch named `feature/yourAwesomeFeature` from `main`
2. Commit changes to that branch and create a pull request.

# Note from Author (JaytidaA)
I do not know how large this project will end up becoming but I hope that via this repository, anyone can make use of these data structures on platforms such as Leetcode or HackerRank and not be restricted by the minimalist (?) nature of the C programming language.
