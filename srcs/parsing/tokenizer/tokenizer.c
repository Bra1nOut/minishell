/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 06:22:06 by levincen          #+#    #+#             */
/*   Updated: 2025/11/05 19:39:47 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

bool	syntax_check(t_token *token)
{
	if (!check_first_token(token))
		return (false);
	return (valid_token_str(token));
}

bool	word_check(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == WORD && tmp->value)
		{
		}
		tmp = tmp->next;
	}
	return (true);
}

static t_token_type	get_token_type(char *value)
{
	if (ft_strcmp(value, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(value, "<") == 0)
		return (IN);
	else if (ft_strcmp(value, ">") == 0)
		return (OUT);
	else if (ft_strcmp(value, "<<") == 0)
		return (HEREDOC);
	else if (ft_strcmp(value, ">>") == 0)
		return (APPEND);
	else if (ft_strcmp(value, "||") == 0)
		return (INVALID);
	else
		return (WORD);
}

void	assign_token_type(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (!tmp->value)
		{
			tmp->type = WORD;
			tmp = tmp->next;
			continue ;
		}
		tmp->type = get_token_type(tmp->value);
		tmp = tmp->next;
	}
}
