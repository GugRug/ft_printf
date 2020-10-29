/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:10 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/28 01:35:09 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
	
void	ft_di_print(t_conv *conv, va_list args)
{
	//see flags 
	int		nb;
	int		spec_len;

	nb = va_arg(args, int);
	ft_
	if (nb < 0)
	{
		nb *= -1;
		ft_exec_flags(conv, nb);
		ft_putchar(conv, '-');
		ft_putnbr_di(conv, nb);
	}
	else
	{
		ft_exec_flags(conv, nb);
		ft_putnbr_di(conv, nb);
	}
}

