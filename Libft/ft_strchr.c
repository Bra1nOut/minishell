/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:55:24 by jockova           #+#    #+#             */
/*   Updated: 2024/12/10 10:02:49 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

/*
// move pointer s in search for a character c
// find the first character occurence in the string pointer
// and cast pointer to that character index (char *)s
// return this casted pointer
// if not found, return NULL
int main(void)
{
	char name[] = "Find the 1st occurence of '1'";
	int ch = '1';
	printf("%s\n", ft_strchr(name, ch));
	printf("%s\n", strchr(name, ch));
	return (0);
}
*/
