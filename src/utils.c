/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:04:00 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/16 18:34:39 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_map_width(char *map)
{
	int	width;

	width = 0;
	while (map[width] != '\n')
		width++;
	return (width);
}

int	get_map_height(char *map)
{
	int	i;
	int	height;

	i = 0;
	height = 1;
	while (map[i])
	{
		if (map[i] == '\n')
			height++;
		i++;
	}
	return (height);
}
