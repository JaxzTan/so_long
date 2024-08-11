/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:41:26 by chtan             #+#    #+#             */
/*   Updated: 2024/08/11 18:02:50 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(int **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	find_row(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != NULL)
		i++;
	return (i);
}

int	find_width(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[0][i] >= 33 && buffer[0][i] <= 126)
		i++;
	return (i);
}

t_struct	*map_parsing(char *files)
{
	char		**split;
	t_struct	*map;

	split = parsing(split, files);
	map = malloc(sizeof(t_struct));
	map->row = find_row(split);
	map->width = find_width(split);
	insert_2d(split, map->width, map->row, map->map);
	if (!map->map)
	{
		free_map(map->map, map->row);
		error_message("Error: Map is empty");
	}
	return (map);
}

void	insert_2d(char **split, int width, int row, char **result)
{
	int		i;
	int		j;

	result = malloc(sizeof(char *) * row);
	if (!result)
		return NULL;
	i = 0;
	while (i < row)
	{
		result[i] = malloc(sizeof(char) * (width + 1));
		if (!result[i])
		{
			free_2d(result);
			return NULL;
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
char	**parsing(char **split, char *files)
{
	int fd;
	char *line;

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
