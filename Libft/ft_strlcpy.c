/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:19:10 by jockova           #+#    #+#             */
/*   Updated: 2024/11/22 13:17:18 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = 0;
	if (size == 0)
	{
		while (src[len_src])
			len_src++;
		return (len_src);
	}
	while (src[len_src] != '\0' && len_src < size - 1)
	{
		dst[len_src] = src[len_src];
		len_src++;
	}
	if (len_src < size)
		dst[len_src] = '\0';
	while (src[len_src] != '\0')
		len_src++;
	return (len_src);
}
/*
int	main(void)
{
	char destination1[10];
	char destination2[10];
	printf("%zu\n", ft_strlcpy(destination1, "World!", 10));
	printf("%zu\n", strlcpy(destination2, "World!", 10));
	printf("%s\n", destination1);
	printf("%s\n", destination2);
	return (0);
}
strlcpy, copy src characters from src until size-1 into dst
null terminating dst
return the length of the string that is tried to be created.  
that means the length of src
*/