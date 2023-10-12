/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:00:45 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/12 10:18:00 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("big_text_file.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
		usleep(190000);
	}
	close(fd);
	return (0);
}

/*
in this main function you can pass as argument the name
of the file to be read, the file must exist !!!

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (1)
		{
			line = get_next_line(fd);
			printf("%s", line);
			if (line == NULL)
				break ;
			free(line);
			sleep(1);
		}
		close(fd);
	}
	else
		printf("too few arguments were entered on the command line!\n");
	return (0);
}
*/
