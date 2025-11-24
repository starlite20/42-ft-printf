/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:36 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/24 23:43:07 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

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
	return (write(1, to_print, ft_strlen(to_print)));
}

int print_percentage()
{
	return (write(1, "%", 1));
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
		printed += print_string("(nil)");
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

		
	else if(fs_val == 'x')
		*printed += print_single_character(va_arg(args, int));
	else if(fs_val == 'X')
		*printed += print_single_character(va_arg(args, int));


	else if(fs_val == '%')
		*printed += print_percentage('%');

	
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
	printf("\n\n\n### MY VERSION\n");
	mfp = ft_printf(" => [%d] [%d] [%%] [%d] [%c] [%s] \nu:[%u] \t p:[%p]\t p:[%p]", 100,  5, -545132323, 'a', "hellow", UINT_MAX, &mfp, NULL);
	printf("\ncount : %d\n\n", mfp);
	
	printf("### ORIG VERSION\n");
	ofp = printf(" => [%d] [%d] [%%] [%d] [%c] [%s] \nu:[%u] \t p:[%p]\t p:[%p]", 100,  5, -545132323, 'a', "hellow", UINT_MAX, &mfp, NULL);
	printf("\ncount : %d\n\n", ofp);
}