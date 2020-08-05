#include "../push_swap.h"

void ft_2num(int *a, char letter)
{
	if (a[1] > a[2])
		ft_sa_sb(a, letter);
}

void ft_3num(int *a, char letter)
{
	int i;

	i = 1;
	if (a[i] < a[2] && a[2] > a[3] && a[i] < a[3])
	{
		ft_sa_sb(a, letter);
		ft_ra_rb(a, letter);
	}
	else if (a[i] > a[2] && a[2] < a[3] && a[i] < a[3])
		ft_sa_sb(a, letter);
	else if (a[i] < a[2] && a[2] > a[3] && a[i] > a[3])
		ft_rra_rrb(a, letter);
	else if (a[i] > a[2] && a[2] > a[3] && a[i] > a[3])
	{
		ft_sa_sb(a, letter);
		ft_rra_rrb(a, letter);
	}
	else if (a[i] > a[2] && a[2] < a[3] && a[i] > a[3])
		ft_ra_rb(a, letter);
}

void ft_few_numbers(int *a, int *b)
{
	while (a[0] > 3)
		ft_pa_pb(b, a , 'b');
	if(ft_check_sort(a))
		ft_3num(a, 'a');
	while(b[0])
	{
		ft_sort_not_reverse_in_a(a, b);
	}
	while(ft_check_sort(a))
	{
		if (ft_find_index_elem(a, ft_find_min(a)) > a[0] / 2 + a[0] % 2)
			ft_rra_rrb(a, 'a');
		else
			ft_ra_rb(a, 'a');
	}
}

