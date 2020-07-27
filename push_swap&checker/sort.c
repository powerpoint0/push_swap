//
// Created by Claudine Joaquin on 7/24/20.
//
#include "../push_swap.h"

void ft_2num(int *a, char letter)
{
	if (a[1] > a[2])
		ft_sa_sb(a, letter);
}

void ft_3num(int *a, char letter)
{
	int i;

	i = 1;
	if (a[i] < a[2] && a[i] < a[3])
	{
		ft_sa_sb(a, letter);
		ft_ra_rb(a, letter);
	}
	else if (a[i] > a[2] && a[2] < a[3] && a[i] < a[3])
		ft_sa_sb(a, letter);
	else if (a[i] < a[2] && a[2] > a[3] && a[i] > a[3])
		ft_rra_rrb(a, letter);
	else if (a[i] > a[2] && a[2] > a[3] && a[i] > a[3])
	{
		ft_sa_sb(a, letter);
		ft_rra_rrb(a, letter);
	}
	else if (a[i] > a[2] && a[2] < a[3] && a[i] > a[3])
		ft_ra_rb(a, letter);
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

int ft_find_min(int *a)
{
	int min;
	int k;

	k = 2;
	min = a[1];
	while(k <= a[0])
	{
		if (min > a[k])
			min = a[k];
		k++;
	}
	return(min);
}

int ft_find_index_elem(int *a, int number)
{
	int i;

	i = 1;
	while(i <= a[0])
	{
		if(a[i] == number)
			return(i);
		i++;
	}
	return(-1);
}

void ft_5num(int *a, int *b)
{

	int max;
	int min;

	while (a[0] > 3)
		ft_pa_pb(b, a , 'b');

	if(ft_check_sort(a))
		ft_3num(a, 'a');
	//if(ft_check_sort(b))
		//ft_2num(b, 'b');
	while(b[0])
	{
		max = ft_find_max(a);
		min = ft_find_min(a);
		if (b[1] > max)
		{
			if (a[a[0]] == max)
				ft_pa_pb(a, b, 'a');

			else {
				while (a[a[0]] != max)
				{
					if (ft_find_index_elem(a, max) >= a[0] / 2 + a[0]% 2)
						ft_rra_rrb(a, 'a');
					else
						ft_ra_rb(a, 'a');
				}
				ft_pa_pb(a, b, 'a');
			}
			//ft_ra_rb(a, 'a');
		}
		else if (b[1] < min)
		{
			if (a[1] == min)
				ft_pa_pb(a, b, 'a');
			else {
				while (a[1] != min)
				{
					if (ft_find_index_elem(a, min) > a[0] / 2 + a[0]%2)
						ft_rra_rrb(a, 'a');
					else
						ft_ra_rb(a, 'a');
				}
				ft_pa_pb(a, b, 'a');
			}
		}
		else
		{
			while (!(b[1] > a[a[0]] && b[1] < a[1]))
				ft_ra_rb(a, 'a');
			ft_pa_pb(a, b, 'a');
		}
	}
	while(ft_check_sort(a))
	{
		if(ft_find_index_elem(a, min) > a[0] / 2 + a[0]%2)
			ft_rra_rrb(a, 'a');
		else
			ft_ra_rb(a, 'a');
	}
}