/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:35:22 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:35:26 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_ra_rb(int *a, char letter)
{
	int k;
	int c;

	k = 1;
	if (a[0] <= 1)
		return(-1);
	c = a[1];
	while(k < a[0])
	{
		a[k] = a[k + 1];
		k++;
	}
	a[*a] = c;
	if (letter == 'n')
		return(0);
	letter == 'a' ? write(1, "ra\n", 3) :  write(1, "rb\n", 3);
	return(0);
}


int ft_rr(int *a,int *b)
{
	ft_ra_rb(a, 'n');
	ft_ra_rb(b, 'n');
	write(1, "rr\n", 3);
	return(0);
}

int ft_rra_rrb(int *a, char letter)
{
	int k;
	int c;

	k = a[0];
	c = a[k];

	if(a[0] <= 1)
		return(-1);
	while(k > 1)
	{
		a[k] = a[k - 1];
		k--;
	}
	a[1] = c;
	if (letter == 'n')
		return(0);
	letter == 'a' ? write(1, "rra\n", 4) :  write(1, "rrb\n", 4);
	return(0);
}

int ft_rrr(int *a, int *b)
{
	ft_rra_rrb(a, 'n');
	ft_rra_rrb(b, 'n');
	write(1, "rrr\n", 4);
	return(0);
}

