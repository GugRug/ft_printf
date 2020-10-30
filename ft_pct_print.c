/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pct_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:45:12 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 15:53:57 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_pct_print(t_conv *conv, va_list args)
{
	ft_putchar(conv, '%');
	conv->counter += conv->len;
}