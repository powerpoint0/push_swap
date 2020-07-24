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

void ft_5num(int *a, int *b)
{
	int i;
	ft_pa_pb(b, a , 'b');
	ft_pa_pb(b, a , 'b');
	ft_3num(a);
	while (!ft_pa_pb(a, b, 'a'))
	{
		if (a[1] > a[2] && a[1] > a[a[0]])
			ft_ra_rb(a, 'a');
		else
			{
				i = 1;
				while(a[i] > a[i + 1])
				{
					if (i != 1)
						ft_ra_rb(a, 'a');
					ft_sa_sb(a, 'a');
					i++;
				}
				while(a[1] > a[a[0]] && ft_check_sort(a))
					ft_rra_rrb(a, 'a');
			}
	}
}