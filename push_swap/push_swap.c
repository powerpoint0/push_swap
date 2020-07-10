#include "push_swap.h"

int ft_check_error_and_write_numbers(int argc, char **argv, int *a)
{
	ft_is_all_number(argc, argv, a);
	ft_write_numbers_one_number(argc, argv, a);
	ft_check_repeat_numbers(a);
	ft_check_sort(a);
	return(0);
}

void ft_main_alg_of_sort(int *a, int *b)
{

}

int main(int argc, char **argv)
{
	int *a;
	int *b;
	int i = 0;

	if (argc <= 1)
	{
		write(2,"Error\n", 6);
		exit(-1);
	}
	if (!(a = (int*)malloc(sizeof(*a) * argc)))
		return(0);
	ft_check_error_and_write_numbers(argc, argv, a);
	if (!(b = (int*)malloc(sizeof(*b) * argc)))
		return(0);
	b[0] = 0;
	ft_main_alg_of_sort(a,b);//sortirovka
	while (i <= argc && (i <= a[0] || i <= b[0]))
	{
		printf("%d    %d\n", a[i], b[i]);
		i++;
	}
	free(a);
	free(b);
	return 0;
}
