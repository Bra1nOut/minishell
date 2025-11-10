/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:25:00 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:48:19 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	has_redirection(t_token *token)
{
	while (token && token->type != PIPE)
	{
		if (token->type == APPEND || token->type == IN
			|| token->type == OUT || token->type == HEREDOC)
		{
			if (token->next && token->next->type == WORD)
				return (1);
		}
		token = token->next;
	}
	return (0);
}

t_token	*find_cmd_tokens(t_token *start, int cmd_index)
{
	t_token	*current;
	int		pipe_count;

	current = start;
	pipe_count = 0;
	while (current && pipe_count < cmd_index)
	{
		if (current->type == PIPE)
			pipe_count++;
		current = current->next;
	}
	return (current);
}

static int	check_word_ending(t_token *current, t_ms *ms)
{
	char	*value;
	int		len;
	char	last_char;

	if (current->type != WORD || !current->next)
		return (0);
	value = current->value;
	len = ft_strlen(value);
	if (len > 1)
	{
		last_char = value[len - 1];
		if (last_char == '>' || last_char == '<' || last_char == '|')
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			ms->status = 2;
			return (-1);
		}
	}
	return (0);
}

int	validate_redirection_syntax(t_token *tokens, t_ms *ms)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		if (current->type >= IN && current->type <= HEREDOC)
		{
			if (!current->next || current->next->type != WORD)
			{
				if (current->type == OUT && current->next == NULL)
					return (0);
				ft_putstr_fd("minishell: syntax error near ", 2);
				ft_putstr_fd("unexpected token\n", 2);
				ms->status = 2;
				return (-1);
			}
		}
		if (check_word_ending(current, ms) == -1)
			return (-1);
		current = current->next;
	}
	return (0);
}
