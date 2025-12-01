/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:56:52 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/01 15:32:42 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




// for u

int print_unsigned_number(unsigned int to_print, fs_flags *flags)
{
	// printf("\n\t=> print unsigned num");
	int printed;
	flags->plus = 0;
	printed = 0;
	printed += print_unum_flags(flags, to_print);
	printed = ft_put_unbr_len(to_print, flags);
	if(flags->left_align == 1) 
	{
		if(flags->left_align == 1)
			flags->left_align = 2;
		printed += print_num_flags(flags, to_print);
	}
	return (printed);
}

int print_unum_flags(fs_flags *flags, unsigned int unum)
{
	int printed = 0;
	int len;
	char printchar;

	len = num_len(unum);

	if(flags->space == 1)
	{
		//printf("\n\n\t ==> this is from + && -  %d \n\n", len);
		printed += print_single_character(' ');
		flags->space = -1;
	}
	if(flags->width > 0)
	{
		if(flags->space != 0)
			len += 1;
		if((flags->left_align == 0) || (flags->left_align == 2))
		{
			if(flags->zero != 1)
				printchar = ' ';
			else
				printchar = '0';

			//printf("\n\n\t\t=> spaces to print %d for num %d \n\n", len, num);
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

int	ft_put_unbr_len(unsigned int unum, fs_flags *flags)
{
	int printed;

	printed = 0;
	if (unum >= 10)
		printed += ft_put_unbr_len(unum / 10, flags);
	
	ft_putchar_fd(('0' + (unum % 10)), 1);
	printed++;
	
	return (printed);
}

