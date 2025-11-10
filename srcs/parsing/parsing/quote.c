/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:37:30 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 14:46:37 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/* Get the length of a word, handling quotes properly */
static int	handle_quote_state(const char *prompt,
				int i, t_quote_state *quote_state)
{
	if (*quote_state == NO_QUOTE)
	{
		if (prompt[i] == '\'')
			*quote_state = SINGLE_QUOTE;
		else if (prompt[i] == '"')
			*quote_state = DOUBLE_QUOTE;
		else if (ft_iswhitespace(prompt[i]) || prompt[i] == '|'
			|| prompt[i] == '<' || prompt[i] == '>')
			return (1);
	}
	else if (*quote_state == SINGLE_QUOTE && prompt[i] == '\'')
	{
		*quote_state = NO_QUOTE;
		return (2);
	}
	else if (*quote_state == DOUBLE_QUOTE && prompt[i] == '"')
	{
		*quote_state = NO_QUOTE;
		return (2);
	}
	return (0);
}

int	get_word_length(const char *prompt, int start)
{
	t_quote_state	quote_state;
	int				i;
	int				result;

	quote_state = NO_QUOTE;
	i = start;
	while (prompt[i])
	{
		result = handle_quote_state(prompt, i, &quote_state);
		if (result == 1 && quote_state == NO_QUOTE)
			break ;
		if (result == 2)
			i++;
		else
			i++;
	}
	return (i - start);
}

/* Check if quotes are properly closed in a string segment */
bool	is_quote_closed(const char *str, int start, int end)
{
	t_quote_state	quote_state;
	int				i;

	quote_state = NO_QUOTE;
	i = start;
	while (i < end)
	{
		if (quote_state == NO_QUOTE)
		{
			if (str[i] == '\'')
				quote_state = SINGLE_QUOTE;
			else if (str[i] == '"')
				quote_state = DOUBLE_QUOTE;
		}
		else if (quote_state == SINGLE_QUOTE && str[i] == '\'')
			quote_state = NO_QUOTE;
		else if (quote_state == DOUBLE_QUOTE && str[i] == '"')
			quote_state = NO_QUOTE;
		i++;
	}
	return (quote_state == NO_QUOTE);
}

/* Extract content from quotes, removing quote characters */
char	*extract_quoted_content(const char *str, int start, int len)
{
	char			*result;
	t_quote_state	quote_state;
	t_quote_data	data;
	int				i;
	int				j;

	if (!is_quote_closed(str, start, start + len))
		return (NULL);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	quote_state = NO_QUOTE;
	j = 0;
	data = (t_quote_data){result, &quote_state, &j};
	i = start;
	while (i < start + len)
	{
		process_quote_type(str, i, &data);
		i++;
	}
	result[j] = '\0';
	return (result);
}

/* Validate that all quotes are properly closed in the input */
bool	validate_quotes(const char *input)
{
	t_quote_state	quote_state;
	int				i;

	if (!input)
		return (false);
	quote_state = NO_QUOTE;
	i = 0;
	while (input[i])
	{
		if (quote_state == NO_QUOTE)
		{
			if (input[i] == '\'')
				quote_state = SINGLE_QUOTE;
			else if (input[i] == '"')
				quote_state = DOUBLE_QUOTE;
		}
		else if (quote_state == SINGLE_QUOTE && input[i] == '\'')
			quote_state = NO_QUOTE;
		else if (quote_state == DOUBLE_QUOTE && input[i] == '"')
			quote_state = NO_QUOTE;
		i++;
	}
	return (quote_state == NO_QUOTE);
}
