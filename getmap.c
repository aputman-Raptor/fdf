/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:42:32 by aputman           #+#    #+#             */
/*   Updated: 2016/04/21 19:31:42 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		*get_numbers(char *str, t_map *map)
{
	int		i;
	int		*result;
	char	**hitler;

	i = 0;
	hitler = ft_strsplit(str, ' ');
	while (hitler[i])
		i++;
	if (!(result = (int *)ft_memalloc(sizeof(int) * (i + 1))))
		return (NULL);
	i = -1;
	while (hitler[++i])
		result[i] = ft_atoi(hitler[i]);
	map->len_x = i;
	return (result);
}

static int		**get_truemap(char **fdp, t_map *map)
{
	int		**obama;
	int		i;

	i = 0;
	while (fdp[i])
		i++;
	if (!(obama = (int **)ft_memalloc(sizeof(int *) * (i + 1))))
		return (NULL);
	i = -1;
	while (fdp[++i])
		obama[i] = get_numbers(fdp[i], map);
	map->len_y = i;
	return (obama);
}

t_map			*getmap(t_map *map, char *argv)
{
	char	**fdp;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &map->map_text) > 0)
		i++;
	close(fd);
	fd = open(argv, O_RDONLY);
	if (!(fdp = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &map->map_text) > 0)
		fdp[i++] = ft_strdup(map->map_text);
	map->tmap = get_truemap(fdp, map);
	free(map->map_text);
	return (map);
}
