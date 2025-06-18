/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:35:47 by jockova           #+#    #+#             */
/*   Updated: 2024/12/13 09:36:15 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*string1;
	char	*string2;
	size_t	i;

	string1 = (char *)s1;
	string2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (string1[i] != string2[i])
			return ((unsigned char)string1[i] - (unsigned char)string2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str1[] = "ABCD";
	char str2[] = "ABC";
	
	printf("%d\n", memcmp(str1, str2, 4));
	printf("%d\n", ft_memcmp(str1, str2, 4));
	return (0);
}
*/