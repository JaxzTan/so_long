/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:43 by chtan             #+#    #+#             */
/*   Updated: 2024/08/22 09:24:29 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_valid_map_name(char *file)
{
	int		i;
	char	*extension;

	i = ft_strlen(file) - 4;
	extension = ft_substr(file, i, 4);
	if (ft_strncmp(".ber", extension, 10) != 0)
	{
		free(extension);
		error_message("Map must be ber file\n");
	}
	free(extension);
}

void	check_map_wall(char **map, int row, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < width)
		{
			if (map[1][j] != '1')
				error_message("map not surrounded by wall!");
			else if (map[row][j] != '1')
				error_message("map not surrounded by wall!");
			else if (map[row][1] != '1')
				error_message("map not surrounded by wall!");
			else if (map[row][width] != '1')
				error_message("map not surrounded by wall!");
			j++;
		}
		i++;
	}
}

void	check_map_shape(int width, int row)
{
	if ( row > width)
		error_message("map not rectangle!");
	return ;
}
