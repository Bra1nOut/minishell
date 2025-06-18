NAME	=	minishell

# Compiler and CFlags (CFLAGS: add -I libft/ for header files)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -Iincludes
# LIBFT_FLAGS = -L./library/libft -lft
# RDL_FLAG = -lreadline
LDFLAGS	= -LLibft -lft -lreadline

# File Management
RM		=	rm -rf

# Library
LIBFT	= ./Libft/libft.a

# Source Files
SRCS	= 	main.c \
				init/env.c \
				init/prompt.c \
				debug/init_debug.c \
				cleanup/free_misc.c \
				# exec/exec.c
				

OBJS	= $(SRCS:.c=.o)

# Include headers
INCLUDES = includes/minishell.h includes/colors.h

# Build rules
all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT)
					$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

%.o: %.c 		$(INCLUDES)
					$(CC) $(CFLAGS) -c $< -o $@

# Build Libft
# @make -s -C library/libft clean
# BREAKDOWN OF THE ABOVE FULL COMMAND:
# @		->	Suppress this line from being printed
# make	->	Call make again
# -s	->	Silent mode (don’t print inner commands)
# -C dir->	Run make in directory library/libft
# clean	->	Run the clean target in that directory
$(LIBFT):
				@make -C Libft

# Clean Rules
clean:
				@$(RM) $(OBJS)
				@make  -C Libft clean

fclean: 		clean
				@$(RM) $(NAME)
				@$(RM) $(LIBFT)

re: 			fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re