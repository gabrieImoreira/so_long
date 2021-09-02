/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 22:37:45 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/01 22:03:56 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	set_image(t_game *game, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(game->mlx.mlx, path, &width, &height);
	if (*img == 0)
		ft_putendl_fd("Error\nCan't load texture", 2);
	(*img)->width = width;
	(*img)->height = height;
}

void	initializing_texture(t_game *game)
{
	set_image(game, &game->player, "./img/wizard.xpm");
	set_image(game, &game->exit, "./img/exit_open.xpm");
	set_image(game, &game->collectible, "./img/key.xpm");
	set_image(game, &game->wall, "./img/wall.xpm");
	set_image(game, &game->floor, "./img/floor.xpm");
}