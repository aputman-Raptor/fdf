/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:44:50 by aputman           #+#    #+#             */
/*   Updated: 2016/06/01 16:35:59 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			usage(void)
{
	ft_putstr("\033[31m");
	ft_putstr("Incorrect number of argument.\nEnter the mapfile path only.\n");
	ft_putstr("\033[m");
	return (-1);
}

int			main(int argc, char **argv)
{
	t_env	*env;
	t_map	*map;

	if (argc != 2)
		return (usage());
	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (-1);
	mlx_env_init(&(*env));
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (-1);
	map = getmap(map, argv[1]);
	env->map = &(*map);
	printmap(map, env);
	mlx_loop(env->mlx);
	return (0);
}
