/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:18:21 by ssujaude          #+#    #+#             */
/*   Updated: 2025/11/29 15:29:34 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>

#include <stdarg.h>
# include "libft/libft.h"



int ft_printf(const char * str, ...);

typedef struct s_flags
{
	int	hashtag;
	int plus;
	int space;
	int dot;
	int zero;
	int minus;
	int width;
}	fs_flags;

int print_argument(char *str, int *printed, va_list args);
int process_flag(char character, fs_flags *flags);
void initiate_flags(fs_flags *flags);
int is_format_flag(char character);
int is_format_specifier(char character);

int print_single_character(char to_print);
int print_number(int to_print, fs_flags *flags);
int print_unsigned_number(unsigned int to_print);
int print_string(char *to_print);
int print_percentage();
int print_hexnum(unsigned int to_print, char hex_format);
void print_hexaddress(unsigned long long to_print, int *printed);
int print_address(void *to_print);
int	ft_put_nbr_len(int n, fs_flags *flags);
int	ft_put_unbr_len(unsigned int n);
void	ft_put_hexnbr_len(unsigned int to_print, char hex_format, int *printed);


#endif