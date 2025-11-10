/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:53:08 by levincen          #+#    #+#             */
/*   Updated: 2025/11/06 18:20:37 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_pid(int **pipes)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (pipes[i])
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	free_cmd(t_cmd **list)
{
	t_cmd	*tmp;
	t_cmd	*next;

	if (!list || !*list)
		return ;
	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->cmd_param)
			free_array(tmp->cmd_param);
		if (tmp->path)
			free(tmp->path);
		if (tmp->infile > 2)
			close(tmp->infile);
		if (tmp->outfile > 2)
			close(tmp->outfile);
		free(tmp);
		tmp = next;
	}
	*list = NULL;
}

void	little_free(t_ms *ms, t_cmd *cmd)
{
	if (cmd)
	{
		free_cmd(&cmd);
		ms->cmd = NULL;
	}
	if (ms->token)
	{
		free_token(ms->token);
		ms->token = NULL;
	}
}

void	free_all(t_ms *ms)
{
	if (!ms)
		return ;
	if (ms->token)
		free_token(ms->token);
	if (ms->cmd)
		free_cmd_exit(ms->cmd);
	if (ms->env)
		free_env(ms->env);
	if (ms->dup_env)
		free_array(ms->dup_env);
}
