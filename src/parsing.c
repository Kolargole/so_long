/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:00:15 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/25 17:03:06 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*parsing(char *map_file)
{
	int		fd;
	char	*map;
	char	*buf;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	buf = get_next_line(fd);
	map = gnl_strjoin(map, buf);
	while (buf)
	{
		buf = get_next_line(fd);
		map = gnl_strjoin(map, buf);
	}
	free(buf);
	close(fd);
	return (map);
}

int	error_check(char *map, t_vars *vars)
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
	if (!components_check(map, vars))
	{
		write(1, "Error\n", 6);
		write(1, "Map's missing something or too much players/exits\n", 50);
		return (0);
	}
	return (1);
}
