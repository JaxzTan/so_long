/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:37:44 by chtan             #+#    #+#             */
/*   Updated: 2024/08/12 10:59:30 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_message(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int	game_over(t_struct *sl)
{
	ft_printf("Game over\n");
	mlx_destroy_window(sl->mlx, sl->wind);
	free_arr_str(sl->map);
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
