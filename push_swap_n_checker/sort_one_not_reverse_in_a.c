/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_not_reverse_in_a.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:36:54 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:36:58 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_if_min(int *a, int *b)
{
	int	min;

	min = ft_find_min(a);
	if (a[1] == min)
		ft_pa_pb(a, b, 'a');
	else
	{
		while (a[1] != min)
		{
			if (ft_find_index_elem(a, min) > a[0] / 2 + a[0] % 2)
				ft_rra_rrb(a, 'a');
			else
				ft_ra_rb(a, 'a');
		}
		ft_pa_pb(a, b, 'a');
	}
}

void	ft_if_max(int *a, int *b)
{
	int	max;

	max = ft_find_max(a);
	if (a[a[0]] == max)
		ft_pa_pb(a, b, 'a');
	else
	{
		while (a[a[0]] != max)
		{
			if (ft_find_index_elem(a, max) >= a[0] / 2 + a[0] % 2)
				ft_rra_rrb(a, 'a');
			else
				ft_ra_rb(a, 'a');
		}
		ft_pa_pb(a, b, 'a');
	}
	ft_ra_rb(a, 'a');
}

void	ft_sort_not_reverse_in_a(int *a, int *b)
{
	int	max;
	int	min;

	if (a[0] == 0)
		ft_pa_pb(a, b, 'a');
	else
	{
		max = ft_find_max(a);
		min = ft_find_min(a);
		if (b[1] > max)
			ft_if_max(a, b);
		else if (b[1] < min)
			ft_if_min(a, b);
		else
		{
			while (!(b[1] > a[a[0]] && b[1] < a[1]))
				ft_ra_rb(a, 'a');
			ft_pa_pb(a, b, 'a');
		}
	}
}
