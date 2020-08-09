/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:11:38 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/09 14:11:42 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_all(char **instr, int *a, int *b)
{
	int	i;

	i = 0;
	if (a)
		free(a);
	if (b)
		free(b);
	if (instr)
	{
		while (instr[i])
		{
			free(instr[i]);
			i++;
		}
		free(instr);
	}
	exit(0);
}

int		ft_check(int *a, int *b)
{
	int	i;

	i = 1;
	printf("% 5d     % 5d\n", a[0], b[0]);
	while ((i <= a[0] || i <= b[0]) && i <= 100)
	{
		if (i <= a[0])
			printf("% 5d", a[i]);
		else
			printf("     ");
		printf("     ");
		if (i <= b[0])
			printf("% 5d", b[i]);
		else
			printf("     ");
		printf("\n");
		i++;
	}
	return (0);
}
