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