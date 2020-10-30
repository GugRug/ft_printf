/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:00:24 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 16:33:53 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			state;
	int			content;
}				t_flags;

typedef struct	s_conv
{
	t_flags		minus;
	t_flags		zero;
	t_flags		width;
	t_flags		precision;
	int			len;
	int			ret;
	int			counter;
	int			len_atoi;
	int			invalid;
	char*		sp_print;
	char		part_chr[3];
	char*		flags;
	char		specifier;
}				t_conv;
/*
**
**		ft_printf.c
*/
int		ft_printf(const char *fmt, ...);
void	ft_flags(t_conv *conv, const char *fmt, va_list args);
int		ft_valid_conv(t_conv *conv, const char *fmt, va_list args);
void	ft_putflag(t_conv *conv, const char *fmt, va_list args);
void	ft_convert(t_conv *conv, va_list args);
/*
**
**		clean.c
*/
void	init(t_conv *conv);
void	clean_flags(t_conv *conv);
/*
**
**		Print
*/
void	ft_c_print(t_conv *conv, va_list args);
void	ft_s_print(t_conv *conv, va_list args);
void	ft_p_print(t_conv *conv, va_list args);
void	ft_di_print(t_conv *conv, va_list args);
void	ft_u_print(t_conv *conv, va_list args);
void	ft_xX_print(t_conv *conv, va_list args);
void	ft_pct_print(t_conv *conv, va_list args);
/*
**
**		putnbr.c
*/
void	ft_putnbr_u(t_conv *conv, unsigned int nb);
void	ft_putnbr_xX(t_conv *conv, size_t nb);
void	int_to_char(t_conv *conv, size_t n);
/*
**
**		utils.c
*/
void	ft_putchar(t_conv *conv, char c);
void	ft_putstr(t_conv *conv, char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(t_conv *conv, char *s1, char *s2);
/*
**
**		utils_2.c
*/
int		ft_isnum(char c);
int		ft_pf_atoi(t_conv *conv, char *str);
size_t	ft_strlen(char *str);
/*
**
**		flags.c
*/
void	ft_read_flags(t_conv *conv, va_list args);
void	ft_exec_flags(t_conv *conv);
void	ft_flag_num(t_conv *conv, int *ref);
void	ft_flag_asterisk(t_conv *conv, va_list args);
/*
**
**		flags_2.c
*/
void	put_precision(t_conv *conv);
void	put_width(t_conv *conv);
char	*strbuild(char c, int n);
void	special_cases(t_conv *conv);
void	ft_correct_flags(t_conv *conv);

#endif