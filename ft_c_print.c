/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:52:14 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 21:12:59 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_c_print(t_conv *conv, va_list args)
{
	conv->zero.state = 0;
	conv->precision.state = 0;
	conv->sp_print = (char*)malloc(sizeof(char*) * 3);
	conv->sp_print[0] = va_arg(args, int);
	conv->sp_print[1] = '\0';
	if (conv->sp_print[0] == '\0')
	{
		conv->sp_print[0] = 'W';
		conv->char_zero = 1;
	}
	ft_exec_flags(conv);
}
