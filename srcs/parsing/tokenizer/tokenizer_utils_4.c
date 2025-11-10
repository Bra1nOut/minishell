/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:25:00 by levincen          #+#    #+#             */
/*   Updated: 2025/11/06 16:35:58 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	rm_first_token(t_token **lst_tok)
{
	t_token	*tmp;

	if (!lst_tok || !*lst_tok)
		return ;
	tmp = *lst_tok;
	*lst_tok = (*lst_tok)->next;
	if (tmp)
	{
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}
