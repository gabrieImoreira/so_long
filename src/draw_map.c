/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:37:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/10 17:51:33 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	print_score(t_game *game, char *score)
{
	mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, (game->map_width / 2) - 32,
		18, create_trgb(0, 255, 255, 255), "score: ");
	mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, (game->map_width / 2) + 8,
		18, create_trgb(0, 255, 255, 255), score);
	free(score);
}

static void	draw_sprite(t_game *game, char *path, int x, int y)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx.mlx, path, &width, &height);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		img, x * 32, y * 32);
	mlx_destroy_image(game->mlx.mlx, img);
}

static void	filter_sprite(t_game *game, int x, int y, int i)
{
	char	*path_exit;

	game->path[PLAYER_RIGHT];
	if (game->exit_is_free == 1)
		path_exit = "./img/exit_open.xpm";
	else
		path_exit = "./img/exit_closed.xpm";
	draw_sprite(game, "./img/floor.xpm", game->x, game->y);
	if (game->map[i + game->aux_num] == 'P')
		draw_sprite(game, game->path[game->player_side], game->x, game->y);
	else if (game->map[i + game->aux_num] == 'C')
		draw_sprite(game, "./img/key.xpm", game->x, game->y);
	else if (game->map[i + game->aux_num] == 'E')
		draw_sprite(game, path_exit, game->x, game->y);
}

int	draw_map(t_game *game)
{
	int		i;
	char	*score;

	game->aux_num = 0;
	game->y = 0;
	game->x = 0;
	while (game->y < (game->total_column))
	{
		i = 0;
		while (i < game->total_line)
		{
			if (game->map[i + game->aux_num] == '1')
				draw_sprite(game, "./img/wall.xpm", game->x, game->y);
			else
				filter_sprite(game, game->x, game->y, i);
			game->x++;
			i++;
		}
		score = ft_itoa(game->numb_move);
		print_score(game, score);
		game->x = 0;
		game->y++;
		game->aux_num = game->total_line * game->y;
	}
	return (0);
}
