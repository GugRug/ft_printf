/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:00:24 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 01:20:26 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

#define MAX_FLAGS 4

typedef struct	s_spec
{
	unsigned char	specifier;
	int		flags[MAX_FLAGS];
	size_t			content;
	int				size;
	int				counter;
	char			*print;
	char			*conv;
	
}				t_spec;

void	inic(t_spec *spec);
void	ft_putnbr(int nb, t_spec *print);

#endif