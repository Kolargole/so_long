/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:20:27 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/14 03:26:29 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	shape_check(char *map)
{
	int	i;
	int	l_len;
	int	l_count;

	i = 0;
	while (map[i] != '\n' && map[i])
		i++;
	if (i == (int)ft_strlen(map))
		return (0);
	l_len = i;
	l_count = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (l_len != (i - l_count - (l_len * l_count)))
				return (0);
			l_count++;
		}
		i++;
	}
	if (l_len != (i - l_count - (l_len * l_count)))
		return (0);
	return (1);
}

int	midwall_check(char *map, int i, int len)
{
	if (i <= len)
	{
		while (i <= len)
		{
			if (map[i] == '\n')
			{
				if (map[i + 1] != '1' || map[i - 1] != '1')
					return (0);
			}
			i++;
		}
	}
	return (1);
}

int	wall_check(char *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map) - 1;
	while (map[i] != '\n' && map[i])
	{
		if (map[i] != '1')
			return (0);
		i++;
	}
	if (i < len + 1)
	{
		while (map[len] != '\n' && len > i)
		{
			if (map[len] != '1')
				return (0);
			len--;
		}
	}
	else
		return (0);
	return (midwall_check(map, i, len));
}

int	components_check(char *map)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			p++;
		if (map[i] == 'E')
			e++;
		if (map[i] == 'C')
			c++;
		i++;
	}
	if (p == 0 || e == 0 || c == 0)
		return (0);
	return (1);
}
