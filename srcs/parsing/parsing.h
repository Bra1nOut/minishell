/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 02:44:06 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:32:45 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../includes/minishell.h"

typedef enum e_quote_state
{
	NO_QUOTE = 0,
	SINGLE_QUOTE = 1,
	DOUBLE_QUOTE = 2
}	t_quote_state;

typedef struct s_quote_data
{
	char			*result;
	t_quote_state	*quote_state;
	int				*j;
}	t_quote_data;

typedef struct s_env_exp
{
	char	*result;
	char	*env_var;
	int		result_pos;
	int		result_size;
}	t_env_exp;

typedef struct s_process_data
{
	t_env_exp		*exp;
	t_ms			*ms;
	t_quote_state	*quote_state;
}	t_process_data;

/* --- Expander --- */
int		ft_expander(const char *str, t_ms *ms);
int		get_env_to_result(const char *str, int *i, t_env_exp *exp, t_ms *ms);
void	rm_first_token(t_token **lst_tok);
void	add_token_to_list(t_token **current, char *word);
void	process_pipe_token(t_token **current, int *i);
void	process_redirect_token(const char *prompt, t_token **current, int *i);
void	process_word_token(const char *prompt, t_token **current, int *i);
void	append_string_to_result(char *result, int *pos, int max_size,
			char *str);
void	append_char_to_result(char *result, int *pos, int max_size, char c);
void	handle_status_expansion(t_env_exp *exp, t_ms *ms, int *i);
char	*ft_expander_to_string(const char *str, t_ms *ms);
t_token	*ft_lst_prompt(const char *prompt, t_ms *ms);
t_token	*ft_newtoken(char *value);
	/* ------------------ */

/* --- Initialization --- */
t_ms	*ft_init_ms(t_ms *ms, char **envp);
t_env	*init_env(char **envp);
char	*find_env_value(char *env_line);
char	*find_env_key(char *env_line);
void	ft_add_env_to_end(t_env **head, t_env *new);
/* ------------------ */

/* --- Prompt --- */
void	ft_prompt(t_ms *ms);
void	create_and_exec_cmd(t_ms *ms);
char	*get_user_input(void);
char	*ft_make_prompt(void);
bool	handle_empty_line(char *line);
bool	handle_validation_quote(char *line);
bool	handle_syntax_check(t_ms *ms, char *line);
/* ------------------ */

/* --- Command Maker --- */
t_cmd	*create_single_cmd(t_token *token);
t_cmd	*create_multiple_cmd(t_token *token);
t_token	*skip_to_next_cmd(t_token *tmp);
/* ------------------ */

/* --- Tokenizer --- */
void	assign_token_type(t_token *token);
void	print_tokens(t_token *token);
void	add_token_to_list_with_quote_type(t_token **current,
			char *word, int quote_type);
void	add_token_to_list(t_token **current, char *word);
void	ft_tokadd_back(t_token **lst, t_token *new, char *value);
bool	word_check(t_token *token);
bool	syntax_check(t_token *token);
bool	token_is_opperator(t_token *token);
bool	check_first_token(t_token *token);
bool	check_token_str(t_token *tmp);
bool	valid_token_str(t_token *token);
t_token	*ft_toklast(t_token *lst);
t_token	*ft_newtoklst(void);
/* ------------------ */

/* --- Quotes --- */
char	*handle_quotes(const char *str);
char	*extract_quoted_content(const char *str, int start, int len);
void	handle_no_quote(const char *str, int i, t_quote_data *data);
void	handle_single_quote(const char *str, int i, t_quote_data *data);
void	handle_double_quote(const char *str, int i, t_quote_data *data);
void	process_quote_type(const char *str, int i, t_quote_data *data);
int		get_word_length(const char *prompt, int start);
bool	is_quote_closed(const char *str, int start, int end);
bool	validate_quotes(const char *input);
char	*ft_exp_to_str_w_quotes(const char *str, t_ms *ms);
void	init_expander_data(t_env_exp *exp, const char *str);
/* ------------------ */

#endif
