/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:35:57 by codespace         #+#    #+#             */
/*   Updated: 2025/09/25 15:36:59 by codespace        ###   ########.fr       */
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
