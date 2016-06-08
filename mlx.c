/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:27:13 by aputman           #+#    #+#             */
/*   Updated: 2016/06/07 13:13:34 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		key_ft(int keycode, t_env *env)
{
	int			result;

	if (keycode == 53)
		exit_handler(&(*env), &(*env->map));
	if (keycode == 122)
	{
		if (env->overlay == 0)
			env->overlay = 1;
		else
			env->overlay = 0;
	}
	result = map_key(keycode, &(*env));
	if (keycode == 82)
	{
		env->color->r = 255;
		env->color->g = 255;
		env->color->b = 255;
		result = 1;
	}
	else
		result = color_key(keycode, &(*env));
	if (result == 1)
		printmap(env->map, env);
	return (1);
}

void			mlx_env_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		exit(0);
	env->zoom = 1;
	env->size = 1000;
	env->posx = 0;
	env->posy = 0;
	env->overlay = 0;
	if (!(env->color = (t_color *)malloc(sizeof(t_color))))
		exit(0);
	env->color->r = 255;
	env->color->g = 255;
	env->color->b = 255;
	env->win = mlx_new_window(env->mlx, env->size, env->size, "fdf");
	mlx_hook(env->win, 2, 1, key_ft, &(*env));
}
