/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:13 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/29 17:35:18 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_s_print(t_conv *conv, va_list args)
{
	int		i;
	char	*temp;
	
	conv->zero.state = 0;
	i = 0;
	temp = va_arg(args, char *);
	conv->sp_print = (char*)malloc(sizeof(char*) * ft_strlen(temp) + 2);
	if (conv->precision.state == 1)
	{
		while (temp[i] != '\0' && i < conv->precision.content)
		{
			conv->sp_print[i] = temp[i];
			i++;
		}	
	}
	else
	{	
		while (temp[i] != '\0')
		{
			conv->sp_print[i] = temp[i];
			i++;
		}
	}
	conv->precision.state = 0;
	conv->precision.content = 0;
	conv->sp_print[i] = '\0';
	ft_exec_flags(conv);
}