/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:36 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/29 01:16:44 by ssujaude         ###   ########.fr       */
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


int process_flag(char character, fs_flags *flags)
{
	if(is_format_flag(character))
	{
		if(character == '+')
			flags->plus = 1;
		else if(character == '0')
			flags->zero = 1;
		else if(character == '-')
			flags->minus = 1;
		else if(character == '#')
			flags->hashtag = 1;
		else if(character == '.')
			flags->dot = 1;
		else if(character == ' ')
			flags->space = 1;

		return (1);
	}
	return (0);
}




int print_argument(char *str, int *printed, va_list args)
{
	int skip_val;
	char fs_val;
	int i;
	fs_flags flags;


	skip_val = 1;
	fs_val = *(str+1);
	initiate_flags(&flags);

	if(is_format_flag(fs_val) == 1)
	{
		i = 1;
		while(process_flag(*(str+i+1), &flags))
			i++;
		if(is_format_specifier(*(str+i+1)))
			fs_val = *(str+i+1);
	}
	
	if(is_format_specifier(fs_val) == 1)
	{
		if(fs_val == 'c')
			*printed += print_single_character(va_arg(args, int));
		else if(fs_val == 's')
			*printed += print_string(va_arg(args, char *));
		else if((fs_val == 'd') || (fs_val == 'i'))
			*printed += print_number(va_arg(args, int), &flags);
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
		*printed += print_single_character(va_arg(args, int));
	}
	

	
	if(fs_val)
		skip_val += 1;

		// printf("\n ==> printed %c \n", fs_val);
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





int main()
{
	
	int mfp, ofp;
	unsigned int num = 123456789;
	int nnum = -123456789;

	// printf("\n\n\n### MY VERSION\n");
	// mfp = ft_printf(" => [%d] [%d] [%%] [%d] [%c] [%s] \nu:[%u] \t p:[%p]\t p:[%p] \t x:[%x] \t X:[%X] ", 100,  5, -545132323, 'a', "hellow", UINT_MAX, &mfp, NULL, num, num);
	// printf("\ncount : %d\n\n", mfp);
	
	// printf("### ORIG VERSION\n");
	// ofp = printf(" => [%d] [%d] [%%] [%d] [%c] [%s] \nu:[%u] \t p:[%p]\t p:[%p] \t x:[%x] \t X:[%X] ", 100,  5, -545132323, 'a', "hellow", UINT_MAX, &mfp, NULL, num, num);
	// printf("\ncount : %d\n\n", ofp);


	

	// printf("\n\n### ORIG VERSION\n");
	// ofp = printf(" NULL %s NULL ", NULL);
	// printf("\ncount : %d\n\n", ofp);
	
	// printf("\n### MY VERSION\n");
	// mfp = ft_printf(" NULL %s NULL ", NULL);
	// printf("\ncount : %d\n\n", mfp);

	

	// printf("\n\n### ORIG VERSION\n");
	// ofp = printf(" [%+d]", num);
	// printf("\ncount : %d\n\n", ofp);
	
	// printf("\n### MY VERSION\n");
	// mfp = ft_printf(" [%+d]", num);
	// printf("\ncount : %d\n\n", mfp);
	
	printf("\n %+d", 123);
	ft_printf("\n %+d", 123);
	// printf("\n %+i", 123);
	// printf("\n %+c", 'a');
	
}






