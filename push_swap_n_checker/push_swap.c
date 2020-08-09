/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:35:47 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:35:51 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_check_sort_and_b_ps(int *a, int *b)
{
	int	i;

	i = 1;
	while ((i < a[0]) && (a[i] < a[i + 1]))
		i++;
	if (i == a[0])
	{
		free(a);
		exit(0);
	}
	if (!(b = (int*)malloc(sizeof(*b) * (a[0] + 2))))
	{
		write(2, "Error\n", 6);
		free(a);
		exit(-1);
	}
	b[0] = 0;
	return (b);
}

void	ft_sort_depends_of_numbers(int *a, int *b)
{
	if (a[0] == 2)
		ft_2num(a, 'a');
	else if (a[0] == 3)
		ft_3num(a, 'a');
	else if (a[0] > 3 && a[0] < 15)
		ft_few_numbers(a, b);
	else if (a[0] >= 15)
		ft_many_numbers(a, b);
}

int		main(int argc, char **argv)
{
	int	*a;
	int	*b;

	a = NULL;
	b = NULL;
	a = ft_check_error_and_write_numbers(argc, argv, a);
	b = ft_check_sort_and_b_ps(a, b);
	ft_sort_depends_of_numbers(a, b);
	free(a);
	free(b);
	return (0);
}
