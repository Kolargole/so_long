/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:44:18 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/21 00:19:29 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"
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

typedef struct s_assets
{
	t_data	wall;
	t_data	floor;
	t_data	collec;
	t_data	exit;
	t_data	c_exit;
	t_data	p_right;
	t_data	p_left;
}				t_assets;

typedef struct s_vars
{
	t_assets	assets;
	t_data		img;
	void		*mlx;
	void		*win;
	char		*map;
	int			x;
	int			y;
	int			pos_x;
	int			pos_y;
	int			exit_x;
	int			exit_y;
	int			width;
	int			height;
	int			map_width;
	int			map_height;
	int			file_size;
	int			n_collec;
	int			is_right;
	int			n_step;
}				t_vars;

// mlx :
void	main_mlx(t_vars *vars);
void	put_image_to_image(t_data *screen, t_data *file, int x, int y);
void	set_vars(t_vars *vars);
void	display_map(t_vars *vars);

// utils :
int		get_map_width(char *map);
int		get_map_height(char *map);

// events :
int		key_hook(int key_code, t_vars *vars);
int		event_hook(t_vars *vars);
void	movements(int key_code, t_vars *vars);
int		whats_ahead(t_vars *vars, int x, int y);

// parsing :
char	*parsing(char *map_file);
int		error_check(char *map);
int		shape_check(char *map);
int		wall_check(char *map);
int		components_check(char *map);

#endif