/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 08:16:56 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/25 17:40:29 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_di(t_conv *conv, int nb)
{
	if (nb < 0)
	{
		ft_putchar(conv, '-');
		nb *= -1;
	}
	ft_putnbr_u(conv, nb);
}

void	ft_putnbr_u(t_conv *conv, unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_u(conv, nb / 10);
		ft_putnbr_u(conv, nb % 10);
	}
	else
		int_to_char(conv, nb);
}

void	ft_putnbr_xX(t_conv *conv, size_t nb)
{
	if (nb >= 16)
	{
		ft_putnbr_xX(conv, nb / 16);
		ft_putnbr_xX(conv, nb % 16);
	}
	else
		int_to_char(conv, nb);
}

void	int_to_char(t_conv *conv, size_t n)
{
	char	c[2];
	if (n < 10)
		*c = n + '0';
	else if (n < 16 && conv->specifier == 'p')
		*c = n + (conv->specifier - ('p' - 'a' +10));
	else if (n < 16)
		*c = n + (conv->specifier - ('x' - 'a' +10));
	c[1] = '\0';
	conv->sp_print = ft_strjoin(conv->sp_print, c);
	conv->sp_len = ft_strlen(conv->sp_print);
}
