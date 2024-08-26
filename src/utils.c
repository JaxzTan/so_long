/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:37:44 by chtan             #+#    #+#             */
/*   Updated: 2024/08/26 19:02:11 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_printf("%s\n", str);
	exit(1);
}

int	game_over(t_struct *map)
{
	t_struct map1;
	
	map1 = *map;
	ft_printf("Game over\n");
	mlx_destroy_window(map1.mlx, map1.wind);
	free_map(map1.map, map1.row);
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

// finding row for easier to copy 2d array in struct
int	find_row(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
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
