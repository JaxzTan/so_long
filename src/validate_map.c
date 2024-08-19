/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:09:43 by chtan             #+#    #+#             */
/*   Updated: 2024/08/19 13:54:34 by chtan            ###   ########.fr       */
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

void	check_map_wall(char **map, int lines_num)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines_num)
	{
		j = 0;
		if (i == 0 || i == lines_num - 1)
		{
			while (map[i][j] && j < ft_strlen(map[0]) - 1)
			{
				if (map[i][j] != '1')
					error_message("Map is not closed with walls\n");
				j++;
			}
		}
		j = 0;
		while (map[i][j] && j < ft_strlen(map[0]) - 1)
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
				error_message("Map is not closed with walls\n");
			j++;
		}
		i++;
	}
}

void	check_map_shape(int width, int row)
{
	if ( row < width)
		error_message("map not rectangle!");
	return ;
}
