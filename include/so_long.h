/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:35:55 by chtan             #+#    #+#             */
/*   Updated: 2024/08/12 16:30:36 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct s_struct
{
	int	collectible;
	int	exit;
	int	player;

	int 	row;
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
int close_window(void *param);
int key_press(int keycode, void *param);

// parsing map
t_struct	*map_parsing(char *files, t_struct *map);
char		**parsing(char **split, char *files);
void		insert_2d(char **split, int width, int row, char **result);
int			find_row(char **buffer);
int			find_width(char **buffer);
void		check_map_shape(int width, int row);
void		check_valid_element(char **buffer);
void		check_valid_map_name(char *str);
void		check_map_wall(t_struct *map, int width, int row);
void		mark_elements(t_struct *map);
void		mark_player(t_struct *map, t_point player);
void		flood_fill(char **map, t_point begin, int col);
void		fill(char **tab, t_point cur, int *c, int *e);



//utils
void		error_message(char *str);
void		free_2d(char **str);
int			game_over(t_struct *sl);
void		free_map(int **map, int rows);


//mlx start
void	load_images(t_struct *map);
void	show_map(t_struct *map, int keycode);


//movement
void		handle_move(t_struct *sl, t_struct *p, int keycode);
void		move_leftside(t_struct *sl, t_struct *p);
void		move_upside(t_struct *sl, t_struct *p);
void		move_rightside(t_struct *sl, t_struct *p);
void		move_downside(t_struct *sl, t_struct *p);

#endif