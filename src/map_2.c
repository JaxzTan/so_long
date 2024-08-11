/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:23:50 by chtan             #+#    #+#             */
/*   Updated: 2024/08/11 15:58:15 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_valid_map(char **buffer)
{
	int i;
	int j;

	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{
			if (buffer[i][j] != '1' && buffer[i][j] != '0' && 
			buffer[i][j] != 'P' && buffer[i][j] != 'C' && buffer[i][j] != 'E')
				error_message("invalid map!");
			j++;
		}
		i++;
	}
	return ;
}

void	check_map_shape(char **map, size_t lines_num)
{
	size_t	first_line_len;
	size_t	i;

	i = 1;
	first_line_len = ft_strlen(map[0]);
	while (i < lines_num - 1)
	{
		if (ft_strlen(map[i]) != first_line_len)
			error_message("Map is not rectangular\n");
		i++;
	}
	if (ft_strlen(map[i]) != first_line_len - 1)
		error_message("Map is not rectangular\n");
}