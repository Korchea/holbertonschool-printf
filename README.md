# _printf

In this variadic function we replicate a printf function. It must print a string that we give to the function and recognice conversion specifiers, we use that conversion specifiers to detect and insert diferent types of variables.

We have five conversion specifiers, those are the %c, %s, %%, %d and %i.
| Conversion specifier | Description					|
|-----|:---------------------------------------------------------------|
| `%c` | It represent a variable of type char.				|
| `%s` | It represent a variable of type `char *`, commonly called string. |
| `%%` | It is used to remplace it with a '%'.				|
| `%d` | It represent a variable of type int in decimal.		|
| `%i` | It represent a variable of type int.				|

In this project we use eigth functions, those functions are _printf, get_format, _strlen, caseint, print_int, casechar, casestring and casepercent.
- `int _printf(const char *format, ...)`: It is our principal function, here we recive the format of all the function and the other variables with the ellipsis. This function creates the list of the variables given in the ellipsis, traverses the string format, look for the conversion specifiers and prints the string format, if it recognise a % in format it call the functon get_format and it returns the number of characters printed.
- `void get_format(const char *format, va_list ap, int i, int *count)`: This function create a structure of chars and functions, look up for the conversion specifiers in the structure and if it find something it call to other function, those functions are casechar, casestring, casepercent and caseint.
- `int casechar(va_list ap)`: In this function we print the char who is in the list and return 1 who is the number of prints.
- `int casestring(va_list ap)`: In this function we print the string who is in the list and return the length of the string using the function _strlen.
- `int casepercent(va_list ap __attribute__((unused)))`: In this function we print the char '%' and return 1 who is the number of prints, we use te attribute unused because we make all the functions of the structure with the same format and we don´t use the list.
- `int caseint(va_list ap)`: In this function we recive an int from the list and send it to the function print_int, it returns the number of digits of the int.
- `void print_int(long int n, int *count)`: In this function we print the integer and if it is less than 0 then print a '-'.
- `unsigned int _strlen(char *s)`: In this function we return the length of a string.

### Diferent limit cases of the function:
Input:
```
_printf(NULL);
Output:
```
Input:
```
_printf("Let´s try to printf a simple sentence.");
Output:
Let´s try to printf a simple sentence.
```
Input:
```
_printf("%D\n", INT_MIN);
Output:
-2147483648
```
Input:
```
_printf("Hi, %s\n", "Betty");
Output:
Hi, Betty
```
Input:
```
_printf("If you %s\n", NULL);
Output:
If you (null)
```
Input:
```
_printf("This is a char %c\n", 'H');
Output:
This is a char H
````
Input:
### To use that function we need to:
- Clone the repository.
- Create a main.c to call the function.
- Compile all whit the command `gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c`.
- Enjoy.

#### If you need some help you can ask to the creators: 
- @Gabriel Acosta: 6333@holbertonstudents.com GitHub: https://github.com/GabiAcosta
- @Guillermo Vega: 6334@holbertonstudents.com GitHub: https://github.com/Korchea

#### Autors:
- Gabriel Acosta - Holberton School Montevideo, Cohort 20.
- Guillermo Vega - Holberton School Montevideo, Cohort 20.
