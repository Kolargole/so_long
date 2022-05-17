/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:16:38 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/17 18:37:17 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_vars(t_vars *vars)
{
	// vars->assets.floor.path = "./assets/64x64/floor(64x64).xpm";
	// vars->assets.wall.path = "./assets/64x64/brick_wall(64x64).xpm";
	// vars->assets.collec.path = "./assets/64x64/collectible(64x64).xpm";
	// vars->assets.exit.path = "./assets/64x64/exit(64x64).xpm";
	// vars->assets.p_right.path = "./assets/64x64/player_right(64x64).xpm";
	// vars->assets.p_left.path = "./assets/64x64/player_left(64x64).xpm";
	vars->assets.floor.img = mlx_xpm_file_to_image(vars->mlx, "./assets/64x64/floor(64x64).xpm", &vars->assets.floor.size_x, &vars->assets.floor.size_y);
	vars->assets.wall.img = mlx_xpm_file_to_image(vars->mlx, "./assets/64x64/brick_wall(64x64).xpm", &vars->assets.wall.size_x, &vars->assets.wall.size_y);
	vars->assets.collec.img = mlx_xpm_file_to_image(vars->mlx, "./assets/64x64/collectible(64x64).xpm", &vars->assets.collec.size_x, &vars->assets.collec.size_y);
	vars->assets.exit.img = mlx_xpm_file_to_image(vars->mlx, "./assets/64x64/exit(64x64).xpm", &vars->assets.exit.size_x, &vars->assets.exit.size_y);
	vars->assets.p_right.img = mlx_xpm_file_to_image(vars->mlx, "./assets/64x64/player_right(64x64).xpm", &vars->assets.p_right.size_x, &vars->assets.p_right.size_y);
	vars->assets.p_left.img = mlx_xpm_file_to_image(vars->mlx, "./assets/64x64/player_left(64x64).xpm", &vars->assets.p_left.size_x, &vars->assets.p_left.size_y);
	dprintf(1, "aaaa\n");
	vars->assets.floor.addr = mlx_get_data_addr(vars->assets.floor.img,
			&vars->assets.floor.bits_per_pixel,
			&vars->assets.floor.line_length,
			&vars->assets.floor.endian);
	vars->assets.wall.addr = mlx_get_data_addr(vars->assets.wall.img,
			&vars->assets.wall.bits_per_pixel,
			&vars->assets.wall.line_length,
			&vars->assets.wall.endian);
	vars->assets.collec.addr = mlx_get_data_addr(vars->assets.collec.img,
			&vars->assets.collec.bits_per_pixel,
			&vars->assets.collec.line_length,
			&vars->assets.collec.endian);
	vars->assets.exit.addr = mlx_get_data_addr(vars->assets.exit.img,
			&vars->assets.exit.bits_per_pixel,
			&vars->assets.exit.line_length,
			&vars->assets.exit.endian);
	vars->assets.p_right.addr = mlx_get_data_addr(vars->assets.p_right.img,
			&vars->assets.p_right.bits_per_pixel,
			&vars->assets.p_right.line_length,
			&vars->assets.p_right.endian);
	vars->assets.p_left.addr = mlx_get_data_addr(vars->assets.p_left.img,
			&vars->assets.p_left.bits_per_pixel,
			&vars->assets.p_left.line_length,
			&vars->assets.p_left.endian);
}

void	put_image_to_image(t_data *screen, t_data *file, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < file->size_y)
	{
		j = -1;
		while (++j < file->size_x)
			my_mlx_pixel_put(screen, x + j, y + i, *((int *)(file->addr + (i * file->line_length + j * (file->bits_per_pixel / 8)))));
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
		if (vars->map[i] == '1')
			put_image_to_image(&vars->img, &vars->assets.wall,
				vars->x * vars->file_size, vars->y * vars->file_size);
		else
		{
			put_image_to_image(&vars->img, &vars->assets.floor,
				vars->x * vars->file_size, vars->y * vars->file_size);
			if (vars->map[i] == 'P')
				put_image_to_image(&vars->img, &vars->assets.p_right,
					vars->x * vars->file_size, vars->y * vars->file_size);
			else if (vars->map[i] == 'E')
				put_image_to_image(&vars->img, &vars->assets.exit,
					vars->x * vars->file_size, vars->y * vars->file_size);
			else if (vars->map[i] == 'C')
				put_image_to_image(&vars->img, &vars->assets.collec,
					vars->x * vars->file_size, vars->y * vars->file_size);
		}
		vars->x++;
		i++;
	}
}

void	main_mlx(t_vars *vars)
{
	vars->file_size = 64;
	vars->width = vars->file_size * vars->map_width;
	vars->height = vars->file_size * vars->map_height;
	vars->mlx = mlx_init();
	dprintf(1, "test\n");
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "so_long");
	dprintf(1, "test\n");
	set_vars(vars);
	my_mlx_pixel_put(&vars->img, 0, 0, 0xFF0000);
	dprintf(1, "test\n");
	vars->img.img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	dprintf(1, "test\n");
	// display_map(mlx, vars, vars->assets);
	for (size_t i = 0; i < 100; i++)
	{
		/* code */
		my_mlx_pixel_put(&vars->img, i, 0, 0xff0000);
	}
	put_image_to_image(&vars->img, &vars->assets.p_right, 20, 20);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_loop(vars->mlx);
}
