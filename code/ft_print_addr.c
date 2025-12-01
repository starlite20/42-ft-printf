/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:43:12 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/01 16:49:21 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"



int hexaddr_len(unsigned long long num)
{
	int len;
	
	len = 0;
	if(num == 0)
		return (1);
	while(num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}


int print_address(void *to_print, fs_flags *flags)
{
	// printf("\n\t=> print address");
	int printed;

	printed = 0;
	printed += print_hexaddr_flags(flags, (unsigned long long)to_print);

	if(to_print == NULL)
		printed += print_string("0x0");
	else
	{
		printed += print_string("0x");
		ft_put_hexaddress(((unsigned long long)to_print), &printed, flags);
	}
	if(flags->left_align == 1) 
	{
		if(flags->left_align == 1)
			flags->left_align = 2;
		printed += print_hexaddr_flags(flags, (unsigned long long)to_print);
	}
	return (printed);
}

int print_hexaddr_flags(fs_flags *flags, unsigned long long addr)
{
	int printed = 0;
	int len;
	char printchar;


	len = hexaddr_len(addr) + 2;

	if(flags->width > 0)
	{
		if((flags->left_align == 0) || (flags->left_align == 2))
		{
			//printf("\n\n\t\t=> spaces to print %d for num %d \n\n", len, num);

			if(flags->zero != 1)
				printchar = ' ';
			else
				printchar = '0';
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

void ft_put_hexaddress(unsigned long long to_print, int *printed, fs_flags *flags)
{
	// printf("\n\t=> print hex addr");
	if(to_print >= 16)
	{
		ft_put_hexaddress(to_print/16, printed, flags);
		ft_put_hexaddress(to_print%16, printed, flags);
	}
	else
	{
		if(to_print >= 10)
			*printed += print_single_character((to_print - 10) + 'a');
		else
			*printed += print_single_character(to_print + '0');
	}
}

