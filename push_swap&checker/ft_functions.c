#include "../push_swap.h"

int ft_sa_sb(int *a, char letter)         ///kolvo elem v [0]
{
	int c;

	if (a[0] <= 1)
		return(-1);
	c = a[1];
	a[1] = a[2];
	a[2] = c;
	if (letter == 'n')
		return(0);
	letter == 'a' ? write(1, "sa\n", 3) :  write(1, "sb\n", 3);
	return(0);
}

int ft_ss(int *a, int *b)
{
	ft_sa_sb(a, 'n');
	ft_sa_sb(b, 'n');
	write(1, "ss\n", 3);
	return(0);
}

int ft_pa_pb(int *a, int *b, char letter, int all_in_a) //++
{
	int k;

	k = a[0];
	if (b[0] == 0)
		return(-1);
	k = all_in_a -1;
	while (k)
	{
		a[k + 1] = a[k];
		k--;
	}
	a[1] = b[1];
	a[0]++;
	k = 1;
	while(k < all_in_a)
	{
		b[k] = b[k + 1];
		k++;
	}
	b[0]--;
	if (letter == 'n')
		return(0);
	letter == 'a' ? write(1, "pa\n", 3) :  write(1, "pb\n", 3);
	return(0);
}

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









