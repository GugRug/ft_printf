/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 05:23:50 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 21:24:10 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(t_conv *conv, char c)
{
	write(1, &c, 1);
	conv->ret++;
}

void	ft_putstr_invalid(t_conv *conv, char *s)
{
	int	i;

	i = 0;
	conv->sp_print = (char*)malloc(sizeof(char*) * (ft_strlen(s) + 1));
	while (s[i])
	{
		conv->sp_print[i] = s[i];
		i++;
	}
	conv->sp_print[i] = '\0';
	conv->invalid = 0;
}

void	ft_putstr(t_conv *conv, char *s)
{
	if (conv->invalid == 1)
	{
		ft_putstr_invalid(conv, s);
	}
	else if (s)
	{
		while (*s || conv->char_zero == 1)
		{
			if (conv->char_zero == 1 && *s == 'W')
			{
				ft_putchar(conv, 0);
				conv->char_zero = 0;
			}
			else
				ft_putchar(conv, *s);
			s++;
		}
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (s != NULL)
	{
		sub = (char*)malloc(sizeof(char) * (len + 1));
		if (!sub)
			return (0);
		i = 0;
		while (i < len && s[i + start])
		{
			sub[i] = s[i + start];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}

char	*ft_strjoin(t_conv *conv, char *s1, char *s2)
{
	char	*join;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	join = (char*)malloc(sizeof(char) * len + 1);
	while (*s1 != '\0' && i < len)
		join[i++] = *(s1++);
	while (*s2 != '\0' && i < len)
		join[i++] = *(s2++);
	join[i] = '\0';
	free(conv->sp_print);
	conv->sp_print = NULL;
	return (join);
}
