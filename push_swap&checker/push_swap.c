#include "../push_swap.h"

void ft_main_alg_of_sort(int *a, int *b)  //sortirovka   //napisat sortirovku puzyrkom для начала +++
{
	if (a[0] == 2)
		ft_2num(a, 'a');
	else if (a[0] == 3)
		ft_3num(a, 'a');
	//else if (a[0] > 3 && a[0] <= 20)
		//ft_5num_(a, b, a[0]+b[0]);
	else if (a[0] >3)
		ft_many_numbers(a, b);
}
int ft_check(int *a,int *b )
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
	int i = 0;

	a = NULL;
	b = NULL;
	a = ft_check_error_and_write_numbers(argc, argv, a);
	b = ft_check_sort_and_b_ps(a, b);
	//ft_check(a, b);
//	ft_5num_reverse_in_b(b, a, a[0] +b[0]);
//	ft_5num_reverse_in_b(b, a, a[0] +b[0]);
//	ft_5num_reverse_in_b(b, a, a[0] +b[0]);
	//ft_many_begin(a, b, 4,5 );
	ft_main_alg_of_sort(a, b);
//	ft_check(a, b);
//	while ((i <= a[0] || i <= b[0]))
//	{
//		printf("%d    %d\n", a[i], b[i]);
//		i++;
//	}
	free(a);
	free(b);

//int a[11] = {10,928, 17, 738, 627, 426, 2,3,4,5,6};
//int b[11] = {0};



	//ft_check(a, b);

	//ft_main_alg_of_sort(a, b);

//	ft_5num_reverse_in_b(b, a, a[0] +b[0]);
//	ft_5num_reverse_in_b(b, a, a[0] +b[0]);
//	ft_5num_reverse_in_b(b, a, a[0] +b[0]);
//	ft_5num_reverse_in_b(b, a, a[0] +b[0]);
//	ft_5num_reverse_in_b(b, a, a[0] +b[0]);

	//ft_check(a, b);



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