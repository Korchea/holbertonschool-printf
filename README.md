#_printf

In this variadic function we replicate a printf function. It must print a string that we give to the function and recognice conversion specifiers, we use that conversion specifiers to detect and insert diferent types of variables.

We have five conversion specifiers, those are the `%c, %s, %%, %d and %i.`
|:---|:-----------------------------------------------------------------|
|%c: |It represent a variable of type char.				|
|%s: |It represent a variable of type char *, commonly called string.	|
|%%: |It is used to remplace it whit a '%'.				|
|%d: |It represent a variable of type int in decimal.			|
|%i: |It represent a variable of type int.				|

In this project we use eigth functions, those functions are _printf, get_format, _strlen, caseint, print_int, casechar, casestring and casepercent.
- @_printf: It is our principal function, here we recive the format of all the function and the other variables with the ellipsis. This function creates the list of the variables given in the ellipsis, traverses the string format, look for the conversion specifiers and prints the string format, if it recognise a % in format it call the functon get_format and it returns the number of characters printed.
- @get_format: This function create a structure of chars and functions, look up for the conversion specifiers in the structure and if it find something it call to other function, those functions are casechar, casestring, casepercent and caseint.
- @casechar: In this function we print the char who is in the list and return 1 who is the number of prints.
-@casestring: In this function we print the string who is in the list and return the length of the string using the function _strlen.
- @casepercent: In this function we print the char '%' and return 1 who is the number of prints.
- @caseint: In this function we recive an int from the list and send it to the function print_int, it returns the number of digits of the int.
- @print_int: In this function we print the integer and if it is less than 0 then print a '-'.
- @_strlen: In this function we return the length of a string.

To use that function we need a header file that contains all prototipes, structure and one main.c that call _printf, to compile it we use the command "gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c".

If you need some help you can ask to the creators: 
- @Gabriel Acosta: 6333@holbertonstudents.com
- @Guillermo Vega: 6334@holbertonstudents.com

Autors:
- Gabriel Acosta - Holberton School Montevideo, Cohort 20.
- Guillermo Vega - Holberton School Montevideo, Cohort 20.
