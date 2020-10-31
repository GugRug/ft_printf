/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:51:28 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 21:24:10 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x_print(t_conv *conv, va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_x(conv, nb);
	ft_exec_flags(conv);
}
