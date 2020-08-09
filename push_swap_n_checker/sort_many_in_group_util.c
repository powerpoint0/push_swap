/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_in_group_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:36:35 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:36:39 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rrr(int *a, int *b, int index_prev_in_b, int index_prev)
{
	int	maxb;

	maxb = ft_find_max(b);
	if (!index_prev_in_b)
	{
		while (a[a[0]] != index_prev && b[1] != ft_find_max(b))
		{
			if ((ft_find_index_elem(a, index_prev) >= a[0] / 2 + a[0] % 2)
				&& (ft_find_index_elem(b, maxb) > b[0] / 2 + b[0] % 2))
				ft_rrr(a, b, 'a');
			else if ((ft_find_index_elem(a, index_prev) < a[0] / 2 + a[0] % 2)
			&& (ft_find_index_elem(b, maxb) <= b[0] / 2 + b[0] % 2))
				ft_rr(a, b, 'a');
			else
				break ;
		}
	}
}

void	ft_reverse_rab_rrab(int *a, int *b, int index_prev_in_b, int index_prev)
{
	int	maxb;

	maxb = ft_find_max(b);
	if (!index_prev_in_b)
	{
		while (a[a[0]] != index_prev)
		{
			if (ft_find_index_elem(a, index_prev) >= a[0] / 2 + a[0] % 2)
				ft_rra_rrb(a, 'a');
			else
				ft_ra_rb(a, 'a');
		}
	}
	while (b[1] != ft_find_max(b))
	{
		if (ft_find_index_elem(b, maxb) > b[0] / 2 + b[0] % 2)
			ft_rra_rrb(b, 'b');
		else
			ft_ra_rb(b, 'b');
	}
}

void	ft_pa_and_rotate_to_the_end(int *a, int *b, int index_c)
{
	while (b[0])
		ft_pa_pb(a, b, 'a');
	while (a[a[0]] != index_c)
	{
		if (ft_find_index_elem(a, index_c) >= a[0] / 2 + a[0] % 2)
			ft_rra_rrb(a, 'a');
		else
			ft_ra_rb(a, 'a');
	}
}
