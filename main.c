/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:02:38 by jockova           #+#    #+#             */
/*   Updated: 2025/06/18 14:52:21 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int g_sig = 0;

void	ms_init(t_ms *ms, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ms->env_lst = NULL;
	ms->token = NULL;
	ms->cmd = NULL;
	// ms->exit_code = 0;
	// ms->pip[0] = -1;
	// ms->pip[1] = -1;
	// g_signal_pid = 0;
	// signals();
}

int		main(int argc, char **argv, char **envp)
{
	// debug part:
	// printf(RED "Program name, i. e. Argument n1: %s\n" RESET, argv[0]);
	// printf("Length of the program name: \033[0;31m%zu\033[0m\n", ft_strlen(argv[0]));
	// printf("\033[0;31mRed text\033[0m\n");
	// printf("N of arguments: " RED"%d" RESET "\n", argc);
	// printf(RED "The 1st env variable: %s\n" RESET, envp[0]);
	
	t_ms	ms;
	
	ms_init(&ms, argc, argv);
	// ms_print_state(&ms); // debug function printing ms members
	env_lst_make(&ms, envp);
	// printf(RED "env_lst first key: %s\n" RESET, ms.env_lst->key); // debug control prints variables
	// ms_print_envlst(ms); // debug function
	prompt(&ms);

	free_env_lst(ms.env_lst);
	// printf(RED "freed" RESET); // debug control

	return (0);
}
