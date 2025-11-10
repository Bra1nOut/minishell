/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:16:16 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 20:11:34 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/* ------- TO DO --------
	Dans l'env, il ne faut pas afficher les variables qui
	ont pour valeur "NULL". Par contre si on fait export a=""
	On aura a= dans l'env. En gros faut juste vérifier les
	= dans l'env. Si il y en a pas on affiche pas
*/

int	ft_print_env(t_ms *ms)
{
	t_env	*tmp;

	tmp = ms->env;
	while (tmp)
	{
		if (tmp->key)
		{
			if (tmp->value && ft_strcmp("""", tmp->value))
				printf("%s=%s\n", tmp->key, tmp->value);
		}
		tmp = tmp->next;
	}
	return (1);
}
