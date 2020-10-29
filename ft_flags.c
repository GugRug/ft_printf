/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:07 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/28 03:56:37 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//Implementing without error treatment
//after this functions, you should expect to have all meaningful data stored in struct atributes

void	ft_read_flags(t_conv *conv, va_list args)
{
	int i;

	i = 0;
	while (conv->flags[i] != '\0')
	{
		if (conv->flags[i] == '-')				//position only will be used in validation data if necessary, maybe delete it later
		{
			conv->minus.state = 1;
			conv->minus.position = i;
		}
		else if (conv->flags[i] == '0')
		{											//will only read the flag without mixing with width 
			if (conv->precision.state == 0)			//before precision
				conv->zero.state = 1;
			conv->zero.position = i;
		}
		else if (conv->flags[i] == '.')
		{
			conv->precision.state = 1;
			conv->precision.position = i;
		}
		else if (conv->flags[i] == '*')				//need to paralell *, one to width and other to precision. do this function later
		{
			ft_flag_asterisk(conv, args);
		}
		else if (ft_isnum(conv->flags[i]))
			ft_flag_num(conv, args, &i);			//deal with all sequencial numbers from here, after it, 
  													//need only i++ one time to skip number
		i++;
	}
}


void	ft_flag_num(t_conv *conv, va_list args, int *ref)
{
	if (conv->precision.state == 0)
	{
		conv->width.state = 1;											// if need to use width position, set here
		conv->width.content = ft_pf_atoi(conv,&(conv->flags[*ref]));
	}
	else
		conv->precision.content = ft_pf_atoi(conv,&(conv->flags[*ref]));
	*ref += conv->len_atoi;
	conv->len_atoi = 0;
}

void	ft_flag_asterisk(t_conv *conv, va_list args)
{	//delete asterisk atributes if wont use it
	if (conv->precision.state == 0)
	{
		conv->asterisk.state = 1;
		conv->asterisk.content = va_arg(args, int);
		conv->width.state = 1;
		conv->width.content = conv->asterisk.content;
	}
	else
	{
		conv->asterisk.state_2 = 1;
		conv->asterisk.content_2 = va_arg(args, int);
		conv->precision.state = 1;
		conv->precision.content = conv->asterisk.content_2;
	}
}

int		ft_pf_atoi(t_conv *conv, char *str)
{
	int i;
	int soma;
	
	i = 0;
	soma = 0;
	while (str[i] && ft_isnum(str[i]))
	{
		soma = (soma * 10) + (str[i] - '0');
		i++;
	}
	return (soma);
}

void	ft_exec_flags(t_conv *conv, size_t nb)
{
	// change conv->sp_len inside this func)
	if (conv->minus.state == 1)
		conv->zero.state == 0;
	if (conv->precision.state == 1 && conv->precision.content != 0)
		put_precision(conv); //Join string with zeros and sp_print, need negative treatment
	if (conv->width.state == 1 && conv->width.content != 0)
		put_width(conv);
	ft_putstr(conv, conv->sp_print);
}

//CREATE A CONV->SPE_STR, TO BE A - OR 0X IN THE BEGINING
void	put_precision(t_conv conv)
{

}

void	put_width(t_conv conv)
{
	
}