/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:21:10 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 15:31:37 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	handle_heredoc_eof(char *line, char *delimiter)
{
	if (!line)
	{
		printf("minishell: warning: here-document delimited ");
		printf("by end-of-file (wanted `%s')\n", delimiter);
		return (true);
	}
	return (false);
}

bool	handle_heredoc_signal(char *line, int pipe_fd[2])
{
	if (g_signal == 130)
	{
		if (line)
			free(line);
		close(pipe_fd[1]);
		return (true);
	}
	return (false);
}

bool	handle_heredoc_delimiter(char *line, char *delimiter)
{
	if (ft_strcmp(line, delimiter) == 0)
	{
		free(line);
		return (true);
	}
	return (false);
}

void	heredoc_prompt(char *line, int pipe_fd[2])
{
	write(pipe_fd[1], line, ft_strlen(line));
	write(pipe_fd[1], "\n", 1);
	free(line);
}
