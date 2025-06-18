/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:14:45 by jockova           #+#    #+#             */
/*   Updated: 2024/12/17 13:44:53 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** Applies the function ’f’ on each character 
** of the string passed as argument, 
** passing its index as first argument.
** Function modifies the characters in the string directly.
** Each character is passed by address 
** to ’f’ to be modified if necessary. 
*/

#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}
/* 
// Example function that modifies the string characters to uppercase
// at even indices
void example_func(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = *c - 'a' + 'A'; 
}

int main(void)
{
    // Test string - mutable, so use a non-const char array
    char s[] = "abcdefg";

    ft_striteri(s, example_func);
    printf("Modified string: %s\n", s);
    return 0;
} 
*/