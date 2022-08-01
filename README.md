# C-Compiler

> WIP! It cannot compile C source code now.

This is a C compiler using LLVM.

It's a practice project to learn how to make a compiler,
and then you may use the same concepts to make a compiler of the new language you designed.
The implementations and comments probably aren't good enough, so welcome to create issues and PRs.

## Building

Dependencies:
- CMake
- [fmt](https://github.com/fmtlib/fmt)
- LLVM

Use the commands below or IDEs such as CLion to build.

```shell
# In the project root directory.
cmake .
make
```

## Usage

After built, run the program with one argument like the example below:

```shell
./C_Compiler "return 10 + 3 * 4 - (-1 == 2);"
```

The available operators include addition, subtraction, multiplication, division, remainder,
unary plus, unary minus, relational operators, equality operators, and assignment operators.

A `return` statement is necessary.
Unreachable code after the return statement won't be parsed.

You can use variables like `foo = 10; return foo + 1;`.
Trying to access a variable that hasn't assigned before causes compilation error.

The program will output LLVM IR into stdout.
You may redirect the output into a file and run it with `lli`.

### Command Templates

#### Optimize the IR and output

```shell
./C_Compiler $SOURCE | opt --O3 | llvm-dis | cat
```

#### Run the IR

```shell
./C_Compiler $SOURCE | lli
```

For some shells, you may have to use `$pipestatus[2]` or something else to get the exit status.
