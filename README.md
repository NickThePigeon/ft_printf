a 42 assignment of make your own printf with limited external functions

- Program name libftprintf.a
- Turn in files Makefile, *.h, */*.h, *.c, */*.c
- Makefile NAME, all, clean, fclean, re
- External functs. 
		malloc, free, write,
		va_start, va_arg, va_copy, va_end
- Libft authorized Yes
- Description Write a library that contains ft_printf(),
	a function that will mimic the original printf().

Here are the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Manage any combination of the following flags: ’-0.’
	and the field minimum width under all conversions.
• Your function will be compared against the original printf().