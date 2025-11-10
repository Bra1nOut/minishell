/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:23:10 by levincen          #+#    #+#             */
/*   Updated: 2025/03/28 16:00:24 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	is_sep(char ch, char *c)
{
	while (*c)
	{
		if (ch == *c)
			return (1);
		c++;
	}
	return (0);
}

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == ' ' || s[i] == '\t'))
			i++;
		if (s[i])
			count++;
		while (s[i] && !(s[i] == c || s[i] == ' ' || s[i] == '\t'))
			i++;
	}
	return (count);
}

static char	**ft_fill(char **new, const char *s, char *c)
{
	size_t	i;
	size_t	copy;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		copy = i;
		while (s[i] && !is_sep(s[i], c))
			i++;
		str = ft_substr(s, copy, i - copy);
		new[count] = str;
		if (ft_strlen(str) == 0)
			free (str);
		count++;
	}
	return (new);
}

char	**ft_split(char const *s, char *c)
{
	char	**new;
	int		count;

	if (!s || !c)
		return (NULL);
	count = ft_count_words(s, *c);
	new = malloc((count + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	new = ft_fill(new, s, c);
	new[count] = NULL;
	return (new);
}
