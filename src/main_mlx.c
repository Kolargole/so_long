/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:16:38 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/20 17:52:37 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_image_to_image(t_data *screen, t_data *file, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->size_y)
	{
		j = 0;
		while (j < file->size_x)
		{
			my_mlx_pixel_put(screen, x + j, y + i,
				*((int *)(file->addr + (i * file->line_length + j
							* (file->bits_per_pixel / 8)))));
			j++;
		}
		i++;
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

void	main_mlx(t_vars *vars)
{
	vars->file_size = 64;
	vars->width = vars->file_size * vars->map_width;
	vars->height = vars->file_size * vars->map_height;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "so_long");
	set_vars(vars);
	vars->img.img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	display_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}
