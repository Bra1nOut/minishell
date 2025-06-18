/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jockova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:09:21 by jockova           #+#    #+#             */
/*   Updated: 2025/06/16 11:48:20 by jockova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
while: find the first newline or the end of the buffer
if (buffer[i] == '\n'): include the newline character if it exists
ft_strlcpy: Copy up to i characters
*/
char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && (buffer[i] != '\n'))
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 1);
	return (line);
}

/*
while: Find the first newline or end of the buffer
if (buffer[i] == '\n'): skip the newline character
if (buffer[i] == '\0'): if no more content, free the buffer
free(buffer): Free the old buffer
ft_strlcpy: copy the remaining buffer
*/
char	*get_rest(char *buffer)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	rest = malloc((ft_strlen(buffer + i) + 1) * sizeof(char));
	if (!rest)
		return (free(buffer), NULL);
	ft_strlcpy(rest, buffer + i, ft_strlen(buffer + i) + 1);
	free(buffer);
	return (rest);
}

char	*append_buffer(char *buffer, char *read_buffer)
{
	char	*temporary;

	temporary = ft_strjoin(buffer, read_buffer);
	free(buffer);
	return (temporary);
}

static char	*read_from_file(char *buffer, int fd)
{
	int		bytes_read;
	char	*nbyte_buffer;

	nbyte_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (nbyte_buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, nbyte_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (nbyte_buffer), free(buffer), NULL);
		nbyte_buffer[bytes_read] = '\0';
		buffer = append_buffer(buffer, nbyte_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (nbyte_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1 * sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!ft_strchr(buffer, '\n'))
		buffer = read_from_file(buffer, fd);
	if (!buffer || buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	line = extract_line(buffer);
	buffer = get_rest(buffer);
	return (line);
}

// int main(void)
// {
// 	int	fd;
// 	char *next_line;

// 	fd = open("example.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		if (next_line == NULL)
// 			break ;
// 		printf("%s", next_line);
// 		free(next_line);
// 		next_line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }