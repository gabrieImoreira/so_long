/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:22:10 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/12 14:10:45 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	errors(char *message, char *map_read)
{
	ft_putendl_fd(message, 2);
	free(map_read);
	exit (1);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\nInvalid number of arguments", 2);
		exit(0);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
	{
		ft_putendl_fd("Error\nInvalid argument", 2);
		exit(0);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
	{
		ft_putendl_fd("Error\nFile must be of type \"<name>.ber\"", 2);
		exit(0);
	}
}

void	check_walls(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			game->error = 1;
		i++;
	}
}

void	check_map_elements(char *map_read)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (map_read[i] != '\0')
	{
		if (map_read[i] == 'P')
			counter++;
		if (ft_strchr("01CEP", map_read[i]) == NULL)
		{
			ft_putendl_fd("Error\nCharacters not allowed", 2);
			free(map_read);
			exit (1);
		}
		i++;
	}
	if (counter > 1)
		errors("Error\nOnly one player should be on the map", map_read);
}

void check_errors(t_game *game, char *map_read)
{
	if (game->error == 1)
		errors("Error\nMap is not surrounded by walls", map_read);
	if (game->error == 2)
		errors("Error\nInvalid parameters", map_read);
	if (game->error == 3)	
		errors("Error\nMissing one player, one collectible or one exit",
			map_read);
}