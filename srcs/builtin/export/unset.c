/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:47:20 by levincen          #+#    #+#             */
/*   Updated: 2025/10/30 17:38:39 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	unset_key(t_ms *ms, char *key)
{
	t_env	*prev;
	t_env	*current;

	prev = NULL;
	current = ms->env;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				ms->env = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	ft_unset(t_ms *ms, t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd->cmd_param[i])
	{
		if (ft_isalpha(cmd->cmd_param[i][0]) || cmd->cmd_param[i][0] == '_')
			unset_key(ms, cmd->cmd_param[i]);
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmd->cmd_param[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			ms->status = 1;
		}
		i++;
	}
	ms->status = 0;
	return (1);
}
