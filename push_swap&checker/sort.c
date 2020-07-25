//
// Created by Claudine Joaquin on 7/24/20.
//
#include "../push_swap.h"

void ft_2num(int *a)
{
	if (a[1] > a[2])
		ft_sa_sb(a, 'a');
}

void ft_3num(int *a)
{
	int i;

	i = 1;
	if (a[i] < a[2] && a[i] < a[3])
	{
		ft_sa_sb(a, 'a');
		ft_ra_rb(a, 'a');
	}
	else if (a[i] > a[2] && a[2] < a[3] && a[i] < a[3])
		ft_sa_sb(a, 'a');
	else if (a[i] < a[2] && a[2] > a[3] && a[i] > a[3])
		ft_rra_rrb(a, 'a');
	else if (a[i] > a[2] && a[2] > a[3] && a[i] > a[3])
	{
		ft_sa_sb(a, 'a');
		ft_rra_rrb(a, 'a');
	}
	else if (a[i] > a[2] && a[2] < a[3] && a[i] > a[3])
		ft_ra_rb(a, 'a');
}

int ft_check_sort(int *a)               //chisla sortirovany
{
	int i;

	i = 1;
	if(a[0] == 0)
		return(-1);
	while ((i < a[0]) && (a[i] < a[i + 1]))
		i++;
	if (i == a[0])
		return (0);
	return (-1);
}

int ft_find_max(int *a)
{
	int max;
	int k;

	k = 2;
	max = a[1];
	while(k <= a[0])
	{
		if (max < a[k])
			max = a[k];
		k++;
	}
	return(max);
}

void ft_5num(int *a, int *b)
{
	int i;
	int max;

	ft_pa_pb(b, a , 'b');
	ft_pa_pb(b, a , 'b');
	if(ft_check_sort(a))
		ft_3num(a);
	while(b[0])
	{
		max = ft_find_max(a);
		if (b[1] < max)
		{
			while ((b[1] > a[1] ))//&& b[1] >= 0) ||(b[1] <a[1] && b[1] < 0))
				ft_ra_rb(a, 'a');
			ft_pa_pb(a, b, 'a');
		}
		else
		{
			while (a[1] != max)
				ft_ra_rb(a, 'a');
			ft_ra_rb(a, 'a');
			ft_pa_pb(a, b, 'a');
		}
	}
	while(ft_check_sort(a))
		ft_ra_rb(a, 'a');
}

