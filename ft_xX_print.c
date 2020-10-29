/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:51:28 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/29 17:37:53 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_xX_print(t_conv *conv, va_list args)
{
	unsigned		nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_xX(conv, nb);
	ft_exec_flags(conv);
}
