/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:02:24 by jockova           #+#    #+#             */
/*   Updated: 2024/12/16 18:42:44 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	strtrim = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!strtrim)
		return (NULL);
	ft_strlcpy(strtrim, &s1[i], j - i + 1);
	return (strtrim);
}

/* int	main(void)
{
	printf("%s\n", ft_strtrim("   xxxtripouille   xxx", " x"));
	return (0);
} */