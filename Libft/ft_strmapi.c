/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:12:38 by jockova           #+#    #+#             */
/*   Updated: 2024/12/17 12:37:11 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
the function doesn't modify the original string
but allocates a memory block to store
a new null terminated string.
*/

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	if (!s || !f)
		return (NULL);
	i = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newstr)
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/* 
char example_func(unsigned int i, char c)
{
    // Convert the character to uppercase at an even index
    if (i % 2 == 0)
        return (char)(c - 'a' + 'A');  // Uppercase conversion for even indices
    else
        return c;  // Leave odd indices unchanged
}

int main(void)
{
    // Example string
    char *s = "abcdefg";

    // Apply the transformation function
    char *result = ft_strmapi(s, example_func);

    if (result)
    {
        // Print the result
        printf("Original string: %s\n", s);
        printf("Transformed string: %s\n", result);

        // Free the allocated memory
        free(result);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return 0;
} */
