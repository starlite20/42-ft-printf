/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:51:30 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/01 21:25:24 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int print_percentage()
{
	// printf("\n\t=> print percentage");
	return (write(1, "%", 1));
}

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
	if(flags->left_align == 1)
		flags->left_align = 2;
	printed += print_char_flags(flags);
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






