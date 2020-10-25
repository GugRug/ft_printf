/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:39:47 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/24 11:14:54 by gumartin         ###   ########.fr       */
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
			ft_flags(&conv, fmt, args);
			clean_flags(&conv);
		}
		else
			ft_putchar(fmt[conv.counter], conv);
		conv.counter++;
	}
	va_end(args);
	return (0);
}


void	ft_flags(t_conv *conv, const char *fmt, va_list args)
{
	conv->counter++;	
	if (fmt[(conv->counter)] == '%')
	{
		ft_putchar('%', conv);
		return;
	}
	if (ft_valid_conv)
	{
		//ft_tempstr
		return;
	}
	ft_putchar(fmt[(conv->counter)], conv);
}

int		ft_valid_conv(t_conv *conv, const char *fmt, va_list args)
{
	while (fmt[(conv->counter + conv->len)])
	{
		if (fmt[(conv->counter + conv->len)] == '-' || fmt[(conv->counter + conv->len)] == '0' ||
			fmt[(conv->counter + conv->len)] == '.' || fmt[(conv->counter + conv->len)] == '*' ||
			ft_isnum(fmt[(conv->counter + conv->len)]))
			conv->len++;
		else if (fmt[(conv->counter + conv->len)] == 'c' || fmt[(conv->counter + conv->len)] == 's' ||
				fmt[(conv->counter + conv->len)] == 'p' || fmt[(conv->counter + conv->len)] == 'd' ||
				fmt[(conv->counter + conv->len)] == 'i' || fmt[(conv->counter + conv->len)] == 'u' ||
				fmt[(conv->counter + conv->len)] == 'x' || fmt[(conv->counter + conv->len)] == 'X')
		{
			conv->specifier = fmt[(conv->counter + conv->len)];
			ft_putflag(conv, fmt, args);
			return (1);
		}
		else 
			return (0);
	}	
	return (0);
}

void	ft_putflag(t_conv *conv, const char *fmt, va_list args)
{
	int	i;
// if isnt printable in any time, return len
	i = 0;
	while (fmt[(conv->counter + i)] != conv->specifier)
	{
		
	}

	return;
}

int		ft_convert(t_conv *conv, const char *fmt, va_list args)
{
	if (fmt[(conv->counter)] == 'c')
		ft_c_print(conv, args);
	else if (fmt[(conv->counter)] == 's')
		ft_s_print(conv, args);
	else if (fmt[(conv->counter)] == 'p')
		ft_p_print(conv, args);
	else if (fmt[(conv->counter)] == 'd' || (fmt[(conv->counter)] == 'i'))
		ft_di_print(conv, args);
	else if (fmt[(conv->counter)] == 'u')
		ft_u_print(conv, args);
	else if (fmt[(conv->counter)] == 'x' || (fmt[(conv->counter)] == 'X'))
		ft_xX_print(conv, args);
}
