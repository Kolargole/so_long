/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:59:31 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/20 18:04:38 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	whats_ahead(t_vars *vars, int x, int y)
{
	int	i;

	i = x + (y * vars->map_width) + y;
	if (vars->map[i] == '1' || vars->map[i] == 'E')
		return (0);
	else if (vars->map[i] == 'C')
	{
		vars->n_collec--;
		if (vars->n_collec == 0)
			put_image_to_image(&vars->img, &vars->assets.exit,
				vars->exit_x * vars->file_size, vars->exit_y * vars->file_size);
	}
	// else if (vars->map[i] == 'E')
	// {
	// 	if (vars->n_collec <= 0)
	// 		You won!;
	// }
	return (1);
}

void	movements(int key_code, t_vars *vars)
{
	put_image_to_image(&vars->img, &vars->assets.floor,
		vars->pos_x * vars->file_size, vars->pos_y * vars->file_size);
	if (key_code == 13)
	{
		if (whats_ahead(vars, vars->pos_x, vars->pos_y - 1))
			vars->pos_y--;
	}
	else if (key_code == 0)
	{
		if (whats_ahead(vars, vars->pos_x - 1, vars->pos_y))
			vars->pos_x--;
	}
	else if (key_code == 1)
	{
		if (whats_ahead(vars, vars->pos_x, vars->pos_y + 1))
			vars->pos_y++;
	}
	else if (key_code == 2)
	{
		if (whats_ahead(vars, vars->pos_x + 1, vars->pos_y))
			vars->pos_x++;
	}
	put_image_to_image(&vars->img, &vars->assets.p_right,
		vars->pos_x * vars->file_size, vars->pos_y * vars->file_size);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
