#include "../push_swap.h"

int	ft_is_all_numbers2(char **argv, int j)
{
	int	i;
	int k;

	k = 0;
	i= 0;
	while(argv[j][i] != '\0')
	{
		if (argv[j][i] == '-' || argv[j][i] == '+')
			i++;
		while (argv[j][i] && argv[j][i] != ' ') {
			if (ft_isdigit(argv[j][i]))
				i++;
			else {
				write(2, "Error\n", 6);
				exit(-1);
			}
		}
		k++;
		if (argv[j][i] == ' ')
			i++;
	}
	return(k);
}

int ft_is_all_number(int argc, char **argv)
{
	int j;
	int k;

	k = 0;
	j = 1;

	while(j< argc)
	{
		if (argc == 2 && (argv[1][0] == '\0'))
			exit(-1);
		k += ft_is_all_numbers2(argv, j);
		j++;
	}
	return(k);
}

int		ft_atoi_with_check(const char *str)
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
		exit(-1);
	}
	return ((int)resalt);
}

int ft_write_numbers_one_number(char **argv, int *a, int kolvo_num)
{
	int j;
	int	i;
	char *str;
	int k;

	k = 0;
	j = 1;
	i = 0;
	str = argv[1];
	while(i++ < kolvo_num)   //zapisyvaem chisla v massiv int
	{
		a[i] = ft_atoi_with_check(str);
		while(argv[j][k] && argv[j][k]!= ' ')
			k++;
		if (i < kolvo_num)
		{
			if(argv[j][k] == ' ')
				str = &argv[j][++k];
			else
			{
				j++;
				k = 0;
				while(!argv[j][k])
					j++;
				str = &argv[j][k];
			}
		}
	}
	if(kolvo_num == 1)// odno chislo
	{
		free(a);
		exit(0);
	}
	if (kolvo_num == 0)
	{
		write(2, "Error\n", 6);
		free(a);
		exit(-1);
	}
	a[0] = kolvo_num;
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

void* ft_check_sort_and_b_ps(int *a, int *b)  //+++++          //chisla sortirovany
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
	if (!(b = (int*)malloc(sizeof(*b) * a[0])))
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
	int kolvo_numbers;

	if (argc <= 1)
		exit(-1);
	kolvo_numbers = ft_is_all_number(argc, argv);
	//printf("%d\n", kolvo_numbers);
	if (!(a = (int*)malloc(sizeof(*a) * (kolvo_numbers + 1))))
		exit(-1);
	ft_write_numbers_one_number(argv, a, kolvo_numbers);

	ft_check_repeat_numbers(a);
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