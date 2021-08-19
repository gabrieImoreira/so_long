/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:38:33 by gantonio          #+#    #+#             */
/*   Updated: 2021/08/18 20:59:30 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}	
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("hey_hook: %c\n", keycode);
	if (keycode == ESC)	
		mlx_destroy_window(vars->mlx, vars->win);
	else if (keycode == 'c')
		mlx_clear_window(vars->mlx, vars->win);
}

int close_clean(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
}

int	main(void)
{
	t_vars	vars;
	t_data	data;
	char	*relative_path = "./img/wizard.xpm";
	int		img_width;
	int		img_height;
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 360, "Tutorial Window - Draw Line");
	data.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, data.img, 100, 100);
	//mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	//mlx_hook(vars.win, 33, 1L<<5, close_clean, &vars);
    mlx_loop(vars.mlx);
}

