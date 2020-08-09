/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoaquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:34:48 by cjoaquin          #+#    #+#             */
/*   Updated: 2020/08/06 20:34:53 by cjoaquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_do_comands(char *instr, int *a, int *b)
{
	if (!ft_strcmp(instr, "sa") || !ft_strcmp(instr, "sb"))
		!ft_strcmp(instr, "sa") ? ft_sa_sb(a, 'n') : ft_sa_sb(b, 'n');
	else if (!ft_strcmp(instr, "ss"))
		ft_ss(a, b, 'n');
	else if (!ft_strcmp(instr, "pa") || !ft_strcmp(instr, "pb"))
		!ft_strcmp(instr, "pa") ? ft_pa_pb(a, b, 'n') : ft_pa_pb(b, a, 'n');
	else if (!ft_strcmp(instr, "ra") || !ft_strcmp(instr, "rb"))
		!ft_strcmp(instr, "ra") ? ft_ra_rb(a, 'n') : ft_ra_rb(b, 'n');
	else if (!ft_strcmp(instr, "rr"))
		ft_rr(a, b, 'n');
	else if (!ft_strcmp(instr, "rra") || !ft_strcmp(instr, "rrb"))
		!ft_strcmp(instr, "rra") ? ft_rra_rrb(a, 'n') : ft_rra_rrb(b, 'n');
	else if (!ft_strcmp(instr, "rrr"))
		ft_rrr(a, b, 'n');
	else
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
}

char	**ft_read_comands(void)
{
	int		red;
	char	*str;
	char	buf[1001];
	char	*p;
	char	**instr;

	str = ft_strnew(0);
	ft_bzero(buf, 1001);
	while ((red = read(0, buf, 1000)))
	{
		p = str;
		buf[red] = '\0';
		str = ft_strjoin(str, buf);
		free(p);
		ft_bzero(buf, 1001);
	}
	instr = ft_strsplit(str, '\n');
	free(str);
	return (instr);
}

int		ft_check_sort(int *a)
{
	int		i;

	i = 1;
	if (a[0] == 0)
		return (-1);
	while ((i < a[0]) && (a[i] < a[i + 1]))
		i++;
	if (i == a[0])
		return (0);
	return (-1);
}

char	**ft_alg(int *a, int *b)
{
	int		i;
	char	**instr;

	i = 0;
	instr = ft_read_comands();
	if (instr)
	{
		while (instr[i])
		{
			ft_do_comands(instr[i], a, b);
			i++;
		}
	}
	if (b[0] != 0 || ft_check_sort(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (instr);
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	**instr;

	a = NULL;
	a = ft_check_error_and_write_numbers(argc, argv, a);
	if (!(b = (int*)malloc(sizeof(*b) * (a[0] + 2))))
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	b[0] = 0;
	instr = ft_alg(a, b);
	ft_free_all(instr, a, b);
	return (0);
}
