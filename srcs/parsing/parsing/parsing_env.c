/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:30:43 by ml-hote           #+#    #+#             */
/*   Updated: 2025/11/05 20:10:11 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*  ft_expander(const char *str)
	This function gets through a string and prints the env vars it finds.
	Maybe I'll add a return value with a chained list so that we can have
	all of the vars in a row ?
*/

int	ft_check_and_get_env(const char *str, int *i, char *env_var)
{
	char	*value;
	int		i_ev;

	(*i)++;
	i_ev = 0;
	if (!ft_isalnum(str[*i]) && str[*i] != '_')
	{
		(*i)--;
		return (0);
	}
	while (str[*i] != '\0' && (ft_isalnum(str[*i]) || str[*i] == '_'))
	{
		env_var[i_ev++] = str[(*i)++];
	}
	env_var[i_ev] = '\0';
	value = getenv((const char *)env_var);
	if (value)
	{
		printf("%s", value);
		return (1);
	}
	return (0);
}

static void	handle_dollar_expansion(const char *str, int *i,
				char *env_var, t_ms *ms)
{
	char	*status_str;

	if (str[*i + 1] == '?')
	{
		status_str = ft_itoa(ms->status);
		write(1, status_str, ft_strlen(status_str));
		free(status_str);
		*i += 2;
	}
	else if (ft_isalnum(str[*i + 1]) || str[*i + 1] == '_')
		ft_check_and_get_env(str, i, env_var);
	else
	{
		write(1, &str[*i], 1);
		(*i)++;
	}
}

int	ft_expander(const char *str, t_ms *ms)
{
	char	*env_var;
	int		i;

	env_var = (char *)malloc(sizeof(char) * 300);
	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] != '\0')
			handle_dollar_expansion(str, &i, env_var, ms);
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	free(env_var);
	return (0);
}

// Ajouter après ft_expander
static char	*get_env_value_from_ms(t_ms *ms, char *key)
{
	t_env	*env_node;
	char	*system_value;

	env_node = ft_find_env(ms->env, key);
	if (env_node && env_node->value)
		return (env_node->value);
	system_value = getenv(key);
	if (system_value)
		return (system_value);
	return (NULL);
}

int	get_env_to_result(const char *str, int *i, t_env_exp *exp, t_ms *ms)
{
	char	*value;
	int		i_ev;

	(*i)++;
	i_ev = 0;
	if (!ft_isalnum(str[*i]) && str[*i] != '_')
	{
		(*i)--;
		return (0);
	}
	while (str[*i] != '\0' && (ft_isalnum(str[*i]) || str[*i] == '_'))
	{
		exp->env_var[i_ev++] = str[(*i)++];
	}
	exp->env_var[i_ev] = '\0';
	value = get_env_value_from_ms(ms, exp->env_var);
	if (value)
	{
		append_string_to_result(exp->result, &exp->result_pos,
			exp->result_size, value);
		return (1);
	}
	return (0);
}
