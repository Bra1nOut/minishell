/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:51:48 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:47:03 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_env	*ft_find_env(t_env *env, char *key)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	ft_update_pwd(t_env *env, char *old_path, t_ms *ms)
{
	t_env	*pwd;
	t_env	*oldpwd;
	char	cwd[4096];

	if (!getcwd(cwd, sizeof(cwd)))
		return ;
	oldpwd = ft_find_env(env, "OLDPWD");
	pwd = ft_find_env(env, "PWD");
	if (oldpwd)
	{
		free(oldpwd->value);
		oldpwd->value = ft_strdup(old_path);
		update_dup_env_var(ms, "OLDPWD", old_path);
	}
	if (pwd)
	{
		free(pwd->value);
		pwd->value = ft_strdup(cwd);
		update_dup_env_var(ms, "PWD", cwd);
	}
}

bool	cd_oldpwd(t_env *var, t_ms *ms)
{
	if (!var || !var->value)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		ms->status = 1;
		return (true);
	}
	ft_putstr_fd(var->value, 1);
	ft_putstr_fd("\n", 1);
	return (false);
}
