/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:10 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 19:35:49 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
	
void	ft_di_print(t_conv *conv, va_list args)
{
	int		temp;
	temp = va_arg(args, int);
	ft_putnbr(temp);
}