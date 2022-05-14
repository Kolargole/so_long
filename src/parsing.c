/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:00:15 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/14 03:33:02 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*parsing(int argc, char *argv[])
{
	int		fd;
	int		i;
	char	*map;
	char	*buf;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	map = NULL;
	while (buf)
	{
		buf = get_next_line(fd);
		map = gnl_strjoin(map, buf);
		i++;
	}
	close(fd);
	return (map);
}

int	error_check(char *map)
{
	if (!shape_check(map))
	{
		write(1, "Error\n", 6);
		write(1, "Map isn't rectangular enough\n", 29);
		return (0);
	}
	if (!wall_check(map))
	{
		write(1, "Error\n", 6);
		write(1, "Map isn't surrounded by walls\n", 30);
		return (0);
	}
	if (!components_check(map))
	{
		write(1, "Error\n", 6);
		write(1, "Map's missing something\n", 24);
	}
	return (1);
}
