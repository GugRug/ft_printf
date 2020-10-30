#include "limits.h"
#include "stdio.h"
#include <unistd.h>

int main ()
{

	ft_printf("/********************     %%p     *******************/\n\n");


	int array_size = 5;
	int i = 0;
	unsigned int nb[] = {0, 6, 451, 2000000, UINT_MAX};

	while (i < array_size)
	{
		ft_printf("-------------------- start while loop with nb[%u] --------------------\n\n", nb[i]);

		ft_printf ("%d\n\n",  ft_printf("1 [%p]",  &nb[i]));

		ft_printf ("%d\n\n",  ft_printf("2 [NULL is undef] [%p]",  NULL));

		ft_printf ("%d\n\n",  ft_printf("1.1 [%5p]",  &nb[i]));


		ft_printf ("%d\n\n",  ft_printf("3 ! [%.p]",  &nb[i]));


		ft_printf ("%d\n\n",  ft_printf("3.4 ![%10.p]",  &nb[i]));


		ft_printf ("%d\n\n",  ft_printf("5 [%-5p]",  &nb[i]));

		int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)	
		{	
			ft_printf ("\n**********  [  * loop with %d ]  *********\n\n", nb_2[i_2]);

			ft_printf ("%d\n\n",    ft_printf("10 [%*p]", nb_2[i_2], &nb[i]));


			i_2++;
		}
		i++;

	}

}
