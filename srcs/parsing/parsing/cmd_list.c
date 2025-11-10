/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 03:25:19 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 13:21:14 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_cmd	*cmd_new(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->infile = -2;
	new->outfile = -2;
	new->append = false;
	new->cmd_param = NULL;
	new->path = NULL;
	new->next = NULL;
	return (new);
}

void	ft_cmdadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static int	count_word_tokens(t_token *token)
{
	t_token	*tmp;
	int		count;

	tmp = token;
	count = 0;
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == WORD)
		{
			count++;
			tmp = tmp->next;
		}
		else if (tmp->type == APPEND || tmp->type == IN || tmp->type == OUT
			|| tmp->type == HEREDOC)
		{
			tmp = tmp->next;
			if (tmp && tmp->type == WORD)
				tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (count);
}

static void	fill_cmd_params(t_cmd *cmd, t_token *token)
{
	int	i;

	i = 0;
	while (token && token->type != PIPE)
	{
		if (token->type == WORD)
		{
			if (token->value && token->value[0] != '\0')
			{
				cmd->cmd_param[i] = ft_strdup(token->value);
				i++;
			}
			token = token->next;
		}
		else if (token->type == APPEND || token->type == IN
			|| token->type == OUT || token->type == HEREDOC)
		{
			token = token->next;
			if (token && token->type == WORD)
				token = token->next;
		}
		else
			token = token->next;
	}
	cmd->cmd_param[i] = NULL;
}

t_cmd	*create_single_cmd(t_token *token)
{
	t_cmd	*cmd;
	int		count;

	cmd = cmd_new();
	count = count_word_tokens(token);
	cmd->cmd_param = malloc(sizeof(char *) * (count + 1));
	if (!cmd->cmd_param)
	{
		free(cmd);
		return (NULL);
	}
	fill_cmd_params(cmd, token);
	return (cmd);
}
