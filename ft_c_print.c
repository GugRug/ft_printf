/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:52:14 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/29 17:13:40 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_c_print(t_conv *conv, va_list args)
{
	//see flags
	conv->zero.state = 0;
	conv->precision.state = 0;
	
	conv->sp_print = (char*)malloc(sizeof(char*) * 3);
	conv->sp_print[0] = va_arg(args, int);
	conv->sp_print[1] = '\0';
	ft_exec_flags(conv);
}