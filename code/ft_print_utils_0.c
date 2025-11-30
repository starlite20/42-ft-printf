/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:11:02 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/01 01:35:45 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




int num_len(long long num)
{
	int len = 0;
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




// for u

int print_unsigned_number(unsigned int to_print, fs_flags *flags)
{
	// printf("\n\t=> print unsigned num");
	int printed;
	flags->plus = 0;
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

	len = num_len(unum);

	if(flags->width > 0)
	{
		if(flags->space != 0)
			len += 1;
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
		printed += print_single_character('+');
		flags->plus = -1;
	}
	else if(flags->space == 1)
	{
		//printf("\n\n\t ==> this is from + && -  %d \n\n", len);
		printed += print_single_character(' ');
		flags->space = -1;
	}
	

	if ((flags->plus == 1) && (flags->left_align == 1))
	{
		//printf("\n\n\t ==> this is from + && -  %d \n\n", len);
		printed += print_single_character('+');
		flags->plus = -1;
	}


	return (printed);
}

int	ft_put_unbr_len(unsigned int unum, fs_flags *flags)
{
	int printed;

	printed = 0;

	printed += print_unum_flags(flags, unum);

	if (unum >= 10)
		printed += ft_put_unbr_len(unum / 10, flags);
	
	ft_putchar_fd(('0' + (unum % 10)), 1);
	printed++;
	
	return (printed);
}






int print_single_character(char to_print)
{
	// printf("\n\t=> print single character");
	return (write(1, &to_print, 1));
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


void print_hexaddress(unsigned long long to_print, int *printed)
{
	// printf("\n\t=> print hex addr");
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
	// printf("\n\t=> print address");
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






int print_hexnum(unsigned int to_print, char hex_format, fs_flags *flags)
{
	// printf("\n\t=> print hex num");
	int printed;

	printed = 0;
	ft_put_hexnbr_len(((unsigned int)to_print), hex_format, &printed, flags);

	return (printed);
}

int print_hexnum_flags(fs_flags *flags, unsigned int unum)
{
	int printed = 0;
	int len;

	len = num_len(unum);

	if(flags->width > 0)
	{
		if(flags->space != 0)
			len += 1;
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
		printed += print_single_character('+');
		flags->plus = -1;
	}
	else if(flags->space == 1)
	{
		//printf("\n\n\t ==> this is from + && -  %d \n\n", len);
		printed += print_single_character(' ');
		flags->space = -1;
	}
	

	if ((flags->plus == 1) && (flags->left_align == 1))
	{
		//printf("\n\n\t ==> this is from + && -  %d \n\n", len);
		printed += print_single_character('+');
		flags->plus = -1;
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





