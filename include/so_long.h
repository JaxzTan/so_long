/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:35:55 by chtan             #+#    #+#             */
/*   Updated: 2024/11/14 13:46:38 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
// # include "mlx.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct s_struct
{
	int		collectible;
	int		exit;
	int		player;

	int		line_nb;
	int		col_num;
	int		row;
	int		width;
	char	**map;

	int		moves;

	void	*mlx;
	void	*wind;

	void	*wal;
	void	*up;
	void	*dow;
	void	*lef;
	void	*rig;
	void	*flr;
	void	*dc;
	void	*dro;
	void	*col;
}	t_struct;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

//main
int			close_window(void *param);
int			key_hook(int keycode, t_struct *map);
void		free_map(char **map, int rows);

// parsing map
t_struct	map_parsing(char *files);
int			get_line_nb(char *file);
char		**read_map_file(char *file, int lines_num);
char		**insert_2d(char **split, int width, int row, t_struct map);
void		initialize(t_struct *map);

//checking map
void		check_valid_map_name(char *str);
void		check_map_wall(char **map, int row, int width);
void		check_map_shape(char **map, int lines_num);
void		check_valid_element(char **buffer);

//map2
int			count_collectible_check(t_struct map, int lines_num);
t_point		mark_player(char **map);
void		fill(char **tab, t_point cur, int *c, int *e);
void		flood_fill(char **map, t_point begin, int col);
void		check_valid_path(char *file, t_struct map, t_point player);

//utils
void		error_message(char *str);
int			game_over(t_struct *map);
void		free_2d(char **str);
int			find_row(char **buffer);
int			find_width(char **buffer);

//mlx start
void		load_images(t_struct *map);
void		show_map(t_struct *map, int keycode);
void		put_player(t_struct *map, int keycode, int i, int j);
void		put_collectible(t_struct *map, int i, int j);
void		put_exit(t_struct *map, int i, int j);

//movement
void		handle_move(t_struct *map, t_point *cur, int keycode);
void		move_leftside(t_struct *map, t_point *p);
void		move_upside(t_struct *map, t_point *p);
void		move_rightside(t_struct *map, t_point *p);
void		move_downside(t_struct *map, t_point *p);

#endif
