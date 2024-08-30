# Lecture Notes
A cpu is designed to execute instructions. When a programmer writes code, 
each line must be converted to a cpu instruction. This conversion is 
done by a compiler. A compiler is a software on your computer designed
to translate code written by a human, to code(binary) that can be read and
executed by your cpu.
```mermaid
graph TD;
    c++ code(main.cpp) --> compiler;
    compiler --> executable(a.exe or a.out);
```
A **low-level programming language** is a type of programming language that is closer to a computer's hardware and machine code than a high-level language.(examples: Assembly, and to some C) <br><br>
A **middle-level programming language** is a computer language that balances the features of high-level and low-level languages.(example is C++) <br><br>
A **high-level programming language** is a programming language that's designed to be easier for humans to understand and write.(example is python)<br><br>
The higher the level of a programming language implies a more complex and computationally expensive compiler. Higher level programming languages are written in lower level programming languages. For example, both python and c++ are written in c.   


## Installation
In this class, we will be working with the g++ compiler for c++ code. 
The simplest method to download the g++ compiler for any computer will be via docker.
In order to do this we must install the following dependencies:
* vscode
* docker(for windows make sure to turn on wsl2) 
* vscode extension: dev containers 
* vscode extension: c/c++


## First Program 
Our first program will be the traditional hello world program. Code can be found [here](./main.cpp). In this code, we discussed the \<iostream\> library(which handles input and output for the program, via input keyboard and output screen). We briefly described how this library is defined within the namespace **std**. We also went over the purpose of the main function in c++, which is to start the execution of the code when you run the program. To run our code we must first compile, then execute.<br><br>

### Steps 
1. Open a terminal, then navigate the terminal to where your code is located(using cd command). Example: ``` cd ./class_notes/week1/intro-08_29``` 
2. Type the command(to compile): ``` g++ main.cpp ```
3. Type the command ``` ls ``` to see if your computer created the executable **a.out**(mac or linux) or **a.exe**(windows)
4. Type the command(to execute(run on cpu)): ```./a.exe ``` or ```./a.out ``` 