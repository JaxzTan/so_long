/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:41:26 by chtan             #+#    #+#             */
/*   Updated: 2024/08/26 13:55:42 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
//the main function in this file that will fill the 2d array, row, and col to
//	struct.
t_struct	map_parsing(char *files)
{
	t_struct	map;
	char		**array;

	map.line_nb = get_line_nb(files);
	array = read_map_file(files, map.line_nb);
	map.row = find_row(array);
	map.width = find_width(array);
	map.map = insert_2d(array, map.width, map.row, map);
	if (!map.map)
	{
		free_map(map.map, map.row);
		error_message("Map is empty");
	}
	free_2d(array);
	return (map);
}

int	get_line_nb(char *file)
{
	int		fd;
	int		lines_num;
	char	*str;

	lines_num = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_message("Fail to open file\n");
	str = get_next_line(fd);
	while (str)
	{
		lines_num++;
		free(str);
		str = get_next_line(fd);
	}
	if (lines_num == 0)
		error_message("Map file is empty\n");
	close(fd);
	return (lines_num);
}

char	**read_map_file(char *file, int lines_num)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_message("Fail to open file\n");
	map = (char **)malloc(sizeof(char *) * (lines_num + 1));
	if (!map)
		error_message("Fail to allocate memory\n");
	i = 0;
	while (i < lines_num)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

//tranfer whole 2d array after split into t_struct.
char	**insert_2d(char **split, int width, int row, t_struct map)
{
	int		i;
	int		j;

	map.map = (char **)malloc(sizeof(char *) * (row + 1));
	if (!map.map)
		error_message("Memory allocation failed");
	i = 0;
	while (i < row)
	{
		map.map[i] = (char *)malloc(sizeof(char) * (width + 1));
		if (!map.map[i])
		{
			free_2d(map.map);
			error_message("	Memory allocation failed");
		}
		j = 0;
		while (j < width)
		{
			map.map[i][j] = split[i][j];
			j++;
		}
		map.map[i][j] = '\0';
		i++;
	}
	map.map[i] = NULL;
	return (map.map);
}

//void print_2d(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		ft_printf("%s\n", map[i]);
// 		i++;
// 	}
// }
