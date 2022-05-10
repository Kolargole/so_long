/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:00:15 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/10 18:30:10 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parsing(int argc, char *argv[])
{
	char	**map;
	int		fd;
	int		i;

	i = 1;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	map[0] = get_next_line(fd);
	while (map[i - 1][0] != '\0')
	{
		map[i] = get_next_line(fd);
		i++;
	}
	return (map);
}

int	error_check(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = 0;
	if (!shape_check(map))
	{
		write(1, "Map isn't rectangular enough\n", 29);
		return (0);
	}
	
}

int	shape_check(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (map[j][len])
		len++;
	j++;
	while (map[j])
	{
		while (map[j][i])
			i++;
		if (i != len)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i = 0;
		j++;
	}
	return (1);
}

int	wall_check(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (map[i][len])
		len++;
	len--;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	i = 1;
	while (map[i][0] != '\0')
	{
		if (map[i][0] != '1' | map[i][len] != '1')
		{
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	len = i - 1;
	i = 0;
	while (map[len][i])
	{
		if (map[len][i] != '1')
		{
			write(1, "error\n", 6);
			return (0);
		}
	}
	return (1);
}
