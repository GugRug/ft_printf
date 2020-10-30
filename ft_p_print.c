/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:52:14 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 17:18:12 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_p_print(t_conv *conv, va_list args)
{
	size_t	nb;

	nb = (size_t)va_arg(args, void *);
	if (!nb)
		conv->invalid = 1;
	else
	{
		conv->part_chr[0] = '0';
		conv->part_chr[1] = 'x';
		ft_putnbr_xX(conv, nb);
	}
	if (conv->invalid == 1)
	{
	 	ft_putstr(conv, "0x0");
	}
	ft_exec_flags(conv);
}