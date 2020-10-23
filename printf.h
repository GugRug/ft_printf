/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:00:24 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 19:05:30 by gumartin         ###   ########.fr       */
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
	int				state;
	int				size;
}				t_flags;

typedef struct	s_conv
{
	t_flags			asterisk;
	t_flags			minus;
	t_flags			zero;
	t_flags			point;
	size_t			content;
	int				len;
	int				counter;
}				t_conv;

int		ft_printf(const char *fmt, ...);
void	init(t_conv *conv);
void	clean_flags(t_conv *conv);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_flags(t_conv *conv, const char *fmt);
//void	setflag(t_conv *conv, const char *fmt);
void	ft_convert(t_conv *conv, const char *fmt, va_list args);


#endif