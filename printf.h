/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:00:24 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/24 11:45:50 by gumartin         ###   ########.fr       */
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
	size_t		content;
}				t_flags;

typedef struct	s_conv
{
	t_flags		asterisk;
	t_flags		minus;
	t_flags		zero;
	t_flags		point;
	t_flags		width;			//itoa
	t_flags		precision;
	int			len;
	int			counter;
	int			ret;
	char		specifier;
}				t_conv;
/*
**
**		ft_printf.c
*/
int		ft_printf(const char *fmt, ...);
void	ft_flags(t_conv *conv, const char *fmt, va_list args);
int		valid_conv(t_conv *conv, const char *fmt, va_list args);
void	ft_putflag(t_conv *conv, const char *fmt, va_list args);
int		ft_convert(t_conv *conv, const char *fmt, va_list args);
/*
**
**		clean.c
*/
void	init(t_conv *conv);
void	clean_flags(t_conv *conv);
/*
**
**		utils.c
*/
void	int_to_char(size_t n, t_conv *conv);
void	ft_putchar(char c, t_conv *conv);
void	ft_putstr(char *s, t_conv *conv);
int		ft_isnum(char c);
/*
**
**		putnbr.c
*/
void	ft_putnbr_di(int nb);
void	ft_putnbr_u(unsigned int nb);
void	ft_putnbr_xX(size_t nb, t_conv *conv);
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
/*
**
**		Flags
*/
//void	setflag(t_conv *conv, const char *fmt);

#endif