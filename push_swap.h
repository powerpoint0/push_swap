#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		ft_check_error_and_write_numbers(int argc, char **argv, int *a, int *b);
void	ft_is_all_number(int argc, char **argv, int *a);
int		ft_atoi_with_check(const char *str, int *a);
int		ft_write_numbers_one_number(int argc, char **argv, int *a);
void	ft_check_repeat_numbers(int *a);
int		ft_check_sort(int *a);
void	ft_sa_sb(int *a, char letter);
void	ft_ss(int *a, int *b);
void	ft_pa_pb(int *a, int *b, char letter);
void	ft_ra_rb(int *a, char letter);
void	ft_rr(int *a,int *b);
void	ft_rra_rrb(int *a, char letter);
void	ft_rrr(int *a, int *b);

#endif