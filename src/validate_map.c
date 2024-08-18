/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:43 by chtan             #+#    #+#             */
/*   Updated: 2024/08/14 13:39:24 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_valid_map_name(char *str)
{
	char	*str1;
	int		i;
	int		j;

	str1 = ".ber";
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == str1[j])
			j++;
		i++;
	}
	if (j != 3)
		error_message("Invalid map file type");
	else
		ft_printf("ok");
}

void	check_map_wall(t_struct *map, int width, int row)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (ft_strcmp(map->map[0][j], "1") != 0)
				error_message("Map is not surrounded by walls");
			else if (ft_strcmp(map->map[i][0], "1") != 0)
				error_message("Map is not surrounded by walls");
			else if (ft_strcmp(map->map[i][map->width], "1") != 0)
				error_message("Map is not surrounded by walls");
			else if (ft_strcmp(map->map[map->row][j], "1") != 0)
				error_message("Map is not surrounded by walls");
			j++;
		}
		i++;
	}
}

void	check_map_shape(int width, int row)
{
	if (ft_strcmp(width, row) <= 0)
		error_message("map not rectangle!");
	return ;
}
