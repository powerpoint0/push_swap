/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:37:36 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:37:45 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_check_sort(int *a)
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

int ft_bubble_sort(int *a)
{
	int i;
	int c;
	int n;

	n = 1;
	i = 1;
	while (i < a[0]) {
		while (i + n <= a[0]) {
			if (a[i] > a[i + n])
			{
				c = a[i];
				a[i] = a[i + n];
				a[i + n] = c;
			}
			n++;
		}
		n = 1;
		i++;
	}
}

int ft_check(int *a, int *b)
{
	int i = 1;
	printf("% 5d     % 5d\n", a[0], b[0]);
	while ((i <= a[0] || i <= b[0]) && i <= 100)
	{
		if(i <= a[0])
			printf("% 5d", a[i]);
		else
			printf("     ");
		printf("     ");
		if(i <= b[0])
			printf("% 5d", b[i]);
		else
			printf("     ");
		printf("\n");
		i++;
	}
	return (0);
}
