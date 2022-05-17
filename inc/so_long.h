/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:44:18 by vimercie          #+#    #+#             */
/*   Updated: 2022/05/17 04:29:24 by vimercie         ###   ########lyon.fr   */
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

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct s_vars
{
	char	*map;
	int		x;
	int		y;
	int		width;
	int		height;
	int		map_width;
	int		map_height;
	int		file_size;
}				t_vars;

typedef struct s_assets
{
	char	*wall;
	char	*floor;
	char	*collec;
	char	*exit;
	char	*p_right;
	char	*p_left;
}				t_assets;

// mlx :
void	main_mlx(t_vars vars);

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