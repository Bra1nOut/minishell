/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:00:27 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 18:33:50 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

bool	ft_print_error(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	return (true);
}

bool	ft_print_error_token(t_token *token)
{
	if (token->value && !ft_strcmp(token->value, "||"))
		ft_putstr_fd(
			"minishell : syntax errornear unexpected token `||'\n", 2);
	else if (token->value && !ft_strcmp(token->value, "|"))
		ft_putstr_fd(
			"minishell : syntax error near unexpected token `|'\n", 2);
	else if (token->value && ft_strcmp(token->value, "<>"))
		ft_putstr_fd(
			"minishell : syntax error near unexpected token `newline'\n", 2);
	else if (token->next == NULL)
		ft_putstr_fd(
			"minishell : syntax error near unexpected token `newline'\n", 2);
	else
	{
		ft_putstr_fd(
			"minishell : syntax error near unexpected token `", 2);
		ft_putstr_fd(token->value, 2);
	}
	return (false);
}
