#include "push_swap.h"

void ft_is_all_number(int argc, char **argv, int *a)
{
	int j;
	int	i;

	j = 1;
	i= 0;
	while(j< argc)   //proverka:vse li chisla
	{
		if (argv[j][i] == '-' || argv[j][i] == '+')
			i++;
		while(argv[j][i])
		{
			if(ft_isdigit(argv[j][i]))
				i++;
			else
			{
				write(2, "Error\n", 6);
				free(a);
				exit(-1);
			}
		}
		i = 0;
		j++;
	}
}

int		ft_atoi_with_check(const char *str, int *a)
{
	long long	sign;
	long long	resalt;

	resalt = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		resalt = resalt * 10 + (*str - '0');
		str++;
	}
	resalt *= sign;
	if (resalt > INT32_MAX || resalt < INT32_MIN)				//some arguments are bigger than an integer,
	{
			write(2, "Error\n", 6);
			free(a);
			exit(-1);
	}
	return ((int)resalt);
}

int ft_write_numbers_one_number(int argc, char **argv, int *a)
{
	int j;
	int	i;

	j = 0;
	i = 0;
	while(j++ < argc-1)//zapisyvaem chisla v massiv int
		a[i++] = ft_atoi_with_check(argv[j], a);
	if(argc == 2)// odno chislo
	{
		free(a);
		exit(0);
	}

	return 0;
}

void ft_check_repeat_numbers(int argc, char **argv, int *a)        //chisla povtoryautsya?
{
	int	i;
	int end;
	int n;

	end = argc - 2;
	i = 0;
	n= 1;
	while (i <= end - 1)
	{
		while (i + n <= end)
		{
			if (a[i] == a[i + n])
			{
				write(2, "Error\n", 6);
				free(a);
				exit(-1);
			}
			else
				n++;
		}
		n = 1;
		i++;
	}
}

int ft_check_sort(int argc, int *a)               //chisla sortirovany
{
	int i;
	int end;

	end = argc - 2;
	i = 0;
	while ((i < end) && (a[i] < a[i+1]))
			i++;
	if (i == end)
	{
		free(a);
		exit(0);
	}
	return(0);
}

int ft_check_error_and_write_numbers(int argc, char **argv, int *a)
{
	ft_is_all_number(argc, argv, a);
	ft_write_numbers_one_number(argc, argv, a);
	ft_check_repeat_numbers(argc, argv, a);
	ft_check_sort(argc, a);
	return(0);
}

	/*1.perevod v chisla, proverka: ++++++++++
	 *
	 * 1.znaki ot 0 do 9 +-				++
	 * 2.atoi							++
	 *  0.1chislo ili sortirovano       ++
	 * 3.chislo <=int_max, >= int_min   ++
	 * 4.povtorenie chisel              ++
	 *
	 * esli oshibka, to
	 * write(0,"Error\n", 6);
	 * exit(-1);
	*/
	///////////


int main(int argc, char **argv)
{
	int *a;
	int *b;
	int i = 0;

	if (argc <= 1)
	{
		write(2,"Error\n", 6);
		exit(-1);
	}
	if (!(a = (int*)malloc(sizeof(*a) * argc)))
		return(0);
	ft_check_error_and_write_numbers(argc, argv, a);
	if (!(b = (int*)malloc(sizeof(*b) * argc)))
		return(0);
	//sortirovka
	while (i < argc -1)
	{
		printf("%d", a[i]);
		i++;
	}
	free(a);
	free(b);
	return 0;
}
