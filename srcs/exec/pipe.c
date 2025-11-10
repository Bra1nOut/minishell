/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:13:18 by levincen          #+#    #+#             */
/*   Updated: 2025/11/04 18:30:15 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* --------- TO DO -----------
	Au niveau des pipes verifier que tous les pipes soient executes
	Parce que cat | cat | ls fait seulement un retour de ligne

	Si on fait une commande qui n'existe pas dans un pipe
	ex : > cmdexistepas | ls
	Ca affiche le mauvais message d'erreur au lieu d'un command
	not found précédé par le retour de ls
*/

int	ft_count_cmd(t_token *token)
{
	t_token	*tmp;
	int		count;

	count = 1;
	tmp = token;
	while (tmp)
	{
		if (tmp->type == PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

bool	pipes_checker(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == PIPE)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

int	**create_pipes(int nb_pipes)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * nb_pipes);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < nb_pipes)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
		{
			while (i-- >= 0)
				free(pipes[i]);
			free(pipes);
			return (NULL);
		}
		if (pipe(pipes[i]) == -1)
		{
			perror("pipe");
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	setup_pipes(int **pipes, int cmd_index, int cmd_count)
{
	if (cmd_index == 0)
		dup2(pipes[0][1], STDOUT_FILENO);
	else if (cmd_index == cmd_count - 1)
		dup2(pipes[cmd_index - 1][0], STDIN_FILENO);
	else
	{
		dup2(pipes[cmd_index - 1][0], STDIN_FILENO);
		dup2(pipes[cmd_index][1], STDOUT_FILENO);
	}
}

void	close_pipes(int **pipes, int nb_pipes)
{
	int	i;

	i = 0;
	while (i < nb_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}
