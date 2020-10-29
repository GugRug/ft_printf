/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:13 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/25 15:05:46 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_s_print(t_conv *conv, va_list args)
{
	conv->zero.state = 0;
	conv->precision.state = 0;
	conv->asterisk.state_2 = 0;
	//see flags
	char	*temp;
	temp = va_arg(args, char *);
	ft_putstr(conv, temp);
}