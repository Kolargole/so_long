/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:47:12 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/21 00:24:14 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int key_code, t_vars *vars)
{
	if (key_code == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		event_hook(NULL);
	}
	if (key_code == 13 || (key_code >= 0 && key_code <= 2))
	{
		movements(key_code, vars);
		vars->n_step++;
		write(1, "You moved ", 10);
		ft_putnbr_fd(vars->n_step, 1);
		write(1, " times.\n", 8);
	}
	return (0);
}

int	event_hook(t_vars *vars)
{
	// gestion de la croix !
	(void)vars;
	exit(0);
}
