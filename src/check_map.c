/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:48:35 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/12 16:52:03 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_Map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

void	check_ext(char *name)
{
	const char	*ext = ".ber";
	int			len;

	len = ft_strlen(name);
	if (len < 4 || ft_strncmp(name + len - 4, ext, 4) != 0)
	{
		ft_putstr("Error\nInvalid map name");
		exit(1);
	}
}

t_Map	*check_map(char *av)
{
	t_Map	*map;

	check_ext(av);
	map = fill_map(av);
	if (map->x > 1920 || map->y > 1080)
	{
		ft_putstr("Error\nthe map is too big!!\n");
		free_map(map);
		exit(1);
	}
	check_shape(map);
	check_walls(map);
	check_src(map);
	check_path(av, map);
	return (map);
}
