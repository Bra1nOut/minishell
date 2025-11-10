/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:24:04 by levincen          #+#    #+#             */
/*   Updated: 2024/12/30 13:23:30 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

int	ftt_strchr(const char *str, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == uc)
			return (1);
		i++;
	}
	if (str[i] == uc)
		return (1);
	return (0);
}

char	*search_copy(char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	str = malloc((sizeof(char)) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*rm_start(char *buffer, const char *line)
{
	int		i;
	int		j;
	size_t	buffer_len;
	size_t	line_len;
	char	*cutted_str;

	if (!buffer || !line)
		return (NULL);
	buffer_len = ft_strlen(buffer);
	line_len = ft_strlen(line);
	if (buffer_len <= line_len)
	{
		free(buffer);
		return (NULL);
	}
	cutted_str = malloc(sizeof(char) * (buffer_len - line_len + 1));
	if (!cutted_str)
		return (NULL);
	i = 0;
	j = line_len;
	while (buffer[j])
		cutted_str[i++] = buffer[j++];
	cutted_str[i] = '\0';
	free(buffer);
	return (cutted_str);
}

char	*ftt_strjoin(char *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			new[i++] = s1[j++];
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
			new[i++] = s2[j++];
	}
	new[i] = '\0';
	free(s1);
	return (new);
}
