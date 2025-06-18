/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:29:27 by jockova           #+#    #+#             */
/*   Updated: 2024/11/22 13:48:58 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
/*
size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (dst[i])
        i++;
    j = 0;
    while (src[j] && (i + j + 1 < size))
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0';
    return (i);
}
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;

	i = 0;
	j = 0;
	len_src = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	while (src[len_src])
		len_src++;
	return (i + len_src);
}
/*
// Veronika length 8, Janko length 5, both 13
// dst size should be the length 13 + 1 for null terminator: 14
// VeronikaJanko return 13 (len dst + len src)
// when dst longer than size, nothing from src will append
int	main(void)
{
	char destination1[50] = "Veronika";
	char destination2[50] = "Veronika";
	char source[] = "Janko";
	size_t limit = 7;
	printf("%zu\n", ft_strlcat(destination1, source, limit));
	printf("%zu\n", strlcat(destination2, source, limit));
	printf("%s\n", destination1);
	printf("%s\n", destination2);
	return (0);
}
*/