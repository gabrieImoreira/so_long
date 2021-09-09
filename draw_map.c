/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:37:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/08 21:10:25 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	draw_sprite(t_game *game, char *path, int x, int y)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx.mlx, path, &width, &height);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		img, x * 32, y * 32);
	mlx_destroy_image(game->mlx.mlx, img);
	
}

void	draw_map(t_game *game)
{
	int	z;
	char *path_exit;

	game->numb = 0;
	game->y = 0;
	game->x = 0;
	if (game->nb_exit == 1)
		path_exit = "./img/exit_open.xpm";
	else
		path_exit = "./img/exit_closed.xpm";	
	while (game->y < (game->line_number))
	{
		z = 0;
		while (z < game->total_line_char)
		{
			if (game->map[z + game->numb] == '1')
				draw_sprite(game, "./img/wall.xpm", game->x, game->y);
			else
			{
				draw_sprite(game, "./img/floor.xpm", game->x, game->y);
				if (game->map[z + game->numb] == 'P')
					draw_sprite(game, "./img/player.xpm", game->x, game->y);
				else if (game->map[z + game->numb] == 'C')
					draw_sprite(game, "./img/key.xpm", game->x, game->y);
				else if (game->map[z + game->numb] == 'E')
					draw_sprite(game, path_exit, game->x, game->y);
			}
			game->x++;
			z++;
		}
		game->x = 0;
		game->y++;
		game->numb = game->total_line_char * game->y;
	}
}