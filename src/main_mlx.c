/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:16:38 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/17 04:37:02 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_assets	set_assets(void *mlx, int f_size)
{
	t_assets	as;

	as.floor = "./assets/16x16/floor.xpm";
	as.wall = "./assets/16x16/brick_wall.xpm";
	as.collec = "./assets/16x16/collectible.xpm";
	as.exit = "./assets/16x16/exit.xpm"
	as.p_right = "./assets/16x16/player_right.xpm";
	as.p_left = "./assets/16x16/player_left.xpm";
	as.floor = mlx_xpm_file_to_image(mlx, as.floor, &f_size, &f_size);
	as.wall = mlx_xpm_file_to_image(mlx, as.wall, &f_size, &f_size);
	as.collec = mlx_xpm_file_to_image(mlx, as.collec, &f_size, &f_size);
	as.exit = mlx_xpm_file_to_image(mlx, as.exit, &f_size, &f_size);
	as.p_right = mlx_xpm_file_to_image(mlx, as.p_right, &f_size, &f_size);
	as.p_left = mlx_xpm_file_to_image(mlx, as.p_left, &f_size, &f_size);
	return (as);
}

void	display_map(t_mlx mlx, t_vars vars, t_assets assets)
{
	int	i;

	i = 0;
	vars.x = 0;
	vars.y = 0;
	while (vars.map[i])
	{
		if (vars.map[i] == '\n')
		{
			vars.x = 0;
			vars.y++;
		}
		else if (vars.map[i] == '1')
			mlx_put_image_to_window(mlx.ptr, mlx.win, assets.wall,
					vars.x * vars.file_size, vars.y * vars.file_size);
		else
		{
			mlx_put_image_to_window(mlx.ptr, mlx.win, assets.floor,
					vars.x * vars.file_size, vars.y * vars.file_size);
			if (vars.map[i] == 'P')
				mlx_put_image_to_window(mlx.ptr, mlx.win, assets.p_right,
						vars.x * vars.file_size, vars.y * vars.file_size);
			else if (vars.map[i] == 'E')
				mlx_put_image_to_window(mlx.ptr, mlx.win, assets.exit, 
						vars.x * vars.file_size, vars.y * vars.file_size);
			else if (vars.map[i] == 'C')
				mlx_put_image_to_window(mlx.ptr, mlx.win, assets.collec,
						vars.x * vars.file_size, vars.y * vars.file_size);
		}
		vars.x++;
		i++;
	}
}

void	main_mlx(t_vars vars)
{
	t_mlx		mlx;
	t_assets	assets;

	vars.file_size = 16;
	vars.width = vars.file_size * vars.map_width;
	vars.height = vars.file_size * vars.map_height;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(vars.mlx, vars.width, vars.height, "so_long");
	assets = set_assets(vars.mlx, vars.file_size);
	display_map(mlx, vars, assets);
	mlx_loop(mlx);
}
