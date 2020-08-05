NAME_PS = push_swap
NAME_CH = checker

FLAGS = -Wall -Wextra -Werror

source_dirs =. srcs libft/src includes libft/includes

SRCS_PS =

SRCS_CH =

OBJS_PS = $(notdir $(patsubst %.c,%.o,$(SRCS_PS)))

OBJS_CH = $(notdir $(patsubst %.c,%.o,$(SRCS_CH)))

all: $(NAME_PS) $(NAME_CH)

%.o: %.c
		gcc $(FLAGS) -c -MD $(addprefix -I,$(source_dirs)) $< -o $@

$(NAME_PS): $(OBJS_PS)
		#make libft
		ar rc $(NAME) $?

$(NAME_CH): $(OBJS_CH)
		#make libft
		ar rc $(NAME) $?


VPATH := $(source_dirs)

clean:
	rm -f $(patsubst %.o,%.d,$(OBJS)) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	gcc  main.c -MD $(addprefix -I,$(source_dirs)) $(NAME) -o test

include $(wildcard *.d)