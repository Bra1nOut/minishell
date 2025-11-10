/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:53:48 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 19:47:03 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		if (env)
			free(env);
		env = tmp;
	}
}

void	free_token(t_token *tok)
{
	t_token	*tmp;

	while (tok)
	{
		tmp = tok->next;
		free(tok->value);
		free(tok);
		tok = tmp;
	}
	tok = NULL;
}

void	free_cmd_exit(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->cmd_param)
		{
			i = 0;
			while (cmd->cmd_param[i])
				free(cmd->cmd_param[i++]);
			free(cmd->cmd_param);
		}
		free(cmd->path);
		free(cmd);
		cmd = tmp;
	}
}

void	exit_clean(t_ms *ms)
{
	if (!ms)
		return ;
	free_token(ms->token);
	if (ms->cmd)
		free_cmd_exit(ms->cmd);
	if (ms->env)
		free_env(ms->env);
	if (ms->dup_env)
		free_array(ms->dup_env);
	free(ms);
}
