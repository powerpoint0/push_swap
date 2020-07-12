//
// Created by Claudine Joaquin on 7/10/20.
//

//tomorrow: (it's easy) + think about using functions in alg_sort
//проверка валидности и запись чисел по функциям из пуш_свап
//чтение иснтрукций по одной
//выполнение инструкций
//проверка сортированности а и пустоты б
//вывод ок/ко            ++++++
//
////////////
// след шаг- подправление здесь неточностей,доработать чтение
//вынести в отдельный проект для тестов
//функции в сортировку пузырьком хоть как-то
// мэйк
//править совместную работу



#include "../push_swap.h"

void ft_do_comand(char *instr,int *a, int *b)
{
	if( !ft_strcmp(instr, "sa") || !ft_strcmp(instr, "sb"))
		!ft_strcmp(instr, "sa") ? ft_sa_sb(a, "a") : ft_sa_sb(a, "b");
	else if( !ft_strcmp(instr, "ss"))
		ft_ss(a, b);
	else if( !ft_strcmp(instr, "pa") || !ft_strcmp(instr, "pb"))
		!ft_strcmp(instr, "pa") ? ft_pa_pb(a, b, "a") : ft_pa_pb(a, b, "b");
	else if( !ft_strcmp(instr, "ra") || !ft_strcmp(instr, "rb"))
		!ft_strcmp(instr, "ra") ? ft_ra_rb(a, "a") : ft_ra_rb(a, "b");
	else if( !ft_strcmp(instr, "rr"))
		ft_rr(a, b);
	else if( !ft_strcmp(instr, "rra") || !ft_strcmp(instr, "rrb"))
		!ft_strcmp(instr, "rra") ? ft_rra_rrb(a, "a") : ft_rra_rrb(a, "b");
	else if( !ft_strcmp(instr, "rrr"))
		ft_rrr(a, b);
	else
		return(-1);///error
	ft_bzero(instr, 5);
}

int main(int argc, char **argv)
{
	int *a;
	int *b;
	char instr[5];

	a = NULL;
	b = NULL;
	ft_check_error_and_write_numbers(argc, argv, a, b);
	ft_bzero(instr, 5);
	while(read <5 && read != 0)   //mozhno pridumat simvol dlya vyhoda  //read!= symvol//zapis v instr
		ft_do_comand(instr, a, b);
	if (b[0]!= 0 || !ft_check_sort(a))     //peredelat ft bez exit
		write(1, "KO\n", 3)
	else
		write(1, "OK\n", 3);
	free(a);
	free(b);
	return(0);
}