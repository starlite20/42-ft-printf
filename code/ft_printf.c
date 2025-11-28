/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:36 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/27 20:11:48 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr_len(int n)
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
	if (n >= 10)
		printed += ft_put_nbr_len(n / 10);
	
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


int print_single_character(char to_print)
{
	return (write(1, &to_print, 1));
}

int print_number(int to_print)
{
	return (ft_put_nbr_len(to_print));
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









int print_argument(char *str, int *printed, va_list args)
{
	int skip_val;
	char fs_val;

	skip_val = 1;
	fs_val = *(str+1);

	if(fs_val == 'c')
		*printed += print_single_character(va_arg(args, int));
	else if(fs_val == 's')
		*printed += print_string(va_arg(args, char *));
	else if((fs_val == 'd') || (fs_val == 'i'))
		*printed += print_number(va_arg(args, int));
	else if(fs_val == 'u')
		*printed += print_unsigned_number(va_arg(args, int));
	else if(fs_val == 'p')
		*printed += print_address(va_arg(args, void *));
	else if((fs_val == 'x') || (fs_val == 'X'))
		*printed += print_hexnum(va_arg(args, unsigned int), fs_val);
	else if(fs_val == '%')
		*printed += print_percentage();

	
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

	

	printf("\n\n### ORIG VERSION\n");
	ofp = printf(" [%+d]", num);
	printf("\ncount : %d\n\n", ofp);
	
	printf("\n### MY VERSION\n");
	mfp = ft_printf(" [%+d]", num);
	printf("\ncount : %d\n\n", mfp);
	
	



}