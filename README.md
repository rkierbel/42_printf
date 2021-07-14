# 42_printf
This project is pretty straightforward -> I recoded printf

My printf manages the following conversions : cspdiuxX%
• %c print a single character.
• %s print a string of characters.
• %p The void * pointer argument is printed in hexadecimal.
• %d print a decimal (base 10) number.
• %i print an integer in base 10.
• %u print an unsigned decimal (base 10) number.
• %x print a number in hexadecimal (base 16).
• %% print a percent sign.

The printf function makes use of what are known in C as variable argument lists. This means you can call the function with different numbers of parameters.
As with all C functions, you have to provide the parameters that have an actual type – in this case the format string. However, you can then supply as many other parameters as you want, including none, and it is up to the function to somehow work out how many you provided.

The function returns the number of characters that it printed, or a negative value if some sort of error occurred (note errors do not cover undefined behaviour).

What I got from this project : deep understanding of structures manipulation in C, variadic functions, enhanced string manipulation
