/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:04:50 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/25 17:06:52 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		return (0);
	vars.map = parsing(argv[1]);
	if (!vars.map)
		return (0);
	if (!error_check(vars.map, &vars))
	{
		free(vars.map);
		return (0);
	}
	vars.map_width = get_map_width(vars.map);
	vars.map_height = get_map_height(vars.map);
	main_mlx(&vars);
	return (0);
}
