/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:52:14 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/24 09:36:19 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_c_print(t_conv *conv, va_list args)
{
	//see flags
	char	temp;
	
	temp = va_arg(args, int);
	ft_putchar(temp);
}