/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:12:36 by chtan             #+#    #+#             */
/*   Updated: 2024/08/11 18:02:08 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_move(t_struct *sl, t_struct *p, int keycode)
{
	if (keycode == 0)
		move_leftside(sl, p);
	if (keycode == 1)
		move_downside(sl, p);
	if (keycode == 2)
		move_rightside(sl, p);
	if (keycode == 13)
		move_upside(sl, p);
	if (keycode == 53)
		game_over(sl);
}

void	move_leftside(t_struct *sl, t_struct *p)
{
	if (sl->map[p->width][p->row - 1] != '1' && sl->map[p->width][p->row - 1] != 'E')
	{
		if (sl->map[p->width][p->row - 1] == 'C')
			sl->col_num--;
		sl->map[p->width][p->row - 1] = 'P';
		sl->map[p->width][p->row] = '0';
		sl->moves++;
		ft_printf("MOVES: %d\n", sl->moves);
	}
	if (sl->map[p->width][p->row - 1] == 'E' && sl->col_num == 0)
	{
		sl->moves++;
		ft_printf("MOVES: %d\n", sl->moves);
		ft_printf("You won\n");
		mlx_destroy_window(sl->mlx, sl->wind);
		exit(0);
	}
}

void	move_upside(t_struct *sl, t_struct *p)
{
	if (sl->map[p->width - 1][p->row] != '1' && sl->map[p->width - 1][p->row] != 'E')
	{
		if (sl->map[p->width - 1][p->row] == 'C')
			sl->col_num--;
		sl->map[p->width - 1][p->row] = 'P';
		sl->map[p->width][p->row] = '0';
		sl->moves++;
		ft_printf("MOVES: %d\n", sl->moves);
	}
	if (sl->map[p->width - 1][p->row] == 'E' && sl->col_num == 0)
	{
		sl->moves++;
		ft_printf("MOVES: %d\n", sl->moves);
		ft_printf("You won\n");
		mlx_destroy_window(sl->mlx, sl->wind);
		exit(0);
	}
}

void	move_rightside(t_struct *sl, t_struct *p)
{
	if (sl->map[p->width][p->row + 1] != '1' && sl->map[p->width][p->row + 1] != 'E')
	{
		if (sl->map[p->width][p->row + 1] == 'C')
			sl->col_num--;
		sl->map[p->width][p->row + 1] = 'P';
		sl->map[p->width][p->row] = '0';
		sl->moves++;
		ft_printf("MOVES: %d\n", sl->moves);
	}
	if (sl->map[p->width][p->row + 1] == 'E' && sl->col_num == 0)
	{
		sl->moves++;
		ft_printf("MOVES: %d\n", sl->moves);
		ft_printf("You won\n");
		mlx_destroy_window(sl->mlx, sl->wind);
		exit(0);
	}
}

void	move_downside(t_struct *sl, t_struct *p)
{
	if (sl->map[p->width + 1][p->row] != '1' && sl->map[p->width + 1][p->row] != 'E')
	{
		if (sl->map[p->width + 1][p->row] == 'C')
			sl->col_num--;
		sl->map[p->width + 1][p->row] = 'P';
		sl->map[p->width][p->row] = '0';
		sl->moves++;
		ft_printf("MOVES: %d\n", sl->moves);
	}
	if (sl->map[p->width + 1][p->row] == 'E' && sl->col_num == 0)
	{
		sl->moves++;
		ft_printf("MOVES: %d\n", sl->moves);
		ft_printf("You won\n");
		mlx_destroy_window(sl->mlx, sl->wind);
		exit(0);
	}
}