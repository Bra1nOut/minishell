/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:45:58 by jockova           #+#    #+#             */
/*   Updated: 2024/12/16 20:29:50 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	ft_length(int nb)
{
	int	s;

	if (nb == 0)
		return (1);
	s = 0;
	if (nb < 0)
		s = 1;
	while (nb)
	{
		s++;
		nb = nb / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = ft_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	str[len] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (num)
	{
		str[len] = ('0' + (num % 10));
		num = num / 10;
		len--;
	}
	return (str);
}

/* int		main(void)
{
	printf("%s\n", ft_itoa(+2798));
	printf("%s\n", ft_itoa(-2798));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(+-2798));
	printf("%s\n", ft_itoa(-+2798));
	printf("%s\n", ft_itoa('t'));
	printf("%s\n", ft_itoa(2798));
	printf("%s\n", ft_itoa(0000));
	printf("%s\n", ft_itoa(8));
	printf("%s\n", ft_itoa(999999));
	return (0);
} */