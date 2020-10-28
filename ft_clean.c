/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:01 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/28 03:32:07 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	clean_flags(t_conv *conv)
{
	conv->minus.state = 0;
	conv->zero.state = 0;
	conv->width.state = 0;
	conv->asterisk.state = 0;
	conv->precision.state = 0;
	conv->minus.position = 0;
	conv->zero.position = 0;
	conv->width.position = 0;
	conv->asterisk.position = 0;
	conv->precision.position = 0;
	conv->minus.content = 0;
	conv->zero.content = 0;
	conv->width.content = 0;
	conv->asterisk.content = 0;
	conv->precision.content = 0;
	conv->len = 0;
	conv->len_atoi = 0;
	conv->success = 0;
	conv->valid = 0;
	conv->specifier = '\0';
	conv->width.inic = '\0';
	conv->width.end = '\0';
	conv->precision.inic = '\0';
	conv->precision.end = '\0';
}

void	init(t_conv *conv)
{
	clean_flags(conv);
	conv->ret = 0;
	conv->counter = 0;
	conv->flags = NULL;
}