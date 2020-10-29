/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:52:14 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/29 16:30:00 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_u_print(t_conv *conv, va_list args)
{
	// Null and Nil to implement later
	//see flags 
	unsigned		nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_u(conv, nb);
	ft_exec_flags(conv);
}
