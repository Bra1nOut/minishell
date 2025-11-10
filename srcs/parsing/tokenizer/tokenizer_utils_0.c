/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:54:54 by levincen          #+#    #+#             */
/*   Updated: 2025/10/30 17:21:40 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

bool	token_is_opperator(t_token *token)
{
	return (token->type == PIPE || token->type == IN || token->type == OUT
		|| token->type == APPEND || token->type == HEREDOC
		|| token->type == INVALID);
}

bool	check_first_token(t_token *token)
{
	if (!token)
		return (false);
	if (token_is_opperator(token))
	{
		ft_print_error_token(token);
		return (false);
	}
	return (true);
}

bool	check_token_str(t_token *tmp)
{
	if (!tmp->next)
	{
		ft_print_error_token(tmp);
		return (false);
	}
	if (tmp->next && tmp->next->type != WORD)
	{
		ft_print_error_token(tmp->next);
		return (false);
	}
	return (true);
}

bool	valid_token_str(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (token_is_opperator(tmp))
		{
			if (!check_token_str(tmp))
				return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}
