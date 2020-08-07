NAME_PS = push_swap
NAME_CH = checker

LIBFT = libft.a

FLAGS = -Wall -Wextra -Werror

source_dirs =. srcs libft/src includes libft/includes

SRCS_PS = push_swap_n_checker/check_valid_n_write.c \
          		push_swap_n_checker/functions.c \
          		push_swap_n_checker/push_swap.c \
          		push_swap.h \
          		push_swap_n_checker/sort_many.c \
          		push_swap_n_checker/sort_few.c \
          		push_swap_n_checker/utils.c \
          		push_swap_n_checker/sort_one_reverse_in_b.c \
          		push_swap_n_checker/functions_rotate.c \
          		push_swap_n_checker/sort_many_in_group_util.c \
          		push_swap_n_checker/sort_one_not_reverse_in_a.c \
          		push_swap_n_checker/check_only_numbers.c

SRCS_CH = push_swap_n_checker/checker.c \
          		push_swap_n_checker/check_valid_n_write.c \
          		push_swap_n_checker/functions.c \
          		push_swap.h \
          		push_swap_n_checker/functions_rotate.c \
          		push_swap_n_checker/check_only_numbers.c

OBJS_PS = $(notdir $(patsubst %.c,%.o,$(SRCS_PS)))

OBJS_CH = $(notdir $(patsubst %.c,%.o,$(SRCS_CH)))

all: $(NAME_PS) $(NAME_CH) $(LIBFT)

%.o: %.c
		gcc $(FLAGS) -c -MD $(addprefix -I,$(source_dirs)) $< -o $@

$(LIBFT):
	cd libft && make

$(NAME_PS): $(OBJS_PS)
		cd libft && make
		ar rc $(NAME) $?

$(NAME_CH): $(OBJS_CH)
		cd libft && make
		ar rc $(NAME) $?

VPATH := $(source_dirs)

clean:
	cd libft && make clean
	rm -f $(patsubst %.o,%.d,$(OBJS)) $(OBJS)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME_PS) $(NAME_CH)

re: fclean all

include $(wildcard *.d)