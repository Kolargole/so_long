/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:16:38 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/16 19:33:00 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_assets	set_assets(void *mlx, int width, int height)
{
	t_assets	as;

	as.floor = "./assets/floor.xpm";
	as.wall = "./assets/brick_wall.xpm";
	as.collec = "./assets/collectible.xpm";
	as.p_right = "./assets/player_right.xpm";
	as.p_left = "./assets/player_left.xpm";
	as.floor = mlx_xpm_file_to_image(mlx, as.floor, &width, &height);
	as.wall = mlx_xpm_file_to_image(mlx, as.wall, &width, &height);
	as.collec = mlx_xpm_file_to_image(mlx, as.collec, &width, &height);
	as.p_right = mlx_xpm_file_to_image(mlx, as.p_right, &width, &height);
	as.p_left = mlx_xpm_file_to_image(mlx, as.p_left, &width, &height);
	return (as);
}

void	mlx_main(int map_width, int map_height)
{
	void		*mlx;
	void		*mlx_win;
	t_assets	as;
	int			width;
	int			height;

	width = 16;
	height = 16;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 16 * map_width, 16 * map_height, "so_long");
	as = set_assets(mlx, width, height);
	mlx_put_image_to_window(mlx, mlx_win, as.collec, 0, 0);
	mlx_loop(mlx);
}
