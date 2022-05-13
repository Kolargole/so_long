/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:04:50 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/13 22:44:31 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// enlever <stdio.h> avant de rendre le projet.
#include <stdio.h>
#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	int	i;
	char	**map;

	i = 0;
	map = parsing(argc, argv);
	while (map[i])
	{
		dprintf(1, "%s", map[i]);
		i++;
	}
	free(map);
	return (0);
}
