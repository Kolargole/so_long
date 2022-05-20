/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:47:12 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/20 15:26:32 by vimercie         ###   ########lyon.fr   */
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
		movements(key_code, vars);
	return (0);
}

int	event_hook(t_vars *vars)
{
	(void)vars;
	exit(0);
}
