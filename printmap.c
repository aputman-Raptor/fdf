/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 09:35:18 by aputman           #+#    #+#             */
/*   Updated: 2016/06/01 16:27:48 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(t_env *env, int x, int y, t_color *color)
{
	char		*data;

	data = mlx_get_data_addr(env->img, &env->rgb, &env->rgb_line, &env->endian);
	data[x * env->rgb / 8 + y * env->rgb_line] = color->b;
	data[x * env->rgb / 8 + 1 + y * env->rgb_line] = color->g;
	data[x * env->rgb / 8 + 2 + y * env->rgb_line] = color->r;
}

static void		draw_line(t_env *env, t_map *map, int px, int py)
{
	t_bresenham marvel;

	marvel.dx = abs(map->dx - px);
	marvel.sx = px < map->dx ? 1 : -1;
	marvel.dy = abs(map->dy - py);
	marvel.sy = py < map->dy ? 1 : -1;
	marvel.err = (marvel.dx > marvel.dy ? marvel.dx : -marvel.dy) / 2;
	while (1)
	{
		if (px < env->size && px >= 0 && py < env->size && py >= 0)
			draw_pixel(env, px, py, env->color);
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

void			put_overlay(t_env *e, int overlay)
{
	if (overlay == 1)
	{
		mlx_string_put(e->mlx, e->win, 20, 20, 0xFFFFFF, "X = ");
		mlx_string_put(e->mlx, e->win, 60, 20, 0xFFFFFF, ft_itoa(-e->posx));
		mlx_string_put(e->mlx, e->win, 20, 40, 0xFFFFFF, "Y = ");
		mlx_string_put(e->mlx, e->win, 60, 40, 0xFFFFFF, ft_itoa(-e->posy));
		mlx_string_put(e->mlx, e->win, 20, 60, 0xFFFFFF, "Zoom = ");
		mlx_string_put(e->mlx, e->win, 90, 60, 0xFFFFFF, ft_itoa(e->zoom));
	}
}

void			printmap(t_map *map, t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->size, e->size);
	e->y = -1;
	while (++e->y < map->len_y)
	{
		e->x = -1;
		while (++e->x < map->len_x)
		{
			if (e->x + 2 <= map->len_x)
			{
				apply_iso(e, e->x * e->zoom, e->y * e->zoom, '0');
				apply_iso(e, (e->x + 1) * e->zoom, e->y * e->zoom, '1');
				draw_line(e, map, map->px, map->py);
			}
			if (e->y + 1 < map->len_y)
			{
				apply_iso(e, e->x * e->zoom, e->y * e->zoom, '0');
				apply_iso(e, e->x * e->zoom, (e->y + 1) * e->zoom, '1');
				draw_line(e, map, map->px, map->py);
			}
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	put_overlay(e, e->overlay);
	mlx_destroy_image(e->mlx, e->img);
}
