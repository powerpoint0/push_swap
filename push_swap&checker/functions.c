#include "../push_swap.h"

int ft_sa_sb(int *a, char letter)
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

int ft_pa_pb(int *a, int *b, char letter)
{
	int k;

	if (b[0] == 0)
		return(-1);
	k = a[0] + b[0] -1;
	while (k)
	{
		a[k + 1] = a[k];
		k--;
	}
	a[1] = b[1];
	a[0]++;
	k = 1;
	while(k < a[0] +b[0])
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

void ft_free_all(char **instr, int *a, int *b)
{
	int i;

	i = 0;
	if(a)
		free(a);
	if(b)
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






