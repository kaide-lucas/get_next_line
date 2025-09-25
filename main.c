/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:41:03 by codespace         #+#    #+#             */
/*   Updated: 2025/09/24 18:43:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
    char	*stash = ft_strdup("Linha 1\nLinha 2\nLinha 3 sem quebra");
    char	*line;

    while (stash && stash[0])
    {
        line = extract_line(stash);
        if (line)
        {
            printf("Extracted line: %s\n", line);
            free(line);
        }
        stash = update_stash(stash);
    }
    return (0);
}
