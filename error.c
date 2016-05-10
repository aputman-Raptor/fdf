/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:26:40 by aputman           #+#    #+#             */
/*   Updated: 2016/05/03 14:18:12 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_handler(t_env *env, t_map *map)
{
	free(map->map_text);
	free(map->tmap);
	free(map);
	free(env->win);
	free(env->mlx);
	exit(0);
}
