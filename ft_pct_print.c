/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pct_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:45:12 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 21:26:26 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pct_print(t_conv *conv)
{
	conv->sp_print = (char*)malloc(sizeof(char*) * 2);
	conv->sp_print[0] = '%';
	conv->sp_print[1] = '\0';
	conv->precision.state = 0;
	conv->precision.content = 0;
	ft_exec_flags(conv);
}
