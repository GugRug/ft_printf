/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:45:31 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 17:09:30 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main(void)
{
	int a = -10, b = 50; unsigned int un = 50; char c = 0; int he = 17080; 
	int ft = 0;
	int ft2 = 0;
	char *str = NULL;
	int *addr = NULL;
	// ft_printf("Isso e um teste basico:\n|%d|\n", 35);
	// ft_printf("Isso e um teste basico:\n|%s|\n", "testa");
	// printf("Isso e o pf %.5- real \n%d, %i, %u, %c, %s, %x, %X, %p\n", -234, 3834567899, 3834567899,'h', "abacate", 163, 32456, &a);
	// ft_printf("Isso e um teste basico \n%d, %i, %u, %c, %s, %x, %X, %p\n", -234, 3834567899, 3834567899,'h', "abacate", 163, 32456, &a);
	// ft_printf("Isso e um teste basico \n%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", c, c, c, c, c, c, c, c, c, c, 12, c, 12, c, 12, c, 12, c);
	// printf("Isso e um teste basico \n%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", c, c, c, c, c, c, c, c, c, c, 12, c, 12, c, 12, c, 12, c);
	ft = ft_printf("ft_printf |%-*c|\n", 5, c);
	ft2 = printf("printf_pf |%-*c|\n", 5, c);
	printf("ft_printf: %d | printf: %d\n", ft, ft2);
	// ft_printf("INTEGERS\n");
	// ft_printf("ft_printf |%-*d|	-	", 3, a);printf("|%-*d| Correto\n", 3, a, b);
	// ft_printf("ft_printf |%-05d|	-	", a);printf("|%-05d| Correto\n", a);
	// ft_printf("ft_printf |%-5d|	-	", a);printf("|%-5d| Correto\n", a);
	// ft_printf("ft_printf |%.9d|	-	", a);printf("|%.9d| Correto\n", a);
	// ft_printf("ft_printf |%-.9d|	-	", a);printf("|%-.9d| Correto\n", a);
	// ft_printf("ft_printf |%5.2d|	-	", a);printf("|%5.2d| Correto\n", a);
	// ft_printf("ft_printf |%010.2d|	-	", a);printf("|%010.2d| Correto\n", a);


	// ft_printf("UNSIGNED INT\n");
	// ft_printf("ft_printf |%-*u|	-	", 3, un);printf("|%-*u| Correto\n", 3, un);
	// ft_printf("ft_printf |%05u|	-	", un);printf("|%05u| Correto\n", un);
	// ft_printf("ft_printf |%-05u|	-	", un);printf("|%-05u| Correto\n", un);
	// ft_printf("ft_printf |%.9u|	-	", un);printf("|%.9u| Correto\n", un);
	// ft_printf("ft_printf |%-.9u|	-	", un);printf("|%-.9u| Correto\n", un);
	// ft_printf("ft_printf |%5.2u|	-	", un);printf("|%5.2u| Correto\n", un);
	// ft_printf("ft_printf |%010.2u|	-	", un);printf("|%010.2u| Correto\n", un);

	// ft_printf("HEXDx -> %x\n", he);
	// ft_printf("ft_printf |%-*x|	-	", 8, he);printf("|%-*x| Correto\n", 8, he);
	// ft_printf("ft_printf |%05x|	-	", he);printf("|%05x| Correto\n", he);
	// ft_printf("ft_printf |%-05x|	-	", he);printf("|%-05x| Correto\n", he);
	// ft_printf("ft_printf |%.9x|	-	", he);printf("|%.9x| Correto\n", he);
	// ft_printf("ft_printf |%-.9x|	-	", he);printf("|%-.9x| Correto\n", he);
	// ft_printf("ft_printf |%5.2x|	-	", he);printf("|%5.2x| Correto\n", he);
	// ft_printf("ft_printf |%010.8x|	-	", he);printf("|%010.8x| Correto\n", he);

	// ft_printf("CHARS\n");
	// ft_printf("ft_printf |%-*c|	-	", 3, c);printf("|%-*c| Correto\n", 3, c);
	// ft_printf("ft_printf |%05c|	-	", c);printf("|%05c| Correto\n", c);
	// ft_printf("ft_printf |%-05c|	-	", c);printf("|%-05c| Correto\n", c);
	// ft_printf("ft_printf |%.9c|	-	", c);printf("|%.9c| Correto\n", c);
	// ft_printf("ft_printf |%-.9c|	-	", c);printf("|%-.9c| Correto\n", c);
	// ft_printf("ft_printf |%5.2c|	-	", c);printf("|%5.2c| Correto\n", c);
	// ft_printf("ft_printf |%010.2c|	-	", c);printf("|%010.2c| Correto\n", c);

	// ft_printf("String -> %s\n", str);
	// ft_printf("ft_printf |%-*s|	-	", 8, str);printf("|%-*s| Correto\n", 8, str);
	// ft_printf("ft_printf |%050s|	-	", str);printf("|%050s| Correto\n", str);
	// ft_printf("ft_printf |%-050s|	-	", str);printf("|%-050s| Correto\n", str);
	// ft_printf("ft_printf |%.9s|	-	", str);printf("|%.9s| Correto\n", str);
	// ft_printf("ft_printf |%-.9s|	-	", str);printf("|%-.9s| Correto\n", str);
	// ft_printf("ft_printf |%5.4s|	-	", str);printf("|%5.4s| Correto\n", str);
	// ft_printf("ft_printf |%010.8s|	-	", str);printf("|%010.8s| Correto\n", str);

	// ft_printf("Adress -> %p\n", addr);
	// ft_printf("ft_printf |%-*p|	-	", 15, addr);printf("|%-*p| Correto\n", 15, addr);
	// ft_printf("ft_printf |%020.10p|	-	", addr);printf("|%020.10p| Correto\n", addr);
	// ft_printf("ft_printf |%-050p|	-	", addr);printf("|%-050p| Correto\n", addr);
	// ft_printf("ft_printf |%.90p|	-	", addr);printf("|%.90p| Correto\n", addr);
	// ft_printf("ft_printf |%-.9p|	-	", addr);printf("|%-.9p| Correto\n", addr);
	// ft_printf("ft_printf |%5.4p|	-	", addr);printf("|%5.4p| Correto\n", addr);
	// ft_printf("ft_printf |%15.30p|	-	", addr);printf("|%15.30p| Correto\n", addr);
	return (0);
}