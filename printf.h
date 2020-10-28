/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:00:24 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/28 02:27:05 by gumartin         ###   ########.fr       */
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
	int			position;
	size_t		content;
	char*		inic;
	char*		end;
}				t_flags;

typedef struct	s_conv
{
	t_flags		minus;
	t_flags		zero;
	t_flags		width;			//itoa to use the wedth and precision
	t_flags		asterisk;
	t_flags		precision;
	int			len;
	int			ret;
	int			success;
	int			counter;
	int			valid;
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
void	ft_convert(t_conv *conv, const char *fmt, va_list args);
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
void	int_to_char(t_conv *conv, size_t n);
void	ft_putchar(t_conv *conv, char c);
void	ft_putstr(t_conv *conv, char *s);
int		ft_isnum(char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
/*
**
**		putnbr.c
*/
void	ft_putnbr_di(t_conv *conv, int nb);
void	ft_putnbr_u(t_conv *conv, unsigned int nb);
void	ft_putnbr_xX(t_conv *conv, size_t nb);
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
void	ft_read_flags(t_conv *conv, va_list args);
void	ft_flag_num(t_conv *conv, va_list args, int *ref);
// void	ft_exec_flags(t_conv *conv, size_t nb);
// void	ft_cut_flags(t_conv *conv, size_t nb);
//void	setflag(t_conv *conv, const char *fmt);

#endif