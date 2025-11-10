/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:43:34 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 16:39:38 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pid_equal_zero_heredoc(int pipe_fd[2], char *delimiter)
{
	close(pipe_fd[0]);
	read_heredoc_lines(pipe_fd, delimiter);
	close(pipe_fd[1]);
	exit(0);
}

int	heredoc_create_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	return (0);
}

int	heredoc_fork_process(int pipe_fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (-1);
	}
	return (pid);
}

int	wait_and_process_child(pid_t pid, int pipe_fd[2])
{
	int	status;

	close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		close(pipe_fd[0]);
		return (-1);
	}
	return (pipe_fd[0]);
}
