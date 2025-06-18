/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:26:16 by jockova           #+#    #+#             */
/*   Updated: 2024/12/12 09:29:33 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *s)
{
	int		i;
	size_t	lenght;
	char	*new_s;

	i = 0;
	lenght = 0;
	while (s[lenght] != '\0')
		lenght++;
	new_s = (char *)malloc(lenght + 1);
	if (!new_s)
		return (NULL);
	while (s[i] != '\0')
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
/*
int	main(void)
{
	char	original[] = "Using malloc() to allocate memory.";
	char	*duplicate;
	char	*duplicate_lib;

	duplicate = ft_strdup(original);
	printf("%s\n", duplicate);
	free(duplicate);
	duplicate_lib = strdup(original);
	printf("%s\n", duplicate_lib);
	free(duplicate_lib);

	return 0;
}
*/