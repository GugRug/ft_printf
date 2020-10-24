/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:01 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 19:20:41 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	clean_flags(t_conv *conv)
{
	conv->asterisk.state = 0;
	conv->minus.state = 0;
	conv->zero.state = 0;
	conv->point.state = 0;

}
void	init(t_conv *conv)
{
	clean_flags(conv);
	conv->content = 0;
	conv->len = 0;
	conv->counter = 0;
}