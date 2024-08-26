/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:49:20 by chtan             #+#    #+#             */
/*   Updated: 2024/08/26 19:10:31 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
wal = wall
flr = floor
lef = left
rig = right
up = up
dow = down
col = collectible
dc = door close
dro = door open
*/
void	load_images(t_struct *map)
{
	int	x;
	int	y;

	x = 40;
	y = 40;
	map->wal = mlx_xpm_file_to_image(map->mlx, "char/wall.xpm", &x, &y);
	map->flr = mlx_xpm_file_to_image(map->mlx, "char/grs.xpm", &x, &y);
	map->lef = mlx_xpm_file_to_image(map->mlx, "char/lft.xpm", &x, &y);
	map->rig = mlx_xpm_file_to_image(map->mlx, "char/rgh.xpm", &x, &y);
	map->up = mlx_xpm_file_to_image(map->mlx, "char/up.xpm", &x, &y);
	map->dow = mlx_xpm_file_to_image(map->mlx, "char/dwn.xpm", &x, &y);
	map->col = mlx_xpm_file_to_image(map->mlx, "char/gds.xpm", &x, &y);
	map->dc = mlx_xpm_file_to_image(map->mlx, "char/dc.xpm", &x, &y);
	map->dro = mlx_xpm_file_to_image(map->mlx, "char/do.xpm", &x, &y);
}

void	show_map(t_struct map, int keycode)
{
	int	i;
	int	j;

	i = -1;
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j])
		{
			if (map.map[i][j] == '1')
				mlx_put_image_to_window(map.mlx, map.wind,
					map.wal, j * 40, i * 40);
			if (map.map[i][j] == '0')
				mlx_put_image_to_window(map.mlx, map.wind,
					map.flr, j * 40, i * 40);
			if (map.map[i][j] == 'P')
				put_player(map, keycode, i, j);
			if (map.map[i][j] == 'C')
				put_collectible(map, i, j);
			if (map.map[i][j] == 'E')
				put_exit(map, i, j);
		}
	}
}

void	put_player(t_struct map, int keycode, int i, int j)
{
	if (keycode == 13)
		mlx_put_image_to_window(map.mlx, map.wind, map.up, j * 40, i * 40);
	if (keycode == 0)
		mlx_put_image_to_window(map.mlx, map.wind, map.lef, j * 40, i * 40);
	if (keycode == 1)
		mlx_put_image_to_window(map.mlx, map.wind, map.dow, j * 40, i * 40);
	if (keycode == 2)
		mlx_put_image_to_window(map.mlx, map.wind, map.rig, j * 40, i * 40);
}

void	put_collectible(t_struct map, int i, int j)
{
	mlx_put_image_to_window(map.mlx, map.wind, map.col, j * 40, i * 40);
}

void	put_exit(t_struct map, int i, int j)
{
	if (map.collectible == 0)
		mlx_put_image_to_window(map.mlx, map.wind, map.dro, j * 40, i * 40);
	else
		mlx_put_image_to_window(map.mlx, map.wind, map.dc, j * 40, i * 40);
}
