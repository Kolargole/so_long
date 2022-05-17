/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:04:50 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/17 17:48:10 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// enlever <stdio.h> avant de rendre le projet.
#include <stdio.h>
#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		return (0);
	vars.map = parsing(argv[1]);
	if (!vars.map)
		return (0);
	if (!error_check(vars.map))
		return (0);
	vars.map_width = get_map_width(vars.map);
	vars.map_height = get_map_height(vars.map);
	main_mlx(&vars);
	free(vars.map);
	return (0);
}
