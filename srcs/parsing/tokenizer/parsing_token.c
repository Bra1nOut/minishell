/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:58:29 by ml-hote           #+#    #+#             */
/*   Updated: 2025/11/07 15:26:09 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*	ft_lst_prompt
	this function will separate all of the words and | < << > >> into a
	chained list. Then we will start tokenizing it.
	It gets through all of the char of the prompt and when it finds something
	that isn't a whitespace it will check if it as any " or ' in it then add
	the len of the word to the index so that it jumps straight to looking at
	others words.
	Each word are added to the chained list that will be returned
*/

void	expand_all_tokens(t_token *tokens, t_ms *ms)
{
	t_token	*current;
	char	*expanded_value;

	current = tokens;
	while (current)
	{
		if (current->value && ft_strchr(current->value, '$')
			&& current->quote_type != 1)
		{
			expanded_value = ft_exp_to_str_w_quotes(current->value, ms);
			if (expanded_value)
			{
				free(current->value);
				current->value = expanded_value;
			}
		}
		current = current->next;
	}
}

t_token	*ft_newtoken(char *value)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	if (value)
		new->value = ft_strdup(value);
	else
		new->value = NULL;
	if (value && !new->value)
	{
		free(new);
		return (NULL);
	}
	new->type = 0;
	new->quote_type = 0;
	new->next = NULL;
	return (new);
}

t_token	*ft_lst_prompt(const char *prompt, t_ms *ms)
{
	t_token	*lst_tok;
	t_token	*current;
	int		i;

	lst_tok = ft_newtoklst();
	current = lst_tok;
	i = 0;
	while (prompt[i] != '\0')
	{
		while (ft_iswhitespace(prompt[i]) && prompt[i] != '\0')
			i++;
		if (prompt[i] == '\0')
			break ;
		if (prompt[i] == '"' || prompt[i] == '\'')
			process_word_token(prompt, &current, &i);
		else if (prompt[i] == '|')
			process_pipe_token(&current, &i);
		else if (prompt[i] == '<' || prompt[i] == '>')
			process_redirect_token(prompt, &current, &i);
		else
			process_word_token(prompt, &current, &i);
	}
	rm_first_token(&lst_tok);
	expand_all_tokens(lst_tok, ms);
	return (lst_tok);
}
