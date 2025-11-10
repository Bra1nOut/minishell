/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:01:11 by levincen          #+#    #+#             */
/*   Updated: 2025/11/07 18:05:49 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/parsing/parsing.h"

int	g_signal = 0;

int	main(int argc, char **argv, char **envp)
{
	t_ms	*minishell;

	minishell = NULL;
	(void) argv;
	if (argc == 1)
	{
		minishell = ft_init_ms(minishell, envp);
		ft_prompt(minishell);
		rl_clear_history();
	}
	return (0);
}
