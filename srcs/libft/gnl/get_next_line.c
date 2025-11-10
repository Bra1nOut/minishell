/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:23:55 by levincen          #+#    #+#             */
/*   Updated: 2024/12/17 10:51:04 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	malloc_temp(int fd, char **temp)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*temp)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*line;
	int			bytes_read;

	if (malloc_temp(fd, &temp) == 0)
		return (NULL);
	while (!ftt_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp);
			if (bytes_read == 0)
				break ;
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer = ftt_strjoin(buffer, temp);
	}
	if (ftt_strchr(buffer, '\n'))
		free(temp);
	line = search_copy(buffer);
	buffer = rm_start(buffer, line);
	return (line);
}

// int	main()
// {
// 	int	fd = open("text.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erreur lors de l'ouverture du fichier");
// 			return 1;
// 	}
// 	char	*line;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	// printf("%s\n", "connard");
// }
