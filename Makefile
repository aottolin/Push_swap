RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m

NAME = push_swap
ARCHIVE = push_swap.a
SRCS = errors.c \
	   ft_split.c \
	   little_sort.c \
	   push_pa_pb.c \
	   reverse_rra_rrb_rrr.c \
	   rotate_ra_rb_rr.c \
	   set_init_nodes.c \
	   sort_push_swap.c \
	   stack_init.c \
	   swap_sa_sb_ss.c \
	   utilities.c \
	   main.c

OBJS = $(SRCS:.c=.o)
CC = gcc
MAKE_LIB = ar -rcs
FLAGS = -Wall -Wextra -Werror -MMD
DEPS = $(SRCS:.c=.d)
SILENCE = --no-print-directory

all: $(NAME)

$(NAME) : $(ARCHIVE) libpushswap.h
	@$(CC) $< -o $@
	@echo "$(WHITE) $(NAME) $(RESET) $(GREEN) ok $(RESET)"
	@echo "$(GREEN) -Todo ha sido compilado! $(RESET)"

$(ARCHIVE) : $(OBJS)
	@$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@ 
	@echo "$(GREEN) ok $(RESET) $(CYAN)$(BOLD) $<$(RESET)"

clean:
	@echo "$(MAGENTA) Eliminando .o  ... $(RESET)"
	@rm -f $(OBJS) $(DEPS)
	@echo "$(GREEN) clean OK  $(RESET)"

fclean: clean
	@echo "$(MAGENTA) Eliminando ... $(RESET)"
	@rm -f $(NAME) $(DEPS)
	@echo "$(GREEN) fclean OK  $(RESET)"

re: fclean all

.PHONY: all clean fclean re
