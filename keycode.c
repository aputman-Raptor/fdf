/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:48:22 by aputman           #+#    #+#             */
/*   Updated: 2016/06/07 13:13:10 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_pos(t_env *env)
{
	env->zoom = 1;
	env->posx = 0;
	env->posy = 0;
}

int			map_key(int keycode, t_env *env)
{
	if (keycode == 49)
		reset_pos(&(*env));
	if (keycode == 69)
		env->zoom += 1;
	if (keycode == 78)
	{
		if (env->zoom > 1)
			env->zoom -= 1;
	}
	if (keycode == 123)
		env->posx += (1 * env->zoom);
	else if (keycode == 124)
		env->posx -= (1 * env->zoom);
	else if (keycode == 125)
		env->posy -= (1 * env->zoom);
	else if (keycode == 126)
		env->posy += (1 * env->zoom);
	return (1);
}

static void	gimme_my_color(char mode, t_env *env)
{
	if (mode == 'R')
	{
		env->color->r = 255;
		env->color->g = 0;
		env->color->b = 0;
	}
	if (mode == 'G')
	{
		env->color->r = 0;
		env->color->g = 255;
		env->color->b = 0;
	}
	if (mode == 'B')
	{
		env->color->r = 0;
		env->color->g = 0;
		env->color->b = 255;
	}
	if (mode == 'Y')
	{
		env->color->r = 255;
		env->color->g = 255;
		env->color->b = 0;
	}
}

int			color_key(int keycode, t_env *env)
{
	if (keycode == 83)
		gimme_my_color('R', &(*env));
	if (keycode == 84)
		gimme_my_color('G', &(*env));
	if (keycode == 85)
		gimme_my_color('B', &(*env));
	if (keycode == 86)
		gimme_my_color('Y', &(*env));
	if (keycode == 87)
	{
		env->color->r = 0;
		env->color->g = 255;
		env->color->b = 255;
	}
	if (keycode == 88)
	{
		env->color->r = 255;
		env->color->g = 0;
		env->color->b = 255;
	}
	return (1);
}
