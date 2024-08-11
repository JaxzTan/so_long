/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:27:02 by chtan             #+#    #+#             */
/*   Updated: 2024/08/11 18:03:05 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int main(int ac, char **av)
{
	char		*files;
	t_struct	*map;
	if (ac != 2)
		error_message("invalid input! please try again...");

	files = av[1];
	map = map_parsing(files);
	// print_map(map);
	// mlx_key_hook(win, key_press, NULL);
	// mlx_hook(win, 17, 0, close_window, NULL);
	// mlx_loop(mlx);
}

// #include <stdio.h>
// void print_map(t_map *map_struct)
// {
//     printf("Height: %d\n", map_struct->height);
//     printf("Row: %d\n", map_struct->row);
//     printf("Width: %d\n", map_struct->width);

//     for (int i = 0; i < map_struct->height; i++)
//     {
//         for (int j = 0; j < map_struct->width; j++)
//         {
//             printf("%d ", map_struct->map[i][j]);
//         }
//         printf("\n");
//     }
// }