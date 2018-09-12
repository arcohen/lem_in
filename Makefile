NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I ./includes/
SRC = srcs/main.c srcs/parse.c srcs/error_check.c
LIBFT = ./libft/libft.a
RM = rm -rf

all: $(LIBFT)
	@$(CC) -o $(CHKR) $(SRC) $(CFLAGS) $(INC) $(LIBFT)
	@echo "\033[32m[Compiled]\033[0m"

lem-in: clean_lem-in
	@$(RM) $(CHKR)
	@$(CC) -o $(CHKR) $(CH_SRCS) $(CFLAGS) $(C_INC) $(LIBFT)
	@echo "\033[32m[Compiled Checker]\033[0m"

clean_chkr:
	@$(RM) $(NAME)

$(LIBFT):
	@make re -C ./libft/
	@echo "\033[32m[Compiled Libft]\033[0m"

clean:
	@make clean -C ./libft/
	@$(RM) $(NAME)
	@echo "\033[31m[Cleaned]\033[0m"

fclean: clean
	@make fclean -C ./libft/
	@echo "\033[031m[Fucking Cleaned]\033[0m"

re: fclean all
