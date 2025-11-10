/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:32:28 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 15:18:33 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	add_token_to_list_with_quote_type(t_token **current,
			char *word, int quote_type)
{
	(*current)->next = ft_newtoken(word);
	*current = (*current)->next;
	(*current)->quote_type = quote_type;
	free(word);
}

void	process_pipe_token(t_token **current, int *i)
{
	char	*word;

	word = ft_strdup("|");
	add_token_to_list(current, word);
	(*i)++;
}

void	process_redirect_token(const char *prompt, t_token **current, int *i)
{
	char	*word;
	int		start;

	start = *i;
	if (prompt[*i + 1] == prompt[*i])
		*i += 2;
	else
		(*i)++;
	word = ft_substr(prompt, start, *i - start);
	add_token_to_list(current, word);
}

int	detect_quote_type(const char *prompt, int start)
{
	if (prompt[start] == '\'')
		return (1);
	else if (prompt[start] == '"')
		return (2);
	else
		return (0);
}

void	process_word_token(const char *prompt, t_token **current, int *i)
{
	char	*word;
	int		start;
	int		word_len;
	int		quote_type;

	start = *i;
	quote_type = detect_quote_type(prompt, start);
	word_len = get_word_length(prompt, start);
	if (word_len > 0)
	{
		word = extract_quoted_content(prompt, start, word_len);
		if (word)
		{
			add_token_to_list_with_quote_type(current, word, quote_type);
			*i = start + word_len;
		}
		else
			(*i)++;
	}
	else
		(*i)++;
}
