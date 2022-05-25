/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:16:38 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/25 16:55:14 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

void	put_image_to_image(t_data *screen, t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	offset;

	i = 0;
	while (i < data->size_y)
	{
		j = 0;
		while (j < data->size_x)
		{
			offset = *((int *)(data->addr + (i * data->line_length
							+ j * (data->bits_per_pixel / 8))));
			my_mlx_pixel_put(screen, x + j, y + i, offset);
			j++;
		}
		i++;
	}
}

void	main_mlx(t_vars *vars)
{
	vars->file_size = 64;
	vars->width = vars->file_size * vars->map_width;
	vars->height = vars->file_size * vars->map_height;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "so_long");
	xpm_to_image(vars);
	set_data_addr(vars);
	vars->img.img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	display_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}
