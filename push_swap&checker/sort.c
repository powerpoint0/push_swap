//
// Created by Claudine Joaquin on 7/24/20.
//
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
	if (a[i] < a[2] && a[i] < a[3])
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

int ft_check_sort(int *a)               //chisla sortirovany
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

void ft_5num_(int *a, int *b,int all_in_a)
{
	while (a[0] > 3)
		ft_pa_pb(b, a , 'b', all_in_a);
	if(ft_check_sort(a))
		ft_3num(a, 'a');
	while(b[0])
	{
		ft_5num2(a, b, a[0]+ b[0]);
	}
		while(ft_check_sort(a))
	{
		if(ft_find_index_elem(a, ft_find_min(a)) > a[0] / 2 + a[0]%2)
			ft_rra_rrb(a, 'a');
		else
			ft_ra_rb(a, 'a');
	}
}

void ft_5num2(int *a, int *b,int all_in_a)
{

	int max;
	int min;

		if (a[0] == 0)
			ft_pa_pb(a, b, 'a', a[0]+b[0] );
		else {
//			if (a[0] == 3)
//			{
//				ft_3num(a, 'a');
//				return;
//			}
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

void	*ft_memcpy_int(void *dst, const void *src, size_t n)
{
	ssize_t 	*p;
	ssize_t 	*p2;

	if (n == 0)
		return (dst);
	if ((ssize_t*)dst == 0 && (ssize_t *)src == 0)
		return (dst);
	p = (ssize_t *)dst;
	p2 = (ssize_t *)src;
	while (n--)
		*p++ = *p2++;
	return (dst);
}

void ft_5num_reverse_in_b(int *b, int *a, int all_in_a)
{

	int max;
	int min;

	if (b[0] == 0)
		ft_pa_pb(b, a, 'b', b[0] + a[0] );
	else {
//			if (ccc[0] == 3)
//			{
//				ft_3num(ccc, 'ccc');
//				return;
//			}
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
			ft_ra_rb(b, 'b');
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
	if (!index_prev_in_b)
	{
		while (a[a[0]] != index_prev){
			ft_ra_rb(a, 'a');
		}
	}
	while (b[1] != ft_find_max(b)){
		ft_ra_rb(b, 'b');
	}
	while (b[0]){
		ft_pa_pb(a, b, 'a',a[0]+ b[0]);
	}
	while(a[a[0]] != index_c){
		ft_ra_rb(a, 'a');
	}

//	i = 0;
//	while ((i <= a[0] || i <= b[0]))
//	{
//		printf("%d    %d\n", a[i], b[i]);
//		i++;
//	}
}

int		ft_many_numbers(int *a, int *b)
{
	int all_in_a;
	int submassiv;
	int i;
	int k;
	int *c;
	int index;
	int group;


//	static num;
//	num++;




	all_in_a = a[0];
	group = (all_in_a < 300) ? 15 : 45;
	//group = 5;
	submassiv = a[0];
	c = ft_memalloc(sizeof(int) * (a[0] + 1));
	c = ft_memcpy_int(c, a, a[0] +1);
	//ft_memcpy(c, a, sizeof(int) * (a[0] + 1));

	ft_bubble_sort(c);
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