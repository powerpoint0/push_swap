#include "../push_swap.h"

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
	i = 1;
	while(j++ < argc-1)//zapisyvaem chisla v massiv int
		a[i++] = ft_atoi_with_check(argv[j], a);
	if(argc == 2)// odno chislo
	{
		free(a);
		exit(0);
	}
	a[0] = argc - 1;
	return 0;
}

void ft_check_repeat_numbers(int *a)        //chisla povtoryautsya?
{
	int	i;
	int n;

	i = 1;
	n= 1;
	while (i < a[0])
	{
		while (i + n <= a[0])
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

void* ft_check_sort_and_b_ps(int argc, int *a, int *b)               //chisla sortirovany
{
	int i;

	i = 1;
	while ((i < a[0]) && (a[i] < a[i+1]))
		i++;
	if (i == a[0])
	{
		free(a);
		exit(0);
	}
	if (!(b = (int*)malloc(sizeof(*b) * argc)))
	{
		write(2,"Error\n", 6);
		free(a);
		exit(-1);
	}
	b[0] = 0;
	return(b);
}

void* ft_check_error_and_write_numbers(int argc, char **argv, int *a)
{
	if (argc <= 1 || (!(a = (int*)malloc(sizeof(*a) * argc))))
	{
		write(2,"Error\n", 6);
		exit(-1);
	}
//	if (!(a = (int*)malloc(sizeof(*a) * argc)))
//		exit(-1);
	ft_is_all_number(argc, argv, a);
	ft_write_numbers_one_number(argc, argv, a);
	ft_check_repeat_numbers(a);
	//if (ft_check_sort(a))

//	if (!(b = (int*)malloc(sizeof(*b) * argc)))
//	{
//		write(2,"Error\n", 6);
//		free(a);
//		exit(-1);
//	}
//	b[0] = 0;
	return(a);
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