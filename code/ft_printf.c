/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:17:36 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/19 20:26:59 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

char is_valid_format(char character)
{
	if((character == 'c') || (character == 's') || (character == 'p') || (character == 'd') || (character == 'i') || (character == 'u') || (character == 'x') || (character == 'X'))
		return (character);
	
	return(NULL);
}

int arg_passed_counter(const char *str)
{
	int i;
	int arg_count;

	i=0;
	arg_count = 0;
	while(*(str + i))
	{
		if(*(str + i) == '%')
		{
			if(is_valid_format(*(str + i)))
			{
				arg_count++;
			}
		}
		i++;
	}
	return (arg_count);
}



int ft_printf(const char * str, ...)
{
	int arg_count;
	
	arg_count = arg_passed_counter(str);
	
	// create the list
	va_list args;
	va_start(args, str);

	printf("\n%d '%s'", va_arg(args, char *));

	
	printf("\n%s", str);

	// clean the macro
	va_end(args);
}

int main()
{
	ft_printf(" chcking one two three %d %c", 100, 'a');
}