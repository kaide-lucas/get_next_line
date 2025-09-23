/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:41:03 by codespace         #+#    #+#             */
/*   Updated: 2025/09/23 18:50:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	char	*stash;
	char	*line;

	stash = "Sem novas linhas aqui\n";
	line = extract_line(stash);
	if (line)
	{
		printf("Extracted line: %s\n", line);
		free(line);
	}
	else
	{
		printf("No line extracted.\n");
	}
	return (0);
}
