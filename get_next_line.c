/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:35:57 by codespace         #+#    #+#             */
/*   Updated: 2025/10/06 19:16:58 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
read_and_join:
Reads from file descriptor and joins content to existing stash until
a newline is found or EOF is reached. Returns updated stash or NULL on error.
*/
char	*read_and_join(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_and_null(stash));
	bytes_read = 1;
	while (bytes_read > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (free_and_null(stash));
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (!temp)
		{
			free(buffer);
			return (free_and_null(stash));
		}
		free(stash);
		stash = temp;
	}
	free(buffer);
	return (stash);
}

/*
extract_line:
Extracts a single line (including '\n' if present) from the stash.
Returns a newly allocated string containing the line, or NULL if error.
*/
char	*extract_line(char *stash)
{
	size_t	i;
	size_t	len;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	len = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		len = i + 2;
	else
		len = i + 1;
	line = malloc(len);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, len);
	return (line);
}

/*
free_and_null:
Frees the memory pointed to by 'ptr' and returns NULL.
Useful for safely freeing pointers and resetting them in one step.
*/
char	*free_and_null(char *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

/*
update_stash:
Updates the stash by removing the extracted line and keeping the remainder.
Returns the new stash content after the newline, or NULL if no more content.
*/
char	*update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free_and_null(stash));
	new_stash = malloc(ft_strlen(stash) - i);
	if (!new_stash)
		return (free_and_null(stash));
	ft_strlcpy(new_stash, &stash[i + 1], ft_strlen(stash) - i);
	free(stash);
	return (new_stash);
}

/*
get_next_line:
Reads from file descriptor until it finds a line or reaches EOF.
Returns the next line read or NULL in case of error or end of file.
*/
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_join(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }