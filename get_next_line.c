/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:35:57 by codespace         #+#    #+#             */
/*   Updated: 2025/09/23 19:08:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		line = malloc(i + 2);
		if (!line)
			return (NULL);
		ft_strlcpy(line, stash, i + 2);
	}
	else
	{
		line = malloc(i + 1);
		if (!line)
			return (NULL);
		ft_strlcpy(line, stash, i + 1);
	}
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

char	*clean_stash(char *stash)
{
	char	*new_stash;
	size_t	remaining_result;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] != '\n')
		return (free_and_null(stash));
	remaining_result = ft_strlen(stash) - (i + 1);
	if (remaining_result <= 0)
		return (free_and_null(stash));
	new_stash = malloc(remaining_result + 1);
	if (!new_stash)
		return (free_and_null(stash));
	ft_strlcpy(new_stash, &stash[i + 1], remaining_result + 1);
	free_and_null(stash);
	return (new_stash);
}
