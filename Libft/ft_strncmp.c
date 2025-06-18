/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:03:54 by jockova           #+#    #+#             */
/*   Updated: 2024/11/22 13:24:37 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	int			dif;

	dif = 0;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n && dif == 0)
	{
		dif = s1[i] - s2[i];
		i++;
	}
	return (dif);
}
/*
int	main(void)
{
	char string1[] = "AB";
	char string2[] = "BCDE";
	unsigned int limit = 3;
	printf("%d\n", ft_strncmp(string1, string2, limit));
	printf("%d\n", strncmp(string1, string2, limit));
	return (0);
}
*/