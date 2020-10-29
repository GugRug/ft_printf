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
{	//state 0 empty, 1 full, 2 used
	conv->minus.state = 0;
	conv->zero.state = 0;
	conv->width.state = 0;
	conv->precision.state = 0;
	conv->minus.content = 0;
	conv->zero.content = 0;
	conv->width.content = 0;
	conv->precision.content = 0;
	conv->len = 0;
	conv->len_atoi = 0;
	conv->specifier = '\0';
	conv->part_chr[0] = '\0';
	conv->part_chr[1] = '\0';
	conv->part_chr[2] = '\0';
}

void	init(t_conv *conv)
{
	clean_flags(conv);
	conv->ret = 0;
	conv->counter = 0;
	conv->sp_print = NULL;
	conv->flags = NULL;
}