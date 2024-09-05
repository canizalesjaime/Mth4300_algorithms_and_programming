# Lecture Notes

## table of contents
1. Vscode Extensions of the Day
2. C++ Syntax
3. Functions
4. Operators 
5. Conditional Statements 
6. Loops 


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



## Operators
Operators are symbols that perform operations on variables and values.
### Arithmetic Operators
The arithmetic operators work exactly as they do in regular math. They take values as inputs(must be integer or decimal) and return the result of the arithmetic operation.
* \+ adds values
* \- subtracts values
* / divides
* \* multipies
* % is referred to as the mod operator. This opeartor divides the first value by the second then returns the remainder. Example: ```cout<<15%2;``` would print 1. Inputs must be integers to use this operator.
to include logical(boolean), arithmetic(ints and floats), string
* = assigns a value to a variable

### Logical Operators
Logical Operators are used to test if some condition is true or false. They take in two values as input, and return either true or false.  
* ! The not operartor. This is the only operator on the list that takes in only one input value. Returns the negation of the input value.
* && The and operator. Returns true if both inputs are true, otherwise returns false. 
* || The or operator. Returns true if at least one of the inputs is true, otherwise returns false.
* == The equality operator. Returns true if the two inputs are equivalent, otherwise return false.


### Object Operators
C++ is an oject oriented class. What this means is that the software developer has the power to create his own classes(which are treated as types internally). C++ allows us to overload the operators for these classes, which means give semantic meaning to something like **class toaster + class bread**. This statement does not make sense unless we apply meaning to the + operator by overloading it. More on operator overloading in the future!<br><br>

One example is the string class + operator. The + operator for strings is going to concatenate the two strings. For example: ``````

## Conditional Statements
if (else if, else if, ...,else if) else


## Loops
for(pow function) and while(conversion to binary)
