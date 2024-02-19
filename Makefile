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
SRCS = 
FLAGS = -Wall -Wextra -Werror -MMD
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
SILENCE = --no-print-directory

all: $(NAME)
CC = gcc

%.o:%.c Makefile 
	@echo "$(GREEN) ok $(RESET) $(CYAN)$(BOLD) $<$(RESET)"
	@$(CC) $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS) Makefile 
	@make -C all $(SILENCE)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(WHITE) $(NAME) $(RESET) $(GREEN) ok $(RESET)"
	@echo "$(GREEN) -Todo ha sido compilado! $(RESET)"

clean:
	@echo "$(MAGENTA) Eliminando .o  ... $(RESET)"
	@rm -f $(OBJS) $(DEPS)
	@make -C clean $(SILENCE)
	@echo "$(GREEN) clean OK  $(RESET)"

fclean: clean
	@echo "$(MAGENTA) Eliminando ... $(RESET)"
	@rm -f $(NAME)
	@make -C fclean $(SILENCE)
	@echo "$(GREEN) fclean OK  $(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re 
