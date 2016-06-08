/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 17:38:16 by aputman           #+#    #+#             */
/*   Updated: 2016/06/01 16:43:07 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				zoom;
	int				size;
	int				rgb;
	int				rgb_line;
	int				endian;
	int				posx;
	int				posy;
	int				x;
	int				y;
	int				overlay;
	struct s_map	*map;
	struct s_color	*color;
}					t_env;

typedef struct		s_map
{
	char			*map_text;
	int				**tmap;
	int				px;
	int				py;
	int				len_x;
	int				len_y;
	int				dx;
	int				dy;
	int				posx;
	int				posy;
}					t_map;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_bresenham
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				e2;
	int				err;
}					t_bresenham;

t_map				*getmap(t_map *map, char *argv);

void				mlx_env_init(t_env *env);
void				exit_handler(t_env *env, t_map *map);

int					map_key(int keycode, t_env *env);
int					color_key(int keycode, t_env *env);

void				printmap(t_map *map, t_env *e);
void				apply_iso(t_env *env, int x, int y, char truc);

#endif
