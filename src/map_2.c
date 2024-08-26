/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:23:50 by chtan             #+#    #+#             */
/*   Updated: 2024/08/26 12:29:21 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
			buffer[i][j] != 'P' && buffer[i][j] != 'C' && buffer[i][j] != 'E')
				error_message("invalid char in map!");
			j++;
		}
		i++;
	}
	return ;
}

void	mark_elements(t_struct map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map.collectible = 0;
	map.exit = 0;
	map.player = 1;
	while (map.map[i])
	{
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'C')
				map.collectible++;
			else if (map.map[i][j] == 'E')
				map.exit++;
			else if (map.map[i][j] == 'P')
				map.player++;
			j++;
		}
		i++;
	}
	if (map.collectible <= 0 || map.player != 1 || map.exit != 1)
		error_message("invalid map elements!");
}

t_point	mark_player(t_struct map)
{
	t_point	player;
	int	i;
	int	j;

	i = 0;
	j = 0;
	player.x = 0;
	player.y = 0;
	while (map.map[i])
	{
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'P')
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
		error_message("Cannot reach all collectibles\n");
	if (exit != 1)
		error_message("Cannot reach exit\n");
}
