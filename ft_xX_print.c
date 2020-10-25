/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:51:28 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/25 15:05:15 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_xX_print(t_conv *conv, va_list args)
{
	//see flags 
	unsigned	temp;
	
	temp = va_arg(args, unsigned int);
	ft_putnbr_xX(conv, temp);
}