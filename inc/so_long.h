/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:44:18 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/17 18:15:42 by vimercie         ###   ########lyon.fr   */
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
	int		size_x;
	int		size_y;
	char	*path;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct s_assets
{
	t_data	wall;
	t_data	floor;
	t_data	collec;
	t_data	exit;
	t_data	p_right;
	t_data	p_left;
}				t_assets;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_assets	assets;
	t_data		img;
	// t_mlx		mlx;
	char		*map;
	int			x;
	int			y;
	int			width;
	int			height;
	int			map_width;
	int			map_height;
	int			file_size;
}				t_vars;

// mlx :
void	main_mlx(t_vars *vars);

// parsing :
char	*parsing(char *map_file);
int		error_check(char *map);
int		shape_check(char *map);
int		wall_check(char *map);
int		components_check(char *map);

// utils :
int		get_map_width(char *map);
int		get_map_height(char *map);

#endif