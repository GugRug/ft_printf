/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 05:23:50 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 01:18:27 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	printa(int n, t_spec *conv)
{
	char	c;

	c = n + '0';
	//write(1, &c, 1);
	conv->print[conv->size] = c;
	(conv->size)++;
}

void	ft_putnbr(int nb, t_spec *conv)
{
	unsigned int	nb2;

	if (nb < 0)
	{
		write(1, "-", 1);					//Check this later
		nb2 = nb * (-1);
	}
	else
		nb2 = nb;
	if (nb2 >= 10)
	{
		ft_putnbr(nb2 / 10, conv);
		ft_putnbr(nb2 % 10, conv);
	}
	else
		printa(nb2, conv);
}
