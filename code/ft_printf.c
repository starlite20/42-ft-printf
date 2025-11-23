/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:36 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/23 23:09:39 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

char is_valid_format(char character)
{
	if((character == 'c') || (character == 's') || (character == 'p') || (character == 'd') || (character == 'i') || (character == 'u') || (character == 'x') || (character == 'X'))
		return (character);
	
	return('\0');
}

int arg_passed_counter(const char *str)
{
	int i;
	int arg_count;

	i=0;
	arg_count = 0;
	while(*(str + i))
	{
		if(*(str + i) == '%')
		{
			if(is_valid_format(*(str + i)))
			{
				arg_count++;
			}
		}
		i++;
	}
	return (arg_count);
}

int print_single_character(char to_print)
{
	ft_putchar_fd(to_print, 1);
	return (1);
}

int print_number(int to_print)
{
	ft_putnbr_fd(to_print, 1);
	return (1);
}

int print_string(char *to_print)
{
	// ft_putstr_fd(to_print, 1);
	return (write(1, to_print, ft_strlen(to_print)));
}

int print_argument(char *str, int *printed, va_list args)
{
	int skip_val;
	char fs_val;

	skip_val = 1;
	fs_val = '\0';

	fs_val = is_valid_format(*(str + 1));

	if(fs_val == 'c')
		*printed += print_single_character(va_arg(args, int));
	else if(fs_val == 's')
		*printed += print_string(va_arg(args, char *));
	else if(fs_val == 'p')
		*printed += print_single_character(va_arg(args, int));
	else if(fs_val == 'd')
		*printed += print_number(va_arg(args, int));
	else if(fs_val == 'i')
		*printed += print_single_character(va_arg(args, int));
	else if(fs_val == 'u')
		*printed += print_single_character(va_arg(args, int));
	else if(fs_val == 'x')
		*printed += print_single_character(va_arg(args, int));
	else if(fs_val == 'X')
		*printed += print_single_character(va_arg(args, int));
	else if(fs_val == '%')
		*printed += print_single_character('%');

	
	if(fs_val)
		skip_val += 1;

		// printf("\n ==> printed %d \n", *printed);
	return (skip_val);
}



int ft_printf(const char * str, ...)
{
	// int arg_count;
	int i;
	int skip;
	int printed;
	//arg_count = arg_passed_counter(str);

	// create the list
	va_list args;
	va_start(args, str);
	

	i = 0;
	skip = 0;
	printed = 0;
	

	while(str[i])
	{
		if(str[i] == '%')
		{
			skip = print_argument((char *)(str+i), &printed, args);
			i += skip;
		}
		else
		{
			printed += write(1, (str+i), 1);
			i++;
		}	
	}
	

	// printf("\n %d", va_arg(args, int));
	// printf("\n '%c'", (unsigned char)(va_arg(args, int)));

	// clean the macro
	va_end(args);

	return (printed);
}

int main()
{
	int mfp, ofp;
	printf("\n\n\n### MY VERSION\n");
	mfp = ft_printf(" chcking one two %% three %d %c %s", 100, 'a', "hellow");
	printf("\ncount : %d\n\n", mfp);
	
	printf("### ORIG VERSION\n");
	ofp = printf(" chcking one two %% three %d %c %s", 100, 'a', "hellow");
	printf("\ncount : %d\n\n", ofp);
}