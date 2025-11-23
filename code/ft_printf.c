/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:36 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/23 20:54:51 by ssujaude         ###   ########.fr       */
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

void print_single_character(char to_print)
{
	write(1, &to_print, 1);
}

int check_format_specifier(char *str, va_list args)
{
	int skip_val;
	char fs_val;

	skip_val = 1;
	fs_val = '\0';

	fs_val = is_valid_format(*(str + 1));

	if(fs_val == 'c')
		print_single_character(va_arg(args, int));
	else if(fs_val == 's')
		print_single_character(va_arg(args, int));
	else if(fs_val == 'p')
		print_single_character(va_arg(args, int));
	else if(fs_val == 'd')
		print_single_character(va_arg(args, int));
	else if(fs_val == 'i')
		print_single_character(va_arg(args, int));
	else if(fs_val == 'u')
		print_single_character(va_arg(args, int));
	else if(fs_val == 'x')
		print_single_character(va_arg(args, int));
	else if(fs_val == 'X')
		print_single_character(va_arg(args, int));

	
	if(fs_val)
		skip_val += 1;

	return (skip_val);
}



int ft_printf(const char * str, ...)
{
	// int arg_count;
	int i;
	int skip;
	
	//arg_count = arg_passed_counter(str);

	// create the list
	va_list args;
	va_start(args, str);
	

	i = 0;
	skip = 0;

	while(str[i])
	{
		if(str[i] == '%')
		{
			skip = check_format_specifier((char *)(str+i), args);
			i += skip;
		}
		else
		{
			i++;
		}
			
	}
	

	// printf("\n %d", va_arg(args, int));
	// printf("\n '%c'", (unsigned char)(va_arg(args, int)));

	printf("\n%s", str);

	// clean the macro
	va_end(args);

	return (0);
}

// int main()
// {
// 	ft_printf(" chcking one two three %d %c", 100, 'a');
// }