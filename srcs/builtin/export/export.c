/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:35:06 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 17:28:37 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	fill_sort_print(t_env *env)
{
	t_env	**array;
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	array = malloc(sizeof(t_env *) * (i + 1));
	if (!array)
		return ;
	fill_export(env, array);
	sort_export(array);
	ft_print_export(array);
	free(array);
}

static bool	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !str[0])
		return (false);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (false);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

static void	process_single_env_var(t_ms *ms, char *param, t_env **env)
{
	t_env	*new;
	char	*add_str;

	if (!is_valid_identifier(param))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(param, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		ms->status = 1;
		return ;
	}
	new = create_env_node(param, ms);
	if (new == NULL)
		return ;
	ft_envadd_back(env, new);
	add_str = ft_join_env(new->key, new->value);
	if (add_str)
	{
		add_to_dup_env(ms, add_str);
		free(add_str);
	}
}

void	add_env_var(t_ms *ms, t_cmd *cmd, t_env **env)
{
	int	i;

	i = 1;
	while (cmd->cmd_param[i])
	{
		process_single_env_var(ms, cmd->cmd_param[i], env);
		i++;
	}
}

int	ft_export(t_ms *ms)
{
	if (!ms->cmd->cmd_param[1])
		fill_sort_print(ms->env);
	else
		add_env_var(ms, ms->cmd, &ms->env);
	return (1);
}
