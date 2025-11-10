/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:44:01 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:54:23 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ==== Includes ==== */
# include "../srcs/libft/libft/libft.h"
# include "colors.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <dirent.h>
# include <string.h>
# include <signal.h>
# include <termios.h>

/* ==== Error Strings & Exit Codes ==== */
# define ERR_MALLOC	"malloc error\n"
# define ERR_PIPE	"pipe error\n"
# define ERR_FORK	"fork error\n"

# define EXT_MALLOC	2
# define EXT_PIPE	3
# define EXT_FORK	4

/* ==== Color Definitions ==== */
// PRINTF COLORS
# define RESET  "\033[0m"
# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE   "\033[0;34m"
# define WHITE  "\033[0;97m"
// BOLD COLORS
# define BOLD_RESET	"\033[1m"
# define BOLD_RED   "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_BLUE "\033[1;34m"

/* ==== Global Variables ==== */
extern int	g_signal;

/* ==== Enums ==== */
typedef enum e_token_type
{
	COMMAND = 1,
	WORD,
	PIPE,
	IN,
	OUT,
	APPEND,
	HEREDOC,
	INVALID
}	t_token_type;

/* ==== Structs ==== */
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_token
{
	char			*value;
	int				type;
	int				quote_type;	// 0=NO_QUOTE, 1=SINGLE_QUOTE, 2=DOUBLE_QUOTE
	bool			joined;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	int				infile;
	int				outfile;
	bool			append;
	char			**cmd_param;
	char			*path;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_ms
{
	struct sigaction	sa;
	t_env				*env;
	t_token				*token;
	t_cmd				*cmd;
	int					cmd_count;
	int					status;
	char				**dup_env;
}	t_ms;

/* --- Free ---*/
void		free_array(char **arr);
void		free_cmd(t_cmd **list);
void		free_cmd_exit(t_cmd *cmd);
void		free_token(t_token *tok);
void		free_env(t_env *env);
void		free_pid(int **pipes);
void		free_pipes(int **pipes, int nb_pipes);
void		little_free(t_ms *ms, t_cmd *cmd);
void		free_all(t_ms *ms);
/* ------------------ */

/* --- Utils --- */
char		*get_env(t_env *env, char *key);
bool		ft_print_error(char *str);
bool		ft_print_error_token(t_token *token);
/* ------------------ */

/* === Builtins === */
int			builtin_checker(t_ms *ms, t_cmd *cmd);
int			is_builtin(char *cmd);

/* --- Printable --- */
int			ft_echo(t_cmd *cmd, t_ms *ms);
int			ft_print_env(t_ms *ms);
int			ft_print_pwd(t_ms *ms);

/* --- Export --- */
int			ft_export(t_ms *ms);
int			ft_unset(t_ms *ms, t_cmd *cmd);
int			count_env_var(char **dup_env);
int			handle_existing_key(t_ms *ms, char *key, char *param, int len);
int			check_key(t_ms *ms, char *key);
char		*ft_join_env(char *key, char *value);
void		fill_export(t_env	*env, t_env	**array);
void		sort_export(t_env **array);
void		ft_print_export(t_env **array);
void		copy_old_env(char **new_dup_env, char **old_dup_env, int count);
void		add_to_dup_env(t_ms *ms, char *new_env_var);
void		ft_envadd_back(t_env **env, t_env *new);
void		update_existing_env_var(t_ms *ms, char *key, char *new_value);
t_env		*create_env_node(char *param, t_ms *ms);
t_env		*ft_envlast(t_env *env);

/* --- Exit ---*/
void		ft_exit(t_ms *ms, t_cmd *cmd);
void		exit_clean(t_ms *ms);

/* --- CD ---*/
int			ft_cd(t_ms *ms, t_cmd *cmd);
void		ft_update_pwd(t_env *env, char *old_path, t_ms *ms);
bool		cd_oldpwd(t_env *var, t_ms *ms);
t_env		*ft_find_env(t_env *env, char *key);
void		update_dup_env_var(t_ms *ms, char *key, char *value);
/* ================== */

/* === Command Execution === */
void		ft_exec_cmd(t_ms *ms, t_cmd *cmd);
void		exec_cmd(t_ms *ms, t_cmd *cmd);
void		cmd_no_pipe(t_ms *ms, t_cmd *cmd);
void		exec_fork_error(char *path, t_ms *ms);
void		pid_equal_zero(char *path, t_cmd *cmd, t_ms *ms);
void		pid_equal_zero_pipes(int **pipe, int i, t_ms *ms, t_cmd *current);
void		setup_pipes(int **pipes, int cmd_index, int cmd_count);
void		close_pipes(int **pipes, int nb_pipes);
void		exec_and_wait_pipes(int **pipes, t_ms *ms, t_cmd *current);
void		exec_and_wait(t_ms *ms, t_cmd *cmd, char *path);
void		redirection_dup2(t_cmd *cmd);
void		exec_error(t_ms *ms, char *path);
int			**create_pipes(int nb_pipes);

/* --- Command Execution Utils --- */
char		*ft_find_path(char *cmd, t_env *env);
void		check_perm(struct stat file_stat, int stat_result, char *cmd);
void		ft_cmd_not_found(t_cmd *cmd, t_ms *ms);
void		cleanup_child_process(t_ms *ms, int status);
int			has_redirection(t_token *token);
int			ft_count_cmd(t_token *token);
t_token		*find_cmd_tokens(t_token *start, int cmd_index);
bool		pipes_checker(t_token *token);
bool		ft_word_check(t_token *token);
/* ================== */

/* --- Initialization --- */
char		**dup_env(char **envp);
t_ms		*ft_init_ms(t_ms *ms, char **envp);
/* ------------------ */

/* --- Prompt Handling --- */
void		ft_prompt(t_ms *ms);
char		*ft_make_prompt(void);
/* ------------------ */

/* --- Quote Handling --- */
char		*handle_quotes(const char *str);
int			get_word_length(const char *prompt, int start);
bool		validate_quotes(const char *input);
bool		is_quote_closed(const char *str, int start, int end);
char		*extract_quoted_content(const char *str, int start, int len);
/* ------------------ */

/* --- Signals --- */
void		signal_handler(int signal);
void		handle_sigquit(int signal);
void		here_doc_sigint(int signal);
/* ------------------ */

/* ==== Signal Handling ==== */
void		handle_sigint(int sig);
void		setup_signals(void);
void		sigquit_handler(int signal);
/* ------------------ */

/* --- Redirections --- */
int			validate_redirection_syntax(t_token *tokens, t_ms *ms);
int			setup_redirections(t_cmd *cmd, t_token *token_list, t_ms *ms);
int			process_redirection(t_cmd *cmd, t_token *token_start, t_ms *ms);
int			handle_redirection(t_cmd *cmd, t_token *token, int type, t_ms *ms);
void		redirection_assign_fd(t_cmd *cmd, int type, int fd);
int			redirection_file_error(t_ms *ms, char *filename);

/* ------------------ */

/* --- Heredoc --- */
int			handle_heredoc(char *delimiter);
int			heredoc_create_pipe(int pipe_fd[2]);
int			heredoc_fork_process(int pipe_fd[2]);
int			read_heredoc_lines(int pipe_fd[2], char *delimiter);
int			wait_and_process_child(pid_t pid, int pipe_fd[2]);
void		heredoc_prompt(char *line, int pipe_fd[2]);
void		pid_equal_zero_heredoc(int pipe_fd[2], char *delimiter);
bool		handle_heredoc_eof(char *line, char *delimiter);
bool		handle_heredoc_signal(char *line, int pipe_fd[2]);
bool		handle_heredoc_delimiter(char *line, char *delimiter);
/* ------------------ */

#endif
