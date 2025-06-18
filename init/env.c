/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:48:43 by jockova           #+#    #+#             */
/*   Updated: 2025/06/17 13:33:24 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cpy_left(char *env_var)
{
	int	i;
	char *key;
	
	i = 0;
	while(env_var[i] != '=') // key=value
		i++; // length for malloc:  012=45678 i=3 pointing to '='
	key = malloc(sizeof(char) * (i + 1));
	if (!key)
		exit (1); //stops the whole program
	i = 0;
	while(env_var[i] != '=')
	{
		key[i] = env_var[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*cpy_right(char *env_var)
{
	int i;
	int j;
	char *value;

	i = 0;
	while(env_var[i] != '=') // key=value, lenght of value = 5
		i++; // lenght for malloc: 012=45678 i=3 pointing to '='
	j = ++i; // augment i to 4 and assign 4 to j
	while(env_var[i])
		i++; // i = 9 pointing to 'end', malloc = j - i = 9 - 4 = 5
	value = malloc(sizeof(char) * (i - j) + 1);
	if (!value)
		exit (1);
	i = 0;
	while (env_var[j])
	{
		value[i] = env_var[j]; // j starts at 4 at 'v'
		i++;
		j++;
	}
	value[i] = '\0';
	return (value);
}

t_envlst	*env_lst_new(char *env_var)
{
	t_envlst	*env;
	static int	i = 0;
	env = malloc(sizeof(*env));
	env->index = i + 1;
	env->key = cpy_left(env_var);
	env->value = cpy_right(env_var);
	env->next = NULL;
	i++;
	return (env);
}

void	ft_lst_add_back(t_envlst **lst, t_envlst *new)
{
	t_envlst	*last;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void	env_lst_make(t_ms *ms, char **envp)
{
	t_envlst	*env;
	int			i;
	char		*cwd;
	
	i = 0;
	while(envp[i])
	{
		env = env_lst_new(envp[i]);
		if(!env)
			return ;
		ft_lst_add_back(&ms->env_lst, env);
		i++;
	}
	
	if(!ms->env_lst) // make minimal environment if no environment variables found
	{
		cwd = getcwd(NULL, 0); // needed: if(!cwd) return ;
		env = malloc(sizeof(t_envlst)); // needed: if (!env) return ; will ever the program comes here, really?
		env->index = ++i;
		env->key = ft_strdup("PWD");
		env->value = ft_strdup(cwd);
		free(cwd);
		env->next = NULL;
		ft_lst_add_back(&ms->env_lst, env);
	}
}
