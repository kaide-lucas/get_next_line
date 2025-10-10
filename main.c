/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:57:25 by kaidda-s          #+#    #+#             */
/*   Updated: 2025/10/10 19:00:23 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
 {
 	int		fd;
 	char	*line;

 	fd = open("test.txt", O_RDONLY);
 	if (fd < 0)
	{
		perror("open");
 		return (1);
 	}
 	while ((line = get_next_line(fd)) != NULL)
 	{
 		printf("%s", line);
 		free(line);
	}
close(fd);
return (0);
}