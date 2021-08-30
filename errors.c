/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:22:10 by gantonio          #+#    #+#             */
/*   Updated: 2021/08/30 20:11:31 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(char *nature, char *whole_chars)
{
	ft_putendl_fd(nature, 2);
	free(whole_chars);
	exit (0);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\nInvalid number of argument", 2);
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