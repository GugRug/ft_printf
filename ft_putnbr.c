/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 08:16:56 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/24 11:46:12 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_di(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	ft_putnbr_u(nb);
}

void	ft_putnbr_u(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10);
		ft_putnbr_u(nb % 10);
	}
	else
		int_to_char(nb, NULL);
}

void	ft_putnbr_xX(size_t nb, t_conv *conv)
{
	if (nb >= 16)
	{
		ft_putnbr_xX(nb / 16, conv);
		ft_putnbr_xX(nb % 16, conv);
	}
	else
		int_to_char(nb, conv);
}