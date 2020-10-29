/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:07 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/29 16:45:04 by gumartin         ###   ########.fr       */
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
		if (conv->flags[i] == '-')
			conv->minus.state = 1;
		else if (conv->flags[i] == '0')	
		{						//will only read the flag without mixing with width 
			if (conv->precision.state == 0)			//before precision
				conv->zero.state = 1;
		}
		else if (conv->flags[i] == '.')
		{
			conv->precision.state = 1;
			conv->zero.state = 0;
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
	*ref += (conv->len_atoi - 1);
	conv->len_atoi = 0;
}

void	ft_flag_asterisk(t_conv *conv, va_list args)
{	//delete asterisk atributes if wont use it
	if (conv->precision.state == 0)
	{
		conv->width.state = 1;
		conv->width.content = va_arg(args, int);
	}
	else
	{
		conv->precision.content = va_arg(args, int);
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
	conv->len_atoi = i;
	return (soma);
}

void	ft_exec_flags(t_conv *conv)
{
	// change conv->sp_len inside this func)
	if (conv->minus.state == 1)
		conv->zero.state == 0;
	if (conv->precision.state == 1 && conv->precision.content != 0)
		put_precision(conv); //Join string with zeros and sp_print, need negative treatment
	if (conv->width.state == 1 && conv->width.content != 0)
		put_width(conv);
	if (conv->part_chr[0] != '\0')
		conv->sp_print =  ft_strjoin(conv->part_chr, conv->sp_print);
	ft_putstr(conv, conv->sp_print);
	free(conv->sp_print);
	conv->sp_print = NULL;
	conv->counter += conv->len;
}

//CREATE A CONV->SPE_STR, TO BE A - OR 0X IN THE BEGINING
void	put_precision(t_conv *conv)
{
	char	*temp;
	int		size;

	size = conv->precision.content - ft_strlen(conv->sp_print);
	if (size > 0)
	{
	temp = strbuild(conv, '0', size);
	conv->sp_print =  ft_strjoin(temp, conv->sp_print);
	free(temp);
	temp = NULL;
	}
}

void	put_width(t_conv *conv)
{
	char	*temp;
	char	c;
	int		size;

	size = conv->width.content - (ft_strlen(conv->sp_print) + ft_strlen(conv->part_chr));
	c = ' ';
	if (conv->zero.state == 1 && conv->minus.state == 0)
		c = '0';
	if (size > 0)
	{
	temp = strbuild(conv, c, size);
	if(conv->minus.state == 0)
		conv->sp_print =  ft_strjoin(temp, conv->sp_print);
	else	
		conv->sp_print =  ft_strjoin(conv->sp_print, temp);
	free(temp);
	temp = NULL;
	}
}

char	*strbuild(t_conv *conv, char c, int n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char*)malloc(sizeof(char*) * (n + 1));
	while (i < n)
	{
		temp[i]	= c;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}





