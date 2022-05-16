/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:44:18 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/16 19:23:46 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/inc/libft.h"
# include "../mlx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_assets
{
	char	*wall;
	char	*floor;
	char	*collec;
	char	*p_right;
	char	*p_left;
}				t_assets;

// parsing :
char	*parsing(char *map_file);
int		error_check(char *map);
int		shape_check(char *map);
int		wall_check(char *map);
int		components_check(char *map);

// mlx :
void	mlx_main(int map_width, int map_height);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// utils :
int		get_map_width(char *map);
int		get_map_height(char *map);

#endif