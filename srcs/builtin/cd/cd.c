/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:40:47 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:31:44 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/* ----------- TODO ------------
	A chaque CD il faut changer oldpwd et pwd
	env | grep PWD
	Car ca ne se reactualise pas
*/

bool	cd_no_home(t_cmd *cmd, t_env *var, t_ms *ms)
{
	if (!cmd->cmd_param[1])
	{
		if (!var || !var->value)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			ms->status = 1;
			return (true);
		}
	}
	return (false);
}

bool	cd_too_many_args(t_cmd *cmd, t_ms *ms)
{
	if (cmd->cmd_param[1] && cmd->cmd_param[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		ms->status = 1;
		return (true);
	}
	else
		return (false);
}

static char	*get_cd_path(t_ms *ms, t_cmd *cmd)
{
	t_env	*var;

	var = NULL;
	if (cd_too_many_args(cmd, ms) == true)
		return (NULL);
	if (!cmd->cmd_param[1])
	{
		var = ft_find_env(ms->env, "HOME");
		if (cd_no_home(cmd, var, ms) == true)
			return (NULL);
		else
			return (var->value);
	}
	if (!ft_strcmp(cmd->cmd_param[1], "-"))
	{
		var = ft_find_env(ms->env, "OLDPWD");
		if (cd_oldpwd(var, ms) == true)
			return (NULL);
		else
			return (var->value);
	}
	return (cmd->cmd_param[1]);
}

// void	cd_parrent_dir_error()

static int	handle_getcwd_error(char *old_path, t_ms *ms)
{
	t_env	*pwd_env;

	ft_putstr_fd("cd: error retrieving current directory: ", 2);
	ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	pwd_env = ft_find_env(ms->env, "PWD");
	if (pwd_env && pwd_env->value)
		ft_strcpy(old_path, pwd_env->value);
	else
		ft_strcpy(old_path, "/");
	return (0);
}

int	ft_cd(t_ms *ms, t_cmd *cmd)
{
	char	old_path[4096];
	char	*path;

	if (!getcwd(old_path, sizeof(old_path)))
		handle_getcwd_error(old_path, ms);
	path = get_cd_path(ms, cmd);
	if (!path)
		return (1);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		ms->status = 1;
		return (1);
	}
	ft_update_pwd(ms->env, old_path, ms);
	ms->status = 0;
	return (1);
}
