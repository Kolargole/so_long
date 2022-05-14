/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:04:50 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/14 03:32:46 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// enlever <stdio.h> avant de rendre le projet.
#include <stdio.h>
#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	char	*map;
	
	map = parsing(argc, argv);
	if (map == 0)
		return (0);
	if (!error_check(map))
		return (0);
	free(map);
	return (0);
}
