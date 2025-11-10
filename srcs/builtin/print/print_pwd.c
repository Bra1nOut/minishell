/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:16:30 by levincen          #+#    #+#             */
/*   Updated: 2025/10/30 17:39:36 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_print_pwd(t_ms *ms)
{
	t_env	*tmp;

	if (!ms || !ms->env)
		return (1);
	tmp = ms->env;
	while (tmp)
	{
		if (tmp->key && ft_strcmp(tmp->key, "PWD") == 0)
		{
			if (tmp->value)
				printf("%s\n", tmp->value);
			else
				printf("minishell: PWD not set\n");
			return (1);
		}
		tmp = tmp->next;
	}
	printf("minishell: PWD not set\n");
	return (1);
}
