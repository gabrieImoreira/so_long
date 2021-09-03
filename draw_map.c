/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:37:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/02 22:34:55 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	set_image(t_game *game, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(game->mlx.mlx, path, &width, &height);
	if (*img == 0)
		ft_putendl_fd("Error\nCan't load texture", 2);
	(*img)->width = width;
	(*img)->height = height;
}

void	initializing_texture(t_game *game)
{
	set_image(game, &game->player, "./img/wizard.xpm");
	set_image(game, &game->exit, "./img/exit_open.xpm");
	set_image(game, &game->collectible, "./img/key.xpm");
	set_image(game, &game->wall, "./img/wall.xpm");
	set_image(game, &game->floor, "./img/floor.xpm");
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

void	draw_square(t_game *game, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(game->mlx.mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	check_for_elements(t_game *game, int x, int y, int z)
{
	if (game->map[z + game->numb] == 'P')
		draw_square(game, game->player, x, y * 32);
	if (game->map[z + game->numb] == 'C')
		draw_square(game, game->collectible, x, y * 32);
	if (game->map[z + game->numb] == 'E' || game->map[z + game->numb] == 'X')
		draw_square(game, game->exit, x, y * 32);
}

void	draw_map(t_game *game)
{
	int	z;

	game->numb = 0;
	game->y = 0;
	game->x = -32;
	while (game->y < (game->line_number))
	{
		z = 0;
		while (z < game->total_line_char)
		{
			if (game->map[z + game->numb] == '1')
				draw_square(game, game->wall, game->x += 32, game->y * 31);
			else
			{
				draw_square(game, game->floor, game->x += 32, game->y * 31);
				check_for_elements(game, game->x, game->y, z);
			}
			z++;
		}
		game->y++;
		game->numb = game->total_line_char * game->y;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->mlx.mlx_img, 0, 0);
}