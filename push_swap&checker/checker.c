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



#include "push_swap.h"

void ft_free_all(char **instr, int *a, int *b)
{
	int i;

	i = 0;
	free(a);
	free(b);
	while(instr[i])
	{
		free(instr[i]);
		i++;
	}
	free(instr);
	exit(0);
}

void ft_do_comands(char **instr_main, char *instr,int *a, int *b)
{
	if( !ft_strcmp(instr, "sa") || !ft_strcmp(instr, "sb"))
		!ft_strcmp(instr, "sa") ? ft_sa_sb(a, 'a') : ft_sa_sb(a, 'b');
	else if( !ft_strcmp(instr, "ss"))
		ft_ss(a, b);
	else if( !ft_strcmp(instr, "pa") || !ft_strcmp(instr, "pb"))
		!ft_strcmp(instr, "pa") ? ft_pa_pb(a, b, 'a') : ft_pa_pb(a, b, 'b');
	else if( !ft_strcmp(instr, "ra") || !ft_strcmp(instr, "rb"))
		!ft_strcmp(instr, "ra") ? ft_ra_rb(a, 'a') : ft_ra_rb(a, 'b');
	else if( !ft_strcmp(instr, "rr"))
		ft_rr(a, b);
	else if( !ft_strcmp(instr, "rra") || !ft_strcmp(instr, "rrb"))
		!ft_strcmp(instr, "rra") ? ft_rra_rrb(a, 'a') : ft_rra_rrb(a, 'b');
	else if( !ft_strcmp(instr, "rrr"))
		ft_rrr(a, b);
	else
	{
		write(2, "Error\n", 6);
		ft_free_all(instr_main, a, b);
		exit(-1);
	}
	ft_bzero(instr, 5);
}

int ft_read_comands(char **instr, int *a, int *b)
{
	char buf[20];
	int read_symb;
	int kolvo_n_buf;
	int i;
	int kolvo_n_all;
	char **pointer;
	char *n;
	int kolvo_simb;

	kolvo_simb = 0;
	i = 0;
	kolvo_n_buf = 0;
	kolvo_n_all = 0;
	ft_bzero(buf, 20);
	while ((read_symb = read(0, buf,19)))   ///ili simvol
	{
		pointer = instr;
		while (buf[i] && buf[i] != 'S')
			kolvo_n_buf = (buf[i++] == '\n') ? kolvo_n_buf + 1 : kolvo_n_buf;
		kolvo_n_all += kolvo_n_buf;
		if (!(instr = (char**)malloc(sizeof(char*) * (kolvo_n_all + 1))))
			return(-1);
		i = 0;
		while(pointer[i])
		{
			kolvo_simb = ft_strlen(pointer[i]);
			if (!(instr[i] = (char*)malloc(sizeof(char)* (kolvo_simb+ 1))))
				ft_free_all(instr, a, b);
			ft_strcpy(instr[i], pointer[i]);
			i++;
		}
		int k = 0;
		while(pointer[k])
		{
			free(pointer[k]);
			k++;
		}
		n = buf;
		k = 0;
		while((n = ft_strchr(n,'\n')))
		{
			while(n[k] != '\n')
				k++;
			if (!(instr[i] = (char*)malloc(sizeof(char)* (k+ 1))))
				ft_free_all(instr, a, b);
			ft_memcpy(instr[i],n , k);
			n = &(n[k+1]);
			i++;
			if (*n == 'S')
				return(0);
		}
		ft_bzero(buf, 20);
	}
	return(0);
}

int ft_check_sort(int *a)               //chisla sortirovany
{
	int i;

	i = 1;
	while ((i < a[0]) && (a[i] < a[i + 1]))
		i++;
	if (i == a[0])
		return (0);
	return (-1);
}

char**	ft_alg(int argc, int *a, int *b, char **instr)
{
	int i;

	i = 0;

	ft_read_comands(instr, a, b);
	ft_bzero(instr, 5);
	while(instr[i])
	{
		ft_do_comands(instr,instr[i], a, b);
		i++;
	}
	if (b[0]!= 0 || ft_check_sort(a))     //peredelat ft bez exit
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
	b = NULL;
	instr = NULL;
	a = ft_check_error_and_write_numbers(argc, argv, a);
	if (!(b = (int*)malloc(sizeof(*b) * argc)))
	{
		write(2,"Error\n", 6);
		free(a);
		exit(-1);
	}
	b[0] = 0;
	instr = ft_alg(argc, a, b, instr);
	ft_free_all(instr, a, b);
	return(0);
}