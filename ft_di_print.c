/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:10 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/25 15:05:40 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
	
void	ft_di_print(t_conv *conv, va_list args)
{
	//see flags 
	int		nb;
	nb = va_arg(args, int);
	if (nb < 0)
	{
		nb *= -1;
		ft_exec_flags(conv, nb);
		ft_putchar(conv, '-');
	}
	else
		ft_exec_flags(conv, nb);
	ft_putnbr_di(conv, nb);
}

void	ft_exec_flags(t_conv *conv, size_t nb)
{
	ft_cut_flags(conv, nb);
}

void	ft_cut_flags(t_conv *conv, size_t nb)
{
	int i;
	int size;

	i = 0;
	size = conv->len;
	while ()
	{
		/* code */
	}
	
}