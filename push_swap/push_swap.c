#include "../push_swap.h"

int ft_check_error_and_write_numbers(int argc, char **argv, int *a, int *b)
{
	if (argc <= 1)
	{
		write(2,"Error\n", 6);
		exit(-1);
	}
	if (!(a = (int*)malloc(sizeof(*a) * argc)))
		return(0);
	ft_is_all_number(argc, argv, a);
	ft_write_numbers_one_number(argc, argv, a);
	ft_check_repeat_numbers(a);
	ft_check_sort(a);
	if (!(b = (int*)malloc(sizeof(*b) * argc)))
		return(0);
	b[0] = 0;
	return(0);
}

void ft_main_alg_of_sort(int *a, int *b)
{
	//sortirovka
	//napisat sortirovku puzyrkom для начала +++
	int i;
	int c;
	int n;

	n = 1;
	i = 1;
	while (i < a[0])
	{
		while (i + n <= a[0])
		{
			if (a[i] > a[i + n])
			{
				//ft_sa_sb(a,'a');
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


int main(int argc, char **argv)
{
	int *a;
	int *b;
	//int i = 0;

	a = NULL;
	b = NULL;
	ft_check_error_and_write_numbers(argc, argv, a, b);
	ft_main_alg_of_sort(a,b);

//	while (i <= argc && (i <= a[0] || i <= b[0]))
//	{
//		printf("%d    %d\n", a[i], b[i]);
//		i++;
//	}
	free(a);
	free(b);
	return 0;
}
