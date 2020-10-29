/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:39:47 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/25 18:25:25 by gumartin         ###   ########.fr       */
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
		{
			ft_putchar(&conv, fmt[conv.counter]);
			conv.counter++;
		}
	}
	va_end(args);
	return (0);
}

void	ft_flags(t_conv *conv, const char *fmt, va_list args)
{
	conv->counter++;	
	if (fmt[(conv->counter)] == '%')
	{
		ft_putchar(conv, '%');
		return;
	}
	if (ft_valid_conv(conv, fmt, args))
		return;
	ft_putchar(conv, fmt[(conv->counter)]);
}

int		ft_valid_conv(t_conv *conv, const char *fmt, va_list args)
{
	while (fmt[(conv->counter + conv->len)])
	{
		if (fmt[(conv->counter + conv->len)] == '-' || fmt[(conv->counter + conv->len)] == '0' ||
			fmt[(conv->counter + conv->len)] == '.' || fmt[(conv->counter + conv->len)] == '*' ||
			ft_isnum(fmt[(conv->counter + conv->len)]))
		{	conv->len++;
		}
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
	i = 0;
	conv->flags = ft_substr(fmt, conv->counter, conv->len);
	ft_convert(conv, fmt, args);
	free(conv->flags);
	conv->flags = NULL;
}

void	ft_convert(t_conv *conv, const char *fmt, va_list args)
{	
	ft_read_flags(conv, args);
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
		// if successe, than counter =+ len;
}

//printf(" ---A substr e: |%s| ---", conv->flags);
//ft_putstr(conv, "{Teste}\n"); //TESTANDO