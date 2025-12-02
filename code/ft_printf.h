/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:18:21 by ssujaude          #+#    #+#             */
/*   Updated: 2025/12/02 12:50:57 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <string.h>

typedef struct s_flags
{
	int	hashtag;
	int	plus;
	int	space;
	int	dot;
	int	zero;
	int	left_align;
	int	width;
	int	precision;
}		t_flags;

int		ft_printf(const char *str, ...);

int		is_format_specifier(char character);
int		print_argument(char *str, int *printed, va_list args);

int		is_format_flag(char character);
void	initiate_flags(t_flags *flags);
int		process_flag(char character, t_flags *flags);
int		process_numflag(char *str, t_flags *flags);

int		print_percentage(void);

int		print_single_character(char to_print);
int		print_character(char to_print, t_flags *flags);
int		print_char_flags(t_flags *flags);

int		ft_put_string_len(char *to_print, int len);
int		print_string(char *to_print, t_flags *flags);
int		print_string_based_on_flag(t_flags *flags, char *to_print, int len);

int		num_len(long long num);

int		print_number(int to_print, t_flags *flags);
int		print_num_flags(t_flags *flags, long long num);
int		ft_put_nbr_len(long long num, t_flags *flags);

int		print_unsigned_number(unsigned int to_print, t_flags *flags);
int		print_unum_flags(t_flags *flags, unsigned int unum);
int		ft_put_unbr_len(unsigned int unum, t_flags *flags);

int		print_hexnum(unsigned int to_print, char hex_format, t_flags *flags);
void	ft_put_hexnbr_len(unsigned int to_print, char hex_format, int *printed,
			t_flags *flags);
int		print_hexnum_flags(t_flags *flags, char hex_format, unsigned int unum);

int		print_address(void *to_print, t_flags *flags);
int		print_hexaddr_flags(t_flags *flags, unsigned long long addr);
void	ft_put_hexaddress(unsigned long long to_print, int *printed,
			t_flags *flags);

#endif