/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:39:00 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:54:00 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	cleanup_child_process(t_ms *ms, int status)
{
	free_all(ms);
	free(ms);
	exit(status);
}

int	check_key(t_ms *ms, char *key)
{
	t_env	*tmp;

	tmp = ms->env;
	while (tmp && tmp->next)
	{
		if (!ft_strcmp(tmp->key, key))
			return (1);
		tmp = tmp->next;
	}
	if (tmp && !ft_strcmp(tmp->key, key))
		return (1);
	return (0);
}

void	update_existing_env_var(t_ms *ms, char *key, char *new_value)
{
	t_env	*tmp;

	tmp = ms->env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			if (tmp->value)
				free(tmp->value);
			if (new_value)
				tmp->value = ft_strdup(new_value);
			else
				tmp->value = NULL;
			return ;
		}
		tmp = tmp->next;
	}
}

int	handle_existing_key(t_ms *ms, char *key, char *param, int len)
{
	if (check_key(ms, key))
	{
		if (param[len] == '=')
			update_existing_env_var(ms, key, &param[len + 1]);
		free(key);
		return (1);
	}
	return (0);
}
