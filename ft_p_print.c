/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:52:14 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 19:50:14 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_p_print(t_conv *conv, va_list args)
{
	size_t	nb;

	nb = (size_t)va_arg(args, void *);
	conv->part_chr[0] = '0';
	conv->part_chr[1] = 'x';
	if (nb)
		ft_putnbr_x(conv, nb);
	else
	{
		conv->invalid = 1;
		conv->sp_print = (char*)malloc(sizeof(char*) * 3);
		conv->sp_print[0] = '\0';
		conv->sp_print[1] = '\0';
	}
	if (conv->invalid == 1 && conv->precision.state == 0)
		conv->sp_print[0] = '0';
	conv->invalid = 0;
	ft_exec_flags(conv);
}
