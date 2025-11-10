/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:14:28 by levincen          #+#    #+#             */
/*   Updated: 2025/11/06 17:06:26 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

t_token	*skip_to_next_cmd(t_token *tmp)
{
	while (tmp && tmp->type != PIPE)
		tmp = tmp->next;
	if (tmp && tmp->type == PIPE)
		tmp = tmp->next;
	return (tmp);
}

void	ft_add_cmd_to_list(t_cmd **first, t_cmd **current, t_cmd *new_cmd)
{
	if (!first || !current || !new_cmd)
		return ;
	if (!*first)
	{
		*first = new_cmd;
		*current = new_cmd;
	}
	else
	{
		(*current)->next = new_cmd;
		*current = new_cmd;
	}
}

t_cmd	*create_multiple_cmd(t_token *token)
{
	t_cmd	*new_cmd;
	t_cmd	*first;
	t_cmd	*current;
	t_token	*tmp;

	if (!token)
		return (NULL);
	new_cmd = NULL;
	first = NULL;
	current = NULL;
	tmp = token;
	while (tmp)
	{
		new_cmd = create_single_cmd(tmp);
		if (!new_cmd)
			break ;
		ft_add_cmd_to_list(&first, &current, new_cmd);
		tmp = skip_to_next_cmd(tmp);
	}
	return (first);
}

static void	process_expansion_char(const char *str, int *i,
				t_env_exp *exp, t_ms *ms)
{
	if (str[*i] == '$' && str[*i + 1] != '\0')
	{
		if (str[*i + 1] == '?')
			handle_status_expansion(exp, ms, i);
		else if (ft_isalnum(str[*i + 1]) || str[*i + 1] == '_')
			get_env_to_result(str, i, exp, ms);
		else
			append_char_to_result(exp->result, &exp->result_pos,
				exp->result_size, str[(*i)++]);
	}
	else
		append_char_to_result(exp->result, &exp->result_pos,
			exp->result_size, str[(*i)++]);
}

char	*ft_expander_to_string(const char *str, t_ms *ms)
{
	t_env_exp	exp;
	int			i;

	if (!str)
		return (NULL);
	exp.result_size = ft_strlen(str) * 1000;
	exp.result = malloc(exp.result_size);
	exp.env_var = malloc(300);
	if (!exp.result || !exp.env_var)
	{
		free(exp.result);
		free(exp.env_var);
		return (ft_strdup(str));
	}
	i = 0;
	exp.result_pos = 0;
	while (str[i] != '\0')
		process_expansion_char(str, &i, &exp, ms);
	exp.result[exp.result_pos] = '\0';
	free(exp.env_var);
	return (exp.result);
}
