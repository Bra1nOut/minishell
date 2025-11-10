/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:58:55 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 17:39:17 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_join_env(char *key, char *value)
{
	char	*tmp;
	char	*res;

	if (!key)
		return (NULL);
	if (!value)
		return (ft_strdup(key));
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, value);
	free(tmp);
	return (res);
}

int	count_env_var(char **dup_env)
{
	int	count_vars;

	count_vars = 0;
	if (dup_env)
	{
		while (dup_env[count_vars])
			count_vars++;
	}
	return (count_vars);
}

void	copy_old_env(char **new_dup_env, char **old_dup_env, int count)
{
	int	i;

	i = 0;
	if (old_dup_env)
	{
		while (i < count)
		{
			new_dup_env[i] = old_dup_env[i];
			i++;
		}
	}
}

void	add_to_dup_env(t_ms *ms, char *new_env_var)
{
	int		old_count;
	char	**new_dup_env;

	old_count = count_env_var(ms->dup_env);
	new_dup_env = malloc(sizeof(char *) * (old_count + 2));
	if (!new_dup_env)
		return ;
	copy_old_env(new_dup_env, ms->dup_env, old_count);
	new_dup_env[old_count] = ft_strdup(new_env_var);
	new_dup_env[old_count + 1] = NULL;
	if (ms->dup_env)
		free(ms->dup_env);
	ms->dup_env = new_dup_env;
}

t_env	*create_env_node(char *param, t_ms *ms)
{
	char	*key;
	int		len;
	int		end;
	t_env	*new;

	len = 0;
	end = ft_strlen(param);
	while (param[len] != '=' && len < end)
		len++;
	key = ft_substr(param, 0, len);
	if (handle_existing_key(ms, key, param, len))
		return (NULL);
	new = malloc(sizeof(t_env));
	if (!new)
	{
		free(key);
		return (NULL);
	}
	new->key = key;
	if (param[len] == '=')
		new->value = ft_strdup(&param[len + 1]);
	else
		new->value = ft_strdup("""");
	new->next = NULL;
	return (new);
}
