/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:35:57 by codespace         #+#    #+#             */
/*   Updated: 2025/09/22 00:19:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

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
