/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:35:57 by codespace         #+#    #+#             */
/*   Updated: 2025/09/28 16:17:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	free(ptr);
	return (NULL);
}

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
	new_stash = malloc(ft_strlen(stash) - i + 1);
	if (!new_stash)
		return (free_and_null(stash));
	ft_strlcpy(new_stash, &stash[i + 1], ft_strlen(stash) - i);
	free(stash);
	return (new_stash);
}

/*
get_next_line:
Lê do file descriptor até encontrar uma linha ou EOF.
Retorna a próxima linha lida ou NULL em caso de erro ou fim de arquivo.
*/
char *get_next_line(int fd)
{
	static char *stash;
	char buffer[BUFFER_SIZE + 1];
	ssize_t bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	// 1. Ler do fd e adicionar ao stash
	bytes_read = 1;
	while (bytes_read > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return free_and_null(stash);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	// 2. Extrair linha do stash
	char *line = extract_line(stash);
	// 3. Atualizar stash
	stash = update_stash(stash);
	// 4. Retornar linha
	return line;
}
