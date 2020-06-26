#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int ft_check_error(int argc, char **argv, int *a)
{
	int j;
	int	i;

	j = 1;
	i= 0;
	while(j< argc)
	{
		while(argv[j][i])
		{
			if(ft_isdigit(argv[j][i]))
				i++;
			else
			{
				write(0, "Error\n", 6);
				free(a);
				exit(-1);
			}
		}
		j++;
	}
	j = 0;
	i = 0;
	while(j++ <argc)
		a[i++] = ft_atoi(argv[j]);
	i= 0;
	while(a[i])
	{
		while(a[i+j])
		{
			if(a[i] == )
		}
		i++;
	}
	/*perevod v chisla, proverka:
	 * 1.znaki ot 0 do 9 +-				++
	 * 2.atoi							++
	 * 3.chislo <=int_max, >= int_min   ---
	 * 4.povtorenie chisel
	 *
	 * esli oshibka, to
	 * write(0,"Error\n", 6);
	 * free(a);
	 * exit(-1);
	*/
	return(0);
}

int main(int argc, char **argv)
{
	int *a;
	int *b;

	if(argc <= 1)
	{
		write(0,"Error\n", 6);
		return(-1);
	}
	//1chislo ili sortirov.-return(0)
	a = ft_memalloc(argc);
	ft_check_error(argc, argv,a);
	b = ft_memalloc(argc);
	//sortirovka
	free(b);
	return 0;

}
