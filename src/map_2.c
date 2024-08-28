/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:23:50 by chtan             #+#    #+#             */
/*   Updated: 2024/08/28 16:45:32 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
// count the number of coll, player, and exit.but only return collectible
int	count_collectible_check(t_struct map, int lines_num)
{
	int	i;
	int	j;

	i = -1;
	map.collectible = 0;
	map.player = 0;
	map.exit = 0;
	while (++i < lines_num - 1)
	{
		j = -1;
		while (++j < ft_strlen(map.map[0]) - 1)
		{
			if (map.map[i][j] == 'C')
				map.collectible++;
			if (map.map[i][j] == 'P')
				map.player++;
			if (map.map[i][j] == 'E')
				map.exit++;
		}
	}
	if (map.collectible == 0 || map.player != 1 || map.exit != 1)
		error_message("invalid map elements!");
	return (map.collectible);
}

// makr the player position
t_point	mark_player(char **map)
{
	t_point	player;
	int		i;
	int		j;

	i = 0;
	j = 0;
	player.x = 0;
	player.y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player.x = j;
				player.y = i;
			}
			j++;
		}
		i++;
	}
	if (player.x == 0 || player.y == 0)
		error_message("player not found!");
	return (player);
}

void	fill(char **tab, t_point cur, int *c, int *e)
{
	if (tab[cur.y][cur.x] == 'E')
		*e = 1;
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'E')
		return ;
	if (tab[cur.y][cur.x] == 'C')
		*c += 1;
	tab[cur.y][cur.x] = '1';
	fill(tab, (t_point){cur.x - 1, cur.y}, c, e);
	fill(tab, (t_point){cur.x + 1, cur.y}, c, e);
	fill(tab, (t_point){cur.x, cur.y - 1}, c, e);
	fill(tab, (t_point){cur.x, cur.y + 1}, c, e);
}

void	flood_fill(char **map, t_point begin, int col)
{
	int	collectible;
	int	exit;

	collectible = 0;
	exit = 0;
	fill(map, begin, &collectible, &exit);
	if (collectible != col)
		error_message("Cannot reach all collectibles");
	if (exit != 1)
		error_message("Cannot reach exit");
}

// check is it possible to reach all collectibles and exit
void	check_valid_path(char *file, t_struct map, t_point player)
{
	char	**array;
	int		i;

	i = map.collectible;
	array = read_map_file(file, map.row);
	if (!array)
		error_message("Cannot read map file");
	flood_fill(array, player, i);
	free_2d(array);
}
