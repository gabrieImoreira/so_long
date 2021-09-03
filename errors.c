/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:22:10 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/02 23:01:01 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	errors(char *nature, char *map_read)
{
	ft_putendl_fd(nature, 2);
	free(map_read);
	exit (0);
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
		ft_putendl_fd("Error\ninvalid argument", 2);
		exit(0);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
	{
		ft_putendl_fd("Error\nfile must be of type \"<name>.ber\"", 2);
		exit(0);
	}
}

void	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			ft_putendl_fd("map is not surrounded by walls", 2);
			free(line);
			exit (1);
		}
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
			ft_putendl_fd("Error\nFile contains characters other than the allowed", 2);
			free(map_read);
			exit (1);
		}
		i++;
	}
	if (counter > 1)
		errors("only one player should be on the map", map_read);
}