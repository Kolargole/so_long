/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:59:31 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/24 17:33:18 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	whats_ahead(t_vars *vars, int x, int y)
{
	int	i;

	i = x + (y * vars->map_width) + y;
	if (vars->map[i] == '1' || (vars->map[i] == 'E' && vars->n_collec > 0))
		return (0);
	else if (vars->map[i] == 'C')
	{
		vars->n_collec--;
		vars->map[i] = '0';
		if (vars->n_collec == 0)
			put_image_to_image(&vars->img, &vars->assets.exit,
				vars->exit_x * vars->file_size, vars->exit_y * vars->file_size);
	}
	else if (vars->map[i] == 'E')
	{
		if (vars->n_collec <= 0)
		{
			write(1, "You won !\n", 10);
			close_window(vars);
		}
	}
	return (1);
}

int	which_way(int key_code, t_vars *vars)
{
	if (key_code == 13 && whats_ahead(vars, vars->pos_x, vars->pos_y - 1))
	{
		vars->pos_y--;
		return (1);
	}
	else if (key_code == 0 && whats_ahead(vars, vars->pos_x - 1, vars->pos_y))
	{
		vars->pos_x--;
		vars->is_right = 0;
		return (1);
	}
	else if (key_code == 1 && whats_ahead(vars, vars->pos_x, vars->pos_y + 1))
	{
		vars->pos_y++;
		return (1);
	}
	else if (key_code == 2 && whats_ahead(vars, vars->pos_x + 1, vars->pos_y))
	{
		vars->pos_x++;
		vars->is_right = 1;
		return (1);
	}
	return (0);
}

int	movements(int key_code, t_vars *vars)
{
	int	has_moved;

	put_image_to_image(&vars->img, &vars->assets.floor,
		vars->pos_x * vars->file_size, vars->pos_y * vars->file_size);
	has_moved = which_way(key_code, vars);
	if (vars->is_right)
		put_image_to_image(&vars->img, &vars->assets.p_right,
			vars->pos_x * vars->file_size, vars->pos_y * vars->file_size);
	else
		put_image_to_image(&vars->img, &vars->assets.p_left,
			vars->pos_x * vars->file_size, vars->pos_y * vars->file_size);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (has_moved);
}
