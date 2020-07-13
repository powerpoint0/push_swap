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

void ft_do_comands(char *instr,int *a, int *b)
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
		return;///error
	ft_bzero(instr, 5);
}

int ft_read_comands(char **instr)
{
	char buf[20];
	int b;
	int kolvo_n_buf;
	int i;
	int kolvo_n_all;
	char **pointer;
	char *n;

	i = 0;
	kolvo_n_buf = 0;
	kolvo_n_all = 0;
	ft_bzero(buf, 20);
	while ((b = read(0, buf,19)))   ///ili simvol
	{
		pointer = instr;
		while (buf[i])
			kolvo_n_buf = (buf[i++] == '\n') ? kolvo_n_buf + 1 : kolvo_n_buf;
		kolvo_n_all += kolvo_n_buf;
		if (!(instr = (char**)malloc(sizeof(char*) * (kolvo_n_all + 1))))
			return(-1);
		i = 0;
		while(pointer[i])
		{
			//malloc pod instr
			ft_strcpy(instr[i], pointer[i]);
			i++;
		}
		while(*pointer)
		{
			free(*pointer);
			*pointer++;
		}
		n = buf;
		int k = 0;
		while((n = ft_strchr(n,'\n')))
		{
			while(n[k] != '\n')
				k++;
			//mallok instr sizeof k + 1
			ft_memcpy(instr[i],n , k);
			n = &n[k+1];
			i++;
		}
		ft_bzero(buf, 20);
	}
	return(0);
}

int main(int argc, char **argv)
{
	int *a;
	int *b;
	char **instr;

	a = NULL;
	b = NULL;
	instr = NULL;
	ft_check_error_and_write_numbers(argc, argv, a, b);
	ft_read_comands(instr);
	ft_bzero(instr, 5);
	while(*instr)
		ft_do_comands(*instr, a, b);
	if (b[0]!= 0 || !ft_check_sort(a))     //peredelat ft bez exit
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(a);
	free(b);
	while(*instr)
	{
		free(*instr);
		*instr++;
	}
	free(instr);//polnost'yu postrochno
	return(0);
}