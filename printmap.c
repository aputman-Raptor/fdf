/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 09:35:18 by aputman           #+#    #+#             */
/*   Updated: 2016/05/10 13:23:25 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(t_env env, int x, int y, t_color *color)
{
	char		*data;

	data = mlx_get_data_addr(env.img, &env.rgb, &env.rgb_line, &env.endian);
	data[x * env.rgb / 8 + y * env.rgb_line] = color->b;
	data[x * env.rgb / 8 + 1 + y * env.rgb_line] = color->g;
	data[x * env.rgb / 8 + 2 + y * env.rgb_line] = color->r;
}

static void		draw_line(t_env env, t_map *map, int px, int py)
{
	t_bresenham marvel;

	marvel.dx = abs(map->dx - px);
	marvel.sx = px < map->dx ? 1 : -1;
	marvel.dy = abs(map->dy - py);
	marvel.sy = py < map->dy ? 1 : -1;
	marvel.err = (marvel.dx > marvel.dy ? marvel.dx : -marvel.dy) / 2;
	while (1)
	{
		if (px < env.size && px >= 0 && py < env.size && py >= 0)
			draw_pixel(env, px, py, env.color);
		if (px == map->dx && py == map->dy)
			break ;
		marvel.e2 = marvel.err;
		if (marvel.e2 > -marvel.dx)
		{
			marvel.err -= marvel.dy;
			px += marvel.sx;
		}
		if (marvel.e2 < marvel.dy)
		{
			marvel.err += marvel.dx;
			py += marvel.sy;
		}
	}
}

void			put_overlay(t_env env, int overlay)
{
	if (overlay == 1)
	{
		mlx_string_put(env.mlx, env.win, 20, 20, 0xFFFFFF, "X = ");
		mlx_string_put(env.mlx, env.win, 60, 20, 0xFFFFFF, ft_itoa(-env.posx));
		mlx_string_put(env.mlx, env.win, 20, 40, 0xFFFFFF, "Y = ");
		mlx_string_put(env.mlx, env.win, 60, 40, 0xFFFFFF, ft_itoa(-env.posy));
		mlx_string_put(env.mlx, env.win, 20, 60, 0xFFFFFF, "Zoom = ");
		mlx_string_put(env.mlx, env.win, 90, 60, 0xFFFFFF, ft_itoa(env.zoom));
	}
}

void			printmap(t_map *map, t_env env)
{
	env.img = mlx_new_image(env.mlx, env.size, env.size);
	env.y = -1;
	while (++env.y < map->len_y)
	{
		env.x = -1;
		while (++env.x < map->len_x)
		{
			if (env.x + 2 <= map->len_x)
			{
				apply_iso(env, env.x * env.zoom, env.y * env.zoom, '0');
				apply_iso(env, (env.x + 1) * env.zoom, env.y * env.zoom, '1');
				draw_line(env, map, map->px, map->py);
			}
			if (env.y + 1 < map->len_y)
			{
				apply_iso(env, env.x * env.zoom, env.y * env.zoom, '0');
				apply_iso(env, env.x * env.zoom, (env.y + 1) * env.zoom, '1');
				draw_line(env, map, map->px, map->py);
			}
		}
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	put_overlay(env, env.overlay);
	mlx_destroy_image(env.mlx, env.img);
}
