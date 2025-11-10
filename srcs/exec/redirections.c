/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:47:20 by bra1nout          #+#    #+#             */
/*   Updated: 2025/11/07 16:49:23 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redirection_dup2(t_cmd *cmd)
{
	if (cmd->infile != -2 && cmd->infile >= 0)
	{
		if (dup2(cmd->infile, STDIN_FILENO) == -1)
			perror("dup2 input");
		close(cmd->infile);
		cmd->infile = -2;
	}
	if (cmd->outfile != -2 && cmd->outfile >= 0)
	{
		if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
		{
			perror("dup2 output");
		}
		close(cmd->outfile);
		cmd->outfile = -2;
	}
}

int	handle_redirection(t_cmd *cmd, t_token *token, int type, t_ms *ms)
{
	int		fd;
	char	*filename;

	fd = -1;
	filename = token->next->value;
	if (type == APPEND)
		fd = open(token->next->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (type == IN)
		fd = open(token->next->value, O_RDONLY);
	else if (type == OUT)
		fd = open(token->next->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == HEREDOC)
	{
		fd = handle_heredoc(token->next->value);
		if (fd == -1)
		{
			ms->status = 130;
			return (-1);
		}
	}
	if (type != HEREDOC && fd == -1)
		return (redirection_file_error(ms, filename));
	redirection_assign_fd(cmd, type, fd);
	return (0);
}

int	process_redirection(t_cmd *cmd, t_token *token_start, t_ms *ms)
{
	t_token	*token;
	int		type;

	token = token_start;
	while (token && token->type != PIPE)
	{
		type = token->type;
		if (type == APPEND || type == IN || type == OUT || type == HEREDOC)
		{
			if (!token->next || !token->next->value)
			{
				ft_putstr_fd("minishell: syntax error near ", 2);
				ft_putstr_fd("unexpected token `newline'\n", 2);
				ms->status = 2;
				return (-1);
			}
			if (handle_redirection(cmd, token, type, ms) < 0)
				return (-1);
			token = token->next;
		}
		token = token->next;
	}
	return (0);
}

int	setup_redirections(t_cmd *cmd, t_token *token_list, t_ms *ms)
{
	return (process_redirection(cmd, token_list, ms));
}
