/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:10 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 21:24:10 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_di_print(t_conv *conv, va_list args)
{
	int	nb;

	nb = va_arg(args, int);
	if (nb < 0)
	{
		nb *= -1;
		conv->part_chr[0] = '-';
		ft_putnbr_u(conv, nb);
		ft_exec_flags(conv);
	}
	else
	{
		ft_putnbr_u(conv, nb);
		ft_exec_flags(conv);
	}
}
