/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:11:02 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/29 01:16:02 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_single_character(char to_print)
{
	return (write(1, &to_print, 1));
}

int print_number(int to_print, fs_flags *flags)
{
	return (ft_put_nbr_len(to_print, flags));
}

int print_unsigned_number(unsigned int to_print)
{
	return (ft_put_unbr_len(to_print));
}

int print_string(char *to_print)
{
	if(to_print == NULL)
		return (write(1, "(null)", 6));	
	return (write(1, to_print, ft_strlen(to_print)));
}

int print_percentage()
{
	return (write(1, "%", 1));
}

int print_hexnum(unsigned int to_print, char hex_format)
{
	int printed;

	printed = 0;
	ft_put_hexnbr_len(((unsigned int)to_print), hex_format, &printed);

	return (printed);
}

void print_hexaddress(unsigned long long to_print, int *printed)
{
	if(to_print >= 16)
	{
		print_hexaddress(to_print/16, printed);
		print_hexaddress(to_print%16, printed);
	}
	else
	{
		if(to_print >= 10)
			*printed += print_single_character((to_print - 10) + 'a');
		else
			*printed += print_single_character(to_print + '0');
	}
}

int print_address(void *to_print)
{
	int printed;

	printed = 0;

	if(to_print == NULL)
	{
		printed += print_string("0x0");
	}
	else
	{
		printed += print_string("0x");
		print_hexaddress(((unsigned long long)to_print), &printed);
	}
	return (printed);
}



int	ft_put_nbr_len(int n, fs_flags *flags)
{
	int printed;

	printed = 0;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		printed += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		printed++;
	}
	if(flags->plus == 1)
	{
		printed = print_single_character('+');
		flags->plus = 0;
	}
	if (n >= 10)
		printed += ft_put_nbr_len(n / 10, flags);
	
	ft_putchar_fd(('0' + (n % 10)), 1);
	printed++;
	
	return (printed);
}


int	ft_put_unbr_len(unsigned int n)
{
	int printed;

	printed = 0;

	if (n >= 10)
		printed += ft_put_unbr_len(n / 10);
	
	ft_putchar_fd(('0' + (n % 10)), 1);
	printed++;
	
	return (printed);
}






void	ft_put_hexnbr_len(unsigned int to_print, char hex_format, int *printed)
{
	if(to_print >= 16)
	{
		ft_put_hexnbr_len(to_print/16, hex_format, printed);
		ft_put_hexnbr_len(to_print%16, hex_format, printed);
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


