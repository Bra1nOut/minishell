/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:33:27 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 18:12:46 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	builtin_checker(t_ms *ms, t_cmd *cmd)
{
	if (!cmd || !cmd->cmd_param || !cmd->cmd_param[0])
		return (0);
	if (cmd->infile != -2 || cmd->outfile != -2)
		redirection_dup2(cmd);
	if (!ft_strcmp(cmd->cmd_param[0], "pwd"))
		return (ft_print_pwd(ms));
	else if (!ft_strcmp(cmd->cmd_param[0], "env"))
		return (ft_print_env(ms));
	else if (!ft_strcmp(cmd->cmd_param[0], "exit"))
	{
		ft_exit(ms, cmd);
		return (1);
	}
	else if (!ft_strcmp(cmd->cmd_param[0], "cd"))
		return (ft_cd(ms, cmd));
	else if (!ft_strcmp(cmd->cmd_param[0], "unset"))
		return (ft_unset(ms, cmd));
	else if (!ft_strcmp(cmd->cmd_param[0], "echo"))
		return (ft_echo(cmd, ms));
	else if (!ft_strcmp(cmd->cmd_param[0], "export"))
		return (ft_export(ms));
	return (0);
}

static void	execute_command(t_ms *ms, t_cmd *current)
{
	if (is_builtin(current->cmd_param[0]) == 1)
	{
		builtin_checker(ms, current);
		exit(ms->status);
	}
	else
	{
		if (current->path)
			execve(current->path, current->cmd_param, ms->dup_env);
		exec_error(ms, current->path);
		exit(127);
	}
}

void	pid_equal_zero_pipes(int **pipe, int i, t_ms *ms, t_cmd *current)
{
	t_token	*cmd_tokens;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	setup_pipes(pipe, i, ms->cmd_count);
	close_pipes(pipe, ms->cmd_count - 1);
	cmd_tokens = find_cmd_tokens(ms->token, i);
	if (process_redirection(current, cmd_tokens, ms) == -1)
		exit(1);
	redirection_dup2(current);
	execute_command(ms, current);
}

void	check_perm(struct stat file_stat, int stat_result, char *cmd)
{
	if (stat_result == 0 && S_ISDIR(file_stat.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		exit(126);
	}
	else if (stat_result == 0 && !(file_stat.st_mode & S_IXUSR))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);
	}
	else if (stat_result != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
}

void	pid_equal_zero(char *path, t_cmd *cmd, t_ms *ms)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGPIPE, SIG_DFL);
	redirection_dup2(cmd);
	execve(path, cmd->cmd_param, ms->dup_env);
	exec_error(ms, path);
	exit(126);
}
