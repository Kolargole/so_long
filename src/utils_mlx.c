/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:57:30 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/21 00:39:05 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	xpm_to_image(t_vars	*vars)
{
	vars->assets.floor.img = mlx_xpm_file_to_image(vars->mlx,
			"./assets/64x64/floor(64x64).xpm",
			&vars->assets.floor.size_x, &vars->assets.floor.size_y);
	vars->assets.wall.img = mlx_xpm_file_to_image(vars->mlx,
			"./assets/64x64/brick_wall(64x64).xpm",
			&vars->assets.wall.size_x, &vars->assets.wall.size_y);
	vars->assets.collec.img = mlx_xpm_file_to_image(vars->mlx,
			"./assets/64x64/collectible(64x64).xpm",
			&vars->assets.collec.size_x, &vars->assets.collec.size_y);
	vars->assets.exit.img = mlx_xpm_file_to_image(vars->mlx,
			"./assets/64x64/exit(64x64).xpm",
			&vars->assets.exit.size_x, &vars->assets.exit.size_y);
	vars->assets.c_exit.img = mlx_xpm_file_to_image(vars->mlx,
			"./assets/64x64/closed_exit(64x64).xpm",
			&vars->assets.c_exit.size_x, &vars->assets.c_exit.size_y);
	vars->assets.p_right.img = mlx_xpm_file_to_image(vars->mlx,
			"./assets/64x64/player_right(64x64).xpm",
			&vars->assets.p_right.size_x, &vars->assets.p_right.size_y);
	vars->assets.p_left.img = mlx_xpm_file_to_image(vars->mlx,
			"./assets/64x64/player_left(64x64).xpm",
			&vars->assets.p_left.size_x, &vars->assets.p_left.size_y);
}

void	set_vars(t_vars *vars)
{
	xpm_to_image(vars);
	vars->assets.floor.addr = mlx_get_data_addr(vars->assets.floor.img,
			&vars->assets.floor.bits_per_pixel,
			&vars->assets.floor.line_length, &vars->assets.floor.endian);
	vars->assets.wall.addr = mlx_get_data_addr(vars->assets.wall.img,
			&vars->assets.wall.bits_per_pixel,
			&vars->assets.wall.line_length, &vars->assets.wall.endian);
	vars->assets.collec.addr = mlx_get_data_addr(vars->assets.collec.img,
			&vars->assets.collec.bits_per_pixel,
			&vars->assets.collec.line_length, &vars->assets.collec.endian);
	vars->assets.exit.addr = mlx_get_data_addr(vars->assets.exit.img,
			&vars->assets.exit.bits_per_pixel,
			&vars->assets.exit.line_length, &vars->assets.exit.endian);
	vars->assets.c_exit.addr = mlx_get_data_addr(vars->assets.c_exit.img,
			&vars->assets.c_exit.bits_per_pixel,
			&vars->assets.c_exit.line_length, &vars->assets.c_exit.endian);
	vars->assets.p_right.addr = mlx_get_data_addr(vars->assets.p_right.img,
			&vars->assets.p_right.bits_per_pixel,
			&vars->assets.p_right.line_length, &vars->assets.p_right.endian);
	vars->assets.p_left.addr = mlx_get_data_addr(vars->assets.p_left.img,
			&vars->assets.p_left.bits_per_pixel,
			&vars->assets.p_left.line_length, &vars->assets.p_left.endian);
}

void	display_assets(t_vars *vars, int i)
{
	if (vars->map[i] == '1')
		put_image_to_image(&vars->img, &vars->assets.wall,
			vars->x * vars->file_size, vars->y * vars->file_size);
	else if (vars->map[i] == '0')
		put_image_to_image(&vars->img, &vars->assets.floor,
			vars->x * vars->file_size, vars->y * vars->file_size);
	else if (vars->map[i] == 'P')
	{
		put_image_to_image(&vars->img, &vars->assets.p_right,
			vars->x * vars->file_size, vars->y * vars->file_size);
		vars->pos_x = vars->x;
		vars->pos_y = vars->y;
	}
	else if (vars->map[i] == 'E')
	{
		vars->exit_x = vars->x;
		vars->exit_y = vars->y;
		put_image_to_image(&vars->img, &vars->assets.c_exit,
			vars->exit_x * vars->file_size, vars->exit_y * vars->file_size);
	}
	else if (vars->map[i] == 'C')
	{
		vars->n_collec++;
		put_image_to_image(&vars->img, &vars->assets.collec,
			vars->x * vars->file_size, vars->y * vars->file_size);
	}
}

void	display_map(t_vars *vars)
{
	int		i;

	i = 0;
	vars->x = 0;
	vars->y = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == '\n')
		{
			vars->x = 0;
			vars->y++;
			i++;
		}
		display_assets(vars, i);
		vars->x++;
		i++;
	}
}
