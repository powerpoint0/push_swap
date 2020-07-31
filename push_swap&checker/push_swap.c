#include "../push_swap.h"

void ft_main_alg_of_sort(int *a, int *b)  //sortirovka   //napisat sortirovku puzyrkom для начала +++
{
	if (a[0] == 2)
		ft_2num(a, 'a');
	else if (a[0] == 3)
		ft_3num(a, 'a');
	else if (a[0] > 3 && a[0] <= 20)
		ft_5num_(a, b, a[0]+b[0]);
	else if (a[0] > 20)
		ft_many_numbers(a, b);
}

int main(int argc, char **argv)
{
	int *a;
	int *b;
	int i = 0;

	a = NULL;
	b = NULL;
	a = ft_check_error_and_write_numbers(argc, argv, a);
	b = ft_check_sort_and_b_ps(a, b);
	ft_main_alg_of_sort(a, b);
//	while ((i <= a[0] || i <= b[0]))
//	{
//		printf("%d    %d\n", a[i], b[i]);
//		i++;
//	}
	free(a);
	free(b);
	return 0;
}
