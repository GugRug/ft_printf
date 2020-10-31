/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:13 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 21:25:58 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string_null(t_conv *conv)
{
	char *temp;

	conv->invalid = 1;
	conv->sp_print = (char*)malloc(sizeof(char*) * 7);
	temp = (char*)malloc(sizeof(char*) * 7);
	temp[0] = '(';
	temp[1] = 'n';
	temp[2] = 'u';
	temp[3] = 'l';
	temp[4] = 'l';
	temp[5] = ')';
	temp[6] = '\0';
	return (temp);
}

void	ft_temp_cpy(t_conv *conv, char *temp)
{
	int	i;

	i = 0;
	if (conv->precision.state == 1 && temp)
		while (temp[i] != '\0' && i < conv->precision.content)
		{
			conv->sp_print[i] = temp[i];
			i++;
		}
	else
		while (temp && temp[i] != '\0')
		{
			conv->sp_print[i] = temp[i];
			i++;
		}
	conv->sp_print[i] = '\0';
}

void	ft_s_print(t_conv *conv, va_list args)
{
	char	*temp;

	temp = va_arg(args, char *);
	if (!temp)
		temp = ft_string_null(conv);
	else
		conv->sp_print = (char*)malloc(sizeof(char*) * ft_strlen(temp) + 2);
	ft_temp_cpy(conv, temp);
	if (conv->invalid == 1)
	{
		free(temp);
		temp = NULL;
		conv->invalid = 0;
	}
	conv->precision.state = 0;
	conv->precision.content = 0;
	ft_exec_flags(conv);
}
