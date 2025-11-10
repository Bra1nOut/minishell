/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:07:37 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:54:53 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	check_cmd_and_builtin(t_ms *ms, t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	if (!cmd || !cmd->cmd_param || !cmd->cmd_param[0])
		return (1);
	if (has_redirection(ms->token))
	{
		if (process_redirection(cmd, ms->token, ms) == -1)
			return (1);
		if (is_builtin(cmd->cmd_param[0]))
		{
			pid = fork();
			if (pid == 0)
			{
				status = builtin_checker(ms, cmd);
				cleanup_child_process(ms, status);
			}
			waitpid(pid, &status, 0);
			return (1);
		}
		return (0);
	}
	if (builtin_checker(ms, cmd))
		return (1);
	return (0);
}

void	cmd_no_pipe(t_ms *ms, t_cmd *cmd)
{
	char	*path;

	if (check_cmd_and_builtin(ms, cmd))
		return ;
	path = ft_find_path(cmd->cmd_param[0], ms->env);
	if (!path || access(path, F_OK | X_OK) != 0)
	{
		if (path)
			free(path);
		ft_cmd_not_found(cmd, ms);
		free_cmd(&ms->cmd);
		return ;
	}
	exec_and_wait(ms, cmd, path);
	free(path);
	free_cmd(&ms->cmd);
}

void	all_cmd_path(t_ms *ms, t_cmd *cmd)
{
	char	*path;

	while (cmd)
	{
		if (cmd->cmd_param && cmd->cmd_param[0]
			&& !is_builtin(cmd->cmd_param[0]))
		{
			path = ft_find_path(cmd->cmd_param[0], ms->env);
			if (path && access(path, F_OK | X_OK) == 0)
			{
				free(cmd->path);
				cmd->path = path;
			}
			else if (path)
				free(path);
		}
		cmd = cmd->next;
	}
}

void	cmd_pipe(t_ms *ms, t_cmd *cmd)
{
	int		**pipes;
	t_cmd	*current;

	ms->cmd_count = ft_count_cmd(ms->token);
	pipes = create_pipes(ms->cmd_count - 1);
	if (!pipes)
		return ;
	all_cmd_path(ms, cmd);
	current = cmd;
	exec_and_wait_pipes(pipes, ms, current);
}

void	exec_cmd(t_ms *ms, t_cmd *cmd)
{
	if (validate_redirection_syntax(ms->token, ms) == -1)
		return ;
	if (pipes_checker(ms->token))
		cmd_pipe(ms, cmd);
	else
		cmd_no_pipe(ms, cmd);
}
