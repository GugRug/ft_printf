/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:00:24 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 01:20:26 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

#define MAX_FLAGS 4

typedef struct	s_flags
{
	int				putzeros;
	int				size;
}				t_flags;


typedef struct	s_conv
{
	t_flags			asterisk;
	t_flags			minus;
	t_flags			zero;
	t_flags			point;
	size_t			content;
	int				size;
	int				counter;
}				t_conv;

void	init(t_conv *conv);
void	clean_flags(t_conv *conv);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_flags(t_conv *conv, char *fmt);
void	setflag(t_conv *conv, char *fmt);
void	ft_convert(t_conv *conv, char *fmt);


#endif