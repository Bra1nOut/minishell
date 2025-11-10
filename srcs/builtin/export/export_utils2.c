/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:03:00 by levincen          #+#    #+#             */
/*   Updated: 2025/10/30 17:36:38 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	fill_export(t_env	*env, t_env	**array)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 0;
	while (tmp)
	{
		array[i] = tmp;
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
}

void	sort_export(t_env **array)
{
	int		i;
	int		swapped;
	t_env	*tmp;

	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (array[i] && array[i + 1])
		{
			if (ft_strcmp(array[i]->key, array[i + 1]->key) > 0)
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	ft_print_export(t_env **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(array[i]->key, STDOUT_FILENO);
		if (array[i]->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(array[i]->value, STDOUT_FILENO);
			ft_putstr_fd("\"\n", STDOUT_FILENO);
		}
		else
			ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
}

t_env	*ft_envlast(t_env *env)
{
	while (env)
	{
		if (!env->next)
			return (env);
		env = env->next;
	}
	return (env);
}

void	ft_envadd_back(t_env **env, t_env *new)
{
	t_env	*last;

	if (*env)
	{
		last = ft_envlast(*env);
		last->next = new;
	}
	else
		*env = new;
}
