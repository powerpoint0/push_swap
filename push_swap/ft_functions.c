//	2.ponyat, gde "top of the stack"-nachalo massiva!
//		cdelat ft sa
//		sb
//		ss
//		pa
//		pb
//		ra
//		rb
//		rr
//		rra
//		rrb
//		rrr
//sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
//		is only one or no elements).
//sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
//		is only one or no elements).
//ss : sa and sb at the same time.
//pa : push a - take the first element at the top of b and put it at the top of a. Do
//		nothing if b is empty.
//pb : push b - take the first element at the top of a and put it at the top of b. Do
//		nothing if a is empty.
//ra : rotate a - shift up all elements of stack a by 1. The first element becomes
//the last one.
//rb : rotate b - shift up all elements of stack b by 1. The first element becomes
//the last one.
//rr : ra and rb at the same time.
//rra : reverse rotate a - shift down all elements of stack a by 1. The last element
//		becomes the first one.
//rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
//		becomes the first one.
//rrr : rra and rrb at the same time.
#include "push_swap.h"

void ft_sa_sb(int *a, char letter)         ///kolvo elem v [0]
{
	int c;

	if (a[0] <= 1)
		return;
	c = a[1];
	a[1] = a[2];
	a[2] = c;
	letter == 'a' ? write(1, "sa\n", 3) :  write(1, "sb\n", 3);
}

void ft_ss(int *a, int *b)
{
	ft_sa_sb(a, 'a');
	ft_sa_sb(b, 'b');
	write(1, "ss\n", 3);
}

void ft_pa_pb(int *a, int *b, char letter)
{
	int k;

	k = a[0];
	if (b[0] == 0)
		return;
	while (k)
	{
		a[k + 1] = a[k];
		k--;
	}
	a[1] = b[1];
	a[0]++;
	k = b[0];
	while(k > 1)
	{
		b[k - 1] = b[k];
		k--;
	}
	b[0]--;
	letter == 'a' ? write(1, "pa\n", 3) :  write(1, "pb\n", 3);
}

void ft_ra_rb(int *a, char letter)
{
	int k;
	int c;

	c = a[1];
	k = a[0];
	while(k > 1)
	{
		a[k - 1] = a[k];
		k--;
	}
	a[*a] = c;
	letter == 'a' ? write(1, "ra\n", 3) :  write(1, "rb\n", 3);
}


void ft_rr(int *a,int *b)
{
	ft_ra_rb(a, 'a');
	ft_ra_rb(b, 'b');
	write(1, "rr\n", 3);
}

void ft_rra_rrb(int *a, char letter)
{
	int k;
	int c;

	k = a[0];
	c = a[k];

	while(k > 1)
	{
		a[k] = a[k - 1];
		k--;
	}
	a[1] = c;
	letter == 'a' ? write(1, "rra\n", 4) :  write(1, "rrb\n", 4);
}

void ft_rrr(int *a, int *b)
{
	ft_rra_rrb(a, 'a');
	ft_rra_rrb(b, 'b');
	write(1, "rrr\n", 4);
}









