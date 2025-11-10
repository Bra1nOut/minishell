/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs_and_waits_pipes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:21:00 by space-blue        #+#    #+#             */
/*   Updated: 2025/11/07 19:56:42 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	fork_and_exec_commands(int **pipes, t_ms *ms,
				t_cmd *current, pid_t *pid)
{
	int	i;

	i = 0;
	while (i < ms->cmd_count && current)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (current->path == NULL && is_builtin(current->cmd_param[0]) == 0)
			{
				ft_cmd_not_found(current, ms);
				exit(127);
			}
			else
				pid_equal_zero_pipes(pipes, i, ms, current);
		}
		else if (pid[i] < 0)
			perror("fork");
		current = current->next;
		i++;
	}
}

static void	wait_for_children(pid_t *pid, t_ms *ms)
{
	int	i;
	int	status;
	int	last_exit_code;

	last_exit_code = 0;
	i = 0;
	while (i < ms->cmd_count)
	{
		waitpid(pid[i], &status, 0);
		if (i == ms->cmd_count - 1)
		{
			if (WIFEXITED(status))
				last_exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				last_exit_code = 128 + WTERMSIG(status);
		}
		i++;
	}
	ms->status = last_exit_code;
}

void	exec_and_wait_pipes(int **pipes, t_ms *ms, t_cmd *current)
{
	pid_t	*pid;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = malloc(sizeof(pid_t) * ms->cmd_count);
	fork_and_exec_commands(pipes, ms, current, pid);
	close_pipes(pipes, ms->cmd_count - 1);
	wait_for_children(pid, ms);
	free(pid);
	setup_signals();
}
