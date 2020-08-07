/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_only_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:33:36 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:33:51 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_is_num_n_less_int(char *argv, int i)
{
	int len_num;


	len_num = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i] && argv[i] != ' ')
	{
		if (ft_isdigit(argv[i]))
		{
			i++;
			len_num++;
		}
		else
			return (-1);
	}
	if (len_num > 16)
		return (-1);
	return(i);
}

int	ft_is_all_numbers2(char **argv, int j)
{
	int	i;
	int k;

	k = 0;
	i= 0;

	while(argv[j][i] != '\0')
	{
		while(argv[j][i] && argv[j][i]== ' ')
			i++;
		if (argv[j][i])
		{
			if((i = ft_is_num_n_less_int(argv[j], i)) == -1)
			{
				write(2, "Error\n", 6);
				exit(-1);
			}
			k++;
		}
	}
	return(k);
}

int ft_is_all_numbers_n_less_ll(int argc, char **argv)
{
	int j;
	int k;

	k = 0;
	j = 1;
	while(j< argc)
	{
		if (argc == 2 && (argv[1][0] == '\0'))
			exit(-1);
		k += ft_is_all_numbers2(argv, j);
		j++;
	}
	return(k);
}
