/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 05:23:50 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/25 17:38:37 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	int_to_char(t_conv *conv, size_t n)
{
	char	c;
	if (n < 10)
		c = n + '0';
	else if (n < 16 && conv->specifier == 'p')
		c = n + (conv->specifier - ('p' - 'a' +10));
	else if (n < 16)
		c = n + (conv->specifier - ('x' - 'a' +10));
	ft_putchar(conv, c);
}

void	ft_putchar(t_conv *conv, char c)
{
	write(1, &c, 1);
	conv->ret++;
}

void	ft_putstr(t_conv *conv, char *s)
{
	if (s)
		while (*s)
		{
		ft_putchar(conv, *s);
		s++;
		}
}

int		ft_isnum(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char                    *sub;
	unsigned int    i;

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

// size_t	ft_strlen(const char *str)
// {
// 	size_t i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
