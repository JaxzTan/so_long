/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:41:26 by chtan             #+#    #+#             */
/*   Updated: 2024/08/14 13:36:02 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
//the main function in this file that will fill the 2d array, row, and col to
//	struct.
t_struct	*map_parsing(char *files, t_struct *map)
{
	char		**split;

	split = parsing(split, files);
	map->row = find_row(split);
	map->width = find_width(split);
	insert_2d(split, map->width, map->row, map->map);
	if (!map->map)
	{
		free_map(map->map, map->row);
		error_message("Error: Map is empty");
	}
	free_2d(split);
	return (map);
}

// this function is almost same with gnl main funcion
// it's doing open files get files and split using ft_split
char	**parsing(char **split, char *files)
{
	int		fd;
	char	*line;

	fd = open(files, O_RDONLY);
	if (fd < 0)
		error_message("Error: File not found");
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	split = ft_split(line, ' ');
	free(line);
	close(fd);
	return (split);
}

// finding row for easier to copy 2d array in struct
int	find_row(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != NULL)
		i++;
	return (i);
}

// this one is width
int	find_width(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[0][i] >= 33 && buffer[0][i] <= 126)
		i++;
	return (i);
}

//tranfer whole 2d array after split into t_struct.
void	insert_2d(char **split, int width, int row, char **result)
{
	int		i;
	int		j;

	result = (char **)malloc(sizeof(char *) * (row + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < row)
	{
		result[i] = (char *)malloc(sizeof(char) * (width + 1));
		if (!result[i])
		{
			free_2d(result);
			return (NULL);
		}
		j = 0;
		while (j < width)
		{
			result[i][j] = split[i][j];
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	return (result);
}
