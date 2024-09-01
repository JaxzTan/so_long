/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:43 by chtan             #+#    #+#             */
/*   Updated: 2024/09/01 12:32:48 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// to comfirm the map in .ber format that match the requirement of pdf
void	check_valid_map_name(char *file)
{
	int		i;
	char	*extension;

	i = ft_strlen(file) - 4;
	extension = ft_substr(file, i, 4);
	if (ft_strncmp(".ber", extension, 10) != 0)
	{
		free(extension);
		error_message("Map must be .ber file");
	}
	free(extension);
}

// to comfirm the wall seround the map
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
			if (i == 0 || i == row - 1 || j == 0 || j == width - 1)
			{
				if (map[i][j] != '1')
					error_message("map not surrounded by wall!");
			}
			j++;
		}
		i++;
	}
}

// need to be in rectangle shape
void	check_map_shape(char **map, int lines_num)
{
	int	first_line_len;
	int	i;

	i = 1;
	first_line_len = ft_strlen(map[0]);
	while (i < lines_num -1)
	{
		if (ft_strlen(map[i]) != first_line_len)
			error_message("Map is not rectangular");
		i++;
	}
	if ((ft_strlen(map[i]) + 1) != first_line_len)
		error_message("Map is not rectangular");
}

/*
C is collectible
E is exit
P is player
1 is wall
0 is floor
*/
void	check_valid_element(char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{
			if (buffer[i][j] != '1' && buffer[i][j] != '0' &&
			buffer[i][j] != 'P' && buffer[i][j] != 'C' && buffer[i][j] != 'E'
				&& buffer[i][j] != '\n')
				error_message("invalid char in map!");
			j++;
		}
		i++;
	}
}
