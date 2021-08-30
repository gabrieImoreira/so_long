/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:38:33 by gantonio          #+#    #+#             */
/*   Updated: 2021/08/30 20:14:01 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"


int	init_map(t_game *game, char *map_name)
{
	char	*line;
	int		ret;
	char	*whole_chars;

	whole_chars = malloc(sizeof(char) * 10000);
	*whole_chars = 0;
	game->line_number = 0;
	game->fd = open(map_name, O_RDONLY);
	if (game->fd == -1)
		errors("Error\nfile cannot be read", whole_chars);
	line = 0;
	//ret = get_next_line(game->fd, &line);
	check_walls(line);
	game->total_line_char = ft_strlen(line);
	//deal_ret(ret, game, line, whole_chars);
	//init_map2(game, whole_chars);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	init_map(&game, argv[1]);
}

