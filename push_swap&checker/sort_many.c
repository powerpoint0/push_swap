#include "../push_swap.h"

void ft_5num2(int *a, int *b,int all_in_a)
{

	int max;
	int min;

		if (a[0] == 0)
			ft_pa_pb(a, b, 'a', a[0]+b[0] );
		else {
			max = ft_find_max(a);
			min = ft_find_min(a);
			if (b[1] > max) {
				if (a[a[0]] == max)
					ft_pa_pb(a, b, 'a', all_in_a);

				else {
					while (a[a[0]] != max) {
						if (ft_find_index_elem(a, max) >= a[0] / 2 + a[0] % 2)
							ft_rra_rrb(a, 'a');
						else
							ft_ra_rb(a, 'a');
					}
					ft_pa_pb(a, b, 'a', all_in_a);
				}
				ft_ra_rb(a, 'a');
			}
			else if (b[1] < min) {
				if (a[1] == min)
					ft_pa_pb(a, b, 'a', all_in_a);
				else {
					while (a[1] != min) {
						if (ft_find_index_elem(a, min) > a[0] / 2 + a[0] % 2)
							ft_rra_rrb(a, 'a');
						else
							ft_ra_rb(a, 'a');
					}
					ft_pa_pb(a, b, 'a', all_in_a);
				}
			}
			else {
				while (!(b[1] > a[a[0]] && b[1] < a[1]))
					ft_ra_rb(a, 'a');
				ft_pa_pb(a, b, 'a', all_in_a);
			}
		}
}

void ft_5num_reverse_in_b(int *b, int *a,int all_in_a)
{
	int max;
	int min;

	if (b[0] == 0)
		ft_pa_pb(b, a, 'b', b[0] + a[0] );
	else {
		max = ft_find_max(b);
		min = ft_find_min(b);
		if (a[1] < min) {
			if (b[b[0]] == min)
				ft_pa_pb(b, a, 'b', all_in_a);

			else {
				while (b[b[0]] != min) {
					if (ft_find_index_elem(b, min) >= b[0] / 2 + b[0] % 2)
						ft_rra_rrb(b, 'b');
					else
						ft_ra_rb(b, 'b');
				}
				ft_pa_pb(b, a, 'b', all_in_a);
			}
		}
		else if (a[1] > max) {
			if (b[1] == max)
				ft_pa_pb(b, a, 'b', all_in_a);
			else {
				while (b[1] != max) {
					if (ft_find_index_elem(b, max) > b[0] / 2 + b[0] % 2)
						ft_rra_rrb(b, 'b');
					else
						ft_ra_rb(b, 'b');
				}
				ft_pa_pb(b, a, 'b', all_in_a);
			}
		}
		else {
			while (!(a[1] < b[b[0]] && a[1] > b[1]))
//			{
//				if (a[0] - ft_find_index_elem(c, a[1]) > b[0] / 2 + b[0] % 2)
//					ft_rra_rrb(b, 'b');
//				else
//					ft_ra_rb(b, 'b');
//			}
				ft_ra_rb(b, 'b');
			ft_pa_pb(b, a, 'b', all_in_a);
		}
	}
}

int		ft_many_begin(int *a, int *b, int index_c, int group)
{
	int i;

	i = 0;
	int index_prev;
	int index_prev_in_b;

	index_prev_in_b = 0;
	index_prev = a[a[0]];

	while (i < group)
	{
		if (a[1] <= index_c)
		{
			if(a[1] == index_prev)
				index_prev_in_b++;
			ft_5num_reverse_in_b(b,a,a[0]+b[0]);
			i++;
		}
		else
			ft_ra_rb(a, 'a');
	}
	int maxb;
	maxb = ft_find_max(b);
	if (!index_prev_in_b)
	{
		while (a[a[0]] != index_prev && b[1] != ft_find_max(b) )
		{
				if ((ft_find_index_elem(a, index_prev) >= a[0] / 2 + a[0] % 2)
				&& (ft_find_index_elem(b, maxb) > b[0] / 2 + b[0] % 2))
					ft_rrr(a, b);
				else if ((ft_find_index_elem(a, index_prev) < a[0] / 2 + a[0] % 2)
						 && (ft_find_index_elem(b, maxb) <= b[0] / 2 + b[0] % 2))
					ft_rr(a, b);
				else
					break;
		}
	}
	if (!index_prev_in_b)
	{
		while (a[a[0]] != index_prev){
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
	while (b[0]){
		ft_pa_pb(a, b, 'a',a[0]+ b[0]);
	}
	while(a[a[0]] != index_c)
	{
		if (ft_find_index_elem(a, index_c) >= a[0] / 2 + a[0] % 2)
			ft_rra_rrb(a, 'a');
		else
			ft_ra_rb(a, 'a');
	}
}

void ft_presort(int *a, int *b, int *c)
{
	int i;
	int ind1;
	int ind2;

	i = a[0];
	ind1 = a[0] / 3;
	ind2 = ind1 *2;
	while(i--)
	{
		if (a[1] > c[ind2])
			ft_ra_rb(a, 'a');
		else if (a[1] <= c[ind1])
		{
			ft_pa_pb(b, a, 'b', a[0]+b[0]);
			ft_ra_rb(b, 'b');
		}
		else if (a[1] > c[ind1] && a[1] <= c[ind2])
			ft_pa_pb(b, a , 'b', a[0]+b[0]);
	}
	while (b[0])
		ft_pa_pb(a, b, 'a', a[0]+b[0]);
}

int		ft_many_numbers(int *a, int *b)
{
	int all_in_a;
	int submassiv;
	int *c;
	int index;
	int group;

	all_in_a = a[0];
	group = (all_in_a < 300) ? 12 : 22;
	submassiv = a[0];
	c = ft_memalloc(sizeof(int) * (a[0] + 1));
	ft_memcpy(c, a, sizeof(int) * (a[0] + 1));
	ft_bubble_sort(c);
	ft_presort(a, b ,c);
	index = 0;
	while (submassiv > 0)
	{
		if (submassiv >= group)
			index += group;
		else {
			index += submassiv;
			group = submassiv;
		}
		ft_many_begin(a, b, c[index],group );
		submassiv -= group;
	}
//	while(ft_check_sort(a))
//	{
//		if(ft_find_index_elem(a, ft_find_min(a)) > a[0] / 2 + a[0]%2)
//			ft_rra_rrb(a, 'a');
//		else
//			ft_ra_rb(a, 'a');
//	}
	free(c);
	return(0);
}