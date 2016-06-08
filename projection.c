/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 12:06:18 by aputman           #+#    #+#             */
/*   Updated: 2016/06/01 16:34:56 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_iso(t_env *env, int x, int y, char truc)
{
	if (truc == '0')
	{
		env->map->px = x - y + (env->size / 2) + env->posx;
		env->map->py = (((x + y) / 2) -
				(env->map->tmap[y / env->zoom][x / env->zoom] * env->zoom))
			+ (env->size / 2) + env->posy;
	}
	else if (truc == '1')
	{
		env->map->dx = x - y + (env->size / 2) + env->posx;
		env->map->dy = (((x + y) / 2) -
				(env->map->tmap[y / env->zoom][x / env->zoom] * env->zoom))
			+ (env->size / 2) + env->posy;
	}
}
