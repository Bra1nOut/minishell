/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:25:00 by levincen          #+#    #+#             */
/*   Updated: 2025/11/04 21:25:00 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	append_string_to_result(char *result, int *pos, int max_size, char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] && *pos < max_size - 1)
	{
		result[(*pos)++] = str[i++];
	}
}

void	append_char_to_result(char *result, int *pos, int max_size, char c)
{
	if (*pos < max_size - 1)
		result[(*pos)++] = c;
}

void	handle_status_expansion(t_env_exp *exp, t_ms *ms, int *i)
{
	char	*status_str;

	status_str = ft_itoa(ms->status);
	append_string_to_result(exp->result, &exp->result_pos,
		exp->result_size, status_str);
	free(status_str);
	*i += 2;
}
