#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

void*	ft_check_error_and_write_numbers(int argc, char **argv, int *a);
void*	ft_check_sort_and_b_ps(int *a, int *b);
int		ft_is_all_numbers(int argc, char **argv);
int		ft_atoi_with_check(const char *str);
int		ft_write_numbers_one_number(char **argv, int *a, int kolvo_num);
void	ft_check_repeat_numbers(int *a);
int		ft_check_sort(int *a);
int 	ft_sa_sb(int *a, char letter);
int		ft_ss(int *a, int *b);
int		ft_pa_pb(int *a, int *b, char letter);
int		ft_ra_rb(int *a, char letter);
int		ft_rr(int *a,int *b);
int		ft_rra_rrb(int *a, char letter);
int		ft_rrr(int *a, int *b);
void	ft_2num(int *a,char letter);
void	ft_3num(int *a,char letter);
void	ft_few_numbers(int *a, int *b);
void	ft_sort_not_reverse_in_a(int *a, int *b);
int		ft_many_numbers(int *a, int *b);
void	ft_sort_in_group(int *a, int *b, int index_c, int group);
void	sort_one_reverse_in_b(int *b, int *a);
int 	ft_check_sort(int *a);
int 	ft_find_max(int *a);
int		ft_find_min(int *a);
int		ft_find_index_elem(int *a, int number);
int		ft_bubble_sort(int *a);
void	ft_reverse_rrr(int *a, int *b,int index_prev_in_b,int index_prev);
void	ft_reverse_rab_rrab(int *a, int *b,int index_prev_in_b,int index_prev);
void	ft_pa_and_rotate_to_the_end(int *a, int *b,int index_c);
int		ft_check(int *a,int *b );
void	ft_free_all(char **instr, int *a, int *b);
#endif
