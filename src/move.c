/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:12:36 by chtan             #+#    #+#             */
/*   Updated: 2024/08/26 19:14:45 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_move(t_struct map, t_point cur, int keycode)
{
	map.col_num = map.width;
	if (keycode == 0)
		move_leftside(map, cur);
	if (keycode == 1)
		move_downside(map, cur);
	if (keycode == 2)
		move_rightside(map, cur);
	if (keycode == 13)
		move_upside(map, cur);
	if (keycode == 53)
		game_over(&map);
}

void	move_leftside(t_struct map, t_point p)
{
	if (map.map[p.y][p.x - 1] != '1' && map.map[p.y][p.x - 1] != 'E')
	{
		if (map.map[p.y][p.x - 1] == 'C')
			map.collectible--;
		ft_printf("collectible: %d\n", map.collectible);
		map.map[p.y][p.x - 1] = 'P';
		map.map[p.y][p.x] = '0';
		map.moves++;
		ft_printf("MOVES: %d\n", map.moves);
	}
	if (map.map[p.y][p.x - 1] == 'E' && map.col_num == 0)
	{
		map.moves++;
		ft_printf("MOVES: %d\n", map.moves);
		ft_printf("You won\n");
		mlx_destroy_window(map.mlx, map.wind);
		exit(0);
	}
}

void	move_upside(t_struct map, t_point p)
{
	if (map.map[p.y - 1][p.x] != '1' && map.map[p.y - 1][p.x] != 'E')
	{
		if (map.map[p.y - 1][p.x] == 'C')
			map.collectible--;
		ft_printf("collectible: %d\n", map.collectible);
		map.map[p.y - 1][p.x] = 'P';
		map.map[p.y][p.x] = '0';
		map.moves++;
		ft_printf("MOVES: %d\n", map.moves);
	}
	if (map.map[p.y - 1][p.x] == 'E' && map.col_num == 0)
	{
		map.moves++;
		ft_printf("MOVES: %d\n", map.moves);
		ft_printf("You won\n");
		mlx_destroy_window(map.mlx, map.wind);
		exit(0);
	}
}

void	move_rightside(t_struct map, t_point p)
{
	if (map.map[p.y][p.x + 1] != '1' && map.map[p.y][p.x + 1] != 'E')
	{
		if (map.map[p.y][p.x + 1] == 'C')
			map.collectible--;
		ft_printf("collectible: %d\n", map.collectible);
		map.map[p.y][p.x + 1] = 'P';
		map.map[p.y][p.x] = '0';
		map.moves++;
		ft_printf("MOVES: %d\n", map.moves);
	}
	if (map.map[p.y][p.x + 1] == 'E' && map.col_num == 0)
	{
		map.moves++;
		ft_printf("MOVES: %d\n", map.moves);
		ft_printf("You won\n");
		mlx_destroy_window(map.mlx, map.wind);
		exit(0);
	}
}

void	move_downside(t_struct map, t_point p)
{
	if (map.map[p.y + 1][p.x] != '1' && map.map[p.y + 1][p.x] != 'E')
	{
		if (map.map[p.y + 1][p.x] == 'C')
			map.collectible--;
		ft_printf("collectible: %d\n", map.collectible);
		map.map[p.y + 1][p.x] = 'P';
		map.map[p.y][p.x] = '0';
		map.moves++;
		ft_printf("MOVES: %d\n", map.moves);
	}
	if (map.map[p.y + 1][p.x] == 'E' && map.col_num == 0)
	{
		map.moves++;
		ft_printf("MOVES: %d\n", map.moves);
		ft_printf("You won\n");
		mlx_destroy_window(map.mlx, map.wind);
		exit(0);
	}
}
