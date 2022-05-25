/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:47:12 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/25 17:02:52 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int key_code, t_vars *vars)
{
	char	*n_step;

	if (key_code == 53)
		close_window(vars);
	if (key_code == 13 || (key_code >= 0 && key_code <= 2))
	{
		if (movements(key_code, vars))
		{
			vars->n_step++;
			write(1, "You moved ", 10);
			ft_putnbr_fd(vars->n_step, 1);
			write(1, " times.\n", 8);
		}
	}
	n_step = ft_itoa(vars->n_step);
	mlx_string_put(vars->mlx, vars->win, 34, 22, 0x00FF00, n_step);
	free(n_step);
	return (0);
}
