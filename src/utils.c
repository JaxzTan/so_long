/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:37:44 by chtan             #+#    #+#             */
/*   Updated: 2024/08/19 16:04:42 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_printf("%s\n", str);
	exit(1);
}

int	game_over(t_struct map)
{
	ft_printf("Game over\n");
	mlx_destroy_window(map.mlx, map.wind);
	free_map(map.map, map.row);
	exit(0);
}

void	free_2d(char **str)
{
	char	**tmp;
	int		i;

	tmp = str;
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(str);
}

void	free_map(char **map, int rows)
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
