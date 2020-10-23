/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:39:47 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 19:10:31 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
			conv.counter++;	
			if(ft_flags(&conv, fmt))
				ft_convert(&conv, fmt, args);
			clean_flags(&conv);
		}
		else
			ft_putchar(fmt[conv.counter]);
		conv.counter++;		
	}
	va_end(args);
	return (0);
}

// void	setflag(t_conv *conv, const char *fmt)
// {
// 	return;
// }

int		ft_flags(t_conv *conv, const char *fmt)
{
	if (fmt[(conv->counter)] == '%')
	{
		ft_putchar('%');
		conv->counter = conv->counter + 1;
		return (0);
	}
	if (fmt[(conv->counter)] == '*' || fmt[(conv->counter)] == '-' ||
		fmt[(conv->counter)] == '0' || fmt[(conv->counter)] == '.');
		// setflag(&conv, fmt); cspdiuxX%
	else if (fmt[(conv->counter)] == 'c' || fmt[(conv->counter)] == 's' ||
			fmt[(conv->counter)] == 'p' || fmt[(conv->counter)] == 'd' ||
			fmt[(conv->counter)] == 'i' || fmt[(conv->counter)] == 'u' ||
			fmt[(conv->counter)] == 'x' || fmt[(conv->counter)] == 'X')
			return (1);
	 else //if isnum before
		ft_putchar(fmt[(conv->counter)]);
	return (0);
}

void	ft_convert(t_conv *conv, const char *fmt, va_list args)
{
	int		temp;
	temp = va_arg(args, int);
	ft_putnbr(temp);
}


void	clean_flags(t_conv *conv)
{
	conv->asterisk.state = 0;
	conv->minus.state = 0;
	conv->zero.state = 0;
	conv->point.state = 0;

}
void	init(t_conv *conv)
{
	clean_flags(conv);
	conv->content = 0;
	conv->len = 0;
	conv->counter = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}