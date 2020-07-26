#include "../push_swap.h"

void ft_main_alg_of_sort(int *a, int *b)  //sortirovka   //napisat sortirovku puzyrkom для начала +++
{
	if (a[0] == 2)
		ft_2num(a, 'a');
	if (a[0] == 3)
		ft_3num(a, 'a');
	if (a[0] >= 5)
		ft_5num(a, b);
//	int i;
//	int c;
//	int n;
//
//	n = 1;
//	i = 1;
//	while (i < a[0])
//	{
//		while (i + n <= a[0])
//		{
//			if (a[i] > a[i + n])
//			{
//				//ft_sa_sb(a,'a');
//				c = a[i];
//				a[i] = a[i + n];
//				a[i + n] = c;
//			}
//			n++;
//		}
//		n = 1;
//		i++;
//	}
//	//ft_sa_sb(a,'a');   //////////////
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
