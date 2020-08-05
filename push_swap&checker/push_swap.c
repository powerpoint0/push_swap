#include "../push_swap.h"

void ft_sort_depends_of_numbers(int *a, int *b)  //sortirovka   //napisat sortirovku puzyrkom для начала +++
{
	if (a[0] == 2)
		ft_2num(a, 'a');
	else if (a[0] == 3)
		ft_3num(a, 'a');
	else if (a[0] > 3 && a[0] < 15)
		ft_few_numbers(a, b);
	else if (a[0] >= 15)
		ft_many_numbers(a, b);
}

int main(int argc, char **argv)
{

	int *a;
	int *b;

	a = NULL;
	b = NULL;
	a = ft_check_error_and_write_numbers(argc, argv, a);
	b = ft_check_sort_and_b_ps(a, b);
	ft_sort_depends_of_numbers(a, b);
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