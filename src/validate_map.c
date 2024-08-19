/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:43 by chtan             #+#    #+#             */
/*   Updated: 2024/08/19 16:51:33 by chtan            ###   ########.fr       */
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
	if (str1[j] != '\0')
		error_message("Invalid map file type");
	else
		ft_printf("ok");
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
