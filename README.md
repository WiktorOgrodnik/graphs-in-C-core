# Graphs in C core

This is my implementation of a math interpreter written in C, which is used by my other project (Graphs in C).

## How to write equations?

In this section, I will describe what capabilities the mathematical command interpreter built into the program provides and how to construct queries.

### Syntax

#### NUmber literal

A number is a constant written with digits and a period or comma ({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0,, ,.}). The numbers are e.g. 10, 2,5, 10.5, 0, 11, 123, etc.

The number can be preceded by a '+' or '-' to indicate the sign of the number, for example: +10, -0.5.

#### Functions

Functions consist of a name, round brackets and take a single argument. E.g. sin(expression), log(expression), etc.

The following functions are available in the program:

- sin(x)
- cos(x)
- tan(x) - another form: tg(x)
- cot(x) - another form: ctg(x)
- ln(x) - natural logarithm, also log(x)
- log2(x) - binary logarithm
- log10(x) - decimal logarithm
- sqrt(x) - square root
- abs(x) - absolute value
- sinh(x) - hyperbolic sine
- cosh(x) - hyperbolic cosine
- tanh(x) - hyperbolic tangent, also tgh(x)
- floor(x) - integer part, the so-called floor
- ceil(x) - integer part (rounding up), so called ceiling
- asin(x) - arcus sine, also arcsin(x)
- acos(x) - arcus cosine, also arccos(x)
- atan(x) - arcus tangent, also arctan(x) and arctg(x)
- exp(x) - expotential function

#### Constants

There are 3 special constants defined in the program, they can be typed in the same way as numbers:

- e
- pi
- phi

#### Variable

Since the program draws functions of one variable, only one variable is available - 'x'. Intepreter substitutes an appropriate numeric value under the x variable, depending on the part of the graph that is drawn.

Note that using a letter other than x as a variable will not work!

#### Brackets

There are 4 types of parentheses available:

- Round brackets '()' - ordinary parentheses without special functions, the expression in these parentheses is executed first. With them you can influence the order of execution of actions.
- Parentheses of the type '||' - have the functions of round parentheses, and in addition calculate the absolute value. The equivalent would be to use the abs(expression) function.
- Square brackets '[]' - in addition to the fact that the expression in parentheses is executed first, the integer part of the expression is shorted. The equivalent would be to use the floor(expression) function.
- Curly brackets '{}' - the expression in parentheses is executed first and the fractional part of the expression is returned.

#### Binary operators

There are 5 binary operators in the program, taking two arguments, one from the right and one from the left of the operators.

Available operators:

- x+y - addition
- x-y - subtraction
- x*y - multiplication
- x/y - division
- x^y - exponentiation

The operators have different priorities. Exponentiations are performed first, then multiplication and division, and finally addition and subtraction.

If the operators have the same priority they are performed from left to right, the exception being the exponentiation, which is performed in the other direction.

Sometimes it is not required to write the multiplication sign. For example, '2x' is interpreted as '2 * x'.

You can substitute a variable, constants, numbers, an expression in parentheses or functions as x and y.

### Semantics

Correct mathematical expressions in the program:

- Every number, constant and variable is a valid expression
- (expression) (op) (expression) is a valid expression, where (op) is '+', '-', '*', '/' or '^'
- function_name((expression)) is a valid expression
- ((expression)) is a valid expression (where '()' is any parentheses)

All mathematical expressions can be constructed according to the above rules.

You can use any number of spaces or none at all in your queries, the exception being spaces inside a number, function name or constant, which are not allowed.

## To-Do

- Write examples
- Add simple python input window and gnuplot integration
