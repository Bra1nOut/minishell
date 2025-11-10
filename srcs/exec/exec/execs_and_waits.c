/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs_and_waits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:13:23 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 18:10:01 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "^C\n", 3);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_signal = 130;
}

void	setup_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
}

static void	handle_child_exit_status(int wstatus, t_ms *ms)
{
	if (WIFEXITED(wstatus))
		ms->status = WEXITSTATUS(wstatus);
	else if (WIFSIGNALED(wstatus))
	{
		ms->status = 128 + WTERMSIG(wstatus);
		if (WTERMSIG(wstatus) == SIGINT)
			write(1, "\n", 1);
		else if (WTERMSIG(wstatus) == SIGQUIT)
			write(2, "Quit (core dumped)\n", 19);
	}
}

void	exec_and_wait(t_ms *ms, t_cmd *cmd, char *path)
{
	pid_t	pid;
	int		wstatus;

	wstatus = 0;
	pid = fork();
	if (pid < 0)
	{
		exec_fork_error(path, ms);
		return ;
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pid_equal_zero(path, cmd, ms);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	waitpid(pid, &wstatus, 0);
	setup_signals();
	handle_child_exit_status(wstatus, ms);
}

void	exec_fork_error(char *path, t_ms *ms)
{
	perror("fork");
	free(path);
	ms->status = 1;
}
