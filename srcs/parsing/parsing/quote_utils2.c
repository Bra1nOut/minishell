/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:02:36 by ml-hote           #+#    #+#             */
/*   Updated: 2025/11/07 15:26:09 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static void	update_quote_state(char c, t_quote_state *quote_state)
{
	if (*quote_state == NO_QUOTE)
	{
		if (c == '\'')
			*quote_state = SINGLE_QUOTE;
		else if (c == '"')
			*quote_state = DOUBLE_QUOTE;
	}
	else if (*quote_state == SINGLE_QUOTE && c == '\'')
		*quote_state = NO_QUOTE;
	else if (*quote_state == DOUBLE_QUOTE && c == '"')
		*quote_state = NO_QUOTE;
}

static void	process_dollar_expansion(const char *str, int *i, t_env_exp *exp,
				t_ms *ms)
{
	if (str[*i + 1] == '?')
		handle_status_expansion(exp, ms, i);
	else if (ft_isalnum(str[*i + 1]) || str[*i + 1] == '_')
		get_env_to_result(str, i, exp, ms);
	else
		append_char_to_result(exp->result, &exp->result_pos,
			exp->result_size, str[(*i)++]);
}

static int	init_and_validate_expander(t_env_exp *exp, const char *str)
{
	init_expander_data(exp, str);
	if (!exp->result || !exp->env_var)
	{
		free(exp->result);
		free(exp->env_var);
		return (0);
	}
	return (1);
}

static void	process_character(const char *str, int *i, t_process_data *data)
{
	update_quote_state(str[*i], data->quote_state);
	if (str[*i] == '$' && str[*i + 1] != '\0'
		&& *data->quote_state != SINGLE_QUOTE)
		process_dollar_expansion(str, i, data->exp, data->ms);
	else
		append_char_to_result(data->exp->result, &data->exp->result_pos,
			data->exp->result_size, str[(*i)++]);
}

char	*ft_exp_to_str_w_quotes(const char *str, t_ms *ms)
{
	t_env_exp		exp;
	t_quote_state	quote_state;
	t_process_data	data;
	int				i;

	if (!str)
		return (NULL);
	if (!init_and_validate_expander(&exp, str))
		return (ft_strdup(str));
	i = 0;
	quote_state = NO_QUOTE;
	data = (t_process_data){&exp, ms, &quote_state};
	while (str[i] != '\0')
		process_character(str, &i, &data);
	exp.result[exp.result_pos] = '\0';
	free(exp.env_var);
	return (exp.result);
}
