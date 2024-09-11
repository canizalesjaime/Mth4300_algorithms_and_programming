# Lecture Notes

## table of contents
1. Vscode Extensions of the Day
2. C++ Syntax
3. Functions


## Vscode Extensions of the Day
* Markdown All in One (allows you to view in markdown with shortcut **ctrl+shift+v**)


## C++ Syntax
* Comments in C++ can be specified in two ways with operator ```// comments for one line``` or<br> ```/* comment can span multiple lines */```  
* Statements are a line of code(one instruction)
* Semicolons are used to end a statement in C++. 
* variables in C++ is how the developer can store and manage data of different forms.There are many variable types:
  * int - Represents an integer ```int x = 7;```(the variable types short and long are also integers, but they represent a smaller and larger range respectively).
  *  float - Represents a decimal number, such as ```float y = 2.718;``` (the variable type double is also a decimal number, but allows for higher precision(more decimal places) at the cost of more memory)
  * char - Represents one character ```char a = 'd';```
  * string - Represents a sequence of characters ```string word = "Hello World";```
  * boolean - A variable that can be either true or false. ```bool check = true;```
* Variable names must follow these three rules:
  * no keywords can be used as variable names. [list of keywords](https://en.cppreference.com/w/cpp/keyword) 
  * variable names cannot start with a number
  * variable names can only contain alphanumeric characters and underscores. 
* A preprocessor directive is specified using the ```#```. For example #include\<iostream\>, and #include\<string\>. Preprocessor directives are parts of your code that must be prepared before compilation. For example, the compiler must fetch the code for the iostream and string libraries first, before it can compile these sections.
* The scope of a variable is determined by the curly braces it is within. The variable does not exist outside of the curly braces.


## Functions
A function is a block of code that performs some operation. A function can optionally define input parameters that enable callers to pass arguments into the function. A function can optionally return a value as output.
Function Synatx for function definition:<br>
```
return_type function_name(type_1 param_1, type_2 param_2, ..., type_n param_n)
{
  // code
  return value_of_return_type;
}
``` 
<br>

In C++ it is good practice to separate the function definition from its decalaration. This will be more important when we introduce classes and separation of implementation and interfaces.<br><br>
A function declaration is placed above the function definiton for main and the function definition is placed below it. The purpose of this is when you perform a function call in the main function, the main function knows what the function is and what it does. Check out the function foo in [file](./main.cpp) to see exactly how this works.

