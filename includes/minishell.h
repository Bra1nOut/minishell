/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:38:59 by jockova           #+#    #+#             */
/*   Updated: 2025/06/18 11:47:37 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include "colors.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

// # define INPUT	1 //"<"  etc.

// typedef struct s_lst
// {
// 	char			*str;
// 	struct s_lst	*prev;
// 	struct s_lst	*next;
// } t_lst;

typedef struct	s_envlst
{
	char			*key;
	char			*value;
	int				index;
	struct s_envlst	*next;
} t_envlst;

typedef struct	s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
} t_token;

typedef struct s_cmd
{
	bool			skip_cmd;
	int				infile;
	int				outfile;
	char			**cmd_param;
	struct s_cmd	*prev;
	struct s_cmd	*next;	
} t_cmd;


typedef struct s_ms
{
	t_envlst		*env_lst;
	t_token			*token;
	t_cmd			*cmd;
	// int 			exit_code;
	// int 			pip[2];
	// bool 			sq;
}	t_ms;

// init/env.c
void		env_lst_make(t_ms *ms, char **envp);
t_envlst	*env_lst_new(char *env_var);
char		*cpy_left(char *env_var);
char		*cpy_right(char *env_var);
void		ft_lst_add_back(t_envlst **lst, t_envlst *new);

// cleanup/free_misc.c
void		free_env_lst(t_envlst *head);

// debug/init_debug.c
void 		ms_print_state(t_ms *ms);
void 		ms_print_envlst(t_ms ms);

#endif