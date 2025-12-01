/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:18:21 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/01 15:43:43 by ssujaude         ###   ########.fr       */
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
	int left_align;
	int width;
	int precision;
}	fs_flags;

int print_argument(char *str, int *printed, va_list args);
int process_flag(char character, fs_flags *flags);
void initiate_flags(fs_flags *flags);
int is_format_flag(char character);
int is_format_specifier(char character);

int print_single_character(char to_print);
int print_string(char *to_print);
int print_percentage();
int print_hexnum(unsigned int to_print, char hex_format, fs_flags *flags);

void	ft_put_hexnbr_len(unsigned int to_print, char hex_format, int *printed, fs_flags *flags);

int num_len(long long num);
int print_hexnum_flags(fs_flags *flags, char hex_format, unsigned int unum);



int print_number(int to_print, fs_flags *flags);
int print_num_flags(fs_flags *flags, long long num);
int	ft_put_nbr_len(long long num, fs_flags *flags);

int print_unsigned_number(unsigned int to_print, fs_flags *flags);
int print_unum_flags(fs_flags *flags, unsigned int unum);
int	ft_put_unbr_len(unsigned int unum, fs_flags *flags);

int print_address(void *to_print, fs_flags *flags);
int print_hexaddr_flags(fs_flags *flags, unsigned long long addr);
void ft_put_hexaddress(unsigned long long to_print, int *printed, fs_flags *flags);



#endif