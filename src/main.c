/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:04:50 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/14 01:58:45 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// enlever <stdio.h> avant de rendre le projet.
#include <stdio.h>
#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	char	*map;
	int		i;

	i = 0;
	map = parsing(argc, argv);
	if (map == 0)
		return (0);
	while (map[i])
	{
		dprintf(1, "%c", map[i]);
		i++;
	}
	dprintf(1, "\n");
	if (!shape_check(map))
		dprintf(1, "not rectangular enough\n");
	else
		dprintf (1, "map ok\n");
	free(map);
	return (0);
}
