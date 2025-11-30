/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 01:11:02 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/01 02:43:10 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




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











