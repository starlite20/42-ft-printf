/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:36 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/29 19:19:48 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




int is_format_specifier(char character)
{
	if((character == 'c') || (character == 's') || (character == 'p') || (character == 'd')|| (character == 'i') || (character == 'u') || (character == 'x') || (character == 'X') || (character == '%'))
		return (1);
	return (-1);
}


int is_format_flag(char character)
{
	if((character == '+') || (character == '#') || (character == '-') || (character == ' ')|| (character == '0') || (character == '.'))
		return (1);
	return (-1);
}


void initiate_flags(fs_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->hashtag = 0;
	flags->dot = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width= 0;
}



void flag_printer(fs_flags *flags)
{
	printf("\n\n\t|| +%d  -%d     space %d = w %d    . %d = prec %d     # %d    0 %d  ||\n\n", flags->plus, flags->minus, flags->space, flags->width, flags->dot, flags->precision, flags->hashtag, flags->zero);
}


int process_flag(char character, fs_flags *flags)
{
	if(is_format_flag(character) != -1)
	{
		if(character == '+')
		{
			flags->plus = 1;
			flags->space = 0;
		}
		else if(character == '0')
			flags->zero = 1;
		else if(character == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		else if(character == '#')
			flags->hashtag = 1;
		else if(character == '.')
		{
			flags->dot = 1;
			flags->zero = 0;
		}
		else if(character == ' ')
			flags->space = 1;

		return (1);
	}
	return (0);
}


int process_numflag(char *str, fs_flags *flags)
{
	int value;

	value = ft_atoi(str);

	if(flags->dot == 1)
		flags->precision = value;
	else
		flags->width = value;
	
	return (num_len(value));
}


int print_argument(char *str, int *printed, va_list args)
{
	int skip_val;
	char fs_val;
	int i;
	fs_flags *flags;


	flags = ft_calloc(1, sizeof(fs_flags));
	i = 1;
	skip_val = 1;
	fs_val = *(str+1);
	initiate_flags(flags);

	while(*(str+i))
	{
		if(process_flag(*(str+i), flags) == 1)
			i++;
		else if(ft_isdigit(*(str+i)))
			i+=process_numflag(str+i, flags);
		else
			break;
	}
	if(is_format_specifier(*(str+i)))
		fs_val = *(str+i);

	
	if(fs_val)
	{
		if(is_format_specifier(fs_val) == 1)
		{
			if(fs_val == 'c')
				*printed += print_single_character(va_arg(args, int));
			else if(fs_val == 's')
				*printed += print_string(va_arg(args, char *));
			else if((fs_val == 'd') || (fs_val == 'i'))
				*printed += print_number(va_arg(args, int), flags);
			else if(fs_val == 'u')
				*printed += print_unsigned_number(va_arg(args, int));
			else if(fs_val == 'p')
				*printed += print_address(va_arg(args, void *));
			else if((fs_val == 'x') || (fs_val == 'X'))
				*printed += print_hexnum(va_arg(args, unsigned int), fs_val);
			else if(fs_val == '%')
				*printed += print_percentage();
		}
		else
		{
			//already printed
			*printed += print_single_character(fs_val);
		}
	} 
	
	if(fs_val)
		skip_val += i;

	// printf("\n ==> printed %c \n", fs_val);
	//flag_printer(flags);
	free(flags);
	return (skip_val);
}




int ft_printf(const char * str, ...)
{
	// int arg_count;
	int i;
	int skip;
	int printed;

	// create the list
	va_list args;
	va_start(args, str);
	

	i = 0;
	skip = 0;
	printed = 0;
	

	while(str[i])
	{
		// printf("\n ===> in ft_printf loop %d : %c", i, str[i]);
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
	
	// clean the macro
	va_end(args);

	return (printed);
}
