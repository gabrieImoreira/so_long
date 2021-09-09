/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantonio <gantonio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:43:13 by gantonio          #+#    #+#             */
/*   Updated: 2021/09/08 21:57:30 by gantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

// void delete_sprites(t_game *game)
// {
// 	mlx_destroy_image(game->mlx.mlx, game->mlx.mlx_img);
// }

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	mlx_destroy_display(game->mlx.mlx);
	free(game->map);
	free(game->mlx.mlx);
	exit(0);
}
