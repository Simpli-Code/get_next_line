/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:00:39 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/12 10:07:58 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	char	*line;

	fd = open("x_file.txt", O_RDONLY);
	fd1 = open("y_file.txt", O_RDONLY);
	fd2 = open("z_file.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
		sleep(1);
		line = get_next_line(fd1);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
		sleep(1);
		line = get_next_line(fd2);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
		sleep(1);
	}
	close(fd);
	close(fd1);
	close(fd2);
	return (0);
}
