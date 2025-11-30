/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:57:29 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/01 02:22:33 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int hexnum_len(long long num)
{
	int len;
	
	len = 0;
	if(num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while(num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int print_hexnum(unsigned int to_print, char hex_format, fs_flags *flags)
{
	// printf("\n\t=> print hex num");
	int printed;

	printed = 0;
	printed = print_hexnum_flags(flags, hex_format, to_print);

	ft_put_hexnbr_len(((unsigned int)to_print), hex_format, &printed, flags);

	if(flags->left_align == 1) 
	{
		if(flags->left_align == 1)
			flags->left_align = 2;
		printed += print_hexnum_flags(flags, hex_format, to_print);
	}
	return (printed);
}

int print_hexnum_flags(fs_flags *flags, char hex_format, unsigned int unum)
{
	int printed = 0;
	int len;

	len = hexnum_len(unum);

	if(flags->width > 0)
	{
		if(flags->space != 0)
			len += 1;
		if(flags->hashtag != 0)
			len += 2;
		if((flags->left_align == 0) || (flags->left_align == 2))
		{
			//printf("\n\n\t\t=> spaces to print %d for num %d \n\n", len, num);

			if(flags->width > len)
			{
				while(printed < (flags->width - len))
					printed += print_single_character(' ');
					//printed += print_single_character('0' + printed);
			}
			flags->width = -1;
			
			if(flags->left_align == 2)
				flags->left_align= -1;
		}
	}
	if(flags->hashtag == 1)
	{
		printed += print_single_character('0');
		printed += print_single_character(hex_format);
		flags->hashtag = -1;
	}
	if(flags->space == 1)
	{
		//printf("\n\n\t ==> this is from + && -  %d \n\n", len);
		printed += print_single_character(' ');
		flags->space = -1;
	}
	
	return (printed);
}

void	ft_put_hexnbr_len(unsigned int to_print, char hex_format, int *printed, fs_flags *flags)
{
	if(to_print >= 16)
	{
		ft_put_hexnbr_len(to_print/16, hex_format, printed, flags);
		ft_put_hexnbr_len(to_print%16, hex_format, printed, flags);
	}
	else
	{
		if(to_print >= 10)
		{
			if(hex_format == 'x')
				*printed += print_single_character((to_print - 10) + 'a');
			else
				*printed += print_single_character((to_print - 10) + 'A');
		}
		else
			*printed += print_single_character(to_print + '0');
	}
}


