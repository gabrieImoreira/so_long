/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:38:33 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/12 14:10:28 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_update_map(t_game *game, char *map_read)
{
	if ((ft_strchr(map_read, 'P') == NULL)
		|| (ft_strchr(map_read, 'E') == NULL)
		|| (ft_strchr(map_read, 'C') == NULL))
		game->error = 3;
	check_errors(game, map_read);
	check_map_elements(map_read);
	game->map_height = (game->total_column) * 32;
	game->map_width = game->total_line * 32;
	game->map = malloc(sizeof(char)
			* (game->total_line * game->total_column) + 1);
	ft_strlcpy(game->map, map_read,
		(game->total_column * game->total_line) + 1);
	game->fd = close(game->fd);
	free(map_read);
}

static void	treat_ret(int ret, t_game *game, char *line, char *map_read)
{
	while (ret > 0)
	{
		game->total_column++;
		game->size_line = ft_strlen(line) - 1;
		if (line[0] != '1' || line[game->size_line] != '1')
			game->error = 1;
		ft_strcat(map_read, line);
		free(line);
		line = 0;
		ret = get_next_line(game->fd, &line);
		if (((int)ft_strlen(line) != game->total_line))
			game->error = 2;
		if (ret == 0)
		{
			game->total_column++;
			check_walls(game, line);
			ft_strcat(map_read, line);
			free(line);
			line = 0;
		}
	}
}

static int	initializing_map(t_game *game, char *map_name)
{
	char	*line;
	int		ret;
	char	*map_read;

	game->error = 0;
	game->size_line = 0;
	map_read = malloc(sizeof(char) * 100000);
	if (!map_read)
		exit (0);
	*map_read = 0;
	line = 0;
	game->total_column = 0;
	game->fd = open(map_name, O_RDONLY);
	if (game->fd == -1)
		errors("Error\nFile cannot be read", map_read);
	ret = get_next_line(game->fd, &line);
	check_walls(game, line);
	game->total_line = ft_strlen(line);
	treat_ret(ret, game, line, map_read);
	check_update_map(game, map_read);
	return (1);
}

static int	initializing_struct(t_game *game)
{
	game->exit_is_free = 0;
	game->numb_move = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			game->map_width, game->map_height, "so_long");
	game->path[PLAYER_LEFT] = "./img/player_left.xpm";
	game->path[PLAYER_RIGHT] = "./img/player_right.xpm";
	game->player_side = 1;
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	initializing_map(&game, argv[1]);
	initializing_struct(&game);
	draw_map(&game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 33, 1L << 5, end_game, &game);
	mlx_expose_hook(game.mlx.mlx_win, draw_map, &game);
	mlx_loop(game.mlx.mlx);
}
