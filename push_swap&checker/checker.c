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

///////
//net seg, no ne chitaet, red == 0.
//ne chitaet arg = "1 2 3"- dolzhno?to est args podayutsya v vide odnoi stroki?
//vozvrashat lokalnye peremennye nelzya, a ukazateli  mozhno?
//plan: dodelat checker , pristupit k sortirovke s komandami

#include "push_swap.h"

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

void ft_do_comands(char **instr_main, char *instr,int *a, int *b)
{
	int all;

	all = a[0] + b[0];
	if( !ft_strcmp(instr, "sa") || !ft_strcmp(instr, "sb"))
		!ft_strcmp(instr, "sa") ? ft_sa_sb(a, 'a') : ft_sa_sb(b, 'b');
	else if( !ft_strcmp(instr, "ss"))
		ft_ss(a, b);
	else if( !ft_strcmp(instr, "pa") || !ft_strcmp(instr, "pb"))
		!ft_strcmp(instr, "pa") ? ft_pa_pb(a, b, 'a', all) : ft_pa_pb(b, a, 'b', all);
	else if( !ft_strcmp(instr, "ra") || !ft_strcmp(instr, "rb"))
		!ft_strcmp(instr, "ra") ? ft_ra_rb(a, 'a') : ft_ra_rb(b, 'b');
	else if( !ft_strcmp(instr, "rr"))
		ft_rr(a, b);
	else if( !ft_strcmp(instr, "rra") || !ft_strcmp(instr, "rrb"))
		!ft_strcmp(instr, "rra") ? ft_rra_rrb(a, 'a') : ft_rra_rrb(b, 'b');
	else if( !ft_strcmp(instr, "rrr"))
		ft_rrr(a, b);
}

char** ft_read_comands(int *a, int *b)
{
	int red;
	char *str;
	char buf[1001];
	char *p;
	char **instr;

	str = ft_strnew(0);
	ft_bzero(buf, 1001);
	while ((red = read(0, buf, 1000)))
	{
		p = str;
		buf[red] = '\0';
		str = ft_strjoin(str, buf);
		free(p);
		ft_bzero(buf, 1001);
	}
	instr = ft_strsplit(str, '\n');
	free(str);
	return (instr);
}


int ft_check_sort(int *a)               //chisla sortirovany
{
	int i;

	i = 1;
	if(a[0] == 0)
		return(-1);
	while ((i < a[0]) && (a[i] < a[i + 1]))
		i++;
	if (i == a[0])
		return (0);
	return (-1);
}

char**	ft_alg(int argc, int *a, int *b)
{
	int i;
	char **instr;

	i = 0;
	instr = ft_read_comands(a, b);
	if (instr)
	{
		while (instr[i])
		{
			ft_do_comands(instr, instr[i], a, b);
			i++;
		}
	}

	if (b[0]!= 0 || ft_check_sort(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return(instr);
}

int main(int argc, char **argv)
{
	int *a;
	int *b;
	char **instr;

	a = NULL;
	a = ft_check_error_and_write_numbers(argc, argv, a);
	if (!(b = (int*)malloc(sizeof(*b) * (a[0] + 1))))
	{
		write(2,"Error\n", 6);
		free(a);
		exit(-1);
	}
	b[0] = 0;
	instr = ft_alg(argc, a, b);

	ft_free_all(instr, a, b);
	return(0);
}


//	int i = 0;
//	if( instr) {
//		while (instr[i]) {
//			printf("%s", instr[i]);
//			i++;
//		}
//	}