/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:27:02 by chtan             #+#    #+#             */
/*   Updated: 2024/08/26 13:45:04 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_struct	map;
	t_point		player;

	if (ac != 2)
		error_message("invalid input! please try again...");
	check_valid_map_name(av[1]);
	map = map_parsing(av[1]);
	check_map_shape(map.width, map.row);
	check_map_wall(map.map, map.row, map.width);
	check_valid_element(map.map);
	mark_elements(map);
	player = mark_player(map);
	flood_fill(map.map, player, map.width);
	map.mlx = mlx_init();
	map.wind = mlx_new_window(map.mlx, (map.width * 40),
			(map.row * 40), "so_long");
	load_images(map);
	show_map(map, 2);
	mlx_key_hook(map.wind, key_press, NULL);
	mlx_hook(map.wind, 17, 0, close_window, NULL);
	mlx_loop(map.mlx);
}

//this function is to handle when using esc button to close fdf
// 53 in key code is esc
int	key_press(int keycode, void *param)
{
	if (keycode == 53)
	{
		if (param)
		{
			mlx_destroy_window(param, param);
			param = NULL;
		}
		exit(0);
	}
	return (0);
}

// this function is handle close by clicking the x in the window fdf
int	close_window(void *param)
{
	if (param)
	{
		mlx_destroy_window(param, param);
		param = NULL;
	}
	exit(0);
	return (0);
}
/*
	// mlx_init
	while using the mlx. 
	First we need to initialize the connection to graphic system,
	and settings necessary enviroment for creating windows.
	only will failure when cannot connect to the server
	// mlx_new_window
	for mlx_new_window it will take 4 arguments.
	1) the (void *) result of init
	2) the length of x_axis of the windows should be
	3) the width of y_axis of the windows should be
	4) the title of the window
	// mlx_loop
	mlx_loop is is a function 
	to keep the windows open (will take the output of init)
*/

/*
	first we need to initialize the mlx
	next is to create a new windows
	for example here i put a string into the windows using mlx_string_put
	key hook and hok is same just handle different ways to close the windows
	mlx_loop is to keep the windows open
*/
// int	main()
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 640, 360, "so_long");

//     // Use win in some way, e.g., drawing something in the window
//     // This example is minimal, but demonstrates usage
//     mlx_string_put(mlx, win, 20, 20, 0xFFFFFF, "Hello World");
// 	mlx_key_hook(win, key_press, NULL);
// 	mlx_hook(win, 17, 0, close_window, NULL);
// 	mlx_loop(mlx);
//     return (write(1, "SUCCESS", 1));
// }

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
