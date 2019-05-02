/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:55:35 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/10 13:07:40 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>


int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	int	i;
	int	ret;
	
	i = 0;
	(void)argc;
	fd = open((argv[1]), O_RDONLY);
	while (i < 36)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		printf("%d %d\n",i,ret = get_next_line(fd, &line));
		i++;
	}
	fd = open((argv[2]), O_RDONLY);
	i = 0;
    while (i < 15)
    {
        line = (char *)malloc(sizeof(*line) * 1);
		printf("%d %d\n",i,ret = get_next_line(fd, &line));
        i++;
    }
}
