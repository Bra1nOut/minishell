/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:13:26 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:56:12 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	anihilation(t_ms *ms, char *path)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": command not found\n", 2);
	free_all(ms);
	free(ms);
	free(path);
}

void	anihilation_bis(t_ms *ms)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(ms->cmd->next->cmd_param[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_all(ms);
	free(ms);
}

void	exec_error(t_ms *ms, char *path)
{
	struct stat	file_stat;
	int			stat_result;

	if (!path || !*path)
	{
		anihilation_bis(ms);
		exit(127);
	}
	stat_result = stat(path, &file_stat);
	if (ft_strncmp(path, "./", 2) == 0 || ft_strncmp(path, "../", 3) == 0
		|| ft_strncmp(path, "/", 1) == 0)
	{
		check_perm(file_stat, stat_result, path);
		free_all(ms);
		free(ms);
		free(path);
		return ;
	}
	anihilation(ms, path);
	exit(127);
}

void	ft_cmd_not_found(t_cmd *cmd, t_ms *ms)
{
	struct stat	file_stat;

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd->cmd_param[0], 2);
	if ((ft_strncmp(cmd->cmd_param[0], "./", 2) == 0
			|| ft_strncmp(cmd->cmd_param[0], "../", 3) == 0
			||ft_strncmp(cmd->cmd_param[0], "/", 1) == 0)
		&&stat(cmd->cmd_param[0], &file_stat) == 0)
	{
		if (!(file_stat.st_mode & S_IXUSR))
		{
			ft_putstr_fd(": Permission denied\n", 2);
			ms->status = 126;
		}
		else
		{
			ft_putstr_fd(": command not found\n", 2);
			ms->status = 127;
		}
	}
	else
	{
		ft_putstr_fd(": command not found\n", 2);
		ms->status = 127;
	}
}
