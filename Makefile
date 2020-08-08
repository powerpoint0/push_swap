NAME_PS = push_swap
NAME_CH = checker

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

source_dirs = . push_swap_n_checker libft/includes

SRCS_PS = push_swap_n_checker/check_valid_n_write.c \
          		push_swap_n_checker/functions.c \
          		push_swap_n_checker/push_swap.c \
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
          		push_swap_n_checker/functions_rotate.c \
          		push_swap_n_checker/check_only_numbers.c

SRCS_LIB = libft/ft_atoi.c \
           		libft/ft_binar_chr.c \
           		libft/ft_bzero.c \
           		libft/ft_count_words.c \
           		libft/ft_isalnum.c \
           		libft/ft_isalpha.c \
           		libft/ft_isascii.c \
           		libft/ft_isdigit.c \
           		libft/ft_isprint.c \
           		libft/ft_itoa.c \
           		libft/ft_lstadd.c \
           		libft/ft_lstdel.c \
           		libft/ft_lstdelone.c \
           		libft/ft_lstiter.c \
           		libft/ft_lstmap.c \
           		libft/ft_lstnew.c \
           		libft/ft_memalloc.c \
           		libft/ft_memccpy.c \
           		libft/ft_memchr.c \
           		libft/ft_memcmp.c \
           		libft/ft_memcpy.c \
           		libft/ft_memdel.c \
           		libft/ft_memmove.c \
           		libft/ft_memset.c \
           		libft/ft_print_params.c \
           		libft/ft_putchar.c \
           		libft/ft_putchar_fd.c \
           		libft/ft_putendl.c \
           		libft/ft_putendl_fd.c \
           		libft/ft_putnbr.c \
           		libft/ft_putnbr_fd.c \
           		libft/ft_putstr.c \
           		libft/ft_putstr_fd.c \
           		libft/ft_sort_params.c \
           		libft/ft_sqrt.c \
           		libft/ft_strcat.c \
           		libft/ft_strchr.c \
           		libft/ft_strclr.c \
           		libft/ft_strcmp.c \
           		libft/ft_strcpy.c \
           		libft/ft_strdel.c \
           		libft/ft_strdup.c \
           		libft/ft_strequ.c \
           		libft/ft_striter.c \
           		libft/ft_striteri.c \
           		libft/ft_strjoin.c \
           		libft/ft_strlcat.c \
           		libft/ft_strlen.c \
           		libft/ft_strmap.c \
           		libft/ft_strmapi.c \
           		libft/ft_strncat.c \
           		libft/ft_strncmp.c \
           		libft/ft_strncpy.c \
           		libft/ft_strnequ.c \
           		libft/ft_strnew.c \
           		libft/ft_strnstr.c \
           		libft/ft_strrchr.c \
           		libft/ft_strsplit.c \
           		libft/ft_strstr.c \
           		libft/ft_strsub.c \
           		libft/ft_strtrim.c \
           		libft/ft_tolower.c \
           		libft/ft_toupper.c \

OBJS_PS = $(notdir $(patsubst %.c,%.o,$(SRCS_PS)))

OBJS_CH = $(notdir $(patsubst %.c,%.o,$(SRCS_CH)))

OBJS_LIB = $(patsubst %.c,%.o,$(SRCS_LIB))

LDIRS = libft/

LIB_ALL = $(addsuffix .all,$(LDIRS))

all: $(LIB_ALL) $(LIBFT) $(NAME_PS) $(NAME_CH)

%.o: %.c
		gcc $(FLAGS) -c -MD $(addprefix -I,$(source_dirs)) $< -o $@

$(LIBFT): $(OBJS_LIB)
	cd libft && make


$(NAME_PS): $(OBJS_PS) $(LIBFT)
		cd libft && make
		gcc $(FLAGS) $(OBJS_PS) -o $(NAME_PS) $(LIBFT)

$(NAME_CH): $(OBJS_CH) $(LIBFT)
		cd libft && make
		gcc $(FLAGS) $(OBJS_CH) -o $(NAME_CH) $(LIBFT)

VPATH := $(source_dirs)

clean:
	cd libft && make clean
	rm -f $(patsubst %.o,%.d,$(OBJS_PS)) $(patsubst %.o,%.d,$(OBJS_CH)) $(OBJS_PS) $(OBJS_CH)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME_PS) $(NAME_CH)

re: fclean all

%.all:
	make -C $*
include $(wildcard *.d)