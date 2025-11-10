/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:49:45 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 20:03:36 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_env	*init_env(char **envp)
{
	int		i;
	t_env	*new;
	t_env	*head;

	i = 0;
	head = NULL;
	while (envp[i])
	{
		new = malloc(sizeof(t_env));
		if (!new)
			return (NULL);
		new->key = find_env_key(envp[i]);
		new->value = find_env_value(envp[i]);
		new->next = NULL;
		ft_add_env_to_end(&head, new);
		i++;
	}
	return (head);
}

char	**dup_env(char **envp)
{
	int		i;
	int		count;
	char	**dup;

	i = 0;
	count = 0;
	while (envp[count])
		count++;
	dup = malloc(sizeof(char *) * (count + 1));
	if (!dup)
		return (NULL);
	while (i < count)
	{
		dup[i] = ft_strdup(envp[i]);
		if (!dup[i])
		{
			while (--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static void	setup_pwd_env(t_ms *ms)
{
	char	cwd[4096];
	t_env	*pwd_env;

	if (getcwd(cwd, sizeof(cwd)))
	{
		update_dup_env_var(ms, "PWD", cwd);
		pwd_env = ft_find_env(ms->env, "PWD");
		if (pwd_env)
		{
			free(pwd_env->value);
			pwd_env->value = ft_strdup(cwd);
		}
		else
		{
			pwd_env = malloc(sizeof(t_env));
			if (pwd_env)
			{
				pwd_env->key = ft_strdup("PWD");
				pwd_env->value = ft_strdup(cwd);
				pwd_env->next = NULL;
				ft_add_env_to_end(&ms->env, pwd_env);
			}
		}
	}
}

t_ms	*ft_init_ms(t_ms *ms, char **envp)
{
	ms = malloc(sizeof(t_ms));
	if (!ms)
		return (NULL);
	g_signal = 0;
	ms->cmd = NULL;
	ms->env = init_env(envp);
	ms->token = NULL;
	ms->dup_env = dup_env(envp);
	ms->status = 0;
	setup_pwd_env(ms);
	return (ms);
}
