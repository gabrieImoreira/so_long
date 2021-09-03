/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:38:33 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/02 22:47:41 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"


void	check_update_map(t_game *game, char *map_read)
{
	if ((ft_strchr(map_read, 'P') == NULL)
		|| (ft_strchr(map_read, 'E') == NULL)
		|| (ft_strchr(map_read, 'C') == NULL))
		errors("Error\nMissing one player, one collectible or one exit",
			map_read);
	if (game->line_number - 1 == game->total_line_char)
		errors("Error\nMap is square!", map_read);
	check_map_elements(map_read);
	game->map_height = (game->line_number) * 32;
	game->map_width = game->total_line_char * 32;
	game->map = malloc(sizeof(char)
			* (game->total_line_char * game->line_number) + 1);
	ft_strlcpy(game->map, map_read,
		(game->line_number * game->total_line_char));
	game->fd = close(game->fd);
	free(map_read);
}

void	treat_ret(int ret, t_game *game, char *line, char *map_read)
{
	while (ret > 0)
	{
		game->line_number++;
		game->endline = ft_strlen(line) - 1;
		if (line[0] != '1' || line[game->endline] != '1')
			errors("Error\nWall missing in the border", map_read);
		ft_strcat(map_read, line);
		free(line);
		line = 0;
		ret = get_next_line(game->fd, &line);
		if ((ret != 0) && (strlen(line)
				!= (long unsigned int)game->total_line_char))
			errors("Error\nmap has a problem", map_read);
		printf("line: %s, ret: %d, len: %lu\n", line, ret, ft_strlen(line));
		if (ret == 0)
		{
			game->line_number++;
			check_walls(line);
			ft_strcat(map_read, line);
			free(line);
			line = 0;
		}
	}
}

int	initializing_map(t_game *game, char *map_name)
{
	char	*line;
	int		ret;
	char	*map_read;

	map_read = malloc(sizeof(char) * 10000);
	*map_read = 0;
	line = 0;
	game->line_number = 0;
	game->fd = open(map_name, O_RDONLY);
	if (game->fd == -1)
		errors("Error\nfile cannot be read", map_read);
	ret = get_next_line(game->fd, &line);
	printf("line: %s, ret: %d, len: %lu\n", line, ret, ft_strlen(line));
	check_walls(line);
	game->total_line_char = ft_strlen(line);
	treat_ret(ret, game, line, map_read);
	printf("\nmap: %s, total: %lu\n",map_read, ft_strlen(map_read));
	check_update_map(game, map_read);
	return (1);
}

int	initializing_struct(t_game *game)
{
	game->nb_exit = 0;
	game->numb_move = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			game->map_width, game->map_height, "so_long");
	game->mlx.mlx_img = mlx_new_image
		(game->mlx.mlx, game->map_width, game->map_height);
	initializing_texture(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	initializing_map(&game, argv[1]);
	initializing_struct(&game);
	draw_map(&game);
	mlx_loop(game.mlx.mlx);
}
