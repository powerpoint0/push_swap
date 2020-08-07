/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_n_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:34:32 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:34:38 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void ft_if_one_number_or_0(int *a)
{
	int kolvo_num;

	kolvo_num = a[0];
	if(kolvo_num == 1)
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
}

void ft_write_numbers_in_a(char **argv, int *a, int kolvo_num)
{
	int j;
	int	i;
	char *str;
	int k;

	k = 0;
	j = 1;
	i = 0;
	while(i < kolvo_num)   //zapisyvaem chisla v massiv int
	{
		while(argv[j][k] && argv[j][k]== ' ')
			k++;
		if (argv[j][k])
		{
			str = &argv[j][k];
			a[++i] = ft_atoi_with_check(str);
			while (argv[j][k] && argv[j][k]!= ' ')
				k++;
		}
		else
		{
			j++;
			k = 0;
		}
	}
}

void ft_check_repeat_numbers(int *a)
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

void* ft_check_error_and_write_numbers(int argc, char **argv, int *a)
{
	int kolvo_numbers;

	if (argc <= 1)
		exit(-1);
	kolvo_numbers = ft_is_all_numbers_n_less_ll(argc, argv);
	if (!(a = (int*)malloc(sizeof(*a) * (kolvo_numbers + 2))))
		exit(-1);
	ft_write_numbers_in_a(argv, a, kolvo_numbers);
	a[0] = kolvo_numbers;
	ft_if_one_number_or_0(a);
	ft_check_repeat_numbers(a);
	return(a);
}
