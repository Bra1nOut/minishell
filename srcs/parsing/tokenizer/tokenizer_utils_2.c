/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:08:07 by ml-hote           #+#    #+#             */
/*   Updated: 2025/11/06 17:00:13 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	add_token_to_list(t_token **current, char *word)
{
	add_token_to_list_with_quote_type(current, word, 0);
}

void	print_tokens(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		printf("Value: '%s', Type: %d\n", tmp->value, tmp->type);
		tmp = tmp->next;
	}
}
