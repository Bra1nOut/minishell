NAME		= minishell
CC			= cc
FLAGS		= -Wall -Wextra -Werror -g3 #-fsanitize=address
RM			= rm -rf
INCLUDES	= -Iincludes -ILibft

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
BLUE		= \033[38;5;153m
NC			= \033[0m
PURPLE		= \033[0;35m
PINK		= \033[38;5;205m
YELLOW		= \033[0;33m

# Bright colors
B_BLACK		= \033[1;30m
B_RED		= \033[1;31m
B_GREEN		= \033[1;32m
B_YELLOW	= \033[1;33m
B_BLUE		= \033[1;34m
B_PURPLE	= \033[1;35m
B_CYAN		= \033[1;36m
B_WHITE		= \033[1;37m

# Custom
WHITE		= \033[38;5;15m
L_GRAY		= \033[38;5;253m
GRAY1		= \033[38;5;250m
GRAY2		= \033[38;5;245m
GRAY3		= \033[38;5;242m
YELLOW1		= \033[38;5;226m
ORANGE1		= \033[38;5;220m
ORANGE2		= \033[38;5;214m
ORANGE3		= \033[38;5;208m
RED1		= \033[38;5;202m
RED2		= \033[38;5;196m
NC			= \033[0m

# Libft
LIBFT_DIR	= srcs/libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Sources
SRCS =	srcs/main.c\
		srcs/parsing/init/init.c\
		srcs/parsing/init/env_utils.c\
		srcs/parsing/parsing/parsing_env.c\
		srcs/parsing/parsing/env_append.c\
		srcs/parsing/parsing/cmd_list.c\
		srcs/parsing/parsing/signals.c\
		srcs/parsing/parsing/quote_utils.c\
		srcs/parsing/parsing/quote_utils2.c\
		srcs/parsing/parsing/quote_utils3.c\
		srcs/parsing/parsing/quote.c\
		srcs/parsing/parsing/utils.c\
		srcs/parsing/prompt/prompt_utils.c\
		srcs/parsing/prompt/prompt.c\
		srcs/parsing/tokenizer/parsing_token.c\
		srcs/parsing/tokenizer/tokenizer_utils_0.c\
		srcs/parsing/tokenizer/tokenizer_utils_1.c\
		srcs/parsing/tokenizer/tokenizer_utils_2.c\
		srcs/parsing/tokenizer/tokenizer_utils_3.c\
		srcs/parsing/tokenizer/tokenizer_utils_4.c\
		srcs/parsing/tokenizer/tokenizer.c\
		srcs/parsing/utils/free.c\
		srcs/parsing/utils/print_err.c\
		srcs/exec/exec/exec.c\
		srcs/exec/exec/exec_utils0.c\
		srcs/exec/exec/exec_utils1.c\
		srcs/exec/exec/execs_and_waits.c\
		srcs/exec/exec/execs_and_waits_pipes.c\
		srcs/exec/cmd_path.c\
		srcs/exec/utils.c\
		srcs/exec/pipe.c\
		srcs/exec/builtin_check.c\
		srcs/exec/redirections.c\
		srcs/exec/redirections_utils.c\
		srcs/exec/redir_check.c\
		srcs/exec/heredoc/heredoc.c\
		srcs/exec/heredoc/heredoc_utils0.c\
		srcs/exec/heredoc/heredoc_utils1.c\
		srcs/builtin/print/print_env.c\
		srcs/builtin/print/print_pwd.c\
		srcs/builtin/print/echo.c\
		srcs/builtin/exit/exit.c\
		srcs/builtin/exit/exit_utils.c\
		srcs/builtin/cd/cd.c\
		srcs/builtin/cd/cd_utils.c\
		srcs/builtin/cd/cd_env_update.c\
		srcs/builtin/export/export.c\
		srcs/builtin/export/export_utils.c\
		srcs/builtin/export/export_utils2.c\
		srcs/builtin/export/export_utils3.c\
		srcs/builtin/export/unset.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES) -lreadline

	@echo "$(WHITE)███████╗ ██████╗         $(YELLOW1)███████╗██╗  ██╗ ██████╗ ██████╗ ████████╗$(NC)"
	@echo "$(L_GRAY)██╔════╝██╔═══██╗        $(ORANGE1)██╔════╝██║  ██║██╔═══██╗██╔══██╗╚══██╔══╝$(NC)"
	@echo "$(GRAY1)███████╗██║   ██║        $(ORANGE2)███████╗███████║██║   ██║██████╔╝   ██║$(NC)"
	@echo "$(GRAY2)╚════██║██║   ██║        $(ORANGE3)╚════██║██╔══██║██║   ██║██╔══██╗   ██║$(NC)"
	@echo "$(GRAY3)███████║╚██████╔╝$(WHITE)███████╗$(RED1)███████║██║  ██║╚██████╔╝██║  ██║   ██║$(NC)"
	@echo "$(GRAY3)╚══════╝ ╚═════╝ $(WHITE)╚══════╝$(RED2)╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝$(NC)"

.c.o:
	@if [ "$(TARGET)" = "$(NAME)" ] && [ ! -f .mandatory ]; then \
		touch .mandatory; \
	fi
	@cc $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "$(B_BLUE)Cleaned the objects 🧹$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(B_BLUE)Cleaned the executable 🗑️$(NC)"

re: fclean all

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

.PHONY: all clean fclean re compile_with_progress libft
