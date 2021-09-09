/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:37:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/09 00:19:34 by gantonio         ###   ########.fr       */
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

void	call_sprite(t_game *game, int x, int y, int i)
{
	char	*path_exit;
	char	*path_player;

	game->path[PLAYER_RIGHT];
	if (game->nb_exit == 1)
		path_exit = "./img/exit_open.xpm";
	else
		path_exit = "./img/exit_closed.xpm";
	draw_sprite(game, "./img/floor.xpm", game->x, game->y);
	if (game->map[i + game->numb] == 'P')
		draw_sprite(game, game->path[game->side], game->x, game->y);
	else if (game->map[i + game->numb] == 'C')
		draw_sprite(game, "./img/key.xpm", game->x, game->y);
	else if (game->map[i + game->numb] == 'E')
		draw_sprite(game, path_exit, game->x, game->y);
}

void	draw_map(t_game *game)
{
	int		i;

	game->numb = 0;
	game->y = 0;
	game->x = 0;
	while (game->y < (game->line_number))
	{
		i = 0;
		while (i < game->total_line_char)
		{
			if (game->map[i + game->numb] == '1')
				draw_sprite(game, "./img/wall.xpm", game->x, game->y);
			else
				call_sprite(game, game->x, game->y, i);
			game->x++;
			i++;
		}
		game->x = 0;
		game->y++;
		game->numb = game->total_line_char * game->y;
	}
}
