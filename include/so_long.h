/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:35:55 by chtan             #+#    #+#             */
/*   Updated: 2024/08/11 18:01:40 by chtan            ###   ########.fr       */
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

	void	*mlx;
	void	*wind;
	size_t	map_lines;
	int		col_num;
	int		moves;
	void	*img_brk;
	void	*img_up;
	void	*img_dow;
	void	*img_lef;
	void	*img_rig;
	void	*img_emp;
	void	*img_dc;
	void	*img_do;
	void	*img_col;
}	t_struct;

//main
int close_window(void *param);
int key_press(int keycode, void *param);

// parsing map
t_struct	*map_parsing(char *files);
char		**parsing(char **split, char *files);
void		insert_2d(char **split, int width, int row, char **result);
int			find_row(char **buffer);
int			find_width(char **buffer);
void		free_map(int **map, int rows);
void		check_map_shape(char **map, size_t lines_num);
void		check_valid_map(char **buffer);

//utils
void		error_message(char *str);
void		free_2d(char **str);
int			game_over(t_struct *sl);

//temp
void		print_map(t_struct *map_struct);

//movement
void		handle_move(t_struct *sl, t_struct *p, int keycode);
void		move_leftside(t_struct *sl, t_struct *p);
void		move_upside(t_struct *sl, t_struct *p);
void		move_rightside(t_struct *sl, t_struct *p);
void		move_downside(t_struct *sl, t_struct *p);

#endif