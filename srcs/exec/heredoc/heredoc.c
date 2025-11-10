/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:26:11 by ml-hote           #+#    #+#             */
/*   Updated: 2025/11/07 15:47:40 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/* HEREDOC
CMD << "EOF"
Il faut que j'envoie ce que me donne le heredoc
Check la condition de fin
*/

int	read_heredoc_lines(int pipe_fd[2], char *delimiter)
{
	char	*line;

	signal(SIGINT, here_doc_sigint);
	while (1)
	{
		line = readline("> ");
		if (handle_heredoc_signal(line, pipe_fd))
			return (-1);
		if (handle_heredoc_eof(line, delimiter))
			return (-1);
		if (handle_heredoc_delimiter(line, delimiter))
			return (-1);
		heredoc_prompt(line, pipe_fd);
	}
	return (0);
}

int	handle_heredoc(char *delimiter)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (heredoc_create_pipe(pipe_fd) == -1)
		return (-1);
	pid = heredoc_fork_process(pipe_fd);
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		pid_equal_zero_heredoc(pipe_fd, delimiter);
		return (-1);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		return (wait_and_process_child(pid, pipe_fd));
	}
}
