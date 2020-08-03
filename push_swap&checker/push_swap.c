#include "../push_swap.h"

void ft_main_alg_of_sort(int *a, int *b)  //sortirovka   //napisat sortirovku puzyrkom для начала +++
{
	if (a[0] == 2)
		ft_2num(a, 'a');
	else if (a[0] == 3)
		ft_3num(a, 'a');
	else if (a[0] > 3 && a[0] < 15)
		ft_few_numbers(a, b, a[0] + b[0]);
	else if (a[0] >= 15)
		ft_many_numbers(a, b);
}

int ft_check(int *a, int *b)
{
	int i = 1;
	printf("% 5d     % 5d\n", a[0], b[0]);
	while ((i <= a[0] || i <= b[0]) && i <= 100)
	{
		if(i <= a[0])
			printf("% 5d", a[i]);
		else
			printf("     ");
		printf("     ");
		if(i <= b[0])
			printf("% 5d", b[i]);
		else
			printf("     ");
		printf("\n");
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{

	int *a;
	int *b;

	a = NULL;
	b = NULL;
	a = ft_check_error_and_write_numbers(argc, argv, a);
	b = ft_check_sort_and_b_ps(a, b);
	ft_main_alg_of_sort(a, b);
	//ft_check(a, b);
	free(a);
	free(b);
	return 0;
}





//int d[5] = {15 , -1, 0, -2, 0};
//
//char *chr = (char *)d;
//int ii = 0;
//while (ii < 5 * 4) {
//printf("%02hhx ", chr[ii]);
//
//ii++;
//}
//
//printf("\n");
//
//int *p = d ;
//ii = 0;
//while (ii < 5) {
//printf("%d ", p[ii]);
//
//ii++;
//}
//return (0);