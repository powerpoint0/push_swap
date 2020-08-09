/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_reverse_in_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:37:13 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:37:16 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_if_min_in_b(int *b, int *a)
{
	int	min;

	min = ft_find_min(b);
	if (b[b[0]] == min)
		ft_pa_pb(b, a, 'b');
	else
	{
		while (b[b[0]] != min)
		{
			if (ft_find_index_elem(b, min) >= b[0] / 2 + b[0] % 2)
				ft_rra_rrb(b, 'b');
			else
				ft_ra_rb(b, 'b');
		}
		ft_pa_pb(b, a, 'b');
	}
}

void	ft_if_max_in_b(int *b, int *a)
{
	int	max;

	max = ft_find_max(b);
	if (b[1] == max)
		ft_pa_pb(b, a, 'b');
	else
	{
		while (b[1] != max)
		{
			if (ft_find_index_elem(b, max) > b[0] / 2 + b[0] % 2)
				ft_rra_rrb(b, 'b');
			else
				ft_ra_rb(b, 'b');
		}
		ft_pa_pb(b, a, 'b');
	}
}

void	sort_one_reverse_in_b(int *b, int *a)
{
	int	max;
	int	min;

	if (b[0] == 0)
		ft_pa_pb(b, a, 'b');
	else
	{
		max = ft_find_max(b);
		min = ft_find_min(b);
		if (a[1] < min)
			ft_if_min_in_b(b, a);
		else if (a[1] > max)
			ft_if_max_in_b(b, a);
		else
		{
			while (!(a[1] < b[b[0]] && a[1] > b[1]))
				ft_ra_rb(b, 'b');
			ft_pa_pb(b, a, 'b');
		}
	}
}
