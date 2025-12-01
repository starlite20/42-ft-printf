/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:51:30 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/01 17:30:52 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




int print_single_character(char to_print)
{
	return(write(1, &to_print, 1));
}

int print_character(char to_print, fs_flags *flags)
{
	int printed;
	
	printed = 0;
	printed += print_char_flags(flags);
	printed += print_single_character(to_print);
	if((flags->left_align == 1) )
	{
		if(flags->left_align == 1)
			flags->left_align = 2;
		printed += print_char_flags(flags);
	}
	return (printed);
}






int print_char_flags(fs_flags *flags)
{
	int printed = 0;
	int len;
	char printchar;

	len = 1;
	if(flags->width > 0)
	{
		if((flags->left_align == 0) || (flags->left_align == 2))
		{
			//printf("\n\n\t\t=> spaces to print %d for width %d \n\n", len, flags->width);
			// if(flags->zero != 1)
			// 	printchar = ' ';
			// else
			// 	printchar = '0';

			printchar = ' ';
			if(flags->width > len)
			{
				while(printed < (flags->width - len))
					printed += print_single_character(printchar);
			}
			flags->width = -1;

			if(flags->left_align == 2)
				flags->left_align= -1;
		}
	}

	return (printed);
}





int print_string_based_on_flag(fs_flags *flags, char *to_print, int len)
{
	int printed = 0;

	ft_strlen(to_print);
	if(flags->width > 0)
	{
		if(flags->width > len)
		{
			while(printed < (flags->width - len))
				printed += print_single_character(' ');
		}
		flags->width = -1;
	}
	return (printed);
}

int print_string(char *to_print)
{
	// printf("\n\t=> print string");
	int printed;
	int len;

	printed = 0;
	if(to_print == NULL)
		return (write(1, "(null)", 6));	
	len = ft_strlen(to_print);
	//printed += print_string_based_on_flag(flags, to_print, len);
	printed += write(1, to_print, len);
	return (printed);
}

int print_percentage()
{
	// printf("\n\t=> print percentage");
	return (write(1, "%", 1));
}



