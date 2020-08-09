/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:36:15 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:36:19 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_presort(int *a, int *b, int *c)
{
	int	i;
	int	ind1;
	int	ind2;

	i = a[0];
	ind1 = a[0] / 3;
	ind2 = ind1 * 2;
	while (i--)
	{
		if (a[1] > c[ind2])
			ft_ra_rb(a, 'a');
		else if (a[1] <= c[ind1])
		{
			ft_pa_pb(b, a, 'b');
			ft_ra_rb(b, 'b');
		}
		else if (a[1] > c[ind1] && a[1] <= c[ind2])
			ft_pa_pb(b, a, 'b');
	}
	while (b[0])
		ft_pa_pb(a, b, 'a');
}

void	ft_sort_in_group(int *a, int *b, int index_c, int group)
{
	int	i;
	int	index_prev;
	int	index_prev_in_b;

	i = 0;
	index_prev_in_b = 0;
	index_prev = a[a[0]];
	while (i < group)
	{
		if (a[1] <= index_c)
		{
			if (a[1] == index_prev)
				index_prev_in_b++;
			sort_one_reverse_in_b(b, a);
			i++;
		}
		else
			ft_ra_rb(a, 'a');
	}
	ft_reverse_rrr(a, b, index_prev_in_b, index_prev);
	ft_reverse_rab_rrab(a, b, index_prev_in_b, index_prev);
	ft_pa_and_rotate_to_the_end(a, b, index_c);
}

void	ft_main_alg(int *a, int *b, int *c)
{
	int	index;
	int	group;
	int	notsort_elems;

	group = (a[0] < 300) ? 12 : 22;
	notsort_elems = a[0];
	index = 0;
	while (notsort_elems > 0)
	{
		if (notsort_elems >= group)
			index += group;
		else
		{
			index += notsort_elems;
			group = notsort_elems;
		}
		ft_sort_in_group(a, b, c[index], group);
		notsort_elems -= group;
	}
}

int		ft_many_numbers(int *a, int *b)
{
	int	*c;

	if (!(c = ft_memalloc(sizeof(int) * (a[0] + 1))))
		exit(-1);
	ft_memcpy(c, a, sizeof(int) * (a[0] + 1));
	ft_bubble_sort(c);
	ft_presort(a, b, c);
	ft_main_alg(a, b, c);
	while (ft_check_sort(a))
		ft_ra_rb(a, 'a');
	free(c);
	return (0);
}
