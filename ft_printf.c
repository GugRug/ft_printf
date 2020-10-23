/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:39:47 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 01:03:08 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	setflag(t_conv *conv, char *fmt)
{
	if
}

void	ft_flags(t_conv *conv, char *fmt)
{
	if (fmt[(conv->counter)] == '%')
	{
		ft_putchar('%');
		conv->counter = conv->counter + 1;
		return;
	}
	if (fmt[(conv->counter)] == '*' || fmt[(conv->counter)] == '-' ||
		fmt[(conv->counter)] == '0' || fmt[(conv->counter)] == '.')
		setflag(&conv, fmt);
	else
		ft_putchar('%');
}

int		ft_printf(const char *fmt, ...)
{
	t_conv conv;
	va_list args;
	
	init(&conv);
	va_start(args, fmt);
	while (fmt[conv.counter])
	{
		if (fmt[conv.counter] == '%')
		{
			ft_flags(&conv, fmt);
			ft_convert(&conv, fmt);
		}
		else
			ft_putchar(fmt[conv.counter]);
		conv.counter++;		
	}
}

void	clean_flags(t_conv *conv)
{
	conv->asterisk = 0;
	conv->minus = 0;
	conv->zero = 0;
	conv->point = 0;
	conv->content = 0;
	conv->size = 0;
	conv->counter = 0;
}
void	init(t_conv *conv)
{
	clean_flags(conv);
	conv->content = 0;
	conv->size = 0;
	conv->counter = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}