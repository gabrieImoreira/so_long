/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:38:33 by gantonio          #+#    #+#             */
/*   Updated: 2021/08/30 23:09:56 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"


void	treat_ret(int ret, t_game *game, char *line, char *all_chars)
{
	while (ret > 0)
	{
		game->line_number++;
		game->endline = ft_strlen(line) - 1;
		if (line[0] != '1' || line[game->endline] != '1')
			errors("Error\nWall missing in the border", all_chars);
		ft_strcat(all_chars, line);
		free(line);
		line = 0;
		ret = get_next_line(game->fd, &line);
		if ((ret != 0) && (strlen(line)
				!= (long unsigned int)game->total_line_char))
			errors("Error\nmap has a problem", all_chars);
		printf("line: %s, ret: %d, len: %lu\n", line, ret, ft_strlen(line));
		if (ret == 0)
		{
			game->line_number++;
			check_walls(line);
			ft_strcat(all_chars, line);
			free(line);
			line = 0;
		}
	}
}

int	init_map(t_game *game, char *map_name)
{
	char	*line;
	int		ret;
	char	*all_chars;

	all_chars = malloc(sizeof(char) * 10000);
	*all_chars = 0;
	line = 0;
	game->line_number = 0;
	game->fd = open(map_name, O_RDONLY);
	if (game->fd == -1)
		errors("Error\nfile cannot be read", all_chars);
	ret = get_next_line(game->fd, &line);
	printf("line: %s, ret: %d, len: %lu\n", line, ret, ft_strlen(line));
	check_walls(line);
	game->total_line_char = ft_strlen(line);
	treat_ret(ret, game, line, all_chars);
	printf("\nmap: %s, total: %lu\n",all_chars, ft_strlen(all_chars));
	//init_map2(game, all_chars);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	init_map(&game, argv[1]);
}

