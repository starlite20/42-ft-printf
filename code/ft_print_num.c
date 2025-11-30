/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:55:59 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/01 02:07:30 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


int num_len(long long num)
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
		num /= 10;
		len++;
	}
	return (len);
}



//For d and i

int print_number(int to_print, fs_flags *flags)
{
	// printf("\n\t=> print number");
	int printed;
	printed = ft_put_nbr_len(to_print, flags);
	if((flags->left_align == 1) )//|| (flags->plus== 1))
	{
		if(flags->left_align == 1)
			flags->left_align = 2;
		// if(flags->plus== 1)
		// 	flags->plus= 2;
		printed += print_num_flags(flags, to_print);
	}
	return (printed);
}

int print_num_flags(fs_flags *flags, int num)
{
	int printed = 0;
	int len;

	len = num_len(num);

	if(flags->width > 0)
	{
		if(num >= 0)
		{
			if((flags->plus == 1) || (flags->plus == -1) || (flags->space != 0))
				len += 1;
		}
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
	if(((flags->plus == 1) && (flags->left_align == 0)) || ((flags->plus == 2) && (flags->left_align == 1)))
	{
		if(num >= 0)
		{
			printed += print_single_character('+');
		}
		flags->plus = -1;
	}
	else if(flags->space == 1)
	{
		//printf("\n\n\t ==> this is from + && -  %d \n\n", len);

		if(num >= 0)
		{
			printed += print_single_character(' ');
		}
		flags->space = -1;
	}
	

	if ((flags->plus == 1) && (flags->left_align == 1))
	{
		//printf("\n\n\t ==> this is from + && -  %d \n\n", len);
		if(num >= 0)
		{
			printed += print_single_character('+');
		}
		flags->plus = -1;
	}


	return (printed);
}

int	ft_put_nbr_len(int num, fs_flags *flags)
{
	int printed;

	// printf("\n\t put nbr len : %d", n);
	printed = 0;

	printed += print_num_flags(flags, num);
	if (num == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		printed += 2;
		num = 147483648;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num *= -1;
		printed++;
	}
	
	if (num >= 10)
		printed += ft_put_nbr_len(num / 10, flags);
	
	ft_putchar_fd(('0' + (num % 10)), 1);
	printed++;
	
	return (printed);
}
