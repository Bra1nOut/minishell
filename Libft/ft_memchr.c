/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:18:06 by jockova           #+#    #+#             */
/*   Updated: 2024/12/13 08:59:09 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	size_t	i;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)string[i] == (unsigned char)c)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
    char string1[12] = "Hello World";
    char character = 'o';

    printf("%s\n", (char *)ft_memchr(string1, character, 5));
	return (0);
}
*/