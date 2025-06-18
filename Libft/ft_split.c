/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:53:16 by jockova           #+#    #+#             */
/*   Updated: 2025/02/04 12:46:35 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_split function:
** The function takes a pointer to a string as input,
** splits the string at a specified character
** and allocates a memory block with malloc
** and returns the new strings ending with a null byte.
** Logic:
** 1) we need to use two extra functions to respect the limit of n of
**    lines, but these functions need to be declared as
**    static so that the rest of the library cannot see them
** 2) we have an error check so that if we are passed nothing
**    the function returns 0
** 3) we need to count the amount of words, so we pass the input
**    to one of our extra functions that increments in a loop
**    using the specified splitting character to count the words
**    and the result returned here will tell us how many
**    strings we need to split the input into and thus how much
**    memory we need to allocate with malloc
** 4) we allocate memory for the variable length + 1 for the null byte
** 5) we have a safeguard so if memory allocation fails
**    the function returns null
** 6) we create a loop to split the words, assign a null byte at the end
**    and repeat for words number of times, using our second function
**    length to find the length of each individual split and allocate
**    memory accordingly to that size plus one for the null byte
** 7) we reset our index so that we can return to the start of our string
** to test: uncomment main
** run gcc -Wall -Wextra -Werror
** ft_strsplit.c ft_strncpy.c ft_strcmp.c
*/

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_wordcount(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		word_len;
	int		i;

	strings = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!s || !strings)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			strings[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	strings[i] = NULL;
	return (strings);
}
/* 
int main()
{
    char **result = ft_split("Hello world  split example", ' ');

    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("%s\n", result[i]);
            free(result[i]);  // free each string
        }
        free(result);  // Free the array of strings
    }

    return 0;
} */
