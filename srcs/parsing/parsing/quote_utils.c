/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:29:34 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 14:46:12 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	handle_no_quote(const char *str, int i, t_quote_data *data)
{
	if (str[i] == '\'')
		*data->quote_state = SINGLE_QUOTE;
	else if (str[i] == '"')
		*data->quote_state = DOUBLE_QUOTE;
	else
		data->result[(*data->j)++] = str[i];
}

void	handle_single_quote(const char *str, int i, t_quote_data *data)
{
	if (str[i] == '\'')
		*data->quote_state = NO_QUOTE;
	else
		data->result[(*data->j)++] = str[i];
}

void	handle_double_quote(const char *str, int i, t_quote_data *data)
{
	if (str[i] == '"')
		*data->quote_state = NO_QUOTE;
	else
		data->result[(*data->j)++] = str[i];
}

void	process_quote_type(const char *str, int i, t_quote_data *data)
{
	if (*data->quote_state == NO_QUOTE)
		handle_no_quote(str, i, data);
	else if (*data->quote_state == SINGLE_QUOTE)
		handle_single_quote(str, i, data);
	else if (*data->quote_state == DOUBLE_QUOTE)
		handle_double_quote(str, i, data);
}

/* Main quote handling function */
char	*handle_quotes(const char *str)
{
	if (!str)
		return (NULL);
	return (extract_quoted_content(str, 0, ft_strlen(str)));
}
