/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:48:35 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/05 21:49:25 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_ext(char *name)
{
	const char *ext = ".ber";
	int len = ft_strlen(name);

	if (len < 5 || ft_strncmp(name + len - 4, ext, 4) != 0)
	{
		ft_putstr("Error\n invalide map name");
		exit(1);
	}
}


t_Map *check_map(char *av)
{
    t_Map   *map;
    
    check_ext(av); // done
	map = fill_map(av);
	if (map->x > 3840 || map->y > 2160)
	{
		ft_putstr("Error\nthe map is too big!!\n");
		free_map(map);
		exit(1);
	}
	check_shape(map);
	check_walls(map);
	check_src(map);
	check_path(av, map);// still in progress
}

